<?php

/**
 * @file
 * Unit search block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_unit_search_info() {
  return [
    'info' => t('Find a different unit'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_unit_search_view() {
  $form = drupal_get_form('vu_core_course_search_form');

  $title = [
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Find a different unit'),
  ];
  $form['#prefix'] = drupal_render($title);

  $form['type']['#value'] = 'Unit';
  $form['search_group']['submit']['#value'] = t('Search for a unit');
  unset($form['search_group']['iam'], $form['search_group']['query']['#attributes']['placeholder'], $form['search_group']['submit']['#icon']);

  $form['iam'] = [
    '#type' => 'hidden',
    '#value' => 'resident',
    '#name' => 'iam',
  ];

  return [
    'subject' => t('Find a different unit'),
    'content' => render($form),
  ];
}
