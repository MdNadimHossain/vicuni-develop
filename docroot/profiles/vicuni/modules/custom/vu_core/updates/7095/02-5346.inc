<?php

/**
 * @file
 * PW-5346 - Add "fee disclaimers" taxonomy items.
 */

use Drupal\drupal_helpers\General;

$disclaimers = [
  [
    'name' => 'Disclaimer #1',
    'description' => '<a href="/study-at-vu/fees-scholarships/course-tuition-fees/commonwealth-supported-students">Commonwealth Supported Places</a> are subsidised by the Australian Government. Students pay a yearly contribution amount determined by the government (based on enrolled units, not the overall course).',
    'field_disclaimer_code' => '1',
  ],
  [
    'name' => 'Disclaimer #2',
    'description' => 'Fees shown are indicative (reviewed annually), based on a full-time study load for one year. Actual fees are calculated on the number and type of enrolled units (adjusted accordingly if studying less than a standard full-time load).',
    'field_disclaimer_code' => '2',
  ],
  [
    'name' => 'Disclaimer #3',
    'description' => '<a href="/study-at-vu/fees-scholarships/course-tuition-fees/full-fee-paying-students">Australian full-fee paying students</a> need to pay the full amount for all enrolled units. Fees shown are indicative (reviewed annually), based on a full-time study load for one year. Actual fees are calculated on the number and type of enrolled units (adjusted accordingly if studying less than a standard full-time load or course duration is less than one year).',
    'field_disclaimer_code' => '3',
  ],
  [
    'name' => 'Disclaimer #4',
    'description' => 'Australian full fee place; tuition fees are calculated based on the type of unit you enrol in and the associated fee band set by the University.',
    'field_disclaimer_code' => '4',
  ],
  [
    'name' => 'Disclaimer #5',
    'description' => '<a href="/study-at-vu/fees-scholarships/course-tuition-fees/international-student-fees">International fee paying place</a>; tuition fees are calculated based on the course you enrol in and year you commence study.',
    'field_disclaimer_code' => '5',
  ],
  [
    'name' => 'Disclaimer #6',
    'description' => 'Enrolling into a <a href="https://www.vupolytechnic.edu.au/eligibility-government-subsidised-place">government subsidised course</a> may impact your eligibility for government subsidy in the future. Talk to our staff at enrolment if you are not sure what this may mean for you.',
    'field_disclaimer_code' => '6',
  ],
  [
    'name' => 'Disclaimer #7',
    'description' => 'Tuition fees (as displayed) are subject to change based on your individual circumstances at enrolment.',
    'field_disclaimer_code' => '7',
  ],
  [
    'name' => 'Disclaimer #8',
    'description' => 'Find out more about <a href="/study-at-vu/courses/pathways-to-vu/credit-for-skills-past-study/recognition-of-prior-learning-rpl">Recognition of Prior Learning (RPL)</a>.',
    'field_disclaimer_code' => '8',
  ],
  [
    'name' => 'Disclaimer #9',
    'description' => '<a href="https://www.vupolytechnic.edu.au/fees-scholarships/course-fees">Concessions</a> are only available to eligible students enrolling into Certificate IV & below courses, or Aboriginal and Torres Strait Islander (ATSI) students enrolling into Diploma & above courses.',
    'field_disclaimer_code' => '9',
  ],
  [
    'name' => 'Disclaimer #10',
    'description' => '<a href="/current-students/your-course/fees/vet-tafe-fees/calculate-your-vet-tafe-fees">International fee paying place</a>; tuition fees are calculated based on the course you enrol in.',
    'field_disclaimer_code' => '10',
  ],
  [
    'name' => 'Disclaimer #11',
    'description' => 'Find out more about the <a href="https://www.vupolytechnic.edu.au/free-tafe ">Free TAFE 2019 initiative</a>.',
    'field_disclaimer_code' => '11',
  ],
  [
    'name' => 'Disclaimer #12',
    'description' => 'Foundations at VU is an enabling course that is fully funded by the government.',
    'field_disclaimer_code' => '12',
  ],
];


$vocabulary = taxonomy_vocabulary_machine_name_load('fee_disclaimers');
foreach ($disclaimers as $disclaimer) {
  $term = (object) [
    'name' => $disclaimer['name'],
    'vid' => $vocabulary->vid,
    'description' => $disclaimer['description'],
    'field_disclaimer_code' => [LANGUAGE_NONE => [['value' => $disclaimer['field_disclaimer_code']]]],
  ];

  taxonomy_term_save($term);

  General::messageSet(format_string('Created term "@name" (tid: @tid)', [
    '@name' => $term->name,
    '@tid' => $term->tid,
  ]));
}
