<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Implements hook_theme().
 */
function vu_theme() {
  return [
    'in-this-section' => [
      'template' => 'templates/in-this-section',
      'variables' => [
        'items' => NULL,
      ],
    ],
    'global_search_pager' => [
      'template' => 'templates/google-appliance/global-search-pager',
      'variables' => [],
    ],
    'vu_google_appliance_empty_query_message' => [
      'template' => 'templates/google-appliance/empty-query-message',
    ],
    'global_footer' => [
      'template' => 'templates/footer',
      'variables' => [],
    ],
    'search_wrapper' => [
      'render element' => 'element',
    ],
    'main_menu_level2_item_section' => [
      'template' => 'templates/menu/menu--main-menu-level2-item-section',
      'variables' => [
        'title' => NULL,
        'summary' => NULL,
        'href' => NULL,
        'attributes' => [],
      ],
    ],
  ];
}

/**
 * Overrides theme_menu_link().
 */
function vu_menu_link__menu_block($variables) {
  // By default, Bootstrap theme converts all menu items that have children
  // into drop-downs. This implementation overrides this behaviour for all menus
  // rendered within menu blocks. Such menus could have their links rendered as
  // drop-downs by copying some of  the functionality from 'bootstrap_menu_link'
  // function. Note, that adding 'bootstrap_menu_link' to the '#theme' array of
  // the menu item will not work for menus starting at depth greater then 1 as
  // 'bootstrap_menu_link' has hardcoded filtering by depth.
  // @see bootstrap_menu_link()
  return theme_menu_link($variables);
}

/**
 * Implements template_preprocess_block().
 */
function vu_preprocess_block(&$variables) {
  // Output machine name as class name for blocks.
  $bid = $variables['elements']['#block']->delta;
  $machine_name = is_numeric($bid) ? fe_block_get_machine_name($bid) : $bid;
  $variables['classes_array'][] = drupal_html_class($machine_name);

  if ($variables['elements']['#block']->module == 'menu_block' && $variables['elements']['#block']->region == 'sidebar_first') {
    if (isset($variables['elements']['#delta']) && $variables['elements']['#delta'] == 'main-menu-our-campuses') {
      $variables['classes_array'][] = "campuses_sidebar_menu";
    }
  }

  // Hide Current Search Blocks title.
  if ('current_search' == $variables['block']->module) {
    $variables['elements']['#block']->subject = NULL;
  }
}

/**
 * Implements template_preprocess_page().
 */
