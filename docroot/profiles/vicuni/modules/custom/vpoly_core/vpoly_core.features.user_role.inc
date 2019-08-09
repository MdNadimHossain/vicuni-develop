<?php
/**
 * @file
 * vpoly_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function vpoly_core_user_default_roles() {
  $roles = array();

  // Exported role: TAFE Author.
  $roles['TAFE Author'] = array(
    'name' => 'TAFE Author',
    'weight' => 6,
  );

  return $roles;
}
