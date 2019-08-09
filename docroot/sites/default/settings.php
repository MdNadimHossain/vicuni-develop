<?php

/**
 * @file
 * Drupal settings.
 *
 * Create settings.local.php file to include local settings overrides.
 */

// Environment constants.
// Use these constants anywhere in code to alter behaviour for specific
// environment.
if (!defined('ENVIRONMENT_LOCAL')) {
  define('ENVIRONMENT_LOCAL', 'local');
}
if (!defined('ENVIRONMENT_CI')) {
  define('ENVIRONMENT_CI', 'ci');
}
if (!defined('ENVIRONMENT_PROD')) {
  define('ENVIRONMENT_PROD', 'prod');
}
if (!defined('ENVIRONMENT_TEST')) {
  define('ENVIRONMENT_TEST', 'test');
}
if (!defined('ENVIRONMENT_TEST2')) {
  define('ENVIRONMENT_TEST2', 'test2');
}
if (!defined('ENVIRONMENT_DEV')) {
  define('ENVIRONMENT_DEV', 'dev');
}
$conf['environment'] = ENVIRONMENT_LOCAL;

if (!function_exists('cidr_match')) {

  /**
   * Check an IP to see if it's within the given range.
   */
  function cidr_match($ip, $cidr) {
    list($subnet, $mask) = explode('/', $cidr);

    return (ip2long($ip) & ~((1 << (32 - $mask)) - 1)) == ip2long($subnet);
  }

}
////////////////////////////////////////////////////////////////////////////////
///                       SITE-SPECIFIC SETTINGS                             ///
////////////////////////////////////////////////////////////////////////////////

// Include Acquia settings.
if (file_exists('/var/www/site-php')) {
  // Delay the initial database connection.
  $conf['acquia_hosting_settings_autoconnect'] = FALSE;
  // The standard require line goes here.
  require '/var/www/site-php/vueduau/vueduau-settings.inc';
  // Alter the charset and collation of the databases.
  $databases['vueduau']['default']['charset'] = 'utf8mb4';
  $databases['vueduau']['default']['collation'] = 'utf8mb4_general_ci';
  // Now connect to the default database.
  acquia_hosting_db_choose_active();
}
else {
  // If we're not on Acquia, use local memcache server.
  $conf['memcache_servers'] = [
    'memcached:11211' => 'default',
  ];
}

// Session variables.
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);

// Set the default timezone globally.
ini_set('date.timezone', 'Australia/Melbourne');
date_default_timezone_set('Australia/Melbourne');

$update_free_access = FALSE;

// Fast404 settings.
$conf['404_fast_paths_exclude'] = '/\/(?:styles)|(?:system\/files)\//';
$conf['404_fast_paths'] = '/\.*$/i';
$conf['404_fast_html'] = file_get_contents(DRUPAL_ROOT . '/profiles/vicuni/modules/custom/vu_core/html/404.html');

// Admin theme.
$conf['admin_theme'] = 'seven';
// Use admin theme on nodes.
$conf['node_admin_theme'] = 1;
$conf['admin_theme_path'] = "node/add*\nnode/*/edit\nadmin*\ntaxonomy/term/*/edit";
// Use admin theme during batch processing.
$conf['admin_theme_admin_theme_batch'] = 1;

// Preprocess CSS and JS.
$conf['preprocess_css'] = 1;
$conf['preprocess_js'] = 1;
// Disable page compression by default as it may cause cache invalidation
// issues for Varnish on Acquia.
// @see https://docs.acquia.com/acquia-cloud/performance/varnish
$conf['page_compression'] = 0;

// Shield is disabled by default.
$conf['shield_user'] = NULL;

$conf['search_cron_limit'] = 5;

