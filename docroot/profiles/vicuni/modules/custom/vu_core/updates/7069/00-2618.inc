<?php

/**
 * @file
 * Updates for [PW-2618].
 *
 * Remove obsolete modules and configuration.
 */

use Drupal\drupal_helpers\Module;

Module::uninstall('context_var');
