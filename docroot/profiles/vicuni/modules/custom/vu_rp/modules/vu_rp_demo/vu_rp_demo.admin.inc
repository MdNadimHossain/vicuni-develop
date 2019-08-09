<?php

/**
 * @file
 * Admin UI for content generation.
 */

/**
 * Provides UI to provision researcher profile demo content.
 */
function vu_rp_demo_provision_form() {
  $form['steps'] = [
    '#type' => 'checkboxes',
    '#title' => t('Demo content'),
    '#options' => array_combine(vu_rp_demo_get_all_steps(), array_map(function ($value) {
      return ucfirst(str_replace('_', ' ', $value));
    }, vu_rp_demo_get_all_steps())),
  ];

  $form['page_link'] = [
    '#markup' => l(t('Demo content page'), 'demo-content'),
  ];

  $form['actions'] = [
    '#type' => 'container',
  ];

  $form['actions']['provision'] = [
    '#type' => 'submit',
    '#value' => 'Provision content',
    '#name' => 'provision',
  ];

  $form['actions']['remove'] = [
    '#type' => 'submit',
    '#value' => 'Remove all provisioned content',
    '#name' => 'remove',
  ];

  return $form;
}

/**
 * Content provision form validation callback.
 */
function vu_rp_demo_provision_form_validate($form, $form_state) {
  if ($form_state['triggering_element']['#name'] == 'provision') {
    if (count(array_filter($form_state['values']['steps'])) == 0) {
      form_set_error('steps', t('Please select at least one step'));
    }
  }
}

/**
 * Content provision form submit callback.
 */
function vu_rp_demo_provision_form_submit($form, $form_state) {
  if ($form_state['triggering_element']['#name'] == 'provision') {
    try {
      vu_rp_demo_process_provision_steps(array_keys(array_filter($form_state['values']['steps'])));
    }
    catch (Exception $exception) {
      drupal_set_message($exception->getMessage(), 'error');
    }
  }
  elseif ($form_state['triggering_element']['#name'] == 'remove') {
    vu_rp_demo_records_remove_all(TRUE);
    // Remove error messages as file_delete() does not properly validate file
    // existence and throws warnings.
    drupal_get_messages();
    drupal_set_message(t('Removed all provisioned content'));
  }
}
