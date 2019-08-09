<?php

/**
 * @file
 * Library Opening Hours Block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_library_opening_hours_info() {
  return [
    'info' => t('Library Opening Hours'),
    'cache' => DRUPAL_NO_CACHE,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_library_opening_hours_view() {
  drupal_add_js('https://api3-au.libcal.com/js/hours_grid.js?002',
    [
      'type' => 'external',
      'scope' => 'footer',
    ]
  );
  drupal_add_js(
    '(function($) {

      var week0 = new $.LibCalWeeklyGrid( $("#s-lc-whw0"), { iid: 1131, lid: 0,  weeks: 12 });
      })(jQuery);',
    [
      'type' => 'inline',
      'scope' => 'footer',
    ]
  );
  drupal_add_js(
    drupal_get_path('module', 'vu_core') . '/js/vu_core.library_hours.js',
    [
      'scope' => 'footer',
    ]
  );
  $block = [];
  $block['content'] = [
    '#theme' => 'library_opening_hours',
  ];
  return $block;

}
