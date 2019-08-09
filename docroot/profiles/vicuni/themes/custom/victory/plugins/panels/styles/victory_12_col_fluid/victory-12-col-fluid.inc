<?php

/**
 * @file
 * Victory 12 column - fluid panel style plugin.
 */

$plugin = [
  'title'       => t('12 column - fluid'),
  'description' => t('12 column - fluid'),
  'render pane' => 'victory_12_col_fluid_style_render_pane',
  'category'    => t('Victory'),
  'hook theme'  => [
    'victory_12_col_fluid_pane_style' => [
      'variables' => [
        'content' => NULL,
        'pane'    => NULL,
        'display' => NULL,
      ],
      'path'      => drupal_get_path('theme', 'victory') . '/plugins/panels/styles/victory_12_col_fluid',
      'template'  => 'victory-12-col-fluid',
    ],
  ],
];

/**
 * Generate pane markup.
 */
function theme_victory_12_col_fluid_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  if (empty($content->content)) {
    return;
  }

  $output = theme('victory_12_col_fluid_pane_style', [
    'content' => $content,
    'pane'    => $pane,
    'display' => $display,
  ]);

  return $output;
}
