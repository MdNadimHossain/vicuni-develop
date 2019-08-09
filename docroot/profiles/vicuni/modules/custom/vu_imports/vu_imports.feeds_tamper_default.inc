<?php
/**
 * @file
 * vu_imports.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function vu_imports_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'course_fees-course_code-atar_profile_data_guid';
  $feeds_tamper->importer = 'course_fees';
  $feeds_tamper->source = 'course_code';
  $feeds_tamper->plugin_id = 'atar_profile_data_guid';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_atar_profile_data_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Resolve a course code to guid';
  $export['course_fees-course_code-atar_profile_data_guid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_information-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_information';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-additional_information-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_he-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_he';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-additional_requirements_he-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_he-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_he';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-additional_requirements_he-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_se-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_se';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-additional_requirements_se-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_se-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_se';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-additional_requirements_se-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_vet-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_vet';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-additional_requirements_vet-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_vet-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_vet';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-additional_requirements_vet-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_wl-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_wl';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-additional_requirements_wl-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additional_requirements_wl-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additional_requirements_wl';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-additional_requirements_wl-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-additionalcosts-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'additionalcosts';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-additionalcosts-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-admission_requirements-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'admission_requirements';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-admission_requirements-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-admissionrequirementspg-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'admissionrequirementspg';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-admissionrequirementspg-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-admissionrequirementspg-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'admissionrequirementspg';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-admissionrequirementspg-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-aqftype-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'aqftype';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-aqftype-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-blank_source_1-admission_requirements';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'admission_requirements';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_admission_requirements_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Parse admission requirements xml nodes into one html string';
  $export['courses-blank_source_1-admission_requirements'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-blank_source_2-course_sort_title';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'course_sort_title';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_clean_course_title_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Clean course title';
  $export['courses-blank_source_2-course_sort_title'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-blank_source_2-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-blank_source_2-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-blank_source_3-unit_college_link';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'Blank source 3';
  $feeds_tamper->plugin_id = 'unit_college_link';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_college_link_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Return the link for a given college name';
  $export['courses-blank_source_3-unit_college_link'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-blank_source_4-course_publish';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'Blank source 4';
  $feeds_tamper->plugin_id = 'course_publish';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_course_publish_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set published status of imported course';
  $export['courses-blank_source_4-course_publish'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-blank_source_5-domestic';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'Blank source 5';
  $feeds_tamper->plugin_id = 'domestic';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_domestic_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Domestic';
  $export['courses-blank_source_5-domestic'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-careeroutcomes-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'careeroutcomes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-careeroutcomes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-continuingstudent-convert_boolean';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'continuingstudent';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['courses-continuingstudent-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-course_title-copy';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'course_title';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'to',
    'source' => 'Blank source 6',
    'vu_imports_callback' => 'feeds_tamper_copy_callback',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Copy source value';
  $export['courses-course_title-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-course_title-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'course_title';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-course_title-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-coursecompletionrules-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'coursecompletionrules';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-coursecompletionrules-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-courselearningoutcomes-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'courselearningoutcomes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-courselearningoutcomes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-courselevel-unit_level';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'courselevel';
  $feeds_tamper->plugin_id = 'unit_level';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_level_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Maps unit level based on course level and aqf fields.';
  $export['courses-courselevel-unit_level'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-courseoffered-convert_boolean';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'courseoffered';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['courses-courseoffered-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-coursepurpose-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'coursepurpose';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-coursepurpose-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-deliverymode-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'deliverymode';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-deliverymode-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-duration-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'duration';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-duration-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-entry_requirements_domestic-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'entry_requirements_domestic';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-entry_requirements_domestic-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-entry_requirements_domestic-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'entry_requirements_domestic';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-entry_requirements_domestic-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-entry_requirements_in-find_replace_regex';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'entry_requirements_in';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[\\n\\r]+/i',
    'replace' => '&lt;br/&gt;',
    'limit' => '',
    'real_limit' => -1,
    'vu_imports_callback' => 'feeds_tamper_find_replace_regex_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['courses-entry_requirements_in-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-entry_requirements_in-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'entry_requirements_in';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-entry_requirements_in-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-fees-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'fees';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-fees-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-handbookinclude-convert_boolean';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'handbookinclude';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['courses-handbookinclude-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-international_offered-convert_boolean';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'international_offered';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['courses-international_offered-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-introduction-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'introduction';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-introduction-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-locationother-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'locationother';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-locationother-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-locations-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'locations';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-locations-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-prerequisite_units-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'prerequisite_units';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-prerequisite_units-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-prerequisiteunitrequirements-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'prerequisiteunitrequirements';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-prerequisiteunitrequirements-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-qualificationcompletionrules-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'qualificationcompletionrules';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-qualificationcompletionrules-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-qualificationlearningoutcomes-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'qualificationlearningoutcomes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-qualificationlearningoutcomes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-sector-unit_level';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'sector';
  $feeds_tamper->plugin_id = 'unit_level';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_level_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Maps unit level based on course level and aqf fields.';
  $export['courses-sector-unit_level'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-semesterintakes-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'semesterintakes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-semesterintakes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-studymode-html_entity_decode';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'studymode';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses-studymode-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-unitid-string2id';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'unitid';
  $feeds_tamper->plugin_id = 'string2id';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => 'node',
      'field_name' => 'field_course_units',
      'bundle_name' => NULL,
    ),
    'views' => array(
      'view' => 'course_import_entity_reference_filter:default',
      'col_id' => '',
    ),
    'vu_imports_callback' => 'feeds_tamper_string2id_resolve_target_callback',
  );
  $feeds_tamper->weight = 9;
  $feeds_tamper->description = 'Convert string into entity ID';
  $export['courses-unitid-string2id'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses-unitid-unit_or_unitset_guid';
  $feeds_tamper->importer = 'courses';
  $feeds_tamper->source = 'unitid';
  $feeds_tamper->plugin_id = 'unit_or_unitset_guid';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_or_unitset_guid_callback',
  );
  $feeds_tamper->weight = 8;
  $feeds_tamper->description = 'Resolve a unit or unit set ID to GUID for entityreference';
  $export['courses-unitid-unit_or_unitset_guid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses_atar_profile_data-code-atar_profile_data_guid';
  $feeds_tamper->importer = 'courses_atar_profile_data';
  $feeds_tamper->source = 'code';
  $feeds_tamper->plugin_id = 'atar_profile_data_guid';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_atar_profile_data_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Resolve a course code to guid';
  $export['courses_atar_profile_data-code-atar_profile_data_guid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'courses_vet-admission_requirements-html_entity_decode';
  $feeds_tamper->importer = 'courses_vet';
  $feeds_tamper->source = 'admission_requirements';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['courses_vet-admission_requirements-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'researcher_profiles-researcher_profile-convert_boolean';
  $feeds_tamper->importer = 'researcher_profiles';
  $feeds_tamper->source = 'Researcher Profile';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'yes',
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['researcher_profiles-researcher_profile-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unit_fees-course_code-atar_profile_data_guid';
  $feeds_tamper->importer = 'unit_fees';
  $feeds_tamper->source = 'course_code';
  $feeds_tamper->plugin_id = 'atar_profile_data_guid';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_atar_profile_data_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Resolve a course code to guid';
  $export['unit_fees-course_code-atar_profile_data_guid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unit_fees-unit_code-copy';
  $feeds_tamper->importer = 'unit_fees';
  $feeds_tamper->source = 'unit_code';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'to',
    'source' => 'unit_code_original',
    'vu_imports_callback' => 'feeds_tamper_copy_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Copy source value';
  $export['unit_fees-unit_code-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unit_fees-unit_code-efq_finder';
  $feeds_tamper->importer = 'unit_fees';
  $feeds_tamper->source = 'unit_code';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'node',
    'bundle' => 'unit',
    'field' => 'field_unit_code',
    'column' => 'value',
    'property' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_efq_finder_callback',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['unit_fees-unit_code-efq_finder'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unit_fees-unit_code_original-copy';
  $feeds_tamper->importer = 'unit_fees';
  $feeds_tamper->source = 'unit_code_original';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'unit_code',
    'vu_imports_callback' => 'feeds_tamper_copy_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['unit_fees-unit_code_original-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-blank_source_1-location_non_entity_reference';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'location_non_entity_reference';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_locations_special_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Handle special location xml node values';
  $export['units-blank_source_1-location_non_entity_reference'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-college_url-unit_college_link';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'college_url';
  $feeds_tamper->plugin_id = 'unit_college_link';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_college_link_callback',
  );
  $feeds_tamper->weight = 12;
  $feeds_tamper->description = 'Return the link for a given college name';
  $export['units-college_url-unit_college_link'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-introduction-html_entity_decode';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'introduction';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units-introduction-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-learning_outcomes-html_entity_decode';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'learning_outcomes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units-learning_outcomes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-locations-find_replace';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'locations';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'City King St',
    'replace' => 'City King',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^City King St$/ui',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['units-locations-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-unit_code-trim';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'unit_code';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
    'vu_imports_callback' => 'feeds_tamper_trim_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['units-unit_code-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-unit_code_path_alias-rewrite';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'unit_code_path_alias';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'units/[unit_code]',
    'vu_imports_callback' => 'feeds_tamper_rewrite_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['units-unit_code_path_alias-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-unit_level-find_replace_pg';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'unit_level';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'PG',
    'replace' => 'postgrad',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^PG$/u',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace PG';
  $export['units-unit_level-find_replace_pg'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-unit_level-find_replace_ug';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'unit_level';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'UG',
    'replace' => 'undergrad',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^UG$/u',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace ug';
  $export['units-unit_level-find_replace_ug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-unit_offered-convert_boolean';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'unit_offered';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['units-unit_offered-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units-unit_title-html_entity_decode';
  $feeds_tamper->importer = 'units';
  $feeds_tamper->source = 'unit_title';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units-unit_title-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-assessment-html_entity_decode';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'assessment';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_na-assessment-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-blank_source_2-unit_college_link';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'unit_college_link';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_college_link_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Return the link for a given college name';
  $export['units_na-blank_source_2-unit_college_link'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-introduction-html_entity_decode';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'introduction';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_na-introduction-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-learning_outcomes-html_entity_decode';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'learning_outcomes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_na-learning_outcomes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-locations-find_replace';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'locations';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'City King St',
    'replace' => 'City King',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^City King St$/ui',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['units_na-locations-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-unit_code-trim';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'unit_code';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
    'vu_imports_callback' => 'feeds_tamper_trim_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['units_na-unit_code-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-unit_code_path_alias-rewrite';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'unit_code_path_alias';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'units/[unit_code]',
    'vu_imports_callback' => 'feeds_tamper_rewrite_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['units_na-unit_code_path_alias-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-unit_offered-convert_boolean';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'unit_offered';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['units_na-unit_offered-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-unit_title-html_entity_decode';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'unit_title';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_na-unit_title-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_na-unit_title-rewrite';
  $feeds_tamper->importer = 'units_na';
  $feeds_tamper->source = 'unit_title';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[unit_code] - [unit_title]',
    'vu_imports_callback' => 'feeds_tamper_rewrite_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Prefix TAFE Unit title with Unit code';
  $export['units_na-unit_title-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-assessment-html_entity_decode';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'assessment';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_vet-assessment-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-blank_source_1-location_non_entity_reference';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'location_non_entity_reference';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_locations_special_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Handle special location xml node values';
  $export['units_vet-blank_source_1-location_non_entity_reference'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-blank_source_2-unit_college_link';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'unit_college_link';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_college_link_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Return the link for a given college name';
  $export['units_vet-blank_source_2-unit_college_link'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-introduction-html_entity_decode';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'introduction';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_vet-introduction-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-learning_outcomes-html_entity_decode';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'learning_outcomes';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_vet-learning_outcomes-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-locations-find_replace';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'locations';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'City King St',
    'replace' => 'City King',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^City King St$/ui',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['units_vet-locations-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-unit_code-trim';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'unit_code';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
    'vu_imports_callback' => 'feeds_tamper_trim_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['units_vet-unit_code-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-unit_code_path_alias-rewrite';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'unit_code_path_alias';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'units/[unit_code]',
    'vu_imports_callback' => 'feeds_tamper_rewrite_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['units_vet-unit_code_path_alias-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-unit_level-default_value';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'unit_level';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'tafe',
    'only_if_empty' => 0,
    'vu_imports_callback' => 'feeds_tamper_default_value_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['units_vet-unit_level-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-unit_offered-convert_boolean';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'unit_offered';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'y',
    'false_value' => 'n',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
    'vu_imports_callback' => 'feeds_tamper_convert_boolean_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['units_vet-unit_offered-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-unit_title-html_entity_decode';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'unit_title';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'HTML entity decode';
  $export['units_vet-unit_title-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'units_vet-unit_title-rewrite';
  $feeds_tamper->importer = 'units_vet';
  $feeds_tamper->source = 'unit_title';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[unit_code] - [unit_title]',
    'vu_imports_callback' => 'feeds_tamper_rewrite_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Prefix TAFE Unit title with Unit code';
  $export['units_vet-unit_title-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-blank_source_1-unitset_publish_test';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'unitset_publish_test';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => '_vu_imports_unitset_publish_test_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set published status of imported unitset';
  $export['unitsets-blank_source_1-unitset_publish_test'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-blank_source_2-location_non_entity_reference';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'location_non_entity_reference';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_locations_special_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Handle special location xml node values';
  $export['unitsets-blank_source_2-location_non_entity_reference'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-blank_source_3-unit_college_link';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'Blank source 3';
  $feeds_tamper->plugin_id = 'unit_college_link';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'vu_imports_unit_college_link_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Return the link for a given college name';
  $export['unitsets-blank_source_3-unit_college_link'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-introduction-html_entity_decode';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'introduction';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['unitsets-introduction-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-locations-find_replace';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'locations';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'City King St',
    'replace' => 'City King',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^City King St$/ui',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['unitsets-locations-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-unit_set_code-trim';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'unit_set_code';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
    'vu_imports_callback' => 'feeds_tamper_trim_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['unitsets-unit_set_code-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-unit_set_level-find_replace_pg';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'unit_set_level';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'PG',
    'replace' => 'postgrad',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^PG$/u',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace PG';
  $export['unitsets-unit_set_level-find_replace_pg'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-unit_set_level-find_replace_ug';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'unit_set_level';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'UG',
    'replace' => 'undergrad',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^UG$/u',
    'vu_imports_callback' => 'feeds_tamper_find_replace_callback',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace UG';
  $export['unitsets-unit_set_level-find_replace_ug'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-unit_set_title-html_entity_decode';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'unit_set_title';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array(
    'vu_imports_callback' => 'feeds_tamper_html_entity_decode_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['unitsets-unit_set_title-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-units-sprintf';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'units';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => 'unit-%s',
    'vu_imports_callback' => 'feeds_tamper_sprintf_callback',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Format string';
  $export['unitsets-units-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unitsets-unitset_code_path_alias-rewrite';
  $feeds_tamper->importer = 'unitsets';
  $feeds_tamper->source = 'unitset_code_path_alias';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'unitsets/[unit_set_code]',
    'vu_imports_callback' => 'feeds_tamper_rewrite_callback',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['unitsets-unitset_code_path_alias-rewrite'] = $feeds_tamper;

  return $export;
}
