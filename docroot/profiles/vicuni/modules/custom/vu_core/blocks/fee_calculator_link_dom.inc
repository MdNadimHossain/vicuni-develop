<?php

/**
 * @file
 * Template file for the domestic fee calculator link.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_fee_calculator_link_dom_info() {
  return [
    'info' => t('Fee Calculator Link (Domestic)'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_fee_calculator_link_dom_view() {
  return [
    'content' => theme('vu_course_fee_calculator_link', [
      'link' => '/study-at-vu/fees-scholarships/fee-calculator',
    ]),
  ];
}
