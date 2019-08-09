<?php
/**
 * @file vumain.featured_content.blocks.php
 *
 * This contains the Featured Content block related functions.
 */

require_once 'vumain.featured_content.functions.php';

/**
 * Pseudo implements hook_block_info();.
 *
 * @return array
 */
function vumain_featured_content_block_info() {
  $blocks = array();

  $blocks['featured_content'] = array(
    'info' => 'Featured content',
    'status' => TRUE,
    'region' => 'featured_content',
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );

  return $blocks;
}

/**
 * Pseudo implements hook_block_view();.
 *
 * @return array|NULL
 */
function vumain_featured_content_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'featured_content':
      $block = array();
      $block['subject'] = '';
      $block['content'] = vumain_featured_content_render();
      break;
  }
  return $block;
}
