<?php

/**
 * @file
 * Token module integration.
 */

/**
 * Implements hook_token_info().
 */
function vu_rp_token_info() {
  return [
    'types' => [
      'researcher_profile' => [
        'name' => t('Researcher Profile'),
        'description' => t('Tokens for Researcher Profiles'),
        'needs-data' => 'node',
      ],
    ],
    'tokens' => [
      'researcher_profile' => [
        'variation_first_name' => [
          'name' => t('Variation First Name'),
          'description' => t('Resolved variation First Name'),
          'needs-data' => 'node',
        ],
        'variation_last_name' => [
          'name' => t('Variation Last Name'),
          'description' => t('Resolved variation Last Name'),
          'needs-data' => 'node',
        ],
      ],
    ],
  ];
}

/**
 * Implements hook_tokens().
 */
function vu_rp_tokens($type, $tokens, array $data = [], array $options = []) {
  $replacements = [];

  if ($type == 'researcher_profile' && !empty($data['node'])) {
    $node = $data['node'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'variation_first_name':
          $replacements[$original] = vu_rp_node_get_variation_first_name($node);
          break;

        case 'variation_last_name':
          $replacements[$original] = vu_rp_node_get_variation_last_name($node);
          break;
      }
    }
  }

  return $replacements;
}
