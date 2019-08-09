<?php
/**
 * @file
 * vu_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vu_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blocks_hero_title_box';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'Blocks: Hero title box';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Relationship: Entityqueue: Block Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'bean';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'hero_title_box' => 'hero_title_box',
  );
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  /* Sort criterion: Entityqueue: Block Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'bean';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hero_title_box' => 'hero_title_box',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['blocks_hero_title_box'] = $view;

  $view = new view();
  $view->name = 'campuses_related_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campuses related blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campuses related blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campus' => 'campus',
  );

  /* Display: Related facilities */
  $handler = $view->new_display('block', 'Related facilities', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'in-this-section ';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Facilities and services at [title_1] campus</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_facilities_services_node']['id'] = 'reverse_field_facilities_services_node';
  $handler->display->display_options['relationships']['reverse_field_facilities_services_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_facilities_services_node']['field'] = 'reverse_field_facilities_services_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '<a href="[path]">
   <h2>[title] </h2>
  [body]
</a>
';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_facilities_services_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_facilities_services_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'Campus facilities';
  $handler->display->display_options['block_caching'] = '4';
  $export['campuses_related_blocks'] = $view;

  $view = new view();
  $view->name = 'content_revisions';
  $view->description = 'Find and manage content.';
  $view->tag = 'admin';
  $view->base_table = 'node_revision';
  $view->human_name = 'Administration: Content Revisions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp_1' => 'title',
    'type' => 'type',
    'name' => 'name',
    'timestamp' => 'timestamp',
    'log' => 'log',
    'nid' => 'nid',
    'status' => 'status',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;',
      'empty_column' => 0,
    ),
    'timestamp_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No content available.';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['label'] = 'Revision';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['field_access'] = array(
    3 => '3',
    2 => 0,
    26 => 0,
    21 => 0,
    11 => 0,
    16 => 0,
    36 => 0,
    41 => 0,
    31 => 0,
    46 => 0,
    51 => 0,
    56 => 0,
    57 => 0,
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Change author',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Stick',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Unstick',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Promote to front page',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Demote from front page',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
  );
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Revised by';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Revision date';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'medium';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content revision: Log message */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  $handler->display->display_options['fields']['log']['element_label_class'] = 'td--width-20';
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Pending';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'vid';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operation';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'vid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
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
    3 => 0,
    31 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    26 => 0,
    21 => 0,
    11 => 0,
    16 => 0,
    36 => 0,
    3 => 0,
    31 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    26 => 0,
    21 => 0,
    11 => 0,
    16 => 0,
    36 => 0,
    3 => 0,
    31 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
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
    3 => 0,
    31 => 0,
  );

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change author',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Stick',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unstick',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Promote to front page',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Demote from front page',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
  );
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Revised by';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Revision date';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'medium';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content revision: Log message */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  $handler->display->display_options['fields']['log']['relationship'] = 'nid';
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Pending';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'vid';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['path'] = 'admin/content/export/content.csv';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'system_1' => 'system_1',
  );
  $export['content_revisions'] = $view;

  $view = new view();
  $view->name = 'course_fees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course Fees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Fees';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_course_target_id']['id'] = 'field_course_target_id';
  $handler->display->display_options['relationships']['field_course_target_id']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_target_id']['field'] = 'field_course_target_id';
  /* Field: Content: International */
  $handler->display->display_options['fields']['field_international']['id'] = 'field_international';
  $handler->display->display_options['fields']['field_international']['table'] = 'field_data_field_international';
  $handler->display->display_options['fields']['field_international']['field'] = 'field_international';
  $handler->display->display_options['fields']['field_international']['label'] = '';
  $handler->display->display_options['fields']['field_international']['element_label_colon'] = FALSE;
  /* Field: Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code']['id'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['relationship'] = 'field_course_target_id';
  $handler->display->display_options['fields']['field_unit_code']['label'] = '';
  $handler->display->display_options['fields']['field_unit_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_course_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Disclaimers */
  $handler->display->display_options['fields']['field_disclaimers']['id'] = 'field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['table'] = 'field_data_field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['field'] = 'field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['label'] = '';
  $handler->display->display_options['fields']['field_disclaimers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_disclaimers']['delta_offset'] = '0';
  /* Field: Content: Credit Points */
  $handler->display->display_options['fields']['field_credit_points']['id'] = 'field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['table'] = 'field_data_field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['field'] = 'field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['label'] = '';
  $handler->display->display_options['fields']['field_credit_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Sector */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['label'] = '';
  $handler->display->display_options['fields']['field_sector']['element_label_colon'] = FALSE;
  /* Field: Content: EFTSL */
  $handler->display->display_options['fields']['field_eftsl']['id'] = 'field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['table'] = 'field_data_field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['field'] = 'field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['label'] = '';
  $handler->display->display_options['fields']['field_eftsl']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eftsl']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '3',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Cohort Year */
  $handler->display->display_options['fields']['field_cohort_year']['id'] = 'field_cohort_year';
  $handler->display->display_options['fields']['field_cohort_year']['table'] = 'field_data_field_cohort_year';
  $handler->display->display_options['fields']['field_cohort_year']['field'] = 'field_cohort_year';
  $handler->display->display_options['fields']['field_cohort_year']['label'] = '';
  $handler->display->display_options['fields']['field_cohort_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cohort_year']['settings'] = array(
    'format_type' => 'search_api_facetapi_YEAR',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Contact Hours */
  $handler->display->display_options['fields']['field_contact_hours']['id'] = 'field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['table'] = 'field_data_field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['field'] = 'field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['label'] = '';
  $handler->display->display_options['fields']['field_contact_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fee */
  $handler->display->display_options['fields']['field_fee']['id'] = 'field_fee';
  $handler->display->display_options['fields']['field_fee']['table'] = 'field_data_field_fee';
  $handler->display->display_options['fields']['field_fee']['field'] = 'field_fee';
  $handler->display->display_options['fields']['field_fee']['label'] = '';
  $handler->display->display_options['fields']['field_fee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fee']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fee Type */
  $handler->display->display_options['fields']['field_fee_type']['id'] = 'field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['table'] = 'field_data_field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['field'] = 'field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['label'] = '';
  $handler->display->display_options['fields']['field_fee_type']['element_label_colon'] = FALSE;
  /* Field: Content: Hourly Rate */
  $handler->display->display_options['fields']['field_hourly_rate']['id'] = 'field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['table'] = 'field_data_field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['field'] = 'field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['label'] = '';
  $handler->display->display_options['fields']['field_hourly_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hourly_rate']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = '';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'search_api_facetapi_YEAR',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_course_target_id';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_fees' => 'course_fees',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: International (field_international) */
  $handler->display->display_options['filters']['field_international_value']['id'] = 'field_international_value';
  $handler->display->display_options['filters']['field_international_value']['table'] = 'field_data_field_international';
  $handler->display->display_options['filters']['field_international_value']['field'] = 'field_international_value';
  $handler->display->display_options['filters']['field_international_value']['value'] = array(
    'all' => 'all',
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_international_value']['group'] = 1;
  /* Filter criterion: Field: Sector (field_sector) */
  $handler->display->display_options['filters']['field_sector_value']['id'] = 'field_sector_value';
  $handler->display->display_options['filters']['field_sector_value']['table'] = 'field_data_field_sector';
  $handler->display->display_options['filters']['field_sector_value']['field'] = 'field_sector_value';
  $handler->display->display_options['filters']['field_sector_value']['value'] = array(
    'all' => 'all',
    'HE' => 'HE',
    'VE' => 'VE',
  );
  $handler->display->display_options['filters']['field_sector_value']['group'] = 1;
  /* Filter criterion: Field: Year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_year_value']['granularity'] = 'year';
  /* Filter criterion: Content: Cohort Year (field_cohort_year) */
  $handler->display->display_options['filters']['field_cohort_year_value']['id'] = 'field_cohort_year_value';
  $handler->display->display_options['filters']['field_cohort_year_value']['table'] = 'field_data_field_cohort_year';
  $handler->display->display_options['filters']['field_cohort_year_value']['field'] = 'field_cohort_year_value';
  $handler->display->display_options['filters']['field_cohort_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_cohort_year_value']['granularity'] = 'year';
  /* Filter criterion: Content: Course Code (field_unit_code) */
  $handler->display->display_options['filters']['field_unit_code_value']['id'] = 'field_unit_code_value';
  $handler->display->display_options['filters']['field_unit_code_value']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['filters']['field_unit_code_value']['field'] = 'field_unit_code_value';
  $handler->display->display_options['filters']['field_unit_code_value']['relationship'] = 'field_course_target_id';
  $handler->display->display_options['filters']['field_unit_code_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_unit_code_value']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_course_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 2;
  /* Filter criterion: Content: Fee Type (field_fee_type) */
  $handler->display->display_options['filters']['field_fee_type_tid']['id'] = 'field_fee_type_tid';
  $handler->display->display_options['filters']['field_fee_type_tid']['table'] = 'field_data_field_fee_type';
  $handler->display->display_options['filters']['field_fee_type_tid']['field'] = 'field_fee_type_tid';
  $handler->display->display_options['filters']['field_fee_type_tid']['value'] = array(
    1699837 => '1699837',
    1699838 => '1699838',
    1699843 => '1699843',
    1699844 => '1699844',
    1699839 => '1699839',
    1699841 => '1699841',
    1699842 => '1699842',
    1699840 => '1699840',
  );
  $handler->display->display_options['filters']['field_fee_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fee_type_tid']['vocabulary'] = 'fee_types';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['course_fees'] = $view;

  $view = new view();
  $view->name = 'course_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_course_index';
  $view->human_name = 'Course Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['style_options']['class'] = 'results-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'courses-search-results';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_unit_code' => 'field_unit_code',
    'field_unit_lev' => 'field_unit_lev',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Results @start - @end of @total.';
  /* No results behavior: Search: Spellcheck */
  $handler->display->display_options['empty']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['empty']['search_api_spellcheck']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['empty']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code']['id'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['field_unit_code']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['label'] = 'Code';
  $handler->display->display_options['fields']['field_unit_code']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_unit_code']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_unit_code']['element_wrapper_class'] = 'course-meta';
  $handler->display->display_options['fields']['field_unit_code']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_unit_code']['hide_empty'] = TRUE;
  /* Field: VU: Study level label */
  $handler->display->display_options['fields']['study_level_label']['id'] = 'study_level_label';
  $handler->display->display_options['fields']['study_level_label']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['study_level_label']['field'] = 'study_level_label';
  $handler->display->display_options['fields']['study_level_label']['label'] = 'Level';
  $handler->display->display_options['fields']['study_level_label']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['study_level_label']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['study_level_label']['element_wrapper_class'] = 'course-meta';
  $handler->display->display_options['fields']['study_level_label']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['study_level_label']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['study_level_label']['link_to_entity'] = 0;
  /* Field: Indexed Content: Locations */
  $handler->display->display_options['fields']['field_locations']['id'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['field_locations']['field'] = 'field_locations';
  $handler->display->display_options['fields']['field_locations']['label'] = 'Campus';
  $handler->display->display_options['fields']['field_locations']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_locations']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_locations']['element_wrapper_class'] = 'course-meta';
  $handler->display->display_options['fields']['field_locations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_locations']['hide_empty'] = TRUE;
  /* Field: Indexed Content: Cricos code */
  $handler->display->display_options['fields']['field_cricos_code']['id'] = 'field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['field_cricos_code']['field'] = 'field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['label'] = 'Campus';
  $handler->display->display_options['fields']['field_cricos_code']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_cricos_code']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_cricos_code']['element_wrapper_class'] = 'course-meta cricos-meta';
  $handler->display->display_options['fields']['field_cricos_code']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cricos_code']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cricos_code']['type'] = 'custom_formatters_cricos_sanitised_location';
  $handler->display->display_options['fields']['field_cricos_code']['delta_offset'] = '0';
  /* Field: Course search description: Text (indexed) */
  $handler->display->display_options['fields']['field_description_editable_value']['id'] = 'field_description_editable_value';
  $handler->display->display_options['fields']['field_description_editable_value']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['field_description_editable_value']['field'] = 'field_description_editable_value';
  $handler->display->display_options['fields']['field_description_editable_value']['label'] = '';
  $handler->display->display_options['fields']['field_description_editable_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description_editable_value']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_description_editable_value']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description_editable_value']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_description_editable_value']['alter']['preserve_tags'] = '<strong>';
  $handler->display->display_options['fields']['field_description_editable_value']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_description_editable_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description_editable_value']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_description_editable_value']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_description_editable_value']['link_to_entity'] = 0;
  /* Field: VU: Course majors */
  $handler->display->display_options['fields']['course_majors']['id'] = 'course_majors';
  $handler->display->display_options['fields']['course_majors']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['course_majors']['field'] = 'course_majors';
  $handler->display->display_options['fields']['course_majors']['label'] = '';
  $handler->display->display_options['fields']['course_majors']['alter']['preserve_tags'] = '<strong>';
  $handler->display->display_options['fields']['course_majors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['course_majors']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['course_majors']['empty'] = '[field_description_editable_value]';
  $handler->display->display_options['fields']['course_majors']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['course_majors']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['course_majors']['link_to_entity'] = 0;
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<strong>';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Indexed Content: Course Commencement Date */
  $handler->display->display_options['fields']['commencement_date']['id'] = 'commencement_date';
  $handler->display->display_options['fields']['commencement_date']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['fields']['commencement_date']['field'] = 'commencement_date';
  $handler->display->display_options['fields']['commencement_date']['label'] = '';
  $handler->display->display_options['fields']['commencement_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commencement_date']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_course_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_career:value' => 'field_career:value',
    'field_course_aqf' => 'field_course_aqf',
    'field_credentials' => 'field_credentials',
    'field_description_editable:value' => 'field_description_editable:value',
    'field_excerpt' => 'field_excerpt',
    'field_imp_career' => 'field_imp_career',
    'field_imp_desc' => 'field_imp_desc',
    'field_imp_intro:value' => 'field_imp_intro:value',
    'field_imp_structure' => 'field_imp_structure',
    'field_locations_special' => 'field_locations_special',
    'field_structure' => 'field_structure',
    'search_api_aggregation_2' => 'search_api_aggregation_2',
    'title' => 'title',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'courses/search';
  $export['course_search'] = $view;

  $view = new view();
  $view->name = 'courses_by_unit_unitset';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses by unit/unitset';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses this unit belongs to';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_course_units_target_id';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_unit_s_type_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  /* Contextual filter: Content: Units (field_course_units) */
  $handler->display->display_options['arguments']['field_course_units_target_id']['id'] = 'field_course_units_target_id';
  $handler->display->display_options['arguments']['field_course_units_target_id']['table'] = 'field_data_field_course_units';
  $handler->display->display_options['arguments']['field_course_units_target_id']['field'] = 'field_course_units_target_id';
  $handler->display->display_options['arguments']['field_course_units_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_course_units_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_course_units_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_units_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_units_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'courses' => 'courses',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Courses this unit belongs to */
  $handler = $view->new_display('block', 'Courses this unit belongs to', 'block');
  $handler->display->display_options['display_description'] = 'Courses this unit belongs to';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Courses this unit belongs to';
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Specialisations this unit belongs to */
  $handler = $view->new_display('block', 'Specialisations this unit belongs to', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Specialisations this unit belongs to';
  $handler->display->display_options['display_description'] = 'Specialisations this unit belongs to';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
    'name' => 'name',
    'path' => 'path',
    'path_1' => 'path_1',
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'path_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing_1' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Unit entities */
  $handler->display->display_options['relationships']['field_course_units_target_id']['id'] = 'field_course_units_target_id';
  $handler->display->display_options['relationships']['field_course_units_target_id']['table'] = 'field_data_field_course_units';
  $handler->display->display_options['relationships']['field_course_units_target_id']['field'] = 'field_course_units_target_id';
  $handler->display->display_options['relationships']['field_course_units_target_id']['ui_name'] = 'Unit entities';
  $handler->display->display_options['relationships']['field_course_units_target_id']['label'] = 'Unit entities';
  $handler->display->display_options['relationships']['field_course_units_target_id']['required'] = TRUE;
  /* Relationship: Course entities */
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['id'] = 'field_course_units_target_id_1';
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['table'] = 'field_data_field_course_units';
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['field'] = 'field_course_units_target_id';
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['relationship'] = 'field_course_units_target_id';
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['ui_name'] = 'Course entities';
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['label'] = 'Course entities';
  $handler->display->display_options['relationships']['field_course_units_target_id_1']['required'] = TRUE;
  /* Relationship: Content: Unit Set Type (field_unit_s_type) */
  $handler->display->display_options['relationships']['field_unit_s_type_tid']['id'] = 'field_unit_s_type_tid';
  $handler->display->display_options['relationships']['field_unit_s_type_tid']['table'] = 'field_data_field_unit_s_type';
  $handler->display->display_options['relationships']['field_unit_s_type_tid']['field'] = 'field_unit_s_type_tid';
  $handler->display->display_options['relationships']['field_unit_s_type_tid']['relationship'] = 'field_course_units_target_id';
  $handler->display->display_options['relationships']['field_unit_s_type_tid']['label'] = 'unit set type';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_course_units_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_unit_s_type_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'node';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['relationship'] = 'field_course_units_target_id';
  $handler->display->display_options['fields']['path_1']['label'] = '';
  $handler->display->display_options['fields']['path_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Course';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['nothing_1']['alter']['alt'] = '[title]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Study as part of';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_1] - [name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[path_1]';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = '[title_1] - [name]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Units (field_course_units) */
  $handler->display->display_options['arguments']['field_course_units_target_id']['id'] = 'field_course_units_target_id';
  $handler->display->display_options['arguments']['field_course_units_target_id']['table'] = 'field_data_field_course_units';
  $handler->display->display_options['arguments']['field_course_units_target_id']['field'] = 'field_course_units_target_id';
  $handler->display->display_options['arguments']['field_course_units_target_id']['relationship'] = 'field_course_units_target_id';
  $handler->display->display_options['arguments']['field_course_units_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_course_units_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_course_units_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_units_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_units_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Specialisations this unit belongs to';
  $handler->display->display_options['block_caching'] = '4';
  $export['courses_by_unit_unitset'] = $view;

  $view = new view();
  $view->name = 'courses_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All courses by topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['relationships']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['relationships']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  /* Field: Content: Study topics */
  $handler->display->display_options['fields']['field_study_topic_1']['id'] = 'field_study_topic_1';
  $handler->display->display_options['fields']['field_study_topic_1']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['fields']['field_study_topic_1']['field'] = 'field_study_topic';
  $handler->display->display_options['fields']['field_study_topic_1']['label'] = '';
  $handler->display->display_options['fields']['field_study_topic_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic_1']['alter']['text'] = '<h2>[field_study_topic_1] courses</h2>
[field_study_topic] ';
  $handler->display->display_options['fields']['field_study_topic_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_study_topic_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_study_topic_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_study_topic_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_study_topic_target_id';
  /* Sort criterion: Content: Study topics (field_study_topic) */
  $handler->display->display_options['sorts']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['sorts']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['sorts']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  $handler->display->display_options['sorts']['field_study_topic_target_id']['relationship'] = 'reverse_field_study_topic_node';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study_topic_area' => 'study_topic_area',
  );
  /* Filter criterion: Content: Study topics (field_study_topic) */
  $handler->display->display_options['filters']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['filters']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['filters']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  $handler->display->display_options['filters']['field_study_topic_target_id']['operator'] = 'not empty';

  /* Display: All courses by topic */
  $handler = $view->new_display('block', 'All courses by topic', 'all_by_topic');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_study_topic_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_study_topic_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_study_topic_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Study topics */
  $handler->display->display_options['fields']['field_study_topic']['id'] = 'field_study_topic';
  $handler->display->display_options['fields']['field_study_topic']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['fields']['field_study_topic']['field'] = 'field_study_topic';
  $handler->display->display_options['fields']['field_study_topic']['label'] = '';
  $handler->display->display_options['fields']['field_study_topic']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic']['alter']['text'] = '<a href="[path]">All courses in [field_study_topic]</a>';
  $handler->display->display_options['fields']['field_study_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_study_topic']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_study_topic']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_study_topic']['delta_offset'] = '0';
  /* Field: Content: Study topics */
  $handler->display->display_options['fields']['field_study_topic_1']['id'] = 'field_study_topic_1';
  $handler->display->display_options['fields']['field_study_topic_1']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['fields']['field_study_topic_1']['field'] = 'field_study_topic';
  $handler->display->display_options['fields']['field_study_topic_1']['label'] = '';
  $handler->display->display_options['fields']['field_study_topic_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic_1']['alter']['text'] = '<h3 id="study-topic-[nid]">[field_study_topic_1] courses</h3>
<p>[field_study_topic]</p>';
  $handler->display->display_options['fields']['field_study_topic_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_study_topic_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_study_topic_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_study_topic_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'All courses by topic';
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Browse courses block */
  $handler = $view->new_display('block', 'Browse courses block', 'course_browser_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse for a course';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study_topic_area' => 'study_topic_area',
  );
  /* Filter criterion: Content: Study topics (field_study_topic) */
  $handler->display->display_options['filters']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['filters']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['filters']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  $handler->display->display_options['filters']['field_study_topic_target_id']['operator'] = 'empty';
  $handler->display->display_options['block_description'] = 'All courses by topic';
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Browse courses block 2col */
  $handler = $view->new_display('block', 'Browse courses block 2col', 'landing_course_browser_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse for a course';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study_topic_area' => 'study_topic_area',
  );
  /* Filter criterion: Content: Study topics (field_study_topic) */
  $handler->display->display_options['filters']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['filters']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['filters']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  $handler->display->display_options['filters']['field_study_topic_target_id']['operator'] = 'empty';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = '!=';
  $handler->display->display_options['filters']['title']['value'] = 'Trades';
  $handler->display->display_options['block_description'] = 'All courses by topic';
  $handler->display->display_options['block_caching'] = '4';
  $export['courses_lists'] = $view;

  $view = new view();
  $view->name = 'courses_study_level';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses by study level';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Course Level */
  $handler->display->display_options['fields']['field_unit_lev']['id'] = 'field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['table'] = 'field_data_field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['field'] = 'field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['label'] = '';
  $handler->display->display_options['fields']['field_unit_lev']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_unit_lev']['element_label_colon'] = FALSE;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_duration']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: AQF */
  $handler->display->display_options['fields']['field_course_aqf']['id'] = 'field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['table'] = 'field_data_field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['field'] = 'field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['label'] = '';
  $handler->display->display_options['fields']['field_course_aqf']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_aqf']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_aqf']['type'] = 'text_plain';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return vumain_extract_study_level_label_from_node($row->nid);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = '$course_title_1 = _vumain_courses_title_order($row1->title);
$course_title_2 =_vumain_courses_title_order($row2->title);
$study_level_label_1 = $row1->php;
$study_level_label_2 = $row2->php;
return ($study_level_label_1 == $study_level_label_2) ? strcasecmp($course_title_1, $course_title_2) : vumain_courses_study_areas_sort_levels($study_level_label_1, $study_level_label_2);';
  /* Contextual filter: Content: Study topic and areas (field_study_topic_area) */
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['id'] = 'field_study_topic_area_target_id';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['table'] = 'field_data_field_study_topic_area';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['field'] = 'field_study_topic_area_target_id';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['validate_options']['types'] = array(
    'study_topic_area' => 'study_topic_area',
  );
  $handler->display->display_options['arguments']['field_study_topic_area_target_id']['validate_options']['nid_type'] = 'nids';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'courses' => 'courses',
  );
  /* Filter criterion: Content: Domestic (field_domestic) */
  $handler->display->display_options['filters']['field_domestic_value']['id'] = 'field_domestic_value';
  $handler->display->display_options['filters']['field_domestic_value']['table'] = 'field_data_field_domestic';
  $handler->display->display_options['filters']['field_domestic_value']['field'] = 'field_domestic_value';
  $handler->display->display_options['filters']['field_domestic_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Course Level (field_unit_lev) */
  $handler->display->display_options['filters']['field_unit_lev_value']['id'] = 'field_unit_lev_value';
  $handler->display->display_options['filters']['field_unit_lev_value']['table'] = 'field_data_field_unit_lev';
  $handler->display->display_options['filters']['field_unit_lev_value']['field'] = 'field_unit_lev_value';
  $handler->display->display_options['filters']['field_unit_lev_value']['operator'] = 'not empty';

  /* Display: Domestic (Block) */
  $handler = $view->new_display('block', 'Domestic (Block)', 'csl_dom_b');
  $handler->display->display_options['block_caching'] = '4';

  /* Display: International (Block) */
  $handler = $view->new_display('block', 'International (Block)', 'csl_int_b');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code_1']['id'] = 'field_unit_code_1';
  $handler->display->display_options['fields']['field_unit_code_1']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['fields']['field_unit_code_1']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code_1']['label'] = '';
  $handler->display->display_options['fields']['field_unit_code_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_unit_code_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_unit_code_1']['alter']['path'] = 'courses/international/[field_unit_code_1-value]';
  $handler->display->display_options['fields']['field_unit_code_1']['element_label_colon'] = FALSE;
  /* Field: Content: Course Level */
  $handler->display->display_options['fields']['field_unit_lev']['id'] = 'field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['table'] = 'field_data_field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['field'] = 'field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['label'] = '';
  $handler->display->display_options['fields']['field_unit_lev']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_unit_lev']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/courses/international/[field_unit_code_1]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code']['id'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['label'] = 'Code';
  $handler->display->display_options['fields']['field_unit_code']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_unit_code']['empty_zero'] = TRUE;
  /* Field: Content: International fees */
  $handler->display->display_options['fields']['field_international_fees']['id'] = 'field_international_fees';
  $handler->display->display_options['fields']['field_international_fees']['table'] = 'field_data_field_international_fees';
  $handler->display->display_options['fields']['field_international_fees']['field'] = 'field_international_fees';
  $handler->display->display_options['fields']['field_international_fees']['label'] = 'Fees';
  $handler->display->display_options['fields']['field_international_fees']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_international_fees']['empty_zero'] = TRUE;
  /* Field: Content: International semester intake */
  $handler->display->display_options['fields']['field_int_sem_int']['id'] = 'field_int_sem_int';
  $handler->display->display_options['fields']['field_int_sem_int']['table'] = 'field_data_field_int_sem_int';
  $handler->display->display_options['fields']['field_int_sem_int']['field'] = 'field_int_sem_int';
  $handler->display->display_options['fields']['field_int_sem_int']['label'] = 'Intakes';
  $handler->display->display_options['fields']['field_int_sem_int']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_int_sem_int']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_int_sem_int']['empty_zero'] = TRUE;
  /* Field: Content: International campus */
  $handler->display->display_options['fields']['field_imp_inter_campus']['id'] = 'field_imp_inter_campus';
  $handler->display->display_options['fields']['field_imp_inter_campus']['table'] = 'field_data_field_imp_inter_campus';
  $handler->display->display_options['fields']['field_imp_inter_campus']['field'] = 'field_imp_inter_campus';
  $handler->display->display_options['fields']['field_imp_inter_campus']['label'] = 'Campus';
  $handler->display->display_options['fields']['field_imp_inter_campus']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_imp_inter_campus']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_imp_inter_campus']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_imp_inter_campus']['delta_offset'] = '0';
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  /* Field: Content: Cricos code */
  $handler->display->display_options['fields']['field_cricos_code']['id'] = 'field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['table'] = 'field_data_field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['field'] = 'field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['label'] = 'Campus';
  $handler->display->display_options['fields']['field_cricos_code']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cricos_code']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_cricos_code']['type'] = 'custom_formatters_cricos_sanitised_location';
  $handler->display->display_options['fields']['field_cricos_code']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: AQF */
  $handler->display->display_options['fields']['field_course_aqf']['id'] = 'field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['table'] = 'field_data_field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['field'] = 'field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return vumain_extract_study_level_label_from_node($row->nid);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'courses' => 'courses',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: International (field_international) */
  $handler->display->display_options['filters']['field_international_value']['id'] = 'field_international_value';
  $handler->display->display_options['filters']['field_international_value']['table'] = 'field_data_field_international';
  $handler->display->display_options['filters']['field_international_value']['field'] = 'field_international_value';
  $handler->display->display_options['filters']['field_international_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_international_value']['group'] = 1;
  /* Filter criterion: Content: Course Level (field_unit_lev) */
  $handler->display->display_options['filters']['field_unit_lev_value']['id'] = 'field_unit_lev_value';
  $handler->display->display_options['filters']['field_unit_lev_value']['table'] = 'field_data_field_unit_lev';
  $handler->display->display_options['filters']['field_unit_lev_value']['field'] = 'field_unit_lev_value';
  $handler->display->display_options['filters']['field_unit_lev_value']['operator'] = 'not empty';
  $handler->display->display_options['block_caching'] = '4';
  $export['courses_study_level'] = $view;

  $view = new view();
  $view->name = 'events_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field: Featured audience (field_audience) */
  $handler->display->display_options['relationships']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['relationships']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['relationships']['field_audience_tid']['field'] = 'field_audience_tid';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'news_listing_page_100x56',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Article Date */
  $handler->display->display_options['fields']['field_article_date']['id'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['fields']['field_article_date']['field'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['label'] = '';
  $handler->display->display_options['fields']['field_article_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_date']['settings'] = array(
    'format_type' => 'vumain_news_listing_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Sort criterion: Content: Event Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Contextual filter: Field: Featured audience (field_audience) */
  $handler->display->display_options['arguments']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['arguments']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['arguments']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['arguments']['field_audience_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_audience_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_audience_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_audience_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );

  /* Display: Events Listing page */
  $handler = $view->new_display('block', 'Events Listing page', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'events-listing-page';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '← Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next →';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = '[field_image_1] clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'news_listing_page_100x56',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'entity_id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Campus */
  $handler->display->display_options['fields']['field_event_campus']['id'] = 'field_event_campus';
  $handler->display->display_options['fields']['field_event_campus']['table'] = 'field_data_field_event_campus';
  $handler->display->display_options['fields']['field_event_campus']['field'] = 'field_event_campus';
  $handler->display->display_options['fields']['field_event_campus']['label'] = '';
  $handler->display->display_options['fields']['field_event_campus']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_campus']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_campus']['alter']['text'] = '<b>[field_event_campus]</b>  |  ';
  $handler->display->display_options['fields']['field_event_campus']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_date']['type'] = 'custom_formatters_event_date_format';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_date']['group_columns'] = array(
    'value2' => 'value2',
  );
  $handler->display->display_options['fields']['field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_date']['multi_type'] = 'ul';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Field: Content: Location tag */
  $handler->display->display_options['fields']['field_location_tag']['id'] = 'field_location_tag';
  $handler->display->display_options['fields']['field_location_tag']['table'] = 'field_data_field_location_tag';
  $handler->display->display_options['fields']['field_location_tag']['field'] = 'field_location_tag';
  $handler->display->display_options['fields']['field_location_tag']['label'] = '';
  $handler->display->display_options['fields']['field_location_tag']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_location_tag']['alter']['text'] = '<b>[field_location_tag]</b>  |  ';
  $handler->display->display_options['fields']['field_location_tag']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="clearfix"  href="[path]">
[field_image]
<div class="row-right">
<h2>[title]</h2>
<div class="row-meta">[field_event_campus][field_location_tag][field_date]</div>
<p>[body]</p>
</div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Content: Event Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = 'now';
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Course information sessions */
  $handler = $view->new_display('block', 'Course information sessions', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'events-listing-page';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '← Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next →';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = '[field_image_1] clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'news_listing_page_100x56',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'entity_id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Campus */
  $handler->display->display_options['fields']['field_event_campus']['id'] = 'field_event_campus';
  $handler->display->display_options['fields']['field_event_campus']['table'] = 'field_data_field_event_campus';
  $handler->display->display_options['fields']['field_event_campus']['field'] = 'field_event_campus';
  $handler->display->display_options['fields']['field_event_campus']['label'] = '';
  $handler->display->display_options['fields']['field_event_campus']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_campus']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_campus']['alter']['text'] = '<b>[field_event_campus]</b>  |  ';
  $handler->display->display_options['fields']['field_event_campus']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_date']['group_columns'] = array(
    'value' => 'value',
  );
  $handler->display->display_options['fields']['field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_date']['multi_type'] = 'ul';
  /* Field: MIN(Content: Body) */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['group_type'] = 'min';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="clearfix"  href="[path]">
[field_image]
<div class="row-right">
<h2>[title]</h2>
<div class="row-meta">[field_event_campus][field_date]</div>
<p>[body]</p>
</div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Event Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = 'now';
  /* Filter criterion: Content: Courses to feature on (domestic) (field_cours_feat_dom) */
  $handler->display->display_options['filters']['field_cours_feat_dom_target_id']['id'] = 'field_cours_feat_dom_target_id';
  $handler->display->display_options['filters']['field_cours_feat_dom_target_id']['table'] = 'field_data_field_cours_feat_dom';
  $handler->display->display_options['filters']['field_cours_feat_dom_target_id']['field'] = 'field_cours_feat_dom_target_id';
  $handler->display->display_options['filters']['field_cours_feat_dom_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_cours_feat_dom_target_id']['group'] = 2;
  /* Filter criterion: Content: Courses to feature on (international) (field_cours_feat_int) */
  $handler->display->display_options['filters']['field_cours_feat_int_target_id']['id'] = 'field_cours_feat_int_target_id';
  $handler->display->display_options['filters']['field_cours_feat_int_target_id']['table'] = 'field_data_field_cours_feat_int';
  $handler->display->display_options['filters']['field_cours_feat_int_target_id']['field'] = 'field_cours_feat_int_target_id';
  $handler->display->display_options['filters']['field_cours_feat_int_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_cours_feat_int_target_id']['group'] = 2;
  $handler->display->display_options['block_description'] = 'Course information sessions';

  /* Display: Promoted events list */
  $handler = $view->new_display('block', 'Promoted events list', 'promoted_events_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'about-vu/news-events/events';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|nid';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_date']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky at top of lists */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: COUNT(DISTINCT Content: Type) */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group_type'] = 'count_distinct';
  $handler->display->display_options['filters']['type']['operator'] = 'in';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Promoted events list components */
  $handler = $view->new_display('block', 'Promoted events list components', 'promoted_events_list_component');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'about-vu/news-events/events';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|nid';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_date']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_location']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky at top of lists */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_caching'] = '4';
  $export['events_listing'] = $view;

  $view = new view();
  $view->name = 'expert_guide';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_expert_guide';
  $view->human_name = 'Expert Guide';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'expert-guide-results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'results-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Results @start - @end of @total.';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Sorry - we can\'t find anyone with expertise in that area.