function vu_preprocess_page(&$variables) {
  drupal_add_js(libraries_get_path('slick') . '/slick/slick.min.js', 'file');
  drupal_add_js(libraries_get_path('jquery.ellipsis') . '/jquery.ellipsis.min.js', 'file');
  drupal_add_js(libraries_get_path('jquery.hoverintent') . '/jquery.hoverIntent.js', 'file');

  // Embed svg logo.
  $variables['logo_svg'] = vu_embed_svg($variables['logo']);

  $page = $variables['page'];
  // Change page title based on this story.
  // https://salsadigital.attask-ondemand.com/task/view?ID=569da8bc004bbc9a6c83887321fb21ef.
  // Setup media release class variable.
  $variables['mr_class'] = '';
  // Setup media release & news type boolean.
  $variables['is_media_release'] = '';
  $variables['is_news'] = '';
  $variables['is_event'] = '';
  $page_titles = variable_get('vumain_page_titles', []);
  // Get the node.
  $node = !empty($variables['node']) ? $variables['node'] : NULL;
  // Get the language.
  $lang = !empty($node->language) ? $node->language : LANGUAGE_NONE;

  // Page is 404 page.
  $is_404 = drupal_get_http_header("status") === '404 Not Found';

  if ($is_404) {
    $variables['theme_hook_suggestions'][] = 'page__404';
    if (!empty($node)) {
      $variables['title'] = $node->title;
    }
    elseif (!isset($variables['title'])) {
      $variables['title'] = t('Page not found');
    }
  }
  elseif (!empty($node) && isset($page_titles[$node->type])) {
    // For news content type where tagged as media release.
    if ($node->type == 'news' &&
      isset($node->field_media_release[$lang][0]['value']) &&
      $node->field_media_release[$lang][0]['value'] == 1
    ) {
      $placeholders = ['@title' => $page_titles['media_release']['title']];
      $variables['title'] = l(t('@title', $placeholders), $page_titles['media_release']['url']);
    }
    else {
      $placeholders = ['@title' => $page_titles[$node->type]['title']];
      $variables['title'] = l(t('@title', $placeholders), $page_titles[$node->type]['url']);
    }
    $variables['non_blue_header_title'] = $node->title;

    // Hide non_blue_header_title for event nodes.
    if ($node->type == 'events') {
      $variables['is_event'] = TRUE;
      unset($variables['non_blue_header_title']);
    }
  }
  elseif (preg_match('|^/courses/international/.+$|', request_uri())) {
    $placeholders = ['@title' => $page_titles['intcourse']['title']];
    $variables['title'] = l(t('@title', $placeholders), $page_titles['intcourse']['url']);
  }
  else {
    // Get current page level.
    $menu = menu_get_active_trail();
    end($menu);
    $level = 0;

    if (count($menu) && isset($menu[key($menu)]['depth'])) {
      $level = $menu[key($menu)]['depth'];
    }

    $menu_title = NULL;
    if (isset($menu[1]['link_title']) && $menu[1]['link_title'] == 'VU Home') {
      $menu_title = $menu[2]['link_title'];
      $menu_path = $menu[2]['link_path'];
    }
    elseif (isset($menu[1]['link_title']) && isset($menu[1]['link_path'])) {
      $menu_title = $menu[1]['link_title'];
      $menu_path = $menu[1]['link_path'];
    }

    if (isset($node->type) && $node->type != 'topic_pages' && $level > 1) {
      if (isset($variables['title'])) {
        $variables['non_blue_header_title'] = $variables['title'];
      }
      elseif (isset($node->title)) {
        $variables['non_blue_header_title'] = $node->title;
      }

      if ($menu_title) {
        $variables['title'] = l($menu_title, $menu_path);
      }
    }
    elseif (isset($variables['title'])) {
      $variables['non_blue_header_title'] = $variables['title'];
      $variables['title'] = _vu_neon_short_title($variables['title']);
    }
    elseif ($level > 1 && empty($node->type)) {
      // For all level 2+ where the page isn't node.
      $variables['non_blue_header_title'] = drupal_get_title();
      if ($menu_title) {
        $variables['title'] = l($menu_title, $menu_path);
      }
    }
    elseif (arg(0) == 'file') {
      $files = entity_load('file', [arg(1)]);
      if ($files[arg(1)]->type == 'video') {
        $variables['title'] = _vu_file_entity_video_transcript_title($files[arg(1)]->filename);
      }
    }
  }

  // Hide sidebar when on level 1.
  $menu_item = array_reverse(menu_get_active_trail());
  $menu_depth = isset($menu_item[0]['depth']) ? $menu_item[0]['depth'] : 0;
  $menu_level = !empty($menu_depth) ? $menu_depth : 0;

  if ($menu_level == 1) {
    $variables['page']['sidebar_first'] = '';
  }

  // Set heading tag for the section header (the blue header), the rules are:
  // - H1 for topic pages or pages at menu level 1 or pages without a parent;
  // - H2 for all other pages, the page title in the main content will be H1;
  // - H2 for node types that don't belong to a menu (e.g. news and units).
  $variables['heading_tag'] = 'h1';
  if ((isset($node->type) && $node->type != 'topic_pages') && $menu_level >= 2 && !$is_404) {
    $variables['heading_tag'] = 'h2';
  }
  elseif (isset($node->type) && isset($page_titles[$node->type])) {
    $variables['heading_tag'] = 'h2';
  }
  elseif (empty($node->type) && $menu_level > 1) {
    $variables['heading_tag'] = 'h2';
  }

  // For staff profile node, add honorific if exist.
  if (isset($node) && $node->type == 'staff_profile') {
    $title = '';
    if (isset($node->field_staff_name_title[$lang][0]['value'])) {
      $title = $node->field_staff_name_title[$lang][0]['value'] . ' ';
    }
    $title = $title . $node->title;
    $variables['title'] = t('Contact us');
    $variables['heading_tag'] = 'h2';
    drupal_set_title($title);
  }

  // Setup ?kiosk display.
  $kiosk_mode_enabled = FALSE;

  // Check kiosk mode is set in URL.
  $params = drupal_get_query_parameters();
  if (array_key_exists('kiosk', $params)) {
    $kiosk_mode_enabled = TRUE;
  }

  // Check webform kiosk mode is set.
  if (isset($node) && $node->type == 'webform') {
    if ($node->field_kiosk_mode[$node->language][0]['value'] == 1) {
      $kiosk_mode_enabled = TRUE;
    }
  }

  // Enable kiosk mode.
  if ($kiosk_mode_enabled) {
    // Set variable.
    $variables['kiosk'] = TRUE;
    $variables['front_page'] .= '?kiosk';
    // Hide menus.
    $variables['page']['navigation'] = '';
    $variables['page']['header_menu'] = '';
    $variables['page']['header'] = '';
    $variables['page']['footer'] = '';
    $variables['page']['sidebar_first'] = '';

    // Hide carousel.
    if (!$variables['is_front']) {
      $variables['page']['featured_content'] = '';
    }
  }
  else {
    $variables['kiosk'] = FALSE;
  }

  // Override sidebar first for news items.
  if (!empty($node) && $node->type == 'news') {
    if ((isset($node->field_media_release[$lang][0]['value'])) && ($node->field_media_release[$lang][0]['value'] == 0)) {
      $variables['page']['sidebar_first'] = '';
      $variables['is_news'] = 1;
    }
    if ((isset($node->field_media_release[$lang][0]['value'])) && ($node->field_media_release[$lang][0]['value'] == 1)) {
      $variables['mr_class'] = 'media-release-class';
      $variables['is_media_release'] = 1;
    }
  }
  // Override sidebar first for courses/events.
  if (isset($node) && ($node->type == 'courses' || $node->type == 'events')) {
    $variables['page']['sidebar_first'] = '';
  }

  // Show new unit search button on unit/unitsets.
  $variables['show_unit_search_button'] = FALSE;
  if (isset($node) && ($node->type == 'unit' || $node->type == 'unit_set')) {
    $variables['show_unit_search_button'] = TRUE;
  }

  // Get the subsites value.
  $subsites = !empty($variables['subsites']) ? $variables['subsites'] : NULL;

  // Set default values.
  $subsite_sidebar_second = 0;
  $subsite_abovetiles_class = $sidebar_second_class = $vicpoly_class = NULL;
  $is_vicpoly_course = $is_vicpoly_unit = FALSE;
  $is_vicpoly_course_content_type = $is_vicpoly_unit_content_type = FALSE;

  $has_subsite_rhs_content = !empty($subsites) && !empty($subsites['right_blocks']) ? TRUE : FALSE;
  if (($has_subsite_rhs_content || $menu_depth == 1) && !empty($page['subsite_landing_rhs'])) {
    $subsite_sidebar_second = 1;
    $sidebar_second_class = ' with-sidebar-second';
  }

  if (!empty($subsites) && !empty($subsites['above_tiles_block']) && !empty($page['subsite_landing_above_tiles'])) {
    $subsite_abovetiles_class = ' with-aboveblock';
  }

  // Is this node a TAFE / Victoria Polytechnic?
  $is_course = (!empty($node) && $node->type == 'courses');
  $is_unit = (!empty($node) && $node->type == 'unit');
  $is_vicpoly = FALSE;
  $is_tafe_search_page = FALSE;
  $is_tafe_course = FALSE;

  $variables['header_new_course_search_button'] = FALSE;
  $header_new_course_search_button_params = ['query' => ['iam' => 'resident']];
  if (vu_courses_is_international_course_url($node)) {
    $header_new_course_search_button_params = ['query' => ['iam' => 'non-resident']];
  }
  if ($is_course || $is_unit) {
    // Is polytechnic?
    if (!empty($node->field_college)) {
      $field_college = $node->field_college[$lang][0]['title'];
      $is_vicpoly = in_array($field_college, ['VU Polytechnic', 'Victoria Polytechnic']);
    }

    // Is tafe?
    if (!empty($node->field_unit_lev)) {
      $is_tafe_course = ($node->field_unit_lev[$lang][0]['value'] == 'tafe');
    }

    // Set up only course.
    if ($is_course) {
      if ($is_tafe_course) {
        $placeholders = ['@title' => 'TAFE courses'];
      }
      if ($is_vicpoly) {
        // Change header to vicpoly design.
        $is_vicpoly_course = TRUE;
        $is_vicpoly_course_content_type = TRUE;
      }
      else {
        $variables['header_new_course_search_button'] = l(t('New course search'), 'courses/search', $header_new_course_search_button_params);
      }

      // Hide featured slider.
      $variables['page']['featured_content'] = '';
    }
    // Set up only unit.
    elseif ($is_unit) {
      if ($is_tafe_course) {
        $placeholders = ['@title' => 'TAFE units'];
      }
      if ($is_vicpoly) {
        // Change header to vicpoly design.
        $is_vicpoly_unit = TRUE;
        $is_vicpoly_unit_content_type = TRUE;
        $variables['show_unit_search_button'] = FALSE;
      }
    }

    // Setup for both course and unit.
    if ($is_vicpoly) {
      // Hide featured slider.
      $variables['page']['featured_content'] = '';
      $variables['vicpoly_search_filter'] = 'f[0]=field_college%253Atitle%3AVU%20Polytechnic';
    }
  }
  // If the 'vuit' query parameter is present.
  elseif (isset($_GET['vuit'])) {
    $is_vicpoly_course = TRUE;
  }

  // Setup for both course and unit.
  if ($is_vicpoly || $is_vicpoly_course) {
    // Set vicpoly class (will change the look of the header).
    $vicpoly_class = ' title-block--vicpoly';
  }

  // Add the button by default on international courses.
  if (vu_courses_is_international_course_url()) {
    $variables['header_new_course_search_button'] = l(t('New course search'), 'courses/search', $header_new_course_search_button_params);
  }

  // If the page is search page.
  if (arg(0) == 'search') {
    $variables['breadcrumb'] = '';
    $variables['site_search_form'] = drupal_get_form('google_appliance_search_form');
  }
  // Add the variables to the template.
  $variables['subsite_sidebar_second'] = $subsite_sidebar_second;
  $variables['subsite_abovetiles_class'] = $subsite_abovetiles_class;
  $variables['sidebar_second_class'] = $sidebar_second_class;
  $variables['vicpoly_class'] = $vicpoly_class;
  $variables['is_vicpoly_course'] = $is_vicpoly_course;
  $variables['is_vicpoly_course_content_type'] = $is_vicpoly_course_content_type;
  $variables['is_vicpoly_unit'] = $is_vicpoly_unit;
  $variables['is_vicpoly_unit_content_type'] = $is_vicpoly_unit_content_type;
  $variables['has_left_sidebar'] = !empty($variables['page']['sidebar_first']);

  // Enable social media links on blue header.
  $variables['share_links'] = FALSE;
  if (!empty($node) && ($node->type == 'events' || $node->type == 'news')) {
    $variables['share_links'] = theme('vumain_share_links', ['node' => $node]);
  }

  // Append campus to the title of campus pages.
  $current_path = drupal_get_path_alias();
  if (!empty($node) && $node->type == 'campus') {
    $campus_id = vumain_googlemaps_get_campus_id($current_path);
    if ($campus_id != VU_CAMPUSES_METROWEST_ALIAS) {
      $variables['non_blue_header_title'] = !empty($variables['non_blue_header_title']) ? $variables['non_blue_header_title'] : '';
      $variables['non_blue_header_title'] .= ' campus';
    }
    drupal_set_title($variables['non_blue_header_title']);
  }

  // Display header course search form on study topic pages.
  $variables['header_course_search_form_block_class'] = '';
  $is_course_search_page = (empty($node) && _vu_is_course_search_page());
  $is_topic_area_page = (!empty($node) && _vu_is_topic_area_page($node->type, $current_path));
  if ($is_course_search_page || $is_topic_area_page) {
    $header_course_search_form_block = module_invoke('vumain', 'block_view', 'vu_course_search_search_minimal');
    if (!empty($header_course_search_form_block['content'])) {
      $variables['header_course_search_form_block_class'] = 'course-search-form-header-wrapper';
      $variables['header_course_search_form_block'] = render($header_course_search_form_block['content']);
      if (!empty($params['query'])) {
        $course_query = filter_xss_admin($params['query']);
        $search_all_vu = t('Search for <em>!query</em> anywhere in the Victoria University website.', ['!query' => $course_query]);
        $variables['header_course_search_form_block'] .= '<div class="coursefinder-site-search-link">' . l($search_all_vu, 'search/vu/' . $course_query, ['html' => TRUE]) . '</div>';
      }
    }

    if ($is_course_search_page) {
      // We don't need to display breadcrumb in course search results page.
      $variables['breadcrumb'] = '';
      $variables['facets_region_header'] = t('Refine your search');

      // Set search page title when query parameter vuit is set.
      if (!empty($params['vuit']) && $params['vuit'] == 1) {
        $search_title = !empty($params['type']) && drupal_strtolower($params['type']) == 'unit' ? t('TAFE units') : t('TAFE courses');
        $placeholders = ['@title' => $search_title];
        $is_tafe_search_page = TRUE;
      }
    }
  }

  if ($is_tafe_course || $is_tafe_search_page) {
    // Set heading.
    $search_type = !empty($params['type']) ? $params['type'] : 'Course';
    $query = [
      'vuit' => 1,
      urldecode('f[0]') => urldecode('field_college%253Atitle%3AVU%20Polytechnic'),
      'type' => $search_type,
    ];
    $url = '/courses/search';
    $variables['title'] = l(t('@title', $placeholders), $url, ['query' => $query]);
  }

  // Append content title on study page.
  if (!empty($node) && ($node->type == 'study_topic_area')) {
    $variables['non_blue_header_title'] .= ' ' . t('courses');

    // Hide featured slider.
    $variables['page']['featured_content'] = '';
  }

  // Hide featured slider on campus housing page.
  if (!empty($node) && ($node->type == 'campus_housing')) {
    $variables['page']['featured_content'] = '';
  }

  // Hide non_blue_header_title on courses page.
  if (!empty($node) && ($node->type == 'courses')) {
    $variables['non_blue_header_title'] = '';
  }

  // Process top content on topic page content type.
  if (!empty($node) && ($node->type == 'topic_pages')) {
    if (!empty($node->field_top_content)) {
      $top_content_field = field_get_items('node', $node, 'field_top_content');

      // Hide featured content, and replace with top content from topic page.
      $top_content_blocks = theme('topics_content_blocks', [
        'entities' => $top_content_field,
        'top_content' => TRUE,
      ]);

      $variables['page']['featured_content'] = [
        '#theme_wrappers' => ['region'],
        '#region' => 'featured_content',
        'top_content_blocks' => [
          '#markup' => $top_content_blocks,
        ],
      ];
    }
  }
}

