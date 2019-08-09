<?php
/**
 * @file
 * vu_core.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function vu_core_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'brand_logo';
  $formatter->label = 'Brand: Logo';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'list_text';
  $formatter->code = '$elements = [];

foreach ($items as $item) {
  $file = path_to_theme() . "/images/brands/{$item[\'value\']}.svg";
  if (file_exists($file)) {
    $elements[] = [
      \'#markup\' => file_get_contents($file),
    ];
  }
}

return $elements;';
  $formatter->fapi = '';
  $export['brand_logo'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'course_delivery';
  $formatter->label = 'Course delivery';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = 'if (!vu_courses_is_international_course_url() ) {
  if(vu_feature_switches_switch_state(\'courses-admission-transparency\')) {
    $node = $variables[\'#object\'];
    $course = new VuCoreCourseBlockBase($node);

    if ($course->isTafeOnly()) {
      return false;
    }

  }

  $elements = [];

  foreach ($items as $delta => $item) {
     $elements[$delta] = [
       \'#markup\' => $item[\'safe_value\']
     ];
  }
 return $elements;
}

return FALSE;';
  $formatter->fapi = '';
  $export['course_delivery'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'course_duration';
  $formatter->label = 'Course duration';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '$element = [];
$course = new VuCoreCourseBlockBase();

if ($course->isTafeOnly()) {
      return false;
}
$element = vu_courses_duration_text($object);
return $element;';
  $formatter->fapi = '';
  $export['course_duration'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'course_international_fees';
  $formatter->label = 'Course international fees';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text_long';
  $formatter->code = 'if (vu_courses_is_international_course_url()) {
  return vu_courses_international_fees_from_node($object);
}

return FALSE;';
  $formatter->fapi = '';
  $export['course_international_fees'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'course_international_intake';
  $formatter->label = 'Course international intake';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text_long';
  $formatter->code = 'if (vu_courses_is_international_course_url()) {
  $variables = [\'node\' => $object];
  return vu_courses_international_intake_from_xml($variables);
}

return FALSE;';
  $formatter->fapi = '';
  $export['course_international_intake'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'course_short_fees';
  $formatter->label = 'Course short fees';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '$node = $variables[\'#object\'];
$course = new VuCoreCourseBlockBase($node);
$shortCourse = $course->getCourseType() === VU_CBS_TYPE_NA;
if (!vu_courses_is_international_course_url() ) {
  if ($shortCourse) {
    return $items[0][\'safe_value\'];
  }
 
}
return FALSE;';
  $formatter->fapi = '';
  $export['course_short_fees'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'cricos_sanitised_location';
  $formatter->label = 'CRICOS sanitised location';
  $formatter->description = 'Retrieve the campus location out of a CRICOS field, by stripping out the CRICOS code and brackets around the campus name.';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '// Get the CRICOS value.
  $cricos_codes = $variables[\'#items\'];

  $elements = [];
  foreach ($cricos_codes as $delta => $cricos_code) {
    $cricos_code = $cricos_code[\'value\'];
    $start = strpos($cricos_code, \'(\');
    $end = strpos($cricos_code, \')\', $start + 1);
    $length = $end - $start;
    $location = substr($cricos_code, $start + 1, $length - 1);
    $elements[$delta] = [
      \'#markup\' => $location,
    ];
  }
  return ($elements);';
  $formatter->fapi = '';
  $export['cricos_sanitised_location'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'event_date_format';
  $formatter->label = 'Event Date Format';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'datestamp';
  $formatter->code = '// Event Date Formatter
// Displays as (depending on field values):
//   20 August 2016 (when no start time or end time are set or when time = 12.00am)
//   20 August 2016 - 25 August 2016 (when the event has start and end dates but no start time or end time or time = 12.00am)
//   20 August 2016 - 9.00am - 10.00am (when the event is a single day event and it has start and end times)
//   20 August 2016 - 9.00am - 25 August 2016 - 5.00pm (when the event has start and end dates + start and end times)
$dates = $variables[\'#items\'];
$date_format = \'j F Y\';
$time_format = \'g.ia\';
$midnight = \'12.00am\';
$elements = [];
foreach ($dates as $index => $date) {
  $timezone = $date[\'time_zone\'];
  $start = !empty($date[\'value\']) ? $date[\'value\'] : \'\';
  $end = !empty($date[\'value2\']) ? $date[\'value2\'] : \'\';

  $d1 = format_date($start, \'custom\', $date_format, $timezone);
  $d2 = format_date($end, \'custom\', $date_format, $timezone);
  $t1 = format_date($start, \'custom\', $time_format, $timezone);
  $t2 = format_date($end, \'custom\', $time_format, $timezone);

  $start_date = $d1;
  $start_time = \'\';
  if (!empty($t1) && $t1 != $midnight) {
    if ($d1 != $d2) {
      $start_time = \' - \' . $t1;
    }
    elseif ($d1 == $d2 && $t1 != $t2) {
      $start_time = \' - \' . $t1 . \' - \' . $t2;
    }
  }

  $end_date = \'\';
  $end_time = \'\';

  if (!empty($d2) && $d1 != $d2) {
    $end_date = \' - \' . $d2;
    if (!empty($t2) && $t2 != $midnight) {
      $end_time = \' - \' . $t2;
    }
  }

  $display_format = \'!start-date !start-time !end-date !end-time\';

  $elements[$index][] = [
    \'#type\' => \'markup\',
    \'#markup\' => "<span class=\'date-display-single\'>" . t($display_format, array(
        \'!start-date\' => $start_date,
        \'!end-date\' => $end_date,
        \'!start-time\' => $start_time,
        \'!end-time\' => $end_time,
      )) . "</span>",
  ];
}
return (render($elements));';
  $formatter->fapi = '';
  $export['event_date_format'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'event_multiple_dates';
  $formatter->label = 'Event: Multiple dates';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'datestamp';
  $formatter->code = '$date = NULL;

// 1 off event.
// e.g. 19 April
if (count($items) === 1 && (!isset($items[0][\'value2\']) || date(\'Y.z\', $items[0][\'value\']) === date(\'Y.z\', $items[0][\'value2\']))) {
  $date = format_date($items[\'0\'][\'value\'], \'custom\', \'j M\');
}

// Continuous, over more than 1 day period.
// e.g. 9 April to 12 April (4 days)
elseif (count($items) === 1) {
  $start_date = format_date($items[\'0\'][\'value\'], \'custom\', \'j M\');
  $end_date = format_date($items[\'0\'][\'value2\'], \'custom\', \'j M\');

  $start = new DateTime(format_date($items[\'0\'][\'value\'], \'custom\', \'Y-m-j\'));
  $end = new DateTime(format_date($items[\'0\'][\'value2\'], \'custom\', \'Y-m-j\'));
  $range = $end->diff($start)->format("%a") + 1;

  $date = "{$start_date} - {$end_date} ({$range} days)";
}

// Multiple, sessions not yet started; e.g. Multiple, starting 23 Nov
// Multiple, sessions have already started (even when started by just 1 minute it must display the next session as below!); e.g. Multiple, next 24 Nov
elseif (count($items) > 1) {
  $dates = [];
  foreach ($items as $delta => $item) {
    $dates[$delta] = $item[\'value\'];
  }
  array_multisort($dates, SORT_ASC, $items);

  $next = NULL;
  foreach ($items as $delta => $item) {
    if (REQUEST_TIME <= $item[\'value\']) {
      $next = $delta;
      break;
    }
  }

  if (!is_null($next)) {
    $string = $next == 0 ? \'starting\' : \'next\';
    $start = intval(date(\'Y\', $items[$next][\'value\']) . str_pad(date(\'z\', $items[$next][\'value\']), 3, \'0\', STR_PAD_LEFT));
    $date = "Multiple, {$string} " . format_date($items[$next][\'value\'], \'custom\', \'j M\');
  }
}

if (!is_null($date)) {
  return [[\'#markup\' => $date]];
}
return FALSE;';
  $formatter->fapi = '';
  $export['event_multiple_dates'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'event_multiple_location';
  $formatter->label = 'Event: Multiple location';
  $formatter->description = 'Formatter customization fro multiple locations.';
  $formatter->mode = 'php';
  $formatter->field_types = 'list_text';
  $formatter->code = '$elements = [];

// Campus
if (isset($items[0][\'value\']) && $items[0][\'value\'] !== \'off-campus\' && isset($field[\'settings\'][\'allowed_values\'][$items[0][\'value\']])) {
  $elements[] = [
    \'#markup\' => $field[\'settings\'][\'allowed_values\'][$items[0][\'value\']],
  ];
}

// Single location.
elseif (isset($object->field_location[LANGUAGE_NONE]) && count($object->field_location[LANGUAGE_NONE]) === 1) {
  $entities = entity_load(\'inline_entities\', [$object->field_location[LANGUAGE_NONE][0][\'target_id\']]);
  $entity = reset($entities);

  $elements[] = [
    \'#markup\' => $entity->title,
  ];
}

// Multiple location.
elseif (isset($object->field_location[LANGUAGE_NONE])) {
  $elements[] = [\'#markup\' => \'Multiple\'];
}

return $elements;';
  $formatter->fapi = '';
  $export['event_multiple_location'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'events_multiple_dates_new_theme_';
  $formatter->label = 'Events: Multiple dates new theme ';
  $formatter->description = 'Multiple dates formatter for the Event type page in the new theme, that shows up in the event essential block.';
  $formatter->mode = 'php';
  $formatter->field_types = 'datestamp';
  $formatter->code = '$date = NULL;
$node = menu_get_object();
if ($node->type !== \'events\') {
    return FALSE;
}
global $theme;
if ($theme == \'victory\') {
  if (count($items) > 3 ) {
    $date = \'<p>Multiple Dates <br><a href="#all-event-dates-content">View all dates</a></p>\';
  }
  else {
    foreach ($items as $date) {
      $val = date(\'j F Y, g:ia\', $date[\'value\']);
      $val1 = date(\'j F Y, g:ia\', $date[\'value2\']);
      ($date[\'value\'] != $date[\'value2\']) ? ($multiple_dates[] = $val . \' to \' . $val1) : ($multiple_dates[] = $val);
    }
    $date = theme(\'item_list\', [\'items\' => $multiple_dates]);
  }
}
if (!is_null($date)) {
  return [[\'#markup\' => $date]];
}
return FALSE;';
  $formatter->fapi = '';
  $export['events_multiple_dates_new_theme_'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'featured_link';
  $formatter->label = 'Featured link : Link';
  $formatter->description = 'A custom formatter to add \'arrow\' svg into the link markup.';
  $formatter->mode = 'php';
  $formatter->field_types = 'entityreference';
  $formatter->code = '$file = path_to_theme() . "/images/link-arrow.svg";
$svg_markup = \'\';
 if (file_exists($file)) {
  $svg_markup = t("<div class=\'link-arrow\'>!markup</div>", [\'!markup\' => file_get_contents($file)]);
 }
return $svg_markup;';
  $formatter->fapi = '';
  $export['featured_link'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'important_dates_dates';
  $formatter->label = 'Important Dates: Dates';
  $formatter->description = 'Date Formatter';
  $formatter->mode = 'php';
  $formatter->field_types = 'datestamp';
  $formatter->code = '$date = NULL;

if (count($items) !== 1) {
  $new_items = [];
  foreach ($items as $key => $item) {
    if ($item[\'value2\'] >= time()) {
      $new_items[] = $items[$key];
      break;
    }
   }

  $items = $new_items;
}

  // 1 off event.
  // e.g. April 19
  if (count($items) === 1 && (!isset($items[0][\'value2\']) || date(\'Y.z\', $items[0][\'value\']) === date(\'Y.z\', $items[0][\'value2\']))) {
    $start_month = format_date($items[\'0\'][\'value\'], \'custom\', \'F\');
    $start_date = format_date($items[\'0\'][\'value\'], \'custom\', \'j\');
    $date = "<div class=\'month\'>{$start_month}</div>";
   $date .= "<div class=\'date\'>{$start_date}</div>";
  }
  elseif (count($items) === 1) {
    $start_month = format_date($items[\'0\'][\'value\'], \'custom\', \'F\');
    $end_month = format_date($items[\'0\'][\'value2\'], \'custom\', \'F\');
    $start_date = format_date($items[\'0\'][\'value\'], \'custom\', \'j\');
    $end_date = format_date($items[\'0\'][\'value2\'], \'custom\', \'j\');

    if ($start_month == $end_month) {
      // Continuous, over more than 1 day period.
      // e.g. April 9 - 12
      $date = "<div class=\'month\'>{$start_month}</div>";
      $date .= "<div class=\'date-range\'>{$start_date} - {$end_date}</div>";
    }
    else {
      // more than 1 month
      $date = "<div class=\'date-multiple\'><div class=\'date-start\'>{$start_date} {$start_month} </div><div class=\'date-end\'>- {$end_date} {$end_month}</div></div>";
    }
  }

  if (!is_null($date)) {
    return [[\'#markup\' => $date]];
  }

return FALSE;';
  $formatter->fapi = '';
  $export['important_dates_dates'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'link_feature_link';
  $formatter->label = 'Link: Feature Link';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'paragraphs';
  $formatter->code = '$file = path_to_theme() . "/images/link-arrow.svg";
$svg_markup = \'\';
 if (file_exists($file)) {
  $svg_markup = t("<div class=\'link-arrow\'>!markup</div>", [\'!markup\' => file_get_contents($file)]);
 }
return $svg_markup;';
  $formatter->fapi = '';
  $export['link_feature_link'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'link_important_dates';
  $formatter->label = 'Link: Important Dates';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'paragraphs';
  $formatter->code = '$elements = [];

foreach ($items as $item) {
  $paragraph = paragraphs_item_load($item[\'value\']);
  $title = "Find out more";
   switch ($paragraph->bundle) {
    case \'link_external\':
      $url = $paragraph->field_link_link[LANGUAGE_NONE][0][\'url\'];
      break;
    case \'link_internal\':
       $nid = $paragraph->field_node_entity_ref[LANGUAGE_NONE][0][\'target_id\'];
       $url = url("node/{$nid}");
      break;
   }

  $elements[] = [
    \'#type\' => \'link\',
    \'#href\' => $url,
    \'#title\' => $title,
    \'#options\' => [\'html\' => TRUE],
  ];
}

return $elements;';
  $formatter->fapi = '';
  $export['link_important_dates'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'link_related_link';
  $formatter->label = 'Link: Related link';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'paragraphs';
  $formatter->code = '$elements = [];

foreach ($items as $item) {
  $paragraph = paragraphs_item_load($item[\'value\']);

  $url = \'\';
  $title = \'\';
  $arrow = "<div class=\'arrow\'></div>";
  $description = !empty($paragraph->field_link_text[LANGUAGE_NONE][0][\'value\']) ? $paragraph->field_link_text[LANGUAGE_NONE][0][\'value\'] : \'\';
  $attributes = [];

  switch ($paragraph->bundle) {
    case \'link_external\':
      $icon = $paragraph->field_link_icon[LANGUAGE_NONE][0][\'value\'];
      $url = $paragraph->field_link_link[LANGUAGE_NONE][0][\'url\'];
      $title = $paragraph->field_link_link[LANGUAGE_NONE][0][\'title\'];
      break;

    case \'link_internal\':
      $nid = $paragraph->field_node_entity_ref[LANGUAGE_NONE][0][\'target_id\'];
      $node = node_load($nid);
      if (!$node->status) {
         continue 2;
      }
      $icon = $paragraph->field_link_icon[LANGUAGE_NONE][0][\'value\'];
      $url = url("node/{$nid}");
      $title = $node->title;
      break;

    case \'link_phone_number\':
      $icon = $paragraph->field_link_icon[LANGUAGE_NONE][0][\'value\'];
      $title = preg_replace("/([+]*[0-9][\\W0-9]*\\d\\b)/", \'<span class="no-wrap">$1</span>\', $paragraph->field_link_title[LANGUAGE_NONE][0][\'value\']);
      $arrow = \'\';

      $url = \'tel:\' . str_replace(\' \', \'\', $paragraph->field_international_phone_number[LANGUAGE_NONE][0][\'value\']);
      $attributes[\'data-tracking\'] = $paragraph->field_international_phone_number[LANGUAGE_NONE][0][\'value\'];
      break;
    }

  $icon = !empty($icon) ? \'<i class="fa \' . $icon . \'"></i>\' : \'\';
  $text = "<span class=\'title\'>{$title}</span>";
  if (!empty($description)) {
    $text .= "<span class=\'summary\'>{$description}</span>";
  }
  $elements[] = [
    \'#type\' => \'link\',
    \'#href\' => $url,
    \'#title\' => "<div class=\'icon\'>{$icon}</div><div class=\'text\'>{$text}</div>" . $arrow,
    \'#options\' => [\'html\' => TRUE],
    \'#attributes\' => $attributes,
  ];
}
return $elements;';
  $formatter->fapi = '';
  $export['link_related_link'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'location_tag';
  $formatter->label = 'Location tag';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '$element = null;
$node = menu_get_object();
$element = $items[0][\'value\'];

if (!empty($element )) {
  return [[\'#markup\' => \'<i class="fa fa-map-marker" aria-hidden="true"></i><span class="location-tag-text">Location: </span><span class="tag">\'.$element.\'</span>\' ]];
}
return FALSE;';
  $formatter->fapi = '';
  $export['location_tag'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'quick_fact_icon';
  $formatter->label = 'Quick Fact Icon';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '$elements = [];
foreach ($items as $item) {

 $icon = !empty($item[\'value\']) ? \'<h2><i class="fa \' . $item[\'value\'] . \'"></i></h2>\' : \'\';
      $elements[] = [
      \'#markup\' => $icon,
    ];
}

return $elements;';
  $formatter->fapi = '';
  $export['quick_fact_icon'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'quick_facts';
  $formatter->label = 'Quick facts';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = '$elements = [];

foreach ($items as $item) {
  if (file_exists($item[\'uri\'])) {
    $elements[] = [
      \'#markup\' => file_get_contents ($item[\'uri\']),
    ];
  }
}

return $elements;';
  $formatter->fapi = '';
  $export['quick_facts'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'short_course_date_format';
  $formatter->label = 'Short Course Date format';
  $formatter->description = 'Formats a date field with a start and end date/time in the format:  20 August - 21 August 2016 | 9.00am - 5.00pm';
  $formatter->mode = 'php';
  $formatter->field_types = 'datetime';
  $formatter->code = '// Natural Date Formatter
// Displays as (depending on field values):
//   20 August
//   20 August | 9.00am
//   20 August | 9.00am - 5.00pm
//   20 August - 21 August 2016
//   20 August - 21 August 2016 | 9.00am - 5.00pm

// Get the label
$label_text = $variables[\'#object\']->title;

// Get all dates
$dates = $variables[\'#items\'];

// Cycle through all dates (if more than one)
foreach ($dates as $index => $date) {
  $timezone = $date[\'timezone\'];
  $timezone_db = $date[\'timezone_db\'];
  $start = strtotime($date[\'value\'] . \' \' . $timezone_db);
  $end = strtotime($date[\'value2\'] . \' \' . $timezone_db);

  $lines = [];
  if ($end < time()) {
    // Do not display this field
  }
  else {
    // Get the start and end date for the current date
    $display = [\'settings\' => [\'format_type\' => \'medium\']];
    $d1 = format_date($start, \'custom\', \'d F\', $timezone);
    $d2 = format_date($end, \'custom\', \'d F Y\', $timezone);
    $t1 = format_date($start, \'custom\', \'g.i a\', $timezone);
    $t2 = format_date($end, \'custom\', \'g.i a\', $timezone);

    // Print single date or a range (dash-separated)
    if (empty($d2) or $d1 == $d2) {
      $formatted_date = "$d1";
    }
    else {
      $formatted_date = "$d1 - $d2";
    }

    // If time is specified, print it (if time is blank or the same, print it
    // once, otherwise print the range).
    // Format with no leading zero, and period instead of colon as per
    // style guide.
    if (empty($t1) && empty($t2)) {
      $formatted_date .= \'\';
    }
    elseif (empty($t2) || $t1 == $t2) {
      $formatted_date .= " | $t1";
    }
    else {
      $formatted_date .= " | $t1 - $t2";
    }

    $label = "<div class=\'date-time-label\'>" . $label_text . "</div>";
    $formatted_date = "<div class=\'date-time-item\'>" . $formatted_date . "</div>";
    $full_output = $label . $formatted_date;

    $lines[] = $full_output;
  }

}

return implode(\'\', $lines);';
  $formatter->fapi = '';
  $export['short_course_date_format'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'short_course_day_format';
  $formatter->label = 'Short course day format';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'datetime';
  $formatter->code = '/**
 * Format Dates for Short course dates
 *
 * 9 December 2017
 * 9 December - 20 December 2017
 */
