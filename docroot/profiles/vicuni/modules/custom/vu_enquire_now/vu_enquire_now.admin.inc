<?php
/**
 * @file
 * VU Enquire Now admin settings.
 */

/**
 * Attach Enquire Now settings to Courses Node type form.
 *
 * @param array $form
 * @param array $form_state
 */
function _vu_enquire_now_form_node_type_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#node_type']->type !== 'courses') {
    return;
  }

  $form['enquire_now'] = array(
    '#title' => t('Enquire Now form'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'additional_settings',
    '#weight' => 100,
  );

  $form['enquire_now']['enquire_now_webform'] = array(
    '#title' => t('Attach Enquire Now webform in Course pages'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('vu_enquire_now_webform', 1),
    '#attributes' => array(
      'data-enabled-description' => t('Enabled'),
      'data-disabled-description' => t('Disabled'),
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'vu_enquire_now') . '/js/node-type-form.js'),
    ),
  );

  $form['enquire_now']['enquire_now_webform_nid'] = array(
    '#title' => t('Webform ID'),
    '#description' => t('Select the webform to display in the Enquire Now section in Course pages.'),
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('webform'),
    '#era_cardinality' => 1,
    '#default_value' => variable_get('vu_enquire_now_webform_nid', NULL),
  );

  $region = !empty($form_state['values']['enquire_now_webform_region'])
    ? $form_state['values']['enquire_now_webform_region']
    : variable_get('vu_enquire_now_webform_region', 'content');
  $form['enquire_now']['enquire_now_webform_region'] = array(
    '#title' => t('Region'),
    '#description' => t('Select the region to attach the Enquire Now webform.'),
    '#type' => 'select',
    '#options' => system_region_list(variable_get('theme_default')),
    '#default_value' => $region,
    '#ajax' => array(
      'callback' => '_vu_enquire_now_form_node_type_form_ajax_callback',
      'wrapper' => 'enquire_now_webform_region_below_wrapper',
    ),
  );

  $blocks = _vu_enquire_now_load_blocks();
  $blocks[$region] = array_merge(
    array('_' => t('-- TOP OF REGION --')),
    $blocks[$region]
  );
  $block_position = !empty($form_state['values']['enquire_now_webform_region_below'])
    ? $form_state['values']['enquire_now_webform_region_below']
    : variable_get('vu_enquire_now_webform_region_below', 'system_main');
  $form['enquire_now']['enquire_now_webform_region_below'] = array(
    '#prefix' => '<div id="enquire_now_webform_region_below_wrapper">',
    '#title' => t('Position below'),
    '#description' => t('The Enquire Now webform will be positioned below the chosen block.'),
    '#type' => 'select',
    '#options' => $blocks[$region],
    '#default_value' => $block_position,
    '#suffix' => '</div>',
  );

  $form['#validate'][] = '_vu_enquire_now_form_node_type_form_validate';
  $form['#submit'][] = '_vu_enquire_now_form_node_type_form_submit';
}

/**
 * Ajax callback for selecting Region.
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 */
function _vu_enquire_now_form_node_type_form_ajax_callback($form, $form_state) {
  return $form['enquire_now']['enquire_now_webform_region_below'];
}

/**
 * Validation handler for Enquire Now settings in Courses Node type form.
 *
 * @param array $form
 * @param array $form_state
 */
function _vu_enquire_now_form_node_type_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (!empty($values['enquire_now_webform_nid']['entity_id'])) {
    $webform_nid = $values['enquire_now_webform_nid']['entity_id'];
    if (!node_load($webform_nid)) {
      form_set_error('enquire_now_webform_nid', t('Invalid webform selected.'));
      return;
    }
  }
}

/**
 * Submit handler for Enquire Now settings in Courses Node type form.
 *
 * @param array $form
 * @param array $form_state
 */
function _vu_enquire_now_form_node_type_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  variable_set('vu_enquire_now_webform', $values['enquire_now_webform']);
  variable_set('vu_enquire_now_webform_nid', $values['enquire_now_webform_nid']);
  variable_set('vu_enquire_now_webform_region', $values['enquire_now_webform_region']);
  variable_set('vu_enquire_now_webform_region_below', $values['enquire_now_webform_region_below']);
  if (!empty($values['enquire_now_webform_nid']['entity_id'])) {
    $webform_nid = $values['enquire_now_webform_nid']['entity_id'];
    $webform_node = node_load($webform_nid);
    if (!$webform_node->webform['block'] || !$webform_node->webform['webform_ajax']) {
      // Expose this webform as a block and Ajaxify it.
      $webform_node->webform['block'] = 1;
      $webform_node->webform['webform_ajax'] = 1;

      // Fake an original object as in node_save().
      $webform_node->original = clone $webform_node;
      // Save the webform settings only.
      webform_node_update($webform_node);
    }
  }
}

/**
 * Implements hook_form_alter()
 *
 * @param array $form
 * @param array $form_state
 * @param string $form_id
 */
function _vu_enquire_now_form_alter(&$form, &$form_state, $form_id) {
  $enquire_now = variable_get('vu_enquire_now_webform_nid', NULL);

  if (!empty($enquire_now['entity_id'])) {
    $enquire_form_notice = t('This webform is displayed as <strong>!link</strong> form on Course pages.',
      array('!link' => l('Enquire Now', 'admin/structure/types/manage/courses'))
    );

    switch ($form_id) {
      case 'webform_node_form':
        if ($form['#node']->nid == $enquire_now['entity_id']) {
          $form['vu_enquire_now'] = array(
            '#type' => 'markup',
            '#prefix' => '<div class="messages warning">',
            '#markup' => $enquire_form_notice,
            '#suffix' => '</div>',
            '#weight' => -999999,
          );
        }
        break;

      case 'webform_components_form':
        if ($form['#node']->nid == $enquire_now['entity_id']) {
          $form['#prefix'] = empty($form['#prefix']) ? '' : $form['#prefix'];
          $form['#prefix'] = '<div class="messages warning">' . $enquire_form_notice . '</div>' . $form['#prefix'];
        }
        break;
    }
  }
}

/**
 * Loads blocks' information of a theme from the database.
 *
 * @param string $theme_key
 *
 * @return array
 *
 * @see _block_load_blocks()
 */
function _vu_enquire_now_load_blocks($theme_key = NULL) {
  $theme_key = $theme_key ?: variable_get('theme_default');

  $system_blocks = array();

  $query = db_select('block', 'b');
  $result = $query
    ->fields('b')
    ->condition('b.theme', $theme_key)
    ->condition('b.status', 1)
    ->orderBy('b.region')
    ->orderBy('b.weight')
    ->orderBy('b.module')
    ->addTag('block_load')
    ->addTag('translatable')
    ->execute();

  $block_info = $result->fetchAllAssoc('bid');
  // Allow modules to modify the block list.
  drupal_alter('block_list', $block_info);

  $blocks = array();
  foreach ($block_info as $block) {
    if (!isset($system_blocks[$block->module])) {
      $system_blocks[$block->module] = module_invoke($block->module, 'block_info');
    }
    if (!empty($system_blocks[$block->module][$block->delta]['info'])) {
      $blocks[$block->region]["{$block->module}_{$block->delta}"] = $system_blocks[$block->module][$block->delta]['info'];
    }
  }
  return $blocks;
}
