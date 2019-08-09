<?php

/**
 * @file
 * Views module integration.
 */

/**
 * Implements hook_views_data().
 */
function vu_core_views_data() {
  $data['search_api_index_course_index']['study_level_label'] = [
    'group' => t('VU'),
    'title' => t('Study level label'),
    'help' => t('A normalised unit study level label.'),
    'field' => [
      'type' => 'text',
      'handler' => 'entity_views_handler_field_text',
    ],
  ];

  $data['search_api_index_course_index']['course_majors'] = [
    'group' => t('VU'),
    'title' => t('Course majors'),
    'help' => t("Contains a summary of the course's majors/specialisations (if any)."),
    'field' => [
      'type' => 'text',
      'handler' => 'entity_views_handler_field_text',
    ],
  ];

  return $data;
}

/**
 * Implements hook_views_default_views_alter().
 */
function vu_core_views_default_views_alter(&$views) {
  // Alter the access permissions for the Fieldable Panels Panes revisions view.
  if (isset($views['fieldable_pane_entity_revisions'])) {
    $views['fieldable_pane_entity_revisions']->display['default']->display_options['access']['perm'] = 'edit fieldable pane_featured_content';
  }
  // Alter access for VBO field in a system view.
  if (isset($views['admin_views_file'])) {
    $views['admin_views_file']->display['default']->display_options['fields']['views_bulk_operations']['vbo_settings']['field_access'] = [
      3 => '3',
      2 => 0,
      26 => 0,
      21 => 0,
      11 => 0,
      16 => 16,
      36 => 0,
      41 => 0,
      31 => 0,
      46 => 0,
      51 => 0,
      56 => 0,
      57 => 0,
    ];
  }
}

/**
 * Implements hook_views_pre_view().
 */
