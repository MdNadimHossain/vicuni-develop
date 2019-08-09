<?php

/**
 * @file
 * How to apply proxy template.
 */
echo theme('how-to-apply',
  [
    'course' => $node,
    'short_course' => $is_short_course,
    'international' => $is_international,
    'how_to_apply' => $how_to_apply,
    'college' => $college,
    'admission' => $has_admission_requirements,
  ]
);
