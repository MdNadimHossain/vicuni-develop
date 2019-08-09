<?php

/**
 * @file
 * Code for VuRpViewsReportStatusHandler.
 */

/**
 * Views node updated handler.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsReportStatusHandler extends views_handler_field {

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
    $report_stat = '';

    $publish_stat = $values->workbench_moderation_node_history_state;
    $status = $values->_field_data['node_node_revision_nid']['entity']->workbench_moderation['current']->state;

    if ($publish_stat == 'published') {
      if ($status == 'published') {
        $report_stat = 'Published';
      }
      else {
        $report_stat = 'Amended & Awaiting Review';
      }
    }
    else {
      if ($status == 'draft') {
        $report_stat = 'Draft';
      }
      if ($status == 'needs_review') {
        $report_stat = 'Awaiting Review';
      }
    }

    return $report_stat;
  }

}
