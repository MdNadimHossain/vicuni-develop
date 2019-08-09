<?php

/**
 * @file
 * Updates for [PW-1507].
 *
 * Enables vpoly_core module.
 */

use Drupal\drupal_helpers\Module;
use Drupal\drupal_helpers\General;

cache_clear_all();
drupal_static_reset();
Module::enable('vpoly_core');

// We are reverting components in two steps to fix an eck cache issue that
// requires reloading entities to get permissions working.
// First group of components.
features_revert([
  'vpoly_core' => [
    'eck_bundle',
    'eck_entity_type',
    'features_api',
    'field_base',
    'field_instance',
  ],
]);

cache_clear_all();
drupal_static_reset();
EntityType::loadAll(TRUE);
Bundle::loadAll(TRUE);

// User permission related components.
features_revert([
  'vpoly_core' => [
    'user_permission',
    'user_role',
  ],
]);

// Assign TAFE AUTHOR role to Madeleine.
$user = user_load_by_mail('Madeleine.Millett-Riley@vu.edu.au');
$role_name = 'TAFE Author';
if ($role = user_role_load_by_name($role_name)) {
  user_multiple_role_edit([$user->uid], 'add_role', $role->rid);
  General::messageSet('Assigned role TAFE Author to: Madeleine.Millett-Riley@vu.edu.au ');
}
else {
  General::messageSet('Role "TAFE Author" was not found.');
}
