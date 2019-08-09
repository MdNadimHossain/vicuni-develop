<?php

/**
 * @file
 * Workbench functionality (do not confuse with workbench_moderation).
 *
 * @todo: Move into own module.
 */

/**
 * Get count of drafts nodes for researcher profiles.
 *
 * @return int
 *   Count of drafts.
 */
function vu_rp_workbench_get_drafts_count() {
  $query = db_select('field_revision_field_rpa_staff_id', 'rp');
  $query->leftJoin('workbench_moderation_node_history', 'wm', "rp.entity_id = wm.nid");
  $query->distinct()->addField('rp', 'entity_id', 'entity_id');
  $query->condition('wm.is_current', 1, '=');
  $query->condition('wm.state', 'draft', '=');
  $result = $query->countQuery()->execute()->fetchField();

  return $result;
}

/**
 * Get count of needs review nodes for researcher profiles.
 *
 * @return int
 *   Count of nodes in review.
 */
function vu_rp_workbench_get_needs_review_count() {
  $query = db_select('field_revision_field_rpa_staff_id', 'rp');
  $query->leftJoin('workbench_moderation_node_history', 'wm', "rp.entity_id = wm.nid");
  $query->distinct()->addField('rp', 'entity_id', 'entity_id');
  $query->condition('wm.is_current', 1, '=');
  $query->condition('wm.state', 'needs_review', '=');
  $result = $query->countQuery()->execute()->fetchField();

  return $result;
}

/**
 * Get count of published nodes for researcher profiles.
 *
 * @return int
 *   Count of published nodes.
 */
function vu_rp_workbench_get_published_count() {
  $query = db_select('field_revision_field_rpa_staff_id', 'rp');
  $query->leftJoin('workbench_moderation_node_history', 'wm', "rp.entity_id = wm.nid");
  $query->distinct()->addField('rp', 'entity_id', 'entity_id');
  $query->condition('wm.is_current', 1, '=');
  $query->condition('wm.state', 'published', '=');
  $result = $query->countQuery()->execute()->fetchField();

  return $result;
}

/**
 * Get count of amended nodes for researcher profiles.
 *
 * @return int
 *   Count of amended nodes.
 *
 * @todo check logic.
 */
function vu_rp_workbench_get_amended_count() {
  // Set initial count.
  $result = 0;

  $query = db_select('field_revision_field_rpa_staff_id', 'rp');
  $query->leftJoin('workbench_moderation_node_history', 'wm', "rp.entity_id = wm.nid");
  $query->distinct()->addField('rp', 'entity_id', 'entity_id');
  $query->condition('wm.is_current', 0, '=');
  $query->condition('wm.state', 'published', '=');
  $query->condition('wm.published', 1, '=');
  $total = $query->countQuery()->execute()->fetchField();
  // If count greater than 0.
  if ($total) {
    $result = $total;
  }

  return $result;
}

/**
 * Get inactive user count.
 *
 * @return int
 *   Count of inactive users.
 */
function vu_rp_workbench_get_inactive_users_count() {
  $query = db_select('vu_rp_list_researchers', 'rp');
  $query->leftJoin('cas_user', 'cas', "rp.staff_id = CONCAT('E', cas.cas_name)");
  $query->addField('rp', 'staff_id', 'staff_id');
  $query->addField('cas', 'cas_name', 'cas_name');
  $query->isNull('cas.cas_name');

  $result = $query->countQuery()->execute()->fetchField();

  return $result;
}

/**
 * Get opted out researchers count.
 *
 * @return int
 *   Count of opted out researchers.
 */
function vu_rp_workbench_get_opted_out_user_count() {
  $query = db_select('vu_rp_list_researchers', 'rp');
  $query->leftJoin('cas_user', 'cas', "rp.staff_id = CONCAT('E', cas.cas_name)");
  $query->leftJoin('field_data_field_rp_optin', 'u', "u.entity_id = cas.uid");
  $query->addField('rp', 'staff_id', 'staff_id');
  $query->addField('cas', 'uid', 'uid');
  $query->condition('u.field_rp_optin_value', 0, '=');

  $result = $query->countQuery()->execute()->fetchField();

  return $result;
}
