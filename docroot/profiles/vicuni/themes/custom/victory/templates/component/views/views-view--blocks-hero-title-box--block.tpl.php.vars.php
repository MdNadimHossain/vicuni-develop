<?php

/**
 * @file
 * Stub file for "views_view_list" theme hook [pre]process functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 *
 * See template for list of available variables.
 *
 * @see views-view--blocks-hero-title-box--block.tpl.php
 *
 * @ingroup theme_preprocess
 */
function victory_preprocess_views_view__blocks_hero_title_box__block(&$variables) {
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/carousel.js');

  $variables['attributes_array']['class'] = $variables['classes_array'];
  $variables['attributes_array']['class'][] = 'carousel';
  $variables['attributes_array']['class'][] = 'slide';
  $variables['attributes_array']['data-ride'] = 'carousel';
}