/**
 * Implements template_preprocess_node().
 */
function vu_preprocess_node(&$variables) {
  $node = $variables['node'];
  $is_page = $variables['page'];

  // Get blocks in inner content and inner content top regions.
  // Blocks can be assigned using Context or the default block system.
  $inner_content_top = [];
  $inner_content_bottom = [];

  // Get context assigned blocks.
  if ($plugin = context_get_plugin('reaction', 'block')) {
    $inner_content_top[] = $plugin->block_get_blocks_by_region('inner_content_top');
    $inner_content_bottom[] = $plugin->block_get_blocks_by_region('inner_content');
    // Invoking Context reactions too early is resulting in statically cached
    // results before all contexts are ready to fire. As such, we need to flush
    // said cache.
    drupal_static_reset('context_reaction_block_list');
  }

  $inner_content_top[] = block_get_blocks_by_region('inner_content_top');
  $inner_content_bottom[] = block_get_blocks_by_region('inner_content');

  $variables['inner_content_top'] = $inner_content_top;
  $variables['inner_content_bottom'] = $inner_content_bottom;

  if (!empty($variables['field_location'][0]['entity']->language) && $node->type == 'campus') {
    $variables['site_map_url'] = '';
    // Get the language.
    $lang = $variables['field_location'][0]['entity']->language;
    // Check if we have a site map in campus node type.
    if (!empty($variables['field_location'][0]['entity']->field_site_map[$lang][0]['uri'])) {
      $site_map_uri = $variables['field_location'][0]['entity']->field_site_map[$lang][0]['uri'];
      $variables['site_map_url'] = file_create_url($site_map_uri);
    }
  }

  switch ($node->type) {
    case 'study_topic_area':
      if ($variables['view_mode'] == 'teaser') {
        $variables['theme_hook_suggestions'][] = 'node__study_topic_area__teaser';
      }
      $variables['jump_menu'] = module_invoke('vumain', 'block_view', 'vu_study_topics_form');

      $content_course_search_form_block = module_invoke('vumain', 'block_view', 'vu_course_search_search_std_desc');
      if (!empty($content_course_search_form_block['content'])) {
        $variables['content_course_search_form_block'] = $content_course_search_form_block['content'];
      }
      break;

    case 'news':
      // Set the default values.
      $media_release = FALSE;
      $col_class = 'news__col news__col--left col-sm-8';
      $row_class = 'row';

      // If this is a media release.
      if (isset($variables['content']['field_media_release']) && $variables['content']['field_media_release']['#items'][0]['value'] == 1) {
        $media_release = TRUE;
        $col_class = '';
        $row_class = '';
      }

      // Add the date format.
      $mr_formats = [
        'label' => 'hidden',
        'settings' => ['format_type' => 'vumain_mr_date'],
      ];
      // Get the date.
      $mr_date = field_view_field('node', $node, 'field_article_date', $mr_formats);

      // Add the variables to the template.
      $variables['media_release'] = $media_release;
      $variables['col_class'] = $col_class;
      $variables['row_class'] = $row_class;
      $variables['mr_date'] = $mr_date;

      $variables['share_links'] = '';
      if (!$media_release) {
        $variables['share_links'] = theme('vumain_share_links', ['node' => $node]);
      }
      break;

    case 'events':
      $variables['share_links'] = theme('vumain_share_links', ['node' => $node]);
      $variables['past_event'] = '';
      $lang = empty($node->language) ? LANGUAGE_NONE : $node->language;
      $dates = $node->field_date[$lang];
      if (!vu_helpers_is_today_or_future_dates($dates)) {
        $variables['past_event'] = [
          '#type' => 'html_tag',
          '#tag' => 'p',
          '#attributes' => [
            'class' => ['past'],
          ],
          '#value' => t('This event has already taken place.'),
        ];
      }

      // Setup the 2nd date format display.
      $display = [
        'label' => 'hidden',
        'settings' => ['format_type' => 'vumain_event_detail_col2'],
      ];
      $field_date = field_view_field('node', $node, 'field_date', $display);
      $variables['dates_col2'] = vumain_get_date_field_all_day($field_date);
      $variables['campus_address'] = '';
      $variables['legacy_location'] = '';
      $variables['show_location_area'] = 0;
      // $is_page is used to fix a weird issue in which a field from
      // 'related links' nodes is loaded instead of the current node.
      if (!empty($is_page)) {
        $field_campus = field_get_items('node', $node, 'field_event_campus');
        $field_legacy_location = field_get_items('node', $node, 'field_legacy_location');
        $google_maps_api_key = variable_get('google_maps_api_key', '');
        $google_maps_api = sprintf('//maps.googleapis.com/maps/api/js?key=%s&v=3.exp', $google_maps_api_key);
        drupal_add_js($google_maps_api, 'external');
        if (!empty($field_campus[0]['value']) && ($field_campus[0]['value'] != 'off-campus')) {
          $field_campus_key = $field_campus[0]['value'];
          $field_campus_value = $variables['content']['field_event_campus'][0]['#markup'];
          $variables['field_campus_value'] = $field_campus_value;
          $campus_address = vumain_journey_planner_get_address($field_campus_key, TRUE);
          $variables['campus_address'] = $campus_address;

          $city_queen = 'city-queen';
          if (strpos($field_campus_key, $city_queen) > -1) {
            $field_campus_key = $city_queen;
          }
          $campus_alias = 'campuses-services/our-campuses/' . $field_campus_key;
          $campus_alias_exists = drupal_lookup_path('source', $campus_alias);
          if (!$campus_alias_exists) {
            $campus_alias = '';
          }
          $variables['campus_alias'] = $campus_alias;
          // Build the google map.
          $latlong[0] = vumain_campuses_get_lat_long($field_campus_key);
          $campus_zoom = vumain_campuses_zoom($field_campus_key);
          $variables['show_location_area'] = 1;
          drupal_add_js([
            'event_campus' => [
              'title' => $field_campus_value,
              'lat_long' => $latlong,
              'zoom' => $campus_zoom,
            ],
          ], 'setting');
        }
        if ($field_campus[0]['value'] == 'off-campus' && !empty($field_legacy_location[0]['value'])) {
          $legacy_location = $field_legacy_location[0]['value'];
          $variables['legacy_location'] = l($legacy_location, 'https://www.google.com/maps',
            [
              'query' => [
                'q' => $legacy_location,
              ],
            ]
          );

          drupal_add_js([
            'event_campus' => [
              'address' => check_plain($legacy_location),
              'zoom' => VU_MAP_ZOOM_DEFAULT,
            ],
          ], 'setting');

          $variables['show_location_area'] = 1;
        }
      }

      break;

    case 'campus':
      // Setup variables to be printed.
      $gmap_block = module_invoke('vumain', 'block_view', 'vumain_location_maps_block');
      $variables['gmap_block'] = FALSE;
      if (!empty($gmap_block['content'])) {
        $variables['gmap_block'] = $gmap_block['content'];
      }

      $block_journey_planner = module_invoke('vumain', 'block_view', 'vumain_journey_planner_block');
      $variables['block_journey_planner'] = FALSE;
      if (isset($block_journey_planner['content'])) {
        $variables['block_journey_planner'] = $block_journey_planner['content'];
      }

      $variables['map_title'] = 'Campus Map';
      $campus_id = vumain_googlemaps_get_campus_id($variables['node_url']);
      if ($campus_id == VU_CAMPUSES_METROWEST_ALIAS) {
        $variables['map_title'] = 'Local Map';
      }
      break;

    case 'courses':
      // Process which description need to be shown as related link.
      if ($variables['view_mode'] == 'related_content_on_event_detail') {
        if (!empty($variables['content']['body'])) {
          // Hide imported and editable description and when body is not empty.
          $variables['content']['field_imp_desc']['#access'] = FALSE;
          $variables['content']['field_description_editable']['#access'] = FALSE;
        }
        elseif (empty($variables['content']['body']) && !empty($variables['content']['field_description_editable'])) {
          // Hide imported and editable description and when body is empty.
          $variables['content']['field_imp_desc']['#access'] = FALSE;
        }
        else {
          // Imported description must render its html tag and trim.
          $convert_to_html = check_markup($variables['content']['field_imp_desc']['#items'][0]['value'], 'full_html');
          $variables['content']['field_imp_desc'][0]['#markup'] = views_trim_text([
            'max_length' => 300,
            'html' => TRUE,
          ], $convert_to_html);
        }
      }
      break;

    case 'topic_pages':
      // Display header course search form on topic pages.
      $study_topics = vumain_cources_get_all_study_topics();
      $args = implode(',', array_flip($study_topics));
      $header_course_browser = views_embed_view('courses_lists', 'landing_course_browser_block', $args);
      $variables['header_course_browser'] = $header_course_browser;
      $variables['course_search_key'] = '';
      $course_search_option = field_get_items('node', $node, 'field_header_course_search_inc');
      $course_search_key = $course_search_option[0]['value'];
      $course_search_index = FALSE;
      if (!empty($course_search_key)) {
        if ($course_search_key == 'future') {
          $course_search_index = 'find_std_desc';
          $variables['header_course_browser'] = $header_course_browser;
        }
        else {
          $course_search_index = 'find_minimal';
        }
        $variables['course_search_key'] = $course_search_key;
      }

      $header_course_search_block = module_invoke('vumain', 'block_view', 'vu_course_search_' . $course_search_index);
      if (!empty($header_course_search_block['content'])) {
        $variables['header_course_search_block'] = $header_course_search_block['content'];
        $variables['header_course_search_block_class'] = 'header-search-' . $course_search_index . ' landing-course-info';
      }

      // Prepare body field.
      $variables['body_content'] = FALSE;
      if (!empty($variables['body'])) {
        // The summary/teaser will be used for left content on its block.
        $body['teaser'] = field_view_field('node', $node, 'body', 'teaser');
        $body['body'] = $variables['body'][0]['safe_value'];
        $variables['body_content'] = $body;
      }

      // If there is a teaser but no body, don't display it.
      if (!empty($variables['body'][0]['summary']) && empty($variables['body'][0]['value'])) {
        $variables['body'] = [];
        $variables['body_content'] = [];
      }

      // Leaders in sport is a special page.
      if (vu_core_is_leaders_in_sports_page()) {
        $variables['leaders_in_sport'] = TRUE;
        $variables['classes_array'][] = 'leaders-in-sport';
      }

      break;

    case 'page_builder':
      $alias = drupal_get_path_alias();
      if ($alias === 'courses') {
        $course_finder_form = drupal_get_form('vumain_courses_course_finder_form', 'find_extended');
        $variables['course_finder_form'] = drupal_render($course_finder_form);
      }
      elseif ($alias === 'library') {
        // Library Search Form.
        $block_search_form = module_invoke('vu_core', 'block_view', 'vu_core_library_search_form');
        $variables['library_search_form'] = render($block_search_form);

        // Find Library Block.
        $variables['library_find_library_block'] = theme('vu_library_shortcut_links');

        // I Want To Block.
        $variables['library_i_want_to_block'] = theme('vu_library_i_want_links');
      }
      elseif ($alias === 'courses/browse-for-courses/all-courses-by-topic') {
        $content_course_search_form_block = module_invoke('vumain', 'block_view', 'vu_course_search_search_std_desc');
        if (!empty($content_course_search_form_block['content'])) {
          $variables['content_course_search_form_block'] = $content_course_search_form_block['content'];
        }
      }

      break;

  }

  if ($variables['view_mode'] == 'related_content_on_event_detail') {
    $sidebar_teaser = '';
    $ellipsis = '';
    $content = $variables['content'];
    if (!empty($content['body'])) {
      $sidebar_teaser = render($content['body']);
    }
    elseif (!empty($content['field_introduction'])) {
      $sidebar_teaser = $content['field_introduction'];
    }
    elseif (!empty($content['field_page_introduction'])) {
      $sidebar_teaser = $content['field_page_introduction'];
    }
    elseif (!empty($content['field_excerpt'])) {
      $sidebar_teaser = $content['field_excerpt'];
    }
    $sidebar_teaser = strip_tags($sidebar_teaser);
    $check_summary = $content['body']['#items'][0]['safe_summary'];
    if (!$check_summary) {
      if (strlen($sidebar_teaser) > 200) {
        $ellipsis = '...';
        $sidebar_teaser = substr($sidebar_teaser, 0, 200);
      }
    }
    $variables['sidebar_related_content'] = $sidebar_teaser . $ellipsis;
    $variables['theme_hook_suggestions'][] = 'node__related_content_on_event_detail';
  }
}

