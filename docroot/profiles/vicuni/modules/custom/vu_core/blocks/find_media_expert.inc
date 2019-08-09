<?php

/**
 * @file
 * Find Media Expert Form Block.
 */

/**
 * Implements hook_block_info().
 */
function vu_core_block_find_media_expert_info() {
  return [
    'info' => t('Find a media expert'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_find_media_expert_view() {

  $form = drupal_get_form('vu_core_expert_guide_search_form');

  // Set form ID.
  $form['#id'] = 'vu-core-expert-guide-search-form';

  drupal_add_js(
    [
      'data' => [
        'defaultPlaceHolderText' => 'Search by name or expertise',
        'longPlaceHolderText' => 'Search by name or area of expertise',
        'shortPlaceHolderText' => 'Search',
      ],
    ],
    'setting'
  );

  $variables = [];
  $variables['data'] = drupal_render($form);

  $block = theme('vu_core_block_find_media_expert', $variables);

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => $block,
      '#attached' => [
        'js' => [
          drupal_get_path('module', 'vu_core') . '/js/vu_core_media_expert_search_form.js',
        ],
      ],
    ],
  ];
}
