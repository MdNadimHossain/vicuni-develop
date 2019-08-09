<?php

/**
 * @file
 * Admin UI for Researcher Profile configuration.
 */

/**
 * Provides UI to configure Researchers Profiles.
 */
function vu_rp_admin_settings($form) {
  $form['vu_rp_helpdesk_email'] = [
    '#type' => 'textfield',
    '#title' => t('Helpdesk email'),
    '#description' => t('Email displayed on the form for Researchers to contact'),
    '#default_value' => variable_get('vu_rp_helpdesk_email', 'researcher.profiles@vu.edu.au'),
    '#required' => TRUE,
  ];

  return system_settings_form($form);
}

/**
 * Form validation handler for vu_rp_admin_settings().
 */
function vu_rp_admin_settings_validate($form, &$form_state) {
  $email = $form_state['values']['vu_rp_helpdesk_email'];
  if (!valid_email_address($email)) {
    form_set_error('vu_rp_helpdesk_email', t('"%mail" is not a valid email address', ['%mail' => $email]));
  }
}
