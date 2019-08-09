<?php
/**
 * @file
 * vu_rp.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vu_rp_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'researcher_profiles_summary';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Researcher profiles summary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Researcher profiles summary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Workbench Moderation: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content: Staff ID */
  $handler->display->display_options['fields']['field_rpa_staff_id']['id'] = 'field_rpa_staff_id';
  $handler->display->display_options['fields']['field_rpa_staff_id']['table'] = 'field_data_field_rpa_staff_id';
  $handler->display->display_options['fields']['field_rpa_staff_id']['field'] = 'field_rpa_staff_id';
  $handler->display->display_options['fields']['field_rpa_staff_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_rpa_staff_id']['label'] = 'STAFF ID';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_rpa_first_name']['id'] = 'field_rpa_first_name';
  $handler->display->display_options['fields']['field_rpa_first_name']['table'] = 'field_data_field_rpa_first_name';
  $handler->display->display_options['fields']['field_rpa_first_name']['field'] = 'field_rpa_first_name';
  $handler->display->display_options['fields']['field_rpa_first_name']['relationship'] = 'vid';
  /* Field: Content: 11. Which VU research institute do you belong to? */
  $handler->display->display_options['fields']['field_rp_institute_primary']['id'] = 'field_rp_institute_primary';
  $handler->display->display_options['fields']['field_rp_institute_primary']['table'] = 'field_data_field_rp_institute_primary';
  $handler->display->display_options['fields']['field_rp_institute_primary']['field'] = 'field_rp_institute_primary';
  $handler->display->display_options['fields']['field_rp_institute_primary']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_rp_institute_primary']['label'] = 'RESEARCH INSTITUTE';
  $handler->display->display_options['fields']['field_rp_institute_primary']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'vid';
  $handler->display->display_options['fields']['changed']['label'] = 'LAST UPDATED';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  /* Filter criterion: Content: First name (field_rp_first_name) */
  $handler->display->display_options['filters']['field_rp_first_name_value']['id'] = 'field_rp_first_name_value';
  $handler->display->display_options['filters']['field_rp_first_name_value']['table'] = 'field_data_field_rp_first_name';
  $handler->display->display_options['filters']['field_rp_first_name_value']['field'] = 'field_rp_first_name_value';
  $handler->display->display_options['filters']['field_rp_first_name_value']['relationship'] = 'vid';
  /* Filter criterion: Content: Last name (field_rp_last_name) */
  $handler->display->display_options['filters']['field_rp_last_name_value']['id'] = 'field_rp_last_name_value';
  $handler->display->display_options['filters']['field_rp_last_name_value']['table'] = 'field_data_field_rp_last_name';
  $handler->display->display_options['filters']['field_rp_last_name_value']['field'] = 'field_rp_last_name_value';
  $handler->display->display_options['filters']['field_rp_last_name_value']['relationship'] = 'vid';

  /* Display: Researcher Profile Summary */
  $handler = $view->new_display('block', 'Researcher Profile Summary', 'researcher_profiles_summary');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h5 class="people-summary">Researcher profiles summary</h5>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(Workbench Moderation: State) */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['group_type'] = 'count';
  $handler->display->display_options['fields']['state']['label'] = 'STATUS';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  /* Field: Researcher Profile Report Status: Drafts counts */
  $handler->display->display_options['fields']['drafts']['id'] = 'drafts';
  $handler->display->display_options['fields']['drafts']['table'] = 'vu_rp_report_status';
  $handler->display->display_options['fields']['drafts']['field'] = 'drafts';
  $handler->display->display_options['fields']['drafts']['exclude'] = TRUE;
  /* Field: Researcher Profile Report Status: Amended counts */
  $handler->display->display_options['fields']['amended']['id'] = 'amended';
  $handler->display->display_options['fields']['amended']['table'] = 'vu_rp_report_status';
  $handler->display->display_options['fields']['amended']['field'] = 'amended';
  $handler->display->display_options['fields']['amended']['exclude'] = TRUE;
  /* Field: Researcher Profile Report Status: Needs Review counts */
  $handler->display->display_options['fields']['needsReview']['id'] = 'needsReview';
  $handler->display->display_options['fields']['needsReview']['table'] = 'vu_rp_report_status';
  $handler->display->display_options['fields']['needsReview']['field'] = 'needsReview';
  $handler->display->display_options['fields']['needsReview']['exclude'] = TRUE;
  /* Field: Researcher Profile Report Status: Published counts */
  $handler->display->display_options['fields']['published']['id'] = 'published';
  $handler->display->display_options['fields']['published']['table'] = 'vu_rp_report_status';
  $handler->display->display_options['fields']['published']['field'] = 'published';
  $handler->display->display_options['fields']['published']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'STATUS';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<table class="rp_report_count_status_col">
  <tr>
    <td>Drafts</td>
  </tr>
  <tr>
    <td>Needs Review</td>
  </tr>
  <tr>
    <td>Published</td>
  </tr>
  <tr>
    <td>Amended & Awaiting Review</td>
  </tr>
