<?php

/**
 * @file
 * Code for VuRpLogEventFilterHandler.
 */

/**
 * Views event filter handler.
 */
class VuRpLogEventFilterHandler extends views_handler_filter_in_operator {

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    // Get options from db to use as filters on log messages.
    $options = [];

    $events = vu_rp_log_get_events();
    foreach ($events as $key => $item) {
      $options[$key] = $item;
    }

    $this->value_options = $options;

    return $options;
  }

}
