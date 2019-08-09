<?php

/**
 * @file
 * Researcher funding Related links.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_fund_links_info() {
  return [
    'info' => t('Researcher funding related links'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_fund_links_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  // Sample links.
  $heading = 'Collaborate with us, find out more';
  $links = [
    [
      'title' => 'Collaborate & commercial research',
      'link' => '/research/collaborative-commercial-research',
    ],
    [
      'title' => 'Research & development innovation',
      'link' => '/industry/research-development-innovation',
    ],
    [
      'title' => 'Research focus areas & expertise',
      'link' => '/research/research-focus-areas-expertise',
    ],
    [
      'title' => 'Research contacts',
      'link' => '/research/research-contacts',
    ],
  ];

  $output = theme('vu_rp_block_researcher_profile_fund_links', [
    'heading' => $heading,
    'content' => $links,
  ]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
