<?php

/**
 * @file
 * Base classes to Course block system.
 */

/**
 * Audience conditions.
 */
define('VU_CBS_AUDIENCE_DOMESTIC', 1);
define('VU_CBS_AUDIENCE_INTERNATIONAL', 2);
define('VU_CBS_AUDIENCE_ALL', VU_CBS_AUDIENCE_DOMESTIC | VU_CBS_AUDIENCE_INTERNATIONAL);

/**
 * Course type conditions.
 */
define('VU_CBS_TYPE_HE', 1);
define('VU_CBS_TYPE_NA', 2);
define('VU_CBS_TYPE_VE', 4);
define('VU_CBS_TYPE_ALL', VU_CBS_TYPE_HE | VU_CBS_TYPE_NA | VU_CBS_TYPE_VE);

/**
 * Course level conditions.
 */
// Non-award:
// Statement of Attainment.
define('VU_CBS_AQF_SA', 1);

// Level 1:
// Certificate I.
define('VU_CBS_AQF_CERT_I', 2);

// Level 2:
// Certificate II.
define('VU_CBS_AQF_CERT_II', 4);

// Level 3:
// Certificate III.
define('VU_CBS_AQF_CERT_III', 8);

// Level 4:
// Certificate IV.
define('VU_CBS_AQF_CERT_IV', 16);

// Level 5:
// Diploma.
define('VU_CBS_AQF_DIPLOMA', 32);

// Level 6:
// Advanced Diploma.
define('VU_CBS_AQF_ADV_DIPLOMA', 64);
// Associate Degree.
define('VU_CBS_AQF_ASSOC_DEGREE', 128);

// Level 7:
// Bachelor Degree.
define('VU_CBS_AQF_BACHE_DEGREE', 256);

// Level 8:
// Bachelor Honours Degree (embedded).
define('VU_CBS_AQF_BACHE_HON_DEGREE_EMB', 512);
// Bachelor Honours Degree (stand alone).
define('VU_CBS_AQF_BACHE_HON_DEGREE_SA', 1024);
// Graduate Certificate.
define('VU_CBS_AQF_GRAD_CERT', 2048);
// Graduate Diploma.
define('VU_CBS_AQF_GRAD_DIPLOMA', 4096);

// Level 9:
// Bachelor Degree/Masters (Coursework) Degree.
define('VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE', 8192);
// Masters (Coursework) Degree.
define('VU_CBS_AQF_MASTERS_DEGREE', 16384);
// Masters (Research) Degree.
define('VU_CBS_AQF_MASTERS_DEGREE_RESEARCH', 32768);

// Level 10:
// Doctoral Degree.
define('VU_CBS_AQF_DOC_DEGREE', 65536);

// Groups.
define('VU_CBS_AQF_GROUP_ALL', 131071);
define('VU_CBS_AQF_GROUP_CERT', VU_CBS_AQF_CERT_I | VU_CBS_AQF_CERT_II | VU_CBS_AQF_CERT_III | VU_CBS_AQF_CERT_IV);

/**
 * Open conditions.
 */
define('VU_CBS_OPEN_IGNORE', -1);
define('VU_CBS_OPEN_NO', 0);
define('VU_CBS_OPEN_YES', 1);
define('VU_CBS_OPEN_CUSTOM', 2);

/**
 * Locations.
 */
define('VUC_CBS_LOC_VU_ONLINE', 'Victoria University Online');

/**
 * Class VuCoreCourseBlockBase.
 */
class VuCoreCourseBlockBase {

  /**
   * Block cache mode.
   *
   * @var int
   */
  public static $cache = DRUPAL_CACHE_GLOBAL;

  /**
   * Block course AQF level condition.
   *
   * @var int
   */
  public $condAQF = VU_CBS_AQF_GROUP_ALL;

  /**
   * Block audience condition.
   *
   * @var int
   */
  public $condAudience = VU_CBS_AUDIENCE_ALL;

  /**
   * Block course type condition.
   *
   * @var int
   */
  public $condOpen = VU_CBS_OPEN_IGNORE;

  /**
   * Block course type condition.
   *
   * @var int
   */
  public $condType = VU_CBS_TYPE_ALL;

