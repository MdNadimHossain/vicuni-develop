<?php

/**
 * @file
 * Various functionality related to displaying courses.
 */

/**
 * Strips all tags except P, LI, UL & OL.
 */
function _better_strip_tags($str, $allowed = 'p,li,ul,ol') {
  if (!is_array($allowed)) {
    $allowed = explode(',', $allowed);
  }
  $pattern = count($allowed) ? '^</?(' . implode(array_filter($allowed), '|') . ')' : '^$';
  $callback = create_function('$match', 'return preg_match("@' . $pattern . '@", $match[0]) ? $match[0] : " ";');
  $str = preg_replace_callback('|<[^>]+>|', $callback, $str);
  $str = preg_replace('|\s([,\.!\?;:%\]\)])|', '$1', $str);
  return $str;
}

/**
 * Replacement clean method.
 */
function vu_courses_clean_special($text) {
  $text = trim($text);
  // Remove double spaces.
  $text = preg_replace('|\s+|', ' ', $text);
  // Position double br's.
  $text = preg_replace('|\s*<br[^>]*>\s*<br[^>]*>\s*|', "\n", $text);
  $text = preg_replace('|\s*<ul>(.+?)</ul>\s*|', "\n<ul>$1</ul>\n", $text);
  $lines = explode("\n", $text);
  $text = '';
  foreach ($lines as $line) {
    $line = trim($line);
    if (preg_match('|^<[uo]l>.*</[uo]l>$|', $line) || preg_match('|^<p>|', $line)) {
      $text .= $line . "\n";
    }
    elseif ($line) {
      $text .= "<p>$line</p>\n\n";
    }
  }

  $text = preg_replace('|<p>([A-Z ]+)<br\s*/?>|', "<h3>$1</h3>\n\n<p>", $text);
  // Make headings out of capitals.
  $text = preg_replace('|<p>([A-Z ]+)</p>|', "<h3>$1</h3>\n\n", $text);
  // Make headings out of capitals.
  $text = preg_replace('|<p><b>([^<]+)</b>|', "\n\n<h3>$1</h3>\n\n<p>", $text);
  // Make headings out of bold text.
  $text = preg_replace('|<br[^>]*>|', '<br />', $text);
  // Remove empty.
  $text = preg_replace('|<p>\s*</p>|', '', $text);
  $text = preg_replace('|<p>\s*|', '<p>', $text);
  $text = preg_replace('|<b>(.+?)</b>|', "<strong>$1</strong>", $text);
  // Convert b to strong.
  $text = preg_replace('|<i>(.+?)</i>|', "<em>$1</em>", $text);
  // Convert i to em.
  $text = _better_strip_tags($text,
    ['p', 'ul', 'ol', 'li', 'strong', 'em', 'h3']);

  // Sentance case all headings.
  $text = preg_replace_callback('/<h3>([A-Z\s]+)<\/h3>/', create_function('$matches', 'return "<h3>".ucfirst(strtolower($matches[1]))."</h3>";'), $text);

  return trim($text);
}

/**
 * Converts all caps course and unit titles to a human readable string.
 *
 * This function:
 *  - title cases words (except joining words),
 *  - replaces ampersands,
 *  - fix string spacing and
 *  - fix spacing around forward slashes.
 *
 * @param string $name
 *   The text to transform.
 *
 * @return string
 *   Transformed text.
 */
