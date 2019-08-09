<?php
/**
 * @file
 * vpoly_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vpoly_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck administer course_information_session_links tafe_info_session_link entities'.
  $permissions['eck administer course_information_session_links tafe_info_session_link entities'] = array(
    'name' => 'eck administer course_information_session_links tafe_info_session_link entities',
    'roles' => array(
      'TAFE Author' => 'TAFE Author',
    ),
    'module' => 'eck',
  );

  return $permissions;
}
