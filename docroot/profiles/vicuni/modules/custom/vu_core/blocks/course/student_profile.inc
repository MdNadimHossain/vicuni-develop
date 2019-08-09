<?php

/**
 * @file
 * Student Profile.
 */

define('SP_HE_TEXT', '<strong>(A) Past Higher Education Study</strong><br/>(includes a bridging or enabling course)');
define('SP_VE_TEXT', '<strong>(B) Past vocational education and training (VET) study</strong>');
define('SP_ATAR_ONLY_TEXT', '<strong>(C) Recent secondary education</strong><p>Admitted solely on the basis of ATAR<br/>(regardless of whether this includes the impact of adjustment factors such as equity or subject bonus points)</p>');
define('SP_ATAR_PLUS_TEXT', '<strong>(C) Recent secondary education</strong><p>Admitted where both ATAR and additional criteria were considered<br/>(e.g. portfolio, audition, extra test, early offer conditional on minimum ATAR)</p>');
define('SP_NA_TEXT', '<strong>(C) Recent secondary education</strong><p>Admitted on the basis of other criteria only and ATAR was <strong><u>not</u></strong> a factor<br/>(e.g. special consideration alone, audition alone, schools recommendation scheme with no minimum ATAR requirement)</p>');
define('SP_WORK_LIFE_TEXT', '<strong>(D) Work and Life experience</strong>');
define('SP_INTERNATIONAL_TEXT', '<strong>International students</strong>');
define('SP_ALL_TEXT', '<strong>All students</strong>');

/**
 * Class VuCoreStudentProfileCourseBlock.
 */
class VuCoreStudentProfileCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Student profile';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_student_profile_block';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    if (vu_feature_switches_switch_state('courses-admission-transparency')) {
      // Ensure that this works for only HE diploma courses.
      if ($this->getCourseAqf() == VU_CBS_AQF_DIPLOMA) {
        if ($this->getCourseType() != VU_CBS_TYPE_HE) {
          return FALSE;
        }
      }

      return TRUE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $variables = [
      'title' => t('Student profile'),
      'table_title' => 'Student profile',
    ];
    // Generate student profile data.
    $data = student_profile_generate_data($this->course);

    if ($data) {
      $variables['display_table'] = TRUE;
      $variables['table'] = student_profile_generate_table($data);
    }

    return $variables;
  }

}

/**
 * Generate the table.
 */
function student_profile_generate_table($data = []) {

  if (empty($data)) {
    return '';
  }

  $colgroup = [
    // COLGROUP with one COL element.
    [
      [
        'style' => [
          'width: 55%',
        ],
      ],
    ],
    [
      [
        'style' => [
          'width: 22.5%',
        ],
      ],
    ],
    [
      [
        'style' => [
          'width: 22.5%',
        ],
      ],
    ],
  ];
  $header = [
    // First column header.
    ['data' => t('Applicant background')],
    // Second column header.
    ['data' => t('Number of students')],
    // Third column header.
    ['data' => t('Percentage of all students')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_HE_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'he_study', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 'he_study', 'percentage')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_VE_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 've_study', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 've_study', 'percentage')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_ATAR_ONLY_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'atar_only', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 'atar_only', 'percentage')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_ATAR_PLUS_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'atar_plus', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 'atar_plus', 'percentage')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_NA_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'se_na', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 'se_na', 'percentage')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_WORK_LIFE_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'work_life', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 'work_life', 'percentage')],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_INTERNATIONAL_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'international', 'students')],
    // Percentage of all students.
    [
      'data' => student_profile_get_row_data($data, 'international', 'percentage'),
    ],
  ];
  $rows[] = [
    // Applicant background.
    ['data' => SP_ALL_TEXT],
    // Number of students.
    ['data' => student_profile_get_row_data($data, 'total', 'students')],
    // Percentage of all students.
    ['data' => student_profile_get_row_data($data, 'total', 'percentage')],
  ];

  return theme('table',
    // Creating array for data.
    [
      // Value header will be in $header.
      'sticky' => FALSE,
      'header' => $header,
      // Value rows will be taken out of $rows.
      'rows' => $rows,
      'colgroups' => $colgroup,
    ]
  );
}

/**
 * Generate table data.
 */
function student_profile_generate_data($course = []) {

  if (empty($course)) {
    return FALSE;
  }

  $data = [];
  // Define fields to look for.
  $fields = [
    'he_study' => 'field_he_study',
    've_study' => 'field_ve_study',
    'atar_only' => 'field_se_atar_only',
    'atar_plus' => 'field_se_atar_plus',
    'se_na' => 'field_se_na',
    'work_life' => 'field_work_life',
    'international' => 'field_international_study',
    'total' => 'field_total_study',
  ];

  foreach ($fields as $key => $field_name) {
    $field = field_get_items('node', $course, $field_name);
    if (is_array($field)) {
      $field = reset($field);
      $data[$key]['students'] = $field['first'];
      $data[$key]['percentage'] = $field['second'];
    }
  }

  return $data;
}

/**
 * Retrieve value from row.
 */
function student_profile_get_row_data($data = [], $row = '', $col = '') {

  if (isset($data[$row][$col])) {
    $suffix = ($col == "percentage" && is_numeric($data[$row][$col])) ? t('%') : '';
    return $data[$row][$col] . $suffix;
  }

  return FALSE;
}
