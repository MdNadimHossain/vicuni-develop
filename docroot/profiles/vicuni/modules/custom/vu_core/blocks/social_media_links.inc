<?php

/**
 * @file
 * Social media links.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_social_media_links_info() {
  return [
    'info' => t('Social media links'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_social_media_links_view() {

  $title_plain = drupal_get_title();
  $url = urlencode(url(current_path(), ['absolute' => TRUE]));
  $title = urlencode($title_plain);
  $site_name = urlencode(variable_get('site_name', ''));
  $variables = [
    'url' => $url,
    'title' => $title,
    'site_name' => $site_name,
    'title_plain' => $title_plain,
  ];

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => theme('vu_social_media_links', $variables),
    ],
  ];

}
