<?php
/**
 * @file
 * vu_core.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function vu_core_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'audience_landing_page_link';
  $bean_type->label = 'Audience landing page link';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['audience_landing_page_link'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'basic_bean';
  $bean_type->label = 'Basic';
  $bean_type->options = '';
  $bean_type->description = 'A basic bean with a single text field.';
  $export['basic_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'choose_vu';
  $bean_type->label = 'Choose VU';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['choose_vu'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'feature_tile';
  $bean_type->label = 'Feature tile';
  $bean_type->options = '';
  $bean_type->description = 'This block is placed on the home page - right column';
  $export['feature_tile'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'featured_success_stories_block';
  $bean_type->label = 'Featured success stories content';
  $bean_type->options = '';
  $bean_type->description = 'Use this to block type to select success stories to feature inline with content on landing pages.';
  $export['featured_success_stories_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'fym_banner_type';
  $bean_type->label = 'FYM Banner Type';
  $bean_type->options = '';
  $bean_type->description = 'Block type for FYM Banner';
  $export['fym_banner_type'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'hero_banner';
  $bean_type->label = 'Hero banner';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['hero_banner'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'hero_title_box';
  $bean_type->label = 'Hero title box';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['hero_title_box'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'homepage_banner';
  $bean_type->label = 'Homepage banner';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['homepage_banner'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'promo';
  $bean_type->label = 'Promo';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['promo'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'quick_facts';
  $bean_type->label = 'Quick facts';
  $bean_type->options = '';
  $bean_type->description = 'Quick fact in the homepage.';
  $export['quick_facts'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'student_testimonials';
  $bean_type->label = 'Student Testimonials';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['student_testimonials'] = $bean_type;

  return $export;
}
