<?php

/**
 * @file
 * VU Researcher Profile Researchers test module REST server functions.
 */

use Drupal\vu_rp_api\Client\RestInterface;

/**
 * Menu callback for rest server.
 */
function vu_rp_test_rest_callback() {
  $method = RestInterface::METHOD_GET;
  if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $method = RestInterface::METHOD_POST;
  }

  $path = str_replace(arg(0), '', request_path());
  $path = trim($path, '/');
  $item = vu_rp_test_rest_record_find_by_path($path, $method);

  drupal_alter('vu_rp_test_rest_response', $item);

  vu_rp_test_rest_record_render($item);
}

/**
 * Render reset record.
 */
function vu_rp_test_rest_record_render($record) {
  if (!$record) {
    drupal_not_found();
  }

  drupal_add_http_header('Content-Type', 'application/json');
  echo $record['response_content'];
}

/**
 * Form to add new REST server record.
 */
function vu_rp_test_rest_server_record_add_form($form, &$form_state, $id = NULL) {
  $record = NULL;
  if ($id) {
    $form['id'] = [
      '#type' => 'value',
      '#value' => $id,
    ];
    $record = vu_rp_test_rest_record_load($id);
  }

  $form['request_path'] = [
    '#type' => 'textfield',
    '#title' => t('Request path'),
    '#field_prefix' => '/' . VU_RP_TEST_REST_URL_PREFIX . '/',
    '#required' => TRUE,
    '#default_value' => $record ? $record['request_path'] : NULL,
  ];
  $form['request_method'] = [
    '#type' => 'radios',
    '#title' => t('Request method'),
    '#options' => [
      RestInterface::METHOD_GET => RestInterface::METHOD_GET,
      RestInterface::METHOD_POST => RestInterface::METHOD_POST,
    ],
    '#required' => TRUE,
    '#default_value' => $record ? $record['request_method'] : NULL,
  ];

  $form['response_content'] = [
    '#type' => 'textarea',
    '#title' => t('Response content'),
    '#default_value' => $record ? $record['response_content'] : NULL,
    '#rows' => 15,
  ];

  $form['comment'] = [
    '#type' => 'textarea',
    '#title' => t('Comment'),
    '#default_value' => $record ? $record['comment'] : NULL,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
  ];

  return $form;
}

/**
 * Form validation handler to add new REST server record.
 */
function vu_rp_test_rest_server_record_add_form_validate($form, &$form_state) {
  // Validate that not adding an existing item.
  if (!isset($form_state['values']['id'])) {
    $record = vu_rp_test_rest_record_find_by_path($form_state['values']['request_path'], $form_state['values']['request_method']);
    if ($record) {
      form_set_error('request_path', t('Provided path with method already exist'));
    }
  }
}

/**
 * Form submit handler to add new REST server record.
 */
function vu_rp_test_rest_server_record_add_form_submit($form, &$form_state) {
  $id = NULL;
  $operation = 'created';

  if (isset($form_state['values']['id'])) {
    $id = $form_state['values']['id'];
    $operation = 'updated';
  }
  $saved = vu_rp_test_rest_record_update($form_state['values'], $id);

  if ($saved) {
    drupal_set_message(t('Successfully @operation record', ['@operation' => $operation]));
    $form_state['redirect'] = 'admin/config/researcher-profile/rest-server';
  }
  else {
    drupal_set_message(t('Unable to @operation record', ['@operation' => $operation]), 'error');
  }
}

/**
 * Form to delete REST server record.
 */
function vu_rp_test_rest_server_record_delete_form($form, &$form_state, $id = NULL) {
  return confirm_form(
    [
      'id' => [
        '#type' => 'value',
        '#value' => $id,
      ],
    ],
    t('Are you sure you want to delete this record?'),
    'admin/config/researcher-profile/rest-server',
    t('This action cannot be undone.'),
    t('Delete record'),
    t('Cancel')
  );
}

/**
 * Form submit handler to delete REST server record.
 */
