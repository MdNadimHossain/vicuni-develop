<?php

/**
 * @file
 * Provisions UAT Research Profile nodes and Drupal accounts for testing.
 */

use Drupal\drupal_helpers\General;

if (variable_get('environment') == ENVIRONMENT_PROD) {
  General::messageSet('Skipping update in production environment');

  return;
}

$staff_ids = [
  'E5031313' => TRUE,
  'E5102381' => TRUE,
  'E5108742' => TRUE,
  'E5100342' => TRUE,
  'E5109076' => TRUE,
  'E5022387' => TRUE,
  'E5106262' => FALSE,
  'E5105530' => FALSE,
  'E5013585' => FALSE,
  'E5110215' => FALSE,
  'E5107118' => FALSE,
  'E5102720' => FALSE,
];

module_load_install('vu_rp');
module_load_include('module', 'vu_rp_list', 'vu_rp_list');

$count = 0;
foreach ($staff_ids as $staff_id => $should_provision) {
  $count++;

  $users = vu_core_create_role_test_users(1, ['Researcher'], $staff_id . '_');
  $user = reset($users);
  $user = user_load($user->uid);
  $cas_name = substr($staff_id, 1);
  user_save($user, ['cas_name' => $cas_name]);
  vu_rp_list_record_save($staff_id);

  if (!$should_provision) {
    General::messageSet(sprintf('Skipping creation of the profile node for staff id %s', $staff_id), '-- ', 4);
    continue;
  }

  vu_rp_install_provision_profile($staff_id);
}

General::messageSet('Finishing provisioning of Researcher Profiles for UAT accounts');
