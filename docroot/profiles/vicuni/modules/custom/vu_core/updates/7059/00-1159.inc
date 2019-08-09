<?php

/**
 * @file
 * Updates for [PW-1159].
 */

$paragraphs = [
  61 => 'views:8d598029c24cbe88ef2023acdbc76b96',
  66 => 'views:61f66d95834841b43e830d6887a50843',
];
foreach ($paragraphs as $item_id => $value) {
  $paragraph = paragraphs_item_load($item_id);
  $paragraph->field_block_reference[LANGUAGE_NONE][0]['moddelta'] = $value;
  entity_save('paragraphs_item', $paragraph);
}
