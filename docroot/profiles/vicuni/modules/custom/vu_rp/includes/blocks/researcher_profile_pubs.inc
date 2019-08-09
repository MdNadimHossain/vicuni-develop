<?php

/**
 * @file
 * Researcher publications.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_pubs_info() {
  return [
    'info' => t('Researcher publications'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_pubs_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  $output = '';

  $publication_count = vu_rp_extract_single_field_value('node', $node, 'field_rpc_publication_count', 'value');
  $link_href = vu_rp_extract_single_field_value('node', $node, 'field_rp_research_repo_link', 'url');
  $first_name = vu_rp_node_get_variation_first_name($node);

  if (!empty($link_href)) {
    $link_sentence = l(t('!name publications is available in the VU Research Repository.', [
      '!name' => vu_core_format_possession($first_name),
    ], [
      'html' => TRUE,
    ]), $link_href);
    $output .= '<div class="publications-link-sentence"><p>' . $first_name . ' has over ' . $publication_count . ' publications, with a selection listed here.</p></br><p>A more comprehensive list of ' . $link_sentence . '</p></div>';
  }

  $accordions = [];
  $publications = vu_rp_node_get_publications($node);
  foreach ($publications as $type => $info) {
    if (!empty($info['total'])) {
      $title = t('@type (showing @count of @total)', [
        '@type' => $type,
        '@count' => count($info['items']),
        '@total' => $info['total'],
      ]);
    }
    else {
      $title = t('@type (showing @count)', [
        '@type' => $type,
        '@count' => count($info['items']),
      ]);
    }

    $accordions[] = theme('vu_accordion', [
      'name' => drupal_html_id('publications-researcher-profile-' . $type),
      'title' => $title,
      'content' => theme('vu_rp_block_rp_publications', ['content' => $info['items']]),
    ]);
  }

  $output .= implode(' ', $accordions);

  // Add a link block to bottom.
  if (!empty($link_href)) {
    $link = [
      'href' => $link_href,
      'user_name' => vu_core_format_possession($first_name),
    ];
    $output .= theme('vu_rp_block_researcher_profile_pubs_list_link', $link);
  }

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}
