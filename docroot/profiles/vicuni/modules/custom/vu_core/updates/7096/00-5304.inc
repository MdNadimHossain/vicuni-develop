<?php

/**
 * @file
 * PW-5304 - Log user events in CMS for the past 31 days.
 */

use Drupal\drupal_helpers\Module;

Module::enable('event_log');
Module::enable('event_log_menu');
Module::enable('event_log_node');
Module::enable('event_log_taxonomy');
Module::enable('event_log_user');
