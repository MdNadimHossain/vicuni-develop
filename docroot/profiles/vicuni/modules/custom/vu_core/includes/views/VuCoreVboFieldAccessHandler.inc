<?php

/**
 * @file
 * Code for VBO Field access.
 *
 * This file contains a new setting to control the access for the VBO field.
 */

/**
 * VBO field handler.
 *
 * @ingroup views_field_handlers
 */
class VuCoreVboFieldAccessHandler extends views_bulk_operations_handler_field_operations {

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['vbo_settings']['field_access'] = [
      '#type' => 'checkboxes',
      '#title' => t('User Access'),
      '#options' => user_roles(TRUE),
      '#default_value' => $this->options['vbo_settings']['field_access'],
      '#description' => t('Select the user roles that have access to use this field. Leave empty for all users.'),
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['vbo_settings']['contains']['field_access'] = ['default' => 0];

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function access() {
    if (isset($this->options['vbo_settings']['field_access']) && !empty($this->options['vbo_settings']['field_access'])) {
      $rids = array_filter($this->options['vbo_settings']['field_access']);
      if (!empty($rids)) {
        global $user;
        if (array_intersect_key($rids, $user->roles) == FALSE) {
          return FALSE;
        }
      }
    }

    // Do not modify access if nothing is selected.
    return TRUE;
  }

}
