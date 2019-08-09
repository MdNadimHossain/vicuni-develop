<?php

/**
 * @file
 * Researcher media appearances.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_media_info() {
  return [
    'info' => t('Researcher media'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_media_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  // Check if this researcher has any awards.
  $field_any_media = vu_rp_extract_single_field_value('node', $node, 'field_rp_has_media_appearances', 'value');
  if (!$field_any_media) {
    return $render;
  }

  $fields = [
    'field_rp_ma_date' => [],
    'field_rp_ma_title' => [],
    'field_rp_ma_summary' => [],
    'field_rp_ma_link' => [
      'target' => 'url',
    ],
  ];

  $data = vu_rp_get_paragraph_item_values($node, 'field_rp_media', 'rp_media_appearance', $fields);
  if ($data) {
    vu_rp_block_researcher_profile_media_format_items($data);
  }

  $output = theme('vu_rp_block_rp_media_appearance', ['content' => $data]);

  $render = empty($output) ? $render : [
    'subject' => NULL,
    'content' => [
      '#markup' => $output,
    ],
  ];

  return $render;
}

/**
 * Formats paragraph data.
 */
function vu_rp_block_researcher_profile_media_format_items(&$data) {
  foreach ($data as &$item) {
    foreach ($item as $field => $value) {
      switch ($field) {
        case 'field_rp_ma_date':
          $value = date('dS F Y', strtotime($value));
          break;
      }

      $item[$field] = $value;
    }
  }
}
