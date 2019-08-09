<?php

/**
 * @file
 * Legacy how to apply block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_how_to_apply_legacy_info() {
  return [
    'info' => t('How to Apply (Legacy)'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_how_to_apply_legacy_view() {
  $node = _vu_core_block_menu_get_course_object(TRUE);
  if (!$node) {
    return;
  }
  $course_code = vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
  $is_international = vu_courses_is_international_course_url();
  $audience = $is_international ? 'international' : 'domestic';

  $variables = [];
  $variables['international'] = $is_international;
  $variables['course_level'] = $node->field_unit_lev[$node->language][0]['value'];
  $variables['tafe_course'] = $variables['course_level'] == 'tafe';
  $variables['short_course'] = $variables['course_level'] == 'short';
  $variables['delivery'] = vu_course_index_get_course_intake_list($course_code);

  $how_to_apply_summary_theme = 'how-to-apply-summary';
  if ($is_international) {
    $how_to_apply_summary_theme = $audience . '-' . $how_to_apply_summary_theme;
  }
  $variables['how_to_apply_summary'] = theme($how_to_apply_summary_theme, ['course' => $node]);

  $themeables = [
    'how_to_apply',
    'admission_information',
  ];
  foreach ($themeables as $themeable) {
    $theme_name = "vu_courses_{$audience}_{$themeable}";
    $variables[$themeable] = theme($theme_name, [
      'node' => $node,
      'title' => '',
    ]);
  }

  return [
    'subject' => '',
    'content' => theme('vu_course_how_to_apply_legacy', $variables),
  ];
}
