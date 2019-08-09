<?php

/**
 * @file
 * Code for VuRpViewsOptedOutHandler.
 */

/**
 * Views inactive users field handler.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsOptedOutHandler extends views_handler_field {

  /**
   * Called to add the field to a query.
   */
  public function query() {
    // Intentionally empty to override the parent query.
  }

  /**
   * Render the field.
   *
   * @param object $values
   *   The values retrieved from the database.
   */
  public function render($values) {
    return vu_rp_workbench_get_opted_out_user_count();
  }

}
