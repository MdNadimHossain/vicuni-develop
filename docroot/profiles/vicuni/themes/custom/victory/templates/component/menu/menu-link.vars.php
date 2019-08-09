<?php

/**
 * @file
 * Theme implementations for menu_link (pre)process functions.
 */

use Drupal\drupal_helpers\Menu;

/**
 * Implements hook_preprocess_menu_link().
 */
function victory_preprocess_menu_link(&$variables) {
  $element = &$variables['element'];
  // Add link level as CSS class.
  $element['#attributes']['class'][] = 'level-' . $element['#original_link']['depth'];

  // Custom processing for a  Footer Useful Links menu: add Bootstrap's column
  // class to a parent column menu item link. Column CSS class name is
  // automatically calculated based on number of columns.
  if ($element['#original_link']['menu_name'] == 'menu-footer-useful-links' && $element['#original_link']['link_path'] == '<separator>') {
    // Note that finding the number of columns is statically cached, so the
    // performance impact is minimal.
    $columns = Menu::findItemSiblings('menu-footer-useful-links', ['mlid' => $element['#original_link']['mlid']], TRUE);
    $element['#attributes']['class'][] = 'col-xs-' . max(1, floor(12 / count($columns)));
  }

  // Add Font-awesome.
  if (isset($element['#bid']) && 'main-menu-level1' === $element['#bid']['delta']) {
    if ('search/vu' === $element['#href']) {
      // @TODO Expose this custom attribute to the UI using the menu_attributes
      // module API to allow admins the ability to drop blocks into the shutter.
      $element['#localized_options']['html'] = TRUE;
      $element['#title'] = '<i class="fa fa-search"></i><span class="sr-only">' . $element['#title'] . '</span>';
    }
  }

  // Custom processing for a second-level menu items within specific menu block:
  // inject second level item into own subtree of children and add markup using
  // template.
  if (($element['#original_link']['menu_name'] == 'main-menu' || $element['#original_link']['menu_name'] == 'menu-subsites') && $element['#bid']['module'] == 'menu_block' && ($element['#bid']['delta'] == 'main-menu-level2' || $element['#bid']['delta'] == 'menu-subsites-level2')) {
    if ($element['#original_link']['depth'] == 2) {
      $has_children = count(element_children($element['#below'])) > 0;
      // Process items with at least one child.
      if ($has_children) {
        $element_clone = $element;
        $element_clone['#attributes']['class'][] = 'section';
        $element_clone['#attributes']['class'][] = 'collapsible';
        // Add custom theme for item processing.
        array_unshift($element_clone['#theme'], 'main_menu_level2_item_section');
        // Remove children for a clone of the item.
        unset($element_clone['#below']);
        // Remove CSS classes that could have been set for a branch.
        $element_clone['#attributes']['class'] = array_diff($element_clone['#attributes']['class'], [
          'first',
          'expanded',
          'active-trail',
        ]);

        // Retrieve node summary for current link.
        $summary = _vu_get_node_summary_by_path($variables['element']['#href']);
        if ($summary) {
          $element_clone['#summary'] = $summary;
        }

        // Add cloned element as a first item in element's children array.
        $element['#below'] = [$element['#original_link']['mlid'] => $element_clone] + $element['#below'];
      }

      // Add Bootstrap's attributes to make this menu link a dropdown trigger,
      // but only for items with children.
      if ($has_children) {
        $element['#localized_options']['html'] = TRUE;
        // Set dropdown trigger element to # to prevent inadvertant page loading
        // when a submenu link is clicked.
        $element['#localized_options']['attributes']['data-target'] = '#';
        $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
        $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

        // Add a span to put the caret :after closer to the top word,
        // when the menu item wraps.
        $char_length = 14;
        if (strlen($element['#title']) > $char_length) {
          $element['#localized_options']['attributes']['class'][] = 'has-top';
          $title_parts = explode(' ', $element['#title']);
          $length = count($title_parts);
          // Add caret at the end of first line.
          $count = $split = 0;
          foreach ($title_parts as $title) {
            // Include space in the count.
            $count += strlen($title) + 1;
            if ($count > $char_length) {
              break;
            }
            $split++;
          }

          $new_title = '<span class="top">';
          foreach ($title_parts as $key => $part) {
            $new_title .= $part;
            if ($key == $split - 1) {
              $new_title .= '</span>';
            }
            if ($key < $length - 1) {
              $new_title .= ' ';
            }
          }
          $element['#title'] = $new_title;
        }
      }
    }
  }

  if (isset($variables['element']['#bid']['delta']) && $variables['element']['#bid']['delta'] == 'main-menu-tools') {
    // Only update the block classes, title and add the ext_icon if we're in the
    // shutter region.
    $contexts = context_active_contexts();
    if (array_key_exists('vu-layout-global-victory', $contexts) && $contexts['vu-layout-global-victory']->reactions['block']['blocks'][$element['#bid']['module'] . '-' . $element['#bid']['delta']]['region'] === 'shutter') {
      // External link icon.
      // In this one scenario ('main-menu-tools' in the shutter region) external
      // link icons should appear differently to everywhere else.
      $ext_icon = theme('tools_menu_ext_link_icon');

      $element['#attributes']['class'][] = 'col-md-4';

      $element['#localized_options']['html'] = TRUE;
      // @TODO Find a better way to determine 'external links'.
      // In the case of redirects The #href value is the redirect value,
      // we want to base the logic on the internal path.
      $title = $element['#title'];
      if (url_is_external($element['#href'])) {
        $element['#title'] = '<span class="text">' . $title . '</span>' . $ext_icon . '<p>' . $element['#localized_options']['attributes']['title'] . '</p>';
      }
      else {
        $element['#title'] = '<span class="text">' . $title . '</span>' . '<p>' . $element['#localized_options']['attributes']['title'] . '</p>';
      }
    }
  }
  $menus = [
    'main-menu' => 'main-menu-child-page-nav',
    'menu-subsites' => 'menu-subsites-child-page-nav',
  ];
  // Populate the link's summary for Child Page Navigation.
  if (in_array($element['#original_link']['menu_name'], array_keys($menus)) && $element['#bid']['module'] == 'menu_block' && in_array($element['#bid']['delta'], $menus)) {
    $summary = _vu_get_node_summary_by_path($variables['element']['#href']);
    $element['#localized_options']['html'] = TRUE;
    $element['#title'] = t('<p><span class="title">@title</span><span class="summary">@summary</span></p>', [
      '@title' => $element['#title'],
      '@summary' => $summary,
    ]);
  }
}

