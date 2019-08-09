<?php

/**
 * @file
 * Course First Year Model info block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_first_year_model_info_info() {
  return [
    'info' => t('Course first year model info'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_first_year_model_info_view() {
  return [
    'subject' => NULL,
    'content' => theme('vu_course_first_year_model_block'),
  ];
}