/**
 * Implements template_preprocess_views_view_unformatted().
 */
function vu_preprocess_views_view_unformatted(&$variables) {
  // Get the view.
  $view = $variables['view'];

  if ($view->name == 'courses_study_level') {
    switch ($view->current_display) {
      case 'csl_dom_b':
      case 'csl_int_b':
        // Create variable level to store original title.
        $variables['level'] = $variables['title'];

        // Create a new title.
        $args = [
          '!title' => $variables['title'],
          '!count' => ' <span>' . format_plural(count($variables['rows']), '1 course', '@count courses') . '</span>',
        ];
        $title = t('!title!count', $args);
        // Update the title.
        $variables['title'] = $title;
        break;
    }
  }
}

/**
 * Implements template_preprocess_entity().
 *
 * Runs a entity specific preprocess function, if it exists.
 */
function vu_preprocess_entity(&$variables, $hook) {
  $function = __FUNCTION__ . '_' . $variables['entity_type'];
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Bean specific implementation of template_preprocess_entity().
 */
function vu_preprocess_entity_bean(&$variables, $hook) {
  // Get the bean.
  $bean = $variables['bean'];

  switch ($bean->type) {
    case 'feature_tile':
      // Set the default values.
      $link_path = '';
      $img_class = '';

      // Get the content.
      $content = $variables['content'];
      // If there is a featured tile link.
      if (isset($content['field_featured_tile_link']['#items'][0]['target_id'])) {
        $link_id = $content['field_featured_tile_link']['#items'][0]['target_id'];
        $link_path = drupal_get_path_alias('node/' . $link_id);
      }

      if (isset($content['field_featured_tile_image'])) {
        $img_class = "with-image";
      }

      // Add the variables to the template.
      $variables['link_path'] = $link_path;
      $variables['img_class'] = $img_class;
      break;
  }
}

/**
 * Legacy code.
 *
 * Some titles are too long to display in the title block so we abbreviate them.
 *
 * @param string $title
 *   The title to abbreviate.
 *
 * @return string
 *   $title if it's ok or an abbreviation if there is one.
 */
function _vu_neon_short_title($title) {
  $title = trim($title);
  $short_titles = [
    'South Pacific User Services Conference (SPUSC) 2011' => 'South Pacific User Services Conference 2011',
    'Centre for Environmental Safety and Risk Engineering (CESARE)' => 'Centre for Environmental Safety and Risk Engineering',
    'Institute of Sport, Exercise and Active Living (ISEAL)' => 'Institute of Sport, Exercise and Active&nbsp;Living',
    'Work-based Education Research Centre (WERC)' => 'Work-based Education Research Centre',
    'Institute for Sustainability and Innovation (ISI)' => 'Institute for Sustainability and Innovation',
    'Institute for Supply Chain and Logistics (ISCL)' => 'Institute for Supply Chain and Logistics',
  ];

  return isset($short_titles[$title]) ? $short_titles[$title] : $title;
}

/**
 * Check if current page builder has inline entity called related link.
 */
function _vu_check_page_builder_has_related_link_entity($variables) {
  // Get the language.
  if (!empty($variables['node']->language)) {
    $lang = $variables['node']->language;
    if (isset($variables['node']->field_page_sections[$lang])) {
      foreach ($variables['node']->field_page_sections as $page_sections) {
        foreach ($page_sections as $pg) {
          if (isset($pg['entity']->type) && $pg['entity']->type == 'related_links') {
            return TRUE;
          }
        }
      }
    }
  }

  return FALSE;
}

/**
 * Implements hook_preprocess_html().
 */
function vu_preprocess_html(&$variables) {
  // Add 'no-js' class to <body> to target styles.
  $variables['classes_array'][] = 'no-js';
  // Add jquery.bbq library to support back-button for accordions.
  drupal_add_library('system', 'jquery.bbq');
  // Add the Page's Parent Menu Item as body class.
  $parent_menu_title = menu_get_active_trail();
  if (isset($parent_menu_title[1]['link_title'])) {
    $parent_menu_title = drupal_html_class($parent_menu_title[1]['link_title']);
    $variables['classes_array'][] = $parent_menu_title;
  }
}

/**
 * Implements theme_link_formatter_link_default().
 */
function vu_link_formatter_link_default($variables) {
  $link_options = $variables['element'];
  unset($link_options['title']);
  unset($link_options['url']);

  if (isset($link_options['attributes']['class'])) {
    $link_options['attributes']['class'] = [$link_options['attributes']['class']];
  }

  // Display a normal link if both title and URL are available.
  // Or field_on_this_page.
  if ((!empty($variables['element']['title']) && !empty($variables['element']['url'])) || $variables['field']['field_name'] == 'field_on_this_page') {
    return l($variables['element']['title'], $variables['element']['url'], $link_options);
  }
  // If only a title, display the title.
  elseif (!empty($variables['element']['title'])) {
    return $link_options['html'] ? $variables['element']['title'] : check_plain($variables['element']['title']);
  }
  elseif (!empty($variables['element']['url'])) {
    return l($variables['element']['title'], $variables['element']['url'], $link_options);
  }
}

/**
 * Implements theme_pager().
 */
function vu_pager($variables) {
  global $pager_page_array, $pager_total;

  $limit = !empty($variables['limit']) ? $variables['limit'] : 10;
  $element = !empty($variables['element']) ? $variables['element'] : 0;
  $parameters = !empty($variables['parameters']) ? $variables['parameters'] : [];
  $quantity = !empty($variables['quantity']) ? $variables['quantity'] : 9;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];
  // End of marker calculations.
  // Prepare for generation loop.
  $i = $pager_first;

  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }

  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.
  $li_previous = theme('pager_previous', [
    'text' => t('← Previous'),
    'limit' => $limit,
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ]);
  $li_next = theme('pager_next', [
    'text' => t('Next →'),
    'limit' => $limit,
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ]);

  if ($pager_total[$element] > 1) {

    if ($li_previous) {
      $items[] = [
        'class' => 'pager-previous' . (1 == $pager_current ? ' disabled' : ''),
        'data' => $li_previous,
      ];
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = [
            'class' => 'pager-item',
            'data' => theme('pager_previous', [
              'text' => $i,
              'limit' => $limit,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            ]),
          ];
        }
        if ($i == $pager_current) {
          $items[] = [
            'class' => 'pager-current active',
            'data' => "<a href='#'>$i</a>",
          ];
        }
        if ($i > $pager_current) {
          $items[] = [
            'class' => 'pager-item',
            'data' => theme('pager_next', [
              'text' => $i,
              'limit' => $limit,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            ]),
          ];
        }
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = [
        'class' => 'pager-next' . ($pager_max == $pager_current ? ' disabled' : ''),
        'data' => $li_next,
      ];
    }

    return theme('item_list', [
      'items' => $items,
      'title' => NULL,
      'type' => 'ul',
      'attributes' => ['class' => 'pagination'],
    ]);
  }
}

