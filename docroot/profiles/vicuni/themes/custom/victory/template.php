<?php

/**
 * @file
 * Core functions for Victory theme.
 */

/**
 * Implements hook_theme().
 */
function victory_theme() {
  $items['main_menu_level2_item_section'] = [
    'template' => 'templates/component/menu/menu--main-menu-level2-item-section',
    'variables' => [
      'title' => NULL,
      'summary' => NULL,
      'href' => NULL,
      'attributes' => [],
    ],
  ];

  $items['search_wrapper'] = [
    'render element' => 'element',
  ];

  $items['tools_menu_ext_link_icon'] = [
    'template' => 'templates/component/header/tools-menu-ext-link-icon',
  ];

  $items['vu_funnelback_empty_query_message'] = [
    'template' => 'templates/funnelback/empty-query-message',
  ];

  return $items;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function victory_form_google_appliance_block_form_alter(&$form, $form_state) {
  $form['actions']['#attributes']['class'][] = 'col-lg-2';
}

/**
 * Implements hook_form_process_HOOK().
 */
function victory_form_process_textfield($element, &$form_state, &$form) {
  if ($form['#id'] == 'google-appliance-block-form' || $form['#id'] == 'vu-core-funnelback-search-form') {
    $element['#theme_wrappers'][] = 'search_wrapper';

    // Set the custom  property '#input_prefix 'and suffix because
    // '#field_suffix' gets appended to the input element without a tag.
    $element['#input_suffix'] = isset($element['#title']) ?? '';
  }

  return $element;
}

/**
 * Custom theme implementation for form_elements to inject Bootstrap classes.
 */
function victory_search_wrapper($variables) {
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
  $attributes['class'] = ['form-item col-sm-12 col-md-9 col-lg-10'];
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
 * Implements hook_form_alter().
 */
function victory_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'vu_core_course_search_form') {
    $form['#attached']['js'][] = path_to_theme() . '/js/search/course_search_form.js';
    // Initialise class array if not set.
    $form['#attributes']['class'] = !isset($form['#attributes']['class']) || !is_array($form['#attributes']['class']) ? [] : $form['#attributes']['class'];
    $form['#attributes']['class'] += [
      'clearfix',
      'form-horizontal',
    ];

    $form['query']['#wrapper_attributes'] = [
      'class' => [
        'js-search_button',
        'pull-left',
      ],
    ];
    $form['query']['#input_group'] = TRUE;
    $form['query']['#field_suffix'] = '<i class="fa fa-search"></i>';
    $form['query']['#title_display'] = 'invisible';
    $form['query']['#title'] = 'Search for a course';
    $form['query']['#attributes'] = [
      'placeholder' => t('Course name or type'),
    ];
    $form['iam']['#attributes'] = [
      'class' => [
        'form-wrapper',
      ],
    ];
    $form['submit']['#attributes'] = [
      'class' => [
        'search',
        'hidden-xs',
        'pull-right',
      ],
    ];
    $form['submit']['#icon'] = '<i class="fa fa-search"></i>';
    $form['submit']['#icon_position'] = 'before';
    $form['search_group'] = [
      '#type' => 'container',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      // Elements.
      'query' => $form['query'],
      'iam' => $form['iam'],
      'submit' => $form['submit'],
      '#attributes' => [
        'class' => [
          'row',
          'form-group-lg',
        ],
      ],
    ];
    unset($form['submit']);
    unset($form['query']);
    unset($form['iam']);

    $form['#method'] = 'get';
    $form['#action'] = url('courses/search');
  }

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
function victory_embed_svg($url) {
  $svg_path = DRUPAL_ROOT . (strpos($url, 'http') === 0 ? parse_url(str_replace('.png', '.svg', $url), PHP_URL_PATH) : str_replace('.png', '.svg', $url));
  if (!file_exists($svg_path)) {
    return FALSE;
  }

  return file_get_contents($svg_path);
}

/**
 * Implements hook_preprocess_HOOK().
 */
function victory_preprocess_bootstrap_accordion(&$variables) {
  include_once drupal_get_path('theme', 'victory') . '/templates/layout/entity/entity.vars.php';

  victory_preprocess_entity__paragraphs_item__accordion($variables, []);
}

/**
 * Implements template_preprocess_block().
 */
function victory_preprocess_block(&$variables) {
  $block = isset($variables['block']) ? $variables['block'] : FALSE;
  if ($block !== FALSE && isset($block->bid)) {
    // Update search block to add container class and use H3, not default title.
    switch ($block->bid) {
      case 'vu_core-vu_course_search':
        $variables['classes_array'][] = 'container';
        $variables['title_prefix'] = [
          '#type' => 'markup',
          '#markup' => "<h3>{$block->subject}</h3>",
        ];

        $block->subject = NULL;
        $variables['title'] = NULL;
        break;

      // Modifications for Course essentials block.
      case 'ds_extras-course_essentials':
        $variables['classes_array'][] = 'container';
        $variables['classes_array'][] = 'content';
        $variables['classes_array'][] = 'fields-' . count(element_children($variables['elements']));
        $variables['content'] = "<div class='row'>{$variables['content']}</div>";
        $block->subject = NULL;
        break;

      case 'vu_core-vu_on_page_nav':
        $variables['title_attributes_array']['class'][] = 'exclude-onthispage';
        $variables['title_attributes_array']['data-title'][] = $block->subject;
        $variables['classes_array'][] = 'switch-on';
        break;

      case 'ds_extras-courses_title_box_feature':
        $block->subject = NULL;
        break;

      case 'vu_core-course_international_switcher':
        $variables['classes_array'][] = 'switch-on';
        break;
    }

    if ($block->delta === 'researcher_profile_search') {
      $variables['classes_array'][] = 'container';
    }
    if ($block->delta === 'vu_block_lower_footer') {
      if (vu_core_is_subsite()) {
        $node = vu_core_subsite_node_get();
        // Load settings from taxonomy.
        $subsite_metadata = vu_core_subsite_meta_get($node);
        $social_links = $subsite_metadata->field_override_social_media_link;
        $chat_now = $subsite_metadata->field_override_chat_now;
        $campus_app = $subsite_metadata->field_override_campus_app;
        $contact_us = $subsite_metadata->field_override_contact_us;
        // Adding class on override social media.
        if ($subsite_metadata && $social_links) {
          $variables['classes_array'][] = 'override-social-links-footer';
        }
        // Adding class on other block overrides.
        if ($subsite_metadata && ($chat_now || $campus_app || $contact_us)) {
          $variables['classes_array'][] = 'override-lower-footer-blocks';
        }
      }
    }
  }
}

/**
 * Implements theme_preprocess_funnelback_results().
 */
function victory_preprocess_funnelback_results(&$vars) {
  // Get search keywords.
  preg_match_all('/"(?:\\\\.|[^\\\\"])*"|\S+/', $vars['query'], $search_keywords);

  if (!empty($search_keywords[0])) {
    // For each result block summary.
    foreach ($vars['items'] as $key => $item) {
      $summary_text = $item['#summary'];

      // For each search keyword.
      foreach ($search_keywords[0] as $keyword) {
        $summary_text = _funnelback_set_search_keyword_bold($keyword, $summary_text);
      }

      // Mapping the summary text to correct result block.
      $vars['items'][$key]['#summary'] = $summary_text;
    }

    if (isset($vars['curator']['#curator']['exhibits'])) {
      foreach ($vars['curator']['#curator']['exhibits'] as $key => $item) {
        $summary_text = $item['descriptionHtml'];

        // For each search keyword.
        foreach ($search_keywords[0] as $keyword) {
          $summary_text = _funnelback_set_search_keyword_bold($keyword, $summary_text);
        }

        // Mapping the summary text to correct result block.
        $vars['curator']['#curator']['exhibits'][$key]['descriptionHtml'] = $summary_text;
      }
    }
  }
}

/**
 * Search text highlighter.
 */
function _funnelback_set_search_keyword_bold($keyword = '', $summary_text = '') {
  $replaced_text = '';
  if (empty($summary_text) || empty($keyword)) {
    return $replaced_text;
  }

  $keyword = trim($keyword, '"');

  $replaced_text = preg_replace('/\b(' . $keyword . ')\b/i', '<b>$1</b>', $summary_text);

  return $replaced_text;
}

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function victory_block_view_vu_core_vu_on_page_nav_alter(&$data, $block) {
  // Attach JS behaviour to 'On this page nav' block.
  $data['content']['#attached']['js'][] = drupal_get_path('theme', 'victory') . '/js/components/victory.on-this-page.js';

  // Wrap content variant with a container.
  if ('content' == $block->region) {
    $data['content']['#markup'] = "<div class='container'>{$data['content']['#markup']}</div>";
  }
}

/**
 * Implements hook_preprocess_entity__ENTITY_TYPE__BUNDLE().
 */
function victory_preprocess_vu_accordion(&$variables, $entity) {
  drupal_add_js(drupal_get_path('module', 'vu_core') . '/js/vu_core.accordion.js');
  $variables['icon'] = victory_embed_svg(url('/profiles/vicuni/themes/custom/victory/images/cross.svg'));
}

/**
 * Implements theme_file_link().
 *
 * Removes icon from default theme_file_link.
 */
function victory_file_link($variables) {
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
 * Implements hook_menu_breadcrumb_alter().
 */
function victory_menu_breadcrumb_alter(&$active_trail, $item) {
  if (_vu_core_active_trail_has_root_parent('main-menu', ['link_title' => 'VU Home'])) {
    unset($active_trail[0]);
  }
  elseif ($active_trail[0]['href'] == '<front>') {
    $active_trail[0]['title'] = t('VU Home');
  }
}

/**
 * Implements hook_preprocessor_hook().
 */
function victory_preprocess_vu_core_block_campus_maps(&$variables) {

  $node = $variables['default'];

  // If the node is not valid.
  if (empty($node->type)) {
    return;
  }

  $campus = $variables['campus_name'];
  $variables['lat_long'][0] = vumain_campuses_get_lat_long($campus);
  $variables['campus_title'] = $node->title;
  $variables['campus_addr'] = vumain_campus_get_location($node);

  // Get all campus positions.
  $all_campuses = vumain_campuses_get_lat_long();
  $campuses = [];

  foreach ($all_campuses as $campus_id => $location) {
    if (array_key_exists($campus_id, $variables['campuses']) || strpos($campus_id, 'queen-') !== FALSE) {
      if (!isset($location['address'])) {
        $title = $variables['campuses'][$campus_id];
      }
      else {
        $title = $variables['campuses']['city-queen'];
      }

      $campuses[$campus_id] = array_merge($location, ['title' => $title]);
    }
  }

  $variables['zoom'] = vumain_campuses_zoom($campus);
  $variables['map_properties'] = [];

  $js_path = drupal_get_path('module', 'vumain') . '/js/';
  $google_maps_api_key = variable_get('google_maps_api_key', '');
  $google_maps_api = sprintf('<script type="text/javascript" src="//maps.googleapis.com/maps/api/js?key=%s&v=3.exp"></script>', $google_maps_api_key);
  $element = [
    '#type' => 'markup',
    '#markup' => $google_maps_api,
  ];

  if (strpos(drupal_get_html_head(), $google_maps_api) === FALSE) {
    drupal_add_html_head($element, 'vumain_google_maps_js');
  }
  drupal_add_js([
    'campus' => [
      'map_marker' => '',
      'title' => $variables['campus_name'],
      'lat_long' => $variables['lat_long'],
      'zoom' => $variables['zoom'],
      'hide' => TRUE,
      'disableUI' => FALSE,
      'all_campuses' => array_values($campuses),
    ],
  ], 'setting');
  drupal_add_js($js_path . 'vumain_campuses.js');
}

/**
 * Implements hook_css_alter().
 */
function victory_css_alter(&$css) {
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
function victory_js_alter(&$javascript) {
  // Add Livereload support.
  if (variable_get('livereload', FALSE)) {
    $path = 'http://localhost:35729/livereload.js?snipver=1';
    drupal_add_js($path, 'external');
  }
}

/**
 * Process image entities.
 *
 * @param array $variables
 *   Theme variables.
 */
function _victory_preprocess_image_entity(&$variables) {
  $variables['image_position'] = !empty($variables['field_image_position']) ? check_plain($variables['field_image_position'][LANGUAGE_NONE][0]['value']) : 'right';
}

/**
 * Implements template_preprocess_file_entity().
 */
function victory_preprocess_file_entity(&$variables) {
  switch ($variables['type']) {

    case 'image':
      _victory_preprocess_image_entity($variables);
      break;
  }
}
