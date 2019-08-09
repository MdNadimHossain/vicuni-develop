<?php

/**
 * @file
 * Updates for [PW-2627].
 *
 * Cleanup features.
 */

use Drupal\drupal_helpers\Field;

Field::delete('field_url_alias_title');
