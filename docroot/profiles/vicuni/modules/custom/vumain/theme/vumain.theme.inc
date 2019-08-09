<?php
/**
 * @file
 * Preprocess functions for templates for the Victoria University Website.
 */

/**
 * Template preprocess: vu_campus_location_maps_block.
 */
function vumain_preprocess_vu_campus_location_maps_block(&$variables) {
  global $base_url;
  global $base_path;
  // Get the node.
  if (empty($variables['campus_nid'])) {
    $node = isset($variables['node']) ? $variables['node'] : menu_get_object();
  }
  else {
    $node = node_load($variables['campus_nid']);
  }

  // If the node is not valid.
  if (empty($node->type)) {
    return;
  }

  $campus = drupal_get_path_alias('node/' . $node->nid);
  $variables['campus_name'] = $campus;
  $variables['lat_long'][0] = vumain_campuses_get_lat_long($campus);


  // Special case for Queen St
  // Show all four addresses.
  $campus_id = vumain_googlemaps_get_campus_id($campus);
  if ($campus_id == VUMAIN_VU_CAMPUS_CITY_QUEEN) {
    $all_campuses = vumain_campuses_get_lat_long();
    $filtered = array_filter(array_keys($all_campuses), function ($k) {
      return strpos($k, 'queen-') !== FALSE;
    });
    $city_queen_lat_long = array_values(array_intersect_key($all_campuses, array_flip($filtered)));
    $variables['lat_long'] = $city_queen_lat_long;
    $campus = VUMAIN_VU_CAMPUS_CITY_QUEEN;
  }
  elseif (strpos($campus, 'queen-')) {
    $campus = VUMAIN_VU_CAMPUS_CITY_QUEEN;
  }
  if (empty($variables['lat_long'])) {
    return;
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
      'map_marker' => $base_url . $base_path . drupal_get_path('theme', 'vu') . '/images/map-marker.jpg',
      'title' => $variables['campus_name'],
      'width' => '320px',
      'height' => '320px',
      'lat_long' => $variables['lat_long'],
      'zoom' => $variables['zoom'],
      'hide' => false,
      'disableUI' => isset($variables['map_properties']['disableUI']) ? $variables['map_properties']['disableUI'] : FALSE,
    ],
  ], 'setting');
  drupal_add_js($js_path . 'vumain_campuses.js');
}

/**
 * Template preprocess: vumain_featured_success_story.
 */
function vumain_preprocess_vumain_featured_success_story(&$variables) {
  if (empty($variables['entity'])) {
    return NULL;
  }
  // Get the language.
  $lang = $variables['entity']->language;
  $image = $variables['entity']->field_image;
  $testimony = $variables['entity']->field_excerpt[$lang][0]['safe_value'];
  $person_name = $variables['entity']->field_person_name[$lang][0]['safe_value'];

  $success_story_image = [
    'style_name' => 'featured_success_story',
    'path' => $image[$lang][0]['uri'],
    'width' => '',
    'height' => '',
    'alt' => $image[$lang][0]['alt'],
    'title' => $image[$lang][0]['title'],
  ];
  $variables['node_link'] = drupal_get_path_alias('node/' . $variables['entity']->nid);
  $variables['image'] = theme('image_style', $success_story_image);
  $variables['person_name'] = $person_name;
  $variables['testimony'] = $testimony;
}

/**
 * Template preprocess: vumain_share_links.
 */
function vumain_preprocess_vumain_share_links(&$variables) {
  global $base_url;
  global $base_path;

  // Get the node.
  $node = isset($variables['node']) ? $variables['node'] : [];

  // If the node is not valid.
  if (empty($node)) {
    return;
  }

  // Build up the node URL.
  $node_url = $base_url . $base_path . drupal_get_path_alias('node/' . $node->nid);

  // Add variables to the template.
  $variables['encoded_title'] = urlencode($node->title);
  $variables['encoded_url'] = urlencode($node_url);
  $variables['encoded_source'] = urlencode(t('Victoria University - Melbourne Australia'));
  $variables['encoded_title_url'] = urlencode($node->title . ' ' . $node_url);
  $variables['node_type'] = $node->type;
  if ($node->type == 'events') {
    $variables['node_type'] = 'event';
  }
}