</table>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'NUMBER OF PROFILES';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<table class="rp_report_count_status_col">
  <tr>
    <td>[drafts]</td>
  </tr>
  <tr>
    <td>[needsReview]</td>
  </tr>
  <tr>
    <td>[published]</td>
  </tr>
  <tr>
    <td>[amended]</td>
  </tr>
</table>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'ACTIONS';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<table class="rp_report_count_status_col">
  <tr>
    <td><a href="/admin/workbench/view-researcher-profile?title=&tid=All&rp_report_status=2&items_per_page=25">View all</a></td>
  </tr>
  <tr>
    <td><a href="/admin/workbench/view-researcher-profile?title=&tid=All&rp_report_status=4&items_per_page=25">View all</a></td>
  </tr>
  <tr>
    <td><a href="/admin/workbench/view-researcher-profile?title=&tid=All&rp_report_status=1&items_per_page=25">View all</a></td>
  </tr>
  <tr>
    <td><a href="/admin/workbench/view-researcher-profile?title=&tid=All&rp_report_status=3&items_per_page=25">View all</a></td>
  </tr>
</table>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['block_description'] = 'researcher profile summary';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_rpa_staff_id' => 'field_rpa_staff_id',
    'title' => 'title',
    'field_rp_institute_primary' => 'field_rp_institute_primary',
    'changed' => 'changed',
    'name' => 'name',
    'state' => 'state',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'field_rpa_staff_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rp_institute_primary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Staff ID */
  $handler->display->display_options['fields']['field_rpa_staff_id']['id'] = 'field_rpa_staff_id';
  $handler->display->display_options['fields']['field_rpa_staff_id']['table'] = 'field_data_field_rpa_staff_id';
  $handler->display->display_options['fields']['field_rpa_staff_id']['field'] = 'field_rpa_staff_id';
  $handler->display->display_options['fields']['field_rpa_staff_id']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_rpa_staff_id']['label'] = 'STAFF ID';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  /* Field: Content: 11. Which VU research institute do you belong to? */
  $handler->display->display_options['fields']['field_rp_institute_primary']['id'] = 'field_rp_institute_primary';
  $handler->display->display_options['fields']['field_rp_institute_primary']['table'] = 'field_data_field_rp_institute_primary';
  $handler->display->display_options['fields']['field_rp_institute_primary']['field'] = 'field_rp_institute_primary';
  $handler->display->display_options['fields']['field_rp_institute_primary']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_rp_institute_primary']['label'] = 'RESEARCH INSTITUTE';
  $handler->display->display_options['fields']['field_rp_institute_primary']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'vid';
  $handler->display->display_options['fields']['changed']['label'] = 'LAST UPDATED';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'REVISED BY';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'STATUS';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Researcher Profile Report Status: Custom Report Status */
  $handler->display->display_options['fields']['rp_report_status']['id'] = 'rp_report_status';
  $handler->display->display_options['fields']['rp_report_status']['table'] = 'vu_rp_report_status';
  $handler->display->display_options['fields']['rp_report_status']['field'] = 'rp_report_status';
  $handler->display->display_options['fields']['rp_report_status']['label'] = 'REPORT STATUS';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'TASK';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Action';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'vid';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    26 => 0,
    21 => 0,
    11 => 0,
    16 => 0,
    36 => 0,
    41 => 0,
    3 => 0,
    31 => 0,
    42 => 0,
    43 => 0,
    44 => 0,
    45 => 0,
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'RESEARCH INSTITUTE';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    26 => 0,
    21 => 0,
    11 => 0,
    16 => 0,
    36 => 0,
    41 => 0,
    3 => 0,
    31 => 0,
    42 => 0,
    43 => 0,
    44 => 0,
    45 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'research_institutes';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  /* Filter criterion: Researcher Profile Report Status: Custom Report Status */
  $handler->display->display_options['filters']['rp_report_status']['id'] = 'rp_report_status';
  $handler->display->display_options['filters']['rp_report_status']['table'] = 'vu_rp_report_status';
  $handler->display->display_options['filters']['rp_report_status']['field'] = 'rp_report_status';
  $handler->display->display_options['filters']['rp_report_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rp_report_status']['expose']['operator_id'] = 'rp_report_status_op';
  $handler->display->display_options['filters']['rp_report_status']['expose']['label'] = 'Custom Report Status';
  $handler->display->display_options['filters']['rp_report_status']['expose']['operator'] = 'rp_report_status_op';
  $handler->display->display_options['filters']['rp_report_status']['expose']['identifier'] = 'rp_report_status';
  $handler->display->display_options['filters']['rp_report_status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['rp_report_status']['group_info']['label'] = 'STATUS';
  $handler->display->display_options['filters']['rp_report_status']['group_info']['identifier'] = 'rp_report_status';
  $handler->display->display_options['filters']['rp_report_status']['group_info']['remember'] = 1;
  $handler->display->display_options['filters']['rp_report_status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Published',
      'operator' => 'or',
      'value' => array(
        'status' => '1',
      ),
    ),
    2 => array(
      'title' => 'Draft',
      'operator' => 'or',
      'value' => array(
        'status' => '2',
      ),
    ),
    3 => array(
      'title' => 'Amended & Awaiting Review',
      'operator' => 'or',
      'value' => array(
        'status' => '3',
      ),
    ),
    4 => array(
      'title' => 'Awaiting Review',
      'operator' => 'or',
      'value' => array(
        'status' => '4',
      ),
    ),
  );
  $handler->display->display_options['path'] = 'admin/workbench/view-researcher-profile';
  $export['researcher_profiles_summary'] = $view;

  $view = new view();
  $view->name = 'researchers_profile_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_researcher_profiles';
  $view->human_name = 'Researchers Profile search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find a Researcher';
  $handler->display->display_options['css_class'] = 'section';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list container';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block']['id'] = 'block';
  $handler->display->display_options['header']['block']['table'] = 'views';
  $handler->display->display_options['header']['block']['field'] = 'block';
  $handler->display->display_options['header']['block']['empty'] = TRUE;
  $handler->display->display_options['header']['block']['block_to_insert'] = 'vu_rp:researcher_profile_search';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<div class="search-separator"></div>
