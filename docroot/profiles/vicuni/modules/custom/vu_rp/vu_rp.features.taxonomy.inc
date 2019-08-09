<?php
/**
 * @file
 * vu_rp.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vu_rp_taxonomy_default_vocabularies() {
  return array(
    'membership_levels' => array(
      'name' => 'Membership levels',
      'machine_name' => 'membership_levels',
      'description' => 'Membership levels',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'membership_organisations' => array(
      'name' => 'Membership organisations',
      'machine_name' => 'membership_organisations',
      'description' => 'Membership organisations',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'research_institutes' => array(
      'name' => 'Research Institutes',
      'machine_name' => 'research_institutes',
      'description' => 'Research Institutes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
