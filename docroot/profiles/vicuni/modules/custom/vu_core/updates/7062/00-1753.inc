<?php

/**
 * @file
 * Updates for [PW-1753].
 *
 * Removes deprecated module.
 */

use Drupal\drupal_helpers\Module;

Module::uninstall('media_wysiwyg_view_mode');
