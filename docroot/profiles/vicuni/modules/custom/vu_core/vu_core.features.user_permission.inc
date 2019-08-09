<?php
/**
 * @file
 * vu_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vu_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Restrict editing page title'.
  $permissions['Restrict editing page title'] = array(
    'name' => 'Restrict editing page title',
    'roles' => array(
      'Admin' => 'Admin',
      'Approver' => 'Approver',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Researcher Profile Tester' => 'Researcher Profile Tester',
      'TAFE Author' => 'TAFE Author',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access audit files reports'.
  $permissions['access audit files reports'] = array(
    'name' => 'access audit files reports',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'auditfiles',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'access coffee'.
  $permissions['access coffee'] = array(
    'name' => 'access coffee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'coffee',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: 'access integration status report'.
  $permissions['access integration status report'] = array(
    'name' => 'access integration status report',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'status_report',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'access_google_appliance_content'.
  $permissions['access_google_appliance_content'] = array(
    'name' => 'access_google_appliance_content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'google_appliance',
  );

  // Exported permission: 'add authenticated twitter accounts'.
  $permissions['add authenticated twitter accounts'] = array(
    'name' => 'add authenticated twitter accounts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'add drupagram accounts'.
  $permissions['add drupagram accounts'] = array(
    'name' => 'add drupagram accounts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'drupagram',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'add twitter accounts'.
  $permissions['add twitter accounts'] = array(
    'name' => 'add twitter accounts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer addressfield staticmap'.
  $permissions['administer addressfield staticmap'] = array(
    'name' => 'administer addressfield staticmap',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'addressfield_staticmap',
  );

  // Exported permission: 'administer audience vocabulary terms'.
  $permissions['administer audience vocabulary terms'] = array(
    'name' => 'administer audience vocabulary terms',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer cas'.
  $permissions['administer cas'] = array(
    'name' => 'administer cas',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cas',
  );

  // Exported permission: 'administer chat now'.
  $permissions['administer chat now'] = array(
    'name' => 'administer chat now',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_chat_now',
  );

  // Exported permission: 'administer coffee'.
  $permissions['administer coffee'] = array(
    'name' => 'administer coffee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'coffee',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer custom formatters'.
  $permissions['administer custom formatters'] = array(
    'name' => 'administer custom formatters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_formatters',
  );

  // Exported permission: 'administer darksite'.
  $permissions['administer darksite'] = array(
    'name' => 'administer darksite',
    'roles' => array(
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'vumain',
  );

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fee_disclaimers vocabulary terms'.
  $permissions['administer fee_disclaimers vocabulary terms'] = array(
    'name' => 'administer fee_disclaimers vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer fee_types vocabulary terms'.
  $permissions['administer fee_types vocabulary terms'] = array(
    'name' => 'administer fee_types vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer inline form errors'.
  $permissions['administer inline form errors'] = array(
    'name' => 'administer inline form errors',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ife',
  );

  // Exported permission: 'administer instapage_cms_plugin settings'.
  $permissions['administer instapage_cms_plugin settings'] = array(
    'name' => 'administer instapage_cms_plugin settings',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'instapage_cms_plugin',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu positions'.
  $permissions['administer menu positions'] = array(
    'name' => 'administer menu positions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_position',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer paragraphs bundles'.
  $permissions['administer paragraphs bundles'] = array(
    'name' => 'administer paragraphs bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'paragraphs',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer stage_file_proxy settings'.
  $permissions['administer stage_file_proxy settings'] = array(
    'name' => 'administer stage_file_proxy settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stage_file_proxy',
  );

  // Exported permission: 'administer subsites vocabulary terms'.
  $permissions['administer subsites vocabulary terms'] = array(
    'name' => 'administer subsites vocabulary terms',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer twitter'.
  $permissions['administer twitter'] = array(
    'name' => 'administer twitter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'administer twitter accounts'.
  $permissions['administer twitter accounts'] = array(
    'name' => 'administer twitter accounts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer webform file upload'.
  $permissions['administer webform file upload'] = array(
    'name' => 'administer webform file upload',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'administer_google_appliance'.
  $permissions['administer_google_appliance'] = array(
    'name' => 'administer_google_appliance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'google_appliance',
  );

  // Exported permission: 'assign Admin role'.
  $permissions['assign Admin role'] = array(
    'name' => 'assign Admin role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Advanced Author role'.
  $permissions['assign Advanced Author role'] = array(
    'name' => 'assign Advanced Author role',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Approver role'.
  $permissions['assign Approver role'] = array(
    'name' => 'assign Approver role',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Author role'.
  $permissions['assign Author role'] = array(
    'name' => 'assign Author role',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Emergency Publisher role'.
  $permissions['assign Emergency Publisher role'] = array(
    'name' => 'assign Emergency Publisher role',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign International Author role'.
  $permissions['assign International Author role'] = array(
    'name' => 'assign International Author role',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign TAFE Author role'.
  $permissions['assign TAFE Author role'] = array(
    'name' => 'assign TAFE Author role',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass redirection'.
  $permissions['bypass redirection'] = array(
    'name' => 'bypass redirection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_redirection',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear course_fees feeds'.
  $permissions['clear course_fees feeds'] = array(
    'name' => 'clear course_fees feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear courses feeds'.
  $permissions['clear courses feeds'] = array(
    'name' => 'clear courses feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear node feeds'.
  $permissions['clear node feeds'] = array(
    'name' => 'clear node feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear unit_fees feeds'.
  $permissions['clear unit_fees feeds'] = array(
    'name' => 'clear unit_fees feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear units feeds'.
  $permissions['clear units feeds'] = array(
    'name' => 'clear units feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear units_vet feeds'.
  $permissions['clear units_vet feeds'] = array(
    'name' => 'clear units_vet feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear unitsets feeds'.
  $permissions['clear unitsets feeds'] = array(
    'name' => 'clear unitsets feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear user feeds'.
  $permissions['clear user feeds'] = array(
    'name' => 'clear user feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'create any basic_bean bean'.
  $permissions['create any basic_bean bean'] = array(
    'name' => 'create any basic_bean bean',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any choose_vu bean'.
  $permissions['create any choose_vu bean'] = array(
    'name' => 'create any choose_vu bean',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any fym_banner_type bean'.
  $permissions['create any fym_banner_type bean'] = array(
    'name' => 'create any fym_banner_type bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any hero_banner bean'.
  $permissions['create any hero_banner bean'] = array(
    'name' => 'create any hero_banner bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any hero_title_box bean'.
  $permissions['create any hero_title_box bean'] = array(
    'name' => 'create any hero_title_box bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any homepage_banner bean'.
  $permissions['create any homepage_banner bean'] = array(
    'name' => 'create any homepage_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any promo bean'.
  $permissions['create any promo bean'] = array(
    'name' => 'create any promo bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any quick_facts bean'.
  $permissions['create any quick_facts bean'] = array(
    'name' => 'create any quick_facts bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any student_testimonials bean'.
  $permissions['create any student_testimonials bean'] = array(
    'name' => 'create any student_testimonials bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create campus content'.
  $permissions['create campus content'] = array(
    'name' => 'create campus content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campus_housing content'.
  $permissions['create campus_housing content'] = array(
    'name' => 'create campus_housing content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course_fees content'.
  $permissions['create course_fees content'] = array(
    'name' => 'create course_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create courses content'.
  $permissions['create courses content'] = array(
    'name' => 'create courses content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create events content'.
  $permissions['create events content'] = array(
    'name' => 'create events content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_additional_information'.
  $permissions['create field_additional_information'] = array(
    'name' => 'create field_additional_information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_additional_requirements'.
  $permissions['create field_additional_requirements'] = array(
    'name' => 'create field_additional_requirements',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_admission_requirements_he'.
  $permissions['create field_admission_requirements_he'] = array(
    'name' => 'create field_admission_requirements_he',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_admission_requirements_se'.
  $permissions['create field_admission_requirements_se'] = array(
    'name' => 'create field_admission_requirements_se',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_admission_requirements_vet'.
  $permissions['create field_admission_requirements_vet'] = array(
    'name' => 'create field_admission_requirements_vet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_admission_requirements_wl'.
  $permissions['create field_admission_requirements_wl'] = array(
    'name' => 'create field_admission_requirements_wl',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_atar_indicator'.
  $permissions['create field_atar_indicator'] = array(
    'name' => 'create field_atar_indicator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_atar_minimum_entry'.
  $permissions['create field_atar_minimum_entry'] = array(
    'name' => 'create field_atar_minimum_entry',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_atar_profile_data'.
  $permissions['create field_atar_profile_data'] = array(
    'name' => 'create field_atar_profile_data',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_career'.
  $permissions['create field_career'] = array(
    'name' => 'create field_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_college'.
  $permissions['create field_college'] = array(
    'name' => 'create field_college',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_completion_rules'.
  $permissions['create field_completion_rules'] = array(
    'name' => 'create field_completion_rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_component_section_style'.
  $permissions['create field_component_section_style'] = array(
    'name' => 'create field_component_section_style',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_content_area'.
  $permissions['create field_content_area'] = array(
    'name' => 'create field_content_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_continuing_student'.
  $permissions['create field_continuing_student'] = array(
    'name' => 'create field_continuing_student',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_aqf'.
  $permissions['create field_course_aqf'] = array(
    'name' => 'create field_course_aqf',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_followed_by'.
  $permissions['create field_course_followed_by'] = array(
    'name' => 'create field_course_followed_by',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_midyear_intake'.
  $permissions['create field_course_midyear_intake'] = array(
    'name' => 'create field_course_midyear_intake',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_offered'.
  $permissions['create field_course_offered'] = array(
    'name' => 'create field_course_offered',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_preceded_by'.
  $permissions['create field_course_preceded_by'] = array(
    'name' => 'create field_course_preceded_by',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_sort_title'.
  $permissions['create field_course_sort_title'] = array(
    'name' => 'create field_course_sort_title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_units'.
  $permissions['create field_course_units'] = array(
    'name' => 'create field_course_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_credit_points'.
  $permissions['create field_credit_points'] = array(
    'name' => 'create field_credit_points',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_cricos_code'.
  $permissions['create field_cricos_code'] = array(
    'name' => 'create field_cricos_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_cut_off_date'.
  $permissions['create field_cut_off_date'] = array(
    'name' => 'create field_cut_off_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_destination_page'.
  $permissions['create field_destination_page'] = array(
    'name' => 'create field_destination_page',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_domestic'.
  $permissions['create field_domestic'] = array(
    'name' => 'create field_domestic',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_duration'.
  $permissions['create field_duration'] = array(
    'name' => 'create field_duration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_entry_requirements_in'.
  $permissions['create field_entry_requirements_in'] = array(
    'name' => 'create field_entry_requirements_in',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_entry_requirements_pg'.
  $permissions['create field_entry_requirements_pg'] = array(
    'name' => 'create field_entry_requirements_pg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_entry_requirements_ve'.
  $permissions['create field_entry_requirements_ve'] = array(
    'name' => 'create field_entry_requirements_ve',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_excerpt'.
  $permissions['create field_excerpt'] = array(
    'name' => 'create field_excerpt',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_feature_duration'.
  $permissions['create field_feature_duration'] = array(
    'name' => 'create field_feature_duration',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_featured_success_story'.
  $permissions['create field_featured_success_story'] = array(
    'name' => 'create field_featured_success_story',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_first_off_date'.
  $permissions['create field_first_off_date'] = array(
    'name' => 'create field_first_off_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_free_tafe'.
  $permissions['create field_free_tafe'] = array(
    'name' => 'create field_free_tafe',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fym_body_text'.
  $permissions['create field_fym_body_text'] = array(
    'name' => 'create field_fym_body_text',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fym_logo'.
  $permissions['create field_fym_logo'] = array(
    'name' => 'create field_fym_logo',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_handbook_include'.
  $permissions['create field_handbook_include'] = array(
    'name' => 'create field_handbook_include',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_he_study'.
  $permissions['create field_he_study'] = array(
    'name' => 'create field_he_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_how_to_apply'.
  $permissions['create field_how_to_apply'] = array(
    'name' => 'create field_how_to_apply',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_how_to_apply_title'.
  $permissions['create field_how_to_apply_title'] = array(
    'name' => 'create field_how_to_apply_title',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_admission_requirements'.
  $permissions['create field_imp_admission_requirements'] = array(
    'name' => 'create field_imp_admission_requirements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_career'.
  $permissions['create field_imp_career'] = array(
    'name' => 'create field_imp_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_delivery_mode'.
  $permissions['create field_imp_delivery_mode'] = array(
    'name' => 'create field_imp_delivery_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_desc'.
  $permissions['create field_imp_desc'] = array(
    'name' => 'create field_imp_desc',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_inter_campus'.
  $permissions['create field_imp_inter_campus'] = array(
    'name' => 'create field_imp_inter_campus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_intro'.
  $permissions['create field_imp_intro'] = array(
    'name' => 'create field_imp_intro',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_object'.
  $permissions['create field_imp_object'] = array(
    'name' => 'create field_imp_object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_prereq_units'.
  $permissions['create field_imp_prereq_units'] = array(
    'name' => 'create field_imp_prereq_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_structure'.
  $permissions['create field_imp_structure'] = array(
    'name' => 'create field_imp_structure',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_int_sem_int'.
  $permissions['create field_int_sem_int'] = array(
    'name' => 'create field_int_sem_int',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inter_lang_requirements'.
  $permissions['create field_inter_lang_requirements'] = array(
    'name' => 'create field_inter_lang_requirements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_international'.
  $permissions['create field_international'] = array(
    'name' => 'create field_international',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_international_body'.
  $permissions['create field_international_body'] = array(
    'name' => 'create field_international_body',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_international_fees'.
  $permissions['create field_international_fees'] = array(
    'name' => 'create field_international_fees',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_international_study'.
  $permissions['create field_international_study'] = array(
    'name' => 'create field_international_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_legacy_location'.
  $permissions['create field_legacy_location'] = array(
    'name' => 'create field_legacy_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_location_other'.
  $permissions['create field_location_other'] = array(
    'name' => 'create field_location_other',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_location_other_editable'.
  $permissions['create field_location_other_editable'] = array(
    'name' => 'create field_location_other_editable',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_location_tag'.
  $permissions['create field_location_tag'] = array(
    'name' => 'create field_location_tag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_locations'.
  $permissions['create field_locations'] = array(
    'name' => 'create field_locations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_materials_fee'.
  $permissions['create field_materials_fee'] = array(
    'name' => 'create field_materials_fee',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_more_button_link'.
  $permissions['create field_more_button_link'] = array(
    'name' => 'create field_more_button_link',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_multiple_audience_group'.
  $permissions['create field_multiple_audience_group'] = array(
    'name' => 'create field_multiple_audience_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_on_this_page'.
  $permissions['create field_on_this_page'] = array(
    'name' => 'create field_on_this_page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_page_lvl_1_thumbnail_image'.
  $permissions['create field_page_lvl_1_thumbnail_image'] = array(
    'name' => 'create field_page_lvl_1_thumbnail_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_page_subsite'.
  $permissions['create field_page_subsite'] = array(
    'name' => 'create field_page_subsite',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_postgrad_research'.
  $permissions['create field_postgrad_research'] = array(
    'name' => 'create field_postgrad_research',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_researcher_profile'.
  $permissions['create field_researcher_profile'] = array(
    'name' => 'create field_researcher_profile',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_results_user_access'.
  $permissions['create field_results_user_access'] = array(
    'name' => 'create field_results_user_access',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_se_atar_only'.
  $permissions['create field_se_atar_only'] = array(
    'name' => 'create field_se_atar_only',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_se_atar_plus'.
  $permissions['create field_se_atar_plus'] = array(
    'name' => 'create field_se_atar_plus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_se_na'.
  $permissions['create field_se_na'] = array(
    'name' => 'create field_se_na',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_sidebar_content'.
  $permissions['create field_sidebar_content'] = array(
    'name' => 'create field_sidebar_content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_staff_id'.
  $permissions['create field_staff_id'] = array(
    'name' => 'create field_staff_id',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_study_mode'.
  $permissions['create field_study_mode'] = array(
    'name' => 'create field_study_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_study_topic_area'.
  $permissions['create field_study_topic_area'] = array(
    'name' => 'create field_study_topic_area',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_sup_application_info'.
  $permissions['create field_sup_application_info'] = array(
    'name' => 'create field_sup_application_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_supplementary_career_info'.
  $permissions['create field_supplementary_career_info'] = array(
    'name' => 'create field_supplementary_career_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_supplementary_date_info'.
  $permissions['create field_supplementary_date_info'] = array(
    'name' => 'create field_supplementary_date_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_tags'.
  $permissions['create field_tags'] = array(
    'name' => 'create field_tags',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_title_area_feature_image'.
  $permissions['create field_title_area_feature_image'] = array(
    'name' => 'create field_title_area_feature_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_total_study'.
  $permissions['create field_total_study'] = array(
    'name' => 'create field_total_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_unit_code'.
  $permissions['create field_unit_code'] = array(
    'name' => 'create field_unit_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_unit_id'.
  $permissions['create field_unit_id'] = array(
    'name' => 'create field_unit_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_unit_lev'.
  $permissions['create field_unit_lev'] = array(
    'name' => 'create field_unit_lev',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_unit_ver'.
  $permissions['create field_unit_ver'] = array(
    'name' => 'create field_unit_ver',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ve_cohorts'.
  $permissions['create field_ve_cohorts'] = array(
    'name' => 'create field_ve_cohorts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ve_study'.
  $permissions['create field_ve_study'] = array(
    'name' => 'create field_ve_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_webhook_url'.
  $permissions['create field_webhook_url'] = array(
    'name' => 'create field_webhook_url',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_work_life'.
  $permissions['create field_work_life'] = array(
    'name' => 'create field_work_life',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create fieldable pane_featured_content'.
  $permissions['create fieldable pane_featured_content'] = array(
    'name' => 'create fieldable pane_featured_content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page_builder content'.
  $permissions['create page_builder content'] = array(
    'name' => 'create page_builder content',
    'roles' => array(
      'Approver' => 'Approver',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create staff_profile content'.
  $permissions['create staff_profile content'] = array(
    'name' => 'create staff_profile content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create study_topic_area content'.
  $permissions['create study_topic_area content'] = array(
    'name' => 'create study_topic_area content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create success_story content'.
  $permissions['create success_story content'] = array(
    'name' => 'create success_story content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create topic_pages content'.
  $permissions['create topic_pages content'] = array(
    'name' => 'create topic_pages content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create unit content'.
  $permissions['create unit content'] = array(
    'name' => 'create unit content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create unit_fees content'.
  $permissions['create unit_fees content'] = array(
    'name' => 'create unit_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create unit_set content'.
  $permissions['create unit_set content'] = array(
    'name' => 'create unit_set content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any basic_bean bean'.
  $permissions['delete any basic_bean bean'] = array(
    'name' => 'delete any basic_bean bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any campus content'.
  $permissions['delete any campus content'] = array(
    'name' => 'delete any campus content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campus_housing content'.
  $permissions['delete any campus_housing content'] = array(
    'name' => 'delete any campus_housing content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any choose_vu bean'.
  $permissions['delete any choose_vu bean'] = array(
    'name' => 'delete any choose_vu bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any course_fees content'.
  $permissions['delete any course_fees content'] = array(
    'name' => 'delete any course_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses content'.
  $permissions['delete any courses content'] = array(
    'name' => 'delete any courses content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any events content'.
  $permissions['delete any events content'] = array(
    'name' => 'delete any events content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any fym_banner_type bean'.
  $permissions['delete any fym_banner_type bean'] = array(
    'name' => 'delete any fym_banner_type bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any hero_banner bean'.
  $permissions['delete any hero_banner bean'] = array(
    'name' => 'delete any hero_banner bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any hero_title_box bean'.
  $permissions['delete any hero_title_box bean'] = array(
    'name' => 'delete any hero_title_box bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any homepage_banner bean'.
  $permissions['delete any homepage_banner bean'] = array(
    'name' => 'delete any homepage_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page_builder content'.
  $permissions['delete any page_builder content'] = array(
    'name' => 'delete any page_builder content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any promo bean'.
  $permissions['delete any promo bean'] = array(
    'name' => 'delete any promo bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any quick_facts bean'.
  $permissions['delete any quick_facts bean'] = array(
    'name' => 'delete any quick_facts bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any staff_profile content'.
  $permissions['delete any staff_profile content'] = array(
    'name' => 'delete any staff_profile content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any student_testimonials bean'.
  $permissions['delete any student_testimonials bean'] = array(
    'name' => 'delete any student_testimonials bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any study_topic_area content'.
  $permissions['delete any study_topic_area content'] = array(
    'name' => 'delete any study_topic_area content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any success_story content'.
  $permissions['delete any success_story content'] = array(
    'name' => 'delete any success_story content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any topic_pages content'.
  $permissions['delete any topic_pages content'] = array(
    'name' => 'delete any topic_pages content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any unit content'.
  $permissions['delete any unit content'] = array(
    'name' => 'delete any unit content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any unit_fees content'.
  $permissions['delete any unit_fees content'] = array(
    'name' => 'delete any unit_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any unit_set content'.
  $permissions['delete any unit_set content'] = array(
    'name' => 'delete any unit_set content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete campus unpublished'.
  $permissions['delete campus unpublished'] = array(
    'name' => 'delete campus unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete campus_housing unpublished'.
  $permissions['delete campus_housing unpublished'] = array(
    'name' => 'delete campus_housing unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete course_fees unpublished'.
  $permissions['delete course_fees unpublished'] = array(
    'name' => 'delete course_fees unpublished',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete courses unpublished'.
  $permissions['delete courses unpublished'] = array(
    'name' => 'delete courses unpublished',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete events unpublished'.
  $permissions['delete events unpublished'] = array(
    'name' => 'delete events unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete fieldable pane_featured_content'.
  $permissions['delete fieldable pane_featured_content'] = array(
    'name' => 'delete fieldable pane_featured_content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete news unpublished'.
  $permissions['delete news unpublished'] = array(
    'name' => 'delete news unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own campus content'.
  $permissions['delete own campus content'] = array(
    'name' => 'delete own campus content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campus_housing content'.
  $permissions['delete own campus_housing content'] = array(
    'name' => 'delete own campus_housing content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_fees content'.
  $permissions['delete own course_fees content'] = array(
    'name' => 'delete own course_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses content'.
  $permissions['delete own courses content'] = array(
    'name' => 'delete own courses content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own events content'.
  $permissions['delete own events content'] = array(
    'name' => 'delete own events content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page_builder content'.
  $permissions['delete own page_builder content'] = array(
    'name' => 'delete own page_builder content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own staff_profile content'.
  $permissions['delete own staff_profile content'] = array(
    'name' => 'delete own staff_profile content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own study_topic_area content'.
  $permissions['delete own study_topic_area content'] = array(
    'name' => 'delete own study_topic_area content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own success_story content'.
  $permissions['delete own success_story content'] = array(
    'name' => 'delete own success_story content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own topic_pages content'.
  $permissions['delete own topic_pages content'] = array(
    'name' => 'delete own topic_pages content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own unit content'.
  $permissions['delete own unit content'] = array(
    'name' => 'delete own unit content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own unit_fees content'.
  $permissions['delete own unit_fees content'] = array(
    'name' => 'delete own unit_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own unit_set content'.
  $permissions['delete own unit_set content'] = array(
    'name' => 'delete own unit_set content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete page_builder unpublished'.
  $permissions['delete page_builder unpublished'] = array(
    'name' => 'delete page_builder unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete staff_profile unpublished'.
  $permissions['delete staff_profile unpublished'] = array(
    'name' => 'delete staff_profile unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete study_topic_area unpublished'.
  $permissions['delete study_topic_area unpublished'] = array(
    'name' => 'delete study_topic_area unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete success_story unpublished'.
  $permissions['delete success_story unpublished'] = array(
    'name' => 'delete success_story unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete terms in delivery_modes'.
  $permissions['delete terms in delivery_modes'] = array(
    'name' => 'delete terms in delivery_modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in expertise'.
  $permissions['delete terms in expertise'] = array(
    'name' => 'delete terms in expertise',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in fee_disclaimers'.
  $permissions['delete terms in fee_disclaimers'] = array(
    'name' => 'delete terms in fee_disclaimers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in fee_types'.
  $permissions['delete terms in fee_types'] = array(
    'name' => 'delete terms in fee_types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in subsites'.
  $permissions['delete terms in subsites'] = array(
    'name' => 'delete terms in subsites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in success_categories'.
  $permissions['delete terms in success_categories'] = array(
    'name' => 'delete terms in success_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in unit_set_type'.
  $permissions['delete terms in unit_set_type'] = array(
    'name' => 'delete terms in unit_set_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete topic_pages unpublished'.
  $permissions['delete topic_pages unpublished'] = array(
    'name' => 'delete topic_pages unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete unit unpublished'.
  $permissions['delete unit unpublished'] = array(
    'name' => 'delete unit unpublished',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete unit_fees unpublished'.
  $permissions['delete unit_fees unpublished'] = array(
    'name' => 'delete unit_fees unpublished',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete unit_set unpublished'.
  $permissions['delete unit_set unpublished'] = array(
    'name' => 'delete unit_set unpublished',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'delete webform unpublished'.
  $permissions['delete webform unpublished'] = array(
    'name' => 'delete webform unpublished',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'eck add accordion_item accordion_item entities'.
  $permissions['eck add accordion_item accordion_item entities'] = array(
    'name' => 'eck add accordion_item accordion_item entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add accordion_item bundles'.
  $permissions['eck add accordion_item bundles'] = array(
    'name' => 'eck add accordion_item bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add bundles'.
  $permissions['eck add bundles'] = array(
    'name' => 'eck add bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add contact_information bundles'.
  $permissions['eck add contact_information bundles'] = array(
    'name' => 'eck add contact_information bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add contact_information contact_information entities'.
  $permissions['eck add contact_information contact_information entities'] = array(
    'name' => 'eck add contact_information contact_information entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entities'.
  $permissions['eck add entities'] = array(
    'name' => 'eck add entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entity types'.
  $permissions['eck add entity types'] = array(
    'name' => 'eck add entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities accordion_section entities'.
  $permissions['eck add inline_entities accordion_section entities'] = array(
    'name' => 'eck add inline_entities accordion_section entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities basic_body_text entities'.
  $permissions['eck add inline_entities basic_body_text entities'] = array(
    'name' => 'eck add inline_entities basic_body_text entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities block_reference entities'.
  $permissions['eck add inline_entities block_reference entities'] = array(
    'name' => 'eck add inline_entities block_reference entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities bundles'.
  $permissions['eck add inline_entities bundles'] = array(
    'name' => 'eck add inline_entities bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities course_date_time entities'.
  $permissions['eck add inline_entities course_date_time entities'] = array(
    'name' => 'eck add inline_entities course_date_time entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities featured_content entities'.
  $permissions['eck add inline_entities featured_content entities'] = array(
    'name' => 'eck add inline_entities featured_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities featured_success_story entities'.
  $permissions['eck add inline_entities featured_success_story entities'] = array(
    'name' => 'eck add inline_entities featured_success_story entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities link_redirects entities'.
  $permissions['eck add inline_entities link_redirects entities'] = array(
    'name' => 'eck add inline_entities link_redirects entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities location entities'.
  $permissions['eck add inline_entities location entities'] = array(
    'name' => 'eck add inline_entities location entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities our_victories entities'.
  $permissions['eck add inline_entities our_victories entities'] = array(
    'name' => 'eck add inline_entities our_victories entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities related_links entities'.
  $permissions['eck add inline_entities related_links entities'] = array(
    'name' => 'eck add inline_entities related_links entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities topic_page_content entities'.
  $permissions['eck add inline_entities topic_page_content entities'] = array(
    'name' => 'eck add inline_entities topic_page_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities topic_page_facts entities'.
  $permissions['eck add inline_entities topic_page_facts entities'] = array(
    'name' => 'eck add inline_entities topic_page_facts entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add inline_entities topic_page_sidebar_content entities'.
  $permissions['eck add inline_entities topic_page_sidebar_content entities'] = array(
    'name' => 'eck add inline_entities topic_page_sidebar_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add intake bundles'.
  $permissions['eck add intake bundles'] = array(
    'name' => 'eck add intake bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add intake intake entities'.
  $permissions['eck add intake intake entities'] = array(
    'name' => 'eck add intake intake entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer accordion_item accordion_item entities'.
  $permissions['eck administer accordion_item accordion_item entities'] = array(
    'name' => 'eck administer accordion_item accordion_item entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer accordion_item bundles'.
  $permissions['eck administer accordion_item bundles'] = array(
    'name' => 'eck administer accordion_item bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer bundles'.
  $permissions['eck administer bundles'] = array(
    'name' => 'eck administer bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer contact_information bundles'.
  $permissions['eck administer contact_information bundles'] = array(
    'name' => 'eck administer contact_information bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer contact_information contact_information entities'.
  $permissions['eck administer contact_information contact_information entities'] = array(
    'name' => 'eck administer contact_information contact_information entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entities'.
  $permissions['eck administer entities'] = array(
    'name' => 'eck administer entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entity types'.
  $permissions['eck administer entity types'] = array(
    'name' => 'eck administer entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities accordion_section entities'.
  $permissions['eck administer inline_entities accordion_section entities'] = array(
    'name' => 'eck administer inline_entities accordion_section entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities basic_body_text entities'.
  $permissions['eck administer inline_entities basic_body_text entities'] = array(
    'name' => 'eck administer inline_entities basic_body_text entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities block_reference entities'.
  $permissions['eck administer inline_entities block_reference entities'] = array(
    'name' => 'eck administer inline_entities block_reference entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities bundles'.
  $permissions['eck administer inline_entities bundles'] = array(
    'name' => 'eck administer inline_entities bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities course_date_time entities'.
  $permissions['eck administer inline_entities course_date_time entities'] = array(
    'name' => 'eck administer inline_entities course_date_time entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities featured_content entities'.
  $permissions['eck administer inline_entities featured_content entities'] = array(
    'name' => 'eck administer inline_entities featured_content entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities featured_success_story entities'.
  $permissions['eck administer inline_entities featured_success_story entities'] = array(
    'name' => 'eck administer inline_entities featured_success_story entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities link_redirects entities'.
  $permissions['eck administer inline_entities link_redirects entities'] = array(
    'name' => 'eck administer inline_entities link_redirects entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities location entities'.
  $permissions['eck administer inline_entities location entities'] = array(
    'name' => 'eck administer inline_entities location entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities our_victories entities'.
  $permissions['eck administer inline_entities our_victories entities'] = array(
    'name' => 'eck administer inline_entities our_victories entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities related_links entities'.
  $permissions['eck administer inline_entities related_links entities'] = array(
    'name' => 'eck administer inline_entities related_links entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities topic_page_content entities'.
  $permissions['eck administer inline_entities topic_page_content entities'] = array(
    'name' => 'eck administer inline_entities topic_page_content entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities topic_page_facts entities'.
  $permissions['eck administer inline_entities topic_page_facts entities'] = array(
    'name' => 'eck administer inline_entities topic_page_facts entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer inline_entities topic_page_sidebar_content entities'.
  $permissions['eck administer inline_entities topic_page_sidebar_content entities'] = array(
    'name' => 'eck administer inline_entities topic_page_sidebar_content entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer intake bundles'.
  $permissions['eck administer intake bundles'] = array(
    'name' => 'eck administer intake bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer intake intake entities'.
  $permissions['eck administer intake intake entities'] = array(
    'name' => 'eck administer intake intake entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete accordion_item accordion_item entities'.
  $permissions['eck delete accordion_item accordion_item entities'] = array(
    'name' => 'eck delete accordion_item accordion_item entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete accordion_item bundles'.
  $permissions['eck delete accordion_item bundles'] = array(
    'name' => 'eck delete accordion_item bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete bundles'.
  $permissions['eck delete bundles'] = array(
    'name' => 'eck delete bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete contact_information bundles'.
  $permissions['eck delete contact_information bundles'] = array(
    'name' => 'eck delete contact_information bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete contact_information contact_information entities'.
  $permissions['eck delete contact_information contact_information entities'] = array(
    'name' => 'eck delete contact_information contact_information entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entities'.
  $permissions['eck delete entities'] = array(
    'name' => 'eck delete entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entity types'.
  $permissions['eck delete entity types'] = array(
    'name' => 'eck delete entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities accordion_section entities'.
  $permissions['eck delete inline_entities accordion_section entities'] = array(
    'name' => 'eck delete inline_entities accordion_section entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities basic_body_text entities'.
  $permissions['eck delete inline_entities basic_body_text entities'] = array(
    'name' => 'eck delete inline_entities basic_body_text entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities block_reference entities'.
  $permissions['eck delete inline_entities block_reference entities'] = array(
    'name' => 'eck delete inline_entities block_reference entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities bundles'.
  $permissions['eck delete inline_entities bundles'] = array(
    'name' => 'eck delete inline_entities bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities course_date_time entities'.
  $permissions['eck delete inline_entities course_date_time entities'] = array(
    'name' => 'eck delete inline_entities course_date_time entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities featured_content entities'.
  $permissions['eck delete inline_entities featured_content entities'] = array(
    'name' => 'eck delete inline_entities featured_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities featured_success_story entities'.
  $permissions['eck delete inline_entities featured_success_story entities'] = array(
    'name' => 'eck delete inline_entities featured_success_story entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities link_redirects entities'.
  $permissions['eck delete inline_entities link_redirects entities'] = array(
    'name' => 'eck delete inline_entities link_redirects entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities location entities'.
  $permissions['eck delete inline_entities location entities'] = array(
    'name' => 'eck delete inline_entities location entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities our_victories entities'.
  $permissions['eck delete inline_entities our_victories entities'] = array(
    'name' => 'eck delete inline_entities our_victories entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities related_links entities'.
  $permissions['eck delete inline_entities related_links entities'] = array(
    'name' => 'eck delete inline_entities related_links entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities topic_page_content entities'.
  $permissions['eck delete inline_entities topic_page_content entities'] = array(
    'name' => 'eck delete inline_entities topic_page_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities topic_page_facts entities'.
  $permissions['eck delete inline_entities topic_page_facts entities'] = array(
    'name' => 'eck delete inline_entities topic_page_facts entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete inline_entities topic_page_sidebar_content entities'.
  $permissions['eck delete inline_entities topic_page_sidebar_content entities'] = array(
    'name' => 'eck delete inline_entities topic_page_sidebar_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete intake bundles'.
  $permissions['eck delete intake bundles'] = array(
    'name' => 'eck delete intake bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete intake intake entities'.
  $permissions['eck delete intake intake entities'] = array(
    'name' => 'eck delete intake intake entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit accordion_item accordion_item entities'.
  $permissions['eck edit accordion_item accordion_item entities'] = array(
    'name' => 'eck edit accordion_item accordion_item entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit accordion_item bundles'.
  $permissions['eck edit accordion_item bundles'] = array(
    'name' => 'eck edit accordion_item bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit bundles'.
  $permissions['eck edit bundles'] = array(
    'name' => 'eck edit bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit contact_information bundles'.
  $permissions['eck edit contact_information bundles'] = array(
    'name' => 'eck edit contact_information bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit contact_information contact_information entities'.
  $permissions['eck edit contact_information contact_information entities'] = array(
    'name' => 'eck edit contact_information contact_information entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entities'.
  $permissions['eck edit entities'] = array(
    'name' => 'eck edit entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entity types'.
  $permissions['eck edit entity types'] = array(
    'name' => 'eck edit entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities accordion_section entities'.
  $permissions['eck edit inline_entities accordion_section entities'] = array(
    'name' => 'eck edit inline_entities accordion_section entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities basic_body_text entities'.
  $permissions['eck edit inline_entities basic_body_text entities'] = array(
    'name' => 'eck edit inline_entities basic_body_text entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities block_reference entities'.
  $permissions['eck edit inline_entities block_reference entities'] = array(
    'name' => 'eck edit inline_entities block_reference entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities bundles'.
  $permissions['eck edit inline_entities bundles'] = array(
    'name' => 'eck edit inline_entities bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities course_date_time entities'.
  $permissions['eck edit inline_entities course_date_time entities'] = array(
    'name' => 'eck edit inline_entities course_date_time entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities featured_content entities'.
  $permissions['eck edit inline_entities featured_content entities'] = array(
    'name' => 'eck edit inline_entities featured_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities featured_success_story entities'.
  $permissions['eck edit inline_entities featured_success_story entities'] = array(
    'name' => 'eck edit inline_entities featured_success_story entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities link_redirects entities'.
  $permissions['eck edit inline_entities link_redirects entities'] = array(
    'name' => 'eck edit inline_entities link_redirects entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities location entities'.
  $permissions['eck edit inline_entities location entities'] = array(
    'name' => 'eck edit inline_entities location entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities our_victories entities'.
  $permissions['eck edit inline_entities our_victories entities'] = array(
    'name' => 'eck edit inline_entities our_victories entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities related_links entities'.
  $permissions['eck edit inline_entities related_links entities'] = array(
    'name' => 'eck edit inline_entities related_links entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities topic_page_content entities'.
  $permissions['eck edit inline_entities topic_page_content entities'] = array(
    'name' => 'eck edit inline_entities topic_page_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities topic_page_facts entities'.
  $permissions['eck edit inline_entities topic_page_facts entities'] = array(
    'name' => 'eck edit inline_entities topic_page_facts entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit inline_entities topic_page_sidebar_content entities'.
  $permissions['eck edit inline_entities topic_page_sidebar_content entities'] = array(
    'name' => 'eck edit inline_entities topic_page_sidebar_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit intake bundles'.
  $permissions['eck edit intake bundles'] = array(
    'name' => 'eck edit intake bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit intake intake entities'.
  $permissions['eck edit intake intake entities'] = array(
    'name' => 'eck edit intake intake entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list accordion_item accordion_item entities'.
  $permissions['eck list accordion_item accordion_item entities'] = array(
    'name' => 'eck list accordion_item accordion_item entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list accordion_item bundles'.
  $permissions['eck list accordion_item bundles'] = array(
    'name' => 'eck list accordion_item bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list bundles'.
  $permissions['eck list bundles'] = array(
    'name' => 'eck list bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list contact_information bundles'.
  $permissions['eck list contact_information bundles'] = array(
    'name' => 'eck list contact_information bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list contact_information contact_information entities'.
  $permissions['eck list contact_information contact_information entities'] = array(
    'name' => 'eck list contact_information contact_information entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entities'.
  $permissions['eck list entities'] = array(
    'name' => 'eck list entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entity types'.
  $permissions['eck list entity types'] = array(
    'name' => 'eck list entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities accordion_section entities'.
  $permissions['eck list inline_entities accordion_section entities'] = array(
    'name' => 'eck list inline_entities accordion_section entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities basic_body_text entities'.
  $permissions['eck list inline_entities basic_body_text entities'] = array(
    'name' => 'eck list inline_entities basic_body_text entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities block_reference entities'.
  $permissions['eck list inline_entities block_reference entities'] = array(
    'name' => 'eck list inline_entities block_reference entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities bundles'.
  $permissions['eck list inline_entities bundles'] = array(
    'name' => 'eck list inline_entities bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities course_date_time entities'.
  $permissions['eck list inline_entities course_date_time entities'] = array(
    'name' => 'eck list inline_entities course_date_time entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities featured_content entities'.
  $permissions['eck list inline_entities featured_content entities'] = array(
    'name' => 'eck list inline_entities featured_content entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities featured_success_story entities'.
  $permissions['eck list inline_entities featured_success_story entities'] = array(
    'name' => 'eck list inline_entities featured_success_story entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities link_redirects entities'.
  $permissions['eck list inline_entities link_redirects entities'] = array(
    'name' => 'eck list inline_entities link_redirects entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities location entities'.
  $permissions['eck list inline_entities location entities'] = array(
    'name' => 'eck list inline_entities location entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities our_victories entities'.
  $permissions['eck list inline_entities our_victories entities'] = array(
    'name' => 'eck list inline_entities our_victories entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities related_links entities'.
  $permissions['eck list inline_entities related_links entities'] = array(
    'name' => 'eck list inline_entities related_links entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities topic_page_content entities'.
  $permissions['eck list inline_entities topic_page_content entities'] = array(
    'name' => 'eck list inline_entities topic_page_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities topic_page_facts entities'.
  $permissions['eck list inline_entities topic_page_facts entities'] = array(
    'name' => 'eck list inline_entities topic_page_facts entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list inline_entities topic_page_sidebar_content entities'.
  $permissions['eck list inline_entities topic_page_sidebar_content entities'] = array(
    'name' => 'eck list inline_entities topic_page_sidebar_content entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list intake bundles'.
  $permissions['eck list intake bundles'] = array(
    'name' => 'eck list intake bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list intake intake entities'.
  $permissions['eck list intake intake entities'] = array(
    'name' => 'eck list intake intake entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view accordion_item accordion_item entities'.
  $permissions['eck view accordion_item accordion_item entities'] = array(
    'name' => 'eck view accordion_item accordion_item entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view accordion_item bundles'.
  $permissions['eck view accordion_item bundles'] = array(
    'name' => 'eck view accordion_item bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view contact_information bundles'.
  $permissions['eck view contact_information bundles'] = array(
    'name' => 'eck view contact_information bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view contact_information contact_information entities'.
  $permissions['eck view contact_information contact_information entities'] = array(
    'name' => 'eck view contact_information contact_information entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view entities'.
  $permissions['eck view entities'] = array(
    'name' => 'eck view entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities accordion_section entities'.
  $permissions['eck view inline_entities accordion_section entities'] = array(
    'name' => 'eck view inline_entities accordion_section entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities basic_body_text entities'.
  $permissions['eck view inline_entities basic_body_text entities'] = array(
    'name' => 'eck view inline_entities basic_body_text entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities block_reference entities'.
  $permissions['eck view inline_entities block_reference entities'] = array(
    'name' => 'eck view inline_entities block_reference entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities bundles'.
  $permissions['eck view inline_entities bundles'] = array(
    'name' => 'eck view inline_entities bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities course_date_time entities'.
  $permissions['eck view inline_entities course_date_time entities'] = array(
    'name' => 'eck view inline_entities course_date_time entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities featured_content entities'.
  $permissions['eck view inline_entities featured_content entities'] = array(
    'name' => 'eck view inline_entities featured_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities featured_success_story entities'.
  $permissions['eck view inline_entities featured_success_story entities'] = array(
    'name' => 'eck view inline_entities featured_success_story entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities link_redirects entities'.
  $permissions['eck view inline_entities link_redirects entities'] = array(
    'name' => 'eck view inline_entities link_redirects entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities location entities'.
  $permissions['eck view inline_entities location entities'] = array(
    'name' => 'eck view inline_entities location entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities our_victories entities'.
  $permissions['eck view inline_entities our_victories entities'] = array(
    'name' => 'eck view inline_entities our_victories entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities related_links entities'.
  $permissions['eck view inline_entities related_links entities'] = array(
    'name' => 'eck view inline_entities related_links entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities topic_page_content entities'.
  $permissions['eck view inline_entities topic_page_content entities'] = array(
    'name' => 'eck view inline_entities topic_page_content entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities topic_page_facts entities'.
  $permissions['eck view inline_entities topic_page_facts entities'] = array(
    'name' => 'eck view inline_entities topic_page_facts entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view inline_entities topic_page_sidebar_content entities'.
  $permissions['eck view inline_entities topic_page_sidebar_content entities'] = array(
    'name' => 'eck view inline_entities topic_page_sidebar_content entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view intake bundles'.
  $permissions['eck view intake bundles'] = array(
    'name' => 'eck view intake bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view intake intake entities'.
  $permissions['eck view intake intake entities'] = array(
    'name' => 'eck view intake intake entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any basic_bean bean'.
  $permissions['edit any basic_bean bean'] = array(
    'name' => 'edit any basic_bean bean',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any campus content'.
  $permissions['edit any campus content'] = array(
    'name' => 'edit any campus content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campus_housing content'.
  $permissions['edit any campus_housing content'] = array(
    'name' => 'edit any campus_housing content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any choose_vu bean'.
  $permissions['edit any choose_vu bean'] = array(
    'name' => 'edit any choose_vu bean',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any course_fees content'.
  $permissions['edit any course_fees content'] = array(
    'name' => 'edit any course_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses content'.
  $permissions['edit any courses content'] = array(
    'name' => 'edit any courses content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any events content'.
  $permissions['edit any events content'] = array(
    'name' => 'edit any events content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any fym_banner_type bean'.
  $permissions['edit any fym_banner_type bean'] = array(
    'name' => 'edit any fym_banner_type bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any hero_banner bean'.
  $permissions['edit any hero_banner bean'] = array(
    'name' => 'edit any hero_banner bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any hero_title_box bean'.
  $permissions['edit any hero_title_box bean'] = array(
    'name' => 'edit any hero_title_box bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any homepage_banner bean'.
  $permissions['edit any homepage_banner bean'] = array(
    'name' => 'edit any homepage_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page_builder content'.
  $permissions['edit any page_builder content'] = array(
    'name' => 'edit any page_builder content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any promo bean'.
  $permissions['edit any promo bean'] = array(
    'name' => 'edit any promo bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any quick_facts bean'.
  $permissions['edit any quick_facts bean'] = array(
    'name' => 'edit any quick_facts bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any staff_profile content'.
  $permissions['edit any staff_profile content'] = array(
    'name' => 'edit any staff_profile content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any student_testimonials bean'.
  $permissions['edit any student_testimonials bean'] = array(
    'name' => 'edit any student_testimonials bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any study_topic_area content'.
  $permissions['edit any study_topic_area content'] = array(
    'name' => 'edit any study_topic_area content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any success_story content'.
  $permissions['edit any success_story content'] = array(
    'name' => 'edit any success_story content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any topic_pages content'.
  $permissions['edit any topic_pages content'] = array(
    'name' => 'edit any topic_pages content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any unit content'.
  $permissions['edit any unit content'] = array(
    'name' => 'edit any unit content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any unit_fees content'.
  $permissions['edit any unit_fees content'] = array(
    'name' => 'edit any unit_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any unit_set content'.
  $permissions['edit any unit_set content'] = array(
    'name' => 'edit any unit_set content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit field_additional_information'.
  $permissions['edit field_additional_information'] = array(
    'name' => 'edit field_additional_information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_additional_requirements'.
  $permissions['edit field_additional_requirements'] = array(
    'name' => 'edit field_additional_requirements',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_admission_requirements_he'.
  $permissions['edit field_admission_requirements_he'] = array(
    'name' => 'edit field_admission_requirements_he',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_admission_requirements_se'.
  $permissions['edit field_admission_requirements_se'] = array(
    'name' => 'edit field_admission_requirements_se',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_admission_requirements_vet'.
  $permissions['edit field_admission_requirements_vet'] = array(
    'name' => 'edit field_admission_requirements_vet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_admission_requirements_wl'.
  $permissions['edit field_admission_requirements_wl'] = array(
    'name' => 'edit field_admission_requirements_wl',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_atar_indicator'.
  $permissions['edit field_atar_indicator'] = array(
    'name' => 'edit field_atar_indicator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_atar_minimum_entry'.
  $permissions['edit field_atar_minimum_entry'] = array(
    'name' => 'edit field_atar_minimum_entry',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_atar_profile_data'.
  $permissions['edit field_atar_profile_data'] = array(
    'name' => 'edit field_atar_profile_data',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_career'.
  $permissions['edit field_career'] = array(
    'name' => 'edit field_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_college'.
  $permissions['edit field_college'] = array(
    'name' => 'edit field_college',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_completion_rules'.
  $permissions['edit field_completion_rules'] = array(
    'name' => 'edit field_completion_rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_component_section_style'.
  $permissions['edit field_component_section_style'] = array(
    'name' => 'edit field_component_section_style',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_content_area'.
  $permissions['edit field_content_area'] = array(
    'name' => 'edit field_content_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_continuing_student'.
  $permissions['edit field_continuing_student'] = array(
    'name' => 'edit field_continuing_student',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_aqf'.
  $permissions['edit field_course_aqf'] = array(
    'name' => 'edit field_course_aqf',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_followed_by'.
  $permissions['edit field_course_followed_by'] = array(
    'name' => 'edit field_course_followed_by',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_midyear_intake'.
  $permissions['edit field_course_midyear_intake'] = array(
    'name' => 'edit field_course_midyear_intake',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_offered'.
  $permissions['edit field_course_offered'] = array(
    'name' => 'edit field_course_offered',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_preceded_by'.
  $permissions['edit field_course_preceded_by'] = array(
    'name' => 'edit field_course_preceded_by',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_sort_title'.
  $permissions['edit field_course_sort_title'] = array(
    'name' => 'edit field_course_sort_title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_units'.
  $permissions['edit field_course_units'] = array(
    'name' => 'edit field_course_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_credit_points'.
  $permissions['edit field_credit_points'] = array(
    'name' => 'edit field_credit_points',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_cricos_code'.
  $permissions['edit field_cricos_code'] = array(
    'name' => 'edit field_cricos_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_cut_off_date'.
  $permissions['edit field_cut_off_date'] = array(
    'name' => 'edit field_cut_off_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_destination_page'.
  $permissions['edit field_destination_page'] = array(
    'name' => 'edit field_destination_page',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_domestic'.
  $permissions['edit field_domestic'] = array(
    'name' => 'edit field_domestic',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_duration'.
  $permissions['edit field_duration'] = array(
    'name' => 'edit field_duration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_entry_requirements_in'.
  $permissions['edit field_entry_requirements_in'] = array(
    'name' => 'edit field_entry_requirements_in',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_entry_requirements_pg'.
  $permissions['edit field_entry_requirements_pg'] = array(
    'name' => 'edit field_entry_requirements_pg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_entry_requirements_ve'.
  $permissions['edit field_entry_requirements_ve'] = array(
    'name' => 'edit field_entry_requirements_ve',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_excerpt'.
  $permissions['edit field_excerpt'] = array(
    'name' => 'edit field_excerpt',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_feature_duration'.
  $permissions['edit field_feature_duration'] = array(
    'name' => 'edit field_feature_duration',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_featured_success_story'.
  $permissions['edit field_featured_success_story'] = array(
    'name' => 'edit field_featured_success_story',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_first_off_date'.
  $permissions['edit field_first_off_date'] = array(
    'name' => 'edit field_first_off_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_free_tafe'.
  $permissions['edit field_free_tafe'] = array(
    'name' => 'edit field_free_tafe',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fym_body_text'.
  $permissions['edit field_fym_body_text'] = array(
    'name' => 'edit field_fym_body_text',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fym_logo'.
  $permissions['edit field_fym_logo'] = array(
    'name' => 'edit field_fym_logo',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_handbook_include'.
  $permissions['edit field_handbook_include'] = array(
    'name' => 'edit field_handbook_include',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_he_study'.
  $permissions['edit field_he_study'] = array(
    'name' => 'edit field_he_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_how_to_apply'.
  $permissions['edit field_how_to_apply'] = array(
    'name' => 'edit field_how_to_apply',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_how_to_apply_title'.
  $permissions['edit field_how_to_apply_title'] = array(
    'name' => 'edit field_how_to_apply_title',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_admission_requirements'.
  $permissions['edit field_imp_admission_requirements'] = array(
    'name' => 'edit field_imp_admission_requirements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_career'.
  $permissions['edit field_imp_career'] = array(
    'name' => 'edit field_imp_career',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_delivery_mode'.
  $permissions['edit field_imp_delivery_mode'] = array(
    'name' => 'edit field_imp_delivery_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_desc'.
  $permissions['edit field_imp_desc'] = array(
    'name' => 'edit field_imp_desc',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_inter_campus'.
  $permissions['edit field_imp_inter_campus'] = array(
    'name' => 'edit field_imp_inter_campus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_intro'.
  $permissions['edit field_imp_intro'] = array(
    'name' => 'edit field_imp_intro',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_object'.
  $permissions['edit field_imp_object'] = array(
    'name' => 'edit field_imp_object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_prereq_units'.
  $permissions['edit field_imp_prereq_units'] = array(
    'name' => 'edit field_imp_prereq_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_structure'.
  $permissions['edit field_imp_structure'] = array(
    'name' => 'edit field_imp_structure',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_int_sem_int'.
  $permissions['edit field_int_sem_int'] = array(
    'name' => 'edit field_int_sem_int',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inter_lang_requirements'.
  $permissions['edit field_inter_lang_requirements'] = array(
    'name' => 'edit field_inter_lang_requirements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_international'.
  $permissions['edit field_international'] = array(
    'name' => 'edit field_international',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_international_body'.
  $permissions['edit field_international_body'] = array(
    'name' => 'edit field_international_body',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_international_fees'.
  $permissions['edit field_international_fees'] = array(
    'name' => 'edit field_international_fees',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_international_study'.
  $permissions['edit field_international_study'] = array(
    'name' => 'edit field_international_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_legacy_location'.
  $permissions['edit field_legacy_location'] = array(
    'name' => 'edit field_legacy_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_location_other'.
  $permissions['edit field_location_other'] = array(
    'name' => 'edit field_location_other',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_location_other_editable'.
  $permissions['edit field_location_other_editable'] = array(
    'name' => 'edit field_location_other_editable',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_location_tag'.
  $permissions['edit field_location_tag'] = array(
    'name' => 'edit field_location_tag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_locations'.
  $permissions['edit field_locations'] = array(
    'name' => 'edit field_locations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_materials_fee'.
  $permissions['edit field_materials_fee'] = array(
    'name' => 'edit field_materials_fee',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_more_button_link'.
  $permissions['edit field_more_button_link'] = array(
    'name' => 'edit field_more_button_link',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_multiple_audience_group'.
  $permissions['edit field_multiple_audience_group'] = array(
    'name' => 'edit field_multiple_audience_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_on_this_page'.
  $permissions['edit field_on_this_page'] = array(
    'name' => 'edit field_on_this_page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_page_lvl_1_thumbnail_image'.
  $permissions['edit field_page_lvl_1_thumbnail_image'] = array(
    'name' => 'edit field_page_lvl_1_thumbnail_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_page_subsite'.
  $permissions['edit field_page_subsite'] = array(
    'name' => 'edit field_page_subsite',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_postgrad_research'.
  $permissions['edit field_postgrad_research'] = array(
    'name' => 'edit field_postgrad_research',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_researcher_profile'.
  $permissions['edit field_researcher_profile'] = array(
    'name' => 'edit field_researcher_profile',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_results_user_access'.
  $permissions['edit field_results_user_access'] = array(
    'name' => 'edit field_results_user_access',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_se_atar_only'.
  $permissions['edit field_se_atar_only'] = array(
    'name' => 'edit field_se_atar_only',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_se_atar_plus'.
  $permissions['edit field_se_atar_plus'] = array(
    'name' => 'edit field_se_atar_plus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_se_na'.
  $permissions['edit field_se_na'] = array(
    'name' => 'edit field_se_na',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_sidebar_content'.
  $permissions['edit field_sidebar_content'] = array(
    'name' => 'edit field_sidebar_content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_staff_id'.
  $permissions['edit field_staff_id'] = array(
    'name' => 'edit field_staff_id',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_study_mode'.
  $permissions['edit field_study_mode'] = array(
    'name' => 'edit field_study_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_study_topic_area'.
  $permissions['edit field_study_topic_area'] = array(
    'name' => 'edit field_study_topic_area',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_sup_application_info'.
  $permissions['edit field_sup_application_info'] = array(
    'name' => 'edit field_sup_application_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_supplementary_career_info'.
  $permissions['edit field_supplementary_career_info'] = array(
    'name' => 'edit field_supplementary_career_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_supplementary_date_info'.
  $permissions['edit field_supplementary_date_info'] = array(
    'name' => 'edit field_supplementary_date_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_tags'.
  $permissions['edit field_tags'] = array(
    'name' => 'edit field_tags',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_title_area_feature_image'.
  $permissions['edit field_title_area_feature_image'] = array(
    'name' => 'edit field_title_area_feature_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_total_study'.
  $permissions['edit field_total_study'] = array(
    'name' => 'edit field_total_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_unit_code'.
  $permissions['edit field_unit_code'] = array(
    'name' => 'edit field_unit_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_unit_id'.
  $permissions['edit field_unit_id'] = array(
    'name' => 'edit field_unit_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_unit_lev'.
  $permissions['edit field_unit_lev'] = array(
    'name' => 'edit field_unit_lev',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_unit_ver'.
  $permissions['edit field_unit_ver'] = array(
    'name' => 'edit field_unit_ver',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ve_cohorts'.
  $permissions['edit field_ve_cohorts'] = array(
    'name' => 'edit field_ve_cohorts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ve_study'.
  $permissions['edit field_ve_study'] = array(
    'name' => 'edit field_ve_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_webhook_url'.
  $permissions['edit field_webhook_url'] = array(
    'name' => 'edit field_webhook_url',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_work_life'.
  $permissions['edit field_work_life'] = array(
    'name' => 'edit field_work_life',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit fieldable pane_featured_content'.
  $permissions['edit fieldable pane_featured_content'] = array(
    'name' => 'edit fieldable pane_featured_content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own campus content'.
  $permissions['edit own campus content'] = array(
    'name' => 'edit own campus content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campus_housing content'.
  $permissions['edit own campus_housing content'] = array(
    'name' => 'edit own campus_housing content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own course_fees content'.
  $permissions['edit own course_fees content'] = array(
    'name' => 'edit own course_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own courses content'.
  $permissions['edit own courses content'] = array(
    'name' => 'edit own courses content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own events content'.
  $permissions['edit own events content'] = array(
    'name' => 'edit own events content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_additional_information'.
  $permissions['edit own field_additional_information'] = array(
    'name' => 'edit own field_additional_information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_additional_requirements'.
  $permissions['edit own field_additional_requirements'] = array(
    'name' => 'edit own field_additional_requirements',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_admission_requirements_he'.
  $permissions['edit own field_admission_requirements_he'] = array(
    'name' => 'edit own field_admission_requirements_he',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_admission_requirements_se'.
  $permissions['edit own field_admission_requirements_se'] = array(
    'name' => 'edit own field_admission_requirements_se',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_admission_requirements_vet'.
  $permissions['edit own field_admission_requirements_vet'] = array(
    'name' => 'edit own field_admission_requirements_vet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_admission_requirements_wl'.
  $permissions['edit own field_admission_requirements_wl'] = array(
    'name' => 'edit own field_admission_requirements_wl',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_atar_indicator'.
  $permissions['edit own field_atar_indicator'] = array(
    'name' => 'edit own field_atar_indicator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_atar_minimum_entry'.
  $permissions['edit own field_atar_minimum_entry'] = array(
    'name' => 'edit own field_atar_minimum_entry',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_atar_profile_data'.
  $permissions['edit own field_atar_profile_data'] = array(
    'name' => 'edit own field_atar_profile_data',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_career'.
  $permissions['edit own field_career'] = array(
    'name' => 'edit own field_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_college'.
  $permissions['edit own field_college'] = array(
    'name' => 'edit own field_college',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_completion_rules'.
  $permissions['edit own field_completion_rules'] = array(
    'name' => 'edit own field_completion_rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_component_section_style'.
  $permissions['edit own field_component_section_style'] = array(
    'name' => 'edit own field_component_section_style',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_content_area'.
  $permissions['edit own field_content_area'] = array(
    'name' => 'edit own field_content_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_continuing_student'.
  $permissions['edit own field_continuing_student'] = array(
    'name' => 'edit own field_continuing_student',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_aqf'.
  $permissions['edit own field_course_aqf'] = array(
    'name' => 'edit own field_course_aqf',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_followed_by'.
  $permissions['edit own field_course_followed_by'] = array(
    'name' => 'edit own field_course_followed_by',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_midyear_intake'.
  $permissions['edit own field_course_midyear_intake'] = array(
    'name' => 'edit own field_course_midyear_intake',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_offered'.
  $permissions['edit own field_course_offered'] = array(
    'name' => 'edit own field_course_offered',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_preceded_by'.
  $permissions['edit own field_course_preceded_by'] = array(
    'name' => 'edit own field_course_preceded_by',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_sort_title'.
  $permissions['edit own field_course_sort_title'] = array(
    'name' => 'edit own field_course_sort_title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_units'.
  $permissions['edit own field_course_units'] = array(
    'name' => 'edit own field_course_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_credit_points'.
  $permissions['edit own field_credit_points'] = array(
    'name' => 'edit own field_credit_points',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_cricos_code'.
  $permissions['edit own field_cricos_code'] = array(
    'name' => 'edit own field_cricos_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_cut_off_date'.
  $permissions['edit own field_cut_off_date'] = array(
    'name' => 'edit own field_cut_off_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_destination_page'.
  $permissions['edit own field_destination_page'] = array(
    'name' => 'edit own field_destination_page',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_domestic'.
  $permissions['edit own field_domestic'] = array(
    'name' => 'edit own field_domestic',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_duration'.
  $permissions['edit own field_duration'] = array(
    'name' => 'edit own field_duration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_entry_requirements_in'.
  $permissions['edit own field_entry_requirements_in'] = array(
    'name' => 'edit own field_entry_requirements_in',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_entry_requirements_pg'.
  $permissions['edit own field_entry_requirements_pg'] = array(
    'name' => 'edit own field_entry_requirements_pg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_entry_requirements_ve'.
  $permissions['edit own field_entry_requirements_ve'] = array(
    'name' => 'edit own field_entry_requirements_ve',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_excerpt'.
  $permissions['edit own field_excerpt'] = array(
    'name' => 'edit own field_excerpt',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_feature_duration'.
  $permissions['edit own field_feature_duration'] = array(
    'name' => 'edit own field_feature_duration',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_featured_success_story'.
  $permissions['edit own field_featured_success_story'] = array(
    'name' => 'edit own field_featured_success_story',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_first_off_date'.
  $permissions['edit own field_first_off_date'] = array(
    'name' => 'edit own field_first_off_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_free_tafe'.
  $permissions['edit own field_free_tafe'] = array(
    'name' => 'edit own field_free_tafe',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fym_body_text'.
  $permissions['edit own field_fym_body_text'] = array(
    'name' => 'edit own field_fym_body_text',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fym_logo'.
  $permissions['edit own field_fym_logo'] = array(
    'name' => 'edit own field_fym_logo',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_handbook_include'.
  $permissions['edit own field_handbook_include'] = array(
    'name' => 'edit own field_handbook_include',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_he_study'.
  $permissions['edit own field_he_study'] = array(
    'name' => 'edit own field_he_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_how_to_apply'.
  $permissions['edit own field_how_to_apply'] = array(
    'name' => 'edit own field_how_to_apply',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_how_to_apply_title'.
  $permissions['edit own field_how_to_apply_title'] = array(
    'name' => 'edit own field_how_to_apply_title',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_admission_requirements'.
  $permissions['edit own field_imp_admission_requirements'] = array(
    'name' => 'edit own field_imp_admission_requirements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_career'.
  $permissions['edit own field_imp_career'] = array(
    'name' => 'edit own field_imp_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_delivery_mode'.
  $permissions['edit own field_imp_delivery_mode'] = array(
    'name' => 'edit own field_imp_delivery_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_desc'.
  $permissions['edit own field_imp_desc'] = array(
    'name' => 'edit own field_imp_desc',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_inter_campus'.
  $permissions['edit own field_imp_inter_campus'] = array(
    'name' => 'edit own field_imp_inter_campus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_intro'.
  $permissions['edit own field_imp_intro'] = array(
    'name' => 'edit own field_imp_intro',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_object'.
  $permissions['edit own field_imp_object'] = array(
    'name' => 'edit own field_imp_object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_prereq_units'.
  $permissions['edit own field_imp_prereq_units'] = array(
    'name' => 'edit own field_imp_prereq_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_structure'.
  $permissions['edit own field_imp_structure'] = array(
    'name' => 'edit own field_imp_structure',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_int_sem_int'.
  $permissions['edit own field_int_sem_int'] = array(
    'name' => 'edit own field_int_sem_int',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inter_lang_requirements'.
  $permissions['edit own field_inter_lang_requirements'] = array(
    'name' => 'edit own field_inter_lang_requirements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_international'.
  $permissions['edit own field_international'] = array(
    'name' => 'edit own field_international',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_international_body'.
  $permissions['edit own field_international_body'] = array(
    'name' => 'edit own field_international_body',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_international_fees'.
  $permissions['edit own field_international_fees'] = array(
    'name' => 'edit own field_international_fees',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_international_study'.
  $permissions['edit own field_international_study'] = array(
    'name' => 'edit own field_international_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_legacy_location'.
  $permissions['edit own field_legacy_location'] = array(
    'name' => 'edit own field_legacy_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_location_other'.
  $permissions['edit own field_location_other'] = array(
    'name' => 'edit own field_location_other',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_location_other_editable'.
  $permissions['edit own field_location_other_editable'] = array(
    'name' => 'edit own field_location_other_editable',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_location_tag'.
  $permissions['edit own field_location_tag'] = array(
    'name' => 'edit own field_location_tag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_locations'.
  $permissions['edit own field_locations'] = array(
    'name' => 'edit own field_locations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_materials_fee'.
  $permissions['edit own field_materials_fee'] = array(
    'name' => 'edit own field_materials_fee',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_more_button_link'.
  $permissions['edit own field_more_button_link'] = array(
    'name' => 'edit own field_more_button_link',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_multiple_audience_group'.
  $permissions['edit own field_multiple_audience_group'] = array(
    'name' => 'edit own field_multiple_audience_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_on_this_page'.
  $permissions['edit own field_on_this_page'] = array(
    'name' => 'edit own field_on_this_page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_page_lvl_1_thumbnail_image'.
  $permissions['edit own field_page_lvl_1_thumbnail_image'] = array(
    'name' => 'edit own field_page_lvl_1_thumbnail_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_page_subsite'.
  $permissions['edit own field_page_subsite'] = array(
    'name' => 'edit own field_page_subsite',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_postgrad_research'.
  $permissions['edit own field_postgrad_research'] = array(
    'name' => 'edit own field_postgrad_research',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_researcher_profile'.
  $permissions['edit own field_researcher_profile'] = array(
    'name' => 'edit own field_researcher_profile',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_results_user_access'.
  $permissions['edit own field_results_user_access'] = array(
    'name' => 'edit own field_results_user_access',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_se_atar_only'.
  $permissions['edit own field_se_atar_only'] = array(
    'name' => 'edit own field_se_atar_only',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_se_atar_plus'.
  $permissions['edit own field_se_atar_plus'] = array(
    'name' => 'edit own field_se_atar_plus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_se_na'.
  $permissions['edit own field_se_na'] = array(
    'name' => 'edit own field_se_na',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_sidebar_content'.
  $permissions['edit own field_sidebar_content'] = array(
    'name' => 'edit own field_sidebar_content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_staff_id'.
  $permissions['edit own field_staff_id'] = array(
    'name' => 'edit own field_staff_id',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_study_mode'.
  $permissions['edit own field_study_mode'] = array(
    'name' => 'edit own field_study_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_study_topic_area'.
  $permissions['edit own field_study_topic_area'] = array(
    'name' => 'edit own field_study_topic_area',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_sup_application_info'.
  $permissions['edit own field_sup_application_info'] = array(
    'name' => 'edit own field_sup_application_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_supplementary_career_info'.
  $permissions['edit own field_supplementary_career_info'] = array(
    'name' => 'edit own field_supplementary_career_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_supplementary_date_info'.
  $permissions['edit own field_supplementary_date_info'] = array(
    'name' => 'edit own field_supplementary_date_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_tags'.
  $permissions['edit own field_tags'] = array(
    'name' => 'edit own field_tags',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_title_area_feature_image'.
  $permissions['edit own field_title_area_feature_image'] = array(
    'name' => 'edit own field_title_area_feature_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_total_study'.
  $permissions['edit own field_total_study'] = array(
    'name' => 'edit own field_total_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_unit_code'.
  $permissions['edit own field_unit_code'] = array(
    'name' => 'edit own field_unit_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_unit_id'.
  $permissions['edit own field_unit_id'] = array(
    'name' => 'edit own field_unit_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_unit_lev'.
  $permissions['edit own field_unit_lev'] = array(
    'name' => 'edit own field_unit_lev',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_unit_ver'.
  $permissions['edit own field_unit_ver'] = array(
    'name' => 'edit own field_unit_ver',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ve_cohorts'.
  $permissions['edit own field_ve_cohorts'] = array(
    'name' => 'edit own field_ve_cohorts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ve_study'.
  $permissions['edit own field_ve_study'] = array(
    'name' => 'edit own field_ve_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_webhook_url'.
  $permissions['edit own field_webhook_url'] = array(
    'name' => 'edit own field_webhook_url',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_work_life'.
  $permissions['edit own field_work_life'] = array(
    'name' => 'edit own field_work_life',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page_builder content'.
  $permissions['edit own page_builder content'] = array(
    'name' => 'edit own page_builder content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own staff_profile content'.
  $permissions['edit own staff_profile content'] = array(
    'name' => 'edit own staff_profile content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own study_topic_area content'.
  $permissions['edit own study_topic_area content'] = array(
    'name' => 'edit own study_topic_area content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own success_story content'.
  $permissions['edit own success_story content'] = array(
    'name' => 'edit own success_story content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own topic_pages content'.
  $permissions['edit own topic_pages content'] = array(
    'name' => 'edit own topic_pages content',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own unit content'.
  $permissions['edit own unit content'] = array(
    'name' => 'edit own unit content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own unit_fees content'.
  $permissions['edit own unit_fees content'] = array(
    'name' => 'edit own unit_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own unit_set content'.
  $permissions['edit own unit_set content'] = array(
    'name' => 'edit own unit_set content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in audience'.
  $permissions['edit terms in audience'] = array(
    'name' => 'edit terms in audience',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in delivery_modes'.
  $permissions['edit terms in delivery_modes'] = array(
    'name' => 'edit terms in delivery_modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in expertise'.
  $permissions['edit terms in expertise'] = array(
    'name' => 'edit terms in expertise',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in fee_disclaimers'.
  $permissions['edit terms in fee_disclaimers'] = array(
    'name' => 'edit terms in fee_disclaimers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in fee_types'.
  $permissions['edit terms in fee_types'] = array(
    'name' => 'edit terms in fee_types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in subsites'.
  $permissions['edit terms in subsites'] = array(
    'name' => 'edit terms in subsites',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in success_categories'.
  $permissions['edit terms in success_categories'] = array(
    'name' => 'edit terms in success_categories',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in unit_set_type'.
  $permissions['edit terms in unit_set_type'] = array(
    'name' => 'edit terms in unit_set_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit_custom_pub_do_not_store_submission_data'.
  $permissions['edit_custom_pub_do_not_store_submission_data'] = array(
    'name' => 'edit_custom_pub_do_not_store_submission_data',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'custom_pub',
  );

  // Exported permission: 'edit_custom_pub_promote'.
  $permissions['edit_custom_pub_promote'] = array(
    'name' => 'edit_custom_pub_promote',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'custom_pub',
  );

  // Exported permission: 'edit_custom_pub_sticky'.
  $permissions['edit_custom_pub_sticky'] = array(
    'name' => 'edit_custom_pub_sticky',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'custom_pub',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import course_fees feeds'.
  $permissions['import course_fees feeds'] = array(
    'name' => 'import course_fees feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import courses feeds'.
  $permissions['import courses feeds'] = array(
    'name' => 'import courses feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import node feeds'.
  $permissions['import node feeds'] = array(
    'name' => 'import node feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import own media'.
  $permissions['import own media'] = array(
    'name' => 'import own media',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'drupagram',
  );

  // Exported permission: 'import unit_fees feeds'.
  $permissions['import unit_fees feeds'] = array(
    'name' => 'import unit_fees feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import units feeds'.
  $permissions['import units feeds'] = array(
    'name' => 'import units feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import units_vet feeds'.
  $permissions['import units_vet feeds'] = array(
    'name' => 'import units_vet feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import unitsets feeds'.
  $permissions['import unitsets feeds'] = array(
    'name' => 'import unitsets feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import user feeds'.
  $permissions['import user feeds'] = array(
    'name' => 'import user feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'make drupagram accounts global'.
  $permissions['make drupagram accounts global'] = array(
    'name' => 'make drupagram accounts global',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'drupagram',
  );

  // Exported permission: 'manage accordion_item properties'.
  $permissions['manage accordion_item properties'] = array(
    'name' => 'manage accordion_item properties',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage contact_information properties'.
  $permissions['manage contact_information properties'] = array(
    'name' => 'manage contact_information properties',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage inline_entities properties'.
  $permissions['manage inline_entities properties'] = array(
    'name' => 'manage inline_entities properties',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage intake properties'.
  $permissions['manage intake properties'] = array(
    'name' => 'manage intake properties',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'menu view unpublished'.
  $permissions['menu view unpublished'] = array(
    'name' => 'menu view unpublished',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'menu_view_unpublished',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'Approver' => 'Approver',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to draft'.
  $permissions['moderate content from published to draft'] = array(
    'name' => 'moderate content from published to draft',
    'roles' => array(
      'Approver' => 'Approver',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'preview focal point'.
  $permissions['preview focal point'] = array(
    'name' => 'preview focal point',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'focal_point',
  );

  // Exported permission: 'purge on-screen'.
  $permissions['purge on-screen'] = array(
    'name' => 'purge on-screen',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'acquia_purge',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Approver' => 'Approver',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'run cron debug'.
  $permissions['run cron debug'] = array(
    'name' => 'run cron debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cron_debug',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for accordion_item'.
  $permissions['show format selection for accordion_item'] = array(
    'name' => 'show format selection for accordion_item',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for bean'.
  $permissions['show format selection for bean'] = array(
    'name' => 'show format selection for bean',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for contact_information'.
  $permissions['show format selection for contact_information'] = array(
    'name' => 'show format selection for contact_information',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for course_information_session_links'.
  $permissions['show format selection for course_information_session_links'] = array(
    'name' => 'show format selection for course_information_session_links',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for entityqueue_subqueue'.
  $permissions['show format selection for entityqueue_subqueue'] = array(
    'name' => 'show format selection for entityqueue_subqueue',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for fieldable_panels_pane'.
  $permissions['show format selection for fieldable_panels_pane'] = array(
    'name' => 'show format selection for fieldable_panels_pane',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for inline_entities'.
  $permissions['show format selection for inline_entities'] = array(
    'name' => 'show format selection for inline_entities',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for intake'.
  $permissions['show format selection for intake'] = array(
    'name' => 'show format selection for intake',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for paragraphs_item'.
  $permissions['show format selection for paragraphs_item'] = array(
    'name' => 'show format selection for paragraphs_item',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch page theme'.
  $permissions['switch page theme'] = array(
    'name' => 'switch page theme',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'vu_core',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'tamper course_fees'.
  $permissions['tamper course_fees'] = array(
    'name' => 'tamper course_fees',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper courses'.
  $permissions['tamper courses'] = array(
    'name' => 'tamper courses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper node'.
  $permissions['tamper node'] = array(
    'name' => 'tamper node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper unit_fees'.
  $permissions['tamper unit_fees'] = array(
    'name' => 'tamper unit_fees',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper units'.
  $permissions['tamper units'] = array(
    'name' => 'tamper units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper units_vet'.
  $permissions['tamper units_vet'] = array(
    'name' => 'tamper units_vet',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper unitsets'.
  $permissions['tamper unitsets'] = array(
    'name' => 'tamper unitsets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper user'.
  $permissions['tamper user'] = array(
    'name' => 'tamper user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock course_fees feeds'.
  $permissions['unlock course_fees feeds'] = array(
    'name' => 'unlock course_fees feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock courses feeds'.
  $permissions['unlock courses feeds'] = array(
    'name' => 'unlock courses feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock node feeds'.
  $permissions['unlock node feeds'] = array(
    'name' => 'unlock node feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock unit_fees feeds'.
  $permissions['unlock unit_fees feeds'] = array(
    'name' => 'unlock unit_fees feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock units feeds'.
  $permissions['unlock units feeds'] = array(
    'name' => 'unlock units feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock units_vet feeds'.
  $permissions['unlock units_vet feeds'] = array(
    'name' => 'unlock units_vet feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock unitsets feeds'.
  $permissions['unlock unitsets feeds'] = array(
    'name' => 'unlock unitsets feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock user feeds'.
  $permissions['unlock user feeds'] = array(
    'name' => 'unlock user feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'update hero_title_box entityqueue'.
  $permissions['update hero_title_box entityqueue'] = array(
    'name' => 'update hero_title_box entityqueue',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'use PHP for label patterns'.
  $permissions['use PHP for label patterns'] = array(
    'name' => 'use PHP for label patterns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'auto_entitylabel',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use funnelback search'.
  $permissions['use funnelback search'] = array(
    'name' => 'use funnelback search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'funnelback',
  );

  // Exported permission: 'use global drupagram account'.
  $permissions['use global drupagram account'] = array(
    'name' => 'use global drupagram account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'drupagram',
  );

  // Exported permission: 'use manual purge blocks'.
  $permissions['use manual purge blocks'] = array(
    'name' => 'use manual purge blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'acquia_purge',
  );

  // Exported permission: 'use media wysiwyg'.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'media_wysiwyg',
  );

  // Exported permission: 'use text format filter_token'.
  $permissions['use text format filter_token'] = array(
    'name' => 'use text format filter_token',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'International Author' => 'International Author',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format migrated_content'.
  $permissions['use text format migrated_content'] = array(
    'name' => 'use text format migrated_content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'International Author' => 'International Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view any basic_bean bean'.
  $permissions['view any basic_bean bean'] = array(
    'name' => 'view any basic_bean bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any choose_vu bean'.
  $permissions['view any choose_vu bean'] = array(
    'name' => 'view any choose_vu bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any fym_banner_type bean'.
  $permissions['view any fym_banner_type bean'] = array(
    'name' => 'view any fym_banner_type bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any hero_banner bean'.
  $permissions['view any hero_banner bean'] = array(
    'name' => 'view any hero_banner bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any hero_title_box bean'.
  $permissions['view any hero_title_box bean'] = array(
    'name' => 'view any hero_title_box bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any homepage_banner bean'.
  $permissions['view any homepage_banner bean'] = array(
    'name' => 'view any homepage_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any promo bean'.
  $permissions['view any promo bean'] = array(
    'name' => 'view any promo bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any quick_facts bean'.
  $permissions['view any quick_facts bean'] = array(
    'name' => 'view any quick_facts bean',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any student_testimonials bean'.
  $permissions['view any student_testimonials bean'] = array(
    'name' => 'view any student_testimonials bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any unpublished campus content'.
  $permissions['view any unpublished campus content'] = array(
    'name' => 'view any unpublished campus content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished campus_housing content'.
  $permissions['view any unpublished campus_housing content'] = array(
    'name' => 'view any unpublished campus_housing content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished course_fees content'.
  $permissions['view any unpublished course_fees content'] = array(
    'name' => 'view any unpublished course_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished courses content'.
  $permissions['view any unpublished courses content'] = array(
    'name' => 'view any unpublished courses content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished events content'.
  $permissions['view any unpublished events content'] = array(
    'name' => 'view any unpublished events content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished news content'.
  $permissions['view any unpublished news content'] = array(
    'name' => 'view any unpublished news content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page_builder content'.
  $permissions['view any unpublished page_builder content'] = array(
    'name' => 'view any unpublished page_builder content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished staff_profile content'.
  $permissions['view any unpublished staff_profile content'] = array(
    'name' => 'view any unpublished staff_profile content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished study_topic_area content'.
  $permissions['view any unpublished study_topic_area content'] = array(
    'name' => 'view any unpublished study_topic_area content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished success_story content'.
  $permissions['view any unpublished success_story content'] = array(
    'name' => 'view any unpublished success_story content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished topic_pages content'.
  $permissions['view any unpublished topic_pages content'] = array(
    'name' => 'view any unpublished topic_pages content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished unit content'.
  $permissions['view any unpublished unit content'] = array(
    'name' => 'view any unpublished unit content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished unit_fees content'.
  $permissions['view any unpublished unit_fees content'] = array(
    'name' => 'view any unpublished unit_fees content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished unit_set content'.
  $permissions['view any unpublished unit_set content'] = array(
    'name' => 'view any unpublished unit_set content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished webform content'.
  $permissions['view any unpublished webform content'] = array(
    'name' => 'view any unpublished webform content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view field_additional_information'.
  $permissions['view field_additional_information'] = array(
    'name' => 'view field_additional_information',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_additional_requirements'.
  $permissions['view field_additional_requirements'] = array(
    'name' => 'view field_additional_requirements',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_admission_requirements_he'.
  $permissions['view field_admission_requirements_he'] = array(
    'name' => 'view field_admission_requirements_he',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_admission_requirements_se'.
  $permissions['view field_admission_requirements_se'] = array(
    'name' => 'view field_admission_requirements_se',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_admission_requirements_vet'.
  $permissions['view field_admission_requirements_vet'] = array(
    'name' => 'view field_admission_requirements_vet',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_admission_requirements_wl'.
  $permissions['view field_admission_requirements_wl'] = array(
    'name' => 'view field_admission_requirements_wl',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_atar_indicator'.
  $permissions['view field_atar_indicator'] = array(
    'name' => 'view field_atar_indicator',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_atar_minimum_entry'.
  $permissions['view field_atar_minimum_entry'] = array(
    'name' => 'view field_atar_minimum_entry',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_atar_profile_data'.
  $permissions['view field_atar_profile_data'] = array(
    'name' => 'view field_atar_profile_data',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_career'.
  $permissions['view field_career'] = array(
    'name' => 'view field_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_college'.
  $permissions['view field_college'] = array(
    'name' => 'view field_college',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_completion_rules'.
  $permissions['view field_completion_rules'] = array(
    'name' => 'view field_completion_rules',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_component_section_style'.
  $permissions['view field_component_section_style'] = array(
    'name' => 'view field_component_section_style',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_content_area'.
  $permissions['view field_content_area'] = array(
    'name' => 'view field_content_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_continuing_student'.
  $permissions['view field_continuing_student'] = array(
    'name' => 'view field_continuing_student',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_aqf'.
  $permissions['view field_course_aqf'] = array(
    'name' => 'view field_course_aqf',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_followed_by'.
  $permissions['view field_course_followed_by'] = array(
    'name' => 'view field_course_followed_by',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_midyear_intake'.
  $permissions['view field_course_midyear_intake'] = array(
    'name' => 'view field_course_midyear_intake',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_offered'.
  $permissions['view field_course_offered'] = array(
    'name' => 'view field_course_offered',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_preceded_by'.
  $permissions['view field_course_preceded_by'] = array(
    'name' => 'view field_course_preceded_by',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_sort_title'.
  $permissions['view field_course_sort_title'] = array(
    'name' => 'view field_course_sort_title',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_units'.
  $permissions['view field_course_units'] = array(
    'name' => 'view field_course_units',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_credit_points'.
  $permissions['view field_credit_points'] = array(
    'name' => 'view field_credit_points',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_cricos_code'.
  $permissions['view field_cricos_code'] = array(
    'name' => 'view field_cricos_code',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_cut_off_date'.
  $permissions['view field_cut_off_date'] = array(
    'name' => 'view field_cut_off_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_destination_page'.
  $permissions['view field_destination_page'] = array(
    'name' => 'view field_destination_page',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_domestic'.
  $permissions['view field_domestic'] = array(
    'name' => 'view field_domestic',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_duration'.
  $permissions['view field_duration'] = array(
    'name' => 'view field_duration',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_entry_requirements_in'.
  $permissions['view field_entry_requirements_in'] = array(
    'name' => 'view field_entry_requirements_in',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_entry_requirements_pg'.
  $permissions['view field_entry_requirements_pg'] = array(
    'name' => 'view field_entry_requirements_pg',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_entry_requirements_ve'.
  $permissions['view field_entry_requirements_ve'] = array(
    'name' => 'view field_entry_requirements_ve',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_excerpt'.
  $permissions['view field_excerpt'] = array(
    'name' => 'view field_excerpt',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_feature_duration'.
  $permissions['view field_feature_duration'] = array(
    'name' => 'view field_feature_duration',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_featured_success_story'.
  $permissions['view field_featured_success_story'] = array(
    'name' => 'view field_featured_success_story',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_first_off_date'.
  $permissions['view field_first_off_date'] = array(
    'name' => 'view field_first_off_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_free_tafe'.
  $permissions['view field_free_tafe'] = array(
    'name' => 'view field_free_tafe',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fym_body_text'.
  $permissions['view field_fym_body_text'] = array(
    'name' => 'view field_fym_body_text',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fym_logo'.
  $permissions['view field_fym_logo'] = array(
    'name' => 'view field_fym_logo',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_handbook_include'.
  $permissions['view field_handbook_include'] = array(
    'name' => 'view field_handbook_include',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_he_study'.
  $permissions['view field_he_study'] = array(
    'name' => 'view field_he_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_how_to_apply'.
  $permissions['view field_how_to_apply'] = array(
    'name' => 'view field_how_to_apply',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_how_to_apply_title'.
  $permissions['view field_how_to_apply_title'] = array(
    'name' => 'view field_how_to_apply_title',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_admission_requirements'.
  $permissions['view field_imp_admission_requirements'] = array(
    'name' => 'view field_imp_admission_requirements',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_career'.
  $permissions['view field_imp_career'] = array(
    'name' => 'view field_imp_career',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_delivery_mode'.
  $permissions['view field_imp_delivery_mode'] = array(
    'name' => 'view field_imp_delivery_mode',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_desc'.
  $permissions['view field_imp_desc'] = array(
    'name' => 'view field_imp_desc',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_inter_campus'.
  $permissions['view field_imp_inter_campus'] = array(
    'name' => 'view field_imp_inter_campus',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_intro'.
  $permissions['view field_imp_intro'] = array(
    'name' => 'view field_imp_intro',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_object'.
  $permissions['view field_imp_object'] = array(
    'name' => 'view field_imp_object',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_prereq_units'.
  $permissions['view field_imp_prereq_units'] = array(
    'name' => 'view field_imp_prereq_units',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_structure'.
  $permissions['view field_imp_structure'] = array(
    'name' => 'view field_imp_structure',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_int_sem_int'.
  $permissions['view field_int_sem_int'] = array(
    'name' => 'view field_int_sem_int',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inter_lang_requirements'.
  $permissions['view field_inter_lang_requirements'] = array(
    'name' => 'view field_inter_lang_requirements',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_international'.
  $permissions['view field_international'] = array(
    'name' => 'view field_international',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_international_body'.
  $permissions['view field_international_body'] = array(
    'name' => 'view field_international_body',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_international_fees'.
  $permissions['view field_international_fees'] = array(
    'name' => 'view field_international_fees',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_international_study'.
  $permissions['view field_international_study'] = array(
    'name' => 'view field_international_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_legacy_location'.
  $permissions['view field_legacy_location'] = array(
    'name' => 'view field_legacy_location',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_location_other'.
  $permissions['view field_location_other'] = array(
    'name' => 'view field_location_other',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_location_other_editable'.
  $permissions['view field_location_other_editable'] = array(
    'name' => 'view field_location_other_editable',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_location_tag'.
  $permissions['view field_location_tag'] = array(
    'name' => 'view field_location_tag',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_locations'.
  $permissions['view field_locations'] = array(
    'name' => 'view field_locations',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_materials_fee'.
  $permissions['view field_materials_fee'] = array(
    'name' => 'view field_materials_fee',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_more_button_link'.
  $permissions['view field_more_button_link'] = array(
    'name' => 'view field_more_button_link',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_multiple_audience_group'.
  $permissions['view field_multiple_audience_group'] = array(
    'name' => 'view field_multiple_audience_group',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_on_this_page'.
  $permissions['view field_on_this_page'] = array(
    'name' => 'view field_on_this_page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_page_lvl_1_thumbnail_image'.
  $permissions['view field_page_lvl_1_thumbnail_image'] = array(
    'name' => 'view field_page_lvl_1_thumbnail_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_page_subsite'.
  $permissions['view field_page_subsite'] = array(
    'name' => 'view field_page_subsite',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_postgrad_research'.
  $permissions['view field_postgrad_research'] = array(
    'name' => 'view field_postgrad_research',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_researcher_profile'.
  $permissions['view field_researcher_profile'] = array(
    'name' => 'view field_researcher_profile',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_results_user_access'.
  $permissions['view field_results_user_access'] = array(
    'name' => 'view field_results_user_access',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_se_atar_only'.
  $permissions['view field_se_atar_only'] = array(
    'name' => 'view field_se_atar_only',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_se_atar_plus'.
  $permissions['view field_se_atar_plus'] = array(
    'name' => 'view field_se_atar_plus',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_se_na'.
  $permissions['view field_se_na'] = array(
    'name' => 'view field_se_na',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_sidebar_content'.
  $permissions['view field_sidebar_content'] = array(
    'name' => 'view field_sidebar_content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_staff_id'.
  $permissions['view field_staff_id'] = array(
    'name' => 'view field_staff_id',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_study_mode'.
  $permissions['view field_study_mode'] = array(
    'name' => 'view field_study_mode',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_study_topic_area'.
  $permissions['view field_study_topic_area'] = array(
    'name' => 'view field_study_topic_area',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_sup_application_info'.
  $permissions['view field_sup_application_info'] = array(
    'name' => 'view field_sup_application_info',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_supplementary_career_info'.
  $permissions['view field_supplementary_career_info'] = array(
    'name' => 'view field_supplementary_career_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_supplementary_date_info'.
  $permissions['view field_supplementary_date_info'] = array(
    'name' => 'view field_supplementary_date_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_tags'.
  $permissions['view field_tags'] = array(
    'name' => 'view field_tags',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_title_area_feature_image'.
  $permissions['view field_title_area_feature_image'] = array(
    'name' => 'view field_title_area_feature_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_total_study'.
  $permissions['view field_total_study'] = array(
    'name' => 'view field_total_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_unit_code'.
  $permissions['view field_unit_code'] = array(
    'name' => 'view field_unit_code',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_unit_id'.
  $permissions['view field_unit_id'] = array(
    'name' => 'view field_unit_id',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_unit_lev'.
  $permissions['view field_unit_lev'] = array(
    'name' => 'view field_unit_lev',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_unit_ver'.
  $permissions['view field_unit_ver'] = array(
    'name' => 'view field_unit_ver',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ve_cohorts'.
  $permissions['view field_ve_cohorts'] = array(
    'name' => 'view field_ve_cohorts',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ve_study'.
  $permissions['view field_ve_study'] = array(
    'name' => 'view field_ve_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_webhook_url'.
  $permissions['view field_webhook_url'] = array(
    'name' => 'view field_webhook_url',
    'roles' => array(
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_work_life'.
  $permissions['view field_work_life'] = array(
    'name' => 'view field_work_life',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own field_additional_information'.
  $permissions['view own field_additional_information'] = array(
    'name' => 'view own field_additional_information',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_additional_requirements'.
  $permissions['view own field_additional_requirements'] = array(
    'name' => 'view own field_additional_requirements',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_admission_requirements_he'.
  $permissions['view own field_admission_requirements_he'] = array(
    'name' => 'view own field_admission_requirements_he',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_admission_requirements_se'.
  $permissions['view own field_admission_requirements_se'] = array(
    'name' => 'view own field_admission_requirements_se',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_admission_requirements_vet'.
  $permissions['view own field_admission_requirements_vet'] = array(
    'name' => 'view own field_admission_requirements_vet',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_admission_requirements_wl'.
  $permissions['view own field_admission_requirements_wl'] = array(
    'name' => 'view own field_admission_requirements_wl',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_atar_indicator'.
  $permissions['view own field_atar_indicator'] = array(
    'name' => 'view own field_atar_indicator',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_atar_minimum_entry'.
  $permissions['view own field_atar_minimum_entry'] = array(
    'name' => 'view own field_atar_minimum_entry',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_atar_profile_data'.
  $permissions['view own field_atar_profile_data'] = array(
    'name' => 'view own field_atar_profile_data',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_career'.
  $permissions['view own field_career'] = array(
    'name' => 'view own field_career',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_college'.
  $permissions['view own field_college'] = array(
    'name' => 'view own field_college',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_completion_rules'.
  $permissions['view own field_completion_rules'] = array(
    'name' => 'view own field_completion_rules',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_component_section_style'.
  $permissions['view own field_component_section_style'] = array(
    'name' => 'view own field_component_section_style',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_content_area'.
  $permissions['view own field_content_area'] = array(
    'name' => 'view own field_content_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_continuing_student'.
  $permissions['view own field_continuing_student'] = array(
    'name' => 'view own field_continuing_student',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_aqf'.
  $permissions['view own field_course_aqf'] = array(
    'name' => 'view own field_course_aqf',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_followed_by'.
  $permissions['view own field_course_followed_by'] = array(
    'name' => 'view own field_course_followed_by',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_midyear_intake'.
  $permissions['view own field_course_midyear_intake'] = array(
    'name' => 'view own field_course_midyear_intake',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_offered'.
  $permissions['view own field_course_offered'] = array(
    'name' => 'view own field_course_offered',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_preceded_by'.
  $permissions['view own field_course_preceded_by'] = array(
    'name' => 'view own field_course_preceded_by',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_sort_title'.
  $permissions['view own field_course_sort_title'] = array(
    'name' => 'view own field_course_sort_title',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_units'.
  $permissions['view own field_course_units'] = array(
    'name' => 'view own field_course_units',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_credit_points'.
  $permissions['view own field_credit_points'] = array(
    'name' => 'view own field_credit_points',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_cricos_code'.
  $permissions['view own field_cricos_code'] = array(
    'name' => 'view own field_cricos_code',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_cut_off_date'.
  $permissions['view own field_cut_off_date'] = array(
    'name' => 'view own field_cut_off_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_destination_page'.
  $permissions['view own field_destination_page'] = array(
    'name' => 'view own field_destination_page',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_domestic'.
  $permissions['view own field_domestic'] = array(
    'name' => 'view own field_domestic',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_duration'.
  $permissions['view own field_duration'] = array(
    'name' => 'view own field_duration',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_entry_requirements_in'.
  $permissions['view own field_entry_requirements_in'] = array(
    'name' => 'view own field_entry_requirements_in',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_entry_requirements_pg'.
  $permissions['view own field_entry_requirements_pg'] = array(
    'name' => 'view own field_entry_requirements_pg',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_entry_requirements_ve'.
  $permissions['view own field_entry_requirements_ve'] = array(
    'name' => 'view own field_entry_requirements_ve',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_excerpt'.
  $permissions['view own field_excerpt'] = array(
    'name' => 'view own field_excerpt',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_feature_duration'.
  $permissions['view own field_feature_duration'] = array(
    'name' => 'view own field_feature_duration',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_featured_success_story'.
  $permissions['view own field_featured_success_story'] = array(
    'name' => 'view own field_featured_success_story',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_first_off_date'.
  $permissions['view own field_first_off_date'] = array(
    'name' => 'view own field_first_off_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_free_tafe'.
  $permissions['view own field_free_tafe'] = array(
    'name' => 'view own field_free_tafe',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fym_body_text'.
  $permissions['view own field_fym_body_text'] = array(
    'name' => 'view own field_fym_body_text',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fym_logo'.
  $permissions['view own field_fym_logo'] = array(
    'name' => 'view own field_fym_logo',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_handbook_include'.
  $permissions['view own field_handbook_include'] = array(
    'name' => 'view own field_handbook_include',
    'roles' => array(
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_he_study'.
  $permissions['view own field_he_study'] = array(
    'name' => 'view own field_he_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_how_to_apply'.
  $permissions['view own field_how_to_apply'] = array(
    'name' => 'view own field_how_to_apply',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_how_to_apply_title'.
  $permissions['view own field_how_to_apply_title'] = array(
    'name' => 'view own field_how_to_apply_title',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_admission_requirements'.
  $permissions['view own field_imp_admission_requirements'] = array(
    'name' => 'view own field_imp_admission_requirements',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_career'.
  $permissions['view own field_imp_career'] = array(
    'name' => 'view own field_imp_career',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_delivery_mode'.
  $permissions['view own field_imp_delivery_mode'] = array(
    'name' => 'view own field_imp_delivery_mode',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_desc'.
  $permissions['view own field_imp_desc'] = array(
    'name' => 'view own field_imp_desc',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_inter_campus'.
  $permissions['view own field_imp_inter_campus'] = array(
    'name' => 'view own field_imp_inter_campus',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_intro'.
  $permissions['view own field_imp_intro'] = array(
    'name' => 'view own field_imp_intro',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_object'.
  $permissions['view own field_imp_object'] = array(
    'name' => 'view own field_imp_object',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_prereq_units'.
  $permissions['view own field_imp_prereq_units'] = array(
    'name' => 'view own field_imp_prereq_units',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_structure'.
  $permissions['view own field_imp_structure'] = array(
    'name' => 'view own field_imp_structure',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_int_sem_int'.
  $permissions['view own field_int_sem_int'] = array(
    'name' => 'view own field_int_sem_int',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inter_lang_requirements'.
  $permissions['view own field_inter_lang_requirements'] = array(
    'name' => 'view own field_inter_lang_requirements',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_international'.
  $permissions['view own field_international'] = array(
    'name' => 'view own field_international',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_international_body'.
  $permissions['view own field_international_body'] = array(
    'name' => 'view own field_international_body',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_international_fees'.
  $permissions['view own field_international_fees'] = array(
    'name' => 'view own field_international_fees',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_international_study'.
  $permissions['view own field_international_study'] = array(
    'name' => 'view own field_international_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_legacy_location'.
  $permissions['view own field_legacy_location'] = array(
    'name' => 'view own field_legacy_location',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_location_other'.
  $permissions['view own field_location_other'] = array(
    'name' => 'view own field_location_other',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_location_other_editable'.
  $permissions['view own field_location_other_editable'] = array(
    'name' => 'view own field_location_other_editable',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_location_tag'.
  $permissions['view own field_location_tag'] = array(
    'name' => 'view own field_location_tag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_locations'.
  $permissions['view own field_locations'] = array(
    'name' => 'view own field_locations',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_materials_fee'.
  $permissions['view own field_materials_fee'] = array(
    'name' => 'view own field_materials_fee',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_more_button_link'.
  $permissions['view own field_more_button_link'] = array(
    'name' => 'view own field_more_button_link',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_multiple_audience_group'.
  $permissions['view own field_multiple_audience_group'] = array(
    'name' => 'view own field_multiple_audience_group',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_on_this_page'.
  $permissions['view own field_on_this_page'] = array(
    'name' => 'view own field_on_this_page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_page_lvl_1_thumbnail_image'.
  $permissions['view own field_page_lvl_1_thumbnail_image'] = array(
    'name' => 'view own field_page_lvl_1_thumbnail_image',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_page_subsite'.
  $permissions['view own field_page_subsite'] = array(
    'name' => 'view own field_page_subsite',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_postgrad_research'.
  $permissions['view own field_postgrad_research'] = array(
    'name' => 'view own field_postgrad_research',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_researcher_profile'.
  $permissions['view own field_researcher_profile'] = array(
    'name' => 'view own field_researcher_profile',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_results_user_access'.
  $permissions['view own field_results_user_access'] = array(
    'name' => 'view own field_results_user_access',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_se_atar_only'.
  $permissions['view own field_se_atar_only'] = array(
    'name' => 'view own field_se_atar_only',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_se_atar_plus'.
  $permissions['view own field_se_atar_plus'] = array(
    'name' => 'view own field_se_atar_plus',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_se_na'.
  $permissions['view own field_se_na'] = array(
    'name' => 'view own field_se_na',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_sidebar_content'.
  $permissions['view own field_sidebar_content'] = array(
    'name' => 'view own field_sidebar_content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_staff_id'.
  $permissions['view own field_staff_id'] = array(
    'name' => 'view own field_staff_id',
    'roles' => array(
      'Admin' => 'Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_study_mode'.
  $permissions['view own field_study_mode'] = array(
    'name' => 'view own field_study_mode',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_study_topic_area'.
  $permissions['view own field_study_topic_area'] = array(
    'name' => 'view own field_study_topic_area',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_sup_application_info'.
  $permissions['view own field_sup_application_info'] = array(
    'name' => 'view own field_sup_application_info',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_supplementary_career_info'.
  $permissions['view own field_supplementary_career_info'] = array(
    'name' => 'view own field_supplementary_career_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_supplementary_date_info'.
  $permissions['view own field_supplementary_date_info'] = array(
    'name' => 'view own field_supplementary_date_info',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_tags'.
  $permissions['view own field_tags'] = array(
    'name' => 'view own field_tags',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_title_area_feature_image'.
  $permissions['view own field_title_area_feature_image'] = array(
    'name' => 'view own field_title_area_feature_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_total_study'.
  $permissions['view own field_total_study'] = array(
    'name' => 'view own field_total_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_unit_code'.
  $permissions['view own field_unit_code'] = array(
    'name' => 'view own field_unit_code',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_unit_id'.
  $permissions['view own field_unit_id'] = array(
    'name' => 'view own field_unit_id',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_unit_lev'.
  $permissions['view own field_unit_lev'] = array(
    'name' => 'view own field_unit_lev',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_unit_ver'.
  $permissions['view own field_unit_ver'] = array(
    'name' => 'view own field_unit_ver',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ve_cohorts'.
  $permissions['view own field_ve_cohorts'] = array(
    'name' => 'view own field_ve_cohorts',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ve_study'.
  $permissions['view own field_ve_study'] = array(
    'name' => 'view own field_ve_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_webhook_url'.
  $permissions['view own field_webhook_url'] = array(
    'name' => 'view own field_webhook_url',
    'roles' => array(
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_work_life'.
  $permissions['view own field_work_life'] = array(
    'name' => 'view own field_work_life',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher' => 'Researcher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Researcher' => 'Researcher',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Advanced Author' => 'Advanced Author',
      'Approver' => 'Approver',
      'Author' => 'Author',
      'Emergency Publisher' => 'Emergency Publisher',
      'Researcher' => 'Researcher',
      'Researcher Profile Admin' => 'Researcher Profile Admin',
      'Researcher Profile Approver' => 'Researcher Profile Approver',
      'Webform Author' => 'Webform Author',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