/**
 * Pager previous themer.
 */
function vu_pager_previous($variables) {
  global $pager_page_array;
  $text = !empty($variables['text']) ? $variables['text'] : '';
  $interval = !empty($variables['interval']) ? $variables['interval'] : 1;
  $element = !empty($variables['element']) ? $variables['element'] : 0;
  $parameters = !empty($variables['parameters']) ? $variables['parameters'] : [];

  $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);
  $output = theme('pager_link', [
    'text' => $text,
    'page_new' => $page_new,
    'element' => $element,
    'parameters' => $parameters,
  ]);

  return $output;
}

/**
 * Pager next themer.
 */
function vu_pager_next($variables) {
  global $pager_page_array;
  $text = !empty($variables['text']) ? $variables['text'] : '';
  $interval = !empty($variables['interval']) ? $variables['interval'] : 1;
  $element = !empty($variables['element']) ? $variables['element'] : 0;
  $parameters = !empty($variables['parameters']) ? $variables['parameters'] : [];

  $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
  $output = theme('pager_link', [
    'text' => $text,
    'page_new' => $page_new,
    'element' => $element,
    'parameters' => $parameters,
  ]);

  return $output;
}

/**
 * Pager link themer.
 */
function vu_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  $page = isset($_GET['page']) ? $_GET['page'] : '';

  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  // If no query has been submitted, leave it out from URL.
  if (empty($parameters['query'])) {
    unset($parameters['query']);
  }

  $query = [];
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters);
  }

  $pager_query_string = pager_get_query_parameters();

  if ($pager_query_string != '') {
    $query = array_merge($query, $pager_query_string);
  }

  $options = [
    'attributes' => $attributes,
    'query' => count($query) ? $query : NULL,
  ];

  $url = url($_GET['q'], $options);

  return '<a href="' . check_url($url) . '"' . drupal_attributes($options['attributes']) . '>' . check_plain($text) . '</a>';
}

