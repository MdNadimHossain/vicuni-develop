<?php

/**
 * @file
 * Researcher key details.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_key_details_info() {
  return [
    'info' => t('Researcher key details'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_key_details_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $items = [];
  $wrapper = entity_metadata_wrapper('node', $node);
  foreach ($wrapper->field_rp_expertise as $term) {
    $items[] = trim($term->label(), "'");
  }

  $output = theme('vu_rp_block_researcher_key_details', ['content' => $items]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
