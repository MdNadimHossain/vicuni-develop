<?php

/**
 * @file
 * Admin functionality for hubspot field mapping.
 */

/**
 * Form to add new hubspot webform field.
 */
function vu_core_hubspot_map_add_form($form, &$form_state) {
  $form['webform_field_name'] = [
    '#type' => 'textfield',
    '#title' => t('What is the webform field you want to add?'),
    '#required' => TRUE,
    '#size' => 100,
    '#maxlength' => 100,
  ];

  $form['crm_field_name'] = [
    '#type' => 'textfield',
    '#title' => t('What is the HubSpot field you want to add?'),
    '#required' => TRUE,
    '#size' => 100,
    '#maxlength' => 100,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
  ];

  $form['cancel'] = [
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => ['vu_core_hubspot_map_add_form_cancel'],
    '#limit_validation_errors' => [],
  ];

  return $form;
}

/**
 * Hubspot webform fields addition submission handler.
 */
function vu_core_hubspot_map_add_form_submit($form, &$form_state) {
  $webform_field_name = $form_state['values']['webform_field_name'];
  $crm_field_name = $form_state['values']['crm_field_name'];

  // Dont save field if already present.
  if (vu_core_hubspot_map_is_existing_field($webform_field_name)) {
    drupal_set_message(t('The webform field you are trying to add already exist.'), 'error');
  }
  else {
    vu_core_hubspot_map_record_save($webform_field_name, $crm_field_name);
    drupal_set_message(t('Successfully saved HubSpot webform field.'));
    drupal_goto('admin/config/hubspot/fields/list');
  }
}

/**
 * Webform fields list cancel handler.
 */
function vu_core_hubspot_map_add_form_cancel($form, &$form_state) {
  drupal_goto('admin/config/hubspot/fields/list');
}

/**
 * Form to delete a specific webform field.
 */
function vu_core_hubspot_map_delete_form($form, &$form_state) {
  $form['webform_field_name'] = [
    '#type' => 'textfield',
    '#title' => t('What is the webform field you want to delete?'),
    '#required' => TRUE,
    '#size' => 100,
    '#maxlength' => 100,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#attributes' => ['onclick' => 'if(!confirm("Are you sure you want to delete this field?")){return false;}'],
  ];

  $form['cancel'] = [
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => ['vu_core_hubspot_map_add_form_cancel'],
    '#limit_validation_errors' => [],
  ];

  return $form;
}

/**
 * Hubspot webform fields deletion submission handler.
 */
function vu_core_hubspot_map_delete_form_submit($form, &$form_state) {
  $webform_field_name = $form_state['values']['webform_field_name'];
  if (vu_core_hubspot_map_is_existing_field($webform_field_name)) {
    vu_core_hubspot_map_record_delete($webform_field_name);
    drupal_set_message(t('Successfully deleted webform field from the master map.'));
    drupal_goto('admin/config/hubspot/fields/list');
  }
  else {
    drupal_set_message(t('The webform field does not exist.'), 'error');
  }
}
