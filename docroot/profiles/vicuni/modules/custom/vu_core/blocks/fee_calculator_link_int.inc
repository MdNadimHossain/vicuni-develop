<?php

/**
 * @file
 * Template file for the international fee calculator link.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_fee_calculator_link_int_info() {
  return [
    'info' => t('Fee Calculator Link (International)'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_fee_calculator_link_int_view() {
  return [
    'content' => theme('vu_course_fee_calculator_link', [
      'link' => '/study-at-vu/fees-scholarships/fee-calculator?international=1',
    ]),
  ];
}
