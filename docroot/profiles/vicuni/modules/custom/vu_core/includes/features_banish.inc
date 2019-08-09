<?php

/**
 * @file
 * Features banish module integration.
 */

/**
 * Implements hook_features_banish_alter().
 */
function vu_core_features_banish_alter(&$banished_items) {
  $additional_items = [
    'variable' => [
      'aes_key',
      'block_cache',
      'cache',
      'cache_class_cache_ctools_css',
      'cache_flush_*',
      'context_block_rebuild_needed',
      // Changes when cron is run.
      'cron_last',
      'node_cron_last',
      'drupal_test_email_collector',
      'test_user_verify_lock',
      'mail_system',
      'smart_notification_cron_last_run',
      // Security: Allows for running cron.php remotely.
      'cron_key',
      'custom_search_*',
      // What install task the site is currently on.
      'install_task',
      // An error flag when Drupal can't talk to the internet.
      'drupal_http_request_fails',
      // A list css files that are being cached by drupal.
      'drupal_css_cache_files',
      // A list js files that are being cached by drupal.
      'drupal_js_cache_files',
      'default_nodes_main',
      'dev_query',
      'domain_bootstrap_modules',
      'entityreference:base-tables',
      'googleanalytics_debug',
      'heartbeat_*',
      // Cached parent-child relationships of menu items.
      'menu_masks',
      'mobile_number_secret',
      // The last timestamp when module updates were checked.
      'update_last_check',
      // Changes each time the css and jss cache is reset.
      'css_js_query_string',
      // Flag when the site is in maintenance mode.
      'maintenance_mode',
      // Private key used to generate tokens.
      'drupal_private_key',
      // Cached md5 hash of features export objects.
      'features_codecache',
      'features_modules_changed',
      // Used to avoid race conditions.
      'features_semaphore',
      // Cache of orphaned features.
      'features_ignored_orphans',
      // Install timestamp.
      'install_time',
      'menu_expanded',
      // CTools - Last cron run timestamp.
      'ctools_last_cron',
      // Entity API - List of entity cache tables.
      'entity_cache_tables_created',
      // Module Filter - Recent modules timestamps.
      'module_filter_recent_modules',
      'node_access_needs_rebuild',
      'node_rank_*',
      // Rules.
      'rules_debug',
      'rules_debug_*',
      'rules_log_*',
      'rules_path_cleaning_callback',
      'statistics_day_timestamp',
      'statistics_count_content_views',
      'statistics_count_content_views_ajax',
      'statistics_flush_accesslog_timer',
      'update_last_email_notification',
      'user_relationships_last_expire',
      'user_relationships_privatemsg_autocomplete_alter',
      'views_block_hashes',
      'views_ui_*',
      // All diff settings.
      'diff_*',
      'save_continue_*',
    ],
    'menu_custom' => [
      'devel',
      'features',
      'management',
      'navigation',
      'user-menu',
    ],
    // Views shipped with contribs.
    'views_view' => [
      'entity_pager_example',
      'redirects',
      'legal_terms',
      'legal_users',
    ],
    // Menu links are content.
    'menu_links' => [
      '*',
    ],
  ];

  $banished_items = array_merge($banished_items, $additional_items);

  // Banish most of the annoying __active_tab variables.
  global $conf;
  $keys = array_keys($conf);
  foreach ($keys as $key) {
    if (strpos($key, '__active_tab') !== FALSE) {
      $banished_items['variable'][] = $key;
    }
  }
}
