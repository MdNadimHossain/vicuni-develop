<?php

/**
 * @file
 * Admin functionality for Researchers list.
 */

/**
 * Form to add new Staff ID.
 */
function vu_rp_list_add_form($form, &$form_state) {
  $form['staff_id'] = [
    '#type' => 'textfield',
    '#title' => t('What is the staff ID of the new researcher?'),
    '#required' => TRUE,
    '#size' => 20,
    '#maxlength' => 8,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
  ];

  $form['cancel'] = [
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => ['vu_rp_list_add_form_cancel'],
    '#limit_validation_errors' => [],
  ];

  $form['#validate'][] = 'vu_rp_list_add_form_validate';

  return $form;
}

/**
 * Researcher list addition validation handler.
 */
function vu_rp_list_add_form_validate($form, &$form_state) {
  $staff_id = $form_state['values']['staff_id'];

  // Validate format.
  try {
    vu_core_staff_id_validate($staff_id);
  }
  catch (Exception $exception) {
    form_set_error('staff_id', $exception->getMessage());
  }

  if (vu_rp_list_is_existing_staff_id($staff_id)) {
    form_set_error('staff_id', t('Staff ID already exists.'));
  }
}

/**
 * Researcher list addition submission handler.
 */
function vu_rp_list_add_form_submit($form, &$form_state) {
  $staff_id = vu_core_normalise_staff_id($form_state['values']['staff_id']);
  vu_rp_list_record_save($staff_id);

  drupal_set_message(t('Successfully saved Staff ID'));

  drupal_goto('admin/config/researcher-profile/list');
}

/**
 * Researcher list cancel handler.
 */
function vu_rp_list_add_form_cancel($form, &$form_state) {
  drupal_goto('admin/config/researcher-profile/list');
}

/**
 * Form to delete all researchers.
 */
function vu_rp_list_delete_all($form, &$form_state) {
  return confirm_form(
    [],
    t('Are you sure you want to delete all records?'),
    'admin/config/researcher-profile/list',
    t('This action cannot be undone.'),
    t('Delete all records'),
    t('Cancel')
  );
}

/**
 * Submit handler for deletion of all researchers.
 */
function vu_rp_list_delete_all_submit($form, &$form_state) {
  vu_rp_list_record_remove_all();

  drupal_set_message(t('Deleted all researchers from the list'));

  $form_state['redirect'] = 'admin/config/researcher-profile/list';
}
