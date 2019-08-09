<?php
/**
 * @file
 * CourseEssentailsPresenter.
 */

/**
 * Presenter class to apply display logic to course index data.
 */
class CourseEssentialsPresenter {
  private $commonRows;
  private $intakeRows;
  private $valueMap = [
    'location' => ['self', 'locationMap'],
    'attendance_type' => [
      'PT' => 'Part Time',
      'FT' => 'Full Time',
    ],
    'specialisation_name' => '_humanize_title',
    'vtac_course_code' => ['self', 'vtacCodeMap'],
  ];
  private $labels = [
    'vtac_course_code' => 'VTAC course code',
    'place_type' => 'Fee type',
    'attendance_type' => 'Study mode',
    'specialisation_name' => 'Specialisation',
  ];
  private $rejectKeys = [
    'is_vtac_course',
    'application_entry_method',
    'place_type'
  ];

  /**
   * Constructor.
   *
   * @param array $info
   *        Course index data sorted into 'common' and 'rows'.
   */
  public function __construct($info) {
    if (is_array($info['value_map'])) {
      $this->valueMap = array_merge_recursive($this->valueMap, $info['value_map']);
    }
    $this->commonRows = $this->preprocessRow(array_filter($info['common']));
    $this->intakeRows = array_map(array($this, 'preprocessRow'), $info['rows']);
  }

  /**
   * Getter.
   */
  public function commonRows() {
    return $this->commonRows;
  }

  /**
   * Getter.
   */
  public function intakeRows() {
    return $this->intakeRows;
  }

  /**
   * Are there any rows?
   *
   * @return bool
   *         Are there any rows?
   */
  public function hasRows() {
    return !empty($this->commonRows) || !empty($this->intakeRows);
  }

  /**
   * Return the correctly-cased title for the given campus code.
   *
   * @param string $location_code
   *        The VU location code as used in VU Connect.
   *
   * @return bool|string
   *         The title or FALSE if none exists.
   */
  public static function locationLabel($location_code) {
    $vu_location_codes = variable_get('vu_location_codes', array());
    if (!isset($vu_location_codes[$location_code])) {
      return FALSE;
    }

    return _humanize_title($vu_location_codes[$location_code]);
  }

  /**
   * Return the url path for the given campus code.
   *
   * Static because we don't want to keep querying the database, this function
   * could be called many times in a page load.
   *
   * @param string $location_code
   *        The VU location code as used in VU Connect.
   *
   * @return bool|string
   *         The URL or FALSE if none exists.
   */
  public static function locationPath($location_code) {
    static $campus_list;
    if (empty($campus_list)) {
      // Vu campuses list returns an array of:
      // 'title' => ('nid' => {nid}, 'title' => {title}, 'url' => {url}).
      $campus_list = vu_campuses_list();
    }

    $vu_location_codes = variable_get('vu_location_codes', array());
    if (!isset($vu_location_codes[$location_code])) {
      return FALSE;
    }
    $campus_name = $vu_location_codes[$location_code];

    // Check to see that there's an entry for $campus_name.
    $location = array_filter($campus_list, function ($v) use ($campus_name) {
      return $campus_name === strtoupper($v['title']);
    });

    return count($location) ? reset($location)['url'] : FALSE;
  }

  /**
   * Prepare a label for output, or return one prepared elsewhere.
   *
   * @param string $str
   *        The raw string to convert to a label.
   *
   * @return string
   *         The label prepared for output.
   */
  private function label($str) {
    return (isset($this->labels[$str])) ? $this->labels[$str] : ucfirst(str_replace('_', ' ', $str));
  }

  /**
   * Prepare a value for output, or return one prepared elsewhere.
   *
   * @param mixed $raw
   *        The raw value to prepare for output.
   * @param string $key
   *        The raw key for this value.
   *
   * @return string
   *         The value prepared for output.
   */
  private function value($raw, $key) {
    if (is_array($raw)) {
      return implode(', ', array_map(function ($_raw) use ($key) {
        return $this->value($_raw, $key);
      }, $raw));
    }
    $value_map = $this->valueMap[$key];
    if (is_callable($value_map)) {
      return call_user_func($value_map, $raw);
    }
    elseif (is_array($value_map) && isset($value_map[$raw])) {
      return $value_map[$raw];
    }
    return $raw;
  }

  /**
   * Identify keys to be ommitted from output.
   *
   * @param string $key
   *        The key to test.
   *
   * @return bool
   *         True to reject, False to include in output.
   */
  private function reject($key) {
    return in_array($key, $this->rejectKeys);
  }

  /**
   * Remove rejected keys, and normalise keys and values.
   *
   * @param array $row
   *        The row to process.
   *
   * @return array
   *         The processed row.
   */
  private function preprocessRow($row) {
    $out = array();
    foreach ($row as $key => $value) {
      if ($this->reject($key)) {
        continue;
      }
      $out[$this->label($key)] = $this->value($value, $key);
    }
    return $out;
  }

  /**
   * Replace empty VTAC code with default text.
   *
   * Return the code if one is passed.
   *
   * @param string $code
   *        VTAC code.
   *
   * @return string
   *         VTAC code as supplied, or default text.
   */
  private static function vtacCodeMap($code) {
    return empty($code) ? '' : $code;
  }

  /**
   * Map course index location codes to links with human-readable campus names.
   *
   * Given a course index location code, returns a link to the campus page in
   * the website if one exists.
   *
   * @param string $location_code
   *        Course index location code.
   *
   * @return string
   *         Link to campus page with human readable campus name
   *         or $raw if no matching location exists for the input.
   */
  public static function locationMap($location_code) {
    $url = CourseEssentialsPresenter::locationPath($location_code);
    $label = CourseEssentialsPresenter::locationLabel($location_code);
    return $url ? "<a href='${url}'>${label}</a>" : $label;
  }

  /**
   * Return a single course essentials item.
   */
  public function singleValue($value, $key) {
    return '<span class="course-essentials__item__label ' . $key . '">' . $this->label($key) . ':</span> <span class="course-essentials__item__value ' . $key . '">' . $this->value($value, $key) . '</span>';
  }

}
