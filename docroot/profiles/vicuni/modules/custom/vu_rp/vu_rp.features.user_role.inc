<?php
/**
 * @file
 * vu_rp.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function vu_rp_user_default_roles() {
  $roles = array();

  // Exported role: Researcher.
  $roles['Researcher'] = array(
    'name' => 'Researcher',
    'weight' => 11,
  );

  // Exported role: Researcher Profile Admin.
  $roles['Researcher Profile Admin'] = array(
    'name' => 'Researcher Profile Admin',
    'weight' => 12,
  );

  // Exported role: Researcher Profile Approver.
  $roles['Researcher Profile Approver'] = array(
    'name' => 'Researcher Profile Approver',
    'weight' => 13,
  );

  return $roles;
}
