<?php

/**
 * @file
 * Enables test module and provisions local endpoints.
 */

use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Module;

if (variable_get('environment') == ENVIRONMENT_PROD) {
  General::messageSet('Skipping this update in production environment');

  return;
}

Module::enable('vu_rp_test');

module_load_install('vu_rp');
module_load_include('inc', 'vu_rp_test', 'vu_rp_test.rest');

vu_rp_test_rest_record_delete_all();

$dir = drupal_get_path('module', 'vu_rp_test') . '/test_responses';
$list_created = vu_rp_test_rest_record_update([
  'request_path' => 'researcher/profiles',
  'request_method' => 'GET',
  'response_content' => file_get_contents($dir . DIRECTORY_SEPARATOR . 'profiles.json'),
  'comment' => 'DO NOT REMOVE! List endpoint for Local API provider',
]);
if (!$list_created) {
  throw new UpdaterException('Unable to create a List entry for local REST server');
}
General::messageSet('Created a List entry for Local REST server');

$account_files = array_diff(scandir($dir), ['..', '.', 'profiles.json']);
$staff_ids = [];
foreach ($account_files as $account_file) {
  $staff_id = basename($account_file, '.json');
  $created = vu_rp_test_rest_record_update([
    'request_path' => 'researcher/profile/' . $staff_id,
    'request_method' => 'GET',
    'response_content' => file_get_contents($dir . DIRECTORY_SEPARATOR . $account_file),
    'comment' => sprintf('DO NOT REMOVE! Account "%s" endpoint for Local API provider', $staff_id),
  ]);
  if (!$created) {
    throw new UpdaterException(sprintf('Unable ot create local entry for "%s" account', $staff_id));
  }
  vu_rp_list_record_save($staff_id);
  General::messageSet(sprintf('Created local entry for "%s" account', $staff_id));
  $staff_ids[] = $staff_id;
}

$current_provider = variable_get('vu_rp_api_provider');

$provider_name = in_array(variable_get('environment'), [
  ENVIRONMENT_DEV,
  ENVIRONMENT_TEST,
  ENVIRONMENT_TEST2,
]) ? 'test2' : 'local';

variable_set('vu_rp_api_provider', $provider_name);
vu_rp_api_get_client(TRUE);
foreach ($staff_ids as $staff_id) {
  vu_rp_install_provision_profile($staff_id);
}
variable_set('vu_rp_api_provider', $current_provider);
vu_rp_api_get_client(TRUE);