function vu_core_views_pre_view(&$view, &$display_id, &$args) {
  // Send the correct VID to the view so it can find it's content.
  if ($view->name == 'vu_courses_related' && $view->current_display == 'block') {
    $node = menu_get_object();
    $view->args[0] = $node->vid;
  }

  if ('success_stories' == $view->name) {
    // The taxonomy filters have to be set via this method because the
    // tids of the exported view don't match up across different instances
    // of the site.
    $map = [
      'block' => 'Student',
      'block_1' => 'Staff',
      'block_2' => 'Partners & Projects',
      'block_3' => 'Employer Testimonials',
      'block_4' => 'VU English',
    ];
    $term = isset($map[$display_id]) ? $map[$display_id] : 'Student';
    // Find the tid for the relevant term.
    $terms = taxonomy_get_term_by_name($term, 'success_categories');
    $term_obj = $terms ? array_shift($terms) : NULL;
    if (isset($term_obj->tid)) {
      $tid = $term_obj->tid;
      // Get the current filters.
      $view_filters = $view->display_handler->get_option('filters');
      // Remove the erroneous taxonomy id from the filter.
      unset($view_filters['field_success_categories_tid']['value']);
      // Construct the filter array element using the correct tid.
      $view_filters['field_success_categories_tid']['value'][$tid] = (string) $tid;
      // Add the new filter element to the view filter list.
      $view->display_handler->override_option('filters', $view_filters);
    }
  }

  if ('course_fees' == $view->name) {
    $request_params = drupal_get_query_parameters();

    // Get the current filters.
    $view_filters = $view->display_handler->get_option('filters');

    // Apply search query against course code and title.
    if (isset($request_params['query'])) {
      $query = trim($request_params['query']);
      $view_filters['field_unit_code_value']['value'] = $query;
      $view_filters['title']['value'] = $query;
    }
    else {
      unset($view_filters['field_unit_code_value']);
    }

    // Filter by "international" flag.
    if (isset($request_params['international'])) {
      $view_filters['field_international_value']['value'] = [
        $request_params['international'] => $request_params['international'],
      ];
    }
    else {
      unset($view_filters['field_international_value']);
    }

    // Filter by fee type, e.g. "Full fee", "Commonwealth-supported place".
    if (isset($request_params['feeType'])) {
      $view_filters['field_fee_type_tid']['value'] = [
        $request_params['feeType'] => $request_params['feeType'],
      ];
    }
    else {
      unset($view_filters['field_fee_type_tid']);
    }

    // Filter by fee year.
    if (isset($request_params['feeYear'])) {
      $view_filters['field_year_value']['value']['value'] = $request_params['feeYear'];
    }
    else {
      unset($view_filters['field_year_value']);
    }

    // Filter by sector, i.e. HE, VE.
    if (isset($request_params['sector'])) {
      $view_filters['field_sector_value']['value'] = [
        $request_params['sector'] => $request_params['sector'],
      ];
    }
    else {
      unset($view_filters['field_sector_value']);
    }

    // Filter by cohort year.
    if (isset($request_params['cohortYear'])) {
      $view_filters['field_cohort_year_value']['value']['value'] = $request_params['cohortYear'];
    }
    else {
      unset($view_filters['field_cohort_year_value']);
    }

    // Add the new filter element to the view filter list.
    $view->display_handler->override_option('filters', $view_filters);
  }

  if ('unit_fees' == $view->name) {
    $request_params = drupal_get_query_parameters();

    // Get the current filters.
    $view_filters = $view->display_handler->get_option('filters');

    // Apply search query against course code and title.
    if (isset($request_params['query'])) {
      $query = trim($request_params['query']);
      $view_filters['field_unit_code_value']['value'] = $query;
      $view_filters['title']['value'] = $query;
    }
    else {
      unset($view_filters['field_unit_code_value']);
    }

    // Filter by "international" flag.
    if (isset($request_params['international'])) {
      $view_filters['field_international_value']['value'] = [
        $request_params['international'] => $request_params['international'],
      ];
    }
    else {
      unset($view_filters['field_international_value']);
    }

    // Filter by fee type, e.g. "Full fee", "Commonwealth-supported place".
    if (isset($request_params['feeType'])) {
      $view_filters['field_fee_type_tid']['value'] = [
        $request_params['feeType'] => $request_params['feeType'],
      ];
    }
    else {
      unset($view_filters['field_fee_type_tid']);
    }

    // Filter by fee year.
    if (isset($request_params['feeYear'])) {
      $view_filters['field_year_value']['value']['value'] = $request_params['feeYear'];
    }
    else {
      unset($view_filters['field_year_value']);
    }

    // Add the new filter element to the view filter list.
    $view->display_handler->override_option('filters', $view_filters);
  }
}

/**
 * Implements hook_views_pre_build().
 */
function vu_core_views_pre_build(&$view) {

  switch ($view->name) {

    case 'events_listing':

      if ($view->current_display === 'promoted_events_list_component') {
        vu_core_views_pre_build_update_common($view, 'vu_events');
      }
      if (!user_is_anonymous()) {
        unset($_SESSION['vu_events']);
      }
      break;

    case 'news_listing':

      if ($view->current_display === 'victory_featured_news_media_landing') {
        vu_core_views_pre_build_update_common($view, 'vu_news');
      }
      unset($_SESSION['vu_news']);
      break;
  }
}

/**
 * Helper function to update common values.
 */
function vu_core_views_pre_build_update_common($view, $component) {

  if (isset($_SESSION[$component]['args'])) {
    $view->set_arguments($_SESSION[$component]['args']);
  }
  if (isset($_SESSION[$component]['more']['url'])) {
    $view->display_handler->set_option('link_url', $_SESSION[$component]['more']['url']);
    unset($_SESSION[$component]['more']['url']);
  }
  if (isset($_SESSION[$component]['btn_more_text'])) {
    $view->display_handler->set_option('use_more_text', $_SESSION[$component]['btn_more_text']);
    unset($_SESSION[$component]['btn_more_text']);
  }
  // Add arguments for contextual filter.
  if ($view->name == 'important_dates_list' && $view->current_display == 'block') {
    if (isset($_SESSION['vu_important_dates']['args'])) {
      $view->set_arguments($_SESSION['vu_important_dates']['args']);
    }
    unset($_SESSION['vu_important_dates']);
  }
}

