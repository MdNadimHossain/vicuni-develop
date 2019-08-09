<?php

/**
 * @file
 * Researcher fundings.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_fundings_info() {
  return [
    'info' => t('Researcher fundings'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_fundings_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $accordions = [];
  $fundings = vu_rp_node_get_fundings($node);
  foreach ($fundings as $year => $fundings_per_year) {
    if (count($fundings_per_year) > 0) {
      $accordions[] = theme('vu_accordion', [
        'name' => 'publications-researcher-fundings-' . mb_strtolower(str_replace(' ', '', $year)),
        'title' => $year,
        'content' => theme('vu_rp_block_researcher_profile_fundings', ['content' => $fundings_per_year]),
      ]);
    }
  }

  $output = implode(' ', $accordions);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