/**
 * Implements template_preprocess_file_entity().
 */
function vu_preprocess_file_entity(&$variables) {
  switch ($variables['type']) {
    case 'video':
      _vu_preprocess_video_entity($variables);
      break;

    case 'image':
      _vu_preprocess_image_entity($variables);
      break;
  }
}

/**
 * Process video entities.
 *
 * @param array $variables
 *   Theme variables.
 */
function _vu_preprocess_video_entity(&$variables) {
  $variables['label'] = _vu_file_entity_video_transcript_title($variables['filename']);
  if (file_entity_is_page($variables['file'])) {
    drupal_set_title($variables['label']);
  }

  // Populate popup URL for modal video viewmode,
  // and for campus videos which use teaser viewmode.
  $youtube_url = file_create_url($variables['uri']);
  preg_match('/[\\?\\&]v=([^\\?\\&]+)/', $youtube_url, $matches);
  $variables['popup_url'] = 'https://www.youtube.com/embed/' . $matches[1] . '?width=640&height=374&iframe=true';

  // For video on campus detail page, use specific template.
  if ($variables['view_mode'] == 'teaser' && $variables['referencing_field'] == 'field_campus_video') {
    $variables['theme_hook_suggestions'][] = 'file__video__campus';
  }
}

/**
 * Process image entities.
 *
 * @param array $variables
 *   Theme variables.
 */
function _vu_preprocess_image_entity(&$variables) {
  $variables['image_position'] = !empty($variables['field_image_position']) ? check_plain($variables['field_image_position'][LANGUAGE_NONE][0]['value']) : 'right';
}

/**
 * Formats video title text.
 */
function _vu_file_entity_video_transcript_title($title) {
  // If title does not already contain the - transcript suffix,
  // add it for consistency.
  if (stripos($title, 'transcript') == FALSE) {
    $title .= ' - transcript';
  }

  return $title;
}

/**
 * Implements hook_preprocess_breadcrumb().
 */
function vu_preprocess_breadcrumb(&$variables) {
  // Get the object of the current page.
  $obj = menu_get_object('file', 1);
  if (isset($obj->type) && $obj->type == 'video') {
    // Modify breadcrumb when this page is a video transcript page.
    end($variables['breadcrumb']);
    $variables['breadcrumb'][key($variables['breadcrumb'])]['data'] = _vu_file_entity_video_transcript_title($variables['breadcrumb'][key($variables['breadcrumb'])]['data']);
  }

  // For international student, show only first and last trail.
  if (drupal_get_path_alias() == VUMAIN_URLS_INTERNATIONAL_STUDENTS) {
    unset($variables['breadcrumb'][1]);
  }

  // Exclude VU Home from breadcrumb.
  if (!empty($variables['breadcrumb'][1]) && is_string($variables['breadcrumb'][1]) && strpos($variables['breadcrumb'][1], 'VU Home') != FALSE) {
    unset($variables['breadcrumb'][1]);
  }
}

/**
 * Generate a class name based on the length of the supplied text.
 */
function _vu_get_page_title_class($title) {
  $rounded_length = round(max(mb_strlen(strip_tags($title)), 1) / 10) * 10;
  $long_title = $rounded_length >= 60 ? ' long-title' : FALSE;

  return 'length-' . $rounded_length . $long_title;
}

/**
 * Implements template_preprocess_field().
 */
function vu_preprocess_field(&$variables) {
  $element = $variables['element'];
  if (in_array($element['#field_name'], vumain_common_unit_fields())) {
    $variables['theme_hook_suggestions'][] = 'field__unit__common';
  }

  if (!empty($variables['items']) && $element['#field_name'] == 'field_staff_expertise') {
    foreach ($variables['items'] as $delta => $item) {
      $variables['items'][$delta]['#markup'] = ucfirst(check_plain($variables['items'][$delta]['#markup']));
    }
  }

  if (!empty($variables['items']) && in_array($element['#field_name'], ['field_staff_phone', 'field_staff_fax'])) {
    // Standardize phone number.
    foreach ($variables['items'] as $delta => $item) {
      $phone_number = trim(check_plain($variables['items'][$delta]['#markup']));
      $phone_number = str_replace([' ', '(', ')'], '', $phone_number);
      while (strpos($phone_number, '0') === 0) {
        $phone_number = substr($phone_number, 1);
      }

      // Add area code if missing.
      if (strlen($phone_number) < 9) {
        $phone_number = '3' . $phone_number;
      }

      // Add country code if missing.
      if (strpos($phone_number, '+') === FALSE) {
        if (strpos($phone_number, '+61') === FALSE) {
          $phone_number = '+61' . $phone_number;
        }
      }

      // Format it if Australian number.
      if (preg_match('/^\+614(\d{2})(\d{3})(\d{3})$/', $phone_number, $matches)) {
        // Mobile number format.
        $phone_number = '+61 4' . $matches[1] . ' ' . $matches[2] . ' ' . $matches[3];
      }
      elseif (preg_match('/^\+61(\d)(\d{4})(\d{4})$/', $phone_number, $matches)) {
        // Land-line format.
        $phone_number = '+61 ' . $matches[1] . ' ' . $matches[2] . ' ' . $matches[3];
      }

      $variables['items'][$delta]['#markup'] = $phone_number;
    }
  }

  // Add Caption underneath field Image.
  if ($element['#field_name'] == 'field_image') {
    foreach ($variables['items'] as $delta => $item) {
      // Don't add caption to homepage news images.
      if ($element[$delta]['#image_style'] == 'news_homepage_block_470x268') {
        continue;
      }
      // Fetch the field-based title first.
      $title = $item['#item']['title'];
      // Override it with title field of file entity if exists.
      if (!empty($item['#item']['field_file_image_title_text'][LANGUAGE_NONE][0]['value'])) {
        $title = $item['#item']['field_file_image_title_text'][LANGUAGE_NONE][0]['value'];
      }
      // Reproduce the structure suggested by image_field_caption module.
      $variables['items'][$delta]['#item']['image_field_caption']['value'] = $title;
      $variables['items'][$delta]['#item']['image_field_caption']['format'] = 'plain_text';
      // Omit the title attribute.
      $variables['items'][$delta]['#item']['title'] = '';
    }
  }
}

