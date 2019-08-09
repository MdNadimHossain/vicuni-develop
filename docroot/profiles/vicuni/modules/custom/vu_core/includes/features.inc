<?php

/**
 * @file
 * Features module integration.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function vu_core_form_features_admin_form_alter(&$form, &$form_state, $form_id) {
  // Move vu vertical tab to the top.
  $form['package_vu']['#weight'] = -100;
}
