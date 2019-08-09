<?php

/**
 * @file
 * Researcher profile form.
 */

/**
 * Profile node form alter.
 */
function _vu_rp_form_researcher_profile_node_form_alter(&$form, &$form_state, $form_id) {
  $form['#attached']['css'][] = drupal_get_path('module', 'vu_rp') . '/css/vu_rp.form.min.css';
  $form['#attached']['js'][] = drupal_get_path('module', 'vu_rp') . '/js/vu_rp.form.js';
  _vu_rp_form_process_fields($form);
  _vu_rp_form_publication_fields_render($form);
  _vu_rp_form_funding_fields_render($form);
  _vu_rp_form_supervision_fields_render($form);

  // Simplify vertical tabs.
  unset($form['revision_information']['#group']);
}

/**
 * Helper to recursively process form fields.
 */
function _vu_rp_form_process_fields(&$form, $is_api_field = FALSE) {
  foreach (element_children($form) as $field) {
    if (strpos($field, 'field_rpa_') === 0 || strpos($field, 'field_rpc_') === 0) {
      // Disable all API and computed fields.
      $form[$field]['#disabled'] = TRUE;
      // Completely remove paragraphs fields.
      if (isset($form[$field][LANGUAGE_NONE]['#instance']['widget']['type'])
        && $form[$field][LANGUAGE_NONE]['#instance']['widget']['type'] == 'paragraphs_embed') {
        $form[$field]['#access'] = FALSE;
      }
      // Completely remove calculated fields.
      if (strpos($field, 'field_rpc_') === 0) {
        $form[$field]['#access'] = FALSE;
      }
      $is_api_field = TRUE;
    }
    elseif (isset($form[$field]['#required']) && !$is_api_field) {
      if ($form[$field]['#required']) {
        $form[$field]['#title'] .= ' (required)';
      }
      else {
        $form[$field]['#title'] .= ' (optional)';
      }
    }

    if (count(element_children($form[$field])) > 0) {
      _vu_rp_form_process_fields($form[$field], $is_api_field);
    }
  }
}

/**
 * Process form elements.
 */
function _vu_rp_form_preprocess_element(&$element, $value) {
  // Change description position.
  if ($element['element']['#field_name'] == 'field_rp_teaching_experience') {
    $element['element']['#title'] = NULL;
  }
  if (!empty($element['element']['#description'])) {
    if ($element['element']['#field_name'] == 'field_rp_photo') {
      $element['element']['#title'] = $element['element']['#description'];
    }
    else {
      $element['element']['#title'] .= '<p class="description">' . $element['element']['#description'] . '</p>';
    }
  }
  $element['element']['#description'] = NULL;
}

/**
 * Render publication fields on the form.
 */
function _vu_rp_form_publication_fields_render(&$form) {
  if (!empty($form['#node'])) {
    $form['field_rp_publications_info'] = [
      '#type' => 'container',
    ];

    $table = _vu_rp_form_publications_table_render($form['#node']);

    $markup = '<h2>Publications from Elements</h2>';
    $email = variable_get('vu_rp_helpdesk_email');
    $email = l($email, 'mailto:' . $email);
    if (!empty($table)) {
      $markup .= '<p>The following publications have come through from Elements. If you have any questions regarding these publications contact ' . $email . '.</p>';
    }
    else {
      $markup .= '<div class="no-api-data">';
      $markup .= '<p>None of your publications have come through from Elements.</p>';
      $markup .= '<p>You will <strong>not</strong> be able to submit your profile for review until you have at least one publication available via Elements.</p>';
      $markup .= '<p>If you have any questions regarding about how to enter your publications in Elements please contact ' . $email . '.</p>';
      $markup .= '</div>';
    }

    $form['field_rp_publications_info']['markup'] = [
      '#markup' => $markup,
    ];

    if (!empty($table)) {
      $form['field_rp_publications_info']['table_container'] = [
        '#type' => 'fieldset',
        '#title' => t('Publications'),
        '#expandable' => FALSE,
        '#expanded' => TRUE,
      ];

      $form['field_rp_publications_info']['table_container']['table'] = [
        '#markup' => $table,
      ];
    }
  }
}

/**
 * Render publication table.
 */
function _vu_rp_form_publications_table_render($node) {
  $publications = vu_rp_node_get_publications($node);

  $rows = [];
  foreach ($publications as $type => $records) {
    $rows[] = [
      [
        'data' => '<strong>' . $type . '</strong>',
        'colspan' => 2,
      ],
    ];
    foreach ($records['items'] as $record) {
      $rows[] = [
        $record['year'],
        '<p>' . (isset($record['citation']) ? $record['citation'] : '') . (isset($record['link']) ? $record['link'] : ''),
      ];
    }
  }

  return !empty($rows) ? theme('table', [
    'rows' => $rows,
    'sticky' => FALSE,
  ]) : '';
}

/**
 * Render funding fields on the form.
 */
