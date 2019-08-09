<?php
/**
 * @file
 * vu_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vu_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "fieldable_panels_panes" && $api == "fieldable_panels_pane_type") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_entityqueue_api().
 */
function vu_core_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vu_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_custom_pub_defaults().
 */
function vu_core_custom_pub_defaults() {
  $options = array();
  // Exported option: do_not_store_submission_data
  $options['do_not_store_submission_data'] = array(
    'type' => 'do_not_store_submission_data',
    'name' => t('Do not store submission data'),
    'node_types' => array(
      'webform' => t('Webform'),
    ),
  );

  // Exported option: promote
  $options['promote'] = array(
    'type' => 'promote',
    'name' => t('Promoted to front page'),
    'node_types' => array(
      'news' => t('News & Media'),
      'events' => t('Events'),
    ),
  );

  // Exported option: sticky
  $options['sticky'] = array(
    'type' => 'sticky',
    'name' => t('Sticky at top of lists'),
    'node_types' => array(
      'news' => t('News & Media'),
      'events' => t('Events'),
    ),
  );

  return $options;
}

/**
 * Implements hook_eck_bundle_info().
 */
function vu_core_eck_bundle_info() {
  $items = array(
    'accordion_item_accordion_item' => array(
      'machine_name' => 'accordion_item_accordion_item',
      'entity_type' => 'accordion_item',
      'name' => 'accordion_item',
      'label' => 'Accordion Item',
      'config' => array(),
    ),
    'contact_information_contact_information' => array(
      'machine_name' => 'contact_information_contact_information',
      'entity_type' => 'contact_information',
      'name' => 'contact_information',
      'label' => 'Contact Information',
      'config' => array(
        'managed_properties' => array(
          'contact_name' => 'contact_name',
          'uid' => 0,
          'created' => 0,
          'changed' => 0,
          'language' => 0,
        ),
      ),
    ),
    'inline_entities_accordion_section' => array(
      'machine_name' => 'inline_entities_accordion_section',
      'entity_type' => 'inline_entities',
      'name' => 'accordion_section',
      'label' => 'Accordion Section',
      'config' => array(),
    ),
    'inline_entities_basic_body_text' => array(
      'machine_name' => 'inline_entities_basic_body_text',
      'entity_type' => 'inline_entities',
      'name' => 'basic_body_text',
      'label' => 'Basic Body Text',
      'config' => array(),
    ),
    'inline_entities_block_reference' => array(
      'machine_name' => 'inline_entities_block_reference',
      'entity_type' => 'inline_entities',
      'name' => 'block_reference',
      'label' => 'Block reference',
      'config' => array(),
    ),
    'inline_entities_course_date_time' => array(
      'machine_name' => 'inline_entities_course_date_time',
      'entity_type' => 'inline_entities',
      'name' => 'course_date_time',
      'label' => 'Course dates and times',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
          'language' => 0,
        ),
        'multilingual' => 0,
      ),
    ),
    'inline_entities_featured_content' => array(
      'machine_name' => 'inline_entities_featured_content',
      'entity_type' => 'inline_entities',
      'name' => 'featured_content',
      'label' => 'Featured Content',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'language' => 'language',
          'created' => 0,
        ),
      ),
    ),
    'inline_entities_featured_success_story' => array(
      'machine_name' => 'inline_entities_featured_success_story',
      'entity_type' => 'inline_entities',
      'name' => 'featured_success_story',
      'label' => 'Featured Success Story',
      'config' => array(),
    ),
    'inline_entities_link_redirects' => array(
      'machine_name' => 'inline_entities_link_redirects',
      'entity_type' => 'inline_entities',
      'name' => 'link_redirects',
      'label' => 'Link Redirects',
      'config' => array(),
    ),
    'inline_entities_location' => array(
      'machine_name' => 'inline_entities_location',
      'entity_type' => 'inline_entities',
      'name' => 'location',
      'label' => 'Location',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
          'language' => 0,
        ),
      ),
    ),
    'inline_entities_our_victories' => array(
      'machine_name' => 'inline_entities_our_victories',
      'entity_type' => 'inline_entities',
      'name' => 'our_victories',
      'label' => 'Our victories',
      'config' => array(),
    ),
    'inline_entities_related_links' => array(
      'machine_name' => 'inline_entities_related_links',
      'entity_type' => 'inline_entities',
      'name' => 'related_links',
      'label' => 'Related Links',
      'config' => array(),
    ),
    'inline_entities_topic_page_content' => array(
      'machine_name' => 'inline_entities_topic_page_content',
      'entity_type' => 'inline_entities',
      'name' => 'topic_page_content',
      'label' => 'Topic page content',
      'config' => array(),
    ),
    'inline_entities_topic_page_facts' => array(
      'machine_name' => 'inline_entities_topic_page_facts',
      'entity_type' => 'inline_entities',
      'name' => 'topic_page_facts',
      'label' => 'Topic Page Facts',
      'config' => array(),
    ),
    'inline_entities_topic_page_sidebar_content' => array(
      'machine_name' => 'inline_entities_topic_page_sidebar_content',
      'entity_type' => 'inline_entities',
      'name' => 'topic_page_sidebar_content',
      'label' => 'Topic page sidebar content',
      'config' => array(),
    ),
    'intake_intake' => array(
      'machine_name' => 'intake_intake',
      'entity_type' => 'intake',
      'name' => 'intake',
      'label' => 'Intake',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function vu_core_eck_entity_type_info() {
  $items = array(
    'accordion_item' => array(
      'name' => 'accordion_item',
      'label' => 'Accordion Item',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
    'contact_information' => array(
      'name' => 'contact_information',
      'label' => 'Contact Information',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
        'contact_name' => array(
          'label' => 'Contact Name',
          'type' => 'text',
          'behavior' => 'plain_title',
        ),
      ),
    ),
    'inline_entities' => array(
      'name' => 'inline_entities',
      'label' => 'Inline Entities',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
    'intake' => array(
      'name' => 'intake',
      'label' => 'Intake',
      'properties' => array(
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function vu_core_fontyourface_features_default_font() {
  return array(
    'Futura PT Book' => array(
      'name' => 'Futura PT Book',
      'enabled' => 1,
      'url' => 'http://typekit.com/fonts/futura-pt#n4',
      'provider' => 'typekit_api',
      'css_selector' => NULL,
      'css_family' => '\'futura-pt\'',
      'css_style' => 'normal',
      'css_weight' => 400,
      'css_fallbacks' => '',
      'foundry' => 'ParaType',
      'foundry_url' => 'http://typekit.com/foundries/paratype',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:3:{s:10:"typekit_id";s:7:"ftnk:n4";s:7:"variant";s:6:"normal";s:3:"kit";s:7:"vnw2lhd";}',
    ),
    'Futura PT Condensed Bold' => array(
      'name' => 'Futura PT Condensed Bold',
      'enabled' => 1,
      'url' => 'http://typekit.com/fonts/futura-pt-condensed#n7',
      'provider' => 'typekit_api',
      'css_selector' => NULL,
      'css_family' => '\'futura-pt-condensed\'',
      'css_style' => 'normal',
      'css_weight' => 700,
      'css_fallbacks' => '',
      'foundry' => 'ParaType',
      'foundry_url' => 'http://typekit.com/foundries/paratype',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:3:{s:10:"typekit_id";s:7:"jxkf:n7";s:7:"variant";s:6:"normal";s:3:"kit";s:7:"vnw2lhd";}',
    ),
    'Futura PT Condensed Book' => array(
      'name' => 'Futura PT Condensed Book',
      'enabled' => 1,
      'url' => 'http://typekit.com/fonts/futura-pt-condensed#n4',
      'provider' => 'typekit_api',
      'css_selector' => NULL,
      'css_family' => '\'futura-pt-condensed\'',
      'css_style' => 'normal',
      'css_weight' => 400,
      'css_fallbacks' => '',
      'foundry' => 'ParaType',
      'foundry_url' => 'http://typekit.com/foundries/paratype',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:3:{s:10:"typekit_id";s:7:"jxkf:n4";s:7:"variant";s:6:"normal";s:3:"kit";s:7:"vnw2lhd";}',
    ),
    'Futura PT Condensed Extra Bold' => array(
      'name' => 'Futura PT Condensed Extra Bold',
      'enabled' => 1,
      'url' => 'http://typekit.com/fonts/futura-pt-condensed#n8',
      'provider' => 'typekit_api',
      'css_selector' => NULL,
      'css_family' => '\'futura-pt-condensed\'',
      'css_style' => 'normal',
      'css_weight' => 800,
      'css_fallbacks' => '',
      'foundry' => 'ParaType',
      'foundry_url' => 'http://typekit.com/foundries/paratype',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:3:{s:10:"typekit_id";s:7:"jxkf:n8";s:7:"variant";s:6:"normal";s:3:"kit";s:7:"vnw2lhd";}',
    ),
    'Futura PT Light' => array(
      'name' => 'Futura PT Light',
      'enabled' => 1,
      'url' => 'http://typekit.com/fonts/futura-pt#n3',
      'provider' => 'typekit_api',
      'css_selector' => NULL,
      'css_family' => '\'futura-pt\'',
      'css_style' => 'normal',
      'css_weight' => 300,
      'css_fallbacks' => '',
      'foundry' => 'ParaType',
      'foundry_url' => 'http://typekit.com/foundries/paratype',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:3:{s:10:"typekit_id";s:7:"ftnk:n3";s:7:"variant";s:6:"normal";s:3:"kit";s:7:"vnw2lhd";}',
    ),
    'Futura PT Medium' => array(
      'name' => 'Futura PT Medium',
      'enabled' => 1,
      'url' => 'http://typekit.com/fonts/futura-pt#n5',
      'provider' => 'typekit_api',
      'css_selector' => NULL,
      'css_family' => '\'futura-pt\'',
      'css_style' => 'normal',
      'css_weight' => 500,
      'css_fallbacks' => '',
      'foundry' => 'ParaType',
      'foundry_url' => 'http://typekit.com/foundries/paratype',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:3:{s:10:"typekit_id";s:7:"ftnk:n5";s:7:"variant";s:6:"normal";s:3:"kit";s:7:"vnw2lhd";}',
    ),
  );
}

/**
 * Implements hook_image_default_styles().
 */
function vu_core_image_default_styles() {
  $styles = array();

  // Exported image style: 100x56.
  $styles['100x56'] = array(
    'label' => '100x56',
    'effects' => array(
      4 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 56,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 220w.
  $styles['220w'] = array(
    'label' => '220w',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 300x160.
  $styles['300x160'] = array(
    'label' => '300x160',
    'effects' => array(
      5 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 160,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 365w.
  $styles['365w'] = array(
    'label' => '365w',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 365,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 430x160.
  $styles['430x160'] = array(
    'label' => '430x160',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 430,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 464x262.
  $styles['464x262'] = array(
    'label' => '464x262',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 464,
          'height' => 262,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => 79,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 660w.
  $styles['660w'] = array(
    'label' => '660w',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 660,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 978x500.
  $styles['978x500'] = array(
    'label' => '978x500',
    'effects' => array(
      8 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 978,
          'height' => 500,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: audience_landing_tile__290x280_.
  $styles['audience_landing_tile__290x280_'] = array(
    'label' => 'Audience landing tile (290x280)',
    'effects' => array(
      1 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 290,
          'height' => 280,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image.
  $styles['background_image'] = array(
    'label' => 'background_image',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_theme_victory_lg_1x.
  $styles['background_image_breakpoints_theme_victory_lg_1x'] = array(
    'label' => 'background_image_breakpoints_theme_victory_lg_1x',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1920,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_theme_victory_md_1x.
  $styles['background_image_breakpoints_theme_victory_md_1x'] = array(
    'label' => 'background_image_breakpoints_theme_victory_md_1x',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_theme_victory_sm_1x.
  $styles['background_image_breakpoints_theme_victory_sm_1x'] = array(
    'label' => 'background_image_breakpoints_theme_victory_sm_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1024,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_theme_victory_xl_1x.
  $styles['background_image_breakpoints_theme_victory_xl_1x'] = array(
    'label' => 'background_image_breakpoints_theme_victory_xl_1x',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2048,
          'height' => 600,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_theme_victory_xxl_1x.
  $styles['background_image_breakpoints_theme_victory_xxl_1x'] = array(
    'label' => 'background_image_breakpoints_theme_victory_xxl_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2560,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_theme_victory_xxxl_1x.
  $styles['background_image_breakpoints_theme_victory_xxxl_1x'] = array(
    'label' => 'background_image_breakpoints_theme_victory_xxxl_1x',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2880,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: background_image_breakpoints_victory_custom_xl_1x.
  $styles['background_image_breakpoints_victory_custom_xl_1x'] = array(
    'label' => 'background_image_breakpoints_victory_custom_xl_1x',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2048,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: campus_image_225w.
  $styles['campus_image_225w'] = array(
    'label' => 'Campus image (225w)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 225,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_12.
  $styles['col_12'] = array(
    'label' => 'Bootstrap Column 12',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 767,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_12_breakpoints_theme_victory_sm_1x.
  $styles['col_12_breakpoints_theme_victory_sm_1x'] = array(
    'label' => 'Bootstrap Column 12 - Small',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 999,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_12_breakpoints_theme_victory_xl_1x.
  $styles['col_12_breakpoints_theme_victory_xl_1x'] = array(
    'label' => 'Bootstrap Column 12 - XL',
    'effects' => array(
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_3_thumbnail.
  $styles['col_3_thumbnail'] = array(
    'label' => 'col_3_thumbnail',
    'effects' => array(
      29 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 368,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_3_thumbnail_breakpoints_theme_victory_lg_1x.
  $styles['col_3_thumbnail_breakpoints_theme_victory_lg_1x'] = array(
    'label' => 'col_3_thumbnail_breakpoints_theme_victory_lg_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 120,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: col_3_thumbnail_breakpoints_theme_victory_md_1x.
  $styles['col_3_thumbnail_breakpoints_theme_victory_md_1x'] = array(
    'label' => 'col_3_thumbnail_breakpoints_theme_victory_md_1x',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 212.5,
          'height' => 120,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: col_3_thumbnail_breakpoints_theme_victory_sm_1x.
  $styles['col_3_thumbnail_breakpoints_theme_victory_sm_1x'] = array(
    'label' => 'col_3_thumbnail_breakpoints_theme_victory_sm_1x',
    'effects' => array(
      4 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 154.5,
          'height' => 120,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: col_3_thumbnail_breakpoints_theme_victory_xl_1x.
  $styles['col_3_thumbnail_breakpoints_theme_victory_xl_1x'] = array(
    'label' => 'col_3_thumbnail_breakpoints_theme_victory_xl_1x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_4.
  $styles['col_4'] = array(
    'label' => 'Bootstrap Column 4',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 767,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_4_breakpoints_theme_victory_lg_1x.
  $styles['col_4_breakpoints_theme_victory_lg_1x'] = array(
    'label' => 'Bootstrap Column 4 - Large',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 370,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_4_breakpoints_theme_victory_md_1x.
  $styles['col_4_breakpoints_theme_victory_md_1x'] = array(
    'label' => 'Bootstrap Column 4 - Medium',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 293,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: col_4_breakpoints_theme_victory_sm_1x.
  $styles['col_4_breakpoints_theme_victory_sm_1x'] = array(
    'label' => 'Bootstrap Column 4 - Small',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 277,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: course_banner_breakpoints_theme_victory_lg_1x.
  $styles['course_banner_breakpoints_theme_victory_lg_1x'] = array(
    'label' => 'course_banner_breakpoints_theme_victory_lg_1x',
    'effects' => array(
      10 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 660,
          'height' => 345,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: course_banner_breakpoints_theme_victory_md_1x.
  $styles['course_banner_breakpoints_theme_victory_md_1x'] = array(
    'label' => 'course_banner_breakpoints_theme_victory_md_1x',
    'effects' => array(
      9 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 615,
          'height' => 345,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: course_banner_breakpoints_theme_victory_sm_1x.
  $styles['course_banner_breakpoints_theme_victory_sm_1x'] = array(
    'label' => 'course_banner_breakpoints_theme_victory_sm_1x',
    'effects' => array(
      8 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 525,
          'height' => 345,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_link_768x430.
  $styles['featured_link_768x430'] = array(
    'label' => 'Featured link (768x430)',
    'effects' => array(
      8 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 430,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => 100,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_square_250.
  $styles['featured_square_250'] = array(
    'label' => 'Featured square (250x250)',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_success_story.
  $styles['featured_success_story'] = array(
    'label' => 'Featured Success Story',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 613,
          'height' => 444,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: full_width_at_small_breakpoint.
  $styles['full_width_at_small_breakpoint'] = array(
    'label' => 'Full width @ small breakpoint ',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 737,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_featured_content.
  $styles['homepage_featured_content'] = array(
    'label' => 'Homepage Featured Content',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 978,
          'height' => 460,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_news_360x160.
  $styles['homepage_news_360x160'] = array(
    'label' => 'Homepage news 360x160',
    'effects' => array(
      7 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 160,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: large_featured_content.
  $styles['large_featured_content'] = array(
    'label' => 'Large featured content',
    'effects' => array(
      2 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 464,
          'height' => 262,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: large_logo__350w.
  $styles['large_logo__350w'] = array(
    'label' => 'Large Logo 350w',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: level_1_tiles_293x215.
  $styles['level_1_tiles_293x215'] = array(
    'label' => '293x215',
    'effects' => array(
      10 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 293,
          'height' => 215,
          'focal_point_advanced' => array(
            'shift_x' => -146,
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: news_homepage_block_470x268.
  $styles['news_homepage_block_470x268'] = array(
    'label' => 'News homepage block (470x268)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 470,
          'height' => 268,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: news_listing_page_100x56.
  $styles['news_listing_page_100x56'] = array(
    'label' => 'News listing page (100x56)',
    'effects' => array(
      8 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 56,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: small_featured_content.
  $styles['small_featured_content'] = array(
    'label' => 'Small featured content',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 56,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: small_logo__150w.
  $styles['small_logo__150w'] = array(
    'label' => 'Small Logo 150w',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: staff_detail_picture_350w.
  $styles['staff_detail_picture_350w'] = array(
    'label' => 'Staff Detail Picture (350w)',
    'effects' => array(
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: staff_profile_thumbnail.
  $styles['staff_profile_thumbnail'] = array(
    'label' => 'Staff Profile Thumbnail (100w)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: success_story.
  $styles['success_story'] = array(
    'label' => 'Success story',
    'effects' => array(
      7 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 430,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => 100,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: success_story_md.
  $styles['success_story_md'] = array(
    'label' => 'Success story md',
    'effects' => array(
      9 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 277.5,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => 100,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: youtube_preview.
  $styles['youtube_preview'] = array(
    'label' => 'Youtube Preview (300x200)',
    'effects' => array(
      7 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 270,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => -10,
      ),
      5 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 300,
          'height' => 200,
          'anchor' => 'center-center',
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_menu_position_default_menu_positions().
 */
function vu_core_menu_position_default_menu_positions() {
  $items = array(
    'courses_secondary_nav' => array(
      'admin_title' => 'courses_secondary_nav',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:7:"courses";s:7:"courses";}}}',
      'menu_name' => 'main-menu',
      'plid' => 2664551,
      'mlid' => 2646425,
      'weight' => 0,
      'machine_name' => 'courses_secondary_nav',
    ),
    'events_breadcrumbs' => array(
      'admin_title' => 'events_breadcrumbs',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:29:"about-vu/news-events/events/*";}}',
      'menu_name' => 'main-menu',
      'plid' => 2644541,
      'mlid' => 2673014,
      'weight' => 0,
      'machine_name' => 'events_breadcrumbs',
    ),
    'international_courses_secondary_nav' => array(
      'admin_title' => 'international_courses_secondary_nav',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:23:"courses/international/*";}}',
      'menu_name' => 'main-menu',
      'plid' => 2664551,
      'mlid' => 2647677,
      'weight' => 0,
      'machine_name' => 'international_courses_secondary_nav',
    ),
    'media_breadcrumbs' => array(
      'admin_title' => 'media_breadcrumbs',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:37:"about-vu/news-events/media-releases/*";}}',
      'menu_name' => 'main-menu',
      'plid' => 2644651,
      'mlid' => 2671666,
      'weight' => 0,
      'machine_name' => 'media_breadcrumbs',
    ),
    'news_breadcrumbs' => array(
      'admin_title' => 'news_breadcrumbs',
      'enabled' => 1,
      'conditions' => 'a:1:{s:5:"pages";a:1:{s:5:"pages";s:27:"about-vu/news-events/news/*";}}',
      'menu_name' => 'main-menu',
      'plid' => 2644516,
      'mlid' => 2670363,
      'weight' => 0,
      'machine_name' => 'news_breadcrumbs',
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function vu_core_node_info() {
  $items = array(
    'campus' => array(
      'name' => t('Campus'),
      'base' => 'node_content',
      'description' => t('A template for campus pages with map, metlink journey planner integration, and driving directions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'campus_housing' => array(
      'name' => t('Campus Housing'),
      'base' => 'node_content',
      'description' => t('A content type for campus housing.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'course_fees' => array(
      'name' => t('Course Fees'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'courses' => array(
      'name' => t('Courses'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'events' => array(
      'name' => t('Events'),
      'base' => 'node_content',
      'description' => t('This content type is for VU events'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News & Media'),
      'base' => 'node_content',
      'description' => t('This is for News Stories and Media Releases.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page_builder' => array(
      'name' => t('Page Builder'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'staff_profile' => array(
      'name' => t('Staff Profile'),
      'base' => 'node_content',
      'description' => t('For staff profiles.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'study_topic_area' => array(
      'name' => t('Study topic or area'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'success_story' => array(
      'name' => t('Success Story'),
      'base' => 'node_content',
      'description' => t('For success stories'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'topic_pages' => array(
      'name' => t('Topic Pages'),
      'base' => 'node_content',
      'description' => t('A jump page to link to different areas of the site that deal with a high-level topic e.g. sport.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'unit' => array(
      'name' => t('Unit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'unit_fees' => array(
      'name' => t('Unit Fees'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'unit_set' => array(
      'name' => t('Unit Set'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function vu_core_paragraphs_info() {
  $items = array(
    'accordion' => array(
      'name' => 'Accordion',
      'bundle' => 'accordion',
      'locked' => '1',
    ),
    'bean_ref_paragraph' => array(
      'name' => 'BEAN reference',
      'bundle' => 'bean_ref_paragraph',
      'locked' => '1',
    ),
    'block_ref_paragraph' => array(
      'name' => 'Block reference',
      'bundle' => 'block_ref_paragraph',
      'locked' => '1',
    ),
    'campus' => array(
      'name' => 'Campus',
      'bundle' => 'campus',
      'locked' => '1',
    ),
    'campus_maps' => array(
      'name' => 'Campus Maps',
      'bundle' => 'campus_maps',
      'locked' => '1',
    ),
    'chat_box' => array(
      'name' => 'Chat Box',
      'bundle' => 'chat_box',
      'locked' => '1',
    ),
    'component_row' => array(
      'name' => 'Component row',
      'bundle' => 'component_row',
      'locked' => '1',
    ),
    'component_section' => array(
      'name' => 'Component section',
      'bundle' => 'component_section',
      'locked' => '1',
    ),
    'course_browse' => array(
      'name' => 'Course browse',
      'bundle' => 'course_browse',
      'locked' => '1',
    ),
    'course_search' => array(
      'name' => 'Course search',
      'bundle' => 'course_search',
      'locked' => '1',
    ),
    'events' => array(
      'name' => 'Events',
      'bundle' => 'events',
      'locked' => '1',
    ),
    'existing_event' => array(
      'name' => 'Existing Event',
      'bundle' => 'existing_event',
      'locked' => '1',
    ),
    'external_link' => array(
      'name' => 'Feature Link: External',
      'bundle' => 'external_link',
      'locked' => '1',
    ),
    'feature_link' => array(
      'name' => 'Feature Link',
      'bundle' => 'feature_link',
      'locked' => '1',
    ),
    'featured_news_items' => array(
      'name' => 'Featured news items',
      'bundle' => 'featured_news_items',
      'locked' => '1',
    ),
    'fee_calculator' => array(
      'name' => 'Fee Calculator',
      'bundle' => 'fee_calculator',
      'locked' => '1',
    ),
    'fee_calculator_link_dom' => array(
      'name' => 'Fee Calculator Link - Domestic',
      'bundle' => 'fee_calculator_link_dom',
      'locked' => '1',
    ),
    'fee_calculator_link_int' => array(
      'name' => 'Fee Calculator Link - International',
      'bundle' => 'fee_calculator_link_int',
      'locked' => '1',
    ),
    'find_media_expert' => array(
      'name' => 'Find media expert',
      'bundle' => 'find_media_expert',
      'locked' => '1',
    ),
    'hero_banner_block' => array(
      'name' => 'Hero Banner Section',
      'bundle' => 'hero_banner_block',
      'locked' => '1',
    ),
    'hero_banner_reference' => array(
      'name' => 'Hero Banner Reference',
      'bundle' => 'hero_banner_reference',
      'locked' => '1',
    ),
    'image' => array(
      'name' => 'Image',
      'bundle' => 'image',
      'locked' => '1',
    ),
    'image_background' => array(
      'name' => 'Background image',
      'bundle' => 'image_background',
      'locked' => '1',
    ),
    'important_dates' => array(
      'name' => 'Important Dates',
      'bundle' => 'important_dates',
      'locked' => '1',
    ),
    'internal_link' => array(
      'name' => 'Feature Link: Internal',
      'bundle' => 'internal_link',
      'locked' => '1',
    ),
    'key_summary_box' => array(
      'name' => 'Key summary box',
      'bundle' => 'key_summary_box',
      'locked' => '1',
    ),
    'key_summary_component' => array(
      'name' => 'Key summary component',
      'bundle' => 'key_summary_component',
      'locked' => '1',
    ),
    'large_logo' => array(
      'name' => 'Large Logo',
      'bundle' => 'large_logo',
      'locked' => '1',
    ),
    'large_logos' => array(
      'name' => 'Logo - large',
      'bundle' => 'large_logos',
      'locked' => '1',
    ),
    'library_opening_hours' => array(
      'name' => 'Library Opening Hours',
      'bundle' => 'library_opening_hours',
      'locked' => '1',
    ),
    'library_search' => array(
      'name' => 'Library search',
      'bundle' => 'library_search',
      'locked' => '1',
    ),
    'link_external' => array(
      'name' => 'External',
      'bundle' => 'link_external',
      'locked' => '1',
    ),
    'link_internal' => array(
      'name' => 'Internal',
      'bundle' => 'link_internal',
      'locked' => '1',
    ),
    'link_phone_number' => array(
      'name' => 'Link: Phone number (international format)',
      'bundle' => 'link_phone_number',
      'locked' => '1',
    ),
    'map_component' => array(
      'name' => 'Map Component',
      'bundle' => 'map_component',
      'locked' => '1',
    ),
    'map_location_details' => array(
      'name' => 'Map Location Details',
      'bundle' => 'map_location_details',
      'locked' => '1',
    ),
    'new_event' => array(
      'name' => 'New Event',
      'bundle' => 'new_event',
      'locked' => '1',
    ),
    'node_ref_paragraph' => array(
      'name' => 'Node reference',
      'bundle' => 'node_ref_paragraph',
      'locked' => '1',
    ),
    'page_intro' => array(
      'name' => 'Intro',
      'bundle' => 'page_intro',
      'locked' => '1',
    ),
    'promo_banner' => array(
      'name' => 'Promo Banner',
      'bundle' => 'promo_banner',
      'locked' => '1',
    ),
    'qflow' => array(
      'name' => 'QFlow',
      'bundle' => 'qflow',
      'locked' => '1',
    ),
    'qflow_hours' => array(
      'name' => 'QFlow hours',
      'bundle' => 'qflow_hours',
      'locked' => '1',
    ),
    'quick_facts' => array(
      'name' => 'Quick Facts',
      'bundle' => 'quick_facts',
      'locked' => '1',
    ),
    'related_links' => array(
      'name' => 'Related links',
      'bundle' => 'related_links',
      'locked' => '1',
    ),
    'section' => array(
      'name' => 'Page section',
      'bundle' => 'section',
      'locked' => '1',
    ),
    'small_logo' => array(
      'name' => 'Small Logo',
      'bundle' => 'small_logo',
      'locked' => '1',
    ),
    'small_logos' => array(
      'name' => 'Logo - small',
      'bundle' => 'small_logos',
      'locked' => '1',
    ),
    'success_story' => array(
      'name' => 'Success story',
      'bundle' => 'success_story',
      'locked' => '1',
    ),
    'system_alert_box' => array(
      'name' => 'System alert box',
      'bundle' => 'system_alert_box',
      'locked' => '1',
    ),
    'video' => array(
      'name' => 'Video',
      'bundle' => 'video',
      'locked' => '1',
    ),
    'webforms' => array(
      'name' => 'Webform',
      'bundle' => 'webforms',
      'locked' => '1',
    ),
    'wysiwyg' => array(
      'name' => 'Basic text',
      'bundle' => 'wysiwyg',
      'locked' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function vu_core_default_search_api_index() {
  $items = array();
  $items['course_index'] = entity_import('search_api_index', '{
    "name" : "Course Index",
    "machine_name" : "course_index",
    "description" : "Course Index.",
    "server" : "acquia_search_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "courses", "unit", "unit_set" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "commencement_date" : { "type" : "string" },
        "course_duration_hours" : { "type" : "integer" },
        "field_career:value" : { "type" : "text" },
        "field_college:title" : { "type" : "string" },
        "field_college:url" : { "type" : "uri" },
        "field_course_aqf" : { "type" : "text" },
        "field_course_midyear_intake" : { "type" : "boolean" },
        "field_course_units" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_credentials" : { "type" : "text" },
        "field_cricos_code" : { "type" : "list\\u003Cstring\\u003E" },
        "field_description_editable:value" : { "type" : "text", "boost" : "3.0" },
        "field_domestic" : { "type" : "boolean" },
        "field_excerpt" : { "type" : "text" },
        "field_imp_career" : { "type" : "text" },
        "field_imp_delivery_mode" : { "type" : "list\\u003Cstring\\u003E" },
        "field_imp_desc" : { "type" : "text" },
        "field_imp_intro:value" : { "type" : "text" },
        "field_imp_structure" : { "type" : "text" },
        "field_international" : { "type" : "boolean" },
        "field_locations" : { "type" : "list\\u003Cstring\\u003E" },
        "field_locations_special" : { "type" : "list\\u003Ctext\\u003E" },
        "field_structure" : { "type" : "text", "boost" : "3.0" },
        "field_study_mode" : { "type" : "list\\u003Cstring\\u003E" },
        "field_supplementary_career_info" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "inline_entities" },
        "field_unit_code" : { "type" : "string" },
        "field_unit_lev" : { "type" : "string" },
        "is_new" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "search_api_aggregation_2" : { "type" : "text", "boost" : "3.0" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "13.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_2" : {
                "name" : "all fields",
                "type" : "fulltext",
                "fields" : [
                  "title",
                  "field_course_units",
                  "field_imp_career",
                  "field_imp_desc",
                  "field_imp_structure",
                  "field_unit_code",
                  "field_course_aqf",
                  "field_unit_lev",
                  "title_field",
                  "field_credentials",
                  "field_structure",
                  "field_career:value",
                  "field_imp_intro:value",
                  "field_description_editable:value",
                  "field_college:title"
                ],
                "description" : "A Fulltext aggregation of the following fields: Title, Units, Career opportunities, Imported Description, Structure, Course Code, AQF, Course Level, Title, Qualifications, Structure, Career opportunities \\u00bb Text, Introduction \\u00bb Text, Description (editable) \\u00bb Text, College \\u00bb The title of the link.."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_unit_code" : true, "field_unit_lev" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_unit_code" : true, "field_unit_lev" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_unit_code" : true, "field_unit_lev" : true },
            "file" : "profiles\\/vicuni\\/modules\\/custom\\/vu_core\\/includes\\/vu_stopwords.txt",
            "stopwords" : ""
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 0,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['expert_guide'] = entity_import('search_api_index', '{
    "name" : "Expert Guide",
    "machine_name" : "expert_guide",
    "description" : "This is index for Expert guide. It indexes \\u0027Staff Profile\\u0027 content type.",
    "server" : "acquia_search_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "staff_profile" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text", "boost" : "2.0" },
        "body:value" : { "type" : "text", "boost" : "2.0" },
        "field_job_title" : { "type" : "text" },
        "field_media_ready" : { "type" : "boolean" },
        "field_post_nominals" : { "type" : "text" },
        "field_staff_expertise" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_staff_search_snippet" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_credentials" : true,
              "field_job_title" : true,
              "field_post_nominals" : true,
              "field_staff_search_snippet" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_credentials" : true,
              "field_job_title" : true,
              "field_post_nominals" : true,
              "field_staff_search_snippet" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_credentials" : true,
              "field_job_title" : true,
              "field_post_nominals" : true,
              "field_staff_search_snippet" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_credentials" : true,
              "field_job_title" : true,
              "field_post_nominals" : true,
              "field_staff_search_snippet" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function vu_core_default_search_api_server() {
  $items = array();
  $items['acquia_search_server'] = entity_import('search_api_server', '{
    "name" : "Acquia Search Server",
    "machine_name" : "acquia_search_server",
    "description" : "",
    "class" : "acquia_search_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "apsoutheast2-c32.acquia-search.com",
      "port" : "80",
      "path" : "\\/solr\\/ILUY-91754",
      "edismax" : 0,
      "modify_acquia_connection" : 0,
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1"
  }');
  return $items;
}
