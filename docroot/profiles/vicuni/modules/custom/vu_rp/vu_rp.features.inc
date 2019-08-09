<?php
/**
 * @file
 * vu_rp.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vu_rp_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vu_rp_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function vu_rp_image_default_styles() {
  $styles = array();

  // Exported image style: rp_title_photo.
  $styles['rp_title_photo'] = array(
    'label' => 'Researcher Profile Title Photo',
    'effects' => array(
      7 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 660,
          'height' => 345,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function vu_rp_node_info() {
  $items = array(
    'researcher_profile' => array(
      'name' => t('Researcher Profile'),
      'base' => 'node_content',
      'description' => t('Researcher Profile
'),
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
function vu_rp_paragraphs_info() {
  $items = array(
    'find_researcher' => array(
      'name' => 'Find a researcher',
      'bundle' => 'find_researcher',
      'locked' => '1',
    ),
    'rp_academic_role' => array(
      'name' => 'Researcher academic role',
      'bundle' => 'rp_academic_role',
      'locked' => '1',
    ),
    'rp_award' => array(
      'name' => 'Researcher award',
      'bundle' => 'rp_award',
      'locked' => '1',
    ),
    'rp_funding' => array(
      'name' => 'Researcher funding',
      'bundle' => 'rp_funding',
      'locked' => '1',
    ),
    'rp_industry_roles' => array(
      'name' => 'Researcher industry roles',
      'bundle' => 'rp_industry_roles',
      'locked' => '1',
    ),
    'rp_keynote' => array(
      'name' => 'Researcher keynote',
      'bundle' => 'rp_keynote',
      'locked' => '1',
    ),
    'rp_media_appearance' => array(
      'name' => 'Researcher media appearance',
      'bundle' => 'rp_media_appearance',
      'locked' => '1',
    ),
    'rp_membership' => array(
      'name' => 'Researcher membership',
      'bundle' => 'rp_membership',
      'locked' => '1',
    ),
    'rp_ota' => array(
      'name' => 'Researcher organisation to acknowledge',
      'bundle' => 'rp_ota',
      'locked' => '1',
    ),
    'rp_publication' => array(
      'name' => 'Researcher publication',
      'bundle' => 'rp_publication',
      'locked' => '1',
    ),
    'rp_supervision' => array(
      'name' => 'Researcher supervision',
      'bundle' => 'rp_supervision',
      'locked' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function vu_rp_default_search_api_index() {
  $items = array();
  $items['researcher_profiles'] = entity_import('search_api_index', '{
    "name" : "Researcher Profiles",
    "machine_name" : "researcher_profiles",
    "description" : "This is an index for Researcher profiles. It indexes \\u0027Staff Profile\\u0027 and \\u0027Researcher Profile\\u0027 content type.",
    "server" : "acquia_search_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "researcher_profile", "staff_profile" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_job_title" : { "type" : "text" },
        "field_media_ready" : { "type" : "boolean" },
        "field_post_nominals" : { "type" : "text" },
        "field_researcher_profile" : { "type" : "boolean" },
        "field_rp_available_to_media" : { "type" : "boolean" },
        "field_rp_expertise" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_rp_job_title" : { "type" : "text" },
        "field_rp_post_nominal" : { "type" : "text" },
        "field_rp_shorter_biography" : { "type" : "text" },
        "field_rp_sup_is_available" : { "type" : "boolean" },
        "field_rpa_first_name" : { "type" : "text" },
        "field_rpa_job_title" : { "type" : "text" },
        "field_rpa_last_name" : { "type" : "text" },
        "field_staff_expertise" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_staff_search_snippet" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "supervisor_unknown" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_job_title" : true,
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
              "field_job_title" : true,
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
              "field_job_title" : true,
              "field_staff_search_snippet" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_job_title" : true,
              "field_staff_search_snippet" : true,
              "field_rp_shorter_biography" : true
            },
            "file" : "profiles\\/vicuni\\/modules\\/custom\\/vu_core\\/includes\\/vu_stopwords.txt",
            "stopwords" : ""
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_job_title" : true,
              "field_staff_search_snippet" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
