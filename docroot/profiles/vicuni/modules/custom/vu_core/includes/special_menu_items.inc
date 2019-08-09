<?php

/**
 * @file
 * Special menu items module integration.
 */

/**
 * Implements hook_preprocess_menu_link().
 */
function vu_core_preprocess_menu_link(&$variables) {
  // Add CSS class to all separator list item links.
  // This is useful for styling menu items that are children of separator items.
  if ($variables['element']['#href'] == '<separator>') {
    $variables['element']['#attributes']['class'][] = 'separator';
    // Set ARIA attributes.
    // @see https://www.w3.org/WAI/GL/wiki/Using_ARIA_menus
    $variables['element']['#attributes']['role'] = 'separator';
    $variables['element']['#attributes']['tabindex'] = '-1';
  }
}

/**
 * Implements hook_vu_core_form_menu_overview_form_alter().
 */
function vu_core_vu_core_form_menu_overview_form_alter(&$form, $form_state) {
  if ($form['#menu']['menu_name'] == 'menu-footer-useful-links') {
    $form['#prefix'] = t('Place children menu items under %separator to create menu columns.', ['%separator' => '<separator>']);
    foreach ($form as $k => $item) {
      if (strpos($k, 'mlid:') === 0 && strpos($form[$k]['title']['#markup'], variable_get('special_menu_items_separator_value', '<hr>')) !== FALSE) {
        $form[$k]['title']['#markup'] = '<span class="separator">Column separator</span>';
      }
    }
  }
}
