<?php

/**
 * @file
 * Drush commands to provision researcher profile demo content.
 */

define('VU_RP_DEMO_PROVISION_STEP_ALL', 'all');

/**
 * Implements hook_drush_command().
 */
function vu_rp_demo_drush_command() {
  $items = [];

  $items['vu-rp-provision'] = [
    'description' => 'Provision content.',
    'arguments' => [
      'steps' => dt('Comma-separated list of steps to run or `all` to run all available steps.'),
    ],
    'examples' => [
      'drush provision all' => 'Provision all content.',
      'drush provision users, articles' => 'Provision users and articles in the specified order.',
    ],
  ];

  $items['vu-rp-provision-remove'] = [
    'description' => 'Remove provisioned content.',
  ];

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function vu_rp_demo_drush_help($section) {
  switch ($section) {
    case 'drush:provision':
      return dt('Provision content for website features.');

    case 'drush:provision-remove':
      return dt('Remove previously provisioned content for website features.');
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_vu_rp_demo_vu_rp_provision_validate() {
  $arguments = drush_get_arguments();

  if (count(array_filter($arguments)) < 2) {
    return drush_set_error('NOT_ENOUGH_ARGUMENTS', dt('Please provide "@all" or one/several of multiple available steps: @steps', [
      '@all' => VU_RP_DEMO_PROVISION_STEP_ALL,
      '@steps' => implode(', ', vu_rp_demo_get_all_steps()),
    ]));
  }

  $arg_steps = _vu_rp_demo_drush_parse_steps(array_slice($arguments, 1));

  // Validate that when `all` is provided, no other steps are in the list,
  // because we do not want to resolve which steps to run.
  if (in_array(VU_RP_DEMO_PROVISION_STEP_ALL, $arg_steps)) {
    if (count($arg_steps) > 1) {
      return drush_set_error('TOO_MANY_STEPS', dt('Too many arguments provided with "@all"', [
        '@all' => VU_RP_DEMO_PROVISION_STEP_ALL,
      ]));
    }

    return TRUE;
  }

  // Validate that provided steps exist.
  $non_existing_steps = array_diff($arg_steps, vu_rp_demo_get_all_steps());
  if (count($non_existing_steps) > 0) {
    return drush_set_error('INVALID_STEPS', dt('Invalid steps provided: @steps.', ['@steps' => implode(', ', $non_existing_steps)]));
  }

  return TRUE;
}

/**
 * Implements drush_hook_COMMAND().
 */
function drush_vu_rp_demo_vu_rp_provision($steps = [VU_RP_DEMO_PROVISION_STEP_ALL]) {
  // Try to retrieve steps from arguments (they were previously validated).
  $arguments = drush_get_arguments();
  $arg_steps = _vu_rp_demo_drush_parse_steps(array_slice($arguments, 1));
  $steps = empty($arg_steps) ? $steps : $arg_steps;
  $steps = in_array(VU_RP_DEMO_PROVISION_STEP_ALL, $steps) ? vu_rp_demo_get_all_steps() : $steps;
  try {
    vu_rp_demo_process_provision_steps($steps);
  }
  catch (RuntimeException $exception) {
    drush_set_error('STEP_REQUIREMENTS', $exception->getMessage());
  }
}

/**
 * Implements drush_hook_COMMAND().
 */
function drush_vu_rp_demo_vu_rp_provision_remove() {
  if (drush_confirm('All provisioned demo content will be removed. Proceed?')) {
    vu_rp_demo_records_remove_all(TRUE);
  }
}

/**
 * Helper to parse comma-separated steps into array.
 */
function _vu_rp_demo_drush_parse_steps($string) {
  $string = is_array($string) ? implode('', $string) : $string;

  return preg_split('/\s*\,\s*/', $string);
}
