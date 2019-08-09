<?php

/**
 * @file
 * Course careers block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_careers_supplementary_info() {
  return [
    'info' => t('Course careers supplementary'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_careers_supplementary_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }

  $node_wrapper = entity_metadata_wrapper('node', $node);
  $field_supplementary_career_info = $node_wrapper->field_supplementary_career_info->value();

  $field_para_supp_career_info = $node_wrapper->field_para_supp_career_info->value();

  $supplementary_career_info = '';

  if (!empty($field_para_supp_career_info)) {
    $output = [];
    foreach ($field_para_supp_career_info as $delta => $item) {
      $output[$delta] = $item->view('full');
    }
    $supplementary_career_info = drupal_render($output);
  }
  elseif (!empty($field_supplementary_career_info)) {
    $referenced_career_info = reset($field_supplementary_career_info);
    $supplementary_career_info = '<div id="supplementary-career-info" class="career-highlights">';
    $inline_entity = entity_view('inline_entities', [$referenced_career_info], 'full');
    $supplementary_career_info .= render($inline_entity);
    $supplementary_career_info .= '</div>';
  }
  return [
    'subject' => NULL,
    'content' => $supplementary_career_info,
  ];
}
