<?php

/**
 * @file
 * Course pathways out block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_pathways_out_info() {
  return [
    'info' => t('Course pathways out'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_pathways_out_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }

  // Prepare array of arguments for theme function.
  $variables = [];
  module_load_include('inc', 'vu_core', 'theme/vu_core.theme');
  $variables['pathways'] = vu_core_pathways_out($node);
  $variables['pathways_information'] = vu_core_extract_single_field_value($node, 'node', 'field_pathways_information');
  $variables['pathway_count'] = count($variables['pathways']);

  if ($variables['pathway_count'] > 0 || !empty($variables['pathways_information'])) {
    return [
      'subject' => NULL,
      'content' => [
        '#theme' => 'vu_accordion',
        '#name' => 'accordion-pathways-from',
        '#title' => t('Pathways to further study'),
        '#content' => theme('pathways_from_this_course', $variables),
      ],
    ];
  }

  return FALSE;
}
