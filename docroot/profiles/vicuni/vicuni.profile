<?php

/**
 * @file
 * Enables modules and site configuration for a vicuni site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function vicuni_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Ensures that the core PHP filter module does not get enabled.
 */
function vicuni_form_system_modules_alter(&$form, &$form_state) {
  unset($form['modules']['Core']['php']);
}
