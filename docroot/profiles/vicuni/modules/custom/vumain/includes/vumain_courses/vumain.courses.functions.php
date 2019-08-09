<?php

/**
 * @file
 * vumain.courses.functions.php
 */

/**
 * Pseudo implements hook_theme().
 */
function vumain_courses_theme() {
  $template_path = drupal_get_path('module', 'vumain') . '/includes/vumain_courses/templates';
  $file = 'vumain_courses.theme.inc';

  return array(
    'vumain_courses_list' => array(
      'path' => $template_path,
      'template' => 'course-list',
      'variables' => array(),
      'preprocess functions' => array(
        'template_preprocess',
        'vumain_courses_list_preprocess',
      ),
    ),
    'vumain_courses_course_finder_box' => array(
      'path' => $template_path,
      'template' => 'homepage-course-finder-box',
      'variables' => array(),
      'preprocess functions' => array(
        'template_preprocess',
        'vumain_courses_course_finder_box_preprocess',
      ),
    ),
  );
}

/**
 * Preprocess vars for a course list.
 */
function vumain_courses_list_preprocess(&$variables) {
  $courses = node_load_multiple(array(), array(
    'type' => VUMAIN_CONTENT_TYPE_COURSES,
    'status' => NODE_PUBLISHED,
  ));

  $variables['lists'] = array(
    'residents' => array(),
    'non-residents' => array(),
  );
  $letters = array();
  $selected_letter = 'A';

  usort($courses, 'vumain_courses_sort_special');

  foreach ($courses as $course) {
    try {
      $course_wrapper = entity_metadata_wrapper('node', $course);
    }
    catch (Exception $e) {
      vu_helpers_watchdog_log($e);
    }

    $trimmed = trim(preg_replace(vumain_courses_title_patterns(), "$4 $3 $2", $course_wrapper->title->value(), 1));
    $first = strtoupper($trimmed[0]);
    if (!in_array($first, $letters, TRUE)) {
      $selected_letter = $first;
      $variables['list'][$selected_letter] = array();
      $letters[] = $first;
    }

    $next_year = date('Y') + 1;
    $course->firstoffered_year = vumain_courses_is_new_course($course_wrapper->field_first_off_date->value(), $next_year);
    $course->highlighted_title = vumain_courses_title_highlight(htmlspecialchars($course_wrapper->title->value()), $course_wrapper->field_unit_lev->value());
    $course->url = 'courses/' . $course_wrapper->field_unit_code->value();

    // Copy the object without its reference.
    $variables['lists']['residents'][$selected_letter][] = clone($course);

    if ($course_wrapper->field_international->value()) {
      $course->url = 'courses/international/' . $course_wrapper->field_unit_code->value();
      $variables['lists']['non-residents'][$selected_letter][] = clone($course);
    }
  }
}

/**
 * Sorts courses by title excluding the qualification.
 *
 * @param object $a
 *   Courses node object.
 * @param object $b
 *   Courses node object.
 *
 * @return bool
 *   String comparison result.
 */
function vumain_courses_sort_special($a, $b) {
  $a = $a->title;
  $b = $b->title;
  if ($a == $b) {
    return 0;
  }
  $a = _vumain_courses_title_order($a);
  $b = _vumain_courses_title_order($b);
  return strcasecmp($a, $b);
}

/**
 * Course title for sorting.
 */
function _vumain_courses_title_order($title = '') {
  $title = strtolower(trim($title));
  $title = preg_replace(vumain_courses_title_patterns(), "$4 $3 $2", $title, 1);
  $title = preg_replace('/[^a-zA-Z0-9\s]/', '', $title, -1);
  $title = preg_replace('/\s+/', ' ', $title, -1);
  return trim($title);
}

/**
 * Course title qualification prefixes.
 */