function _vu_rp_form_funding_fields_render(&$form) {
  if (!empty($form['#node'])) {
    $form['field_rp_fundings_info'] = [
      '#type' => 'container',
    ];

    $table = _vu_rp_form_funding_table_render($form['#node']);

    $markup = '<h2>Research funding for the past 5 years</h2>';
    $email = variable_get('vu_rp_helpdesk_email');
    $email = l($email, 'mailto:' . $email);
    if (!empty($table)) {
      $markup .= '<p>The following funding information has come through from QUEST. If you have any questions regarding these publications contact ' . $email . '.</p>';
    }
    else {
      $markup .= '<div class="no-api-data">';
      $markup .= '<p>No funding entries have come through from QUEST.</p>';
      $markup .= '<p>Your profile can still be published without funding entries but you must enter at least one organisation to acknowledge in the next section.</p>';
      $markup .= '<p>If you have any questions regarding about how to enter your funded projects into QUEST please contact ' . $email . '.</p>';
      $markup .= '</div>';
    }

    $form['field_rp_fundings_info']['markup'] = [
      '#markup' => $markup,
    ];

    if (!empty($table)) {
      $form['field_rp_fundings_info']['table_container'] = [
        '#type' => 'fieldset',
        '#title' => t('Funding for the past 5 years'),
        '#expandable' => FALSE,
        '#expanded' => TRUE,
      ];

      $form['field_rp_fundings_info']['table_container']['table'] = [
        '#markup' => $table,
      ];
    }
  }
}

/**
 * Render funding table.
 */
function _vu_rp_form_funding_table_render($node) {
  $fundings = vu_rp_node_get_fundings($node);

  $rows = [];
  $last_year = end($fundings);
  foreach ($fundings as $year => $records) {
    $rows[] = ['<strong>' . $year . '</strong>'];

    $last_record = end($records);
    foreach ($records as $record) {
      $rows[] = ['<strong>' . $record['title'] . '</strong>'];
      $rows[] = [$record['amount']];
      $rows[] = ['From: ' . $record['source']];
      if (!empty($record['investigators'])) {
        $rows[] = ['Investigators: ' . $record['investigators']];
      }
      $rows[] = ['For period: ' . $record['period']];
      if ($record != $last_record) {
        $rows[] = ['&nbsp;'];
      }
    }

    if ($fundings != $last_year) {
      $rows[] = ['&nbsp;'];
    }
  }

  return !empty($rows) ? theme('table', [
    'rows' => $rows,
    'sticky' => FALSE,
  ]) : '';
}

/**
 * Render supervision fields on the form.
 */
function _vu_rp_form_supervision_fields_render(&$form) {
  if (!empty($form['#node'])) {
    $form['field_rp_sup_info'] = [
      '#type' => 'container',
    ];

    $table_current = _vu_rp_form_supervision_table_render($form['#node'], TRUE);
    $table_completed = _vu_rp_form_supervision_table_render($form['#node'], FALSE);

    $markup = '<h2>Supervision of research students at VU</h2>';
    $email = variable_get('vu_rp_helpdesk_email');
    $email = l($email, 'mailto:' . $email);
    if (!empty($table_current) || !empty($table_completed)) {
      $markup .= '<p>The following supervision information has come through from QUEST. Please review  it is correct. If you have any questions regarding this information contact ' . $email . '.</p>';
    }
    else {
      $markup .= '<div class="no-api-data">';
      $markup .= '<p>No supervision information has come through from QUEST.</p>';
      $markup .= '<p>If you have any questions regarding about how to enter your supervision information into QUEST please contact ' . $email . '.</p>';
      $markup .= '</div>';
    }

    $form['field_rp_sup_info']['markup'] = [
      '#markup' => $markup,
    ];

    if (!empty($table_current)) {
      $form['field_rp_sup_info']['table_container1'] = [
        '#type' => 'fieldset',
        '#title' => t('Currently supervised research students at VU'),
        '#expandable' => FALSE,
        '#expanded' => TRUE,
      ];

      $form['field_rp_sup_info']['table_container1']['table'] = [
        '#markup' => $table_current,
      ];
    }

    if (!empty($table_completed)) {
      $form['field_rp_sup_info']['table_container2'] = [
        '#type' => 'fieldset',
        '#title' => t('Completed supervision of research students at VU'),
        '#expandable' => FALSE,
        '#expanded' => TRUE,
      ];

      $form['field_rp_sup_info']['table_container2']['table'] = [
        '#markup' => $table_completed,
      ];
    }
  }
}

/**
 * Render supervision table.
 */
function _vu_rp_form_supervision_table_render($node, $is_current) {
  $supervisions = vu_rp_get_node_supervisions($node, $is_current);

  $header = [
    'No. of students',
    'Study level',
    'Your role',
  ];

  $rows = [];
  foreach ($supervisions as $record) {
    $rows[] = [
      $record['student_count'],
      $record['level'],
      $record['role'],
    ];
  }

  return !empty($rows) ? theme('table', [
    'header' => $header,
    'rows' => $rows,
    'sticky' => FALSE,
  ]) : '';
}
