<?php
/**
 * @file
 * vu_core.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function vu_core_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'victory';
  $breakpoint_group->name = 'Victory';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.victory.xs',
    1 => 'custom.victory.sm',
    2 => 'custom.victory.md',
    3 => 'custom.victory.lg',
    4 => 'custom.victory.xl',
    5 => 'custom.user.xxl',
    6 => 'custom.user.xxxl',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 1;
  $export['victory'] = $breakpoint_group;

  return $export;
}