function vu_rp_test_rest_server_record_delete_form_submit($form, &$form_state) {
  $id = isset($form_state['values']['id']) ? $form_state['values']['id'] : NULL;

  if ($id) {
    $deleted = vu_rp_test_rest_record_delete($id);
    if ($deleted) {
      drupal_set_message(t('Successfully delete record @id', ['@id' => $id]));
    }
    else {
      drupal_set_message(t('Unable to delete record @id', ['@id' => $id]), 'error');
    }
  }

  $form_state['redirect'] = 'admin/config/researcher-profile/rest-server';
}

/**
 * Pager callback to list all REST server records.
 */
function vu_rp_test_rest_server_list_callback() {
  $output = '';

  $output .= '<div class="admin-panel">';
  $output .= l(t('+ Add new record'), 'admin/config/researcher-profile/rest-server/add');
  $output .= '</div>';

  $records = vu_rp_test_rest_record_get_all();

  $header = ['Method', 'Path', 'Content', 'Comments', 'Actions'];
  $rows = [];
  foreach ($records as $id => $record) {
    $rows[] = [
      $record['request_method'],
      l($record['request_path'], VU_RP_TEST_REST_URL_PREFIX . '/' . $record['request_path']),
      truncate_utf8($record['response_content'], 144, FALSE, TRUE),
      $record['comment'],
      l(t('Edit'), "admin/config/researcher-profile/rest-server/$id/edit") . ' | ' . l(t('Delete'), "admin/config/researcher-profile/rest-server/$id/delete"),
    ];
  }

  $output .= theme('table', [
    'header' => $header,
    'rows' => $rows,
    'empty' => t('There are no records. Click !link to add some records', [
      '!link' => l(t('here'), 'admin/config/researcher-profile/rest-server/add'),
    ]),
  ]);

  return $output;
}

/**
 * Update REST server records.
 *
 * @param array $values
 *   Values to update.
 * @param null $id
 *   Existing id. If not provided, the record will be created.
 *
 * @return int
 *   The result of adding a record.
 */
function vu_rp_test_rest_record_update($values, $id = NULL) {
  $defaults = [
    'request_path' => '',
    'request_method' => RestInterface::METHOD_GET,
    'response_content' => '',
    'comment' => '',
  ];

  $values = array_intersect_key($values, $defaults);
  $values += $defaults;

  // Make sure that prefix is always stripped.
  if (strpos($values['request_path'], VU_RP_TEST_REST_URL_PREFIX . '/') === 0) {
    $values['request_path'] = substr($values['request_path'], 0, strlen(VU_RP_TEST_REST_URL_PREFIX . '/'));
  }
  $values['request_path'] = trim($values['request_path'], '/');

  if ($id) {
    return db_update('vu_rp_test_rest_responses')
      ->fields($values)
      ->condition('id', $id)
      ->execute();
  }

  return db_insert('vu_rp_test_rest_responses')
    ->fields($values)
    ->execute();
}

/**
 * Load specific REST server record.
 */
function vu_rp_test_rest_record_load($id) {
  return db_select('vu_rp_test_rest_responses', 'ts')
    ->fields('ts')
    ->condition('id', $id)
    ->execute()
    ->fetchAssoc();
}

/**
 * Find specific REST server record by path.
 */
function vu_rp_test_rest_record_find_by_path($path, $method = RestInterface::METHOD_GET) {
  return db_select('vu_rp_test_rest_responses', 'ts')
    ->fields('ts')
    ->condition('request_path', $path)
    ->condition('request_method', $method)
    ->execute()
    ->fetchAssoc();
}

/**
 * Get all REST server records.
 */
function vu_rp_test_rest_record_get_all() {
  $records = [];

  $query = db_select('vu_rp_test_rest_responses', 'ts');
  $query->fields('ts');
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $records[$record['id']] = $record;
  }

  return $records;
}

/**
 * Delete specific REST server record.
 */
function vu_rp_test_rest_record_delete($id) {
  return db_delete('vu_rp_test_rest_responses')
    ->condition('id', $id)
    ->execute();
}

/**
 * Delete all REST server records.
 */
function vu_rp_test_rest_record_delete_all() {
  db_truncate('vu_rp_test_rest_responses')->execute();
}