function vumain_courses_title_patterns($pattern = '') {
  if (!empty($pattern)) {
    return '/' . $pattern . '/i';
  }
  else {
    return array(
      '/^([\S]+ - )?(bachelor\sof\s)(.+)$/i',
      '/^([\S]+ - )?((?:advanced\s)?diploma\s(?:in|of)?\s?)(.+)$/i',
      '/^([\S]+ - )?(associate\sdegree\sin\s)(.+)$/i',
      '/^([\S]+ - )?(certificate\s(?:i|ii|iii|iv)\sin\s)(.+)$/i',
      '/^([\S]+ - )?(course\sin\s)(.+)$/i',
      '/^([\S]+ - )?(doctorate\sof\s)(.+)$/i',
      '/^([\S]+ - )?(graduate\s(?:certificate|diploma)\sin\s)(.+)$/i',
      '/^([\S]+ - )?(introduction\sto\s)(.+)$/i',
      '/^([\S]+ - )?(master\sof\s)(.+)$/i',
      '/^([\S]+ - )?(masters\sdegrees\sby\sresearch\smaster\sof\s)(.+)$/i',
      '/^([\S]+ - )?(victorian\scertificate\sof\s)(.+)$/i',
      '/^([\S]+ - )?(doctor\sof\s)(.+)$/i',
      '/^([\S]+ - )?(.+)$/i',
    );
  }
}

/**
 * Checks if a course is a new entry for a given year.
 *
 * Defaults to the following year.
 * Returns the four-digit year that the course is starting, or FALSE.
 */
