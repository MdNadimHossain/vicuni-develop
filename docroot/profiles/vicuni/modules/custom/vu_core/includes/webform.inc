<?php

/**
 * @file
 * Webform module integration.
 */

/**
 * Implements hook_vu_core_form_FORM_ID_alter().
 */
function vu_core_vu_core_form_webform_component_edit_form_alter(&$form, $form_state) {
  if ('file' == $form['type']['#value']) {
    $form['extra']['temporary_scheme']['#type'] = 'value';
    $form['extra']['temporary_scheme']['#value'] = TRUE;
  }
}

/**
 * Implements custom hook_form_alter().
 */
function webform_vu_core_form_alter(&$form, &$form_state, $form_id) {
  // Hide multiple email option.
  if ($form_id == 'webform_component_edit_form') {
    _webform_vu_core_hide_multiple_email_option($form);
  }

  // Disable file addition for users with no access.
  if ($form_id == "webform_components_form") {
    if (isset($form['add']['type']['#options']['file'])) {
      if (!user_access('bypass file access') && !user_access('administer webform file upload')) {
        unset($form['add']['type']['#options']['file']);
      }
    }
  }

  if (!isset($form['#node']) || !is_object($form['#node'])) {
    return;
  }

  if ($form['#node']->type != 'webform') {
    return;
  }

  $form['#validate'][] = 'webform_recapthca_validate_custom';

  $required_instructions = 0;
  if ($form['#node']->status == 1) {
    foreach ($form['#node']->webform['components'] as $component) {
      if ($component['required'] == 1) {
        $required_instructions = 1;
        break;
      }
    }
  }

  if ($required_instructions) {
    $form['#prefix'] = "<div class='required-fields-description'>Information marked with an asterisk \"<span class='form-required'>*</span>\" is required.
    </div>";
  }

  if (!isset($form['#node']->field_webhook_url)) {
    return;
  }

  // Do not set webhook on edit pages.
  $args = arg();
  if (is_numeric($args[1]) && isset($args[2])) {
    return;
  }

  $node = $form['#node'];
  $url = vu_core_extract_single_field_value($node, 'node', 'field_webhook_url', 'url');

  // Do not set submit handler when webhook is empty.
  if (empty($url)) {
    return;
  }

  if (!isset($form['#submit'])) {
    $form['#submit'] = [];
  }

  $form['#submit'][] = '_webform_vu_core_form_submit_webhooks';

}

/**
 * Form submit calback to post form data to external integrations.
 */