/**
 * Implements hook_theme_preprocess().
 */
function vumain_preprocess_topics_content_blocks(&$variables) {
  if (empty($variables['entities']) || !count($variables['entities'])) {
    return NULL;
  }
  $content_blocks = $variables['entities'];
  $items = [];
  $variables['additional_classes'] = '';

  foreach ($content_blocks as $content_block) {
    if (empty($content_block['entity'])) {
      continue;
    }
    $entity = $content_block['entity'];
    $lang = $entity->language;

    _vumain_get_inline_entity_basic_content($entity, $lang, $items, TRUE);

    if (!empty($entity->field_image[$lang][0]['fid'])) {
      $items[$entity->id]['content_class'] = 'col-md-6';

      // Add class for image position.
      $items[$entity->id]['push_class'] = FALSE;
      $items[$entity->id]['pull_class'] = FALSE;
      if (!empty($entity->field_image_position) && !empty($entity->field_image) && $entity->field_image_position[$lang][0]['value'] == 'left') {
        $items[$entity->id]['push_class'] = 'image-left col-md-push-6';
        $items[$entity->id]['pull_class'] = 'image-left col-md-pull-6';
      }

      // Convert file array to object to pass to file_view_file.
      $file = (object) $entity->field_image[$lang][0];

      $fid = $entity->field_image[$lang][0]['fid'];
      $file_mime = $entity->field_image[$lang][0]['filemime'];
      $file_title = $entity->field_image[$lang][0]['filename'];
      $file_url = file_create_url($entity->field_image[$lang][0]['uri']);

      if ($file_url != FALSE) {
        preg_match('/[\\?\\&]v=([^\\?\\&]+)/', $file_url, $matches);
        if (isset($matches[1])) {
          $items[$entity->id]['file_url'] = 'https://www.youtube.com/embed/' . $matches[1] . '?width=640&height=374&iframe=true';
        }
      }

      $items[$entity->id]['image'] = file_view_file($file, 'wysiwyg', $lang);
      if (!empty($variables['top_content'])) {
        // Set correct dimension for topic page header image preview.
        $items[$entity->id]['image']['#style_name'] = '430x160';
        $items[$entity->id]['content_class'] = '';
      }

      $items[$entity->id]['transcript'] = ($file_mime == MediaYouTubeStreamWrapper::getMimeType('')) ? l(t('!file_name !transcript', [
        '!file_name' => $file_title,
        '!transcript' => 'transcript',
      ]), url('file/' . $fid)) : '';

      $items[$entity->id]['caption'] = '';
      if (isset($entity->field_main_content_caption[$lang][0]['value'])) {
        $items[$entity->id]['caption'] = filter_xss_admin($entity->field_main_content_caption[$lang][0]['value']);
      }
    }
  }
  $variables['items'] = $items;
  if (!empty($variables['top_content'])) {
    // For top content, let's get the first value.
    // It's meant for video on header area of topic page.
    if (vu_core_is_leaders_in_sports_page()) {
      $variables['additional_classes'] = 'featured-leaders-in-sport-block';
    }
    $variables['items'] = [reset($items)];
  }
}

/**
 * Implements hook_theme_preprocess().
 */
function vumain_preprocess_topics_sidebar_content_blocks(&$variables) {
  if (empty($variables['entities']) || !count($variables['entities'])) {
    return NULL;
  }
  $sidebar_content_blocks = $variables['entities'];
  $items = [];

  foreach ($sidebar_content_blocks as $content_block) {
    if (empty($content_block['entity'])) {
      continue;
    }
    $entity = $content_block['entity'];
    $lang = $entity->language;
    if ($entity->type === 'topic_page_facts') {
      $block_class = 'sidebar--box-facts ' . $entity->fact_class;
    }
    else {
      $block_class = !empty($entity->field_block_style) ? 'sidebar-box--' . $entity->field_block_style[$lang][0]['value'] : '';
    }
    _vumain_get_inline_entity_basic_content($entity, $lang, $items);
    $items[$entity->id]['block_class'] = $block_class;
    $items[$entity->id]['hide_title'] = !empty($entity->field_hide_block_title) && $entity->field_hide_block_title[$lang][0]['value'] == 1 ? TRUE : FALSE;
  }
  $variables['items'] = $items;
}

