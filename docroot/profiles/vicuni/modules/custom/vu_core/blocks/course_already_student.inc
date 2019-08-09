<?php

/**
 * @file
 * Course Already a VU Student.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_already_student_info() {
  return [
    'info' => t("Already a VU Student"),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_already_student_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }
  $is_international = vu_courses_is_international_course_url();
  $course_aqf = vu_core_extract_single_field_value($node, 'node', 'field_course_aqf');
  $is_postgrad = preg_match('/Doctoral|Research/', $course_aqf);
  $course_code = vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
  $delivery = vu_course_index_get_course_intake_list($course_code);
  $link = vu_courses_apply_url($course_code);

  if (!$is_international && !$is_postgrad  && !($delivery->isTafe() && !$delivery->hasOnlineApplication()) && !$delivery->isApprenticeship() && $delivery->isOpen('direct')) {
    return [
      'subject' => '',
      'content' => theme('vu_course_already_student', ['link' => $link]),
    ];
  }

  return FALSE;
}