function _webform_vu_core_form_submit_webhooks($form, $form_state) {
  if (!isset($form['#node']) || !is_object($form['#node']) || !isset($form['#node']->field_webhook_url)) {
    return;
  }

  $node = $form['#node'];

  $url = vu_core_extract_single_field_value($node, 'node', 'field_webhook_url', 'url');

  // We have to ignore coding standards because it fails
  // recommending to use $form_state['values'] instead
  // it's json encoded and sent elsewere so not an issue.
  // @codingStandardsIgnoreLine
  $form_data = $form_state['input']['submitted'];
  $form_data['form_name'] = $form['#node']->title;
  $form_data['form_url'] = $form['#action'];
  // Add page url.
  $form_data['page_url'] = url(current_path(), ['absolute' => TRUE]);

  // Get campaign parameters.
  $campaign_params = vu_core_get_campaign_parameters();
  $form_data = array_merge($form_data, $campaign_params);

  // Find hidden fields.
  $hidden = [];
  foreach ($form_state['webform']['component_tree']['children'] as $form_element) {
    if ($form_element['type'] == 'hidden') {
      $hidden[$form_element['cid']] = $form_element['form_key'];
    }
  }

  // Add hidden fields to submission.
  foreach ($hidden as $cid => $form_key) {
    $form_data[$form_key] = isset($form_state['values']['submitted'][$cid]) ? $form_state['values']['submitted'][$cid] : '';
  }

  $webhook_submission_method = vu_core_extract_single_field_value($node, 'node', 'field_webhook_submission_method', 'value');
  // If hubspot is selected in the webhook configuration.
  if ($webhook_submission_method == 'Hubspot') {
    // Make the whitelist to submit to hubspot matching to the master map.
    // Need to refactor this part to create the JSON.
    $white_list = vu_core_get_hubspot_webform_fields($form_data);
    $json_string = '{"fields": [';
    $num_of_items = count($white_list);
    $num_count = 0;
    foreach ($white_list as $key => $item) {
      $num_count = $num_count + 1;
      $value = ($num_count == $num_of_items) ? '{"name": "' . $key . '","value":"' . $item . '"}]}' : '{"name":"' . $key . '","value":"' . $item . '"},';
      $json_string = $json_string . ' ' . $value;
    }
    $data = $json_string;
  }
  else {
    $data = json_encode($form_data);
  }
  $content_type = 'application/json';

  $post = 'POST';
  $curl = curl_init($url);
  curl_setopt($curl, CURLOPT_HEADER, FALSE);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($curl, CURLOPT_HTTPHEADER, ["Content-type: $content_type"]);
  curl_setopt($curl, CURLOPT_POST, $post);
  if ($post) {
    curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
  }

  // Make sure errors are  handled.
  try {
    $json_response = curl_exec($curl);

    $status = curl_getinfo($curl, CURLINFO_HTTP_CODE);
    $response_data = json_decode($json_response, TRUE);

    // If not a valid response or response isn't status:"success", log an error.
    // Requestbin just has 'ok' as the response.
    if (($json_response !== 'ok' && $response_data === NULL) || ($status != 200 && $status != 201)) {
      watchdog(
        'vu_core',
        'Error: Webhook post to @url failed with status @status, response @response, curl_error @error',
        [
          '@url' => $url,
          '@status' => $status,
          '@response' => $json_response,
          '@error' => curl_error($curl),
        ],
        WATCHDOG_ERROR
      );
    }
    else {
      $id = isset($response_data['id']) ? $response_data['id'] : '-';
      watchdog(
        'vu_core',
        'Successfully posted "@form" form submission @submission to @endpoint (returned ID: @id)',
        [
          '@form' => $form['#node']->title,
          '@submission' => $form_state['storage']['details']['sid'],
          '@endpoint' => $url,
          '@id' => $id,
        ],
        WATCHDOG_INFO
      );
    }
  }
  catch (Exception $e) {
    watchdog('vu_core', $e->getMessage);
  }

  curl_close($curl);
}

/**
 * Implements reacptcha validation on webform.
 */
function webform_recapthca_validate_custom(&$form, &$form_state) {
  if (empty($_POST['g-recaptcha-response'])) {
    drupal_add_js(drupal_get_path('module', 'vu_core') . '/js/vu_core.recaptcha_validation.js');
  }
}

/**
 * Implements hook_webform_component_render_alter().
 */
function webform_webform_component_render_alter(&$element, &$component) {
  if (isset($component['extra']['width'])) {
    if (!empty($component['extra']['width'])) {
      $element['#attributes']['class'][] = 'field-width-auto';
    }
  }
}

/**
 * Hide multiple email option.
 */
function _webform_vu_core_hide_multiple_email_option(&$form) {
  if (isset($form['extra']['multiple'])) {
    if (!user_access('bypass node access')) {
      $form['extra']['multiple']['#access'] = FALSE;
    }
  }
}

/**
 * Implements hook_permission_alter().
 */
function webform_vu_core_permission_alter(&$permissions) {
  $permissions['administer webform file upload'] = [
    'title' => t('Webform: Add file upload fields to webforms.'),
  ];
}

/**
 * Get hubspot webform fields from db and make a list of matching fields.
 *
 * @return array
 *   hubspot webform fields.
 */
function vu_core_get_hubspot_webform_fields($form_data) {
  $white_list = [];
  $query = db_select('vu_core_hubspot_map', 'hp');
  $query->fields('hp', ['webform_field_name', 'crm_field_name']);
  $query->condition('field_type', 'HS');
  $results = $query->execute()->fetchAllKeyed(0, 1);
  $data = array_intersect_key($form_data, $results);

  // Replacing the key with the HubSpot field names.
  foreach ($data as $origKey => $value) {
    $white_list[$results[$origKey]] = $value;
  }

  return $white_list;
}
