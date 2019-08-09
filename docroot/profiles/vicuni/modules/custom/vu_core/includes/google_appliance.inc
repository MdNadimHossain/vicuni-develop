<?php

/**
 * @file
 * Google Appliance module integration.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function vu_core_form_google_appliance_block_form_alter(&$form, &$form_state) {
  if ($form['#id'] == 'google-appliance-block-form') {
    $form['search_keys']['#title'] = t('Search e.g. courses, units, information, people, facilities');
    $form['search_keys']['#attributes']['placeholder'] = t('Type to search');
    $form['actions']['#attributes']['class'][] = 'col-sm-3';
  }
}