/**
 * Override of theme_image_formatter().
 *
 * @see theme_image_formatter()
 * @see image_field_caption_theme()
 */
function vu_image_formatter($variables) {
  $image = theme_image_formatter($variables);
  // Now that Drupal has rendered the image, if there was a caption let's
  // render the image and the caption, otherwise just return the already
  // rendered image.
  if (!empty($variables['item']['image_field_caption'])) {
    $caption = check_plain($variables['item']['image_field_caption']['value']);
    // Try image_field_caption module.
    if (module_exists('image_field_caption')) {
      return theme('image_field_caption', [
        'image' => $image,
        'caption' => $caption,
      ]);
    }
    // Fallback to manually constructed HTML.
    else {
      return '<figure>' . $image . '<figcaption>' . $caption . '</figcaption></figure>';
    }
  }
  else {
    return $image;
  }
}

/**
 * Implements theme_preprocess_google_appliance_results().
 */
function vu_preprocess_google_appliance_results(&$variables) {
  $search_query_data = $variables['search_query_data'];
  $response_data = $variables['response_data'];
  $variables['query'] = !empty($search_query_data['gsa_query_params']['q']) ? check_plain($search_query_data['gsa_query_params']['q']) : '';
  $variables['total_results'] = !empty($response_data['total_results']) ? $response_data['total_results'] : 0;
}

/**
 * Implements theme_preprocess_google_appliance_result().
 */
function vu_preprocess_google_appliance_result(&$vars) {
  // Some results come through empty. Just show the URL in these cases.
  // This is consistent with the built-in front-end.
  if (empty($vars['title'])) {
    $vars['title'] = _vu_global_search_display_url($vars['abs_url']);
  }

  // For some reason, titles are double escaped
  // Remove HTML tags from title.
  // Tags can be truncated and left without a closing tag, which causes
  // breakage in the output.
  $vars['title'] = strip_tags(decode_entities($vars['title']), '<b>');

  // Clean up URL.
  $vars['display_url'] = _vu_global_search_display_url($vars['abs_url']);

  // If it has an extension? add it to the title.
  // Shorten the mime to only include the extension.
  // e.g. application/pdf to pdf.
  $vars['file_mime'] = !empty($vars['mime']['type']) ? preg_replace('|^.+/|', '', $vars['mime']['type']) : '';
  $vars['file_icon'] = !empty($vars['mime']['icon']) ? $vars['mime']['icon'] : '';

  // Remove tags from snippet. XML/HTML tags can break output.
  $vars['snippet'] = strip_tags($vars['snippet'], '<b>');
}

/**
 * Implements template_preprocess_google_appliance_keymatch().
 */
function vu_preprocess_google_appliance_keymatch(&$vars) {
  // Sanatize urls.
  $vars['url'] = check_url($vars['url']);
  $vars['display_url'] = _vu_global_search_display_url($vars['url']);
  $vars['description'] = filter_xss($vars['description'], ['b', 'strong']);
}

/**
 * Implements theme_google_appliance_pager().
 */
function vu_google_appliance_pager(&$vars) {
  // Grab module settings.
  $settings = _google_appliance_get_settings();

  $total_results = $vars['total_results_count'];
  $results_per_page = $settings['results_per_page'];
  $max_pager_items = 10;
  $current_page = isset($_GET['page']) ? $_GET['page'] : 0;

  $current_page += 1;
  // Add offset.
  // Avoid divide by zero error.
  if ($results_per_page < 1) {
    $results_per_page = 1;
  }

  $number_of_pages = ceil($total_results / $results_per_page);

  // Reset the current page if we are beyond the number of results.
  $current_page = ($current_page >= $number_of_pages) ? $number_of_pages : $current_page;

  $vars['current_page'] = $current_page;

  if ($number_of_pages > 1) {

    // Work out next and prev links.
    $prev_page = $current_page - 1;
    $next_page = $current_page + 1;

    if ($prev_page > 0) {
      $vars['prev_link'] = _vu_href_with_page($prev_page);
    }

    if ($next_page <= $number_of_pages) {
      $vars['next_link'] = _vu_href_with_page($next_page);
    }
    // Work out pager gizzards.
    $width = floor($max_pager_items / 2);
    $pager_start = (($current_page - $width) <= 1) ? 1 : $current_page - $width;
    $pager_start = (($number_of_pages - $pager_start) < $max_pager_items) ? $number_of_pages - $max_pager_items + 1 : $pager_start;
    $pager_start = ($pager_start <= 1) ? 1 : $pager_start;

    for ($i = $pager_start; $i <= (($pager_start - 1) + $max_pager_items) && $i <= $number_of_pages; $i++) {
      $vars['pager_links'][$i] = _vu_href_with_page($i);
    }
  }

  return theme('global_search_pager', $vars);
}

/**
 * Implements template_preprocess_views_view().
 */
function vu_preprocess_views_view(&$variables) {
  // Get the view.
  $view = $variables['view'];

  if ($view->name == 'courses_lists' && $view->current_display == 'all_by_topic') {
    // Process sidebar static blocks.
    $rhs_boxes = [];
    $prepare_for_your_studies_bid = fe_block_get_bid('rhs_prepare_for_your_studies');
    if (!empty($prepare_for_your_studies_bid)) {
      $prepare_for_your_studies = module_invoke('block', 'block_view', $prepare_for_your_studies_bid);
      if (!empty($prepare_for_your_studies['content'])) {
        $rhs_boxes[] = $prepare_for_your_studies['content'];
      }
    }

    $contact_box_bid = fe_block_get_bid('rhs_contactbox');
    if (!empty($contact_box_bid)) {
      $contact_box = module_invoke('block', 'block_view', $contact_box_bid);
      if (!empty($contact_box['content'])) {
        $rhs_boxes[] = $contact_box['content'];
      }
    }
    $variables['rhs_boxes'] = $rhs_boxes;
  }

  if ($view->name == 'course_search') {
    // Get the parameters.
    $params = drupal_get_query_parameters();
    // If the 'iam' query string is 'non-resident'.
    if (!empty($params['iam']) && $params['iam'] == 'non-resident') {
      // Update the view title.
      $view->set_title(t('International courses'));
    }
    if (!empty($params['type']) && $params['type'] == 'Midyear') {
      // Update the view title.
      $view->set_title(t('Mid-year courses'));
    }

    if (!empty($params['type']) && $params['type'] == 'Unit') {
      // Update the view title.
      $view->set_title(t('Units'));
    }

    if ($view->total_rows == 0) {
      $current_query = $view->exposed_input['query'];
      $variables['no_results_message'] = !empty($current_query) ? t("<h2>No results found for <em>'!query'</em>.</h2>", ['!query' => $current_query]) : '<h2>No results found.</h2>';
    }
  }
}

/**
 * Removes the protocol part from a URL for display.
 *
 * @param string $url
 *   A URL.
 *
 * @return string
 *   Input with the first '://' and any characters preceding it removed.
 */
function _vu_global_search_display_url($url) {
  return preg_replace('|^.*://|', '', $url);
}

/**
 * Build a search URL with a page parameter.
 *
 * @param int $page
 *   The page number (1 index, URL is 0 index).
 *
 * @return string
 *   URL.
 */
function _vu_href_with_page($page) {
  $page = $page - 1;
  // Remove offset.
  $parts = parse_url($_SERVER['REQUEST_URI']);
  // Get current query strings.
  $params = [];

  if (isset($parts['query'])) {
    parse_str($parts['query'], $params);
  }
  $params['page'] = $page;
  $query = http_build_query($params, '', '&amp;');
  $href = '?' . $query;

  return $href;
}

/**
 * Helper function to check with the current page is Course search page.
 */
function _vu_is_course_search_page() {
  $args = arg();

  return $args[0] == 'courses' && $args[1] == 'search';
}

