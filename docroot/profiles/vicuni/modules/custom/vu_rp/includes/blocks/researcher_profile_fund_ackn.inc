<?php

/**
 * @file
 * Researcher funding acknowledgements.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_fund_ackn_info() {
  return [
    'info' => t('Researchers organisations to acknowledge'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_fund_ackn_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $fields = [
    'field_rp_ota_name' => [],
    'field_rp_ota_link' => [
      'target' => 'url',
    ],
    'field_rp_ota_description' => [],
  ];

  $data = vu_rp_get_paragraph_item_values($node, 'field_rp_ota', 'rp_ota', $fields);

  $output = theme('vu_rp_block_researcher_profile_fund_ackn', ['content' => $data]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
