<?php

/**
 * @file
 * News View all link.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_news_see_all_info() {
  return [
    'info' => t('News see all'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_news_see_all_view() {
  $node = menu_get_object();
  if ($node->type !== 'news') {
    return FALSE;
  }
  // Set default path.
  $variables = [
    'text' => 'See all news articles',
    'path' => 'about-vu/news-events/news',
  ];
  // Media release links.
  $media = vu_core_extract_single_field_value($node, 'node', 'field_media_release');
  if ($media == TRUE) {
    $variables['text'] = 'See all media releases';
    $variables['path'] = 'about-vu/news-events/media-releases';
  }

  $block = theme('link', $variables);

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => $block,
    ],
  ];

}
