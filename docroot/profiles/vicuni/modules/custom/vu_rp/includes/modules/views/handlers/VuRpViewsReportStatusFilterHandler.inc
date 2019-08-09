<?php

/**
 * @file
 * Code for VuRpViewsReportStatusFilterHandler.
 */

/**
 * Views status filter handler.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsReportStatusFilterHandler extends views_handler_filter_field_list {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Intentionally empty to override the parent query.
  }

  /**
   * Provide filter options.
   */
  public function value_form(&$form, &$form_state) {
    $form['value']['#tree'] = TRUE;
    $rp_status = [
      1 => 'Published',
      2 => 'Draft',
      3 => 'Amended & Awaiting Review',
      4 => 'Awaiting Review',
    ];

    $form['value']['status'] = [
      '#type' => 'select',
      '#title' => 'STATUS',
      '#options' => $rp_status,
    ];

    if (!isset($form['value'])) {
      // Ensure there is something in the 'value'.
      $form['value'] = [
        '#type' => 'value',
        '#value' => NULL,
      ];
    }
  }

}