function _humanize_title($name = '') {
  $name = trim($name);

  // Space around '/'.
  $name = preg_replace('/(.)\/(.)/', "$1 / $2", $name);

  // Collapse space.
  $name = trim(preg_replace('/\s+/', ' ', $name));

  // Short circuit: only process ALL CAPS strings after here.
  if ($name !== strtoupper($name)) {
    return $name;
  }

  // Lowercase.
  $name = strtolower($name);

  // Uppercase trailing A.
  $name = preg_replace('/\ba$/', 'A', $name);

  // Convert to title case.
  $name = preg_replace_callback("/\b[^\W]+/", function ($word) {
    if (is_array($word)) {
      $word = $word[0];
    }
    $stopwords = implode('|', [
      'a(nd?|s|t)?',
      'b(ut|y)',
      'en',
      'for',
      'i[fn]',
      'o[fnr]',
      't(he|o)',
      'vs?\.?',
      'via',
      's',
    ]);
    $caps_whitelist = strtolower(implode('|', [
      '2D',
      '3D',
      '4WD',
      'ATPL',
      'AESOL',
      'BAS',
      'BMS',
      'BBUS',
      'CCNA',
      'CD',
      'CESARE',
      'CPL',
      'CPR',
      'CS[\d]',
      'CSM',
      'DBA',
      'DSLR',
      'DSP',
      'DVD',
      'ECE',
      'EDA',
      'ERP',
      'EAL',
      'ESL',
      'GIS',
      'GST',
      'HDL',
      'HRM',
      'HVAC',
      'HWS',
      'I',
      'IC',
      'IELTS',
      'II',
      'III',
      'IR',
      'IREX',
      'IT',
      'ITIL',
      'IV',
      'JIT',
      'LAN',
      'MCITP',
      'MCSA',
      'MCTA',
      'MCTS',
      'MIDI',
      'MYOB',
      'OET',
      'OHS',
      'PVC',
      'REC',
      'RF',
      'RFID',
      'ROM',
      'SOSE',
      'SQL',
      'TESOL',
      'V',
      'VCE',
      'VET',
      'VGS',
      'VHDL',
      'VI',
      'VII',
      'VLSI',
      'XML',
    ]));
    $mixed_case_exceptions = [
      'PhD',
      'InDesign',
      'iPhone',
      'iPad',
      'iOS',
      'ZBrush',
    ];
    $mixed_case_exceptions = array_combine(
      array_map('strtolower', $mixed_case_exceptions),
      $mixed_case_exceptions);
    $mixed_case_pattern = implode('|', array_keys($mixed_case_exceptions));
    if (preg_match("/^({$stopwords})$/", $word)) {
      return $word;
    }
    elseif (preg_match("/^({$caps_whitelist})$/", $word)) {
      return strtoupper($word);
    }
    elseif (preg_match("/^({$mixed_case_pattern})$/", $word, $matches)) {
      return $mixed_case_exceptions[$matches[0]];
    }
    else {
      return ucfirst($word);
    }
  }, $name);

  // Hack for non-word boundary char.
  $name = str_replace('Oh&s', 'OH&S', $name);

  // Hack for non-word boundary char.
  $name = str_replace('D.c.', 'D.C.', $name);

  // And the final hack:
  // we want to uppercase the first letter UNLESS it is iThing.
  $name = preg_replace_callback('/^([^i])/', function ($match) {
    return strtoupper($match[1]);
  }, $name);

  return $name;
}

/**
 * Generate URL for admission centre from a course code.
 */
function vu_courses_apply_url($code = '', $tafe = FALSE) {
  if ($tafe && vu_feature_switches_switch_state('tafe-online-applications')) {
    $url = 'https://gotovu.custhelp.com/app/tafe/launch_application';
  }
  else {
    $url = 'https://gotovu.custhelp.com/app/launch_application';
  }

  // A code with a dash means ${course_code}-${specialisation_code}
  // and we only want ${course_code} so throw everything after the
  // dash away.
  // @FIXME: remove this, it was only used for BBUS which no lnger exists.
  $exploded = explode('-', $code);
  $code = array_shift($exploded);

  return !empty($code) ? "${url}?c_code=${code}" : $url;
}

/**
 * Checks if a course is a new entry for a given year.
 *
 * Defaults to the following year.
 * Returns the four-digit year that the course is starting, or FALSE.
 */
function vu_courses_is_new_course($firstoffered = '', $year = '') {
  if (!$firstoffered) {
    return FALSE;
  }

  if (!$year) {
    $year = date('Y');
  }

  $firstoffered_year = date('Y', strtotime($firstoffered));

  if ($firstoffered_year >= $year) {
    return $firstoffered_year;
  }

  return FALSE;
}

/**
 * Used to markup the structure element of the course XML.
 *
 * @param string $structure
 *   String containing either structure XML to be transformed
 *    or something else to be treated as pre-transformed.
 *
 * @return string
 *   HTML markup of course structure.
 */
