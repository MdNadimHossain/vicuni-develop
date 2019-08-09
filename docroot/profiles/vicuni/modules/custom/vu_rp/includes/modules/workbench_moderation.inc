<?php

/**
 * @file
 * Workbench moderation module integration.
 */

/**
 * Implements hook_workbench_moderation_transition().
 */
function vu_rp_workbench_moderation_transition($node, $previous_state, $new_state) {
  if ($node->type == 'researcher_profile' && $new_state == workbench_moderation_state_published()) {
    $staff_id = vu_rp_extract_single_field_value('node', $node, 'field_rpa_staff_id');

    if (empty($staff_id)) {
      return;
    }

    $researcher = vu_core_get_user_by_staff_id($staff_id);
    if (!$researcher) {
      return;
    }

    $unpublished = vu_rp_optin_unpublish_staff_profile($researcher, t('Unpublished profile due to publishing Researcher profile'), TRUE);
    if ($unpublished) {
      $user = vu_core_get_user_by_staff_id($staff_id);
      drupal_set_message(t('Old Staff profile of user @name has been unpublished', [
        '@name' => $user->name,
      ]));
    }
  }
}

/**
 * Implements hook_workbench_moderation_states_next_alter().
 */
function vu_rp_workbench_moderation_states_next_alter(&$states, $current_state, $context) {
  if (empty($context['node'])) {
    return;
  }

  if ($context['node']->type != 'researcher_profile') {
    return;
  }

  if (user_access('bypass researcher profile state transition validation')) {
    return;
  }

  if (!vu_rp_node_can_submit_for_review($context['node'], $context['account'])) {
    unset($states['needs_review']);
  }
}
