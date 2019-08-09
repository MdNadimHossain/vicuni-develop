<?php

/**
 * @file
 * Migrate contact us link.
 */

use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Feature;

// Ensure the field exists.
Feature::revert('vu_core', 'field_base');
Feature::revert('vu_core', 'field_instance');

$terms = taxonomy_get_tree(2, 0, NULL, TRUE);
foreach ($terms as $term) {

  $url = vu_core_extract_single_field_value($term, 'taxonomy_term', 'field_subsite_contact_us', 'url');
  if (!empty($url)) {
    $term->field_contact_us_link[LANGUAGE_NONE][0] = [
      'value' => $url,
    ];

    taxonomy_term_save($term);

    General::messageSet(format_string('Contact us link migrated', [
      '@name' => $term->name,
      '@tid' => $term->tid,
    ]));
  }
}

// Delete field.
field_delete_field('field_subsite_contact_us');
