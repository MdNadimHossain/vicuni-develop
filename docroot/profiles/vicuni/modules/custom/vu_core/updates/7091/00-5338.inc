<?php

/**
 * @file
 * PW-5338 - Add fields to map.
 */

// Insert map to send data to right now.
$rows = [
  [
    'mid' => NULL,
    'rightnow_field_fid' => 'postal',
    'nid' => 10915786,
    'webform_component_cid' => 8,
  ],
  [
    'mid' => NULL,
    'rightnow_field_fid' => 'timeframe',
    'nid' => 10915786,
    'webform_component_cid' => 11,
  ],
  [
    'mid' => NULL,
    'rightnow_field_fid' => 'current-situation',
    'nid' => 10915786,
    'webform_component_cid' => 9,
  ],
  [
    'mid' => NULL,
    'rightnow_field_fid' => 'area-of-interest',
    'nid' => 10915786,
    'webform_component_cid' => 13,
  ],
  [
    'mid' => NULL,
    'rightnow_field_fid' => 'level-of-study',
    'nid' => 10915786,
    'webform_component_cid' => 14,
  ],
];

$query = db_insert('vu_rightnow_webform_map')
  ->fields(['mid', 'rightnow_field_fid', 'nid', 'webform_component_cid']);

foreach ($rows as $record) {
  $query->values($record);
}
$query->execute();
