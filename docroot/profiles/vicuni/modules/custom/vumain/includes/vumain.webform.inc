<?php

/**
 * @file
 * Define access control for webform submissions and results.
 */

/**
 * Implements hook_webform_submission_access().
 */
function vumain_webform_submission_access($node, $submission, $op = 'view', $account = NULL) {
  return vumain_webform_results_access($node, $account);
}

/**
 * Implements hook_webform_results_access().
 */
function hook_webform_results_access($node, $account) {
  return vumain_webform_results_access($node, $account);
}

/**
 * Restrict access to webform submissions / results.
 *
 * @param object $node
 *   Webform node object.
 * @param object $account
 *   Drupal user object.
 *
 * @return bool
 *   TRUE or FALSE indication of user's access to the webform results.
 */
function vumain_webform_results_access($node, $account) {
  // Only continue checking access for authenticated users.
  if (user_is_anonymous()) {
    return FALSE;
  }

  // Administrators are allowed through, always.
  if (user_access('administer site configuration')) {
    return TRUE;
  }

  if (!empty($node->field_results_user_access)) {
    $users_array = $node->field_results_user_access[$node->language];
    // Loop over array of users and return TRUE if current user's
    // uid is found in the field.
    foreach ($users_array as $key => $user) {
      if ($user['target_id'] == $account->uid) {
        return TRUE;
      }
    }
  }

  // Catch-all.
  return FALSE;
}
