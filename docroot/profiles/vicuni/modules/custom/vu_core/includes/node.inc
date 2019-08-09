<?php

/**
 * @file
 * VU Specific node related functions.
 */

/**
 * Implements hook_permission_alter().
 */
function node_vu_core_permission_alter(&$permissions) {
  $permissions['switch page theme'] = [
    'title' => t('Allow user to select the page theme.'),
  ];

  $permissions['Restrict editing page title'] = [
    'title' => t('Allow user to edit the title field of a page.'),
  ];

  // Create permissions to allow users to delete content which has not been
  // published.
  foreach (node_type_get_types() as $type => $info) {
    $permissions["delete $type unpublished"] = [
      'title' => t('%type_name: Delete content when it has never been published', ['%type_name' => $info->name]),
    ];
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function node_vu_core_form_events_node_form_alter(&$form, &$form_state) {
  // Add customisations to admin UI - row colours etc.
  drupal_add_css(drupal_get_path('module', 'vu_core') . "/css/vu_core.admin.page_builder.css");
  drupal_add_css(drupal_get_path('module', 'vu_core') . "/css/vu_core.admin.basic_text.css");

  node_vu_core_toggle_content_visibility($form);
  if ((isset($form['#node']->ds_switch) && $form['#node']->ds_switch == 'victory') || (empty($form['nid']['#value']))) {
    $form['field_event_campus'][LANGUAGE_NONE]['#required'] = FALSE;
    if (!user_access('bypass node access')) {
      $form['field_theme']['#access'] = FALSE;
    }
  }
  else {
    $form['field_event_cost'][LANGUAGE_NONE][0]['#required'] = FALSE;
    $form['field_event_cost'][LANGUAGE_NONE][0]['value']['#required'] = FALSE;
  }
  // Move theme switcher field.
  vu_core_theme_switcher($form, $form_state);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function node_vu_core_form_news_node_form_alter(&$form, &$form_state) {
  drupal_add_css(drupal_get_path('module', 'vu_core') . "/css/vu_core.admin.basic_text.css");
  node_vu_core_toggle_content_visibility($form);
  if (!user_access('bypass node access')) {
    $form['field_theme']['#access'] = FALSE;
  }

  // Move theme switcher field.
  vu_core_theme_switcher($form, $form_state);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function node_vu_core_form_page_builder_node_form_alter(&$form, &$form_state) {
  // Move theme switcher field.
  vu_core_theme_switcher($form, $form_state);

  // Add customisations to admin UI - row colours etc.
  drupal_add_css(drupal_get_path('module', 'vu_core') . "/css/vu_core.admin.page_builder.css");
  // Remove the script that auto-hides the summary.
  $form['body'][$form['language']['#value']][0]['summary']['#attached'] = NULL;
  // Set summary as a require field.
  $form['body'][$form['language']['#value']][0]['summary']['#required'] = TRUE;
  // Update help text.
  $form['body'][$form['language']['#value']][0]['summary']['#description'] = t('Maximum recommended length: <strong>140 characters</strong>');

  // Move 'Redirect link' field into 'URL redirects' vertical tabs.
  if (!isset($form['redirect'])) {
    $form['redirect'] = [
      '#type' => 'fieldset',
      '#title' => t('URL redirects'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 30,
      '#group' => 'additional_settings',
    ];
  }

  $form['redirect']['field_redirect_link'] = $form['field_redirect_link'];
  unset($form['field_redirect_link']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function node_vu_core_form_courses_node_form_alter(&$form, &$form_state) {
  // See PW-3253, Hide title for non admin's.
  if (!user_access('bypass node access')) {
    $form['title']['#attributes']['disabled'] = 'disabled';
    $form['field_imp_desc'][LANGUAGE_NONE][0]['value']['#attributes']['disabled'] = 'disabled';
    $form['field_imp_career'][LANGUAGE_NONE][0]['value']['#attributes']['disabled'] = 'disabled';
    $form['field_atar_adjustment']['#access'] = FALSE;
  }
}

/**
 * Implements hook_field_group_build_pre_render_alter().
 */
function vu_core_field_group_build_pre_render_alter(&$element) {
  if (isset($element['group_theme']) && isset($element['#entity']->field_theme) && 'victory' == $element['#entity']->field_theme[LANGUAGE_NONE][0]['value']) {
    $temp = $element['group_theme']['group_theme_victory']['#weight'];
    $element['group_theme']['group_theme_victory']['#weight'] = $element['group_theme']['group_theme_vu']['#weight'];
    $element['group_theme']['group_theme_vu']['#weight'] = $temp;
  }

  // Hiding 2015 theme tab for migrated and new event page.
  if (isset($element['type']) && $element['type']['#value'] == 'events') {
    if ((isset($element['#entity']->ds_switch) && $element['#entity']->ds_switch == 'victory') || empty($element['nid']['#value'])) {
      if (!user_access('bypass node access')) {
        $element['group_theme']['group_theme_vu']['#access'] = FALSE;
      }
    }
    else {
      $temp = $element['group_theme']['group_theme_victory']['#weight'];
      $element['group_theme']['group_theme_victory']['#weight'] = $element['group_theme']['group_theme_vu']['#weight'];
      $element['group_theme']['group_theme_vu']['#weight'] = $temp;
    }
  }
}

/**
 * Configure node edit form to show/hide the promote and sticky options.
 *
 * @param array $form
 *   The drupal form array.
 */
function node_vu_core_toggle_content_visibility(&$form) {
  // If this form has the media release checkbox (news items) then
  // hide the promote and sticky checkboxes when media release is checked.
  if (!empty($form['field_media_release'])) {
    $state_condition = [
      'invisible' => [
        sprintf(':input[name="field_media_release[%s]"]', $form['language']['#value'] ?: LANGUAGE_NONE) => ['checked' => TRUE],
      ],
    ];
    $form['options']['promote']['#states'] = $state_condition;
    $form['options']['sticky']['#states'] = $state_condition;
  }
}

/**
 * Implements hook_vu_core_node_presave().
 */
function node_vu_core_node_presave_alter($node) {
  if (isset($node->type)) {
    switch ($node->type) {
      // Toggle view mode based on selected theme.
      case 'page_builder':
      case 'success_story':
      case 'campus':
        vu_core_set_view_mode($node);
        break;

      case 'news':
        if ($node->is_new) {
          $node->ds_switch = 'victory';
          $node->field_theme[LANGUAGE_NONE][0]['value'] = 'victory';
        }
        else {
          vu_core_set_view_mode($node);
        }
        break;

      case 'events':
        $rhs_component = vu_core_extract_single_field_value($node, 'node', 'field_rhs_components', 'value');
        if (!empty($rhs_component)) {
          $component = paragraphs_item_load($rhs_component);
          $map_component_row = $component->field_map_component_row[LANGUAGE_NONE];
          foreach ($map_component_row as $location) {
            $location_arr = paragraphs_item_load($location['value']);
            // Load campus names.
            $campus_nid = vu_core_extract_single_field_value($location_arr, 'paragraphs_item', 'field_campus', 'target_id');
            if (!empty($campus_nid)) {
              $campus = node_load($campus_nid);
              $custom_location[] = $campus->title;
            }
            // Load custom locations.
            $custom_loc = vu_core_extract_single_field_value($location_arr, 'paragraphs_item', 'field_place_name', 'value');
            if (!empty($custom_loc)) {
              $custom_location[] = $custom_loc;
            }
          }
          // Setting the value for location tag field.
          $node->field_location_tag[LANGUAGE_NONE][0]['value'] = !empty($custom_location) ? (count($custom_location) > 1 ? 'Multiple Location' : $custom_location[0]) : '';
        }
        if ($node->is_new) {
          $node->ds_switch = 'victory';
          $node->field_theme[LANGUAGE_NONE][0]['value'] = 'victory';
          $node->field_event_campus[LANGUAGE_NONE][0]['value'] = '';
        }
        else {
          $theme = vu_core_extract_single_field_value($node, 'node', 'field_theme', 'value');
          if ($theme == 'victory') {
            $node->field_event_campus[LANGUAGE_NONE][0]['value'] = '';
          }
          vu_core_set_view_mode($node);
        }
        break;
    }
  }
}

/**
 * Implements hook_block_view_alter().
 */
function node_vu_core_block_view_alter(&$data, $block) {
  // Selectively hide the block title.
  $region_map = [
    'navigation',
    'header_menu',
    'shutter',
  ];

  $block_map = [
    'menu_block',
  ];

  // Hide menu block title in navigation region.
  if (in_array($block->module, $block_map) && in_array($block->region, $region_map)) {
    $block->title = '<none>';
  }
}

/**
 * Implements hook_preprocess_html_alter().
 */
function node_vu_core_preprocess_html_alter(&$variables) {
  $node = isset($variables['node']) ? $variables['node'] : node_load(arg(1));
  // Checks if VU Sydney subsite and if yes, changes the $head_title.
  if (is_object($node) && ($node->type === 'page_builder' || $node->type === 'webform')) {
    $subsite_node = vu_core_subsite_node_get($node);
    if (!empty($subsite_node) && $subsite_node->title === VU_SYDNEY_SUBSITE_TITLE) {
      $head_title = [
        'title' => strip_tags(drupal_get_title()),
        'name' => VU_SYDNEY_SUBSITE_NAME,
      ];
      $variables['head_title_array'] = $head_title;
      $variables['head_title'] = implode(' | ', $head_title);
    }
  }
}

/**
 * Implements hook_preprocess_node_alter().
 */
function node_vu_core_preprocess_node_alter(&$variables) {
  $node = isset($variables['node']) ? $variables['node'] : FALSE;
  if (is_object($node) && ($node->type === 'unit' || $node->type === 'unit_set')) {
    $variables['is_first_year_college'] = $variables['field_college'][0]['title'] === 'First Year College';
  }
}

/**
 * Implements hook_preprocess_page_alter().
 */
function node_vu_core_preprocess_page_alter(&$variables) {
  $node = isset($variables['node']) && is_object($variables['node']) ? $variables['node'] : FALSE;
  if ($node === FALSE) {
    $node = _vu_core_block_menu_get_course_object();
  }

  if ($node === FALSE) {
    return;
  }

  switch ($node->type) {
    case 'webform':
    case 'page_builder':
      $subsites = [];
      // Get the language.
      if (!empty($node->language)) {
        if (!vu_core_is_subsite()) {
          break;
        }

        $subsite_node = vu_core_subsite_node_get();

        // Load settings from taxonomy.
        $subsite_metadata = vu_core_subsite_meta_get($subsite_node);

        if ($subsite_metadata) {
          // Hide secondary nav aka header region.
          if ($subsite_metadata->hide_menu && isset($variables['page']['header'])) {
            $variables['page']['header'] = '';
          }

          // Load background.
          $subsites['background_url'] = $subsite_metadata->background;

          // Set Logo and front page URL.
          if ($subsite_metadata->name === VU_SYDNEY_SUBSITE_TITLE) {
            $variables['logo'] = '/' . drupal_get_path('theme', 'vu') . '/logo-sydney.png';
            $variables['front_page'] = url('node/' . $subsite_node->nid);
            // This fixes the logo link <a> title param.
            $variables['site_name'] = VU_SYDNEY_SUBSITE_NAME;
          }

          // Load page logo.
          $subsites['page_logo_url'] = $subsite_metadata->logo;
        }

        // Load subsite regions "subsite_landing_rhs" and "above_tiles_block"
        // on subsite landing page.
        $menu_depth = vu_core_menu_depth_get();

        $subsites['right_blocks'] = FALSE;
        if ($blocks = block_get_blocks_by_region('subsite_landing_rhs') && $menu_depth == 1) {
          $subsites['right_blocks'] = $blocks;
        }

        $subsites['above_tiles_block'] = FALSE;
        if ($blocks = block_get_blocks_by_region('subsite_landing_above_tiles') && $menu_depth == 1) {
          $subsites['above_tiles_block'] = $blocks;
        }

        $subsites['below_tiles_blocks'] = FALSE;
        if ($blocks = block_get_blocks_by_region('subsite_landing_below_tiles') && $menu_depth == 1) {
          $subsites['below_tiles_blocks'] = $blocks;
        }

      }
      $variables['subsites'] = $subsites;
      break;

    case 'unit_set':
      // Add "type" - major, minor - suffix to unit set title.
      if (!empty($node->field_unit_s_type[$node->language][0]['taxonomy_term']) && is_object($node->field_unit_s_type[$node->language][0]['taxonomy_term'])) {
        $variables['title_suffix'] = [
          '#markup' => '<div class="unitset-type h3">' . $node->field_unit_s_type[$node->language][0]['taxonomy_term']->name . '</div>',
        ];
      }
    case 'courses':
    case 'unit':
      // Custom VU Poly header for courses and units.
      if (!empty($node->field_college[$node->language][0]['title']) && in_array($node->field_college[$node->language][0]['title'], ['VU Polytechnic', 'Victoria Polytechnic'])) {
        if (empty($variables['title_box_classes'])) {
          $variables['title_box_classes'] = [];
        }
        $variables['title_box_classes'][] = 'victoria-polytechnic';
        $vicpoly_logo_img = '<img src="/profiles/vicuni/themes/custom/vu/images/vp-logo-full-white.png">';
        $vicpoly_logo_svg = '/profiles/vicuni/themes/custom/victory/images/brands/vicpoly.svg';
        $vicpoly_logo_svg = victory_embed_svg($vicpoly_logo_svg);

        $variables['title_prefix'] = [
          '#markup' => '<a href="https://vupolytechnic.edu.au">' . ($vicpoly_logo_svg !== FALSE ? $vicpoly_logo_svg : $vicpoly_logo_img) . '</a>',
        ];
      }

      break;
  }

  // Set custom breadcrumb for Unit(set)s.
  if (in_array($node->type, ['unit', 'unit_set'])) {
    $breadcrumb = drupal_get_breadcrumb();
    $breadcrumb[] = l(t('Units'), 'units');
    drupal_set_breadcrumb($breadcrumb);
  }
}

/**
 * Implements hook_init().
 */
function node_vu_core_init() {
  if (drupal_is_cli()) {
    return;
  }

  // Add cors headers if required.
  $cors_config = variable_get('vu_cors_config', []);
  if (!empty(current_path()) && !empty($cors_config)) {
    require_once '_cors.inc';
    $request_headers = getallheaders();
    // Even if the path doesn't match, we still want the cache to change
    // based on the Origin header.
    drupal_add_http_header('Vary', 'Origin', TRUE);
    if (!empty($request_headers['Origin'])) {
      $header = _vu_core_cors_header_prepare_for_path(current_path(), $request_headers['Origin'], $cors_config);
    }
    if (!empty($header)) {
      drupal_add_http_header($header['name'], $header['value'], FALSE);
    }
  }
}

/**
 * Implements hook_node_view().
 */
function node_vu_core_node_view_alter($node, $view_mode, $langcode) {
  // Check permissions and whether the node can be moderated.
  if (!user_is_logged_in()
    || !user_access('view moderation messages')
    || !workbench_moderation_node_type_moderated($node->type)
  ) {
    return;
  }

  // For new content, workbench_moderation property will not be set.
  if (isset($node->workbench_moderation)) {
    $messages = [];
    $revision = $node->workbench_moderation['my_revision'];
    $user = user_load($revision->uid);
    $user_name = !empty($user) ? check_plain($user->name) : '';
    $date = !empty($revision->timestamp) ? format_date($revision->timestamp, 'short') : '';
    $log = !empty($node->log) ? strip_tags($node->log) : '';

    $messages[] = ['label' => t('Revised by'), 'message' => $user_name];
    $messages[] = ['label' => t('Date of revision'), 'message' => $date];
    $messages[] = ['label' => t('Log message'), 'message' => $log];

    // Add the above info to moderation messages.
    workbench_moderation_set_message($messages);
    // Add default workbench messages (workbench only adds on "full" view mode).
    if ($view_mode === 'victory') {
      workbench_moderation_messages('view', $node);
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function node_vu_core_form_success_story_node_form_alter(&$form, &$form_state) {
  // Move theme switcher field.
  vu_core_theme_switcher($form, $form_state);

}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function node_vu_core_form_campus_node_form_alter(&$form, &$form_state) {
  // Move theme switcher field.
  vu_core_theme_switcher($form, $form_state);

  // Add customisations to admin UI - row colours etc.
  drupal_add_css(drupal_get_path('module', 'vu_core') . "/css/vu_core.admin.page_builder.css");
}
