<?php

/**
 * @file
 * Bean module integration.
 */

/**
 * Log bean block insert.
 */
function bean_insert($form, &$form_state) {
  $log = [
    'type' => 'block',
    'operation' => 'insert',
    'description' => t('%type', [
      '%type' => $form_state['build_info']['args'][0]->type . ' type block created',
    ]),
    'ref_char' => $form_state['build_info']['args'][0]->type,
    'path' => $form_state['storage']['path'],
    'form_id' => $form['#form_id'],
  ];
  event_log_insert($log);
}

/**
 * Log bean block update.
 */
function bean_update($form, &$form_state) {
  $log = [
    'type' => 'block',
    'operation' => 'update',
    'description' => t('%type: %title', [
      '%type' => $form_state['build_info']['args'][0]->type,
      '%title' => $form_state['build_info']['args'][0]->label,
    ]),
    'ref_numeric' => $form_state['build_info']['args'][0]->bid,
    'ref_char' => $form_state['build_info']['args'][0]->type . '/' . $form_state['build_info']['args'][0]->label,
    'path' => $form_state['storage']['path'],
    'form_id' => $form['#form_id'],
  ];
  event_log_insert($log);
}
