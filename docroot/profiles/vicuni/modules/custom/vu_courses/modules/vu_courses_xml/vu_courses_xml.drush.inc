<?php

/**
 * @file
 * Drush integration for VU Courses XML module.
 */

define('VU_COURSES_XML_D6', 'https://www.vu.edu.au/international-courses.xml');
define('VU_COURSES_XML_D7', 'https://vu:46>GwfCp@vueduaudev.prod.acquia-sites.com/international-courses.xml');

/**
 * @file
 * Drush command to make sure that XML exports work correctly.
 */

/**
 * Implements hook_drush_command().
 */
function vu_courses_xml_drush_command() {
  return [
    'vu-courses-xml' => [
      'description' => 'Test to make sure that XML exports work correctly.',
      'bootstrap'   => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases'     => ['vucx'],
      'examples'    => [
        'drush vucx',
        'drush vucx ' . VU_COURSES_XML_D6 . ' ' . VU_COURSES_XML_D7,
        'drush vucx /var/beetbox/6.xml /var/beetbox/7.xml',
      ],
    ],
  ];
}

/**
 * Drush callback.
 */
function drush_vu_courses_xml($d6 = VU_COURSES_XML_D6, $d7 = VU_COURSES_XML_D7) {
  $data = [];

  foreach ([6, 7] as $v) {
    $uri = ${"d{$v}"};

    $scheme = file_uri_scheme($uri);
    switch ($scheme) {
      // Support downloading XML file from HTTP(s).
      case 'http':
      case 'https':
        $file_data = file_get_contents($uri, FALSE, stream_context_create([
          'ssl' => [
            'verify_peer'      => FALSE,
            'verify_peer_name' => FALSE,
          ],
        ]));
        if (empty($file_data)) {
          drush_set_error(dt('FAILURE! Unable to download file.'));
          return;
        }
        break;

      default:
        if (pathinfo($uri)['dirname'] == '.') {
          $uri = DRUPAL_ROOT . '/' . $uri;
        }
        $file_data = file_get_contents($uri);
        if (empty($file_data)) {
          drush_set_error(dt('FAILURE! Unable to open file.'));
          return;
        }
    }
    $file = file_save_data($file_data);

    $data[$v] = _vu_courses_xml_extract_courses_data($file->uri);
    if (!$data[$v]) {
      drush_set_error(dt('FAILURE! Unable to parse !file.', ['!file' => $file->uri]));
      return;
    }
  }

  $results = _vu_courses_xml_compare_data($data[6], $data[7]);
  $report = _vu_courses_xml_compare_render_results($results);

  if ($report['error']) {
    drush_set_error($report['message']);
  }
  else {
    drush_print($report['message']);
  }
}