function vu_courses_transform_structure($structure) {
  if (preg_match('/<(line|section)>/', $structure)) {
    $structure = simplexml_load_string($structure);
    $result = '';
    foreach ($structure->section as $section) {
      if (!empty($section->sectiontitle)) {
        foreach ($section->line as $content) {
          if ($content->continuingstudent == 'Y' || $content->suspended == 'Y') {
            unset($content->unitcode['0']);
            unset($content->unittitle['0']);
          }
        }
        $result .= '<h3 class="section-title">' . $section->sectiontitle . '</h3>';
      }

      if (!empty($section->sectionheader)) {
        $result .= '<p class="section-header">' . strip_tags($section->sectionheader) . '</p>';
      }

      $result .= vu_courses_transform_section($section);

      if (!empty($section->sectionfooter)) {
        $result .= '<p class="section-footer">' . $section->sectionfooter . '</p>';
      }

      if (!empty($section->sectionfootnote)) {
        $result .= '<p class="section-footnote">' . $section->sectionfootnote . '</p>';
      }
    }
  }
  else {
    $result = $structure;
  }
  // Return empty string if it's just dashes and whitespace.
  return (preg_match('/^[\-\s]+$/uis', strip_tags($result)) ? '' : $result);
}

/**
 * Used to markup a individual section element of the course XML.
 *
 * Do not call this function directly,
 * instead call vu_courses_transform_structure().
 *
 * @param SimpleXMLElement $section
 *   Structure node of course XML.
 *
 * @return string
 *   HTML markup of unit structure.
 */
function vu_courses_transform_section(SimpleXMLElement $section) {
  $result = '';
  $ul = FALSE;

  foreach ($section->line as $line) {
    $text = '';
    if (strlen($line->linetext) > 0) {
      $text = vu_courses_clean_special($line->linetext);
      if (!empty($text)) {
        if ($ul) {
          $result .= '</ul>';
          $ul = FALSE;
        }

        $result .= '<div class="unit-linetext">' . $text . '</div>';
      }
    }
    elseif (strlen($line->unittitle) > 0 && strlen(trim($line->unitcode)) > 0) {

      $code = trim($line->unitcode);
      $is_tafe = FALSE;
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'unit')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_unit_code', 'value', $code)
        ->fieldCondition('field_unit_lev', 'value', 'tafe');

      $unit_result = $query->execute();
      if (isset($unit_result['node'])) {
        $is_tafe = TRUE;
      }

      $text = _humanize_title($line->unittitle);
      if (!empty($text)) {
        if (!$ul) {
          $result .= '<ul>';
          $ul = TRUE;
        }
        // Is it a unit or a unitset?
        $href = sprintf("/%s/%s", ($line->isUnitSet == 'Y') ? 'unitsets' : 'units', trim($line->unitcode));

        $result .= "<li class=\"unit-title\">";
        if ($is_tafe) {
          $result .= "  <div>
            <a href=\"{$href}\"><span class=\"unit-code\">" . trim($line->unitcode) . "</span> - {$text}</a></div>";
          $result .= "  <dl>";
        }
        else {
          $result .= "  <div><a href=\"{$href}\">{$text}</a></div>";
          $result .= "  <dl>";
          $result .= "    <dt class=\"dt-code\">Unit code</dt> <dd class=\"dd-code\">" . trim($line->unitcode) . "</dd>";
        }

        if ($line->creditpoints && $line->creditpoints > 0) {
          $result .= "    <dt class=\"dt-credits\">Credits</dt><dd class=\"dd-credits\">$line->creditpoints</dd>";
        }
        $result .= "  </dl>";
        $result .= "</li>";
      }
    }
  }

  if ($ul) {
    $result .= '</ul>';
  }
  return $result;
}

/**
 * Returns the CAMS duration text qualified by study mode.
 *
 * For example:
 *  - '1 year full time',
 *  - '1 year part time',
 *  - '1 year full time or longer for part time'.
 */
