<?php
/**
 * @file
 * vu_rp.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vu_rp_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access researcher profile api log'.
  $permissions['access researcher profile api log'] = array(
    'name' => 'access researcher profile api log',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp_log',
  );

  // Exported permission: 'administer membership_levels vocabulary terms'.
  $permissions['administer membership_levels vocabulary terms'] = array(
    'name' => 'administer membership_levels vocabulary terms',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer membership_organisations vocabulary terms'.
  $permissions['administer membership_organisations vocabulary terms'] = array(
    'name' => 'administer membership_organisations vocabulary terms',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer research_institutes vocabulary terms'.
  $permissions['administer research_institutes vocabulary terms'] = array(
    'name' => 'administer research_institutes vocabulary terms',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer researcher profile api configuration'.
  $permissions['administer researcher profile api configuration'] = array(
    'name' => 'administer researcher profile api configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp_api',
  );

  // Exported permission: 'administer researcher profile configuration'.
  $permissions['administer researcher profile configuration'] = array(
    'name' => 'administer researcher profile configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp',
  );

  // Exported permission: 'assign Researcher Profile Admin role'.
  $permissions['assign Researcher Profile Admin role'] = array(
    'name' => 'assign Researcher Profile Admin role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Researcher Profile Approver role'.
  $permissions['assign Researcher Profile Approver role'] = array(
    'name' => 'assign Researcher Profile Approver role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Researcher role'.
  $permissions['assign Researcher role'] = array(
    'name' => 'assign Researcher role',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'bypass maxlength'.
  $permissions['bypass maxlength'] = array(
    'name' => 'bypass maxlength',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'maxlength',
  );

  // Exported permission: 'bypass researcher profile state transition validation'.
  $permissions['bypass researcher profile state transition validation'] = array(
    'name' => 'bypass researcher profile state transition validation',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp',
  );

  // Exported permission: 'clear researcher profile api log'.
  $permissions['clear researcher profile api log'] = array(
    'name' => 'clear researcher profile api log',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp_log',
  );

  // Exported permission: 'create field_rp_nid'.
  $permissions['create field_rp_nid'] = array(
    'name' => 'create field_rp_nid',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_rp_optin'.
  $permissions['create field_rp_optin'] = array(
    'name' => 'create field_rp_optin',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_rp_optout_timestamp'.
  $permissions['create field_rp_optout_timestamp'] = array(
    'name' => 'create field_rp_optout_timestamp',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create researcher_profile content'.
  $permissions['create researcher_profile content'] = array(
    'name' => 'create researcher_profile content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any researcher_profile content'.
  $permissions['delete any researcher_profile content'] = array(
    'name' => 'delete any researcher_profile content',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own researcher_profile content'.
  $permissions['delete own researcher_profile content'] = array(
    'name' => 'delete own researcher_profile content',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete researcher_profile unpublished'.
  $permissions['delete researcher_profile unpublished'] = array(
    'name' => 'delete researcher_profile unpublished',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete terms in research_institutes'.
  $permissions['delete terms in research_institutes'] = array(
    'name' => 'delete terms in research_institutes',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'ds_switch researcher_profile'.
  $permissions['ds_switch researcher_profile'] = array(
    'name' => 'ds_switch researcher_profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'edit any researcher_profile content'.
  $permissions['edit any researcher_profile content'] = array(
    'name' => 'edit any researcher_profile content',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_rp_nid'.
  $permissions['edit field_rp_nid'] = array(
    'name' => 'edit field_rp_nid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_rp_optin'.
  $permissions['edit field_rp_optin'] = array(
    'name' => 'edit field_rp_optin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_rp_optout_timestamp'.
  $permissions['edit field_rp_optout_timestamp'] = array(
    'name' => 'edit field_rp_optout_timestamp',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rp_nid'.
  $permissions['edit own field_rp_nid'] = array(
    'name' => 'edit own field_rp_nid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rp_optin'.
  $permissions['edit own field_rp_optin'] = array(
    'name' => 'edit own field_rp_optin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rp_optout_timestamp'.
  $permissions['edit own field_rp_optout_timestamp'] = array(
    'name' => 'edit own field_rp_optout_timestamp',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own researcher_profile content'.
  $permissions['edit own researcher_profile content'] = array(
    'name' => 'edit own researcher_profile content',
    'roles' => array(
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in research_institutes'.
  $permissions['edit terms in research_institutes'] = array(
    'name' => 'edit terms in research_institutes',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'manage researcher list'.
  $permissions['manage researcher list'] = array(
    'name' => 'manage researcher list',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp_list',
  );

  // Exported permission: 'provision researcher profile demo content'.
  $permissions['provision researcher profile demo content'] = array(
    'name' => 'provision researcher profile demo content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp_demo',
  );

  // Exported permission: 'use researcher profile workbench'.
  $permissions['use researcher profile workbench'] = array(
    'name' => 'use researcher profile workbench',
    'roles' => array(
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_rp',
  );

  // Exported permission: 'use text format researcher'.
  $permissions['use text format researcher'] = array(
    'name' => 'use text format researcher',
    'roles' => array(
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any unpublished researcher_profile content'.
  $permissions['view any unpublished researcher_profile content'] = array(
    'name' => 'view any unpublished researcher_profile content',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view field_rp_nid'.
  $permissions['view field_rp_nid'] = array(
    'name' => 'view field_rp_nid',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_rp_optin'.
  $permissions['view field_rp_optin'] = array(
    'name' => 'view field_rp_optin',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_rp_optout_timestamp'.
  $permissions['view field_rp_optout_timestamp'] = array(
    'name' => 'view field_rp_optout_timestamp',
    'roles' => array(
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rp_nid'.
  $permissions['view own field_rp_nid'] = array(
    'name' => 'view own field_rp_nid',
    'roles' => array(
      'Researcher' => 'Researcher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rp_optin'.
  $permissions['view own field_rp_optin'] = array(
    'name' => 'view own field_rp_optin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rp_optout_timestamp'.
  $permissions['view own field_rp_optout_timestamp'] = array(
    'name' => 'view own field_rp_optout_timestamp',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
