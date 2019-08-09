<?php

/**
 * @file
 * PW-5973 - Show pop up for users outside AU and NZ.
 */

use Drupal\drupal_helpers\Module;

// Delete records.
db_drop_table('smart_ip');
db_drop_table('cache_smart_ip');

// Enable smart_ip module.
Module::enable('smart_ip');
