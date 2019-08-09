<?php

/**
 * @file
 * Timestamp submit handler to handle microseconds.
 */

class VuRpLogTimestampFieldHandler extends views_handler_field_date {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    if (property_exists($values, 'vu_rp_log_timestamp')) {
      $values->vu_rp_log_timestamp = intval($values->vu_rp_log_timestamp);
    }

    return parent::render($values);
  }

}
