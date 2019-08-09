<?php

namespace Drupal\vu_rp_api;

use Drupal\vu_rp_api\Config\ConfigManager;
use Drupal\vu_rp_api\Endpoint\Endpoint;
use Drupal\vu_rp_api\Provider\Provider;
use Drupal\vu_rp_api\Provider\ProviderManager;

/**
 * Class FormBuilder.
 *
 * @package Drupal\vu_rp_api
 */
class FormBuilder {

  /**
   * The configuration manger.
   *
   * @var \Drupal\vu_rp_api\Config\ConfigManager
   */
  protected $configManager;

  /**
   * The provider manager.
   *
   * @var \Drupal\vu_rp_api\Provider\ProviderManager
   */
  protected $providerManager;

  /**
   * Stack of forms to track while collecting settings.
   *
   * @var array
   */
  protected $formStack = [];

  /**
   * FormBuilder constructor.
   *
   * @param \Drupal\vu_rp_api\Config\ConfigManager $configManager
   *   The configuration manager.
   * @param \Drupal\vu_rp_api\Provider\ProviderManager $providerManager
   *   The provider manager.
   */
  public function __construct(ConfigManager $configManager, ProviderManager $providerManager) {
    $this->configManager = $configManager;
    $this->providerManager = $providerManager;
  }

  /**
   * Get form key by name.
   *
   * @param string $name
   *   Element name on the form.
   *
   * @return string
   *   The form key.
   */
  public function getFormKey($name) {
    return $this->configManager->buildConfigKey($name);
  }

  /**
   * Get default value for a form element.
   *
   * @param string $name
   *   Form element name.
   * @param null $default
   *   Optional default value to return if no configuration value exists.
   *
   * @return array|mixed|null
   *   Stored value or $default if no value is stored.
   */
  public function getDefaultValue($name, $default = NULL) {
    $name = array_merge($this->formStack, [$name]);

    return $this->configManager->getValue($name, $default);
  }

  /**
   * Builds form.
   */
  public function build($form, &$form_state) {
    $form[$this->getFormKey('provider')] = [
      '#type' => 'radios',
      '#title' => t('Providers'),
      '#required' => TRUE,
      '#default_value' => $this->getDefaultValue('provider'),
      '#options' => $this->providerManager->getFormOptions(),
    ];

    $form_providers = $this->collectProviderForms($form, $form_state);
    $form += $form_providers;

    $form[$this->getFormKey('logger_is_enabled')] = [
      '#type' => 'checkbox',
      '#title' => t('Enable logging'),
      '#description' => t('Enable to track processed API data and events'),
      '#default_value' => $this->getDefaultValue('logger_is_enabled'),
    ];

    $form[$this->getFormKey('debug_request')] = [
      '#type' => 'checkbox',
      '#title' => t('Debug requests'),
      '#description' => t("Print debug information about performed requests into browser's console."),
      '#default_value' => $this->getDefaultValue('debug_request'),
    ];

    return $form;
  }

  /**
   * Recursively set form element states.
   */
  protected function setElementStates(&$form, Provider $provider) {
    $form['#states']['visible'][':input[name="' . $this->getFormKey('provider') . '"]'] = ['value' => $provider->getName()];

    foreach (element_children($form) as $key) {
      $this->setElementStates($form[$key], $provider);
    }
  }

  /**
   * Collect provider settings forms.
   */
  protected function collectProviderForms($form, &$form_state) {
    $this->formStackPush('provider_config');

    /** @var \Drupal\vu_rp_api\Provider\Provider $provider */
    foreach ($this->providerManager->getAll() as $provider) {
      // Fieldset to group each provider settings.
      $provider_container = [
        '#type' => 'fieldset',
        '#title' => $provider->getTitle(),
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#tree' => TRUE,
        '#states' => [
          // Show only when relevant provider is selected.
          'visible' => [
            ':input[name="' . $this->getFormKey('provider') . '"]' => ['value' => $provider->getName()],
          ],
        ],
      ];

      $this->formStackPush($provider->getName());
      $endpoints = $provider->getEndpoints();
      /** @var \Drupal\vu_rp_api\Endpoint\Endpoint $endpoint */
      foreach ($endpoints as $endpoint) {
        $this->formStackPush($endpoint->getName());
        $provider_form[$endpoint->getName()] = $this->buildEndpointForm($form, $form_state, $provider, $endpoint);
        $this->formStackPop();
      }

      $this->setElementStates($provider_form, $provider);

      $form[$this->getFormKey('provider_config')][$provider->getName()] = $provider_container + $provider_form;
      // Allow provider settings to be stored as a correct structure.
      $form[$this->getFormKey('provider_config')]['#tree'] = TRUE;
      $this->formStackPop();
    }

    $this->alterRequiredStates($form);
    $this->formStackPop();

    return $form;
  }