<div class="count container">
 <div class="total-number"><b>@total Researchers found</b></div></br>
   <span class="currently-showing">Showing @start - @end of @total</span>
</div>';
  /* No results behavior: Search: Spellcheck */
  $handler->display->display_options['empty']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['empty']['search_api_spellcheck']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['empty']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['empty']['search_api_spellcheck']['empty'] = TRUE;
  /* Field: Indexed Content: Upload photo */
  $handler->display->display_options['fields']['field_rp_photo']['id'] = 'field_rp_photo';
  $handler->display->display_options['fields']['field_rp_photo']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_rp_photo']['field'] = 'field_rp_photo';
  $handler->display->display_options['fields']['field_rp_photo']['label'] = '';
  $handler->display->display_options['fields']['field_rp_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rp_photo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_rp_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_rp_photo']['settings'] = array(
    'image_style' => 'rp_title_photo',
    'image_link' => '',
  );
  /* Field: Indexed Content: Staff picture */
  $handler->display->display_options['fields']['field_staff_picture']['id'] = 'field_staff_picture';
  $handler->display->display_options['fields']['field_staff_picture']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_staff_picture']['field'] = 'field_staff_picture';
  $handler->display->display_options['fields']['field_staff_picture']['label'] = '';
  $handler->display->display_options['fields']['field_staff_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_picture']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_staff_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_staff_picture']['settings'] = array(
    'image_style' => 'staff_detail_picture_350w',
    'image_link' => '',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Content: Supervisor Unknown */
  $handler->display->display_options['fields']['supervisor_unknown']['id'] = 'supervisor_unknown';
  $handler->display->display_options['fields']['supervisor_unknown']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['supervisor_unknown']['field'] = 'supervisor_unknown';
  $handler->display->display_options['fields']['supervisor_unknown']['label'] = '';
  $handler->display->display_options['fields']['supervisor_unknown']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['supervisor_unknown']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['supervisor_unknown']['type'] = 'custom';
  $handler->display->display_options['fields']['supervisor_unknown']['type_custom_true'] = '<i class="fa fa-question"></i> Supervisor availability unknown';
  $handler->display->display_options['fields']['supervisor_unknown']['not'] = 0;
  $handler->display->display_options['fields']['supervisor_unknown']['link_to_entity'] = 0;
  /* Field: Indexed Content: 1. Are you available to supervise research students at VU? */
  $handler->display->display_options['fields']['field_rp_sup_is_available']['id'] = 'field_rp_sup_is_available';
  $handler->display->display_options['fields']['field_rp_sup_is_available']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_rp_sup_is_available']['field'] = 'field_rp_sup_is_available';
  $handler->display->display_options['fields']['field_rp_sup_is_available']['label'] = '';
  $handler->display->display_options['fields']['field_rp_sup_is_available']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rp_sup_is_available']['type'] = 'custom_formatters_research_profile_flags';
  /* Field: Indexed Content: Media ready? */
  $handler->display->display_options['fields']['field_media_ready']['id'] = 'field_media_ready';
  $handler->display->display_options['fields']['field_media_ready']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_media_ready']['field'] = 'field_media_ready';
  $handler->display->display_options['fields']['field_media_ready']['label'] = '';
  $handler->display->display_options['fields']['field_media_ready']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_ready']['type'] = 'custom_formatters_staff_profiles_media_flag';
  /* Field: Indexed Content: 4. Are you available for media queries? */
  $handler->display->display_options['fields']['field_rp_available_to_media']['id'] = 'field_rp_available_to_media';
  $handler->display->display_options['fields']['field_rp_available_to_media']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_rp_available_to_media']['field'] = 'field_rp_available_to_media';
  $handler->display->display_options['fields']['field_rp_available_to_media']['label'] = '';
  $handler->display->display_options['fields']['field_rp_available_to_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rp_available_to_media']['type'] = 'custom_formatters_staff_profiles_media_flag';
  /* Field: Indexed Content: Areas of expertise */
  $handler->display->display_options['fields']['field_rp_expertise']['id'] = 'field_rp_expertise';
  $handler->display->display_options['fields']['field_rp_expertise']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_rp_expertise']['field'] = 'field_rp_expertise';
  $handler->display->display_options['fields']['field_rp_expertise']['label'] = '';
  $handler->display->display_options['fields']['field_rp_expertise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rp_expertise']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_rp_expertise']['list']['mode'] = 'list';
  $handler->display->display_options['fields']['field_rp_expertise']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_rp_expertise']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_rp_expertise']['bypass_access'] = 0;
  /* Field: Indexed Content: Areas of expertise */
  $handler->display->display_options['fields']['field_staff_expertise']['id'] = 'field_staff_expertise';
  $handler->display->display_options['fields']['field_staff_expertise']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_staff_expertise']['field'] = 'field_staff_expertise';
  $handler->display->display_options['fields']['field_staff_expertise']['label'] = '';
  $handler->display->display_options['fields']['field_staff_expertise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_expertise']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_staff_expertise']['list']['mode'] = 'list';
  $handler->display->display_options['fields']['field_staff_expertise']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_staff_expertise']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_staff_expertise']['bypass_access'] = 0;
  /* Field: Indexed Content: 3. Provide a short description of you */
  $handler->display->display_options['fields']['field_rp_shorter_biography']['id'] = 'field_rp_shorter_biography';
  $handler->display->display_options['fields']['field_rp_shorter_biography']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_rp_shorter_biography']['field'] = 'field_rp_shorter_biography';
  $handler->display->display_options['fields']['field_rp_shorter_biography']['label'] = '';
  $handler->display->display_options['fields']['field_rp_shorter_biography']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Staff search snippet */
  $handler->display->display_options['fields']['field_staff_search_snippet']['id'] = 'field_staff_search_snippet';
  $handler->display->display_options['fields']['field_staff_search_snippet']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_staff_search_snippet']['field'] = 'field_staff_search_snippet';
  $handler->display->display_options['fields']['field_staff_search_snippet']['label'] = '';
  $handler->display->display_options['fields']['field_staff_search_snippet']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Content: First name */
  $handler->display->display_options['fields']['field_rpa_first_name']['id'] = 'field_rpa_first_name';
  $handler->display->display_options['fields']['field_rpa_first_name']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['fields']['field_rpa_first_name']['field'] = 'field_rpa_first_name';
  $handler->display->display_options['fields']['field_rpa_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_rpa_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_rpa_first_name']['alter']['text'] = 'View [field_rpa_first_name]\'s full profile';
  $handler->display->display_options['fields']['field_rpa_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rpa_first_name']['empty'] = 'View [title]\'s full profile';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Block Link';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[url]';
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'staff_profile' => 'staff_profile',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Indexed Content: Researcher profile */
  $handler->display->display_options['filters']['field_researcher_profile']['id'] = 'field_researcher_profile';
  $handler->display->display_options['filters']['field_researcher_profile']['table'] = 'search_api_index_researcher_profiles';
  $handler->display->display_options['filters']['field_researcher_profile']['field'] = 'field_researcher_profile';
  $handler->display->display_options['filters']['field_researcher_profile']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_researcher_profile']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Find a researcher';
  $handler->display->display_options['path'] = 'research/find-researcher';
  $export['researchers_profile_search'] = $view;

  $view = new view();
  $view->name = 'researchers_profile_user_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Researchers Profile: user profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>My Researcher Profile</h3>
