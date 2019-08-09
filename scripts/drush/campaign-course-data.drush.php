<?php

/**
 * @file
 * Script to generate courses csv for static sites.
 */

$header = [
  "title",
  "course_id",
  "sort_title",
  "related_courses",
  "level",
  "campus",
  "url",
  "college",
  "description",
];
fputcsv(STDOUT, $header);

// Get all offered courses.
$course_args = ['type' => 'courses', 'status' => '1'];

$published_courses = array_map('wrap', node_load_multiple([], $course_args));
$open_courses = array_filter($published_courses, 'course_open_test');
usort($open_courses, function ($a, $b) {
  return strnatcmp(sort_title($a), sort_title($b));
});

foreach ($open_courses as $course) {
  $row = [
    $course->title->value(),
    $course->field_unit_code->value(),
    sort_title($course),
    related_courses($course),
    course_level($course),
    campuses($course),
    course_url($course),
    $course->field_college->value()['title'],
    course_description($course),
  ];
  fputcsv(STDOUT, $row);
}

/**
 * Wrap a node with an entity_metadata_wrapper.
 *
 * @param object $node
 *   Drupal node.
 *
 * @return object
 *   EntityMetadataWrapper.
 */
function wrap($node) {
  return entity_metadata_wrapper('node', $node);
}

/**
 * Test if a course is open.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return bool
 *   Is it open?
 */
function course_open_test($course) {
  $intake = get_course_intake($course);
  return $intake->isOpen();
}

/**
 * Get course index info for a course.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return CourseIntakeList
 *   Course index rows.
 */
function get_course_intake($course) {
  static $intakes = [];
  module_load_include('php', 'vu_course_index', 'vu_course_index.functions');
  $course_code = $course->field_unit_code->value();
  if (!isset($intakes[$course_code])) {
    $intakes[$course_code] = vu_course_index_get_course_intake_list($course_code);
  }
  return $intakes[$course_code];
}

/**
 * Return a URL given a wrapped node.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Course URL.
 */
function course_url($course) {
  return drupal_get_path_alias('node/' . $course->nid->value());
}

/**
 * Return a link given a wrapped node.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Link to course.
 */
function course_link($course) {
  return l($course->title->value(), course_url($course));
}

/**
 * Return a Markdown list of links to related courses.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Markdown list of Markdown links.
 */
function related_courses($course) {
  $related_courses = array_filter($course->field_related_courses->value());
  $entities = array_map('wrap', $related_courses);
  foreach ($entities as $key => $entity) {
    // Exclude unpublished related courses.
    if ($entity->status->value() == 0) {
      unset($entities[$key]);
    }
  }
  return markdown_list(array_map('course_link', $entities));
}

/**
 * Turn an array into a flat Markdown list.
 *
 * @param array $arr
 *   Whatever.
 *
 * @return string
 *   Markdown list.
 */
function markdown_list(array $arr) {
  return count($arr) < 1 ? current($arr) : '* ' . implode(PHP_EOL . '* ', $arr);
}

/**
 * Return a sensible level string for the course.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Course level string.
 */
function course_level($course) {
  $title = $course->title->value();
  $re = '/(.* - )?(Victorian |Graduate )?((Advanced )?[^ ]+) (I|of|in).*$/uU';
  $level = preg_replace($re, '$3', $title);
  return in_array($level, ['Master', 'Doctor']) ? 'Postgraduate' : $level;
}

/**
 * Generate title for sorting.
 *
 * There is a field on the node for this but it's not populated all the time.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Title for sort.
 */
function sort_title($course) {
  $title = $course->title->value();
  $re = '/^(.* - )?(Victorian |Graduate )?((Advanced )?[^ ]+) ([IV]+ )?(of|in)(.*$)$/uUsm';
  return trim(preg_replace($re, '$7 $2$3 $5', $title));
}

/**
 * Return a Markdown list of links to campuses for this course.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Markdown list of links to campuses.
 */
function campuses($course) {
  $intake = get_course_intake($course);
  $campuses = array_map([CourseEssentialsPresenter, 'locationMap'], $intake->locations());
  return markdown_list($campuses);
}

/**
 * Return a truncated course description.
 *
 * @param object $course
 *   Wrapped course node.
 *
 * @return string
 *   Description truncated at the first heading.
 */
function course_description($course) {
  $description = $course->field_introduction->value()['value'];

  $paragraph_items = $course->field_paragraphs_left->value();
  $paragraph_description = '';
  foreach ($paragraph_items as $paragraph_item) {
    if ($paragraph_item->bundle() == "wysiwyg") {
      $item = vu_core_extract_single_field_value($paragraph_item, 'paragraphs_item', 'field_body', 'value');
      $paragraph_description .= $item;
    }
  }

  $description .= $paragraph_description;

  return preg_replace('/(.*)<h.*$/uUs', '$1', $description);
}
