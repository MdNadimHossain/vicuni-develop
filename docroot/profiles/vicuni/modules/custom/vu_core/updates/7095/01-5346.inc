<?php

/**
 * @file
 * PW-5346 - Add "fee type" taxonomy items.
 */

use Drupal\drupal_helpers\General;

$feeTypes = [
  [
    'name' => 'HE - Commonwealth Supported Place (CSP)',
    'display_name' => 'Commonwealth Supported Place (CSP)',
    'sector' => 'HE',
  ],
  [
    'name' => 'HE - Full fee',
    'display_name' => 'Full fee',
    'sector' => 'HE',
  ],
  [
    'name' => 'TAFE - Government subsidised',
    'display_name' => 'Government subsidised',
    'sector' => 'VE',
  ],
  [
    'name' => 'TAFE - Government subsidised RPL',
    'display_name' => 'Government subsidised RPL',
    'sector' => 'VE',
  ],
  [
    'name' => 'TAFE - Government subsidised concession',
    'display_name' => 'Government subsidised concession',
    'sector' => 'VE',
  ],
  [
    'name' => 'TAFE - Government subsidised concession RPL',
    'display_name' => 'Government subsidised concession RPL',
    'sector' => 'VE',
  ],
  [
    'name' => 'TAFE - Full fee',
    'display_name' => 'Full fee',
    'sector' => 'VE',
  ],
  [
    'name' => 'TAFE - Full fee RPL',
    'display_name' => 'Full fee RPL',
    'sector' => 'VE',
  ],
];


$vocabulary = taxonomy_vocabulary_machine_name_load('fee_types');
foreach ($feeTypes as $feeType) {
  $term = (object) [
    'name' => $feeType['name'],
    'vid' => $vocabulary->vid,
    'field_display_name' => [LANGUAGE_NONE => [['value' => $feeType['display_name']]]],
    'field_sector' => [LANGUAGE_NONE => [['value' => $feeType['sector']]]],
  ];

  taxonomy_term_save($term);

  General::messageSet(format_string('Created term "@name" (tid: @tid)', [
    '@name' => $term->name,
    '@tid' => $term->tid,
  ]));
}
