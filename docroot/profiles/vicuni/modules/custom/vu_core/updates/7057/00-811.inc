<?php

/**
 * @file
 * Updates for [PW-811].
 */

// Delete duplicated field instances.
$instances = [
  'paragraphs_item::block_ref_paragraph::field_block_entity_ref',
  'fieldable_panels_pane::pane_featured_links::field_featured_link_paragraph',
];
foreach ($instances as $id) {
  list($entity_type, $bundle_name, $field_name) = explode('::', $id);
  db_delete('field_config_instance')
    ->condition('field_name', $field_name)
    ->condition('entity_type', $entity_type)
    ->condition('bundle', $bundle_name)
    ->execute();
}

// Update choose_vu since we've refactored field names and other stuff.
_vu_core_remove_choose_vu_pane();

// Create and place Quick facts pane.
_vu_core_create_quick_facts_pane();

// Success stories VU fieldable panel pane.
$fpp = fieldable_panels_panes_create([
  'uid' => 1,
  'title' => 'Hear from our students',
  'uuid' => '886714cf-9590-428c-aef0-0813212bda0e',
  'bundle' => 'pane_featured_content',
  'reusable' => 1,
  'category' => 'VicUni',
]);
fieldable_panels_panes_save($fpp);

$featured_success_story_nodes = [
  '10880141' => [
    'field_excerpt' => t("VU supported me and my dream of being a teacher."),
    'field_featured_tile_text' => t("Christian's Story"),
    'field_course_studied' => t('Bachelor of Education'),
  ],
  '10879991' => [
    'field_excerpt' => t("My course kept me interested - every single subject and topic was relevant, current, and intriguing."),
    'field_featured_tile_text' => t("Chantelle's Story"),
    'field_course_studied' => t('Bachelor of Business'),
  ],
  '10879746' => [
    'field_excerpt' => t("VU also offers a lot of support to international students who have different needs."),
    'field_featured_tile_text' => t("Sally's Story"),
    'field_course_studied' => t('Bachelor of Business'),
  ],
];

foreach ($featured_success_story_nodes as $nid => $defaults) {
  // Update featured success story nodes with default content.
  $node = node_load($nid);
  if (!empty($node)) {
    foreach ($defaults as $field => $value) {
      if (isset($node->{$field})) {
        $node->{$field}[LANGUAGE_NONE][0]['value'] = $value;
      }
    }
    node_save($node);
  }

  $paragraph = entity_create('paragraphs_item', [
    'bundle' => 'node_ref_paragraph',
    'field_name' => 'field_fieldable_pane_paragraph',
    'field_node_entity_ref' => [LANGUAGE_NONE => [['target_id' => $nid]]],
  ]);
  $paragraph->setHostEntity('fieldable_panels_pane', $fpp);
  $paragraph->save();
}
