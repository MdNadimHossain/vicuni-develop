<?php

/**
 * @file
 * Search for functionality.
 */

/**
 * VU researcher profile search form.
 */
function vu_rp_search_form($form, &$form_state) {
  $params = drupal_get_query_parameters();
  $options = [
    VU_RP_SEARCH_ALL => t('All researchers'),
    VU_RP_SEARCH_SUPERVISORS => t('Only available supervisors'),
    VU_RP_SEARCH_MEDIA_QUERIES => t('Only those available for media queries'),
  ];

  $form['title'] = [
    '#prefix' => '<div class="researcher-title">',
    '#markup' => t('Find a researcher'),
    '#suffix' => '</div>',
  ];

  $form['description'] = [
    '#prefix' => '<div class="researcher-description">',
    '#markup' => t('Search for VU researchers by name or provide keywords e.g. areas of expertise, publications, projects.'),
    '#suffix' => '</div>',
  ];

  // Add container for search elements.
  $form['container'] = [
    '#type' => 'container',
    '#weight' => 1,
    '#attributes' => [
      'class' => [
        'search-container',
      ],
    ],
  ];

  $form['container']['query'] = [
    '#title' => '',
    '#type' => 'textfield',
    '#attributes' => [
      'maxlength' => 60,
      'placeholder' => 'Enter researcher name or topic…',
    ],
    '#weight' => 1,
  ];

  // Set default query.
  if (!empty($params['query'])) {
    $form['container']['query']['#default_value'] = check_plain($params['query']);
  }

  // Set default option.
  $default = VU_RP_SEARCH_ALL;
  if (isset($params['rpc']) && array_key_exists($params['rpc'], $options)) {
    $default = $params['rpc'];
  }

  // Researcher search criteria.
  $form['container']['rpc'] = [];
  $form['container']['rpc']['#type'] = 'radios';
  $form['container']['rpc']['#default_value'] = $default;
  $form['container']['rpc']['#options'] = $options;
  $form['container']['rpc']['#weight'] = 3;

  $form['container']['submit'] = [
    '#type' => 'button',
    '#value' => t('Search'),
    '#weight' => 2,
  ];

  $form['#method'] = 'get';

  // Remove additional attributes from being submitted.
  $form['#pre_render'] = ['vu_core_form_remove_state'];

  // Change form action on node pages.
  if (arg(0) == 'node') {
    $form['#action'] = VU_RP_SEARCH_LINK;
  }

  $form['#attributes'] = [
    'class' => [
      'researcher-search-form',
    ],
  ];

  return $form;
}
