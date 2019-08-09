<?php

/**
 * @file
 * Researcher keynotes.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_keynotes_info() {
  return [
    'info' => t('Researcher keynotes'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_keynotes_view() {
  $render = [];

  $node = vu_rp_get_researcher_profile_node();
  if (!$node) {
    return $render;
  }

  // Check if this researcher has any keynotes.
  $field_rp_any_keynotes = vu_rp_extract_single_field_value('node', $node, 'field_rp_has_keynote_invitations', 'value');
  if (!$field_rp_any_keynotes) {
    return $render;
  }

  $fields = [
    'field_rp_k_year' => [],
    'field_rp_k_title' => [],
    'field_rp_k_details' => [],
  ];

  $data = vu_rp_get_paragraph_item_values($node, 'field_rp_keynotes', 'rp_keynote', $fields);
  if ($data) {
    vu_rp_block_researcher_profile_keynotes_format_items($data);
  }

  $output = theme('vu_rp_block_rp_keynotes', ['content' => $data]);

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
function vu_rp_block_researcher_profile_keynotes_format_items(&$data) {
  foreach ($data as &$item) {
    foreach ($item as $field => $value) {
      switch ($field) {
        case 'field_rp_k_year':
          $value = date('Y', strtotime($value));
          break;
      }

      $item[$field] = $value;
    }
  }
}
