<?php

/**
 * @file
 * Course International Brochure.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_international_brochure_info() {
  return [
    'info' => t("International Brochure"),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_international_brochure_view() {
  $node = _vu_core_block_menu_get_course_object(FALSE, TRUE);
  if (!$node) {
    return;
  }

  $course_code = vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
  $link = 'http://eaams.vu.edu.au/LAVA/MyBrochure/CreateBrochure.aspx?courseid=' . $course_code;
  return [
    'subject' => '',
    'content' => theme('vu_course_international_brochure', ['link' => $link]),
  ];
}
