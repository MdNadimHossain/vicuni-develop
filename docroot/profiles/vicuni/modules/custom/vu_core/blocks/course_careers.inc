<?php

/**
 * @file
 * Course careers block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_careers_info() {
  return [
    'info' => t('Course careers'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_careers_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }

  vu_courses_node_view($node, 'full_html');

  $variables = [];
  $variables['careers'] = !empty($node->field_imp_career[$node->language][0]['value']) ? $node->field_imp_career[$node->language][0]['value'] : NULL;
  // If there's a custom careers section heading, use that.
  $variables['title'] = t('Careers');
  if (!empty($node->field_career_opportunities_title[$node->language][0]['safe_value'])) {
    $variables['title'] = $node->field_career_opportunities_title[$node->language][0]['safe_value'];
  }
  return [
    'subject' => NULL,
    'content' => theme('vu_courses_careers', $variables),
  ];
}
