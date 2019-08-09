<?php
/**
 * @file
 * Drush commands.
 */

/**
 * Implements hook_drush_help().
 */
function vu_midyear_intake_drush_help($section) {
  switch ($section) {
    case 'drush:vu-midyear-intake-rl':
      $help = dt('(vumyir) Reload Mid-Year availability of all courses.');
      break;

    case 'drush:vu-midyear-intake-up':
      $help = dt('(vumyiu) Scan the course_intake table and reindex any new changes.');
      break;
  }

  return $help;
}

/**
 * Implements hook_drush_command().
 */
function vu_midyear_intake_drush_command() {
  return array(
    'vu-midyear-intake-rl' => array(
      'description' => dt('Reload Mid-Year availability of all courses.'),
      'aliases' => array('vumyir'),
    ),
    'vu-midyear-intake-up' => array(
      'description' => dt('Scan the course_intake table and reindex any new changes.'),
      'aliases' => array('vumyiu'),
    ),
  );
}

/**
 * Callback for drush vu-midyear-intake-rl command.
 */
function drush_vu_midyear_intake_rl() {
  module_load_include('inc', 'vu_midyear_intake', 'vu_midyear_intake.admin');
  $batch = _vu_midyear_intake_reload_batch();
  batch_set($batch);
  $batch = &batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}

/**
 * Callback for drush vu-midyear-intake-up command.
 */
function drush_vu_midyear_intake_up() {
  vu_midyear_intake_update_index();
}
