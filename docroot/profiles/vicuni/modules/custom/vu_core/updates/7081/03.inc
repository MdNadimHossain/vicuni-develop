<?php

/**
 * @file
 * Removes traces of previously removed modules.
 */

use Drupal\drupal_helpers\Module;

Module::remove('bugherd');
Module::remove('smart_ip');
