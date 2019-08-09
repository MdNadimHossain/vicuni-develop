<?php

/**
 * @file
 * Opt-in/opt-out functionality.
 *
 * Note that we are operating with 2 types of nodes:
 * - Staff Profile - the old content type that Researchers may or may not have.
 * - Researcher profile - new content type.
 *
 * @todo: Move into standalone module.
 */

/**
 * Get opt in status of a user.
 *
 * @return int|bool
 *   1 if user has opted in.
 *   0 if user has opted out.
 *   NULL if user has not selected to opt-in or opt-out.
 */
function vu_rp_optin_get_status($account) {
  $account = user_load($account->uid);

  return vu_rp_extract_single_field_value('user', $account, 'field_rp_optin');
}

/**
 * Set opt-in status.
 *
 * @param bool $value
 *   Status of user.
 */
function vu_rp_optin_set_status($account, $value) {
  $account = user_load($account->uid);
  /** @var \EntityStructureWrapper $wrapper */
  $wrapper = entity_metadata_wrapper('user', $account);
  $wrapper->field_rp_optin->set($value);

  if ($value == 0) {
    // Set opt out date if user is opting out.
    $wrapper->field_rp_optout_timestamp->set(REQUEST_TIME);
  }
  else {
    // Reset opt out date if user is opting in.
    $wrapper->field_rp_optout_timestamp = NULL;
  }

  // @todo: Do not save the status in setter.
  $wrapper->save();

  return $account;
}

/**
 * Unpublish Staff profile.
 *
 * Returns unpublished node or FALSE if the node is already published.
 *
 * @param object $account
 *   The user account to unpublish the profile for.
 * @param bool|string $log_message
 *   Log message to provide when unpublishing. Defaults to no message.
 * @param bool $is_replaced_by_rp
 *   Flag to set on the node if it has been replaced by a researcher profile
 *   node. Defaults to FALSE.
 *
 * @return bool|mixed
 *   Unpublished node or FALSE if the node does not exist or currently
 *   unpublished.
 */
function vu_rp_optin_unpublish_staff_profile($account, $log_message = NULL, $is_replaced_by_rp = FALSE) {
  $node = vu_core_get_staff_profile_by_uid($account->uid);

  // Do not unpublish non-existing and already unpublished nodes.
  if (!$node || ($node && $node->status != NODE_PUBLISHED)) {
    return FALSE;
  }

  $node->status = NODE_NOT_PUBLISHED;
  if ($log_message) {
    $node->log = $log_message;
  }

  if ($is_replaced_by_rp) {
    $node->field_researcher_profile[LANGUAGE_NONE][] = ['value' => TRUE];
  }

  node_save($node);

  $logger = vu_rp_api_get_logger();
  $logger->log('Unpublish Staff profile node', sprintf('Unpublished staff profile node "%s" for user "%s" (%s): %s', $node->nid, $account->name, $account->uid, $log_message));

  return $node;
}

/**
 * Unpublish Researcher profile.
 *
 * Returns unpublished node or FALSE if the node is already published.
 *
 * @param object $account
 *   The user account to unpublish the profile for.
 * @param bool|string $log_message
 *   Log message to provide when unpublishing. Defaults to no message.
 *
 * @return bool|mixed
 *   Unpublished node or FALSE if the node does not exist or currently
 *   unpublished.
 */
function vu_rp_optin_unpublish_researcher_profile($account, $log_message = FALSE) {
  $node = vu_rp_lookup_researcher_profile_by_uid($account->uid);

  // Do not unpublish non-existing and already unpublished nodes.
  if (!$node || ($node && $node->status != NODE_PUBLISHED)) {
    return FALSE;
  }

  $node->status = NODE_NOT_PUBLISHED;
  if ($log_message) {
    $node->log = $log_message;
  }

  node_save($node);

  $logger = vu_rp_api_get_logger();
  $logger->log('Unpublish researcher profile node', sprintf('Unpublished staff profile node "%s" for user "%s" (%s): %s', $node->nid, $account->name, $account->uid, $log_message));

  return $node;
}

/**
 * Link account to researcher profile.
 */
function vu_rp_optin_link_account_to_researcher_profile($account) {
  $staff_id = vu_core_get_staff_id_by_uid($account->uid);
  if (!$staff_id) {
    throw new Exception('Account does not contain staff ID information');
  }

  $node = vu_rp_get_researcher_profile_by_staff_id($staff_id);
  if (!$node) {
    throw new Exception('Unable to find Researcher Profile node for this staff ID');
  }

  $account = user_load($account->uid);
  if (!empty($account->field_rp_nid[LANGUAGE_NONE][0]['target_id']) && $account->field_rp_nid[LANGUAGE_NONE][0]['target_id'] == $node->nid) {
    // Do not re-save the user if it is already linked.
  }
  else {
    $account->field_rp_nid[LANGUAGE_NONE] = [['target_id' => $node->nid]];
    user_save($account);

    // Do not re-save the node if it is already linked.
    if ($node->uid != $account->uid) {
      $node->uid = $account->uid;
      $node->log = t('Linked account and updated an owner');
      node_save($node);
    }
  }

  // Force opt-in for data consistency.
  vu_rp_optin_set_status($account, 1);
}

/**
 * Unlink account from researcher profile.
 */
function vu_rp_optin_unlink_account_from_researcher_profile($account) {
  $staff_id = vu_core_get_staff_id_by_uid($account->uid);
  if (!$staff_id) {
    throw new Exception('Account does not contain staff ID information');
  }

  $account = user_load($account->uid);
  if (!empty($account->field_rp_nid)) {
    $account->field_rp_nid = [];
    user_save($account);
  }

  // Force opt-out for data consistency.
  vu_rp_optin_set_status($account, 0);
}
