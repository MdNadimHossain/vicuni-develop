<?php

/**
 * @file
 * Block module integration.
 */

/**
 * Implements hook_block_info().
 */
function vu_rp_block_info() {
  $blocks = [];
  $dirname = dirname(dirname(__FILE__));
  $includes = file_scan_directory("{$dirname}/blocks", '/.inc$/');
  foreach ($includes as $file) {
    module_load_include('inc', 'vu_rp', "includes/blocks/{$file->name}");

    $function = "vu_rp_block_{$file->name}_info";
    if (function_exists($function)) {
      $return = $function();
      if (isset($return['multiple'])) {
        unset($return['multiple']);
        $blocks += $return;
      }
      else {
        $blocks[$file->name] = $function();
      }
    }
  }

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function vu_rp_block_view($delta = '') {
  $block = [];

  module_load_include('inc', 'vu_rp', "includes/blocks/{$delta}");
  $function = "vu_rp_block_{$delta}_view";
  if (function_exists($function)) {
    return $function();
  }

  return $block;
}
