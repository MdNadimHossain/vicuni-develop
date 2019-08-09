<?php

/**
 * @file
 * Course careers block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_success_story_info() {
  return [
    'info' => t('Course success story'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_success_story_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }

  $node_wrapper = entity_metadata_wrapper('node', $node);
  $field_course_success_story = $node_wrapper->field_related_success_stories->value();

  $success_story = '';
  // Filter out unpublished nodes.
  $field_course_success_story = array_filter($field_course_success_story, '_vu_core_filter_unpublished');
  // Reindex array.
  $field_course_success_story = array_values($field_course_success_story);
  // Update the field items to return only one random item.
  if (!empty($field_course_success_story)) {
    $referenced_success_story = $field_course_success_story[mt_rand(0, count($field_course_success_story) - 1)];
    $success_story = '<div id="success-story" class="career-highlights">';
    $success_story_entity = entity_view('node', [$referenced_success_story], 'teaser_with_read_more');
    $success_story .= render($success_story_entity);
    $success_story .= '</div>';
  }
  return [
    'subject' => NULL,
    'content' => $success_story,
  ];
}
