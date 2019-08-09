<?php

/**
 * @file
 * Researcher Supervision Related links.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_sup_links_info() {
  return [
    'info' => t('Researcher supervision related links'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_sup_links_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  // Sample links.
  $heading = 'Become a graduate researcher';
  $links = [
    [
      'title' => 'How to apply for a research degree',
      'link' => '/study-at-vu/how-to-apply/graduate-research-applicants',
    ],
    [
      'title' => 'Our support for graduate researchers',
      'link' => '/study-at-vu/why-choose-vu/support-services-that-work-for-you/support-for-graduate-researchers',
    ],
    [
      'title' => 'Research student fees',
      'link' => '/study-at-vu/fees-scholarships/course-tuition-fees/research-student-fees',
    ],
    [
      'title' => 'Graduate researcher scholarships',
      'link' => '/study-at-vu/fees-scholarships/scholarships/graduate-research-scholarships',
    ],
  ];

  $output = theme('vu_rp_block_researcher_profile_sup_links', [
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
