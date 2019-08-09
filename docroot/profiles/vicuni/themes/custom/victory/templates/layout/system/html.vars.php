<?php

/**
 * @file
 * File for "html" theme hook [pre]process functions.
 */

/**
 * Implements hook_preprocess_html().
 */
function victory_preprocess_html(&$variables) {
  // Add 'no-js' class to <body> to target styles.
  $variables['classes_array'][] = 'no-js';
  $hello_bar_enabled = variable_get('hellobar-enabled', FALSE);
  $node = isset($variables['node']) && is_object($variables['node']) ? $variables['node'] : FALSE;
  if ($node === FALSE) {
    $node = _vu_core_block_menu_get_course_object();
  }

  if (!$node) {
    // Add class when hello bar is enabled.
    if ($hello_bar_enabled) {
      $variables['classes_array'][] = 'hellobar-enabled';
    }

    return;
  }

  if ($node->type != 'courses' && $hello_bar_enabled) {
    $variables['classes_array'][] = 'hellobar-enabled';
  }

  switch ($node->type) {
    case 'courses':
    case 'unit':
      if ($node->type == "courses") {
        $unit_level = field_get_items('node', $node, 'field_unit_lev');
        if ($unit_level[0]['value'] == 'tafe') {
          $variables['classes_array'][] = 'print-friendly';
        }
      }
      // Add class for vicpoly.
      if (!empty($node->field_college[$node->language][0]['title']) && in_array($node->field_college[$node->language][0]['title'], ['VU Polytechnic', 'Victoria Polytechnic'])) {
        $variables['classes_array'][] = 'victoria-polytechnic';
      }
      break;
  }
}