/**
 * Processes inline entities and returns basic content (title,icon,content).
 *
 * @param object $entity
 *   Inline-entity object.
 * @param string $lang
 *   Entity language.
 * @param array $items
 *   The items array passed by reference.
 * @param bool $no_goto_prefix
 *   Don't append 'goto-' to link id if TRUE.
 */
function _vumain_get_inline_entity_basic_content($entity, $lang, array &$items, $no_goto_prefix = FALSE) {
  $hide_title = 0;
  if (!empty($entity->field_hide_block_title)) {
    $hide_title = isset($entity->field_hide_block_title[$lang][0]['value']) ? $entity->field_hide_block_title[$lang][0]['value'] : $hide_title;
  }
  if ($hide_title !== 1) {
    $items[$entity->id]['title'] = $entity->title;
    $items[$entity->id]['icon'] = !empty($entity->field_main_content_icon) ? $entity->field_main_content_icon[$lang][0]['value'] : '';
  }
  $items[$entity->id]['title_anchor_id'] = _vumain_onthispage_link_id($entity->title, $no_goto_prefix);
  if ($entity->type == 'block_reference') {
    if (empty($entity->field_block_reference[$lang][0]['moddelta'])) {
      $items[$entity->id]['content'] = '';
    }
    $block_reference = explode(':', $entity->field_block_reference[$lang][0]['moddelta']);

    // Block delta.
    $block_delta = $block_reference[1];

    // Get block type: a bean or a vumain block.
    $block_type = $block_reference[0];

    $block = module_invoke($block_type, 'block_view', $block_delta);
    $items[$entity->id]['content'] = !empty($block['content']) ? $block['content'] : '';
  }
  elseif ($entity->type == 'our_victories') {
    if (!empty($entity->field_success_story_entity)) {
      $render_content = '';
      foreach ($entity->field_success_story_entity[LANGUAGE_NONE] as $featured_success_story) {
        $variables['classes_array'][] = 'row';
        $target_id = $featured_success_story['target_id'];
        $entity_object = entity_load('inline_entities', [$target_id]);
        $render_array = entity_view('inline_entities', $entity_object, 'default');
        $render_content .= render($render_array);
      }
      $items[$entity->id]['content'] = $render_content;
    }
  }
  else {
    if (!empty($entity->field_topic_main_content[$lang][0]['value'])) {
      $content = check_markup($entity->field_topic_main_content[$lang][0]['value'], 'full_html');
      $content = token_replace($content);
    }
    else {
      $content = '';
    }
    $items[$entity->id]['content'] = $content;
  }
}

/**
 * Template preprocess: vumain_latest_testimonial.
 */
function vumain_preprocess_vumain_latest_testimonial(&$variables) {
  $output = '';

  // Get all course category options.
  $categories = _vumain_get_course_category_options();
  // Return a random value from the categories.
  $key = array_rand($categories);
  $category_name = $categories[$key];

  // Get the category term for the given name.
  $category_term = taxonomy_get_term_by_name($key, 'success_categories');

  if (!empty($category_term)) {
    $category_term = reset($category_term);
    $category_tid = $category_term->tid;

    // Get the latest 'Success Story' node for a given category.
    $success_story = _vumain_get_latest_success_story_by_category_tid($category_tid);

    if (!empty($success_story)) {
      $node_view = node_view($success_story, 'teaser');
      $output = drupal_render($node_view);
    }
  }

  // Add the variable/s to the template.
  $variables['category_name'] = $category_name;
  $variables['output'] = $output;
}
