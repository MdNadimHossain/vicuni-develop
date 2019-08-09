<?php

/**
 * @file
 * Paragraphs module integration.
 */

/**
 * Implements hook_paragraphs_item_access().
 */
function vu_core_paragraphs_item_access($entity, $op, $account) {
  if (!in_array($op, ['view', 'update', 'delete', 'create'], TRUE)) {
    // If there was no bundle to check against, or the $op was not one of the
    // supported ones, we return access denied.
    return PARAGRAPHS_ITEM_ACCESS_IGNORE;
  }

  // Find the non-paragraph parent entity.
  $current = $entity;
  while ('paragraphs_item' == $current->hostEntityType()) {
    $current = $current->hostEntity();
  }
  $parent = $current->hostEntity();

  // If parent is a node, pass through to `node_access`.
  if (isset($parent->nid)) {
    $node = $parent;
    // Update/Delete/Create access requires update access on the parent.
    $op = 'view' == $op ? $op : 'update';
    return node_access($op, $node, $account) ? PARAGRAPHS_ITEM_ACCESS_ALLOW : PARAGRAPHS_ITEM_ACCESS_DENY;
  }

  // Else, pass back to standard paragraphs permission system.
  return paragraphs_paragraphs_item_access($entity, $op, $account);
}

/**
 * Implements hook_vu_core_entity_load_TYPE_alter().
 */
function vu_core_vu_core_entity_load_paragraphs_item_alter(&$entities) {

  if (count($entities) === 1) {
    /** @var \ParagraphsItemEntity $entity */
    $entity = reset($entities);

    switch ($entity->bundle()) {

      case 'events':

        // Get sort arguments from paragraph.
        vu_core_paragraphs_item_set_args($entity, 'field_audience', 'vu_events');

        // Get more link destination from paragraph.
        vu_core_paragraphs_item_set_more_link($entity, 'field_more_link', 'vu_events');

        break;

      case 'featured_news_items':

        // Get more link destination from paragraph.
        vu_core_paragraphs_item_set_more_link($entity, 'field_more_button_link', 'vu_news');
        vu_core_paragraphs_item_set_args($entity, 'field_fn_featured_audience', 'vu_news');

        break;

      case 'course_browse':
        // Check if international version is enabled.
        $enabled = vu_core_extract_single_field_value($entity, 'paragraphs_item', 'field_international_links');
        if ($enabled) {
          $_SESSION['vu_course_browse_interational'] = $enabled;
        }
        break;
    }

    if ($entity->bundle() == 'important_dates') {
      $_SESSION['vu_important_dates']['args'][] = $entity->item_id;
    }
  }
}

/**
 * Handle more link button url.
 */
function vu_core_paragraphs_item_set_more_link($entity, $link_field, $component) {

  // Get more link destination from paragraph.
  $item = vu_core_extract_single_field_value($entity, 'paragraphs_item', $link_field, 'revision_id');
  if ($item) {
    $paragraph = paragraphs_item_revision_load($item);

    switch ($paragraph->bundle()) {
      case 'link_external':
        $_SESSION[$component]['more']['url'] = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_link_link', 'url');
        break;

      case 'link_internal':
        $_SESSION[$component]['more']['url'] = 'node/' . vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_node_entity_ref', 'target_id');
        break;
    }

    // Handle button text.
    $button_text = $paragraph->field_link_text;
    $button_text = $button_text[LANGUAGE_NONE][0]['value'];
    if ($button_text) {
      $_SESSION[$component]['btn_more_text'] = $button_text;
    }

  }

}

/**
 * Supply arguments to view from paragraph item taxonomy.
 */
