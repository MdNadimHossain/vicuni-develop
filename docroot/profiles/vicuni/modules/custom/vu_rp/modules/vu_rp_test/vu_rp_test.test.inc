<?php

/**
 * @file
 * Functionality used by automated tests.
 *
 * How this works:
 * 1. Tests (usually Behat tests) set a site in the test mode by setting a
 *    variable defined in vu_rp_test_variable_name_is_test_mode().
 * 2. Functions in this file implement hooks to alter existing behaviour if
 *    the site is in the test mode.
 * 3. Tests unset the test mode variable after the test is finished.
 *
 * @note: We are using test variable instead of enabling/disabling the whole
 * test module to increase test performance.
 *
 * An example of alteration hook could be a view of nodes. Such view would
 * already have some production data that would interfere with data provisioned
 * during tests. We would implement hook_view_query_alter() to only return
 * entries whose title starts with `[TEST]` (this is why we use such prefix for
 * all entries created within Behat tests).
 */

/**
 * Returns variable name used to determine if the site runs in the tes mode.
 */
function vu_rp_test_variable_name_is_test_mode() {
  return 'vu_rp_test_is_test_mode';
}

/**
 * Returns variable name used to store REST responses.
 */
function vu_rp_test_variable_name_test_rest_responses_list() {
  return 'vu_rp_test_rest_responses_list';
}

/**
 * Check if site is running in test mode.
 */
function vu_rp_test_is_test_mode() {
  return variable_get(vu_rp_test_variable_name_is_test_mode(), FALSE);
}

/**
 * Implements hook_vu_rp_test_rest_response_alter().
 */
function vu_rp_test_vu_rp_test_rest_response_alter(&$item) {
  // In test mode, alter responses if they are not what tests expect.
  if (vu_rp_test_is_test_mode()) {
    $allowed_test_responses = variable_get(vu_rp_test_variable_name_test_rest_responses_list());
    if (!in_array($item['request_path'], $allowed_test_responses)) {
      $item = FALSE;
    }
  }
}
