<?php

/**
 * @file
 * PW-5831 - Enable Robotstxt.
 */

use Drupal\drupal_helpers\Module;
use Drupal\drupal_helpers\General;

Module::enable('robotstxt');

if (variable_get('environment') == ENVIRONMENT_PROD) {
  General::messageSet('Skipping robotstxt override.');

  return;
}

// Set robotstxt.
$content = "User-agent: * \nDisallow: /";

vu_core_set_robotstxt($content);
