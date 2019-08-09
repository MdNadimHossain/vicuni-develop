<?php

/**
 * @file
 * PW-1972 - Updated Page builder w/Views.
 */

$nids = [10889101, 10891681];

foreach ($nids as $nid) {
  $node = node_load($nid);
  $node->field_theme[LANGUAGE_NONE][0]['value'] = 'victory';
  node_save($node);

  $item = entity_create('paragraphs_item', [
    'field_name' => 'field_page_paragraphs',
    'bundle' => 'page_intro',
  ]);

  $item->setHostEntity('node', $node, LANGUAGE_NONE, FALSE);
  $item->save();
}
