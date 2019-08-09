<?php

/**
 * @file
 * Views module integration.
 */

/**
 * Implements hook_views_data().
 */
function vu_rp_views_data() {
  $data = [];

  $data['vu_rp_list_researchers']['table']['group'] = t('Researchers List');

  $data['vu_rp_list_researchers']['table']['base'] = [
    'title' => t('Researchers List'),
    'help' => t('List of researchers'),
  ];

  $data['vu_rp_list_researchers_custom']['table']['join'] = [
    '#global' => [],
  ];

  $data['vu_rp_list_researchers']['staff_id'] = [
    'group' => t('Researchers List'),
    'title' => t('Staff ID'),
    'help' => t("The user's Staff ID"),
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
    'relationship' => [
      'base' => 'cas_user',
      'base field' => 'cas_name',
      'handler' => 'views_handler_relationship',
      'label' => t('Staff ID'),
      'title' => t('Staff ID of the researcher'),
      'help' => t('Staff ID of the researcher'),
      'extra' => "CONCAT('e', cas_user_vu_rp_list_researchers.cas_name) = vu_rp_list_researchers.staff_id OR CONCAT('E', cas_user_vu_rp_list_researchers.cas_name) = vu_rp_list_researchers.staff_id",
      'extra type' => 'OR',
      'join_handler' => 'VuRpViewsJoin',
    ],
  ];

  $data['cas_user']['uid'] = [
    'title' => t('CAS user Id'),
    'help' => t('CAS user ID associated with a user.'),
    'field' => [
      'handler' => 'views_handler_field',
      'no group by' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
    ],
    'relationship' => [
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User ID of the user'),
      'title' => t('User ID of the user'),
      'help' => t('User ID of the user'),
    ],
  ];

  $data['vu_rp_list_researchers_custom']['status'] = [
    'title' => t('Status'),
    'group' => t('Researchers List'),
    'help' => t('Status of researcher profile'),
    'field' => [
      'handler' => 'VuRpViewsStatusHandler',
      'click sortable' => TRUE,
    ],
    'filter' => [
      'handler' => 'VuRpViewsStatusFilterHandler',
    ],
  ];

  $data['vu_rp_list_researchers_custom']['inactive'] = [
    'title' => t('Inactive user count'),
    'group' => t('Researchers List'),
    'help' => t('Inactive user count.'),
    'field' => [
      'handler' => 'VuRpViewsInactiveHandler',
    ],
  ];

  $data['vu_rp_list_researchers_custom']['optout'] = [
    'title' => t('Opted Out user count'),
    'group' => t('Researchers List'),
    'help' => t('Opted out user count'),
    'field' => [
      'handler' => 'VuRpViewsOptedOutHandler',
    ],
  ];

  // To show the pending reviews.
  $data['vu_rp_report_status']['table']['group'] = t('Researcher Profile Report Status');
  $data['vu_rp_report_status']['table']['join'] = [
    // Exist in all views.
    '#global' => [],
  ];

  $data['vu_rp_report_status']['rp_report_status'] = [
    'title' => t('Custom Report Status'),
    'help' => t('Custom Report Status for RP admin page.'),
    'field' => [
      'handler' => 'VuRpViewsReportStatusHandler',
    ],
    'filter' => [
      'handler' => 'VuRpViewsReportStatusFilterHandler',
    ],
  ];

  // To show the counts for drafts.
  $data['vu_rp_report_status']['drafts'] = [
    'title' => t('Drafts counts'),
    'group' => t('Researcher Profile Report Status'),
    'help' => t('Total count of Drafts State'),
    'field' => [
      'handler' => 'VuRpViewsDraftCountHandler',
    ],
  ];

  // To show the counts for needs review.
  $data['vu_rp_report_status']['needsReview'] = [
    'title' => t('Needs Review counts'),
    'group' => t('Researcher Profile Report Status'),
    'help' => t('Total count of Needs Review State'),
    'field' => [
      'handler' => 'VuRpViewsReviewCountHandler',
    ],
  ];

  // To show the counts for published.
  $data['vu_rp_report_status']['published'] = [
    'title' => t('Published counts'),
    'group' => t('Researcher Profile Report Status'),
    'help' => t('Total count of Published State'),
    'field' => [
      'handler' => 'VuRpViewsPublishCountHandler',
    ],
  ];

  // To show the counts for amended.
  $data['vu_rp_report_status']['amended'] = [
    'title' => t('Amended counts'),
    'group' => t('Researcher Profile Report Status'),
    'help' => t('Total count of Amended State'),
    'field' => [
      'handler' => 'VuRpViewsAmendedCountHandler',
    ],
  ];

  return $data;
}

/**
 * Implements hook_views_query_alter().
 */
function vu_rp_views_query_alter(&$view, &$query) {
  if ($view->name == 'researcher_profiles_summary') {
    $params = drupal_get_query_parameters();
    if (isset($params['rp_report_status'])) {
      // Filter by published profiles.
      if ($params['rp_report_status'] == 1) {
        $query->add_where('node_node_revision__workbench_moderation_node_history_is_cur', 'is_current', 1);
        $query->add_where('workbench_moderation_node_history_state', 'state', 'published');
      }
      // Filter by draft profiles.
      if ($params['rp_report_status'] == 2) {
        $query->add_where('node_node_revision__workbench_moderation_node_history_is_cur', 'is_current', 1);
        $query->add_where('workbench_moderation_node_history_state', 'state', 'draft');
      }
      // Filter by Amended & Awaiting Review profiles.
      if ($params['rp_report_status'] == 3) {
        $query->add_where('node_node_revision__workbench_moderation_node_history_is_cur', 'is_current', 0);
        $query->add_where('workbench_moderation_node_history_state', 'state', 'published');
      }
      // Filter by Awaiting Review profiles.
      if ($params['rp_report_status'] == 4) {
        $query->add_where('node_node_revision__workbench_moderation_node_history_is_cur', 'is_current', 1);
        $query->add_where('workbench_moderation_node_history_state', 'state', 'needs_review');
      }
    }
  }
}