$output = [];

foreach ($items as $delta => $item) {
  /** @var \\DateTime $to */
  /** @var \\DateTime $from */
  list($from, $to) = _vu_core_get_date_objects($item);

  if (!$to || $from->format(\'YY "/" mm "/" dd\') == $to->format(\'YY "/" mm "/" dd\')) {
    $output[$delta][\'#markup\'] = $from->format(\'j F Y\');
    break;
  }

  $from_to_date_format = \'@from &ndash; @to\';
  $from_format = \'j F \';
  if ($from->format(\'Y\') != $to->format(\'Y\')) {
    $from_format .= \'Y\';
  }
  elseif ($from->format(\'F\') == $to->format(\'F\')) {
    $from_format = \'j\';
    $from_to_date_format = \'@from&ndash;@to\';
  }

  $output[$delta][\'#markup\'] = format_string($from_to_date_format, [\'@from\' => $from->format($from_format), \'@to\' => $to->format(\'j F Y\')]);
}

return $output;';
  $formatter->fapi = '';
  $export['short_course_day_format'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'short_course_time_format';
  $formatter->label = 'Short course time format';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'datetime';
  $formatter->code = '/**
 * Format times for Short course dates
 *
 * 10am
 * 10.15am
 * 10-11am
 * 10am-1.30pm
 */
$output = [];

foreach ($items as $delta => $item) {
  /** @var \\DateTime $to */
  /** @var \\DateTime $from */
  list($from, $to) = _vu_core_get_date_objects($item);

  $from_to_time_format = \'@from&ndash;@to\';
  $from_format = \'g\';
  $to_format = \'g\';

  if (($from->getTimestamp() % 3600) != 0) {
    $from_format .= \'.i\';
  }
  if (($to->getTimestamp() % 3600) != 0) {
    $to_format .= \'.i\';
  }

  $to_format .= \'a\';
  if ($from->format(\'a\') != $to->format(\'a\')) {
    $from_format .= \'a\';
  }

  if ($from->format(\'g.i\') == $to->format(\'g.i\')) {
    $from_to_time_format = \'@to\';
  }

  $output[$delta][\'#markup\'] = format_string($from_to_time_format, [\'@from\' => $from->format($from_format), \'@to\' => $to->format($to_format)]);
}

return $output;';
  $formatter->fapi = '';
  $export['short_course_time_format'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'title_id';
  $formatter->label = 'Title: ID';
  $formatter->description = 'Turns a title string into a ID value.';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '$id = vu_core_title_id($items[0][\'value\'], \'formatter\');
return "#{$id}";';
  $formatter->fapi = '';
  $export['title_id'] = $formatter;

  return $export;
}
