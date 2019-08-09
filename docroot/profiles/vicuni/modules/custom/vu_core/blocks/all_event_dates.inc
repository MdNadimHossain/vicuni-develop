<?php

/**
 * @file
 * All event dates.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_all_event_dates_info() {
  return [
    'info' => t('All event dates'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_all_event_dates_view() {
  $node = menu_get_object();
  if ($node->type !== 'events') {
    return FALSE;
  }
  $dates = field_get_items('node', $node, 'field_date');
  $cta_button = field_get_items('node', $node, 'field_cta_button');
  foreach ($dates as $date) {
    $val = date('j F Y, g:ia', $date['value']);
    $val1 = date('j F Y, g:ia', $date['value2']);
    $multiple_dates[] = ($date['value'] != $date['value2']) ? $val . ' to ' . $val1 : $val;
  }
  if (count($multiple_dates) < 4) {
    $multiple_dates = '';
  }
  if (!empty($cta_button[0]['title'])) {
    $cta_title = $cta_button[0]['title'];
    $cta_url = $cta_button[0]['url'];
  }
  $items_list = theme('item_list', ['items' => $multiple_dates]);
  $variables = [
    'multiple_dates' => $items_list,
    'cta_title' => $cta_title,
    'cta_url' => $cta_url,
  ];

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => theme('vu_all_event_dates', $variables),
    ],
  ];

}