$conf['googleanalytics_account'] = 'UA-';
// @todo: Clarify why cache lifetime is set to 0.
$conf['cache_lifetime'] = 0;
// Disabled because we revert features with update hooks, not every cache clear.
$conf['features_rebuild_on_flush'] = FALSE;
$conf['entity_rebuild_on_flush'] = FALSE;
$conf['cron_safe_threshold'] = 0;
// This is to work around a bug in redirect module.
// @see https://www.drupal.org/node/2567651.
$conf['redirect_purge_inactive'] = 0;

// Memcache servers. Skipped on CI for now to avoid homepage test issues.
$memcache_bin_file = 'profiles/vicuni/modules/contrib/memcache/memcache.inc';
if (isset($conf['memcache_servers']) && file_exists($memcache_bin_file)) {
  $conf['cache_backends'][] = $memcache_bin_file;
  $conf['cache_default_class'] = 'MemCacheDrupal';
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

  // Use memcache for locks instead of the database.
  $conf['lock_inc'] = 'profiles/vicuni/modules/contrib/memcache/memcache-lock.inc';
}

////////////////////////////////////////////////////////////////////////////////
///                   END OF SITE-SPECIFIC SETTINGS                          ///
////////////////////////////////////////////////////////////////////////////////

// Acquia per-environment overrides.
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  ini_set('memory_limit', '192M');
  // Disabling NewRelic imposed max nesting level in Acquia platform.
  ini_set('newrelic.special.max_nesting_level', -1);

  // Set Acquia purge to use https, not http (www is only SSL).
  // @see https://insight.acquia.com/support/tickets/329126.
  $conf['acquia_purge_https'] = TRUE;
  $conf['acquia_purge_http'] = FALSE;

  // This is to try and resolve logged in users getting served anonymously
  // cached pages.
  // @see http://drupal.stackexchange.com/q/53467.
  $conf['omit_vary_cookie'] = FALSE;

  // Settings for all Acquia environments.
  if (isset($_ENV['AH_SITE_GROUP'])) {
    // Increase resources for large pages.
    if (isset($_GET['q']) && strpos($_GET['q'], 'admin') === 0 ||
      strpos($_GET['q'], 'node/add') === 0 ||
      strpos($_GET['q'], 'file/ajax/upload') === 0 ||
      strpos($_GET['q'], 'block/add') === 0 ||
      (strpos($_GET['q'], 'block/') === 0 && preg_match('/^node\/[a-zA-Z]+\/edit/', $_GET['q']) === 1) ||
      (strpos($_GET['q'], 'node/') === 0 && preg_match('/^node\/[\d]+\/edit/', $_GET['q']) === 1)
    ) {
      ini_set('memory_limit', '512M');
      ini_set('max_input_vars', '2000');
    }

    $conf['plupload_temporary_uri'] = "/mnt/gfs/{$_ENV['AH_SITE_GROUP']}.{$_ENV['AH_SITE_ENVIRONMENT']}/tmp";

    $conf['gtm_id'] = 'GTM-TNRVD4';
    $conf['vu_fb_page_plugin'] = TRUE;
  }

  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'dev':
      $conf['environment'] = ENVIRONMENT_DEV;

      // Google analytics staging account.
      $conf['googleanalytics_account'] = 'UA-1582839-25';

      $conf['shield_user'] = 'vu';
      $conf['shield_pass'] = '46>GwfCp';
      $conf['shield_print'] = '';

      $conf['search_api_acquia_overrides']['acquia_search_server'] = [
        'path' => '/solr/ILUY-91754.dev.default',
        'host' => 'apsoutheast2-c32.acquia-search.com',
        'derived_key' => '35d77d88d3f36fb8fede11deef6bdab7b15fe210',
      ];
      break;

    case 'test':
      $conf['environment'] = ENVIRONMENT_TEST;

      // Google analytics staging account.
      $conf['googleanalytics_account'] = 'UA-1582839-25';

      $conf['shield_user'] = 'vu';
      $conf['shield_pass'] = '46>GwfCp';
      $conf['shield_print'] = '';

      $conf['search_api_acquia_overrides']['acquia_search_server'] = [
        'path' => '/solr/ILUY-91754.test.default',
        'host' => 'apsoutheast2-c32.acquia-search.com',
        'derived_key' => 'd15840054fc63a2492efdac458a619249c00cf97',
      ];
      break;

    case 'test2':
      $conf['environment'] = ENVIRONMENT_TEST2;

      // Google analytics staging account.
      $conf['googleanalytics_account'] = 'UA-1582839-25';

      $conf['shield_user'] = 'vu';
      $conf['shield_pass'] = '46>GwfCp';
      $conf['shield_print'] = '';

      $conf['search_api_acquia_overrides']['acquia_search_server'] = [
        'path' => '/solr/ILUY-91754.test2.default',
        'host' => 'apsoutheast2-c32.acquia-search.com',
        'derived_key' => '89611ec0bb26ab0b498627213ad7a8a6d25e2c4f',
      ];
      break;

    case 'prod':
      $conf['environment'] = ENVIRONMENT_PROD;

      $conf['shield_user'] = NULL;

      // Google analytics prod account.
      $conf['googleanalytics_account'] = 'UA-1582839-5';
      break;
  }

  // Disable shield if client matches allowed ranges.
  if ($conf['environment'] !== ENVIRONMENT_PROD && !empty($conf['shield_user'])) {
    if (!empty($_ENV['AH_Client_IP'])) {
      // VU Network range.
      $whitelisted_ip = cidr_match($_ENV['AH_Client_IP'], '140.159.0.0/16');
      // VU Server range
      $whitelisted_ip = $whitelisted_ip || cidr_match($_ENV['AH_Client_IP'], '203.13.192.0/20');
      // Disable shield.
      if ($whitelisted_ip) {
        $conf['shield_user'] = NULL;
        $conf['shield_pass'] = NULL;
      }
    }
    // If it's still enabled.
    if (!empty($conf['shield_user'])) {
      // These are authenticated separately anyway.
      $service_urls = [
        '/boomi',
        '/formsubmissions/feed',
        '/ciservice',
      ];
      foreach ($service_urls as $url) {
        if (strpos($_SERVER['REQUEST_URI'], $url) === 0) {
          $conf['shield_user'] = NULL;
          $conf['shield_pass'] = NULL;
          break;
        }
      }
    }
  }

  // Override memory limit for drush/cli.
  if (drupal_is_cli()) {
    ini_set('memory_limit', '1024M');
    // 20 mins is more than enough. If we need more then the
    // specific script that is running should deal with it.
    ini_set('max_execution_time', 1200);
  }
}
// CI environment.
elseif (getenv('CI')) {
  $conf['environment'] = ENVIRONMENT_CI;

  // Host for all requests sent to the server itself. Required when running
  // inside of docker containers.
  $conf['self_server_request_host'] = 'http://nginx:8080';

  $conf['stage_file_proxy_origin'] = 'https://www.vu.edu.au';

  $conf['search_api_acquia_overrides']['acquia_search_server'] = [
    'path' => '/solr/ILUY-91754.dev.default',
    'host' => 'apsoutheast2-c32.acquia-search.com',
    'derived_key' => '35d77d88d3f36fb8fede11deef6bdab7b15fe210',
  ];

  // Disable any cron runs.
  $conf['cron_safe_threshold'] = 0;
}
// Other environments.
else {
  $conf['environment'] = ENVIRONMENT_LOCAL;

  // Host for all requests sent to the server itself. Required when running
  // inside of docker containers.
  $conf['self_server_request_host'] = 'http://nginx:8080';

  $conf['stage_file_proxy_origin'] = 'https://www.vu.edu.au';

  $conf['search_api_acquia_overrides']['acquia_search_server'] = [
    'path' => '/solr/ILUY-91754.dev.default',
    'host' => 'apsoutheast2-c32.acquia-search.com',
    'derived_key' => '35d77d88d3f36fb8fede11deef6bdab7b15fe210',
  ];

  $conf['vu_fb_page_plugin'] = TRUE;
}

