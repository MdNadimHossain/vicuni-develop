<?php

/**
 * @file
 * User module integration.
 */

/**
 * Implements hook_user_login().
 */
function vu_rp_user_login(&$edit, $account) {

  $roles = $account->roles;
  // Check if user is a researcher and add role if not present.
  if (!in_array(VU_RP_ROLE_RESEARCHER, $account->roles)) {
    $cas_id = isset($account->cas_name) ? $account->cas_name : NULL;
    if ($cas_id) {
      $id = vu_core_normalise_staff_id($cas_id);
      if (!_vu_rp_api_account_is_blacklisted($id)) {
        if ($role = user_role_load_by_name(VU_RP_ROLE_RESEARCHER)) {
          user_multiple_role_edit([$account->uid], 'add_role', $role->rid);
          $roles[$role->rid] = VU_RP_ROLE_RESEARCHER;
        }
      }
    }
  }

  if (in_array(VU_RP_ROLE_RESEARCHER, $roles)) {
    $node = vu_rp_lookup_researcher_profile_by_uid($account->uid);
    if ($node) {
      $node->uid = $account->uid;
      $node->log = t('Linked account and updated an owner upon login');
      node_save($node);
    }
  }
}
