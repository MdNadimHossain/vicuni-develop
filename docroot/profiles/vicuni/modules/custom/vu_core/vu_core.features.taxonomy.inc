<?php
/**
 * @file
 * vu_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vu_core_taxonomy_default_vocabularies() {
  return array(
    'audience' => array(
      'name' => 'Audience',
      'machine_name' => 'audience',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'delivery_modes' => array(
      'name' => 'Delivery Modes',
      'machine_name' => 'delivery_modes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'expertise' => array(
      'name' => 'Expertise',
      'machine_name' => 'expertise',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'fee_disclaimers' => array(
      'name' => 'Fee Disclaimers',
      'machine_name' => 'fee_disclaimers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'fee_types' => array(
      'name' => 'Fee Types',
      'machine_name' => 'fee_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'subsites' => array(
      'name' => 'Subsites',
      'machine_name' => 'subsites',
      'description' => 'Terms for storing the subsite configurations.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'success_categories' => array(
      'name' => 'Categories',
      'machine_name' => 'success_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'unit_set_type' => array(
      'name' => 'Unit Set Type',
      'machine_name' => 'unit_set_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