function vumain_courses_is_new_course($firstoffered = '', $year = '') {
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
 * Course title with the part after the qualification prefix highlighted.
 */
function vumain_courses_title_highlight($value, $level = '') {
  $tag = 'strong';
  $tag1 = "<$tag>";
  $tag2 = "</$tag>";
  $replacement = $level == 'Short course' ? "$1$tag1$2$3$tag2" : "$1$2$tag1$3$tag2";
  $value = preg_replace(vumain_courses_title_patterns(), $replacement, $value, 1, $count);

  if (!$count) {
    $value = "$tag1$value$tag2";
  }
  return $value;
}

/**
 * Course finder form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The state of the form.
 * @param string $type
 *   The type of the form to output. The following are valid options:
 *   - find_minimal: 'Find' block with minimal options.
 *   - find_std: 'Find' block with standard options.
 *   - find_std_search: 'find_std' with 'Search' title.
 *   - find_extended: 'Find' block with extended options.
 *   - find_std_desc: 'find_std' with description.
 *   - search_minimal: 'Search' block with minimal options.
 *   - search_std_desc: 'search_standard' with description.
 *
 * @see _vumain_courses_search_get_form_type()
 *
 * @return array $form
 *   The renderable form.
 *
 * @deprecated @PW-236
 */
function vumain_courses_course_finder_form($form, &$form_state, $type = 'find_std') {
  // Get a list of valid types.
  $types = _vumain_courses_search_get_form_type();

  // If this type is not valid.
  if (!array_key_exists($type, $types)) {
    // Prevent any further processing.
    return;
  }

  // Set up the 'I am' portion of the form.
  $form['iam'] = array();

  // Set the default value/s.
  $placeholder = '';
  $prefix = '';
  $suffix = '';
  $submit_type = '';
  $resident_status = 'resident';
  $button_title = t('Search for courses');
  $params = drupal_get_query_parameters();
  $midyear_flag = '';
  if (vu_midyear_intake_is_enabled()) {
    $midyear_flag = '<p class="midyear"><a href="/courses/search?type=Midyear">' . t('Find courses open for <strong>mid-year entry</strong>') . '</a></p>';
  }

  switch ($type) {
    case 'find_minimal':
    case 'find_std':
    case 'find_extended':
    case 'find_std_desc':
      $prefix = '<h3><i class="fa fa-search"></i>' . t('Find a course') . '</h3>';
      $submit_type = 'button';
      break;

    case 'find_std_search':
      $prefix = '<h3>' . t('Search for courses') . '</h3>';
      $submit_type = 'button';
      break;

    case 'search_std_desc':
      $prefix = '<section class="search-std-desc"><h3>' . t("Can't find your course?") . '</h3><h4>' . t("Search for courses for Australian residents") . '</h4>';
      break;
  }
  // If the type is 'find_std'.
  if ($type == 'find_std') {
    // Update the suffix.
    $suffix = $midyear_flag;
  }

  // If the type is 'find_std_desc'.
  if ($type == 'find_std_desc') {
    // Update the suffix.
    $args = array(
      '!campuses' => l(t('campuses'), 'campuses-services/our-campuses'),
      '!vu_sydney' => l(t('VU Sydney'), 'vu-sydney'),
    );
    $suffix = $midyear_flag . t("Our courses are delivered across !campuses in Melbourne's CBD and inner west, and at !vu_sydney.", $args);
  }

  // Build up an array of options.
  $options = array(
    VU_COURSE_SEARCH_RESIDENT => t('Australian residents'),
    VU_COURSE_SEARCH_NON_RESIDENT => t('Non-residents'),
  );
  // If the type is 'find_extended'.
  if ($type == 'find_extended') {
    // Update the options.
    $options[VU_COURSE_SEARCH_RESIDENT] = t('an Australian resident');
    $options[VU_COURSE_SEARCH_NON_RESIDENT] = t('a non-resident');
    // Add the title.
    $form['iam']['#title'] = t('I am ...');
  }

  // If the type is not 'search_minimal'.
  if ($type != 'search_minimal') {
    // Update the placeholder value.
    $placeholder = t('Course name or type');
  }

  // If the type is not 'find_minimal', 'search_minimal' or 'search_std_desc'.
  if ($type != 'find_minimal' && $type != 'search_minimal' && $type != 'search_std_desc') {
    // Update the 'I am' portion of the form.
    $form['iam']['#type'] = 'radios';
    $form['iam']['#default_value'] = VU_COURSE_SEARCH_RESIDENT;
    $form['iam']['#options'] = $options;
  }
  else {
    if (!empty($params['iam'])) {
      $resident_status = $params['iam'];
    }
    if (drupal_get_path_alias() == VUMAIN_URLS_INTERNATIONAL_STUDENTS) {
      $resident_status = 'non-resident';
    }
    $form['iam']['#type'] = 'hidden';
    $form['iam']['#default_value'] = $resident_status;
  }

  $form['query'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'class' => array(
        'query',
        'form-text',
      ),
      'maxlength' => 60,
    ),
  );

  if (!empty($params['query'])) {
    $form['query']['#default_value'] = check_plain($params['query']);
  }
  if (!empty($params['type']) && $params['type'] == 'Unit') {
    // Set search type as Unit.
    $form['type']['#type'] = 'hidden';
    $form['type']['#default_value'] = 'Unit';
  }
  elseif (!empty($params['type']) && $params['type'] == 'Midyear') {
    // Set search type as Midyear.
    $form['type']['#type'] = 'hidden';
    $form['type']['#default_value'] = 'Midyear';
  }
  else {
    // Set default search type as Course.
    $form['type']['#type'] = 'hidden';
    $form['type']['#default_value'] = 'Course';
  }

  //  If it's vicpoly search.
  if (!empty($_GET['vuit']) && $_GET['vuit'] == 1) {
    // Set to search vicpoly courses only.
    $form['vuit']['#type'] = 'hidden';
    $form['vuit']['#default_value'] = 1;

    $form['college']['#type'] = 'hidden';
    $form['college']['#default_value'] = 'VU Polytechnic';
  }

  // If the type is 'search_std_desc'.
  if ($type == 'search_std_desc') {
    $args = array(
      '!azlist' => l(t('A-Z list of all our courses'), 'courses/browse-for-courses/all-courses-a-to-z'),
    );
    $form['#suffix'] = t('You can also browse through an !azlist.', $args) . '</section>';
  }

  // If the placeholder should not be empty.
  if ($placeholder != '') {
    $form['query']['#attributes']['placeholder'] = $placeholder;
  }

  // If there is a prefix.
  if ($prefix != '') {
    $form['#prefix'] = $prefix;
  }

  // If there is a suffix.
  if ($suffix != '') {
    $form['#suffix'] = $suffix;
  }

  // If the submit button is 'button'.
  if ($submit_type == 'button') {
    $form['submit'] = array(
      '#type' => 'button',
      '#attributes' => array(
        'class' => array(
          'submit',
          'btn-action-lg',
        ),
      ),
      '#value' => t('Find'),
      '#icon' => '<i class="fa fa-search"></i>',
      '#icon_position' => 'after',
      '#hide_text' => TRUE,
    );
  }
  else {

    // Set button title.
    if (!empty($params['type']) && $params['type'] == 'Midyear') {
      if (vu_midyear_intake_is_enabled() && !vu_core_is_non_resident_search()) {
        $button_title = t('Search for mid-year courses');
      }
    }

    if (!empty($params['type']) && $params['type'] == 'Unit') {
      $button_title = t('Search for units');
    }
    $form['submit'] = array(
      '#type' => 'button',
      '#value' => $button_title,
    );
    // Set the dropdown toggle.
    $dropdown_toggle = array(
      '#type' => 'button',
      '#attributes' => array(
        'class' => array(
          'btn',
          'btn-primary',
          'dropdown-toggle',
        ),
        'data-toggle' => 'dropdown',
      ),
      '#value' => '<span class="caret"></span><span class="accessibility">' . t('Select search type (content changes below)') . '</span>',
    );
    // Set the dropdown options.
    $items = array(
      l(t('Search for courses'), 'courses/search', array(
        'attributes' => array(
          'data-search-type' => t('Course'),
        ),
      )),
    );
    if (vu_midyear_intake_is_enabled()) {
      if (!vu_core_is_non_resident_search()) {
        $items[] = l(t('Search for mid-year courses'), 'courses/search', array(
          'query' => array(
            'type' => t('Midyear'),
          ),
          'attributes' => array(
            'data-search-type' => t('Midyear'),
          ),
        ));
      }
    }
    $items[] = l(t('Search for units'), 'units/search', array(
      'attributes' => array(
        'data-search-type' => t('Unit'),
      ),
    ));
    $dropdown_options = theme('item_list',
      array(
        'items' => $items,
        'attributes' => array(
          'class' => 'dropdown-menu',
        ),
      )
    );
    // Update the suffix of the submit button.
    $form['submit']['#suffix'] = drupal_render($dropdown_toggle) . $dropdown_options;

    // Add javascript for dropdown options functionality.
    $js_path = drupal_get_path('module', 'vumain') . '/js/';
    drupal_add_js($js_path . 'vumain_course_search.js');
  }

  $form['#method'] = 'get';
  $form['#action'] = url('courses/search');
  $form['#attributes'] = array('class' => array('coursefinder__form'));
  $form['#pre_render'] = array('vumain_courses_form_remove_state');

  return $form;
}

