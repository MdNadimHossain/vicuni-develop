<?php

/**
 * @file
 * Theme implementations for menu_link (pre)process functions.
 */

use Drupal\drupal_helpers\Menu;

/**
 * Implements hook_preprocess_menu_link().
 */
function vu_preprocess_menu_link(&$variables) {
  $element = &$variables['element'];
  // Add link level as CSS class.
  $element['#attributes']['class'][] = 'level-' . $element['#original_link']['depth'];

  // Add '(Unpublished)' suffix to menu links, but only for users with
  // appropriate access.
  if (user_access('menu view unpublished')) {
    // menu_view_unpublished module's link alterations do not apply here,
    // therefore we need to add CSS class as well as suffix.
    $path = drupal_get_normal_path($element['#href']);
    $path_parts = explode('/', $path);

    // Lookup directly, this avoids 400+ node_loads per page.
    if ($path_parts[0] == 'node' && isset($path_parts[1]) && is_numeric($path_parts[1])) {
      $query = db_select('node', 'n')
        ->fields('n', ['status'])
        ->condition('n.nid', $path_parts[1])
        ->execute();
      $result = $query->fetchObject();
      $node_published = $result ? $result->status : FALSE;

      // If no result or unpublished, we can append the unpublished.
      if (!$node_published) {
        $element['#attributes']['class'][] = 'menu-node-unpublished';
        $element['#title'] .= ' (Unpublished)';
      }
    }
  }

  // Custom processing for a  Footer Useful Links menu: add Bootstrap's column
  // class to a parent column menu item link. Column CSS class name is
  // automatically calculated based on number of columns.
  if ($element['#original_link']['menu_name'] == 'menu-footer-useful-links' && $element['#original_link']['link_path'] == '<separator>') {
    // Note that finding the number of columns is statically cached, so the
    // performance impact is minimal.
    $columns = Menu::findItemSiblings('menu-footer-useful-links', ['mlid' => $element['#original_link']['mlid']], TRUE);
    $element['#attributes']['class'][] = 'col-xs-' . max(1, floor(12 / count($columns)));
  }

  // Custom processing for a second-level menu items within specific menu block:
  // inject second level item into own subtree of children and add markup using
  // template.
  if ($element['#original_link']['menu_name'] == 'main-menu' && $element['#bid']['module'] == 'menu_block' && $element['#bid']['delta'] == 'main-menu-level2') {
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
        if (strlen($element['#title']) > 16) {
          $element['#localized_options']['attributes']['class'][] = 'has-top';
          $title_parts = explode(' ', $element['#title']);
          $length = count($title_parts);
          $new_title = '<span class="top">';
          foreach ($title_parts as $key => $part) {
            $new_title .= $part;
            if ($key == $length - 2) {
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

  if (isset($variables['element']['#bid']) && 'main-menu-level1' === $variables['element']['#bid']['delta']) {
    if ('search/vu' === $variables['element']['#href']) {
      // @TODO Expose this custom attribute to the UI using the menu_attributes
      // module API to allow admins the ability to drop blocks into the shutter.
      $element['#localized_options']['html'] = TRUE;
      $element['#title'] = '<i class="fa fa-search"></i><span class="sr-only">' . $element['#title'] . '</span>';
    }
  }

  if (isset($variables['element']['#bid']) && 'main-menu-tools' === $variables['element']['#bid']['delta']) {
    // Only update the block classes, title and add the ext_icon if we're in the
    // shutter region.
    $contexts = context_active_contexts();
    if (array_key_exists('vu-layout-global', $contexts) && $contexts['vu-layout-global']->reactions['block']['blocks'][$element['#bid']['module'] . '-' . $element['#bid']['delta']]['region'] === 'shutter') {
      // External link icon.
      // In this one scenario ('main-menu-tools' in the shutter region) external
      // link icons should appear differently to everywhere else.
      $ext_icon = '<div class="external-link-wrapper">
        <div class="ext-box-break-hover"></div>
        <div class="ext-box"></div>
        <div class="arrow-wrapper">
            <div class="ext-box-break"></div>
            <div class="ext-arrow-head"></div>
            <div class="ext-arrow-stroke"></div>
        </div>
      </div>';

      $element['#attributes']['class'][] = 'col-md-4';

      $element['#localized_options']['html'] = TRUE;
      // @TODO Find a better way to determine 'external links'.
      // In the case of redirects The #href value is the redirect value,
      // we want to base the logic on the internal path.
      if (url_is_external($element['#href'])) {
        $element['#title'] = $element['#title'] . $ext_icon . '<p>' . $element['#localized_options']['attributes']['title'] . '</p>';
      }
      else {
        $element['#title'] = $element['#title'] . '<p>' . $element['#localized_options']['attributes']['title'] . '</p>';
      }
    }
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
