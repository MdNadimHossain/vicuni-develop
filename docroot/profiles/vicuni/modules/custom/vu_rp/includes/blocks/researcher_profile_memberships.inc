<?php

/**
 * @file
 * Researcher memberships.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_memberships_info() {
  return [
    'info' => t('Researcher memberships'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_memberships_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $fields = [
    'field_rp_m_organisation' => [
      'target' => 'target_id',
    ],
    'field_rp_m_role' => [
      'target' => 'target_id',
    ],
  ];

  $data = vu_rp_get_paragraph_item_values($node, 'field_rp_memberships', 'rp_membership', $fields);

  $output = theme('vu_rp_block_rp_memberships', ['content' => $data]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