function vu_courses_duration_text($node, $modes = NULL) {
  $course = new VuCoreCourseBlockBase($node);
  $ve_duration = $course->veDuration();
  $tafe = $course->isTafeOnly();
  if ($tafe) {
    if ($ve_duration == "") {
      return NULL;
    }
    $duration = $ve_duration;
    $modes = $course->veStudyMode();
  }
  else {
    if (!isset($node->field_duration[$node->language][0]['safe_value'])) {
      return NULL;
    }
    $duration = $node->field_duration[$node->language][0]['safe_value'];
  }

  if (is_null($modes) && isset($node->field_study_mode[$node->language])) {
    $modes = array_reduce($node->field_study_mode[$node->language], function ($acc, $mode) {
      $mode_name = strtolower($mode['value']);
      $acc[$mode_name] = $mode_name;
      return $acc;
    }, []);
  }

  if (!vu_courses_is_international_course_url() && is_array($modes)) {
    if (in_array('full time', $modes)) {
      $duration .= ' full time';
      if (in_array('part time', $modes)) {
        $duration .= ' or longer for part time';
      }
    }
    elseif (in_array('part time', $modes)) {
      $duration .= ' part time';
    }
  }

  return $duration;
}

/**
 * Return an icon name for a specific 'course essentials' item.
 */
function vu_courses_course_essentials_icon($label, $default = 'table') {
  $icons = [
    'CRICOS' => 'certificate',
    'Course dates' => 'calendar',
    'Course times' => 'clock-o lg',
    'Delivery mode' => 'desktop',
    'Duration' => 'clock-o lg',
    'Fee type' => 'money',
    'Fees' => 'money',
    'Intake' => 'level-up rotate-90',
    'Location' => 'map-marker',
    'Offered by' => 'university',
    'Other locations' => 'map-marker',
    'Study mode' => 'compass',
    'VU course code' => 'tag',
  ];
  if (isset($icons[$label])) {
    return $icons[$label];
  }
  return $default;
}

/**
 * Find the first H2 in HTML and return its text.
 */
function _vu_courses_extract_first_h2(&$html) {
  preg_match('|<h2.*?>(.*?)</h2.*?>|m', $html, $matches);
  $html = preg_replace('|<h2.*?>(.*?)</h2.*?>|', '', $html, 1);
  return !empty($matches[1]) ? $matches[1] : '';
}

/**
 * Test the URL to determine if we're on an international course page.
 */
function vu_courses_is_international_course_url() {
  $international = &drupal_static(__FUNCTION__);
  if (!isset($international)) {
    $international = FALSE;
    if (arg(0) === 'courses' && arg(1) === 'international') {
      $international = TRUE;
    }
  }

  return $international;
}

/**
 * Check whether a course is offered to international or domestic audience.
 *
 * @param object $node
 *   Drupal course node.
 * @param string $audience
 *   Should be 'international' or 'domestic'.
 *
 * @return bool
 *   Whether the course is offered to this audience.
 */
function vu_courses_offered_to_audience($node, $audience) {
  $field_name = "field_${audience}";
  $field = $node->$field_name;
  if ($audience === 'domestic') {
    return $field[$node->language][0]['value'] != FALSE;
  }
  elseif ($audience === 'international') {
    return $field[$node->language][0]['value'] == TRUE;
  }
}

/**
 * Return a part of the course title.
 *
 * @param string $value
 *   Input course title.
 * @param bool $strip_level
 *   If true, remove the course level.
 * @param bool $level_only
 *   If true, only return the level.
 * @param bool $reorder
 *   If true, change title to match [name] [level] e.g. arts, bachelor of.
 *
 * @return string
 *   The altered title.
 */
function clean_title($value = '', $strip_level = FALSE, $level_only = FALSE, $reorder = TRUE) {
  if (!$strip_level && $level_only) {
    return trim(preg_replace(vumain_courses_title_patterns(), "$2", $value, 1));
  }
  return $strip_level ? trim(preg_replace(vumain_courses_title_patterns(), "$3", $value, 1)) : trim(preg_replace(vumain_courses_title_patterns(), $reorder ? '$3 $2' : '$2 $3', $value, 1));
}
