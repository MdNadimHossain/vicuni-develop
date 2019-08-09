<?php

/**
 * @file
 * Stub file for "views_view_list" theme hook [pre]process functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 *
 * See template for list of available variables.
 *
 * @see views-view-list--courses-lists--course-browser-block.tpl.php
 *
 * @ingroup theme_preprocess
 */
function victory_preprocess_views_view_list__courses_lists__course_browser_block(&$variables) {
  // Add 'All courses A to Z' item to the end of the Courses list view block
  // display.
  if (vu_core_is_course_browse_international_version()) {
    $variables['rows'] = preg_replace('/href="(.*?)"/', 'href="$1?audience=international"', $variables['rows']);
    $link = l(t('English Language Courses'), '/vu-english/english-language-courses');
  }
  else {
    $node = node_load(10889101);
    $link = l($node->title, "node/{$node->nid}");
  }

  $variables['rows'][] = preg_replace('/<a.*?<\/a>/', $link, $variables['rows'][0]);

  // Adjust classes.
  $variables['classes_array'][count($variables['classes_array']) - 1] = str_replace(' views-row-last', '', $variables['classes_array'][count($variables['classes_array']) - 1]);
  $variables['classes_array'][] = $variables['classes_array'][count($variables['classes_array']) - 2] . ' views-row-last';

  $variables['class'] = "col-sm-4";
  $variables['list_type_prefix'] = '<' . $variables['view']->style_plugin->options['type'] . ' class="' . $variables['class'] . '">';

  $variables['wrapper_class'] .= " row";
  $variables['wrapper_prefix'] = '<div class="' . $variables['wrapper_class'] . '">';
}
