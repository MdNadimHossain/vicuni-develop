<?php

/**
 * @file
 * Request callback block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_request_callback_info() {
  return [
    'info' => t('Request Callback'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_request_callback_view() {
  $node = _vu_core_block_menu_get_course_object(TRUE, FALSE);
  if (!$node) {
    return;
  }

  $college = field_get_items('node', $node, 'field_college');
  $is_vicpoly = in_array($college[0]['title'], ['VU Polytechnic', 'Victoria Polytechnic']);
  $is_vucollege = $college[0]['title'] == 'VU College';

  // Is this course open for enrolments?
  $course_code = vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
  $delivery = vu_course_index_get_course_intake_list($course_code);
  $is_open = $delivery->isOpen();

  // Setup course block class.
  $course = new VuCoreCourseBlockBase($node);
  $is_vu_online = $course->isVuOnline();
  $is_tafe_only = $course->isTafeOnly();
  $direct_open = $course->getCourseIntake()->isOpen('direct');
  $vtac_open = $course->getCourseIntake()->isOpen('vtac');

  // Don't show for International / Vic Poly / Closed courses.
  if ($is_vucollege || !$is_open) {
    return FALSE;
  }

  // Don't show for Tafe Closed courses.
  if ($is_tafe_only && !$direct_open && !$vtac_open) {
    return FALSE;
  }

  $title = t('Need some advice?');
  // Override title for vu online courses.
  if ($is_vu_online) {
    $title = t('Advice for on-campus study');
  }

  $variables['advice_center'] = $is_vicpoly ? 'Victoria University Polytechnic' : 'VUHQ';
  $variables['callback_link'] = $is_vicpoly ? "http://study.vu.edu.au/vu-polytechnic-request-callback?course=$course_code" : "http://study.vu.edu.au/requestcallback?course=$course_code";
  $variables['title'] = $title;

  return [
    'subject' => '',
    'content' => theme('vu_course_request_callback', $variables),
  ];
}