/**
 * Course finder theme function.
 */
function vumain_courses_course_finder_box_preprocess(&$variables) {
  $form = module_invoke('vumain', 'block_view', 'vu_course_search_find_std');
  if (!empty($form['content'])) {
    $variables['form'] = $form['content'];
  }

  // Load course list.
  $study_topics = vumain_cources_get_all_study_topics();
  $args = implode(',', array_flip($study_topics));
  $variables['course_list'] = views_embed_view('courses_lists', 'course_browser_block', $args);
}

/**
 * Remove drupal form state information.
 */
function vumain_courses_form_remove_state($form) {
  unset($form['form_token']);
  unset($form['form_build_id']);
  unset($form['form_id']);
  return $form;
}

/**
 * Used to markup the structure element of the course XML.
 *
 * @param string $node
 *   String containing either structure XML to be transformed
 *   or something else to be treated as pre-transformed.
 *
 * @return string
 *   HTML markup of course structure.
 */
function vumain_courses_transform_structure($node) {
  if (!empty($node->field_imp_structure)) {
    $structure = $node->field_imp_structure[$node->language][0]['value'];
  }
  else {
    return '';
  }

  if (preg_match('/<(line|section)>/', $structure)) {
    $structure = simplexml_load_string($structure);
    $result = '';
    foreach ($structure->section as $section) {
      if (!empty($section->sectiontitle)) {
        $result .= '<h3 class="section-title">' . $section->sectiontitle . '</h3>';
      }

      if (!empty($section->sectionheader)) {
        $result .= '<p class="section-header">' . strip_tags($section->sectionheader) . '</p>';
      }

      $result .= vumain_courses_transform_section($section, $node);

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
 * Determine if a given unit is from a TAFE course.
 *
 * @param object $node
 *   The unit node to test for TAFE level.
 *
 * @return bool
 *   true if the course is tafe course.
 */
function vumain_courses_is_tafe_course($node) {
  $result = db_select('feeds_item', 'fi')
    ->fields('fi', array('id'))
    ->condition('entity_id', $node->nid)
    ->execute()
    ->fetchField();
  // Courses imported through either of these feed importers are
  // considered to only have units in the TAFE sector.
  return in_array($result, array('courses_vet', 'courses_na'));
}

/**
 * Used to markup a individual section element of the course XML.
 *
 * Do not call this function directly, instead call
 * vumain_courses_transform_structure().
 *
 * @param SimpleXMLElement $section
 *   Structure node of course XML.
 *
 * @return string
 *   HTML markup of unit structure.
 */
function vumain_courses_transform_section(SimpleXMLElement $section, $node = FALSE) {
  $result = '';
  $ul = FALSE;

  foreach ($section->line as $line) {
    $text = '';
    if (strlen($line->linetext) > 0) {
      $text = vumain_courses_clean_special($line->linetext);
      if (!empty($text)) {
        if ($ul) {
          $result .= '</ul>';
          $ul = FALSE;
        }

        $result .= '<div class="unit-linetext">' . $text . '</div>';
      }
    }
    elseif (strlen($line->unittitle) > 0 && strlen(trim($line->unitcode)) > 0) {
      // Determine if this unit is a from a TAFE course.
      $is_tafe = FALSE;
      if (is_object($node)) {
        $is_tafe = vumain_courses_is_tafe_course($node);
      }
      $text = _vumain_courses_humanize_title($line->unittitle);
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
 * Replacement clean method.
 *
 * @param string $text
 *   Text to clean.
 *
 * @return string
 *   Cleaned text.
 */
function vumain_courses_clean_special($text) {
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
  $text = _vumain_cources_better_strip_tags($text,
    array('p', 'ul', 'ol', 'li', 'strong', 'em', 'h3'));

  // Sentance case all headings.
  $text = preg_replace_callback('/<h3>([A-Z\s]+)<\/h3>/', create_function('$matches', 'return "<h3>".ucfirst(strtolower($matches[1]))."</h3>";'), $text);

  return trim($text);
}

/**
 * Strips all tags except P, LI, UL & OL.
 */
function _vumain_cources_better_strip_tags($str, $allowed = 'p,li,ul,ol') {
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
function _vumain_courses_humanize_title($name = '') {
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
    $stopwords = implode('|', array(
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
    ));
    $caps_whitelist = strtolower(implode('|', array(
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
    )));
    $mixed_case_exceptions = array(
      'PhD',
      'InDesign',
      'iPhone',
      'iPad',
      'iOS',
      'ZBrush',
    );
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
 * Form for courses by study topic.
 */
function vumain_courses_courses_by_study_topic_form() {
  $options[0] = t('Please select a topic ...');
  $options += vumain_cources_get_all_study_topics();

  $current_nid = arg(1);

  $form['study-topics'] = array(
    '#type' => 'select',
    '#title' => t('Show all courses for'),
    '#options' => $options,
    '#default_value' => !empty($current_nid) ? $current_nid : '',
    '#attributes' => array(
      'class' => array(
        'jump-menu',
      ),
      'id' => 'jump-menu',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Show'),
  );

  $form['#attributes']['class'][] = 'vumain-study-area-jump-menu';

  return $form;
}

/**
 * Implements hook_form_FORM_ID_validate().
 */
function vumain_courses_courses_by_study_topic_form_validate($form, &$form_state) {
  if (empty($form_state['values']['study-topics'])) {
    form_set_error('study-topics', t('Please select study topic, then click the Show button'));
  }
}

/**
 * Implements hook_form_FORM_ID_submit().
 */
function vumain_courses_courses_by_study_topic_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['study-topics'])) {
    $form_state['redirect'] = url('node/' . $form_state['values']['study-topics']);
  }
}

/**
 * Gets all published Study Topics.
 *
 * @return array
 *   Array of fetched rows, keyed by nid, title as value.
 */
function vumain_cources_get_all_study_topics() {
  $rows = &drupal_static(__FUNCTION__, array());
  if (!empty($rows)) {
    return $rows;
  }

  $query = db_select('node', 'n');
  $query->fields('n', array('title', 'nid'));
  $query->addJoin('left', 'field_data_field_study_topic', 'st', 'n.nid = st.entity_id');
  $query->addJoin('left', 'field_data_field_related_study_areas', 'sa', 'n.nid = sa.entity_id');
  // The condition for study topic is entity reference from courses content type
  // to study_topic_area_content.
  // Adding join for courses content type to determine study topics that are
  // used.
  $query->addJoin('inner', 'field_data_field_study_topic_area', 'sta', 'sta.field_study_topic_area_target_id = n.nid');
  $query->addJoin('inner', 'node', 'ntc', 'ntc.nid = sta.entity_id');
  $query->condition('n.status', NODE_NOT_PUBLISHED, '<>');
  $query->condition('ntc.status', NODE_NOT_PUBLISHED, '<>');
  $query->condition('n.type', VUMAIN_CONTENT_TYPE_STUDY_TOPIC_AREA, '=');
  $query->condition('ntc.type', VUMAIN_CONTENT_TYPE_COURSES, '=');
  $query->condition('st.field_study_topic_target_id', NULL, 'IS NULL');
  $query->isNull('st.field_study_topic_target_id');
  $query->isNull('sa.field_related_study_areas_target_id');

  $result = $query->execute();

  $rows = array();
  while ($row = $result->fetchAssoc()) {
    $rows[$row['nid']] = $row['title'];
  }

  return $rows;
}

/**
 * Identifies unit level based on course level/AQF.
 *
 * @param string $course_level
 *   Course level string.
 * @param string $aqf_type
 *   Value of AQF type field.
 *
 * @return mixed
 *   Key for unit level. See vumain_courses_return_unit_level_labels().
 */
function vumain_courses_get_unit_levels($course_level, $aqf_type = NULL) {
  $course_level = strtolower($course_level);

  switch ($aqf_type) {
    case NULL:
    case FALSE:
    case '':
      if ($course_level == VUMAIN_COURSELEVEL_UNDERGRADUATE_FULL) {
        return VUMAIN_COURSELEVEL_UNDERGRADUATE;
      }
      elseif ($course_level == VUMAIN_COURSELEVEL_VET_SHORT) {
        return VUMAIN_COURSELEVEL_TAFE;
      }
      else {
        return VUMAIN_COURSELEVEL_SHORT;
      }

    case VUMAIN_COURSE_AQF_STATEMENT_OF_ATTAINMENT:
      return VUMAIN_COURSELEVEL_SHORT;

    case VUMAIN_COURSE_AQF_CERTIFICATE_I:
    case VUMAIN_COURSE_AQF_CERTIFICATE_II:
    case VUMAIN_COURSE_AQF_CERTIFICATE_III:
    case VUMAIN_COURSE_AQF_CERTIFICATE_IV:
      return VUMAIN_COURSELEVEL_TAFE;

    case VUMAIN_COURSE_AQF_DIPLOMA:
    case VUMAIN_COURSE_AQF_ADVANCED_DIPLOMA:
      return in_array($course_level, [VUMAIN_COURSELEVEL_UNDERGRADUATE_FULL, VUMAIN_COURSELEVEL_UNDERGRADUATE, VUMAIN_COURSELEVEL_HE_DIPLOMAS]) ?
        VUMAIN_COURSELEVEL_HE_DIPLOMAS : VUMAIN_COURSELEVEL_TAFE;

    case VUMAIN_COURSE_AQF_ASSOCIATE_DEGREE:
    case VUMAIN_COURSE_AQF_BACHELOR_DEGREE:
    case VUMAIN_COURSE_AQF_BACHELOR_HONOUR_DEGREE_EMBEDDED:
    case VUMAIN_COURSE_AQF_BACHELOR_HONOUR_DEGREE_STANDALONE:
      return VUMAIN_COURSELEVEL_UNDERGRADUATE;

    case VUMAIN_COURSE_AQF_GRADUATE_DIPLOMA:
    case VUMAIN_COURSE_AQF_MASTERS_COURSEWORK_DEGREE:
      return VUMAIN_COURSELEVEL_POSTGRADUATE;

    case VUMAIN_COURSE_AQF_GRADUATE_CERTIFICATE:
      return $course_level == VUMAIN_COURSELEVEL_VET_SHORT || $course_level == VUMAIN_COURSELEVEL_TAFE ?
        VUMAIN_COURSELEVEL_TAFE : VUMAIN_COURSELEVEL_POSTGRADUATE;

    case VUMAIN_COURSE_AQF_DOCTORAL_DEGREE:
    case VUMAIN_COURSE_AQF_MASTERS_RESEARCH_DEGREE:
      return VUMAIN_COURSELEVEL_POSTGRADUATE_RESEARCH;
  }
}

function vumain_courses_study_areas_sort_levels($a, $b) {
  static $labels;
  if(is_null($labels)) {
    $labels = array_flip(array_values(vumain_courses_return_unit_level_labels()));
  }
  return $labels[$a] > $labels[$b];
}

/**
 * Normalises various ways of defined course levels.
 *
 * @param string $course_level
 *   Course level string.
 *
 * @return string
 *   Normalised string.
 */
function vumain_courses_normalise_course_level($course_level) {
  switch ($course_level) {
    case VUMAIN_COURSELEVEL_UNDERGRADUATE_SHORT:
      return VUMAIN_COURSELEVEL_UNDERGRADUATE_FULL;

    case VUMAIN_COURSELEVEL_POSTGRADUATE_SHORT:
    case VUMAIN_COURSELEVEL_POSTGRADUATE:
      return VUMAIN_COURSELEVEL_POSTGRADUATE_FULL;

    case VUMAIN_COURSELEVEL_VET_FULL:
    case VUMAIN_COURSELEVEL_VET_SHORT:
      return VUMAIN_COURSELEVEL_VET_SHORT;
  }
}

/**
 * Return all unit level labels.
 *
 * @return array
 *   All course level labels (key/value pair).
 */
function vumain_courses_return_unit_level_labels() {
  return array(
    VUMAIN_COURSELEVEL_SHORT => t('Short courses'),
    VUMAIN_COURSELEVEL_TAFE => t('TAFE certificates & diplomas'),
    VUMAIN_COURSELEVEL_HE_DIPLOMAS => t('Higher Education diplomas'),
    VUMAIN_COURSELEVEL_UNDERGRADUATE => t('Bachelor degrees (undergraduate)'),
    VUMAIN_COURSELEVEL_POSTGRADUATE => t('Postgraduate'),
    VUMAIN_COURSELEVEL_POSTGRADUATE_RESEARCH => t('Postgraduate research'),
  );
}

/**
 * Return all Course search form block types.
 *
 * @return array
 *   Array keyed by ID with a block title value.
 */
function _vumain_courses_search_get_form_type() {
  // Build up an array of 'Course search form' blocks.
  return array(
    'find_minimal' => t('Find (Minimal) - title and input'),
    'find_std' => t('Find (Standard) - title, I am and input'),
    'find_std_search' => t('Find (Standard with Search title)'),
    'find_extended' => t('Find (Extended) - title, I am (extended) and title'),
    'find_std_desc' => t('Find (Standard with description) - title, I am, input and description'),
    'search_minimal' => t('Search (Minimal) - input only'),
    'search_std_desc' => t('Search (Standard with description) - input and descriptions'),
  );
}

/**
 * Returns study level label (e.g. postgrad -> Postgraduate).
 *
 * @param int $nid
 *    Node id.
 *
 * @return mixed
 *    string or NULL.
 */
function vumain_extract_study_level_label_from_node($nid) {
  $node = node_load($nid);
  $aqf_code = !empty($node->field_course_aqf[$node->language][0]['safe_value']) ? $node->field_course_aqf[$node->language][0]['safe_value'] : '';
  $unit_level_code = !empty($node->field_unit_lev[$node->language][0]['value']) ? $node->field_unit_lev[$node->language][0]['value'] : '';
  $labels = vumain_courses_return_unit_level_labels();
  $unit_level = vumain_courses_get_unit_levels($unit_level_code, $aqf_code);
  return $labels[$unit_level];
}