  /**
   * Build endpoint config form.
   */
  protected function buildEndpointForm($form, $form_state, Provider $provider, Endpoint $endpoint) {
    $form = [
      '#title' => t('Endpoint: @title', ['@title' => $endpoint->getTitle()]),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    ];

    $form += $this->collectEndpointForms($form, $form_state, $provider, $endpoint);

    $form['schema'] = [
      '#title' => t('Schema'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ];
    $form['schema']['value'] = [
      '#markup' => '<pre>' . $endpoint->getFieldMapper()->renderSchema() . '</pre>',
    ];

    return $form;
  }

  /**
   * Collect all implemented endpoint forms.
   *
   * @see hook_vu_rp_api_PROVIDER_ENDPOINT_form()
   */
  protected function collectEndpointForms($form, $form_state, Provider $provider, Endpoint $endpoint) {
    $hook = 'vu_rp_api_' . $provider->getName() . '_' . $endpoint->getName() . '_form';

    $form = module_invoke_all($hook, $form, $form_state, $this);

    return $form;
  }

  /**
   * Alter form element to process required fields that use States API.
   *
   * Recursively scan $element and replace any required fields, which also use
   * State API and are depending on other fields, with State API-aware
   * behaviour.
   * Specifically, '#required' attribute is unset and replaced with 'required'
   * States API entry and a validation callback.
   *
   * @param mixed $element
   *   Element passed by reference.
   *
   * @return array
   *   Element with processed fields.
   */
  protected function alterRequiredStates(&$element) {
    if (!empty($element['#required']) && isset($element['#states']['visible'])) {
      // Make field non-required - validation callback and States API 'required'
      // entry will make sure that the fields still behaves as required.
      $element['#required'] = FALSE;
      // Add per-element validation callback. It will make sure that current
      // field will be considered required only if it's dependee (the field that
      // controls visibility of the current field) is set to the value that
      // triggers current element's visibility.
      //
      // Since Drupal does not use call_user_func_array() when calling dynamic
      // functions, we cannot pass a method of this class and have to use
      // separate validation function.
      $element['#element_validate'][] = '_vu_rp_api_states_required_validate';
      // Copy visibility States API entries to 'required' entries to correctly
      // show required marker (and other front-end properties) for the field.
      $element['#states']['required'] = !empty($element['#states']['required']) ? $element['#states']['required'] : [];
      $element['#states']['required'] += $element['#states']['visible'];
    }

    foreach (element_children($element) as $k) {
      $element[$k] = $this->alterRequiredStates($element[$k]);
    }

    return $element;
  }

  /**
   * Validation callback for required fields using States API.
   */
  public static function elementValidateRequiredFields($element, $form_state) {
    // Check that current dependent field uses States API and visibility state.
    if (!isset($element['#states']['visible'])) {
      return;
    }

    $valid_field = TRUE;
    foreach (array_keys($element['#states']['visible']) as $dependee_field_expression) {
      // Get the expression of the dependee field.
      $parts = explode('"', $dependee_field_expression);
      if (!isset($parts[1])) {
        // Incorrectly provided expression - does not contain field name.
        continue;
      }
      $dependee_field_name = $parts[1];

      // Make sure that only correctly set states are used.
      if (!isset($element['#states']['visible'][$dependee_field_expression]['value'])) {
        continue;
      }
      $visible_field_value = $element['#states']['visible'][$dependee_field_expression]['value'];

      // Check that the dependee field has the same value as set in visibility
      // states of the current field.
      preg_match_all('/[^\[\]]+/', $dependee_field_name, $matches);
      if (isset($matches[0])) {
        $dependee_parents = $matches[0];
        $dependee_value = drupal_array_get_nested_value($form_state['values'], $dependee_parents);
        if ($dependee_value != $visible_field_value) {
          $valid_field = FALSE;
          break;
        }
      }
    }

    if ($valid_field) {
      $value = drupal_array_get_nested_value($form_state['values'], $element['#array_parents']);
      // Get actual submitted value.
      if (empty($value)) {
        form_set_error(implode('][', $element['#array_parents']), t('@title is required.', ['@title' => $element['#title']]));
      }
    }
  }

  /**
   * Remove an element from the form stack.
   */
  public function formStackPop() {
    return array_pop($this->formStack);
  }

  /**
   * Add an element to the form stack.
   */
  public function formStackPush($item) {
    array_push($this->formStack, $item);
  }

  /**
   * Get current form stack element.
   */
  public function formStackCurrent($item) {
    return end($this->formStack);
  }

}
