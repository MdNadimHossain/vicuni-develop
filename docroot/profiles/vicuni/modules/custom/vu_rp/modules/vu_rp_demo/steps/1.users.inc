<?php

/**
 * @file
 * Step to provision required taxonomy for Research Profiles demo content.
 */

use Drupal\drupal_helpers\General;

/**
 * Provisions Pages test pages.
 */
function vu_rp_demo_provision_step_users() {
  $demo_role_names = [
    VU_RP_ROLE_RESEARCHER => 10,
    VU_RP_ROLE_ADMIN => 10,
    VU_RP_ROLE_APPROVER => 10,
  ];

  $roles = user_roles(TRUE);
  foreach ($roles as $rid => $role) {
    if (!isset($demo_role_names[$role])) {
      continue;
    }

    $num_users = $demo_role_names[$role];
    $role_machine_name = strtolower(preg_replace('/[^a-z]+/i', '_', $role));
    for ($i = 1; $i <= $num_users; $i++) {
      $name = 'demo_' . $role_machine_name . '_' . $i;
      // If this test user has been created previously, skip and notify.
      $existing_user = user_load_by_name($name);
      if ($existing_user !== FALSE) {
        General::messageSet('Skipped existing user: ' . $name);
        continue;
      }
      $mail = $name . '.demo@example.com';
      $user = [
        'name' => $name,
        'pass' => $name,
        'mail' => $mail,
        'status' => 1,
        'init' => $mail,
        'roles' => [
          DRUPAL_AUTHENTICATED_RID => 'authenticated user',
          $rid => $role,
        ],
      ];
      $user = user_save('', $user);

      if ($user !== FALSE) {
        General::messageSet('Created user: ' . $user->name);
        vu_rp_demo_record_add('user', 'user', $user->uid);
      }
      else {
        General::messageSet('FAILED creating user: ' . $name);
      }
    }
  }
}
