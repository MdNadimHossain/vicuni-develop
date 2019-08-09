<?php

/**
 * @file
 * Updated Victoria polytechnic links.
 */

db_update('field_data_field_college')
  ->fields([
    'field_college_url' => 'https://www.vupolytechnic.edu.au',
  ])
  ->condition('field_college_title', ['VU Polytechnic', 'Victoria Polytechnic'], 'IN')
  ->execute();

db_update('field_revision_field_college')
  ->fields([
    'field_college_url' => 'https://www.vupolytechnic.edu.au',
  ])
  ->condition('field_college_title', ['VU Polytechnic', 'Victoria Polytechnic'], 'IN')
  ->execute();
