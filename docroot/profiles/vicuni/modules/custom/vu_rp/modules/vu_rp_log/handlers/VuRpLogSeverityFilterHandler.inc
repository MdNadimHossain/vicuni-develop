<?php

/**
 * @file
 * Code for VuRpLogSeverityFilterHandler.
 */

use Drupal\vu_rp_api\Logger\Logger;

/**
 * Views severity level filter handler.
 */
class VuRpLogSeverityFilterHandler extends views_handler_filter_in_operator {

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    // Override default options to display log severity.
    $severity = [];

    $map = Logger::severityMap();
    foreach ($map as $key => $item) {
      $severity[$key] = $item;
    }

    $this->value_options = $severity;

    return $severity;
  }

}
