<?php

/**
 * @file
 * Stub file for "views_view_list" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "victory_12_col" theme hook.
 *
 * See template for list of available variables.
 *
 * @see victory-12-col.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_victory_12_col_pane_style(&$variables) {
  $delta_class = "panel-pane--delta-{$variables['id']}";
  template_preprocess_panels_pane($variables);
  $variables['classes_array'][] = $delta_class;
  if (empty($variables['title']) || !in_array($variables['title_heading'], ['h2', 'h3'])) {
    $variables['classes_array'][] = 'panel-pane__not-title';
  }

  $variables['title_attributes_array']['class'][] = 'victory-title__stripe';
}
