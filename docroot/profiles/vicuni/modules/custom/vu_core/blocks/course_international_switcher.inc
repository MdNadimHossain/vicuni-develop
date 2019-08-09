<?php

/**
 * @file
 * International switcher block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_international_switcher_info() {
  return [
    'info' => t('VU International Switcher'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_international_switcher_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }
  $is_international_url = vu_courses_is_international_course_url();

  if ($node->type !== 'courses') {
    return FALSE;
  }

  $variables = [
    'is_international_url' => $is_international_url,
    'code' => $node->field_unit_code[$node->language][0]['safe_value'],
    // Internationl courses.
    'international_has_dom' => $is_international_url && vu_courses_offered_to_audience($node, 'domestic'),
    'international_only' => $is_international_url && (vu_core_extract_single_field_value($node, 'node', 'field_domestic') === '0'),
    // Domestic courses.
    'domestic_has_int' => !$is_international_url && vu_courses_offered_to_audience($node, 'international'),
    'domestic_only' => !$is_international_url && !vu_courses_offered_to_audience($node, 'international'),
    'is_vu_sydney' => vu_core_is_vu_sydney($node),
  ];

  return [
    'subject' => '',
    'content' => theme('vu_international_switcher', $variables),
  ];
}
