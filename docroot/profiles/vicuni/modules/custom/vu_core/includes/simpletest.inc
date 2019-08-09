<?php

/**
 * @file
 * Simpletest module integration.
 */

/**
 * Implements hook_simpletest_alter().
 */
function vu_core_simpletest_alter(&$groups) {
  $allowed_base_classes = ['VuCoreUnitTestCase', 'LinkManagementTestCase'];

  $allowed_groups = [];

  // Remove all tests that do not have parents from allowed test base classes.
  foreach ($groups as $group_name => &$group) {
    foreach ($group as $test_class_name => $test) {
      foreach ($allowed_base_classes as $allowed_base_class) {
        if (is_a($test_class_name, $allowed_base_class, TRUE)) {
          if (!isset($allowed_groups[$group_name])) {
            $allowed_groups[$group_name] = [];
          }
          if (!isset($allowed_groups[$group_name][$test_class_name])) {
            $allowed_groups[$group_name][$test_class_name] = $test;
          }
          continue(2);
        }
      }
    }
  }

  // Set allowed tests.
  $groups = $allowed_groups;
}

/**
 * Implements hook hook_registry_files_alter().
 */
function vu_core_registry_files_alter(&$files, $modules) {
  // Exclude test files from contrib modules that are relying on other contribs
  // that current site does not use. This allows to prevent BSOD when loading
  // simpletest admin page.
  $excluded_test_modules = [
    'drafty',
    'drafty_1992010',
    'drafty_enforce',
    'feeds_ex',
    'uuid_services',
  ];
  foreach ($files as $filename => $info) {
    if (in_array($info['module'], $excluded_test_modules) && pathinfo($filename, PATHINFO_EXTENSION) == 'test') {
      unset($files[$filename]);
    }
  }
}
