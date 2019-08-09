<?php

/**
 * @file
 * Stub file for "page" theme hook [pre]process functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_preprocess
 */
function victory_preprocess_page(&$variables) {
  // Add Font-awesome.
  drupal_add_css('//maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.css', ['type' => 'external']);
  // Add Typekit script.
  drupal_add_js('//use.typekit.net/vnw2lhd.js', ['cache' => FALSE]);
  drupal_add_js('try { Typekit.load(); } catch (e) {}', 'inline');
  // Add accessibility bar.
  drupal_add_js(path_to_theme() . '/js/components/victory.accessibility-bar.js');
  // Add secondary menu and required dependencies.
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/transition.js');
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/dropdown.js');
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/tooltip.js');
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/popover.js');
  drupal_add_js(libraries_get_path('jquery.hoverintent') . '/jquery.hoverIntent.js');
  drupal_add_js(path_to_theme() . '/js/components/victory.mask.js');
  drupal_add_js(path_to_theme() . '/js/components/victory.secondary-menu.js');
  // Add mobile menu.
  drupal_add_js(path_to_theme() . '/js/components/victory.mobile-menu.js');
  // Add shutter.
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/modal.js');
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/collapse.js');
  drupal_add_js(path_to_theme() . '/js/components/victory.shutter.js');
  // Add sticky header.
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/affix.js');
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/scrollspy.js');
  drupal_add_js(path_to_theme() . '/js/components/victory.sticky-header.js');
  // Sticky Back to Top.
  drupal_add_js(path_to_theme() . '/js/components/victory.sticky-back_to_top.js');
  // Tabs.
  drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/tab.js');

  $variables['pre_content'] = NULL;

  $variables['show_title_box'] = TRUE;
  if (empty($variables['title_box_classes'])) {
    $variables['title_box_classes'] = [];
  }
  $variables['title_box_classes'][] = 'row';

  $variables['title_box_feature_classes'] = !empty($variables['title_box_feature_classes']) ? $variables['title_box_feature_classes'] : [];
  // Set title box inner classes depending on content.
  if (array_key_exists('ds_extras_courses_title_box_feature', $variables['page']['title_box_feature'])) {
    $variables['title_box_feature_inner_classes'][] = 'title-box__feature__image';
  }
  else {
    $variables['title_box_feature_inner_classes'][] = 'title-box__feature__inner';
  }

  $variables['title_box_classes'][] = 'title-box--heading-smaller';

  // Node type specific Javascripts.
  $node = isset($variables['node']) && is_object($variables['node']) ? $variables['node'] : FALSE;
  if ($node === FALSE) {
    $node = _vu_core_block_menu_get_course_object();
  }

  if ($node) {
    switch ($node->type) {
      case 'courses':
        // Sticky CTA.
        drupal_add_js(path_to_theme() . '/js/components/victory.sticky-cta.js');
        break;

      case 'page_builder':
      case 'campus':
        $items = field_get_items('node', $node, 'field_title_area_feature');
        if (empty($items)) {
          break;
        }

        $paragraph = paragraphs_item_revision_load($items[0]['revision_id']);
        if ($paragraph->bundle() == 'image_background') {
          $variables['title_box_classes'][] = 'background-image';
          $element = $paragraph->view('preprocess');
          $variables['pre_content'] = render($element);

          $find_on_page = vu_core_extract_single_field_value($paragraph, 'paragraphs_item', 'field_on_this_page_enabled');
          if ($find_on_page) {
            $variables['title_box_classes'][] = 'title-box--on-this-page';
          }
        }

        break;
    }
  }

  // Frontpage.
  if (drupal_is_front_page()) {
    // Hide title box on the homepage.
    $variables['show_title_box'] = FALSE;
    $variables['container_class'] = 'container-fluid';

    // Add Hero title box script.
    drupal_add_js(path_to_theme() . '/js/components/victory.hero-title-box.js');
  }

  // If the page is search page.
  if (arg(0) == 'search') {
    $variables['site_search_form'] = drupal_get_form('vu_core_funnelback_search_form');
  }

}
