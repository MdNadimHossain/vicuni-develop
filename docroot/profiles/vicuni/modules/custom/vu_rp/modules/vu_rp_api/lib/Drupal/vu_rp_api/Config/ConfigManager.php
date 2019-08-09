<?php

namespace Drupal\vu_rp_api\Config;

/**
 * Class ConfigManager.
 *
 * Used for all configuration interactions with Drupal's config storage system.
 *
 * @package Drupal\vu_rp_api\Config
 */
class ConfigManager {

  /**
   * Variable name to store provider configuration.
   */
  const VARIABLE_PROVIDER_CONFIG = 'vu_rp_api_provider_config';

  /**
   * Variable name to store current provider ID.
   */
  const VARIABLE_PROVIDER_CURRENT_ID = 'vu_rp_api_provider';

  /**
   * Variable to store current provider class.
   */
  const VARIABLE_HTTP_CLIENT_CLASS = 'vu_rp_api_http_client_class';

  /**
   * Variable to store flag to debug requests.
   */
  const VARIABLE_DEBUG_REQUEST = 'vu_rp_api_debug_request';

  /**
   * Get stored entity ids.
   */
  public function getStoredEntityIds($entity_type) {
    $value = $this->variableGet($this->makeEntityVariable($entity_type));

    return is_array($value) ? $value : [$value];
  }

  /**
   * Helper to make a variable name.
   */
  protected function makeEntityVariable($entity_type) {
    return $this->buildConfigKey($entity_type);
  }

  /**
   * Get configuration for entity type and id.
   */
  public function getConfig($entity_type, $entity_id) {
    return $this->getValue([$entity_type . '_config', $entity_id]);
  }

  /**
   * Get the ID of the currently selected provider.
   *
   * @return string
   *   ID of the currently selected provider.
   */
  public function getCurrentProviderId() {
    return $this->variableGet(self::VARIABLE_PROVIDER_CURRENT_ID);
  }

  /**
   * Get configuration for all providers.
   *
   * @return array
   *   Array of configuration from storage.
   */
  public function getConfigProviderAll() {
    return $this->variableGet(self::VARIABLE_PROVIDER_CONFIG, []);
  }

  /**
   * Get configuration for a single provider.
   *
   * @param string $provider_id
   *   Provider ID.
   *
   * @return mixed
   *   Stored configuration for provider.
   */
  public function getConfigProvider($provider_id) {
    $configs = $this->getConfigProviderAll();

    return isset($configs[$provider_id]) ? $configs[$provider_id] : NULL;
  }

  /**
   * Get currently set HTTP client class.
   *
   * @param string $default
   *   Optional default class name.
   *
   * @return string
   *   Currently set HTTP client class name.
   */
  public function getHttpClientClass($default = NULL) {
    return $this->variableGet(self::VARIABLE_HTTP_CLIENT_CLASS, $default);
  }

  /**
   * Get flag that specifies if request debug information should be used.
   *
   * @return bool
   *   TRUE if debug information should be printed, FALSE otherwise.
   */
  public function getDebugRequest() {
    return $this->getValue('debug_request');
  }

  /**
   * Check if log is enabled.
   */
  public function logIsEnabled() {
    return $this->getValue('logger_is_enabled');
  }

  /**
   * Get variable with name.
   *
   * @see variable_get()
   */
  protected function variableGet($name, $default = NULL) {
    return variable_get($name, $default);
  }

  /**
   * Set variable with name.
   *
   * @see variable_set()
   */
  protected function variableSet($name, $value) {
    variable_set($name, $value);
  }

  /**
   * Get multiple variables with depth.
   *
   * @param array $names
   *   Array of variables to retrieve.
   * @param array $parents
   *   Optional array of parent variable keys to traverse. If not specified,
   *   each provided name is considered to be in the root of the variable
   *   container.
   * @param mixed $default
   *   Optional default value to return if no valid value was found.
   *
   * @return array
   *   Array of variable values keyed by name.
   */
  protected function variableGetBulk(array $names, array $parents = [], $default = NULL) {
    $variables = [];

    foreach ($names as $name) {
      if (count($parents) > 0) {
        $container_name = reset($parents);
        $container = $this->variableGet($container_name, []);
        $value = drupal_array_get_nested_value($container, array_merge(array_slice($parents, 1), [$name]));
        if (!is_null($default) || !is_null($value)) {
          $variables[$name] = $value;
        }
      }
      else {
        $variables[$name] = $this->variableGet($name, $default);
      }
    }

    return $variables;
  }

  /**
   * Build configuration key from provided arguments.
   */
  public function buildConfigKey() {
    return 'vu_rp_api_' . implode('_', func_get_args());
  }

  /**
   * Set configuration value.
   *
   * @param string $name
   *   Variable name.
   * @param mixed $value
   *   Value.
   * @param bool $use_prefix
   *   Optional flag to use config prefix. Default to TRUE. If FALSE, the value
   *   is set in 'global' context (i.e., as plan Drupal variable with some
   *   specified name).
   */
  public function setValue($name, $value, $use_prefix = TRUE) {
    if ($use_prefix) {
      $name = $this->buildConfigKey($name);
    }

    $this->variableSet($name, $value);
  }

  /**
   * Get configuration value.
   *
   * @param string $name
   *   Value name.
   * @param null $default
   *   Default value if value does not exist.
   * @param bool $use_prefix
   *   Get internal or global value. Defaults to internal.
   *
   * @return array|mixed|null
   *   Configuration value.
   */
  public function getValue($name, $default = NULL, $use_prefix = TRUE) {
    $children = [];
    if (is_array($name)) {
      $children = array_slice($name, 1);
      $name = reset($name);
    }

    if ($use_prefix) {
      $name = $this->buildConfigKey($name);
    }
    $value = $this->variableGet($name, $default);

    if ($value && $children) {
      $value = drupal_array_get_nested_value($value, $children);
    }

    return $value;
  }

  /**
   * Get global value.
   */
  public function getValueGlobal($name, $default = NULL) {
    return $this->getValue($name, $default, FALSE);
  }

  /**
   * Lookup value within configuration tree.
   */
  protected function lookupValue($name, $config, $default) {
    $value = $default;

    if (isset($config[$name])) {
      $value = !is_null($config[$name]) ? $config[$name] : $default;
    }
    elseif (is_array($config)) {
      foreach ($config as $config_value) {
        $value = $this->lookupValue($name, $config_value, $default);
        if (!is_null($value)) {
          break;
        }
      }
    }

    return !is_null($value) ? $value : $default;
  }

}
