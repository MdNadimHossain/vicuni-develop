<?php

/**
 * @file
 * Stub file for "views_view_list" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "victory_12_col_fluid" theme hook.
 *
 * See template for list of available variables.
 *
 * @see victory-12-col-fluid.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_victory_12_col_fluid_pane_style(&$variables) {
  $variables['content']->css_class .= " panel-pane--delta-{$variables['id']}";
  if (empty($variables['content']->title) || $variables['content']->content['title']['#tag'] !== 'h2' && $variables['content']->title_heading !== 'h2') {
    $variables['content']->css_class .= ' panel-pane__not-title';
  }

  template_preprocess_panels_pane($variables);
  $variables['title_attributes_array']['class'][] = 'victory-title__stripe';
}
