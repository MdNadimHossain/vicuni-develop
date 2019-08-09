<?php
/**
 * @file
 * VU Mid-Year Intake admin settings.
 */

// Include VU Course Index functions.
if (!function_exists('vu_course_index_get_course_intake_list')) {
  require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'vu_course_index') . '/vu_course_index.functions.php';
}

/**
 * Attach Mid-Year Intake settings to Courses Node type form.
 */
function _vu_midyear_intake_form_node_type_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#node_type']->type !== 'courses') {
    return;
  }

  $form['midyear_intake'] = array(
    '#title' => t('Mid-Year Intake'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'additional_settings',
    '#weight' => 101,
  );

  $form['midyear_intake']['midyear_intake'] = array(
    '#title' => t('Enable Mid-Year Intake period'),
    '#type' => 'checkbox',
    '#default_value' => vu_midyear_intake_is_enabled(),
    '#attributes' => array(
      'data-enabled-description' => t('Enabled'),
      'data-disabled-description' => t('Disabled'),
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'vu_midyear_intake') . '/js/node-type-form.js'),
    ),
  );

  $form['midyear_intake']['midyear_intake_search_index'] = array(
    '#title' => t('Course Search Index'),
    '#type' => 'select',
    '#required' => TRUE,
    '#default_value' => variable_get('vu_midyear_intake_search_index', 'course_index'),
    '#options' => search_api_index_options_list(),
  );

  global $databases;
  foreach ($databases as $key => $targets) {
    foreach ($targets as $target => $info) {
      if (Database::getConnection($target, $key)
        ->schema()
        ->tableExists('course_intake')
      ) {
        $options[$key]["$key:$target"] = "$key > $target";
      }
    }
  }
  if (count($options) > 1 || count(reset($options)) > 1) {
    $form['midyear_intake']['midyear_intake_source'] = array(
      '#type' => 'select',
      '#title' => t('Database source for course_intake table'),
      '#options' => $options,
      '#default_value' => variable_get('vu_midyear_intake_source', 'default:default'),
      '#required' => TRUE,
    );
  }
  else {
    $form['midyear_intake']['midyear_intake_source_desc'] = array(
      '#type' => 'markup',
      '#markup' => '<div>' . t('Database source for <em>course_intake</em> table: <strong>!source</strong>', array('!source' => "$key > $target")) . '</div>',
    );
    $form['midyear_intake']['midyear_intake_source'] = array(
      '#type' => 'value',
      '#value' => "$key:$target",
    );
  }

  $form['midyear_intake']['midyear_intake_last_reindex'] = array(
    '#type' => 'markup',
    '#markup' => '<div>' . t('Last update: !update', array('!update' => format_date(vu_midyear_intake_get_last_reindex(), 'short'))) . '</div>',
  );
  if (user_access('administer nodes')) {
    $form['midyear_intake']['midyear_intake_source_reload'] = array(
      '#type' => 'markup',
      '#markup' => l('Reload Mid-Year Intake Availability', 'admin/structure/types/manage/courses/reload_midyear_intake'),
    );
  }

  $form['#submit'][] = '_vu_midyear_intake_form_node_type_form_submit';
}

/**
 * Submit handler for Enquire Now settings in Courses Node type form.
 */
function _vu_midyear_intake_form_node_type_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  vu_feature_switches_switch_toggle('courses-midyear-info', $values['midyear_intake']);
  drupal_set_message(t('Mid-Year Intake settings have been updated.'));

  variable_set('vu_midyear_intake_source', $values['midyear_intake_source']);
  drupal_set_message(t('<a href="!link">Reload</a> course Mid-Year availability.',
    array(
      '!link' => url('admin/structure/types/manage/courses/reload_midyear_intake'),
    )
  ));

  variable_set('vu_midyear_intake_search_index', $values['midyear_intake_search_index']);
  drupal_set_message(t('<a href="!link" target="_blank">Reindex</a> Course Search index.',
    array(
      '!link' => url('admin/config/search/search_api/index/' . $values['midyear_intake_search_index']),
    )
  ));
  if ($search_index = search_api_index_load($values['midyear_intake_search_index'])) {
    /** @var SearchApiIndex $search_index */
    if (!isset($search_index->options['fields']['field_course_midyear_intake'])) {
      $search_index->options['fields']['field_course_midyear_intake'] = array('type' => 'boolean');
      $search_index->save();
    }
  }
  cache_clear_all('facetapi', 'cache', TRUE);
  cache_clear_all('search_api', 'cache', TRUE);
}

