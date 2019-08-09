<?php

/**
 * @file
 * Available to supervision flag.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_is_super_info() {
  return [
    'info' => t('Researcher supervision'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_is_super_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $output = theme('vu_rp_block_researcher_is_super', [
    'is_supervising' => vu_rp_extract_single_field_value('node', $node, 'field_rp_sup_is_available'),
    'is_media' => vu_rp_extract_single_field_value('node', $node, 'field_rp_available_to_media'),
  ]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
