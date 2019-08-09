<?php
/**
 * @file
 * vu_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function vu_core_user_default_roles() {
  $roles = array();

  // Exported role: Advanced Author.
  $roles['Advanced Author'] = array(
    'name' => 'Advanced Author',
    'weight' => 4,
  );

  // Exported role: Approver.
  $roles['Approver'] = array(
    'name' => 'Approver',
    'weight' => 5,
  );

  // Exported role: Author.
  $roles['Author'] = array(
    'name' => 'Author',
    'weight' => 3,
  );

  // Exported role: Emergency Publisher.
  $roles['Emergency Publisher'] = array(
    'name' => 'Emergency Publisher',
    'weight' => 2,
  );

  // Exported role: International Author.
  $roles['International Author'] = array(
    'name' => 'International Author',
    'weight' => 6,
  );

  // Exported role: Webform Author.
  $roles['Webform Author'] = array(
    'name' => 'Webform Author',
    'weight' => 15,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 7,
  );

  return $roles;
}