  /**
   * The Course node object.
   *
   * @var bool|object
   */
  protected $course = FALSE;

  /**
   * The Course AQF level.
   *
   * @var bool|int
   */
  protected $courseAQF = FALSE;

  /**
   * The Course intake object.
   *
   * @var bool|CourseIntakeList
   */
  protected $courseIntake = FALSE;

  /**
   * The Course type.
   *
   * @var bool|int
   */
  protected $courseType = FALSE;

  /**
   * Human readable block name.
   *
   * @var null|string
   */
  public static $info = NULL;

  /**
   * The theme to render.
   *
   * @var bool
   */
  public $theme = FALSE;

  /**
   * VuCoreCourseBlockBase constructor.
   *
   * @param \stdClass|null $course
   *   Mock course object.
   */
  public function __construct(stdClass $course = NULL) {
    // Get course, using audience arguments.
    $this->course = is_null($course) ? _vu_core_block_menu_get_course_object($this->condAudience & VU_CBS_AUDIENCE_DOMESTIC, $this->condAudience & VU_CBS_AUDIENCE_INTERNATIONAL) : $course;
    if ($this->course) {
      $this->courseType = $this->getCourseType();
      $this->courseAQF = $this->getCourseAqf();
      if ($this->condOpen !== VU_CBS_OPEN_IGNORE) {
        $this->courseIntake = $this->getCourseIntake();
      }
    }
  }

  /**
   * Extra conditions callback.
   *
   * @return bool
   *   TRUE if block should display, else FALSE.
   */
  public function condCallback() {
    return TRUE;
  }

  /**
   * Get the course intake object.
   *
   * @return \CourseIntakeList
   *   The Course intake object.
   */
  public function getCourseIntake() {
    if (isset($this->course->_intakes)) {
      return new CourseIntakeList($this->course->_intakes);
    }
    $course_code = vu_core_extract_single_field_value($this->course, 'node', 'field_unit_code');

    return vu_course_index_get_course_intake_list($course_code);
  }

  /**
   * Get course type.
   *
   * @return bool|int
   *   The course type, or FALSE.
   */
  public function getCourseType() {
    // Ensure there's an active course node.
    if (!$this->course) {
      return FALSE;
    }

    // Ensure the course has a populate `field_unit_lev` field.
    $unit_level = field_get_items('node', $this->course, 'field_unit_lev');
    if (!isset($unit_level[0]['value'])) {
      return FALSE;
    }

    // Return the result.
    switch ($unit_level[0]['value']) {

      // HE.
      case 'he_diplomas':
      case 'postgrad':
      case 'postgrad_research':
      case 'undergrad':
        return VU_CBS_TYPE_HE;

      // NA.
      case 'short':
        return VU_CBS_TYPE_NA;

      // VE.
      case 'tafe':
        return VU_CBS_TYPE_VE;

    }

    // Else, return FALSE.
    return FALSE;
  }

  /**
   * Get course AQF level.
   *
   * @return bool|int
   *   The AQF level, or FALSE.
   */
  public function getCourseAqf() {
    // Ensure there's an active course node.
    if (!$this->course) {
      return FALSE;
    }

    // Ensure the course has a populate `field_unit_lev` field.
    $aqf = field_get_items('node', $this->course, 'field_course_aqf');
    if (!isset($aqf[0]['safe_value'])) {
      return FALSE;
    }

    // Ensure AQF level translates to a constant.
    $aqf = 'VU_CBS_AQF_' . $this->stringToConstant($aqf[0]['safe_value']);
    if (!defined($aqf)) {
      return FALSE;
    }

    // Return the constant.
    return constant($aqf);
  }

