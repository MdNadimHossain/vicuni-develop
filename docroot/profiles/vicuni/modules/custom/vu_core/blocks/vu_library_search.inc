<?php

/**
 * @file
 * VU Library Search block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_vu_library_search_info() {
  return [
    'info' => t('Find library resources'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_vu_library_search_view() {
  $form = drupal_get_form('vu_core_library_search_form');
  $form['#id'] = 'vu-core-library-search-block-form';
  $form['#attributes'] = [
    'class' => [
      'clearfix',
      'form-horizontal',
      'library-search-form',
    ],
  ];

  $form['query']['#wrapper_attributes'] = [
    'class' => [
      'js-search_button',
      'pull-left',
    ],
  ];
  $form['query']['#input_group'] = TRUE;
  $form['query']['#field_suffix'] = '<i class="fa fa-search"></i>';
  $form['query']['#title_display'] = 'invisible';
  $form['query']['#title'] = 'VU Library Search';
  $form['query']['#attributes'] = [
    'placeholder' => t('Title, author, journal name, ISBN etc.'),
  ];
  $form['options']['#attributes'] = [
    'class' => [
      'form-wrapper',
    ],
  ];
  $form['submit']['#attributes'] = [
    'class' => [
      'search',
      'hidden-xs',
      'pull-right',
    ],
  ];
  $form['submit']['#icon'] = '<i class="fa fa-search"></i>';
  $form['submit']['#icon_position'] = 'before';
  $form['search_group'] = [
    '#type' => 'container',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    // Elements.
    'query' => $form['query'],
    'options' => $form['options'],
    'link' => $form['link'],
    'submit' => $form['submit'],
    '#attributes' => [
      'class' => [
        'row',
        'form-group-lg',
        'form-wrapper',
        'form-group',
        'lib-search-group',
      ],
    ],
  ];
  unset($form['submit']);
  unset($form['query']);
  unset($form['options']);
  unset($form['link']);
  return [
    'subject' => t('Find library resources'),
    'content' => [
      'form' => $form,
      '#attached' => [
        'js' => [
          drupal_get_path('module', 'vu_core') . '/js/vu_core_library_search_form.js',
          drupal_get_path('theme', 'victory') . '/js/search/course_search_form.js',
        ],
      ],
    ],
  ];

}