////////////////////////////////////////////////////////////////////////////////
///                        CUSTOM VU SETTINGS                                ///
////////////////////////////////////////////////////////////////////////////////

// Course tiles.
// @todo: Clarify why course titles are set in config rather than in variables.
$conf['course_tiles'] = [
  'preference-course-tile' => '/preference-2016/promo-tile/',
  'cop-course-tile' => '/change-of-preference-2016/promo-tile/',
  'pg-course-tile' => '/postgrad-october-2015/promo-tile/',
  'open-day' => '/open-day-2016/promo-tile/',
  'csa-course-tile' => '/courses-available-2016/promo-tile/',
  'midyear-course-tile' => '/mid-year-2016/promo-tile/',
];

$conf['course_index_use_vtac'] = TRUE;

$conf['self_accredited_courses'] = [
  'ADES',
  'TDIT',
  'WDAC',
  'WDBE',
  'WDCI',
];

$conf['alert_email'] = 'webcontent@vu.edu.au';

// Array mapping VU location codes to strings.
$conf['vu_location_codes'] = [
  '4' => 'FLEX ED',
  'I' => 'INDUSTRY',
  'LW' => 'LEARNING IN THE WORKPLACE',
  'ZA' => 'ONLINE',
  'ZO' => 'ONLINE (OFFSHORE)',
  'C' => 'CITY FLINDERS',
  'J' => 'CITY KING',
  'CQ' => 'CITY QUEEN',
  'G' => 'FOOTSCRAY NICHOLSON',
  'F' => 'FOOTSCRAY PARK',
  'M' => 'MELTON',
  'N' => 'NEWPORT',
  'S' => 'ST ALBANS',
  'B' => 'SUNBURY',
  'T' => 'SUNSHINE',
  'E' => 'ECHUCA',
  'W' => 'WERRIBEE',
  'X' => 'WEST MELBOURNE ANNEXE',
  'Y' => 'YARRAVILLE',
  '76' => 'SYDNEY-ECA',
  'AVET' => 'GOV FOOTSCRAY PARK',
  'SY' => 'VU SYDNEY',
];