function vu_core_paragraphs_item_set_args($entity, $taxonomy, $component) {

  $items = field_get_items('paragraphs_item', $entity, $taxonomy);
  if ($items) {
    $args = array_map(function ($item) {
      return $item['tid'];
    }, $items);
    $_SESSION[$component]['args'] = $args;
  }
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_alter(&$vars) {
  // Wrap Block reference paragraphs with an Anchor if applicable.
  // Note: Due to a timing issue, and time constraints for the delivery of this
  // feature, this can not be put in the Victory theme preprocess system as the
  // content appears to be already rendered by DS at that point.
  // Preprocess order should be adjusted and this should be re-homed.
  $paragraph = &$vars['elements']['#entity'];

  $field_name = '';
  switch ($paragraph->bundle()) {
    case 'bean_ref_paragraph':
      $field_name = 'field_bean_entity_ref';
      break;

    case 'node_ref_paragraph':
      $field_name = 'field_node_entity_ref';
      break;

    case "success_story":
      $field_name = "field_success_story";
      break;

    case "hero_banner_block":
      array_push($vars['classes_array'], 'js-parallax-container');
      break;

    case "key_summary_component":
      $key_summary_box_count = count($paragraph->field_key_summary_row[LANGUAGE_NONE]);
      array_push($vars['classes_array'], 'key-summary-field-' . $key_summary_box_count, 'section');
      $color = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_background_color', 'value');
      $top_style = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_on_top_styling', 'value');
      if ($color == 1) {
        array_push($vars['classes_array'], 'key-summary-bg-color-change');
      }
      if ($top_style == 1) {
        array_push($vars['classes_array'], 'key-summary-on-top');
      }
      break;

    case "wysiwyg":
      $paragraph = $vars['elements']['#entity'];
      $full_width_custom_style = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_full_width_styling');
      if ($full_width_custom_style) {
        array_push($vars['classes_array'], 'full-width-custom-style');
      }
      break;
  }

  if (!empty($field_name) && !empty($paragraph->{$field_name}[LANGUAGE_NONE][0]['entity'])) {
    $target = $paragraph->{$field_name}[LANGUAGE_NONE][0]['entity'];
    $fields = [];

    // This field will be used later in theme_preprocess_entity().
    $paragraph->referenced_entity_type = $target->type;

    // Support for various BEAN and NODE types,
    // just add a case and the specific fields below.
    switch ($target->type) {
      case 'choose_vu':
        $fields['link'] = 'field_choose_vu_link';
        $fields['title'] = 'title_field';
        break;

      case 'success_story':
        $fields['link'] = 'nid';
        $fields['title'] = 'field_featured_tile_text';
        break;
    }

    if (!empty($fields) && isset($fields['link']) && isset($target->{$fields['link']})) {
      $nid = is_array($target->{$fields['link']}) ? $target->{$fields['link']}[LANGUAGE_NONE][0]['target_id'] : $target->{$fields['link']};
      $attributes = ['title' => $target->title];
      if (isset($fields['title']) && isset($target->{$fields['title']})) {
        $language = count($target->{$fields['title']}) == 1 ? LANGUAGE_NONE : 'en';
        // Using decode_entities since a field may contain special characters.
        $attributes['title'] = decode_entities($target->{$fields['title']}[$language][0]['safe_value']);
      }
      $options = [
        'attributes' => $attributes,
        'html' => TRUE,
      ];
      $link = l(t('SPLIT'), 'node/' . $nid, $options);

      list($prefix, $suffix) = explode(t('SPLIT'), $link);

      $prefix = !empty($vars['content'][$field_name]['#prefix']) ? $vars['content'][$field_name]['#prefix'] . $prefix : $prefix;
      $vars['content'][$field_name]['#prefix'] = $prefix;

      $suffix = !empty($vars['content'][$field_name]['#suffix']) ? $suffix . $vars['content'][$field_name]['#suffix'] : $suffix;
      $vars['content'][$field_name]['#suffix'] = $suffix;

      // We can't have an anchor inside an anchor. It breaks the markup.
      if (!empty($vars['content'][$field_name][0]['node'])) {
        unset($vars['content'][$field_name][0]['node'][$nid]['#contextual_links']);
      }
    }
  }
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_system_alert_box_alter(&$vars) {
  $items = [
    'style' => 'field_alert_box_style',
    'title' => 'field_alert_title',
    'text' => 'field_alert_text',
    'icon' => 'field_link_icon',
  ];
  foreach ($items as $key => $value) {
    $vars[$key] = vu_core_extract_single_field_value($vars['paragraphs_item'], 'paragraphs_item', $value);
  }
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_page_intro_alter(&$vars) {
  $node = menu_get_object();

  switch ($node->nid) {
    case 10889101:
      $vars['content']['field_body'][0]['#markup'] .= theme('vumain_courses_list');
      break;

    case 10891681:
      $vars['content']['field_body'][0]['#markup'] .= views_embed_view('courses_lists', 'all_by_topic');
      break;
  }
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_feature_link_alter(&$vars) {
  $vars['content']['link_title'] = !empty($vars['content']['field_feature_link_title'][0]['#markup']) ? $vars['content']['field_feature_link_title'][0]['#markup'] : '';
  $paragraph = $vars['elements']['#entity'];
  // Get link.
  $link = '';
  if (isset($paragraph->field_feature_link[LANGUAGE_NONE][0]['value'])) {
    $feature_link_item = paragraphs_item_load($paragraph->field_feature_link[LANGUAGE_NONE][0]['value']);
    switch ($feature_link_item->bundle) {
      case 'internal_link':
        $link = isset($feature_link_item->field_node_entity_ref[LANGUAGE_NONE][0]['target_id']) ? url('node/' . $feature_link_item->field_node_entity_ref[LANGUAGE_NONE][0]['target_id']) : '';
        break;

      case 'external_link':
        $link = $feature_link_item->field_related_external_links[LANGUAGE_NONE][0]['url'] ?? '';
        break;
    }
  }
  $vars['content']['feature_link'] = $link;
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_quick_facts_alter(&$vars) {
  $paragraph = $vars['elements']['#entity'];
  $color = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_background_color', 'value');
  if ($color == 1) {
    array_push($vars['classes_array'], 'quick-fact-bg-color-change');
  }
  // Get link.
  $link = '';
  if (isset($paragraph->field_fact_links[LANGUAGE_NONE][0]['value'])) {
    $fact_link_item = paragraphs_item_load($paragraph->field_fact_links[LANGUAGE_NONE][0]['value']);
    switch ($fact_link_item->bundle) {
      case 'internal_link':
        $link = isset($fact_link_item->field_node_entity_ref[LANGUAGE_NONE][0]['target_id']) ? url('node/' . $fact_link_item->field_node_entity_ref[LANGUAGE_NONE][0]['target_id']) : '';
        break;

      case 'external_link':
        $link = $fact_link_item->field_related_external_links[LANGUAGE_NONE][0]['url'] ?? '';
        break;
    }
  }
  $vars['content']['quick_facts'] = $link;
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_course_search_alter(&$vars) {
  $paragraph = $vars['elements']['#entity'];
  $entity = $paragraph->field_course_search_int[LANGUAGE_NONE][0]['value'];
  // Checking if the Course Search International box checked
  // If checked then swap radio button in the course search block.
  if ($entity == 1) {
    drupal_add_js(
      drupal_get_path('module', 'vu_core') . '/js/vu_core.course_search_int.js',
      [
        'scope' => 'footer',
      ]
    );

  }

}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_accordion_alter(&$vars) {
  // Ensure that even if a Paragraph isn't provided, e.g., access to the DS
  // theme function directly, the variables are still correctly populated.
  $vars['accordion_id'] = 1;
  if (isset($vars['elements']['#entity'])) {
    $paragraph = &$vars['elements']['#entity'];
    $vars['accordion_id'] = $paragraph->item_id;
  }
  elseif (isset($vars['elements']['#accordion_id'])) {
    $vars['accordion_id'] = $vars['elements']['#accordion_id'];
  }

  if (isset($vars['elements']['#ds_content']) && isset($vars['elements']['#title'])) {
    $vars['title'] = $vars['elements']['#title'];
    $vars['ds_content'] = $vars['elements']['#ds_content'];
  }

  $vars['item_attributes_array'] = ['class' => ['accordion-inner']];
  $vars['content_attributes_array'] = ['class' => ['accordion-content', 'collapse']];

  // Open/Close button.
  $vars['icon'] = '';

  // Add custom accordion behavior js.
  drupal_add_js(drupal_get_path('module', 'vu_core') . '/js/vu_core.accordion.js');
}

/**
 * Implements hook_preprocess_HOOK().
 */
function vu_core_preprocess_bootstrap_accordion(&$vars) {
  vu_core_preprocess_entity_paragraphs_item_accordion_alter($vars);
}

/**
 * Implements hook_field_widget_form_alter().
 */
function vu_core_field_widget_paragraphs_embed_form_alter(&$element, &$form_state, $context) {
  if (!isset($context['field']['field_name'])) {
    return;
  }

  switch ($context['field']['field_name']) {
    case 'field_page_paragraphs':
      $langcode = $context['langcode'];
      $form = $context['form'];
      $field_name = $context['field']['field_name'];
      $field_state = field_form_get_state($form['#parents'], $field_name, $langcode, $form_state);
      $delta = $context['delta'];
      $type = $form['#node']->type;

      // If there are no items, add a default intro paragraph.
      if (empty($field_state['items_count'])) {
        // Get the host entity.
        $host_entity = $form['#entity'];
        $items = [];

        $bundle = ($type == 'staff_profile') ? 'section' : 'page_intro';
        /* @var $item ParagraphsItemEntity */
        $item = entity_create('paragraphs_item', [
          'field_name' => $field_name,
          'bundle' => $bundle,
        ]);

        $item->setHostEntity($element['#instance']['entity_type'], $host_entity, $langcode, FALSE);

        // Check entity access before adding item.
        if ($item && entity_access('create', 'paragraphs_item', $item)) {
          $items[]['entity'] = $item;
        }

        $original_element = [
          '#entity_type' => $element['#instance']['entity_type'],
          '#entity' => &$host_entity,
          '#bundle' => $host_entity->type,
          '#field_name' => $field_name,
          '#language' => $langcode,
          '#field_parents' => $form['#parents'],
          '#columns' => array_keys($field_state['field']['columns']),
          '#title' => '',
          '#description' => '',
          '#delta' => $delta,
          '#weight' => $delta,
        ];

        $items_count = count($items);

        $form_state['field'][$field_name][$langcode][]['entity'] = $item;
        $form_state['field'][$field_name][$langcode]['items_count'] = $items_count;
        $form_state['field'][$field_name][$langcode]['real_items_count'] = $items_count;

        $element = paragraphs_field_multiple_value_form($field_state['field'], $field_state['instance'], $langcode, $items, $form, $form_state, $delta, $original_element);
      }

      if ($type != "staff_profile") {
        // Remove the 'remove' button from the "Intro" section.
        $element[0]['actions']['remove_button']['#access'] = FALSE;
      }

      // Remove "Intro" section type for available section types.
      unset($element['add_more']['type']['#options']['page_intro']);
      if (count($element['add_more']['type']['#options']) == 1) {
        $element['add_more']['type']['#type'] = 'hidden';
        $keys = array_keys($element['add_more']['type']['#options']);
        $element['add_more']['type']['#value'] = $keys[0];
      }

      // Attach javascript behaviour to prevent dragability.
      $element['#attached']['js'][] = drupal_get_path('module', 'vu_core') . '/js/vu_core.page_builder.js';
      break;

  }
}

/**
 * Implements hook_preprocess_field_FIELD_NAME_alter().
 */
function vu_core_preprocess_field_field_video_transcript_alter(&$variables) {
  $element = &$variables['element'];
  if ($element['#view_mode'] != 'full') {
    // Replace text with a link to its entity page.
    $variables['items'][0]['#markup'] = l(t('@filename - Transcript', ['@filename' => $element['#object']->filename]), entity_uri('file', $element['#object'])['path'], ['html' => TRUE]);
  }
}

/**
 * Implements hook_preprocess_field_FIELD_NAME_alter().
 */
function vu_core_preprocess_field_field_section_title_alter(&$variables) {
  // Generate an ID string from the section title.
  $id = vu_core_title_id($variables['element']['#items'][0]['value'], 'preprocess');

  // Set ID via DS attribute config.
  $variables['ds-config']['fi-at'] .= " id='{$id}'";
}

/**
 * Implements hook_preprocess_field_FIELD_NAME_alter().
 */
function vu_core_preprocess_field_field_component_section_title_alter(&$variables) {
  // Generate an ID string from the Component section title.
  $id = vu_core_title_id($variables['element']['#items'][0]['value'], 'preprocess');

  // Set ID via DS attribute config.
  $variables['ds-config']['fi-at'] .= " id='{$id}'";
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_key_summary_box_alter(&$vars) {
  $paragraph = $vars['elements']['#entity'];

  // Get link.
  $link = '';
  $link_load = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_key_summary_link');
  if (isset($link_load)) {
    $key_link_item = paragraphs_item_load($link_load);
    switch ($key_link_item->bundle) {
      case 'internal_link':
        $internal_link = vu_core_extract_single_field_value($key_link_item, 'paragraphs_item', 'field_node_entity_ref', 'target_id');
        $link = isset($internal_link) ? url('node/' . $internal_link) : '';
        break;

      case 'external_link':
        $external_link = vu_core_extract_single_field_value($key_link_item, 'paragraphs_item', 'field_related_external_links', 'url');
        $link = $external_link ?? '';
        break;
    }
  }
  $vars['content']['key_summary_link'] = $link;
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_webforms_alter(&$variables) {
  $paragraph = $variables['elements']['#entity'];

  $hide_title = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_webform_hide_title');
  if (!$hide_title) {
    // Get title.
    $node = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_webform', 'entity');
    if (isset($node->title) && !empty($node->title)) {
      $variables['content']['field_webform']['#prefix'] = theme('html_tag', [
        'element' => [
          '#tag' => 'h2',
          '#value' => $node->title,
        ],
      ]);
    }
  }
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_map_component_alter(&$vars) {
  $paragraph = $vars['elements']['#entity']->field_map_component_row[LANGUAGE_NONE];

  // Switch view to full width.
  $location_count = count($paragraph);
  $vars['full_width'] = $vars['left_menu'] = FALSE;
  $host = $vars['elements']['#entity']->hostEntity();
  if ($host) {
    if (isset($host->field_row_components)) {
      $item_count = count(field_get_items('paragraphs_item', $host, 'field_row_components'));
      if ($item_count == 1) {
        $vars['full_width'] = TRUE;
        if ($location_count > 3) {
          // Switch view.
          $vars['left_menu'] = TRUE;
        }
      }
    }
  }

  foreach ($paragraph as $index => $map_para) {

    $item = paragraphs_item_load($map_para['value']);
    if (!$item) {
      return FALSE;
    }
    // Load details from campus if present.
    $campus_nid = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_campus', 'target_id');
    if (!empty($campus_nid)) {
      $campus = node_load($campus_nid);
      $location_details = vu_core_get_campus_location_details($campus);
      // Add campus building and room details.
      $location_details['campus_building'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_campus_building', 'value');
    }
    else {
      $location_details = vu_core_get_location_details($item);
    }

    // Don't add location if lat/long is not present.
    if (empty(array_filter($location_details['lat_long']))) {
      continue;
    }

    // Arrays to hold every value. - this as well.
    if (isset($location_details['lat_long'][0])) {
      foreach ($location_details['lat_long'] as $location) {
        $all_locations[] = [
          'address' => $location['address'],
          'lat' => $location['lat'],
          'long' => $location['long'],
          'title' => $location_details['place_name'],
        ];
      }
      $location_details['lat_long'] = $location_details['lat_long'][0];
    }
    else {
      $all_locations[] = [
        'address' => $location_details['address'],
        'lat' => $location_details['lat_long']['lat'],
        'long' => $location_details['lat_long']['long'],
        'title' => $location_details['place_name'],
      ];
    }

    $titles[] = theme('vu_map_locations', [
      'address' => $location_details['address'],
      'title' => $location_details['place_name'],
      'lat_long' => $location_details['lat_long']['lat'] . ',' . $location_details['lat_long']['long'],
      'position' => "position " . ($index + 1),
      'campus_building' => $location_details['campus_building'],
    ]);
  }

  $titles_list = theme('item_list', ['items' => $titles]);

  $vars['locations'] = $titles_list;
  $js_path = drupal_get_path('module', 'vumain') . '/js/';
  $google_maps_api_key = variable_get('google_maps_api_key', '');
  $google_maps_api = sprintf('<script type="text/javascript" src="//maps.googleapis.com/maps/api/js?key=%s&v=3.exp"></script>', $google_maps_api_key);
  $element = [
    '#type' => 'markup',
    '#markup' => $google_maps_api,
  ];

  // Add if not already present.
  if (strpos(drupal_get_html_head(), $google_maps_api) === FALSE) {
    drupal_add_html_head($element, 'vumain_google_maps_js');
  }

  drupal_add_js([
    'mapComponent' => [
      'map_marker' => '',
      'title' => $location_details['place_name'],
      'lat_long' => [],
      'zoom' => 15,
      'hide' => TRUE,
      'disableUI' => FALSE,
      'all_campuses' => $all_locations,
    ],
  ], 'setting');
  drupal_add_js($js_path . 'vumain_map_component.js');
}

/**
 * Get campus location details.
 */
function vu_core_get_campus_location_details($campus) {
  $location_details = vu_core_get_location_structure();

  if (!isset($campus->type)) {
    return $location_details;
  }

  $location = vumain_campus_get_location($campus, FALSE);
  $campus_alias = drupal_get_path_alias('node/' . $campus->nid);

  $campus_id = vumain_googlemaps_get_campus_id($campus_alias);
  if ($campus_id == VUMAIN_VU_CAMPUS_CITY_QUEEN) {
    $location_details['lat_long'] = vumain_campus_get_city_queen_locations();
  }

  if (!empty($location[0])) {
    $location = reset($location);
    $location_details['locality'] = $location['locality'];
    $location_details['thoroughfare'] = $location['thoroughfare'];
    $location_details['postal_code'] = $location['postal_code'];
    $location_details['administrative_area'] = $location['administrative_area'];
    $location_details['country'] = $location['country'];
  }

  $location_details['address'] = vu_core_get_location_address($location_details);
  $location_details['place_name'] = $campus->title . ' Campus';

  if (empty($location_details['lat_long']) && !empty($campus_alias)) {
    $details = vumain_campuses_get_lat_long($campus_alias);
    if (!empty($details)) {
      $location_details['lat_long'] = [
        'lat' => $details['lat'],
        'long' => $details['long'],
      ];
    }
  }

  return $location_details;
}

/**
 * Get location details.
 */
function vu_core_get_location_details($item = []) {
  $location_details = vu_core_get_location_structure();

  if (empty($item)) {
    return $location_details;
  }

  $location_details['country'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_address', 'country');
  $location_details['administrative_area'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_address', 'administrative_area');
  $location_details['locality'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_address', 'locality');
  $location_details['postal_code'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_address', 'postal_code');
  $location_details['thoroughfare'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_address', 'thoroughfare');
  // Indiavidual Variables.
  $location_details['place_name'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_place_name', 'safe_value');
  $location_details['address'] = vu_core_get_location_address($location_details);
  $location_details['longitude'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_longitude', 'safe_value');
  $location_details['latitude'] = vu_core_extract_single_field_value($item, 'paragraphs_item', 'field_location_latitude', 'safe_value');

  $location_details['lat_long'] = ['lat' => $location_details['latitude'], 'long' => $location_details['longitude']];

  return $location_details;
}

/**
 * Default settings structure.
 */
function vu_core_get_location_structure() {
  return [
    'lat_long' => '',
    'address' => '',
    'locality' => '',
    'postal_code' => '',
    'thoroughfare' => '',
    'place_name' => '',
    'administrative_area' => '',
    'country' => '',
    'campus_building' => '',
  ];
}

/**
 * Get location address.
 */
function vu_core_get_location_address($location_details = []) {
  return trim(implode(', ',
    [
      $location_details['thoroughfare'],
      $location_details['locality'],
      $location_details['postal_code'],
      $location_details['administrative_area'],
      $location_details['country'],
    ]
  ), ', ');
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_qflow_alter(&$vars) {

  $paragraph = $vars['elements']['#entity'];
  // Get link.
  $link = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_virtual_queue_link', 'url');
  $vars['virtual_queue_link'] = !empty($link) ? $link : '';

  $campus_nid = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_qflow_campus', 'target_id');
  if ($campus_nid) {
    // Get times from campus.
    $campus = node_load($campus_nid);
    $times = vu_core_get_campus_qflow_hours($campus);
  }
  else {
    // Get times from all campuses.
    $times = vu_core_get_qflow_hours();
  }

  // Get current chat state for provided time config.
  $qflow_state = _vu_chat_now_get_chat_state($times);
  $vars['is_open'] = $qflow_state['is_open'];

  drupal_add_js(libraries_get_path('moment') . '/min/moment-with-locales.min.js', ['weight' => -2]);
  drupal_add_js(libraries_get_path('moment-timezone') . '/builds/moment-timezone-with-data.min.js', ['weight' => -1]);
  drupal_add_js(drupal_get_path('module', 'vu_chat_now') . '/js/vu_qflow.js');
  drupal_add_js(['vu_qflow' => $qflow_state + ['times' => $times]], 'setting');

}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_small_logo_alter(&$vars) {
  $paragraph = $vars['elements']['#entity'];

  // Get link.
  $link = '';
  $link_load = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_small_logo_link');
  if (!empty($link_load)) {
    $link_item = paragraphs_item_load($link_load);
    switch ($link_item->bundle) {
      case 'internal_link':
        $internal_link = vu_core_extract_single_field_value($link_item, 'paragraphs_item', 'field_node_entity_ref', 'target_id');
        $link = isset($internal_link) ? url('node/' . $internal_link) : '';
        break;

      case 'external_link':
        $external_link = vu_core_extract_single_field_value($link_item, 'paragraphs_item', 'field_related_external_links', 'url');
        $link = $external_link ?? '';
        break;
    }
  }
  $vars['content']['small_logo_link'] = $link;
}

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_core_preprocess_entity_paragraphs_item_large_logo_alter(&$vars) {
  $paragraph = $vars['elements']['#entity'];

  // Get link.
  $link = '';
  $link_load = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_large_logo_link');
  if (!empty($link_load)) {
    $link_item = paragraphs_item_load($link_load);
    switch ($link_item->bundle) {
      case 'internal_link':
        $internal_link = vu_core_extract_single_field_value($link_item, 'paragraphs_item', 'field_node_entity_ref', 'target_id');
        $link = isset($internal_link) ? url('node/' . $internal_link) : '';
        break;

      case 'external_link':
        $external_link = vu_core_extract_single_field_value($link_item, 'paragraphs_item', 'field_related_external_links', 'url');
        $link = $external_link ?? '';
        break;
    }
  }
  $vars['content']['large_logo_link'] = $link;
}
