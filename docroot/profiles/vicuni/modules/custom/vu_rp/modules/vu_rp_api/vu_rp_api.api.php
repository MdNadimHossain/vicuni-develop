<?php

/**
 * @file
 * Hooks provided by vu_rp_api module.
 */

use Drupal\vu_rp_api\Client\RestInterface;
use Drupal\vu_rp_api\Endpoint\FieldMapper;
use Drupal\vu_rp_api\FormBuilder;

/**
 * Return array of provider machine name and titles.
 */
function hook_vu_rp_api_providers() {
  return [
    'myprovider' => t('MyProvider'),
  ];
}

/**
 * Returns endpoints information.
 */
function hook_vu_rp_api_endpoints() {
  return [
    // Key is a machine name of the endpoint.
    'listing' => [
      // Title of the endpoint.
      'title' => t('Listing'),
      // Method to use to retrieve the data.
      'method' => RestInterface::METHOD_GET,
      // Format of data received by the endpoint.
      'format' => RestInterface::FORMAT_JSON,
      // Default timeout.
      'timeout' => 180,
      // Schema definition.
      // @see my_module_endpoint_listing_schema_callback() below.
      'schema' => my_module_endpoint_listing_schema_callback(),
    ],
  ];
}

/**
 * Example of the endpoint schema definition.
 */
function my_module_endpoint_listing_schema_callback() {
  return [
    // Some to group data.
    'some_key' => [
      // The key needs to be mapped as 'root' to allow traversal to the actual
      // data.
      'is_root' => TRUE,
      // Type of value for this key.
      'type' => FieldMapper::TYPE_ARRAY,
      // Children as array.
      'children' => [
        // Key is a source field name.
        'staffID' => [
          // Type of the field. If value will be of different type - the data
          // validation will fail the mapping and throw an exception.
          'type' => FieldMapper::TYPE_STRING,
          // Shorthand mapping to the Drupal field on the entity.
          'field' => 'field_rpa_staff_id',
          // Special field to set this field as a primary. Used to build unique
          // entries. Multiple fields may be set as primary (compound keys).
          'is_primary' => TRUE,
        ],
        'firstName' => [
          'field' => 'field_rpa_first_name',
          // Callback to process this field.
          'callback' => 'vu_rp_api_field_callback_first_name',
        ],
        // Shorthand to process src=>dst using default callback.
        'orcID' => 'field_rpa_orcid_id',
        'publications' => [
          'type' => FieldMapper::TYPE_ARRAY,
          // Some random name of the non-existing field. This field's values
          // will be set in the callback.
          'field' => 'MULTIPLE_FIELDS_IN_CALLBACK',
          'callback' => 'vu_rp_api_field_callback_publications',
          'children' => [
            // Still need to put field types for validation to work.
            'type' => FieldMapper::TYPE_STRING,
          ],
        ],
      ],
    ],
  ];
}

/**
 * Allows to determine if imported account is blacklisted.
 *
 * @param bool $is_blacklisted
 *   Current item state passed by reference.
 * @param mixed $id
 *   ID used to identify account.
 */
function hook_vu_rp_api_account_is_blacklisted_alter(&$is_blacklisted, $id) {
  $allowed_ids = [1, 2, 3];

  $is_blacklisted = in_array($id, $allowed_ids);
}

/**
 * Provider's endpoint configuration form.
 *
 * Used to integrate with other API settings.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   Form state.
 * @param \Drupal\vu_rp_api\FormBuilder $form_builder
 *   Special form builder instance that allows to have access to provider
 *   configuration and default values.
 */
function hook_vu_rp_api_PROVIDER_ENDPOINT_form($form, $form_state, FormBuilder $form_builder) {
  $form['url'] = [
    '#type' => 'textfield',
    '#title' => t('Listing URL'),
    '#required' => TRUE,
    // 'url' is the key in the form.
    '#default_value' => $form_builder->getDefaultValue('url'),
  ];

  return $form;
}

/**
 * Log logger event.
 */
function hook_vu_rp_api_logger_log($event, $message, $severity) {
  watchdog($event, (string) $message, [], $severity);
}