// Campaign sites - for setting CORS headers.
$conf['vu_cors_config'] = [
  // Postgrad call back request form.
  'node/10924171' => [
    'applydirect.vu.edu.au',
    'applynow.vu.edu.au',
    'apply-now-stage.surge.sh',
  ],
  // General enquiry form.
  'node/10915786' => [
    'applydirect.vu.edu.au',
    'applynow.vu.edu.au',
    'apply-now-stage.surge.sh',
  ],
  // Law/justice open day registration form.
  'node/10922706' => ['discoverlaw.vu.edu.au'],
];

////////////////////////////////////////////////////////////////////////////////
///                        GENERATED SETTINGS                                ///
////////////////////////////////////////////////////////////////////////////////

// Include generated settings file, if available.
if (file_exists(DRUPAL_ROOT . '/' . conf_path() . '/settings.generated.php')) {
  include DRUPAL_ROOT . '/' . conf_path() . '/settings.generated.php';
}

////////////////////////////////////////////////////////////////////////////////
///                      LOCAL OVERRIDES FOR SETTINGS                        ///
////////////////////////////////////////////////////////////////////////////////

// Load local development override configuration, if available.
//
// Use settings.local.php to override variables on secondary (staging,
// development, etc) installations of this site. Typically used to disable
// caching, JavaScript/CSS compression, re-routing of outgoing emails, and
// other things that should not happen on development and testing sites.
//
// Keep this code block at the end of this file to take full effect.
if (file_exists(DRUPAL_ROOT . '/' . conf_path() . '/settings.local.php')) {
  include DRUPAL_ROOT . '/' . conf_path() . '/settings.local.php';
}
