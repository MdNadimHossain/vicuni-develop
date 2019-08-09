<?php
/**
 * @file
 * VU Enquire Now - Boomi integration.
 */

/**
 * Capture webform submission for Boomi integration.
 *
 * @param object $node
 * @param object $submission
 */
function _vu_enquire_now_webform_submission_insert($node, $submission) {
  $enquire_now = variable_get('vu_enquire_now_webform_nid', NULL);
  if (!empty($enquire_now['entity_id'])) {
    if ($submission->nid == $enquire_now['entity_id']) {
      $record = array(
        'drupal_submitted' => $submission->submitted,
        'boomi_submitted' => 0,
        'first_name' => $submission->data[1][0],
        'last_name' => $submission->data[8][0],
        'email' => $submission->data[2][0],
        'phone' => $submission->data[3][0],
        'course' => $submission->data[7][0],
        'school' => $submission->data[16][0],
        'comment' => $submission->data[5][0],
        'opt_in' => $submission->data[10][0],
        'postal' => $submission->data[11][0],
        'timeframe' => $submission->data[13][0],
        'current_situation' => $submission->data[12][0],
        'area_of_interest' => $submission->data[17][0],
      );
      try {
        drupal_write_record('enquire_now_submissions', $record);
      }
      catch (Exception $e) {
        watchdog_exception('vu_enquire_now', $e);
      }
    }
  }
}

/**
 * Menu callback to generate XML for Boomi to consume.
 */
function vu_enquire_now_boomi_xml() {
  module_load_include('module', 'vu_rightnow_forms');
  vu_rightnow_forms_authenticate();

  $keys_to_send = array(
    'first-name',
    'last-name',
    'email',
    'phone',
    'course',
    'school',
    'comment',
    'opt-in',
    'postal',
    'timeframe',
    'current-situation',
    'area-of-interest',
    'level-of-study',
  );

  $params = drupal_get_query_parameters();

  $query = db_select('enquire_now_submissions')->fields('enquire_now_submissions');
  $query->condition('boomi_submitted', 0);
  $result = $query->execute();

  $domtree = new DOMDocument('1.0', 'UTF-8');

  $root = $domtree->createElement("form-submissions");
  $root = $domtree->appendChild($root);

  while ($row = $result->fetchAssoc()) {
    $submission = $root->appendChild($domtree->createElement('form-submission'));
    $row['opt_in'] = (isset($row['opt_in']) && ($row['opt_in'] === 'yes' || $row['opt_in'] === 1)) ? 1 : 0;

    foreach ($row as $key => $value) {
      $key = str_replace('_', '-', $key);
      if (in_array($key, $keys_to_send)) {
        $submission->appendChild($domtree->createElement($key, htmlspecialchars($value)));
      }
    }

    if (!isset($params['ro'])) {
      // Update the submission to mark it as submitted if we haven't called this function with read only.
      $row['boomi_submitted'] = REQUEST_TIME;
      try {
        drupal_write_record('enquire_now_submissions', $row, 'sid');
      }
      catch (Exception $e) {
        watchdog_exception('vu_enquire_now', $e);
      }
    }
  }

  header('Content-Type: text/xml; charset=utf-8');
  echo $domtree->saveXML();
  drupal_exit();
}
