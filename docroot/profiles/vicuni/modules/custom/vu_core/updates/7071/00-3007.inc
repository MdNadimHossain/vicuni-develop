<?php

/**
 * @file
 * Updates for PW-3007.
 *
 * Added VU Pathways field.
 */

use Drupal\drupal_helpers\Module;

// Removes old pathways schema.
drupal_uninstall_schema('vu_core');
Module::enable('vu_pathway');
