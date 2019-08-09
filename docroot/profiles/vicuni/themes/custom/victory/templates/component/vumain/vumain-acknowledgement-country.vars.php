<?php

/**
 * @file
 * File for "vumain_acknowledgement_country" theme hook [pre]process functions.
 */

/**
 * Preprocess for theme_vumain_acknowledgement_country.
 */
function victory_preprocess_vumain_acknowledgement_country(&$variables) {
  $variables['attributes_col1'] = [];
  $variables['attributes_col1']['class'][] = 'footer-aoc-flag';
  $variables['attributes_col1']['class'][] = 'col-sm-2 col-md-1';
  $variables['attributes_col2'] = [];
  $variables['attributes_col2']['class'][] = 'col-sm-10 col-md-11';
}
