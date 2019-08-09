<?php

/**
 * @file
 * Code for VuRpViewsStatusFilterHandler.
 */

/**
 * Views status filter handler.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsStatusFilterHandler extends views_handler_filter_field_list {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Intentionally empty to override the parent query.
  }

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    $this->value_options = [
      1 => 'Active',
      0 => 'Inactive',
    ];
  }

}
