<?php
/**
 * @file
 * vu_core.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function vu_core_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'campus_housing_fields';
  $linkit_profile->admin_title = 'Campus housing fields';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:course_information_session_links' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'campus_housing' => 'campus_housing',
        'page_builder' => 'page_builder',
        'campus' => 0,
        'courses' => 0,
        'events' => 0,
        'news' => 0,
        'researcher_profile' => 0,
        'staff_profile' => 0,
        'study_topic_area' => 0,
        'success_story' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
        'audience' => 0,
        'membership_levels' => 0,
        'membership_organisations' => 0,
        'research_institutes' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_researcher_profile' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'basic_bean' => 0,
        'choose_vu' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'fym_banner_type' => 0,
        'hero_banner' => 0,
        'hero_title_box' => 0,
        'homepage_banner' => 0,
        'promo' => 0,
        'quick_facts' => 0,
        'student_testimonials' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:course_information_session_links' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
        'our_victories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:fieldable_panels_pane' => array(
      'result_description' => '',
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'pane_featured_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'features' => 0,
        'menu-footer' => 0,
        'menu-footer-useful-links' => 0,
        'menu-header-area' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-researcher-role' => 0,
        'menu-researcher-profile-admin' => 0,
        'menu-subsites' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'entity_reference',
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['campus_housing_fields'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'courses_field';
  $linkit_profile->admin_title = 'Courses field';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:course_information_session_links' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'courses' => 'courses',
        'campus' => 0,
        'campus_housing' => 0,
        'events' => 0,
        'news' => 0,
        'page_builder' => 0,
        'researcher_profile' => 0,
        'staff_profile' => 0,
        'study_topic_area' => 0,
        'success_story' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
        'audience' => 0,
        'membership_levels' => 0,
        'membership_organisations' => 0,
        'research_institutes' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_researcher_profile' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'basic_bean' => 0,
        'choose_vu' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'fym_banner_type' => 0,
        'hero_banner' => 0,
        'hero_title_box' => 0,
        'homepage_banner' => 0,
        'promo' => 0,
        'quick_facts' => 0,
        'student_testimonials' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:course_information_session_links' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
        'our_victories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:fieldable_panels_pane' => array(
      'result_description' => '',
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'pane_featured_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'features' => 0,
        'menu-footer' => 0,
        'menu-footer-useful-links' => 0,
        'menu-header-area' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-researcher-role' => 0,
        'menu-researcher-profile-admin' => 0,
        'menu-subsites' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'entity_reference',
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['courses_field'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'related_success_stories_field';
  $linkit_profile->admin_title = 'Related success stories field';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:course_information_session_links' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'success_story' => 'success_story',
        'campus' => 0,
        'campus_housing' => 0,
        'courses' => 0,
        'events' => 0,
        'news' => 0,
        'page_builder' => 0,
        'researcher_profile' => 0,
        'staff_profile' => 0,
        'study_topic_area' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
        'audience' => 0,
        'membership_levels' => 0,
        'membership_organisations' => 0,
        'research_institutes' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_researcher_profile' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'basic_bean' => 0,
        'choose_vu' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'fym_banner_type' => 0,
        'hero_banner' => 0,
        'hero_title_box' => 0,
        'homepage_banner' => 0,
        'promo' => 0,
        'quick_facts' => 0,
        'student_testimonials' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:course_information_session_links' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
        'our_victories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:fieldable_panels_pane' => array(
      'result_description' => '',
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'pane_featured_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'features' => 0,
        'menu-footer' => 0,
        'menu-footer-useful-links' => 0,
        'menu-header-area' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-researcher-role' => 0,
        'menu-researcher-profile-admin' => 0,
        'menu-subsites' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'entity_reference',
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['related_success_stories_field'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'standard_fields';
  $linkit_profile->admin_title = 'Standard Fields';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:course_information_session_links' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'campus' => 0,
        'campus_housing' => 0,
        'courses' => 0,
        'events' => 0,
        'news' => 0,
        'page_builder' => 0,
        'researcher_profile' => 0,
        'staff_profile' => 0,
        'study_topic_area' => 0,
        'success_story' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
        'audience' => 0,
        'membership_levels' => 0,
        'membership_organisations' => 0,
        'research_institutes' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_researcher_profile' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'basic_bean' => 0,
        'choose_vu' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'fym_banner_type' => 0,
        'hero_banner' => 0,
        'hero_title_box' => 0,
        'homepage_banner' => 0,
        'promo' => 0,
        'quick_facts' => 0,
        'student_testimonials' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:course_information_session_links' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
        'our_victories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:fieldable_panels_pane' => array(
      'result_description' => '',
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'pane_featured_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'features' => 0,
        'menu-footer' => 0,
        'menu-footer-useful-links' => 0,
        'menu-header-area' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-researcher-role' => 0,
        'menu-researcher-profile-admin' => 0,
        'menu-subsites' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'entity_reference',
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['standard_fields'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'standard_wyswyg';
  $linkit_profile->admin_title = 'Standard WYSWYG';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'full_html' => 'full_html',
      'filtered_html' => 'filtered_html',
      'plain_text' => 0,
      'migrated_content' => 0,
      'php_code' => 0,
    ),
    'search_plugins' => array(
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'campus' => 0,
        'campus_housing' => 0,
        'courses' => 0,
        'events' => 0,
        'links' => 0,
        'news' => 0,
        'page_builder' => 0,
        'staff_profile' => 0,
        'study_topic_area' => 0,
        'success_story' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_links' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'homepage_banner' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '3',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['standard_wyswyg'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'study_topic_or_area_field';
  $linkit_profile->admin_title = 'Study topic or area field';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:course_information_session_links' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'study_topic_area' => 'study_topic_area',
        'campus' => 0,
        'campus_housing' => 0,
        'courses' => 0,
        'events' => 0,
        'news' => 0,
        'page_builder' => 0,
        'researcher_profile' => 0,
        'staff_profile' => 0,
        'success_story' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
        'audience' => 0,
        'membership_levels' => 0,
        'membership_organisations' => 0,
        'research_institutes' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_researcher_profile' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'basic_bean' => 0,
        'choose_vu' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'fym_banner_type' => 0,
        'hero_banner' => 0,
        'hero_title_box' => 0,
        'homepage_banner' => 0,
        'promo' => 0,
        'quick_facts' => 0,
        'student_testimonials' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:course_information_session_links' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
        'our_victories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:fieldable_panels_pane' => array(
      'result_description' => '',
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'pane_featured_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'features' => 0,
        'menu-footer' => 0,
        'menu-footer-useful-links' => 0,
        'menu-header-area' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-researcher-role' => 0,
        'menu-researcher-profile-admin' => 0,
        'menu-subsites' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'entity_reference',
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['study_topic_or_area_field'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'webforms_profile';
  $linkit_profile->admin_title = 'Webforms profile';
  $linkit_profile->admin_description = 'Webforms profile';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:inline_entities' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:fieldable_panels_pane' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:contact_information' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:course_information_session_links' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:accordion_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => 'Node [node:nid]',
      'bundles' => array(
        'webform' => 'webform',
        'campus' => 0,
        'campus_housing' => 0,
        'courses' => 0,
        'events' => 0,
        'news' => 0,
        'page_builder' => 0,
        'researcher_profile' => 0,
        'staff_profile' => 0,
        'study_topic_area' => 0,
        'success_story' => 0,
        'topic_pages' => 0,
        'unit' => 0,
        'unit_set' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'delivery_modes' => 0,
        'subsites' => 0,
        'success_categories' => 0,
        'unit_set_type' => 0,
        'expertise' => 0,
        'tags' => 0,
        'audience' => 0,
        'membership_levels' => 0,
        'membership_organisations' => 0,
        'research_institutes' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_campus' => 0,
        'comment_node_campus_housing' => 0,
        'comment_node_courses' => 0,
        'comment_node_events' => 0,
        'comment_node_news' => 0,
        'comment_node_page_builder' => 0,
        'comment_node_researcher_profile' => 0,
        'comment_node_staff_profile' => 0,
        'comment_node_study_topic_area' => 0,
        'comment_node_success_story' => 0,
        'comment_node_topic_pages' => 0,
        'comment_node_unit' => 0,
        'comment_node_unit_set' => 0,
        'comment_node_webform' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'audience_landing_page_link' => 0,
        'basic_bean' => 0,
        'choose_vu' => 0,
        'feature_tile' => 0,
        'featured_success_stories_block' => 0,
        'fym_banner_type' => 0,
        'hero_banner' => 0,
        'hero_title_box' => 0,
        'homepage_banner' => 0,
        'promo' => 0,
        'quick_facts' => 0,
        'student_testimonials' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:accordion_item' => array(
      'result_description' => '',
    ),
    'entity:contact_information' => array(
      'result_description' => '',
    ),
    'entity:course_information_session_links' => array(
      'result_description' => '',
    ),
    'entity:inline_entities' => array(
      'result_description' => '',
      'bundles' => array(
        'accordion_section' => 0,
        'basic_body_text' => 0,
        'block_reference' => 0,
        'course_date_time' => 0,
        'featured_content' => 0,
        'location' => 0,
        'related_links' => 0,
        'topic_page_content' => 0,
        'topic_page_sidebar_content' => 0,
        'link_redirects' => 0,
        'topic_page_facts' => 0,
        'featured_success_story' => 0,
        'our_victories' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:fieldable_panels_pane' => array(
      'result_description' => '',
      'bundles' => array(
        'fieldable_panels_pane' => 0,
        'pane_featured_content' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'features' => 0,
        'menu-footer' => 0,
        'menu-footer-useful-links' => 0,
        'menu-header-area' => 0,
        'main-menu' => 0,
        'management' => 0,
        'navigation' => 0,
        'menu-researcher-role' => 0,
        'menu-researcher-profile-admin' => 0,
        'menu-subsites' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'entity_reference',
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['webforms_profile'] = $linkit_profile;

  return $export;
}
