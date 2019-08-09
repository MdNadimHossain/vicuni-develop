<?php
/**
 * @file
 * vu_rp.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function vu_rp_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['vu_rp-researcher_profile_navbar'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'researcher_profile_navbar',
    'module' => 'vu_rp',
    'node_types' => array(
      0 => 'researcher_profile',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'victory' => array(
        'region' => 'below_header',
        'status' => 1,
        'theme' => 'victory',
        'weight' => 0,
      ),
      'vu' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'vu',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
