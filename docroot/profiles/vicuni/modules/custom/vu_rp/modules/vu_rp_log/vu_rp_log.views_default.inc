<?php
/**
 * @file
 * vu_rp_log.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vu_rp_log_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'researcher_profile_logs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'vu_rp_log';
  $view->human_name = 'Researcher Profile Logs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Researcher Profile Configuration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access researcher profile api log';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'event' => 'event',
    'timestamp' => 'timestamp',
    'severity' => 'severity',
    'message' => 'message',
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'event' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'severity' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Clear button';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="admin-panel">
    <p>This will permanently remove the log messages from the database.</p>
    <a class="button" href="/admin/config/researcher-profile/log/clear">
      Clear log messages
    </a>
  </div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no records';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Researchers Profile Logs: Event */
  $handler->display->display_options['fields']['event']['id'] = 'event';
  $handler->display->display_options['fields']['event']['table'] = 'vu_rp_log';
  $handler->display->display_options['fields']['event']['field'] = 'event';
  /* Field: Researchers Profile Logs: Date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'vu_rp_log';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'Y/m/d H:i:s';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Researchers Profile Logs: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'vu_rp_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  /* Field: Researchers Profile Logs: Message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'vu_rp_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['message']['alter']['text'] = '<pre class=\'pre-style\'>
      [message]
    </pre>';
  /* Field: Researchers Profile Logs: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'vu_rp_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'View';
  $handler->display->display_options['fields']['id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'admin/config/researcher-profile/log/[id]';
  /* Sort criterion: Researchers Profile Logs: ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'vu_rp_log';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Researchers Profile Logs: Event */
  $handler->display->display_options['filters']['event']['id'] = 'event';
  $handler->display->display_options['filters']['event']['table'] = 'vu_rp_log';
  $handler->display->display_options['filters']['event']['field'] = 'event';
  $handler->display->display_options['filters']['event']['group'] = 1;
  $handler->display->display_options['filters']['event']['exposed'] = TRUE;
  $handler->display->display_options['filters']['event']['expose']['operator_id'] = 'event_op';
  $handler->display->display_options['filters']['event']['expose']['label'] = 'Event';
  $handler->display->display_options['filters']['event']['expose']['operator'] = 'event_op';
  $handler->display->display_options['filters']['event']['expose']['identifier'] = 'event';
  $handler->display->display_options['filters']['event']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['event']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['event']['group_info']['label'] = 'Event';
  $handler->display->display_options['filters']['event']['group_info']['identifier'] = 'event';
  $handler->display->display_options['filters']['event']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['event']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Researchers Profile Logs: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'vu_rp_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['group'] = 1;
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator_id'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['filters']['severity']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['remember_roles'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/researcher-profile/log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Log';
  $handler->display->display_options['menu']['weight'] = '91';
  $handler->display->display_options['menu']['name'] = 'menu-researcher-profile-admin';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  $export['researcher_profile_logs'] = $view;

  return $export;
}
