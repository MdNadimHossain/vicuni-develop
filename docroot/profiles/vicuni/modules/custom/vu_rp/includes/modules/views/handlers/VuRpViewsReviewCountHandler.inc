<?php

/**
 * @file
 * Code for VuRpViewsReviewCountHandler.
 */

/**
 * Views node updated handler.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsReviewCountHandler extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Intentionally empty to override the parent query.
  }

  /**
   * Render callback handler.
   */
  public function render($values) {
    return vu_rp_workbench_get_needs_review_count();
  }

}
