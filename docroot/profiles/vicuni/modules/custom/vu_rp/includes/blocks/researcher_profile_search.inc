<?php

/**
 * @file
 * Researcher Profile Search.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_search_info() {
  return [
    'info' => t('Researcher Profile Search'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_search_view() {
  $render = [];

  $form = drupal_get_form('vu_rp_search_form');
  if (!$form) {
    return $render;
  }

  $render = [
    'subject' => NULL,
    'content' => drupal_render($form),
  ];

  return $render;
}