<br/>Please try your search again.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_expert_guide';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Areas of expertise */
  $handler->display->display_options['fields']['field_staff_expertise']['id'] = 'field_staff_expertise';
  $handler->display->display_options['fields']['field_staff_expertise']['table'] = 'search_api_index_expert_guide';
  $handler->display->display_options['fields']['field_staff_expertise']['field'] = 'field_staff_expertise';
  $handler->display->display_options['fields']['field_staff_expertise']['label'] = 'Expertise';
  $handler->display->display_options['fields']['field_staff_expertise']['element_type'] = '0';
  $handler->display->display_options['fields']['field_staff_expertise']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_staff_expertise']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_staff_expertise']['element_wrapper_class'] = 'result-item-meta';
  $handler->display->display_options['fields']['field_staff_expertise']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_expertise']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_staff_expertise']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_staff_expertise']['bypass_access'] = 0;
  /* Field: Indexed Content: Staff picture */
  $handler->display->display_options['fields']['field_staff_picture']['id'] = 'field_staff_picture';
  $handler->display->display_options['fields']['field_staff_picture']['table'] = 'search_api_index_expert_guide';
  $handler->display->display_options['fields']['field_staff_picture']['field'] = 'field_staff_picture';
  $handler->display->display_options['fields']['field_staff_picture']['label'] = '';
  $handler->display->display_options['fields']['field_staff_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_staff_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_picture']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_staff_picture']['element_wrapper_class'] = 'staff-picture-thumbnail';
  $handler->display->display_options['fields']['field_staff_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_staff_picture']['settings'] = array(
    'image_style' => 'staff_profile_thumbnail',
    'image_link' => '',
  );
  /* Field: Indexed Content: Staff search snippet */
  $handler->display->display_options['fields']['field_staff_search_snippet']['id'] = 'field_staff_search_snippet';
  $handler->display->display_options['fields']['field_staff_search_snippet']['table'] = 'search_api_index_expert_guide';
  $handler->display->display_options['fields']['field_staff_search_snippet']['field'] = 'field_staff_search_snippet';
  $handler->display->display_options['fields']['field_staff_search_snippet']['label'] = '';
  $handler->display->display_options['fields']['field_staff_search_snippet']['element_type'] = '0';
  $handler->display->display_options['fields']['field_staff_search_snippet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_search_snippet']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_staff_search_snippet']['element_default_classes'] = FALSE;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_expert_guide';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Media ready? */
  $handler->display->display_options['filters']['field_media_ready']['id'] = 'field_media_ready';
  $handler->display->display_options['filters']['field_media_ready']['table'] = 'search_api_index_expert_guide';
  $handler->display->display_options['filters']['field_media_ready']['field'] = 'field_media_ready';
  $handler->display->display_options['filters']['field_media_ready']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_caching'] = '-1';
  $export['expert_guide'] = $view;

  $view = new view();
  $view->name = 'featured_content_inline_entity_reference';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Featured content inline entity reference';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [nid: [nid]]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campus' => 'campus',
    'campus_housing' => 'campus_housing',
    'page_builder' => 'page_builder',
    'topic_pages' => 'topic_pages',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'nid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['featured_content_inline_entity_reference'] = $view;

  $view = new view();
  $view->name = 'fym_banner_course_pages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'Fym Banner Course Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Block: Logo */
  $handler->display->display_options['fields']['field_fym_logo']['id'] = 'field_fym_logo';
  $handler->display->display_options['fields']['field_fym_logo']['table'] = 'field_data_field_fym_logo';
  $handler->display->display_options['fields']['field_fym_logo']['field'] = 'field_fym_logo';
  $handler->display->display_options['fields']['field_fym_logo']['label'] = '';
  $handler->display->display_options['fields']['field_fym_logo']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_fym_logo']['element_class'] = 'field-name-field-fym-logo';
  $handler->display->display_options['fields']['field_fym_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fym_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fym_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Block: Body Text */
  $handler->display->display_options['fields']['field_fym_body_text']['id'] = 'field_fym_body_text';
  $handler->display->display_options['fields']['field_fym_body_text']['table'] = 'field_data_field_fym_body_text';
  $handler->display->display_options['fields']['field_fym_body_text']['field'] = 'field_fym_body_text';
  $handler->display->display_options['fields']['field_fym_body_text']['label'] = '';
  $handler->display->display_options['fields']['field_fym_body_text']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_fym_body_text']['element_class'] = 'field-name-field-fym-body-text';
  $handler->display->display_options['fields']['field_fym_body_text']['element_label_colon'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fym_banner_type' => 'fym_banner_type',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'FYM Banner View Block';
  $export['fym_banner_course_pages'] = $view;

  $view = new view();
  $view->name = 'important_dates_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'paragraphs_item';
  $view->human_name = 'Important Dates List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Important Dates List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_entity_ref_target_id']['id'] = 'field_event_entity_ref_target_id';
  $handler->display->display_options['relationships']['field_event_entity_ref_target_id']['table'] = 'field_data_field_event_entity_ref';
  $handler->display->display_options['relationships']['field_event_entity_ref_target_id']['field'] = 'field_event_entity_ref_target_id';
  /* Relationship: Paragraphs item: Entity with the Event (field_event) */
  $handler->display->display_options['relationships']['field_event_paragraphs_item']['id'] = 'field_event_paragraphs_item';
  $handler->display->display_options['relationships']['field_event_paragraphs_item']['table'] = 'paragraphs_item';
  $handler->display->display_options['relationships']['field_event_paragraphs_item']['field'] = 'field_event_paragraphs_item';
  /* Field: Paragraphs item: Event Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_event_date']['element_class'] = 'event-date';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['type'] = 'custom_formatters_important_dates_dates';
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_event_date']['group_column'] = 'entity_id';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'div';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'event-title';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Paragraphs item: Link */
  $handler->display->display_options['fields']['field_feature_link']['id'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['table'] = 'field_data_field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['field'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['label'] = '';
  $handler->display->display_options['fields']['field_feature_link']['element_class'] = 'event-link';
  $handler->display->display_options['fields']['field_feature_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_feature_link']['type'] = 'custom_formatters_link_important_dates';
  $handler->display->display_options['fields']['field_feature_link']['settings'] = array(
    'view_mode' => 'full',
  );
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'field_event_entity_ref_target_id';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_date']['element_class'] = 'event-date';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date']['type'] = 'custom_formatters_important_dates_dates';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_date']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_event_entity_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'event-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_event_entity_ref_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_event_entity_ref_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="[path]">Find out more</a>';
  $handler->display->display_options['fields']['nid']['element_type'] = 'div';
  $handler->display->display_options['fields']['nid']['element_class'] = 'event-link';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
  /* Contextual filter: Paragraphs item: Paragraphs item ID */
  $handler->display->display_options['arguments']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['arguments']['item_id_1']['table'] = 'paragraphs_item';
  $handler->display->display_options['arguments']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id_1']['relationship'] = 'field_event_paragraphs_item';
  $handler->display->display_options['arguments']['item_id_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Paragraphs item: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'paragraphs_item';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'existing_event' => 'existing_event',
    'important_dates' => 'important_dates',
    'new_event' => 'new_event',
  );
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  /* Filter criterion: Content: Event Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['relationship'] = 'field_event_entity_ref_target_id';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 2;
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = 'now';
  /* Filter criterion: Paragraphs item: Event Date - end date (field_event_date:value2) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value2']['group'] = 2;
  $handler->display->display_options['filters']['field_event_date_value2']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $export['important_dates_list'] = $view;

  $view = new view();
  $view->name = 'instagram_feed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'drupagram';
  $view->human_name = 'Instagram Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Instagram Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Instagram Account: Profile picture */
  $handler->display->display_options['fields']['profile_picture']['id'] = 'profile_picture';
  $handler->display->display_options['fields']['profile_picture']['table'] = 'drupagram_account';
  $handler->display->display_options['fields']['profile_picture']['field'] = 'profile_picture';
  $handler->display->display_options['fields']['profile_picture']['label'] = '';
  $handler->display->display_options['fields']['profile_picture']['element_label_colon'] = FALSE;
  /* Field: Instagram: Instagram author username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'drupagram';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['exclude'] = TRUE;
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['source'] = 'standard_resolution';
  $handler->display->display_options['fields']['images']['link_to_post'] = 0;
  /* Field: Instagram: Caption */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'drupagram';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  /* Field: Instagram: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_time']['custom_date_format'] = 'j M y';
  $handler->display->display_options['fields']['created_time']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Instagram Account: Full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'drupagram_account';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['label'] = '';
  $handler->display->display_options['fields']['full_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Instagram: Created time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['instagram_feed'] = $view;

  $view = new view();
  $view->name = 'international_courses_xml';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'International courses XML';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'drupal_node';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title']['id'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title']['label'] = 'title_sortable';
  $handler->display->display_options['fields']['field_course_sort_title']['element_label_colon'] = FALSE;
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title_3']['id'] = 'field_course_sort_title_3';
  $handler->display->display_options['fields']['field_course_sort_title_3']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_3']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_3']['label'] = 'title_study_area';
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title_4']['id'] = 'field_course_sort_title_4';
  $handler->display->display_options['fields']['field_course_sort_title_4']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_4']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_4']['label'] = 'title_level';
  /* Field: Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code']['id'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['label'] = 'code';
  $handler->display->display_options['fields']['field_unit_code']['element_label_colon'] = FALSE;
  /* Field: Content: Cricos code */
  $handler->display->display_options['fields']['field_cricos_code']['id'] = 'field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['table'] = 'field_data_field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['field'] = 'field_cricos_code';
  $handler->display->display_options['fields']['field_cricos_code']['label'] = 'cricos';
  $handler->display->display_options['fields']['field_cricos_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cricos_code']['delta_offset'] = '0';
  /* Field: Content: International */
  $handler->display->display_options['fields']['field_international']['id'] = 'field_international';
  $handler->display->display_options['fields']['field_international']['table'] = 'field_data_field_international';
  $handler->display->display_options['fields']['field_international']['field'] = 'field_international';
  $handler->display->display_options['fields']['field_international']['label'] = 'international';
  $handler->display->display_options['fields']['field_international']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['field_international']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_international']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_international']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_international']['element_label_colon'] = FALSE;
  /* Field: Content: Admission requirements */
  $handler->display->display_options['fields']['field_imp_admission_requirements']['id'] = 'field_imp_admission_requirements';
  $handler->display->display_options['fields']['field_imp_admission_requirements']['table'] = 'field_data_field_imp_admission_requirements';
  $handler->display->display_options['fields']['field_imp_admission_requirements']['field'] = 'field_imp_admission_requirements';
  $handler->display->display_options['fields']['field_imp_admission_requirements']['label'] = 'admission_requirements';
  $handler->display->display_options['fields']['field_imp_admission_requirements']['element_label_colon'] = FALSE;
  /* Field: Content: Career opportunities */
  $handler->display->display_options['fields']['field_imp_career']['id'] = 'field_imp_career';
  $handler->display->display_options['fields']['field_imp_career']['table'] = 'field_data_field_imp_career';
  $handler->display->display_options['fields']['field_imp_career']['field'] = 'field_imp_career';
  $handler->display->display_options['fields']['field_imp_career']['label'] = 'cams_career';
  $handler->display->display_options['fields']['field_imp_career']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_imp_career']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_career']['type'] = 'text_plain';
  /* Field: Content: Career opportunities */
  $handler->display->display_options['fields']['field_career']['id'] = 'field_career';
  $handler->display->display_options['fields']['field_career']['table'] = 'field_data_field_career';
  $handler->display->display_options['fields']['field_career']['field'] = 'field_career';
  $handler->display->display_options['fields']['field_career']['label'] = 'drupal_career';
  $handler->display->display_options['fields']['field_career']['element_label_colon'] = FALSE;
  /* Field: Content: Course Level */
  $handler->display->display_options['fields']['field_unit_lev']['id'] = 'field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['table'] = 'field_data_field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['field'] = 'field_unit_lev';
  $handler->display->display_options['fields']['field_unit_lev']['label'] = 'level';
  $handler->display->display_options['fields']['field_unit_lev']['element_label_colon'] = FALSE;
  /* Field: Content: Imported Description */
  $handler->display->display_options['fields']['field_imp_desc']['id'] = 'field_imp_desc';
  $handler->display->display_options['fields']['field_imp_desc']['table'] = 'field_data_field_imp_desc';
  $handler->display->display_options['fields']['field_imp_desc']['field'] = 'field_imp_desc';
  $handler->display->display_options['fields']['field_imp_desc']['label'] = 'cams_description';
  /* Field: Content: Course search description */
  $handler->display->display_options['fields']['field_description_editable']['id'] = 'field_description_editable';
  $handler->display->display_options['fields']['field_description_editable']['table'] = 'field_data_field_description_editable';
  $handler->display->display_options['fields']['field_description_editable']['field'] = 'field_description_editable';
  $handler->display->display_options['fields']['field_description_editable']['label'] = 'drupal_description';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'faculty';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Victoria University';
  /* Field: Content: College */
  $handler->display->display_options['fields']['field_college']['id'] = 'field_college';
  $handler->display->display_options['fields']['field_college']['table'] = 'field_data_field_college';
  $handler->display->display_options['fields']['field_college']['field'] = 'field_college';
  $handler->display->display_options['fields']['field_college']['label'] = 'school';
  $handler->display->display_options['fields']['field_college']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_college']['type'] = 'link_title_plain';
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['label'] = 'cams_duration';
  /* Field: Content: AQF */
  $handler->display->display_options['fields']['field_course_aqf']['id'] = 'field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['table'] = 'field_data_field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['field'] = 'field_course_aqf';
  $handler->display->display_options['fields']['field_course_aqf']['label'] = 'aqf';
  /* Field: Content: Completion rules */
  $handler->display->display_options['fields']['field_completion_rules']['id'] = 'field_completion_rules';
  $handler->display->display_options['fields']['field_completion_rules']['table'] = 'field_data_field_completion_rules';
  $handler->display->display_options['fields']['field_completion_rules']['field'] = 'field_completion_rules';
  $handler->display->display_options['fields']['field_completion_rules']['label'] = 'units_and_electives';
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title_6']['id'] = 'field_course_sort_title_6';
  $handler->display->display_options['fields']['field_course_sort_title_6']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_6']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_6']['label'] = 'cams_locations';
  /* Field: Content: International fees */
  $handler->display->display_options['fields']['field_international_fees']['id'] = 'field_international_fees';
  $handler->display->display_options['fields']['field_international_fees']['table'] = 'field_data_field_international_fees';
  $handler->display->display_options['fields']['field_international_fees']['field'] = 'field_international_fees';
  $handler->display->display_options['fields']['field_international_fees']['label'] = 'fees';
  $handler->display->display_options['fields']['field_international_fees']['element_label_colon'] = FALSE;
  /* Field: Content: International semester intake */
  $handler->display->display_options['fields']['field_int_sem_int']['id'] = 'field_int_sem_int';
  $handler->display->display_options['fields']['field_int_sem_int']['table'] = 'field_data_field_int_sem_int';
  $handler->display->display_options['fields']['field_int_sem_int']['field'] = 'field_int_sem_int';
  $handler->display->display_options['fields']['field_int_sem_int']['label'] = 'semester_intakes';
  $handler->display->display_options['fields']['field_int_sem_int']['element_label_colon'] = FALSE;
  /* Field: Content: Structure */
  $handler->display->display_options['fields']['field_imp_structure']['id'] = 'field_imp_structure';
  $handler->display->display_options['fields']['field_imp_structure']['table'] = 'field_data_field_imp_structure';
  $handler->display->display_options['fields']['field_imp_structure']['field'] = 'field_imp_structure';
  $handler->display->display_options['fields']['field_imp_structure']['label'] = 'structure';
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title_5']['id'] = 'field_course_sort_title_5';
  $handler->display->display_options['fields']['field_course_sort_title_5']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_5']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_5']['label'] = 'drupal_pathways';
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title_1']['id'] = 'field_course_sort_title_1';
  $handler->display->display_options['fields']['field_course_sort_title_1']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_1']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_1']['label'] = 'study_areas';
  /* Field: Content: Sort title */
  $handler->display->display_options['fields']['field_course_sort_title_2']['id'] = 'field_course_sort_title_2';
  $handler->display->display_options['fields']['field_course_sort_title_2']['table'] = 'field_data_field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_2']['field'] = 'field_course_sort_title';
  $handler->display->display_options['fields']['field_course_sort_title_2']['label'] = 'course_topics';
  /* Field: Content: Study topic and areas */
  $handler->display->display_options['fields']['field_study_topic_area']['id'] = 'field_study_topic_area';
  $handler->display->display_options['fields']['field_study_topic_area']['table'] = 'field_data_field_study_topic_area';
  $handler->display->display_options['fields']['field_study_topic_area']['field'] = 'field_study_topic_area';
  $handler->display->display_options['fields']['field_study_topic_area']['label'] = 'study';
  $handler->display->display_options['fields']['field_study_topic_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_study_topic_area']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_study_topic_area']['delta_offset'] = '0';
  /* Sort criterion: Content: International (field_international) */
  $handler->display->display_options['sorts']['field_international_value']['id'] = 'field_international_value';
  $handler->display->display_options['sorts']['field_international_value']['table'] = 'field_data_field_international';
  $handler->display->display_options['sorts']['field_international_value']['field'] = 'field_international_value';
  $handler->display->display_options['sorts']['field_international_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'courses' => 'courses',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'international-courses.xml';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'underline';
  $handler->display->display_options['style_options']['root_node'] = 'root';
  $handler->display->display_options['style_options']['item_node'] = 'course';
  $handler->display->display_options['style_options']['no_entity_encode'] = array(
    'field_completion_rules' => 'field_completion_rules',
    'field_course_sort_title_6' => 'field_course_sort_title_6',
    'field_international_fees' => 'field_international_fees',
    'field_int_sem_int' => 'field_int_sem_int',
    'field_imp_structure' => 'field_imp_structure',
    'field_course_sort_title_5' => 'field_course_sort_title_5',
    'field_course_sort_title_1' => 'field_course_sort_title_1',
    'field_course_sort_title_2' => 'field_course_sort_title_2',
  );
  $handler->display->display_options['style_options']['cdata_wrapper'] = array(
    'field_career' => 'field_career',
    'field_description_editable' => 'field_description_editable',
    'field_completion_rules' => 'field_completion_rules',
    'field_imp_structure' => 'field_imp_structure',
  );
  $handler->display->display_options['path'] = 'international-courses.xml';
  $export['international_courses_xml'] = $view;

  $view = new view();
  $view->name = 'news_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_article_date|field_article_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'news_listing_page_100x56',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Article Date */
  $handler->display->display_options['fields']['field_article_date']['id'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['fields']['field_article_date']['field'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['label'] = '';
  $handler->display->display_options['fields']['field_article_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_date']['settings'] = array(
    'format_type' => 'vumain_news_listing_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Article Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Media release (field_media_release) */
  $handler->display->display_options['filters']['field_media_release_value']['id'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['table'] = 'field_data_field_media_release';
  $handler->display->display_options['filters']['field_media_release_value']['field'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_media_release_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page news list */
  $handler = $view->new_display('block', 'Page news list', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'news-listing-page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '← Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next →';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = '[field_image_1] clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'picture_mapping' => 'bootstrap_1_col',
    'fallback_image_style' => 'news_listing_page_100x56',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 1,
    'image_link' => '',
    'colorbox_settings' => array(
      'colorbox_group' => 'col_12',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'auto',
      'colorbox_caption_custom' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Article Date */
  $handler->display->display_options['fields']['field_article_date']['id'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['fields']['field_article_date']['field'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['label'] = '';
  $handler->display->display_options['fields']['field_article_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_date']['settings'] = array(
    'format_type' => 'vumain_news_listing_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">
<div class="views-field-field-image">[field_image] </div>
<div class="row-right">
 <h2>[title]</h2>
 <div class="row-meta">[field_article_date]</div>
 <div class="body">[body] </div>
</div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_1']['alter']['text'] = 'with-image';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );

  /* Display: Media releases list */
  $handler = $view->new_display('block', 'Media releases list', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Media releases';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'news-listing-page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '← Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next →';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '160';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '160',
  );
  /* Field: Content: Article Date */
  $handler->display->display_options['fields']['field_article_date']['id'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['fields']['field_article_date']['field'] = 'field_article_date';
  $handler->display->display_options['fields']['field_article_date']['label'] = '';
  $handler->display->display_options['fields']['field_article_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_date']['settings'] = array(
    'format_type' => 'vumain_news_listing_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '<a href=[path]>
  <h2>[title]</h2>
  <div class="media-release-date row-meta">[field_article_date] </div>
  <div class="body">[body]</div>
</a>';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Media release (field_media_release) */
  $handler->display->display_options['filters']['field_media_release_value']['id'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['table'] = 'field_data_field_media_release';
  $handler->display->display_options['filters']['field_media_release_value']['field'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['value'] = array(
    1 => '1',
  );

  /* Display: Victory Homepage News & Media Block */
  $handler = $view->new_display('block', 'Victory Homepage News & Media Block', 'victory_home_news_media');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News & media';
  $handler->display->display_options['display_description'] = 'Victory homepage news';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all news & media';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news-events/news';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_article_date|field_article_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky at top of lists */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Article Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Media release (field_media_release) */
  $handler->display->display_options['filters']['field_media_release_value']['id'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['table'] = 'field_data_field_media_release';
  $handler->display->display_options['filters']['field_media_release_value']['field'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_media_release_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_media_release_value']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Unpin date (field_unpin_date) */
  $handler->display->display_options['filters']['field_unpin_date_value']['id'] = 'field_unpin_date_value';
  $handler->display->display_options['filters']['field_unpin_date_value']['table'] = 'field_data_field_unpin_date';
  $handler->display->display_options['filters']['field_unpin_date_value']['field'] = 'field_unpin_date_value';
  $handler->display->display_options['filters']['field_unpin_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_unpin_date_value']['group'] = 2;
  /* Filter criterion: Content: Unpin date (field_unpin_date) */
  $handler->display->display_options['filters']['field_unpin_date_value_1']['id'] = 'field_unpin_date_value_1';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['table'] = 'field_data_field_unpin_date';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['field'] = 'field_unpin_date_value';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_unpin_date_value_1']['default_date'] = 'now';

  /* Display: Featured news items on landing page */
  $handler = $view->new_display('block', 'Featured news items on landing page', 'victory_featured_news_media_landing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Featured news items on landing page';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all news & media';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news-events/news';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_article_date|field_article_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'alternate_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky at top of lists */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Article Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Media release (field_media_release) */
  $handler->display->display_options['filters']['field_media_release_value']['id'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['table'] = 'field_data_field_media_release';
  $handler->display->display_options['filters']['field_media_release_value']['field'] = 'field_media_release_value';
  $handler->display->display_options['filters']['field_media_release_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_media_release_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_media_release_value']['group'] = 1;
  /* Filter criterion: Content: Unpin date (field_unpin_date) */
  $handler->display->display_options['filters']['field_unpin_date_value']['id'] = 'field_unpin_date_value';
  $handler->display->display_options['filters']['field_unpin_date_value']['table'] = 'field_data_field_unpin_date';
  $handler->display->display_options['filters']['field_unpin_date_value']['field'] = 'field_unpin_date_value';
  $handler->display->display_options['filters']['field_unpin_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_unpin_date_value']['group'] = 2;
  /* Filter criterion: Content: Unpin date (field_unpin_date) */
  $handler->display->display_options['filters']['field_unpin_date_value_1']['id'] = 'field_unpin_date_value_1';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['table'] = 'field_data_field_unpin_date';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['field'] = 'field_unpin_date_value';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_unpin_date_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_unpin_date_value_1']['default_date'] = 'now';
  $export['news_listing'] = $view;

  $view = new view();
  $view->name = 'paragraphs_section_navigation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'paragraphs_item';
  $view->human_name = 'Paragraphs: On this page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Paragraphs item: Entity with the Page sections (field_page_paragraphs) */
  $handler->display->display_options['relationships']['field_page_paragraphs_node']['id'] = 'field_page_paragraphs_node';
  $handler->display->display_options['relationships']['field_page_paragraphs_node']['table'] = 'paragraphs_item';
  $handler->display->display_options['relationships']['field_page_paragraphs_node']['field'] = 'field_page_paragraphs_node';
  $handler->display->display_options['relationships']['field_page_paragraphs_node']['label'] = 'Host Node';
  /* Field: Paragraphs item: Section title (h2) */
  $handler->display->display_options['fields']['field_section_title']['id'] = 'field_section_title';
  $handler->display->display_options['fields']['field_section_title']['table'] = 'field_data_field_section_title';
  $handler->display->display_options['fields']['field_section_title']['field'] = 'field_section_title';
  $handler->display->display_options['fields']['field_section_title']['label'] = '';
  $handler->display->display_options['fields']['field_section_title']['element_label_colon'] = FALSE;
  /* Field: Paragraphs item: Section title (h2) */
  $handler->display->display_options['fields']['field_section_title_1']['id'] = 'field_section_title_1';
  $handler->display->display_options['fields']['field_section_title_1']['table'] = 'field_data_field_section_title';
  $handler->display->display_options['fields']['field_section_title_1']['field'] = 'field_section_title';
  $handler->display->display_options['fields']['field_section_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_section_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_section_title_1']['type'] = 'custom_formatters_title_id';
  /* Field: Paragraphs item: Component section title (h2) */
  $handler->display->display_options['fields']['field_component_section_title']['id'] = 'field_component_section_title';
  $handler->display->display_options['fields']['field_component_section_title']['table'] = 'field_data_field_component_section_title';
  $handler->display->display_options['fields']['field_component_section_title']['field'] = 'field_component_section_title';
  $handler->display->display_options['fields']['field_component_section_title']['label'] = '';
  $handler->display->display_options['fields']['field_component_section_title']['element_label_colon'] = FALSE;
  /* Field: Paragraphs item: Component section title (h2) */
  $handler->display->display_options['fields']['field_component_section_title_1']['id'] = 'field_component_section_title_1';
  $handler->display->display_options['fields']['field_component_section_title_1']['table'] = 'field_data_field_component_section_title';
  $handler->display->display_options['fields']['field_component_section_title_1']['field'] = 'field_component_section_title';
  $handler->display->display_options['fields']['field_component_section_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_component_section_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_section_title_1']['type'] = 'custom_formatters_title_id';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_page_paragraphs_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Paragraphs item: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'paragraphs_item';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'component_section' => 'component_section',
    'section' => 'section',
  );
  $export['paragraphs_section_navigation'] = $view;

  $view = new view();
  $view->name = 'short_dates_and_times_revision';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Short dates and times';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Short course dates and times';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_short_date_times' => 'field_short_date_times',
    'field_short_date_times_1' => 'field_short_date_times_1',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_short_date_times' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_date_times_1' => array(
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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_short_dates_times_target_id']['id'] = 'field_short_dates_times_target_id';
  $handler->display->display_options['relationships']['field_short_dates_times_target_id']['table'] = 'field_revision_field_short_dates_times';
  $handler->display->display_options['relationships']['field_short_dates_times_target_id']['field'] = 'field_short_dates_times_target_id';
  $handler->display->display_options['relationships']['field_short_dates_times_target_id']['required'] = TRUE;
  /* Field: Inline Entities: Course dates and times */
  $handler->display->display_options['fields']['field_short_date_times']['id'] = 'field_short_date_times';
  $handler->display->display_options['fields']['field_short_date_times']['table'] = 'field_data_field_short_date_times';
  $handler->display->display_options['fields']['field_short_date_times']['field'] = 'field_short_date_times';
  $handler->display->display_options['fields']['field_short_date_times']['relationship'] = 'field_short_dates_times_target_id';
  $handler->display->display_options['fields']['field_short_date_times']['label'] = '';
  $handler->display->display_options['fields']['field_short_date_times']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_short_date_times']['type'] = 'custom_formatters_short_course_day_format';
  $handler->display->display_options['fields']['field_short_date_times']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Inline Entities: Course dates and times */
  $handler->display->display_options['fields']['field_short_date_times_1']['id'] = 'field_short_date_times_1';
  $handler->display->display_options['fields']['field_short_date_times_1']['table'] = 'field_data_field_short_date_times';
  $handler->display->display_options['fields']['field_short_date_times_1']['field'] = 'field_short_date_times';
  $handler->display->display_options['fields']['field_short_date_times_1']['relationship'] = 'field_short_dates_times_target_id';
  $handler->display->display_options['fields']['field_short_date_times_1']['label'] = '';
  $handler->display->display_options['fields']['field_short_date_times_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_short_date_times_1']['type'] = 'custom_formatters_short_course_time_format';
  $handler->display->display_options['fields']['field_short_date_times_1']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Inline Entities: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_inline_entities';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_short_dates_times_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Inline Entities: Course dates and times -  start date (field_short_date_times) */
  $handler->display->display_options['sorts']['field_short_date_times_value']['id'] = 'field_short_date_times_value';
  $handler->display->display_options['sorts']['field_short_date_times_value']['table'] = 'field_data_field_short_date_times';
  $handler->display->display_options['sorts']['field_short_date_times_value']['field'] = 'field_short_date_times_value';
  $handler->display->display_options['sorts']['field_short_date_times_value']['relationship'] = 'field_short_dates_times_target_id';
  /* Contextual filter: Content revision: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Inline Entities: Course dates and times -  start date (field_short_date_times) */
  $handler->display->display_options['filters']['field_short_date_times_value']['id'] = 'field_short_date_times_value';
  $handler->display->display_options['filters']['field_short_date_times_value']['table'] = 'field_data_field_short_date_times';
  $handler->display->display_options['filters']['field_short_date_times_value']['field'] = 'field_short_date_times_value';
  $handler->display->display_options['filters']['field_short_date_times_value']['relationship'] = 'field_short_dates_times_target_id';
  $handler->display->display_options['filters']['field_short_date_times_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_short_date_times_value']['group'] = 1;
  $handler->display->display_options['filters']['field_short_date_times_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['short_dates_and_times_revision'] = $view;

  $view = new view();
  $view->name = 'study_areas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Study Areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Study Areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Study topics (field_study_topic) */
  $handler->display->display_options['arguments']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study_topic_area' => 'study_topic_area',
  );

  /* Display: List study areas */
  $handler = $view->new_display('block', 'List study areas', 'list_study_areas');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Study Areas';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class=\'title\'>[title]</span>
[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Study topics (field_study_topic) */
  $handler->display->display_options['arguments']['field_study_topic_target_id']['id'] = 'field_study_topic_target_id';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['table'] = 'field_data_field_study_topic';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['field'] = 'field_study_topic_target_id';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_study_topic_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Related Study Areas */
  $handler = $view->new_display('block', 'Related Study Areas', 'related_study_areas');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_study_areas_target_id']['id'] = 'field_related_study_areas_target_id';
  $handler->display->display_options['relationships']['field_related_study_areas_target_id']['table'] = 'field_data_field_related_study_areas';
  $handler->display->display_options['relationships']['field_related_study_areas_target_id']['field'] = 'field_related_study_areas_target_id';
  $handler->display->display_options['relationships']['field_related_study_areas_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Related Study Areas */
  $handler->display->display_options['fields']['field_related_study_areas']['id'] = 'field_related_study_areas';
  $handler->display->display_options['fields']['field_related_study_areas']['table'] = 'field_data_field_related_study_areas';
  $handler->display->display_options['fields']['field_related_study_areas']['field'] = 'field_related_study_areas';
  $handler->display->display_options['fields']['field_related_study_areas']['label'] = '';
  $handler->display->display_options['fields']['field_related_study_areas']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_study_areas']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_related_study_areas']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_related_study_areas']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_related_study_areas']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_related_study_areas']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_related_study_areas']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_related_study_areas_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study_topic_area' => 'study_topic_area',
  );
  $export['study_areas'] = $view;

  $view = new view();
  $view->name = 'success_stories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Success Stories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_course_grouping',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '100x56',
    'image_link' => '',
  );
  /* Field: Content: Course grouping */
  $handler->display->display_options['fields']['field_course_grouping']['id'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['field'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['label'] = '';
  $handler->display->display_options['fields']['field_course_grouping']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_grouping']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Excerpt or quote */
  $handler->display->display_options['fields']['field_excerpt']['id'] = 'field_excerpt';
  $handler->display->display_options['fields']['field_excerpt']['table'] = 'field_data_field_excerpt';
  $handler->display->display_options['fields']['field_excerpt']['field'] = 'field_excerpt';
  $handler->display->display_options['fields']['field_excerpt']['label'] = '';
  $handler->display->display_options['fields']['field_excerpt']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Course grouping (field_course_grouping) */
  $handler->display->display_options['sorts']['field_course_grouping_value']['id'] = 'field_course_grouping_value';
  $handler->display->display_options['sorts']['field_course_grouping_value']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['sorts']['field_course_grouping_value']['field'] = 'field_course_grouping_value';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Course grouping (field_course_grouping) */
  $handler->display->display_options['filters']['field_course_grouping_value']['id'] = 'field_course_grouping_value';
  $handler->display->display_options['filters']['field_course_grouping_value']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['filters']['field_course_grouping_value']['field'] = 'field_course_grouping_value';
  $handler->display->display_options['filters']['field_course_grouping_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_course_grouping_value']['group'] = 1;
  /* Filter criterion: Content: Categories (field_success_categories) */
  $handler->display->display_options['filters']['field_success_categories_tid']['id'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['table'] = 'field_data_field_success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['field'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['value'] = array(
    52521 => '52521',
    55181 => '55181',
  );
  $handler->display->display_options['filters']['field_success_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_success_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_success_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_success_categories_tid']['vocabulary'] = 'success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['hierarchy'] = 1;

  /* Display: Students and Alumni */
  $handler = $view->new_display('block', 'Students and Alumni', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '100x56',
    'image_link' => '',
  );
  /* Field: Content: Course grouping */
  $handler->display->display_options['fields']['field_course_grouping']['id'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['field'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['label'] = '';
  $handler->display->display_options['fields']['field_course_grouping']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_grouping']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'image\'>[field_image]</div>
<div class=\'right\'>
<div class=\'title\'>[title]</div>
<div class=\'excerpt\'>[body]</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Course grouping (field_course_grouping) */
  $handler->display->display_options['filters']['field_course_grouping_value']['id'] = 'field_course_grouping_value';
  $handler->display->display_options['filters']['field_course_grouping_value']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['filters']['field_course_grouping_value']['field'] = 'field_course_grouping_value';
  $handler->display->display_options['filters']['field_course_grouping_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_course_grouping_value']['group'] = 1;
  /* Filter criterion: Content: Categories (field_success_categories) */
  $handler->display->display_options['filters']['field_success_categories_tid']['id'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['table'] = 'field_data_field_success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['field'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['value'] = array(
    362901 => '362901',
  );
  $handler->display->display_options['filters']['field_success_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_success_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_success_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_success_categories_tid']['vocabulary'] = 'success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['hierarchy'] = 1;

  /* Display: Staff */
  $handler = $view->new_display('block', 'Staff', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '100x56',
    'image_link' => '',
  );
  /* Field: Content: Course grouping */
  $handler->display->display_options['fields']['field_course_grouping']['id'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['field'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['label'] = '';
  $handler->display->display_options['fields']['field_course_grouping']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_grouping']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'image\'>[field_image]</div>
<div class=\'right\'>
<div class=\'title\'>[title]</div>
<div class=\'excerpt\'>[body]</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Categories (field_success_categories) */
  $handler->display->display_options['filters']['field_success_categories_tid']['id'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['table'] = 'field_data_field_success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['field'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['value'] = array(
    362896 => '362896',
  );
  $handler->display->display_options['filters']['field_success_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_success_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_success_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_success_categories_tid']['vocabulary'] = 'success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['hierarchy'] = 1;

  /* Display: Partners & Projects */
  $handler = $view->new_display('block', 'Partners & Projects', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '100x56',
    'image_link' => '',
  );
  /* Field: Content: Course grouping */
  $handler->display->display_options['fields']['field_course_grouping']['id'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['field'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['label'] = '';
  $handler->display->display_options['fields']['field_course_grouping']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_grouping']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'image\'>[field_image]</div>
<div class=\'right\'>
<div class=\'title\'>[title]</div>
<div class=\'excerpt\'>[body]</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Categories (field_success_categories) */
  $handler->display->display_options['filters']['field_success_categories_tid']['id'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['table'] = 'field_data_field_success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['field'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['value'] = array(
    362906 => '362906',
  );
  $handler->display->display_options['filters']['field_success_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_success_categories_tid']['vocabulary'] = 'success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['hierarchy'] = 1;
  /* Filter criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';

  /* Display: Employers Testimonials */
  $handler = $view->new_display('block', 'Employers Testimonials', 'block_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '100x56',
    'image_link' => '',
  );
  /* Field: Content: Course grouping */
  $handler->display->display_options['fields']['field_course_grouping']['id'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['field'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['label'] = '';
  $handler->display->display_options['fields']['field_course_grouping']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_grouping']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'image\'>[field_image]</div>
<div class=\'right\'>
<div class=\'title\'>[title]</div>
<div class=\'excerpt\'>[body]</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Categories (field_success_categories) */
  $handler->display->display_options['filters']['field_success_categories_tid']['id'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['table'] = 'field_data_field_success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['field'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['value'] = array(
    371246 => '371246',
  );
  $handler->display->display_options['filters']['field_success_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_success_categories_tid']['vocabulary'] = 'success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['hierarchy'] = 1;
  /* Filter criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';

  /* Display: VU English Testimonials */
  $handler = $view->new_display('block', 'VU English Testimonials', 'block_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '100x56',
    'image_link' => '',
  );
  /* Field: Content: Course grouping */
  $handler->display->display_options['fields']['field_course_grouping']['id'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['table'] = 'field_data_field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['field'] = 'field_course_grouping';
  $handler->display->display_options['fields']['field_course_grouping']['label'] = '';
  $handler->display->display_options['fields']['field_course_grouping']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_grouping']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'image\'>[field_image]</div>
<div class=\'right\'>
<div class=\'title\'>[title]</div>
<div class=\'excerpt\'>[body]</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Categories (field_success_categories) */
  $handler->display->display_options['filters']['field_success_categories_tid']['id'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['table'] = 'field_data_field_success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['field'] = 'field_success_categories_tid';
  $handler->display->display_options['filters']['field_success_categories_tid']['value'] = array(
    1110126 => '1110126',
  );
  $handler->display->display_options['filters']['field_success_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_success_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_success_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_success_categories_tid']['vocabulary'] = 'success_categories';
  $handler->display->display_options['filters']['field_success_categories_tid']['hierarchy'] = 1;
  $export['success_stories'] = $view;

  $view = new view();
  $view->name = 'unit_fees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Unit Fees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Unit Fees';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_unit_target_id']['id'] = 'field_unit_target_id';
  $handler->display->display_options['relationships']['field_unit_target_id']['table'] = 'field_data_field_unit';
  $handler->display->display_options['relationships']['field_unit_target_id']['field'] = 'field_unit_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_course_target_id']['id'] = 'field_course_target_id';
  $handler->display->display_options['relationships']['field_course_target_id']['table'] = 'field_data_field_course';
  $handler->display->display_options['relationships']['field_course_target_id']['field'] = 'field_course_target_id';
  /* Field: Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code']['id'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['fields']['field_unit_code']['label'] = '';
  $handler->display->display_options['fields']['field_unit_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Disclaimers */
  $handler->display->display_options['fields']['field_disclaimers']['id'] = 'field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['table'] = 'field_data_field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['field'] = 'field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['label'] = '';
  $handler->display->display_options['fields']['field_disclaimers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_disclaimers']['delta_offset'] = '0';
  /* Field: Content: Credit Points */
  $handler->display->display_options['fields']['field_credit_points']['id'] = 'field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['table'] = 'field_data_field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['field'] = 'field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['label'] = '';
  $handler->display->display_options['fields']['field_credit_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Sector */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['label'] = '';
  $handler->display->display_options['fields']['field_sector']['element_label_colon'] = FALSE;
  /* Field: Content: EFTSL */
  $handler->display->display_options['fields']['field_eftsl']['id'] = 'field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['table'] = 'field_data_field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['field'] = 'field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['label'] = '';
  $handler->display->display_options['fields']['field_eftsl']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eftsl']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '3',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Contact Hours */
  $handler->display->display_options['fields']['field_contact_hours']['id'] = 'field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['table'] = 'field_data_field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['field'] = 'field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['label'] = '';
  $handler->display->display_options['fields']['field_contact_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fee */
  $handler->display->display_options['fields']['field_fee']['id'] = 'field_fee';
  $handler->display->display_options['fields']['field_fee']['table'] = 'field_data_field_fee';
  $handler->display->display_options['fields']['field_fee']['field'] = 'field_fee';
  $handler->display->display_options['fields']['field_fee']['label'] = '';
  $handler->display->display_options['fields']['field_fee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fee']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fee Type */
  $handler->display->display_options['fields']['field_fee_type']['id'] = 'field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['table'] = 'field_data_field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['field'] = 'field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['label'] = '';
  $handler->display->display_options['fields']['field_fee_type']['element_label_colon'] = FALSE;
  /* Field: Field: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = '';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'search_api_facetapi_YEAR',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Hourly Rate */
  $handler->display->display_options['fields']['field_hourly_rate']['id'] = 'field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['table'] = 'field_data_field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['field'] = 'field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['label'] = '';
  $handler->display->display_options['fields']['field_hourly_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hourly_rate']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_course_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'unit_fees' => 'unit_fees',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_year_value']['granularity'] = 'year';
  /* Filter criterion: Content: Course Code (field_unit_code) */
  $handler->display->display_options['filters']['field_unit_code_value']['id'] = 'field_unit_code_value';
  $handler->display->display_options['filters']['field_unit_code_value']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['filters']['field_unit_code_value']['field'] = 'field_unit_code_value';
  $handler->display->display_options['filters']['field_unit_code_value']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['filters']['field_unit_code_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_unit_code_value']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 2;
  /* Filter criterion: Content: Fee Type (field_fee_type) */
  $handler->display->display_options['filters']['field_fee_type_tid']['id'] = 'field_fee_type_tid';
  $handler->display->display_options['filters']['field_fee_type_tid']['table'] = 'field_data_field_fee_type';
  $handler->display->display_options['filters']['field_fee_type_tid']['field'] = 'field_fee_type_tid';
  $handler->display->display_options['filters']['field_fee_type_tid']['value'] = array(
    1699837 => '1699837',
    1699838 => '1699838',
    1699843 => '1699843',
    1699844 => '1699844',
    1699839 => '1699839',
    1699841 => '1699841',
    1699842 => '1699842',
    1699840 => '1699840',
  );
  $handler->display->display_options['filters']['field_fee_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fee_type_tid']['vocabulary'] = 'fee_types';

  /* Display: TAFE Block */
  $handler = $view->new_display('block', 'TAFE Block', 've');

  /* Display: Higher Ed Block */
  $handler = $view->new_display('block', 'Higher Ed Block', 'he');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_unit_target_id']['id'] = 'field_unit_target_id';
  $handler->display->display_options['relationships']['field_unit_target_id']['table'] = 'field_data_field_unit';
  $handler->display->display_options['relationships']['field_unit_target_id']['field'] = 'field_unit_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Course Code */
  $handler->display->display_options['fields']['field_unit_code']['id'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['table'] = 'field_data_field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['field'] = 'field_unit_code';
  $handler->display->display_options['fields']['field_unit_code']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['fields']['field_unit_code']['label'] = '';
  $handler->display->display_options['fields']['field_unit_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_unit_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Disclaimers */
  $handler->display->display_options['fields']['field_disclaimers']['id'] = 'field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['table'] = 'field_data_field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['field'] = 'field_disclaimers';
  $handler->display->display_options['fields']['field_disclaimers']['label'] = '';
  $handler->display->display_options['fields']['field_disclaimers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_disclaimers']['delta_offset'] = '0';
  /* Field: Content: Credit Points */
  $handler->display->display_options['fields']['field_credit_points']['id'] = 'field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['table'] = 'field_data_field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['field'] = 'field_credit_points';
  $handler->display->display_options['fields']['field_credit_points']['label'] = '';
  $handler->display->display_options['fields']['field_credit_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Sector */
  $handler->display->display_options['fields']['field_sector']['id'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['table'] = 'field_data_field_sector';
  $handler->display->display_options['fields']['field_sector']['field'] = 'field_sector';
  $handler->display->display_options['fields']['field_sector']['label'] = '';
  $handler->display->display_options['fields']['field_sector']['element_label_colon'] = FALSE;
  /* Field: Content: EFTSL */
  $handler->display->display_options['fields']['field_eftsl']['id'] = 'field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['table'] = 'field_data_field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['field'] = 'field_eftsl';
  $handler->display->display_options['fields']['field_eftsl']['label'] = '';
  $handler->display->display_options['fields']['field_eftsl']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eftsl']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '3',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Contact Hours */
  $handler->display->display_options['fields']['field_contact_hours']['id'] = 'field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['table'] = 'field_data_field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['field'] = 'field_contact_hours';
  $handler->display->display_options['fields']['field_contact_hours']['label'] = '';
  $handler->display->display_options['fields']['field_contact_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fee */
  $handler->display->display_options['fields']['field_fee']['id'] = 'field_fee';
  $handler->display->display_options['fields']['field_fee']['table'] = 'field_data_field_fee';
  $handler->display->display_options['fields']['field_fee']['field'] = 'field_fee';
  $handler->display->display_options['fields']['field_fee']['label'] = '';
  $handler->display->display_options['fields']['field_fee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fee']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fee Type */
  $handler->display->display_options['fields']['field_fee_type']['id'] = 'field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['table'] = 'field_data_field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['field'] = 'field_fee_type';
  $handler->display->display_options['fields']['field_fee_type']['label'] = '';
  $handler->display->display_options['fields']['field_fee_type']['element_label_colon'] = FALSE;
  /* Field: Field: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = '';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'search_api_facetapi_YEAR',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Hourly Rate */
  $handler->display->display_options['fields']['field_hourly_rate']['id'] = 'field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['table'] = 'field_data_field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['field'] = 'field_hourly_rate';
  $handler->display->display_options['fields']['field_hourly_rate']['label'] = '';
  $handler->display->display_options['fields']['field_hourly_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hourly_rate']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $export['unit_fees'] = $view;

  $view = new view();
  $view->name = 'vu_courses_related';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Courses: Related';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_courses_target_id']['id'] = 'field_related_courses_target_id';
  $handler->display->display_options['relationships']['field_related_courses_target_id']['table'] = 'field_revision_field_related_courses';
  $handler->display->display_options['relationships']['field_related_courses_target_id']['field'] = 'field_related_courses_target_id';
  $handler->display->display_options['relationships']['field_related_courses_target_id']['label'] = 'Related courses';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_courses_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: Content revision: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_related_courses_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_related_courses_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'courses' => 'courses',
  );

  /* Display: Related courses */
  $handler = $view->new_display('block', 'Related courses', 'block');
  $handler->display->display_options['block_description'] = 'Related courses';
  $handler->display->display_options['block_caching'] = '4';
  $export['vu_courses_related'] = $view;

  return $export;
}
