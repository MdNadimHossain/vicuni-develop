<?php

/**
 * @file
 * Researcher current supervision.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_sup_curr_info() {
  return [
    'info' => t('Researcher current supervisions'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_sup_curr_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $supervisions = vu_rp_get_node_supervisions($node, TRUE);

  $output = theme('vu_rp_block_researcher_profile_sup_curr', ['content' => $supervisions]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
