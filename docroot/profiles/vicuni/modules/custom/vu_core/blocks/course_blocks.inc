<?php

/**
 * @file
 * Block functions for How to Apply block system.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_blocks_info() {
  $info['multiple'] = TRUE;

  $dirname = dirname(__FILE__);
  $includes = file_scan_directory("{$dirname}/course", '/.inc$/');
  foreach ($includes as $file) {
    module_load_include('inc', 'vu_core', "blocks/course/{$file->name}");

    $class = 'VuCore' . vu_core_underscores_to_camelcase($file->name, TRUE) . 'CourseBlock';

    // @TODO - Throw an exception if no $info.
    // @codingStandardsIgnoreStart
    if (class_exists($class) && !is_null($class::$info)) {
      $info["vu_cbs_{$file->name}"] = [
        'info' => 'VU Course Block: ' . $class::$info,
        'cache' => $class::$cache,
      ];
    }
    // @codingStandardsIgnoreEnd
  }

  return $info;
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_blocks_view($delta) {
  // Ensure file exists.
  $file = drupal_get_path('module', 'vu_core') . "/blocks/course/{$delta}.inc";
  if (!file_exists($file)) {
    return FALSE;
  }
  require_once $file;

  // Ensure class exists.
  $class = 'VuCore' . vu_core_underscores_to_camelcase($delta, TRUE) . 'CourseBlock';
  if (!class_exists($class)) {
    return FALSE;
  }

  // Ensure block is visible.
  $block = new $class();
  if (!$block->isVisible()) {
    return FALSE;
  }

  // Return block.
  return $block->view();
}
