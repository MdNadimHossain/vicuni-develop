<?php

/**
 * @file
 * Template file for the fee calculator.
 */

define('FEE_AUDIENCE_DOMESTIC', 0);
define('FEE_AUDIENCE_INTERNATIONAL', 1);

define('FEE_SECTOR_HE', 'HE');
define('FEE_SECTOR_VE', 'VE');

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_fee_calculator_info() {
  return [
    'info' => t('Fee Calculator'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_fee_calculator_view() {
  $request_params = drupal_get_query_parameters();

  $variables['international'] = FALSE;
  if (isset($request_params['international'])) {
    $variables['international'] = (bool) $request_params['international'];
  }

  drupal_add_js(
    drupal_get_path('module', 'vu_core') . '/js/vu_core.fee-calculator.js',
    [
      'scope' => 'footer',
    ]
  );

  $variables['fee_type_select_options'] = vu_core_get_fee_type_select_options();

  $sectors = vu_core_get_sectors();
  $variables['sectors'] = $sectors;
  $variables['default_sector'] = _vu_core_get_default_sector($sectors);

  $cohort_years = vu_core_get_cohort_years();
  $variables['cohort_years'] = _vu_core_get_cohort_year_values($cohort_years);
  $variables['default_cohort_year'] = _vu_core_get_default_cohort_year($cohort_years);

  $fee_years = vu_core_get_fee_years(2, FALSE);
  $variables['fee_years'] = $fee_years;
  $variables['default_fee_year'] = _vu_core_get_default_fee_year($fee_years);

  $variables['disclaimers'] = vu_core_get_fee_disclaimers();

  return [
    'content' => theme('vu_fee_calculator', $variables),
  ];
}

/**
 * Calculate a default sector for the given collection of sectors.
 *
 * @param array $sectors
 *   The available sectors.
 *
 * @return string|null
 *   The default sector.
 */
function _vu_core_get_default_sector(array $sectors) {
  foreach ($sectors as $key => $sector) {
    return $key;
  }

  return NULL;
}

/**
 * Transform the provided cohort years into something usable on the frontend.
 *
 * @param array $cohort_years
 *   The available cohort years.
 *
 * @return array
 *   The default transformed cohort years.
 */
function _vu_core_get_cohort_year_values(array $cohort_years) {
  $response = [];

  $first = TRUE;
  foreach ($cohort_years as $cohort_year) {
    if ($first) {
      $first = FALSE;
      $response[] = [
        'value' => $cohort_year,
        'label' => $cohort_year . ' or prior',
      ];
    }
    else {
      $response[] = [
        'value' => $cohort_year,
        'label' => $cohort_year,
      ];
    }
  }

  return $response;
}

/**
 * Calculate a default cohort year for the given collection of cohort years.
 *
 * @param array $cohort_years
 *   The available cohort years.
 *
 * @return string|null
 *   The default fee year.
 */
function _vu_core_get_default_cohort_year(array $cohort_years) {
  if (count($cohort_years) === 0) {
    return NULL;
  }

  $current_year = date('Y');

  // PW-5592: Current year must always be selected by default.
  foreach ($cohort_years as $cohort_year) {
    if ($cohort_year === $current_year) {
      return $cohort_year;
    }
  }

  return $cohort_years[0];
}

/**
 * Calculate a default fee year for the given collection of fee years.
 *
 * @param array $fee_years
 *   The available fee years.
 *
 * @return string|null
 *   The default fee year.
 */
function _vu_core_get_default_fee_year(array $fee_years) {
  if (count($fee_years) === 0) {
    return NULL;
  }

  $current_year = date('Y');

  // PW-5592: Current year must always be selected by default.
  foreach ($fee_years as $fee_year) {
    if ($fee_year === $current_year) {
      return $fee_year;
    }
  }

  return $fee_years[0];
}
