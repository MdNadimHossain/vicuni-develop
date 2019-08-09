<?php

/**
 * @file
 * Code for views.
 */

/**
 * Implements hook_views_data().
 */
function vu_rp_log_views_data() {
  $data['vu_rp_log']['table']['group'] = t('Researchers Profile Logs');

  $data['vu_rp_log']['table']['base'] = [
    'title' => t('Researchers Profile Logs'),
    'help' => t('List of log messages'),
  ];

  $data['vu_rp_log']['event'] = [
    'group' => t('Researchers Profile Logs'),
    'title' => t('Event'),
    'help' => t('Researchers log event'),
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'handler' => 'VuRpLogEventFilterHandler',
    ],
  ];

  $data['vu_rp_log']['severity'] = [
    'group' => t('Researchers Profile Logs'),
    'title' => t('Severity'),
    'help' => t('Researchers log severity'),
    'field' => [
      'handler' => 'VuRpLogSeverityFieldHandler',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'handler' => 'VuRpLogSeverityFilterHandler',
    ],
  ];

  $data['vu_rp_log']['timestamp'] = [
    'group' => t('Researchers Profile Logs'),
    'title' => t('Date'),
    'help' => t('Researchers log timestamp'),
    'field' => [
      'handler' => 'VuRpLogTimestampFieldHandler',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['vu_rp_log']['message'] = [
    'group' => t('Researchers Profile Logs'),
    'title' => t('Message'),
    'help' => t('Researchers log message'),
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
    ],
  ];

  $data['vu_rp_log']['entity_id'] = [
    'group' => t('Researchers Profile Logs'),
    'title' => t('Entity'),
    'help' => t('Researchers log entity'),
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
    ],
  ];

  $data['vu_rp_log']['id'] = [
    'group' => t('Researchers Profile Logs'),
    'title' => t('ID'),
    'help' => t('Researchers log ID'),
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
    ],
  ];

  return $data;
}

/**
 * Implements hook_preprocess_views_view().
 */
function vu_rp_log_preprocess_views_view(&$variables) {
  if ($variables['view']->name == 'researcher_profile_logs') {
    // Wrap exposed filters in a fieldset.
    if ($variables['exposed']) {
      drupal_add_js('misc/form.js');
      drupal_add_js('misc/collapse.js');
      // Default state.
      $collapsed = TRUE;
      $class = ['collapsible', 'collapsed'];

      $params = drupal_get_query_parameters();
      if (count($params)) {
        // If parameters are available, assume they are exposed filters.
        $collapsed = FALSE;
        $class = ['collapsible'];
      }

      $fieldset['element'] = [
        '#title' => t('Filter Log messages'),
        '#collapsible' => TRUE,
        '#collapsed' => $collapsed,
        '#attributes' => ['class' => $class],
        '#children' => $variables['exposed'],
      ];

      $variables['exposed'] = theme('fieldset', $fieldset);
    }

    if (!user_access('clear researcher profile api log')) {
      $variables['header'] = '';
    }
  }
}
