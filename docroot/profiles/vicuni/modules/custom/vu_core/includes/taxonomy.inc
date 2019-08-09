<?php

/**
 * @file
 * Taxonomy module integration.
 */

/**
 * Implements hook_vu_core_form_alter().
 */
function taxonomy_vu_core_form_alter(&$form, &$form_state, $form_id) {
  // Add validation handler.
  if ($form_id == 'taxonomy_form_term') {
    $form['#validate'][] = 'vu_core_contact_us_link_validate';
  }
}
