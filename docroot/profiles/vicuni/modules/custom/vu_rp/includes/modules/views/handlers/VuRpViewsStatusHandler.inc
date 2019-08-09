<?php

/**
 * @file
 * Code for VuRpViewsStatusHandlers.
 */

/**
 * Views status field handler.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsStatusHandler extends views_handler_field {

  /**
   * {@inheritdoc}
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
    $nid = isset($values->node_field_data_field_rp_nid_nid) ? $values->node_field_data_field_rp_nid_nid : '';

    return !empty($nid) ? 'Active' : 'Inactive';
  }

}
