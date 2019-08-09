<?php

/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_init().
 */
function vu_core_init() {
  module_invoke_all('vu_core_init');

  // Set campaign parameters if present.
  $params = drupal_get_query_parameters();
  foreach ($params as $key => $value) {
    if (strpos($key, 'utm_') !== FALSE) {
      vu_core_set_campaign_parameter($key, $value);
    }
  }
}

/**
 * Implements hook_preprocess().
 */
function vu_core_preprocess(&$vars, $hook) {
  drupal_alter('vu_core_preprocess', $vars, $hook);
  drupal_alter("vu_core_preprocess_{$hook}", $vars);
}

/**
 * Implements hook_form_alter().
 */
function vu_core_form_alter(&$form, $form_state, $form_id) {
  drupal_alter('vu_core_form', $form, $form_state, $form_id);
  drupal_alter("vu_core_form_{$form_id}", $form, $form_state);
  // Add submission handler for all client webforms.
  switch ($form_id) {
    case strstr($form_id, 'webform_client_form'):
      $form['#submit'][] = 'vu_core_webform_check_submissions';
      break;

    // Catch the block add/configure form and add custom submit handler.
    case 'block_add_block_form':
      // Add custom submit handler to block add form.
      $form_state['storage']['path'] = $_GET['q'];
      $form['#submit'][] = 'vu_core_insert';
      break;

    case 'block_admin_configure':
      // Add custom submit handler to block configuration form.
      $form_state['storage']['path'] = $_GET['q'];
      $form_state['storage']['original'] = block_load($form_state['build_info']['args'][0], $form_state['build_info']['args'][1]);
      $form['#submit'][] = 'vu_core_update';
      break;

    case 'block_custom_block_delete':
      // Add custom submit handler to block delete form.
      $form_state['storage']['path'] = $_GET['q'];
      $form_state['storage']['original'] = block_load($form_state['build_info']['args'][0], $form_state['build_info']['args'][1]);
      $form['#submit'][] = 'vu_core_delete';
      break;

    case 'bean_form':
      $form_state['storage']['path'] = $_GET['q'];
      $id = $form_state['build_info']['args'][0]->bid;
      ($id == '') ? ($form['#submit'][] = 'bean_insert') : ($form['#submit'][] = 'bean_update');
      break;

    case 'bean_delete_confirm':
      $form_state['storage']['path'] = $_GET['q'];
      $form['#submit'][] = 'vu_core_delete';
      break;

    case 'vu_chat_now_admin_form':
      $form_state['storage']['path'] = $_GET['q'];
      $form['#submit'][] = 'vu_core_chat_updated';
      break;
  }

  // PW-5272 restricting Author & Advanced Author to edit title.
  // Check that the form is a content type edit/create form.
  if (isset($form['#node']) && $form['#node']->type == 'page_builder') {
    if (!user_access('Restrict editing page title') && isset($form['title']['#default_value'])) {
      if (isset($form['title_field']['#type'])) {
        $form['title_field']['#disabled'] = TRUE;
      }
    }
  }
}

/**
 * Check for webform if it is enabled for not to store submissions.
 */
function vu_core_webform_check_submissions($form, &$form_state) {

  $sid = $form_state['values']['details']['sid'];
  $is_new = $form_state['values']['details']['is_new'];
  $node = $form['#node'];

  // Check if the flag (do_not_store_submission_data) is set.
  $wrapper = entity_metadata_wrapper('node', $node);
  $status = $wrapper->do_not_store_submission_data->value();

  if ($status && $sid && $is_new) {
    vu_core_webform_clear_submission($node, $sid);
  }
}

/**
 * Clear webform submission data.
 */
function vu_core_webform_clear_submission($node, $sid) {

  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $submission = webform_get_submission($node->nid, $sid);

  // Remove the submission.
  webform_submission_delete($node, $submission);

}

/**
 * Implements hook_query_alter().
 */
function vu_core_query_alter(QueryAlterableInterface $query) {
  drupal_alter('vu_core_query', $query);
}

/**
 * Implements hook_node_presave().
 */
function vu_core_node_presave($node) {
  drupal_alter('vu_core_node_presave', $node);
}

/**
 * Implements hook_node_view().
 */
function vu_core_node_view($node, $view_mode, $langcode) {
  drupal_alter('vu_core_node_view', $node, $view_mode, $langcode);
}

/**
 * Implements hook_permission().
 */
function vu_core_permission() {
  $permissions = [];
  drupal_alter('vu_core_permission', $permissions);
  return $permissions;
}

/**
 * Implements hook_block_view_alter().
 */
function vu_core_block_view_alter(&$data, $block) {
  drupal_alter('vu_core_block_view', $data, $block);

  $delta = str_replace('-', '_', $block->delta);
  drupal_alter("vu_core_block_{$delta}_view", $data, $block);
}

/**
 * Implements hook_module_implements_alter().
 */
function vu_core_module_implements_alter(&$implementations, $hook) {
  // Note: Best not to abstract this particular function, as it has a negative
  // impact on performance given how much is passed through this hook.
  switch ($hook) {
    // Ensure that only the VU hook is invoked.
    case 'paragraphs_item_access':
      $implementations = ['vu_core' => FALSE];
      break;
  }
}

/**
 * Implements hook_menu_get_item_alter().
 */
function vu_core_menu_get_item_alter(&$router_item, $path, $original_map) {
  if (isset(variable_get('vu_core_410_paths', [])[$path]) && user_is_anonymous()) {
    $router_item['delivery_callback'] = 'vu_core_deliver_410';
  }
}

/**
 * Implements hook_entity_view_alter().
 */
function vu_core_entity_view_alter(&$build, $type) {
  drupal_alter('vu_core_entity_view', $build, $type);
}

/**
 * Implements hook_entity_load().
 */
function vu_core_entity_load($entities, $type) {
  drupal_alter('vu_core_entity_load', $entities, $type);
  drupal_alter("vu_core_entity_load_{$type}", $entities);
}

/**
 * Implements hook_menu_link_alter().
 */
function vu_core_menu_link_alter(&$link) {
  if ($link['link_title'] == 'Contact us' && $link['menu_name'] == 'main-menu') {
    $link['options']['alter'] = TRUE;
  }
}

/**
 * Implements hook_translated_menu_link_alter().
 */
function vu_core_translated_menu_link_alter(&$link) {
  if ($link['link_title'] == 'Contact us' && $link['menu_name'] == 'main-menu') {
    // Add data tracking link.
    $link['localized_options']['attributes']['data-tracking'] = 'contact-us-link';
    if (vu_core_is_subsite()) {
      $subsite_node = vu_core_subsite_node_get();
      $subsite_metadata = vu_core_subsite_meta_get($subsite_node);
      if (!empty($subsite_metadata->contact_us_link)) {
        $link['href'] = $subsite_metadata->contact_us_link;
      }
      // Set link title.
      if (!empty($subsite_metadata->contact_us_title)) {
        $link['title'] = $subsite_metadata->contact_us_title;
      }
    }
  }
}