<p>A Researcher Profile gives you a public presence on the VU website. People will be able to search for you or your areas of expertise using external search engines or on the VU website.</p>
<p>To save you time we will import data you have provided in Elements and Quest. We will notify you when updates have come through these systems.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p class="clearfix"></p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You do not have a profile created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last updated';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Workbench Moderation: Moderation history link */
  $handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'vid';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['label'] = '';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['workbench_moderation_history_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['workbench_moderation_history_link']['text'] = 'View history';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]   &nbsp; [workbench_moderation_history_link]';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last updated';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Workbench Moderation: Moderation history link */
  $handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'vid';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['label'] = '';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['workbench_moderation_history_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['workbench_moderation_history_link']['text'] = 'View history';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]   &nbsp; [workbench_moderation_history_link]';
  /* Field: User: Researcher Profile */
  $handler->display->display_options['fields']['field_rp_nid']['id'] = 'field_rp_nid';
  $handler->display->display_options['fields']['field_rp_nid']['table'] = 'field_data_field_rp_nid';
  $handler->display->display_options['fields']['field_rp_nid']['field'] = 'field_rp_nid';
  $handler->display->display_options['fields']['field_rp_nid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_rp_nid']['label'] = '';
  $handler->display->display_options['fields']['field_rp_nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rp_nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rp_nid']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  /* Filter criterion: Global: Fields comparison */
  $handler->display->display_options['filters']['fields_compare']['id'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare']['table'] = 'views';
  $handler->display->display_options['filters']['fields_compare']['field'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare']['right_field'] = 'field_rp_nid';
  $handler->display->display_options['filters']['fields_compare']['left_field'] = 'nid';
  $export['researchers_profile_user_profile'] = $view;

  $view = new view();
  $view->name = 'rp_institutes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'RP institutes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'research_institutes' => 'research_institutes',
  );

  /* Display: All institutes */
  $handler = $view->new_display('entityreference', 'All institutes', 'all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Flagship institutes */
  $handler = $view->new_display('entityreference', 'Flagship institutes', 'flagship');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'research_institutes' => 'research_institutes',
  );
  /* Filter criterion: Taxonomy term: Is flagship institute (field_research_institutes_is_f) */
  $handler->display->display_options['filters']['field_research_institutes_is_f_value']['id'] = 'field_research_institutes_is_f_value';
  $handler->display->display_options['filters']['field_research_institutes_is_f_value']['table'] = 'field_data_field_research_institutes_is_f';
  $handler->display->display_options['filters']['field_research_institutes_is_f_value']['field'] = 'field_research_institutes_is_f_value';
  $handler->display->display_options['filters']['field_research_institutes_is_f_value']['value'] = array(
    1 => '1',
  );
  $export['rp_institutes'] = $view;

  return $export;
}
