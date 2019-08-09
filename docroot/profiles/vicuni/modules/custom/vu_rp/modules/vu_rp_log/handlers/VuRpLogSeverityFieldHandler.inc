<?php

/**
 * @file
 * Code for VuRpLogSeverityFieldHandler.
 */

use Drupal\vu_rp_api\Logger\Logger;

/**
 * Views severity level field handler.
 */
class VuRpLogSeverityFieldHandler extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $severity = $values->{$this->field_alias};

    // Map values to the severity level.
    return !empty($severity) ? Logger::severityMap($severity) : '';
  }

}
