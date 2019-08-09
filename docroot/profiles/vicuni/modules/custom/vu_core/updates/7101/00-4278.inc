<?php

/**
 * @file
 * PW-4278 - Reverted user permissions.
 */

use Drupal\drupal_helpers\General;
use Drupal\drupal_helpers\Feature;

Feature::revert('vu_core', 'user_permission');

if (variable_get('environment') == ENVIRONMENT_PROD) {
  General::messageSet('Skipping this update in production environment');

  return;
}

module_load_include('install', 'vu_rp_test', 'vu_rp_test');
$role = _vu_rp_test_install_create_test_role('Researcher Profile Admin');
