<?php

/**
 * @file
 * PW-3898 - Add audience taxonomy terms.
 */

use Drupal\drupal_helpers\Feature;

// Ensure the vocabulary exists.
Feature::revert('vu_core', 'taxonomy');

$terms = [
  'alumni',
  'current students',
  'future students',
  'industry',
  'library',
  'research',
  'researchers',
  'international',
];

// Load vocab and existing terms.
$vocab = taxonomy_vocabulary_machine_name_load('audience');
$existing = taxonomy_term_load_multiple([], ['vid' => $vocab->vid]);

// Ensure we don't add existing terms.
foreach ($existing as $exist) {
  if (FALSE !== $key = array_search($exist->name, $terms)) {
    unset($terms[$key]);
  }
}

// Add terms.
foreach ($terms as $term) {
  $term = [
    'vid' => $vocab->vid,
    'name' => $term,
  ];
  taxonomy_term_save((object) $term);
}
