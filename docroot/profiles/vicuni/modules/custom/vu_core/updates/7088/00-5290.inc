<?php

/**
 * @file
 * PW-5290 - Close of VET courses from Callista in preparation for DATA from S1.
 *
 * @see PW-5290
 */

db_update('course_intake')
  ->fields([
    'course_intake_status' => 'FULL',
    'updated_date_time' => date("Y-m-d H:i:s"),
  ])
  ->condition('course_intake_status', 'OFFERED', '=')
  ->condition('sector_code', 'VET', '=')
  ->condition('course_index_id', 'S1%', 'NOT LIKE')
  ->execute();