/**
 * Get node summary by path.
 *
 * @param string $path
 *   Path to get summary for.
 *
 * @return string
 *   Summary for node or empty string if node was not found.
 */
function _vu_get_node_summary_by_path($path) {
  $cid = 'vu_core_node_update:' . __FUNCTION__;
  $summaries = &drupal_static($cid, []);

  if (!isset($summaries[$path])) {
    if ($cache = cache_get($cid)) {
      $summaries = $cache->data;
    }

    if (!isset($summaries[$path])) {
      $summary = '';

      $nid = arg(1, $path);
      if (is_numeric($nid)) {
        $node = node_load($nid);
        if ($node) {
          $wrapper = entity_metadata_wrapper('node', $node);
          $summary = !empty($wrapper->body->value()) ? filter_xss($wrapper->body->summary->value()) : '';
          if (!empty($summary)) {
            // Use views' text trimming function as it has more features then
            // standard text trimming function.
            $summary = module_exists('views') ? views_trim_text([
              'max_length' => 140,
              'word_boundary' => TRUE,
              'ellipsis' => TRUE,
            ], $summary) : text_summary($summary, NULL, 140);
          }
        }
      }

      $summaries[$path] = $summary;
      cache_set($cid, $summaries);
    }
  }

  return $summaries[$path];
}
