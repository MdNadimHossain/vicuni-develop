<?php

/**
 * @file
 * News View all link.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_qr_code_info() {
  return [
    'info' => t('QR Code'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_qr_code_view() {
  $node = menu_get_object();
  if ($node->type !== 'courses') {
    return FALSE;
  }
  // Only display for VET courses.
  $unit_level = field_get_items('node', $node, 'field_unit_lev');
  if ($unit_level[0]['value'] != 'tafe') {
    return FALSE;
  }

  $content = module_invoke('page_url_qr_code_block', 'block_view', 'page_url_qr_code_block');
  $block = theme('vu_core_qr_code', [
    'qr_code' => render($content),
  ]);

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => render($block),
    ],
  ];

}