/**
 * Implements hook_views_query_alter().
 */
function vu_core_views_query_alter(&$view, &$query) {
  // Subquery to prevent duplicate events.
  if ($view->name == 'events_listing' && $view->current_display == 'promoted_events_list_component') {
    $args = $view->args;
    if (!empty($args)) {
      $sub_query = db_select('field_data_field_audience', 'field_data_field_audience');
      $sub_query->fields('field_data_field_audience');
      $sub_query->condition('bundle', 'events', '=');
      $sub_query->condition('deleted', 0, '=');
      $sub_query->condition('entity_type', 'node', '=');
      $sub_query->condition('field_audience_tid', $args, 'IN');
      $sub_query->groupBy('entity_id');

      $join = new views_join();
      $join->definition = [
        'table formula' => $sub_query,
        'left_field' => 'nid',
        'field' => 'entity_id',
        'left_table' => 'node',
      ];
      $join->left_table = 'node';
      $join->field = 'entity_id';
      $join->left_field = 'nid';
      $join->type = 'LEFT';

      $view->query->table_queue['field_data_field_audience'] = [
        'alias' => 'field_data_field_audience',
        'table' => $sub_query,
        'relationship' => 'node',
        'join' => $join,
      ];

      $join = new views_join();
      $join->table = 'taxonomy_term_data';
      $join->field = 'tid';
      $join->left_table = 'field_data_field_audience';
      $join->left_field = 'field_audience_tid';
      $join->type = 'LEFT';
      $query->add_relationship('taxonomy_term_data_field_data_field_audience', $join, 'taxonomy_term_data');
      // Custom sort criteria.
      $query->orderby[0] = [
        'field' => '
          CASE
            WHEN (field_data_field_audience.field_audience_tid IS NOT NULL) AND (node.sticky = \'1\') THEN 1
            WHEN (field_data_field_audience.field_audience_tid IS NOT NULL) AND (node.sticky = \'0\') THEN 2
            WHEN (field_data_field_audience.field_audience_tid IS NULL) AND (node.sticky = \'1\') THEN 3
            ELSE 4
          END
        ',
        'direction' => 'ASC',
      ];
    }
  }

  // Custom sort order for news components.
  if ($view->name == 'news_listing' && $view->current_display == 'victory_featured_news_media_landing') {
    $args = $view->args;
    if (!empty($args)) {
      $sub_query = db_select('field_data_field_news_audience', 'field_data_field_news_audience');
      $sub_query->fields('field_data_field_news_audience');
      $sub_query->condition('bundle', 'news', '=');
      $sub_query->condition('deleted', 0, '=');
      $sub_query->condition('entity_type', 'node', '=');
      $sub_query->condition('field_news_audience_tid', $args, 'IN');
      $sub_query->groupBy('entity_id');

      $join = new views_join();
      $join->definition = [
        'table formula' => $sub_query,
        'left_field' => 'nid',
        'field' => 'entity_id',
        'left_table' => 'node',
      ];
      $join->left_table = 'node';
      $join->field = 'entity_id';
      $join->left_field = 'nid';
      $join->type = 'LEFT';

      $view->query->table_queue['field_data_field_news_audience'] = [
        'alias' => 'field_data_field_news_audience',
        'table' => $sub_query,
        'relationship' => 'node',
        'join' => $join,
      ];

      $join = new views_join();
      $join->table = 'taxonomy_term_data';
      $join->field = 'tid';
      $join->left_table = 'field_data_field_news_audience';
      $join->left_field = 'field_news_audience_tid';
      $join->type = 'LEFT';
      $query->add_relationship('taxonomy_term_data_field_data_field_news_audience', $join, 'taxonomy_term_data');

      // Custom sort criteria.
      array_unshift($query->orderby,
        [
          'field' => '
            CASE
              WHEN (field_data_field_news_audience.field_news_audience_tid IS NOT NULL) AND (node.sticky = \'1\') THEN 1
              WHEN (field_data_field_news_audience.field_news_audience_tid IS NOT NULL) AND (node.sticky = \'0\') THEN 2
              WHEN (field_data_field_news_audience.field_news_audience_tid IS NULL) AND (node.sticky = \'1\') THEN 3
              ELSE 4
            END
          ',
          'direction' => 'ASC',
        ]
      );
    }
  }

  // Add a subquery to show only the first (closest) event date.
  if ($view->name == 'events_listing' && in_array($view->current_display, ['promoted_events_list', 'promoted_events_list_component'])) {
    $sub_query = db_select('field_data_field_date', 'd');
    $sub_query->addField('d', 'revision_id', 'vid');
    $sub_query->addExpression('MIN(field_date_value)', 'field_date_value');
    $sub_query->addField('d', 'field_date_value2');
    $sub_query->condition('bundle', 'events', '=');
    $sub_query->where('(field_date_value >= UNIX_TIMESTAMP() OR (field_date_value2 > unix_timestamp(concat(CURRENT_DATE, \' 23:59:59\')) AND d.delta = 0))');
    $sub_query->groupBy('vid');

    $join = new views_join();
    $join->definition = [
      'table formula' => $sub_query,
      'left_field' => 'vid',
      'field' => 'vid',
      'left_table' => 'node',
    ];
    $join->left_table = 'node';
    $join->field = 'vid';
    $join->left_field = 'vid';
    $join->type = 'INNER';

    $view->query->table_queue['field_data_field_date'] = [
      'alias' => 'd',
      'table' => $sub_query,
      'relationship' => 'node',
      'join' => $join,
    ];

    $query->add_field('d', 'field_date_value');
    $query->add_field('d', 'field_date_value2');
    $query->add_orderby('d', 'field_date_value', 'ASC');
  }

  if ($view->name == 'important_dates_list' && $view->current_display == 'block') {
    $query->orderby = [
      [
        'field' => 'CASE WHEN node_field_data_field_event_entity_ref__field_data_field_date.field_date_value THEN node_field_data_field_event_entity_ref__field_data_field_date.field_date_value ELSE field_data_field_event_date.field_event_date_value END',
        'direction' => 'ASC',
      ],
    ];
  }

  // Custom query for Administration: Content Revisions view.
  if ($view->name != VU_VIEWS_CONTENT_REVISIONS) {
    return;
  }

  if (!empty($query->table_queue['node_node_revision']['join'])) {
    // Change node revision join field from vid to nid.
    $query->table_queue['node_node_revision']['join']->left_field = 'nid';
    $query->table_queue['node_node_revision']['join']->field = 'nid';
  }

  // This is required to fix 'Column is ambiguous' mysql error.
  $query->fields['type']['field'] = 'node_node_revision.type';

  $join_vid = new views_join();
  $join_vid->table = 'node';
  $join_vid->field = 'vid';
  $join_vid->left_table = 'node_revision';
  $join_vid->left_field = 'vid';
  $join_vid->type = 'LEFT';

  // Add 'node_node_revision_vid' table to the query.
  // This table joins with node_revision by vid.
  $query->table_queue['node_node_revision_vid'] = [
    'alias' => 'node_node_revision_vid',
    'table' => 'node',
    'relationship' => 'node_revision',
    'join' => $join_vid,
  ];

  // Sub-query to get the most recent revision of each node.
  $sub_query_table = db_select('node_revision', 'nr');
  $sub_query_table->fields('nr');
  $sub_query_table->orderBy('nid', 'DESC');
  $sub_query_table->orderBy('timestamp', 'DESC');

  // Join the above sub-query with node_revision.
  $sub_query_join = new views_join();
  $sub_query_join->definition = [
    'table formula' => $sub_query_table,
    'field' => 'vid',
    'left_table' => 'node_revision',
    'left_field' => 'vid',
  ];
  $sub_query_join->left_table = 'node_revision';
  $sub_query_join->field = 'vid';
  $sub_query_join->left_field = 'vid';
  $sub_query_join->type = 'INNER';

  // Add the table to the query.
  $query->table_queue['most_recent_revisions'] = [
    'alias' => 'most_recent_revisions',
    'table' => $sub_query_table,
    'relationship' => 'node_revision',
    'join' => $sub_query_join,
  ];

  // Group by most_recent_revisions.nid.
  $query->add_field('most_recent_revisions', 'nid', 'most_recent_revisions_nid', ['function' => 'groupby']);
  $query->add_groupby('most_recent_revisions.nid');
  $query->add_orderby('most_recent_revisions', 'timestamp', 'DESC');

  // Join with node revision to get pending revisions.
  $pending_revision_join = new views_join();
  $pending_revision_join->table = 'node_revision';
  $pending_revision_join->field = 'nid';
  $pending_revision_join->left_table = 'node_node_revision_vid';
  $pending_revision_join->left_field = 'nid';
  $pending_revision_join->type = 'LEFT';
  $pending_revision_join->extra = '((pending_node_revisions.vid != node_node_revision_vid.vid AND pending_node_revisions.timestamp > node_revision.timestamp) OR (pending_node_revisions.vid > node_node_revision_vid.vid AND !node_node_revision_vid.status))';

  $query->add_field('pending_node_revisions', 'vid', 'pending_rev_count', ['count' => TRUE]);
  $query->add_relationship('pending_node_revisions', $pending_revision_join, 'node_node_revision_vid');
}

/**
 * Implements hook_preprocess_HOOK().
 *
 * See template for list of available variables.
 *
 * @see views-view-list--courses-lists--landing_course-browser-block.tpl.php
 *
 * @ingroup theme_preprocess
 */
function vu_core_preprocess_views_view_list(&$variables) {
  if ('courses_lists' == $variables['view']->name && 'landing_course_browser_block' == $variables['view']->current_display) {
    $current_path = drupal_get_path_alias();
    if ($current_path == VUMAIN_URLS_INTERNATIONAL_STUDENTS) {
      $variables['rows'] = preg_replace('/href="(.*?)"/', 'href="$1?audience=international"', $variables['rows']);
    }
  }

  $view = $variables['view'];

  if ($view->name == 'course_search') {
    $params = drupal_get_query_parameters();
    foreach ($variables['rows'] as $id => $row) {
      $course = $view->result[$id]->entity;
      if (!is_object($course)) {
        $course = node_load($course);
      }
      // Add b3intake class to wrapper if the course is available.
      if ($params['iam'] != 'non-resident' && $course->type == 'courses' && vu_course_index_is_b3intake($course) && !vu_course_index_is_b3intake_closed($course)) {
        $variables['classes_array'][$id] .= 'b3intake';
      }
    }
  }
}

/**
 * Implements hook_field_views_data_alter().
 */
function vu_core_views_data_alter(&$data) {
  // Override the default VBO field handler to allow access control.
  foreach (entity_get_info() as $entity_type => $info) {
    if (isset($data['views_entity_' . $entity_type]['views_bulk_operations']['field']['handler'])) {
      $data['views_entity_' . $entity_type]['views_bulk_operations']['field']['handler'] = 'VuCoreVboFieldAccessHandler';
    }
    if (isset($info['revision table']) && isset($data[$info['revision table']]['views_bulk_operations']['field']['handler'])) {
      $data[$info['revision table']]['views_bulk_operations']['field']['handler'] = 'VuCoreVboFieldAccessHandler';
    }
  }
}