  /**
   * Convert string to constant.
   *
   * @param string $string
   *   The string.
   *
   * @return mixed|string
   *   The constant.
   */
  private function stringToConstant($string) {
    $replacements = [
      '' => ['(', ')', 'COURSEWORK'],
      'ADV' => 'ADVANCED',
      'ASSOC' => 'ASSOCIATE',
      'BACHE' => 'BACHELOR',
      'CERT' => 'CERTIFICATE',
      'DOC' => 'DOCTORAL',
      'EMB' => 'EMBEDDED',
      'GRAD' => 'GRADUATE',
      'HON' => 'HONOURS',
      'SA' => ['STAND ALONE', 'STATEMENT OF ATTAINMENT'],
      '_' => [' ', '/'],
    ];

    $string = strtoupper($string);
    foreach ($replacements as $replace => $search) {
      $string = str_replace($search, $replace, $string);
    }

    // Move 'RESEARCH' to the end of the string.
    if (strstr($string, 'RESEARCH')) {
      $string = str_replace('RESEARCH', '', $string) . '_RESEARCH';
    }

    // Ensure no double underscores.
    $string = str_replace('__', '_', $string);

    return $string;
  }

  /**
   * Check if the block should be visible.
   *
   * @TODO - If mock course object provided, we need to check audience.
   *
   * @return bool
   *   TRUE if the block is visible, else FALSE.
   */
  public function isVisible() {
    // Ensure a course is set; This also ensures the valid audience is set.
    if (!$this->course) {
      return FALSE;
    }

    // Check course type.
    if (!($this->condType & $this->courseType)) {
      return FALSE;
    }

    // Check course AQF level.
    if ($this->condAQF !== VU_CBS_AQF_GROUP_ALL && !($this->condAQF & $this->courseAQF)) {
      return FALSE;
    }

    // Check course open status.
    if ($this->courseIntake) {
      // If course is open and condition is closed, return FALSE.
      if ($this->isOpen() && $this->condOpen == VU_CBS_OPEN_NO) {
        return FALSE;
      }

      // If course is closed and condition is open, return FALSE.
      if (!$this->isOpen() && $this->condOpen == VU_CBS_OPEN_YES) {
        return FALSE;
      }
    }

    return $this->condCallback();
  }

  /**
   * Check if course is open.
   *
   * @return bool
   *   Course open state.
   */
  public function isOpen() {
    return $this->isVuOnline() || $this->courseIntake->isOpen();
  }

  /**
   * Check if course is offered via VicUni Online.
   *
   * @return bool
   *   Course VUOnline state.
   */
  public function isVuOnline() {
    $items = field_get_items('node', $this->course, 'field_locations');
    if (is_array($items)) {
      foreach ($items as $item) {
        if (strtolower($item['value']) == strtolower(VUC_CBS_LOC_VU_ONLINE)) {
          return TRUE;
        }
      }
    }

    return FALSE;
  }

  /**
   * Check if course is TAFE.
   *
   * @return bool
   *   Course TAFE state.
   */
  public function isTafeOnly() {
    $items = field_get_items('node', $this->course, 'field_unit_lev');
    if (is_array($items)) {
      foreach ($items as $item) {
        if ($item['value'] == 'tafe') {
          return TRUE;
        }
      }
    }

    return FALSE;
  }