/**
 * Helper function to determine this is a topic area page.
 */
function _vu_is_topic_area_page($node_type, $path = '') {
  return $node_type == 'study_topic_area' || ($node_type == 'page_builder' && $path === 'courses/browse-for-courses/all-courses-by-topic');
}

/**
 * Implements theme_current_search_item_wrapper().
 */
function vu_current_search_item_wrapper($variables) {
  $element = $variables['element'];
  $attributes = [
    'class' => [
      'results-summary-item',
    ],
  ];

  if ($element['#current_search_name'] == 'active_items') {
    $attributes['class'][] = 'active-filters-wrapper';
  }

  return sprintf('<div%s>%s</div>', drupal_attributes($attributes), $element['#children']);
}

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function vu_block_view_current_search_course_search_alter(&$data, $block) {
  $params = drupal_get_query_parameters();

  // Hide if no results.
  $view = views_get_page_view();
  if (!empty($view) && $view->total_rows == 0) {
    unset($data['content']);
  }

  // Define the Strings and replacements.
  $placeholders = ['@search-type-single', '@search-type-plural'];
  $labels = ['course', 'courses'];
  if ((isset($params['type']) && drupal_strtolower($params['type']) == 'unit')) {
    $labels = ['unit', 'units'];
  }
  // Replace the '@search-type' string for units and course search.
  if (isset($data['content'])) {
    foreach ($data['content'] as $count_item => $result_count) {
      $count_markup = isset($result_count['#markup']) ? $result_count['#markup'] : 0;
      $replaced_markup = str_replace($placeholders, $labels, $count_markup);
      $data['content'][$count_item]['#markup'] = $replaced_markup;
    }
  }

  // Determine showing result count message with or without keyword.
  if (empty($params['query']) && !empty($data['content']['result_count'])) {
    unset($data['content']['result_count']);
  }
  else {
    unset($data['content']['result_count_without_keyword']);
  }

  // Merge active facets list and the reset button which are separate blocks
  // by default so this makes it easier to style them as one list.
  if (!empty($data['content']['active_items']['#items']) && !empty($data['content']['reset_filters'])) {
    $items = $data['content']['active_items']['#items'];
    array_unshift($items, t('Filtered by:'));
    $items_count = count($items) - 1;
    // By default active facets are URLs to reset the filters. Convert them
    // to plain text since we will have one button to reset all of them instead.
    foreach ($items as $key => $item) {
      $last_item_class = $key == $items_count ? 'last' : '';
      $new_attributes = [
        'data' => strip_tags($item),
        'class' => 'active-filter ' . $last_item_class,
      ];
      $data['content']['active_items']['#items'][$key] = $new_attributes;
    }
    // Add reset button to active facets list.
    $data['content']['active_items']['#items'][] = [
      'data' => $data['content']['reset_filters']['#markup'],
      'class' => 'reset-filters element-invincible',
    ];
    // We no longer need the standalone reset button.
    unset($data['content']['reset_filters']);
  }
}

/**
 * Convert a field possibly containing multiple values into form: a, b, c and d.
 *
 * We might want to consider replacing this with a module like
 * https://www.drupal.org/project/textformatter although
 * or https://www.drupal.org/project/field_delimiter but it seems
 * that oxford comma support is still in development.
 */
function vu_join_multiple_values($field, $cj = 'and', $callback = NULL, $unique = FALSE) {
  foreach ($field as $value) {
    $values[] = trim($value['safe_value']);
  }
  if (is_callable($callback)) {
    $values = array_map($callback, $values);
  }
  $values = array_filter($values);
  if ($unique) {
    $values = array_unique($values);
  }
  $last_value = array_pop($values);

  return $values ? sprintf('%s %s %s', implode(', ', $values), $cj, $last_value) : $last_value;
}

/**
 * Determines if a campus has full campus status or not.
 *
 * E.g. MetroWest is technically not.
 *
 * @param string $campus
 *   Name of the campus to check.
 *
 * @return bool
 *   TRUE if campus is ful campus.
 */
function vu_campuses_is_full_campus($campus) {
  return $campus != VU_CAMPUSES_METROWEST_TITLE;
}

/**
 * Convert paragraphs to list items.
 */
function vu_listify($html) {
  $html = preg_replace('/<([\/]?)(p)>/', '<\\1li>', $html);
  $html = preg_replace('/<li>[\W]*<\/li>/x', '', $html);

  return $html;
}

/**
 * Change Cricos code facet title.
 */
function vu_facetapi_title($variables) {
  if ($variables['title'] == 'Cricos code') {
    return t('Filter by campus');
  }
}

/**
 * Implements hook_form_process_HOOK().
 */
function vu_form_process_textfield($element, &$form_state, &$form) {
  if ($form['#id'] == 'google-appliance-block-form' || $form['#id'] == 'vu-core-funnelback-search-form') {
    $element['#theme_wrappers'][] = 'search_wrapper';

    // Set the custom  property '#input_prefix 'and suffix because
    // '#field_suffix' gets appended to the input element without a tag.
    $element['#input_suffix'] = $element['#title'];
  }
  return $element;
}

/**
 * Custom theme implementation for form_elements to inject Bootstrap classes.
 */
function vu_search_wrapper($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += [
    '#title_display' => 'before',
  ];

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = ['form-item col-sm-12 col-md-9'];
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], [
      ' ' => '-',
      '_' => '-',
      '[' => '-',
      ']' => '',
    ]);
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  // Use the custom  property '#input_prefix 'and suffix because field_suffix
  // gets appended to the input element without a tag.
  $prefix = isset($element['#input_prefix']) ? '<span class="field-prefix">' . $element['#input_prefix'] . '</span> ' : '';
  $suffix = isset($element['#input_suffix']) ? ' <span class="field-suffix">' . $element['#input_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Embed SVG from provided URL.
 *
 * @param string $url
 *   Local URL or local path to retrieve SVG from.
 *
 * @return string
 *   Loaded SVG or FALSE if unable to load SVG.
 */
function vu_embed_svg($url) {
  $svg_path = DRUPAL_ROOT . (strpos($url, 'http') === 0 ? parse_url(str_replace('.png', '.svg', $url), PHP_URL_PATH) : str_replace('.png', '.svg', $url));

  if (!file_exists($svg_path)) {
    return FALSE;
  }

  return file_get_contents($svg_path);
}

/**
 * Implements theme_file_link().
 *
 * Removes icon from default theme_file_link.
 */
function vu_file_link($variables) {
  $file = $variables['file'];
  $url = file_create_url($file->uri);
  $options = [
    'attributes' => [
      'type' => $file->filemime . '; length=' . $file->filesize,
    ],
  ];
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }
  return '<span class="file">' . ' ' . l($link_text, $url, $options) . '</span>';
}

/**
 * Implements theme_facetapi_count().
 */
function vu_facetapi_count($variables) {
  return ' <small>(' . (int) $variables['count'] . ')</small>';
}

/**
 * Implements theme_facetapi_link_active().
 */
function vu_facetapi_link_active($variables) {
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Implements hook_css_alter().
 */
function vu_css_alter(&$css) {
  if (variable_get('livereload', FALSE)) {
    // Alter css to display as link tags.
    foreach ($css as $key => $value) {
      $css[$key]['preprocess'] = FALSE;
    }
  }
}

/**
 * Implements hook_js_alter().
 */
function vu_js_alter(&$javascript) {
  // Add Livereload support.
  if (variable_get('livereload', FALSE)) {
    $path = 'http://localhost:35729/livereload.js?snipver=1';
    drupal_add_js($path, 'external');
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function vu_form_vu_core_funnelback_search_form_alter(&$form, $form_state) {
  $form['submit']['#prefix'] = '<div class="col-sm-3 form-actions form-wrapper form-group">';
  $form['submit']['#suffix'] = '</div>';
}