/**
 * Menu callback to reload Mid-Year Intake Availability from course_intake.
 */
function vu_midyear_intake_reload() {
  $batch = _vu_midyear_intake_reload_batch();
  batch_set($batch);

  batch_process('admin/structure/types/manage/courses');
}

/**
 * Get batch operation to reload Mid-Year Intake Availability.
 *
 * @return array
 */
function _vu_midyear_intake_reload_batch() {
  $batch = array(
    'operations' => array(
      array('_vu_midyear_intake_reload_batch_process', array()),
    ),
    'finished' => '_vu_midyear_intake_reload_batch_finished',
    'title' => t('Reloading Mid-Year Intake Availability'),
    'init_message' => t('Reloading Mid-Year Intake Availability'),
    'progress_message' => t('Reloading Mid-Year Intake Availability'),
    'error_message' => t('Mid-Year Intake Reload has encountered an error.'),
    'file' => drupal_get_path('module', 'vu_midyear_intake') . '/vu_midyear_intake.admin.inc',
  );
  return $batch;
}

/**
 * Batch API process callback.
 */
function _vu_midyear_intake_reload_batch_process(&$context) {
  $source = variable_get('vu_midyear_intake_source', 'default:default');
  list($key, $target) = explode(':', $source);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_nid'] = 0;
    $context['sandbox']['max'] = db_query('SELECT COUNT(nid) FROM {node} WHERE type = :type ORDER BY nid ASC', array(
      ':type' => 'courses',
    ))->fetchField();
  }

  $is_mid_year_intake = vu_midyear_intake_is_enabled();

  if ($is_mid_year_intake) {
    // Load course mid-year intake availability.
    $available_courses = array();
    $result = Database::getConnection($target, $key)
      ->query('SELECT course_code FROM course_intake WHERE intake_enabled = :intake_enabled AND course_intake_status = :course_intake_status GROUP BY course_code', array(
        ':intake_enabled' => 1,
        ':course_intake_status' => VU_MIDYEAR_INTAKE_STATUS_OFFERED,
      ));
    foreach ($result as $row) {
      $delivery = vu_course_index_get_course_intake_list($row->course_code);
      if ($delivery->isOpen()) {
        $available_courses[$row->course_code] = 1;
      }
    }
  }

  $limit = 100;
  $result = db_query_range('SELECT nid FROM {node} WHERE nid > :nid AND type = :type ORDER BY nid ASC', 0, $limit, array(
    ':nid' => $context['sandbox']['current_nid'],
    ':type' => 'courses',
  ));
  foreach ($result as $row) {
    $context['sandbox']['progress']++;
    $context['sandbox']['current_nid'] = $row->nid;

    // Load and update the course.
    if ($course = node_load($row->nid)) {
      $course_available = 0;
      $course_code = '';

      if (!empty($course->field_unit_code[$course->language][0]['value'])) {
        $course_code = $course->field_unit_code[$course->language][0]['value'];
        if ($is_mid_year_intake) {
          $course_available = !empty($available_courses[$course_code]) ? 1 : 0;
        }
      }

      $course_changed = FALSE;
      if (isset($course->field_course_midyear_intake[$course->language][0]['value'])) {
        if ($course->field_course_midyear_intake[$course->language][0]['value'] != $course_available) {
          $course->field_course_midyear_intake[$course->language][0]['value'] = $course_available;
          $course_changed = TRUE;
        }
      }
      else {
        $course->field_course_midyear_intake[$course->language][0]['value'] = $course_available;
        $course_changed = TRUE;
      }

      if ($course_changed) {
        $context['message'] = t('Now updating course %course_code (nid: %nid)', array(
          '%course_code' => $course_code,
          '%nid' => $course->nid,
        ));
        $course->revision = 0;
        node_save($course);
        $context['results'][$course->nid] = $course->course_code;
      }
    }

    // Inform the batch engine that we are not finished,
    // and provide an estimation of the completion level we reached.
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
}

/**
 * Batch API finished callback.
 */
function _vu_midyear_intake_reload_batch_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = t('@count courses successfully updated.', array('@count' => count($results)));
    if (count($results)) {
      $message .= ' ' . t('Please <a href="!link" target="_blank">Reindex</a> Course Search index.', array(
        '!link' => url('admin/config/search/search_api/index/' . variable_get('vu_midyear_intake_search_index', 'course_index')),
      ));
    }
    drupal_set_message($message);
    vu_midyear_intake_set_last_reindex();
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }
}
