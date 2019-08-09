<?php

/**
 * @file
 * Update Researcher Profile Tester permissions.
 */

$parent_role = user_role_load_by_name('Researcher Profile Admin');
if ($parent_role) {
  $admin_perms = user_role_permissions([$parent_role->rid => $parent_role->name]);
  $test_perms = $admin_perms[$parent_role->rid];

  $tester_role = user_role_load_by_name('Researcher Profile Tester');
  if ($tester_role) {
    $test_perms['modify researcher profile api fields'] = TRUE;
    $test_perms['administer test rest server'] = TRUE;
    $test_perms['administer researcher profile configuration'] = TRUE;
    $test_perms['clear researcher profile api log'] = TRUE;
    $test_perms['access site reports'] = TRUE;
    $test_perms['admin queue_ui'] = TRUE;
    $test_perms['access content overview'] = TRUE;
    $test_perms['view the administration theme'] = TRUE;

    if (module_exists('vu_rp_api')) {
      $test_perms['administer researcher profile api configuration'] = TRUE;
    }
    if (module_exists('vu_rp_log')) {
      $test_perms['access researcher profile api log'] = TRUE;
    }
    if (module_exists('vu_rp_demo')) {
      $test_perms['provision researcher profile demo content'] = TRUE;
    }
    if (module_exists('elysia_cron')) {
      $test_perms['view elysia_cron'] = TRUE;
      $test_perms['execute elysia_cron'] = TRUE;
    }
    if (module_exists('queue_ui')) {
      $test_perms['admin queue_ui'] = TRUE;
    }

    user_role_grant_permissions($tester_role->rid, array_keys($test_perms));

  }
}
