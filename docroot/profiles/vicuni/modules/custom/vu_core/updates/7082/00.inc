<?php

/**
 * @file
 * Enables Researcher Profile functionality.
 */

use Drupal\drupal_helpers\Feature;
use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Module;

Module::enable('vu_rp');

Feature::revert('vu_core', 'user_permission');
Feature::revert('vu_rp');

$environment = variable_get('environment', FALSE);
$non_production_environments = [
  ENVIRONMENT_LOCAL => TRUE,
  ENVIRONMENT_DEV => TRUE,
  ENVIRONMENT_TEST => TRUE,
  ENVIRONMENT_TEST2 => TRUE,
];

if (isset($non_production_environments[$environment])) {
  Module::enable('queue_ui');

  General::messageSet('Enabling Researcher Profile test and demo modules', '-- ', 0);
  Module::enable('vu_rp_demo');
}