  /**
   * Check if course is offered via VicUni Online.
   *
   * @return bool
   *   Course Undergrad state.
   */
  public function isUndergrad() {
    // Ensure the course has a populate `field_unit_lev` field.
    $unit_level = field_get_items('node', $this->course, 'field_unit_lev');
    if (!isset($unit_level[0]['value'])) {
      return FALSE;
    }

    if ($unit_level[0]['value'] == 'undergrad') {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Check if course is offered for multiple audience.
   *
   * @return bool
   *   Course multiple audience state.
   */
  public function isMultipleAud() {
    // Ensure the course has a populate `field_multiple_audience_group` field.
    $multiple_aud = field_get_items('node', $this->course, 'field_multiple_audience_group');

    if ($multiple_aud) {
      $val = [];
      foreach ($multiple_aud as $item) {
        $val[] = $item['value'];
      }

      $target = [
        'Domestic',
        'International On-Shore',
      ];

      if (count(array_intersect($val, $target)) == 0) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Block view theme function variables.
   *
   * @return array
   *   The template variables for this block.
   */
  public function variables() {
    return [];
  }

  /**
   * Block view callback.
   *
   * @return array|bool
   *   The rendered result.
   *
   * @throws \Exception
   */
  public function view() {
    // Ensure a theme is defined for the output of this block.
    if (!$this->theme) {
      return FALSE;
    }

    return [
      'subject' => NULL,
      'content' => theme($this->theme, $this->variables()),
    ];
  }

  /**
   * Return VE cohorts for TAFE Courses Only.
   *
   * @return array
   *   The array.
   */
  public function veCohorts() {
    // Ensure the course has a populate `field_multiple_audience_group` field.
    $cohortarray = [];

    $ve_cohorts = field_get_items('node', $this->course, 'field_ve_cohorts');
    if ($ve_cohorts) {
      foreach ($ve_cohorts as $item) {
        $cohortarray[] = json_decode(json_encode((array) simplexml_load_string('<data>' . $item['value'] . '</data>')), 1);
      }
    }

    return $cohortarray;
  }

  /**
   * Return domestic duration for TAFE Courses Only.
   *
   * @return array|string
   *   The array or string.
   */
  public function veDuration() {
    $duration = '';
    $cohortarray = $this->veCohorts();
    $course_status = vu_courses_is_international_course_url();
    foreach ($cohortarray as $item) {
      if (!$course_status && $item['title'] == 'Domestic') {
        if (!empty($item['courseduration'])) {
          $duration = $item['courseduration'];
          break;
        }
      }
      if ($course_status && $item['title'] == 'International On-Shore') {
        if (!empty($item['courseduration'])) {
          $duration = $item['courseduration'];
          break;
        }
      }
    }

    return $duration;
  }

  /**
   * Return studymode for TAFE Courses Only.
   *
   * @return array|string
   *   The array or string.
   */
  public function veStudyMode() {
    $studymode = [];
    $cohortarray = $this->veCohorts();
    $course_status = vu_courses_is_international_course_url();
    foreach ($cohortarray as $item) {
      if (!$course_status && $item['title'] == 'Domestic') {
        if (!empty($item['studymodes'])) {
          $studymode = $item['studymodes']['studymode'];
          $studymode = is_array($studymode) ? (array_map('strtolower', $studymode)) : [strtolower($studymode)];
          break;
        }
      }
      if ($course_status && $item['title'] == 'International On-Shore') {
        if (!empty($item['studymodes'])) {
          $studymode = $item['studymodes']['studymode'];
          $studymode = is_array($studymode) ? (array_map('strtolower', $studymode)) : [strtolower($studymode)];
          break;
        }
      }
    }

    return $studymode;
  }

  /**
   * Return deliverymode for TAFE Courses Only.
   *
   * @return array|string
   *   The array or string.
   */
  public function veDeliveryMode() {
    $deliverymode = [];
    $cohortarray = $this->veCohorts();
    $course_status = vu_courses_is_international_course_url();
    foreach ($cohortarray as $item) {
      if (!$course_status && $item['title'] == 'Domestic') {
        if (!empty($item['deliverymodes'])) {
          $deliverymode = $item['deliverymodes']['deliverymode'];
          $deliverymode = is_array($deliverymode) ? (implode(', ', $deliverymode)) : $deliverymode;
          break;
        }
      }
    }

    return $deliverymode;
  }

  /**
   * Return custom course start date.
   *
   * @return array
   *   The array.
   */
  public function customCourseStartDate() {
    $dates = [];
    $custom_dates = field_get_items('node', $this->course, 'field_course_start_date');

    if (!empty($custom_dates)) {
      foreach ($custom_dates as $date) {
        $current_date = new DateTime();
        $course_date = new DateTime($date['value']);
        if ($course_date > $current_date) {
          $dates[] = $date['value'];
        }
      }

      // Sort dates.
      usort($dates, "vu_core_sort_date");

    }

    return $dates;
  }

  /**
   * Return custom course start next date.
   *
   * @return string
   *   The date.
   */
  public function customCourseStartDateNext() {
    $date = '';
    $dates = $this->customCourseStartDate();

    if (empty($dates)) {
      return $date;
    }

    $date = reset($dates);
    if (!empty($date)) {
      $date = new DateTime($date);
      $date = $date->format('j F Y');
    }

    return $date;
  }

}
