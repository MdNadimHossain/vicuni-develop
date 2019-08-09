<?php

/**
 * @file
 * Course admissions transparency.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_admission_transparency_info() {
  return [
    'info' => t('Admission Transparency'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_admission_transparency_view() {
  $node = _vu_core_block_menu_get_course_object(TRUE, FALSE);
  if (!$node) {
    return;
  }

  $content = '';
  $level = vu_core_extract_single_field_value($node, 'node', 'field_unit_lev');

  if (('undergrad' === $level)  && !vu_feature_switches_switch_state('courses-admission-transparency')) {
    $content = theme('vu_course_admission_transparency');
  }

  return [
    'subject' => NULL,
    'content' => $content,
  ];
}
