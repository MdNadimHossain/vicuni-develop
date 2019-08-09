<?php

/**
 * @file
 * Updates for [PW-1159].
 */

use Drupal\drupal_helpers\Feature;

Feature::revert('vu_core');

// Delete old 'field_block_entity_ref' field.
field_delete_field('field_block_entity_ref');

$fpp = fieldable_panels_panes_create([
  'uid'      => 1,
  'title'    => 'What\'s happening at VU',
  'uuid'     => '4bb0c050-23ef-402c-94ac-4a2309076ad9',
  'bundle'   => 'pane_featured_content',
  'reusable' => 1,
  'category' => 'VicUni',
]);
fieldable_panels_panes_save($fpp);

$paragraphs = ['views:8d598029c24cbe88ef2023acdbc76b96', 'views:61f66d95834841b43e830d6887a50843'];
foreach ($paragraphs as $item) {
  $paragraph = entity_create('paragraphs_item', [
    'bundle'                 => 'block_ref_paragraph',
    'field_name'             => 'field_fieldable_pane_paragraph',
    'field_block_reference' => [LANGUAGE_NONE => [['moddelta' => $item]]],
  ]);
  $paragraph->setHostEntity('fieldable_panels_pane', $fpp);
  $paragraph->save();
}
