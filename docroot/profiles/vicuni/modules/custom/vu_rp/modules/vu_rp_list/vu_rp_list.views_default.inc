<?php
/**
 * @file
 * vu_rp_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vu_rp_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rp_researchers_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vu_rp_list_researchers';
  $view->human_name = 'Researcher Admin: Researchers List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administration of Researcher Profiles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage researcher list';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a class="button" href="admin/config/researcher-profile/list/add">Add new researcher</a> <a class="button" href="admin/config/researcher-profile/list/delete-all">Delete all researchers</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Researchers List: Staff ID of the researcher */
  $handler->display->display_options['relationships']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['relationships']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['relationships']['staff_id']['field'] = 'staff_id';
  $handler->display->display_options['relationships']['staff_id']['label'] = 'Default label for the relationship';
  /* Relationship: User: User ID of the user */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'cas_user';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'staff_id';
  $handler->display->display_options['relationships']['uid']['label'] = 'user';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'List of researchers';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: COUNT(Researchers List: Staff ID) */
  $handler->display->display_options['fields']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['fields']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['fields']['staff_id']['field'] = 'staff_id';
  $handler->display->display_options['fields']['staff_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['staff_id']['label'] = 'Number of People';
  $handler->display->display_options['fields']['staff_id']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href=\'/admin/config/researcher-profile/list\'>View & manage</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Researchers List: Staff ID */
  $handler->display->display_options['sorts']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['sorts']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['sorts']['staff_id']['field'] = 'staff_id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75, 100, 200';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'staff_id' => 'staff_id',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'changed' => 'changed',
    'nid' => 'nid',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'staff_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No results found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Researchers List: Staff ID of the researcher */
  $handler->display->display_options['relationships']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['relationships']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['relationships']['staff_id']['field'] = 'staff_id';
  /* Relationship: User: User ID of the user */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'cas_user';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'staff_id';
  $handler->display->display_options['relationships']['uid']['label'] = 'user';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_rp_nid_target_id']['id'] = 'field_rp_nid_target_id';
  $handler->display->display_options['relationships']['field_rp_nid_target_id']['table'] = 'field_data_field_rp_nid';
  $handler->display->display_options['relationships']['field_rp_nid_target_id']['field'] = 'field_rp_nid_target_id';
  $handler->display->display_options['relationships']['field_rp_nid_target_id']['relationship'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Researchers List: Staff ID */
  $handler->display->display_options['fields']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['fields']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['fields']['staff_id']['field'] = 'staff_id';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'field_rp_nid_target_id';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_rp_nid_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Researchers List: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'vu_rp_list_researchers_custom';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Researchers List: Staff ID */
  $handler->display->display_options['sorts']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['sorts']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['sorts']['staff_id']['field'] = 'staff_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Researchers List: Staff ID */
  $handler->display->display_options['filters']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['filters']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['filters']['staff_id']['field'] = 'staff_id';
  $handler->display->display_options['filters']['staff_id']['operator'] = 'contains';
  $handler->display->display_options['filters']['staff_id']['group'] = 1;
  $handler->display->display_options['filters']['staff_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['staff_id']['expose']['operator_id'] = 'staff_id_op';
  $handler->display->display_options['filters']['staff_id']['expose']['label'] = 'Staff ID';
  $handler->display->display_options['filters']['staff_id']['expose']['operator'] = 'staff_id_op';
  $handler->display->display_options['filters']['staff_id']['expose']['identifier'] = 'staff_id';
  $handler->display->display_options['filters']['staff_id']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
    46 => 0,
    51 => 0,
    56 => 0,
    57 => 0,
  );
  /* Filter criterion: Researchers List: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'vu_rp_list_researchers_custom';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
    46 => 0,
    51 => 0,
    56 => 0,
    57 => 0,
  );
  $handler->display->display_options['path'] = 'admin/config/researcher-profile/list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Researchers list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: block */
  $handler = $view->new_display('block', 'block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nothing_1' => 'nothing_1',
    'staff_id' => 'staff_id',
    'nothing' => 'nothing',
    'nothing_3' => 'nothing_3',
    'inactive' => 'inactive',
    'nothing_2' => 'nothing',
    'optout' => 'nothing',
    'nothing_4' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'staff_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'inactive' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '<tr></tr>',
      'empty_column' => 0,
    ),
    'optout' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="manage-researchers">
        <a class="button" href="/admin/config/researcher-profile/list">Manage list of Researchers</a>
      </div>
      <h5 class="people-summary">People Summary</h5>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Title';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'List of researchers';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: COUNT(Researchers List: Staff ID) */
  $handler->display->display_options['fields']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['fields']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['fields']['staff_id']['field'] = 'staff_id';
  $handler->display->display_options['fields']['staff_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['staff_id']['label'] = 'Number of People';
  $handler->display->display_options['fields']['staff_id']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href=\'/admin/config/researcher-profile/list\'>View & manage</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '<a href=\'/admin/config/researcher-profile/list?users=no-account\'>View all</a>';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Field: Researchers List: Inactive user count */
  $handler->display->display_options['fields']['inactive']['id'] = 'inactive';
  $handler->display->display_options['fields']['inactive']['table'] = 'vu_rp_list_researchers_custom';
  $handler->display->display_options['fields']['inactive']['field'] = 'inactive';
  $handler->display->display_options['fields']['inactive']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<tr class="even">
      <td>Researchers - never logged in/no account</td>
      <td>[inactive]</td>
      <td>[nothing_3] </td>
      </tr>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_5']['id'] = 'nothing_5';
  $handler->display->display_options['fields']['nothing_5']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_5']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_5']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_5']['alter']['text'] = '<a href=\'/admin/researchers-list/opted-out\'>View all</a>';
  /* Field: Researchers List: Opted Out user count */
  $handler->display->display_options['fields']['optout']['id'] = 'optout';
  $handler->display->display_options['fields']['optout']['table'] = 'vu_rp_list_researchers_custom';
  $handler->display->display_options['fields']['optout']['field'] = 'optout';
  $handler->display->display_options['fields']['optout']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<tr class="odd">
      <td>Researchers - opted out</td>
      <td>[optout]</td>
      <td>[nothing_5] </td>
      </tr>';
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Current researchers - opted out';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75, 100, 200';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cas_name' => 'cas_name',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_rp_optout_timestamp' => 'field_rp_optout_timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'cas_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rp_optout_timestamp' => array(
      'sortable' => 1,
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No results found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Researchers List: Staff ID of the researcher */
  $handler->display->display_options['relationships']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['relationships']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['relationships']['staff_id']['field'] = 'staff_id';
  /* Relationship: User: User ID of the user */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'cas_user';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'staff_id';
  $handler->display->display_options['relationships']['uid']['label'] = 'user';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Researchers List: Staff ID */
  $handler->display->display_options['fields']['staff_id']['id'] = 'staff_id';
  $handler->display->display_options['fields']['staff_id']['table'] = 'vu_rp_list_researchers';
  $handler->display->display_options['fields']['staff_id']['field'] = 'staff_id';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: User: Researcher profile opt-out date */
  $handler->display->display_options['fields']['field_rp_optout_timestamp']['id'] = 'field_rp_optout_timestamp';
  $handler->display->display_options['fields']['field_rp_optout_timestamp']['table'] = 'field_data_field_rp_optout_timestamp';
  $handler->display->display_options['fields']['field_rp_optout_timestamp']['field'] = 'field_rp_optout_timestamp';
  $handler->display->display_options['fields']['field_rp_optout_timestamp']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_rp_optout_timestamp']['label'] = 'Date Opted Out';
  $handler->display->display_options['fields']['field_rp_optout_timestamp']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'd/m/Y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Researcher profile opt-in (field_rp_optin) */
  $handler->display->display_options['filters']['field_rp_optin_value']['id'] = 'field_rp_optin_value';
  $handler->display->display_options['filters']['field_rp_optin_value']['table'] = 'field_data_field_rp_optin';
  $handler->display->display_options['filters']['field_rp_optin_value']['field'] = 'field_rp_optin_value';
  $handler->display->display_options['filters']['field_rp_optin_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_rp_optin_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
    46 => 0,
    51 => 0,
    56 => 0,
    57 => 0,
  );
  $handler->display->display_options['path'] = 'admin/researchers-list/opted-out';

  $export['rp_researchers_list'] = $view;

  return $export;
}
