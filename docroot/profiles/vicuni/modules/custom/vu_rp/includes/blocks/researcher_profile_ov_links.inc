<?php

/**
 * @file
 * Researcher Overview Related links.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_ov_links_info() {
  return [
    'info' => t('Researcher overview related links'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_ov_links_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $links = [];
  $institute = _vu_rp_preprocess_page_render_institute($node, TRUE);
  if (!empty($institute['link'])) {
    $links[] = $institute;
  }

  $wrapper = entity_metadata_wrapper('node', $node);
  foreach ($wrapper->field_rp_related_links as $link) {
    $links[] = [
      'link' => $link->url->value(),
      'link_label' => $link->title->value(),
    ];
  }

  $output = theme('vu_rp_block_researcher_profile_ov_links', ['content' => $links]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
