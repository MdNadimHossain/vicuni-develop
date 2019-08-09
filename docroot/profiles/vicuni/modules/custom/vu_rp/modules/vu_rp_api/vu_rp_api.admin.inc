<?php

/**
 * @file
 * Admin page callbacks for the VU Researcher Profile API module.
 */

use Drupal\vu_rp_api\Config\ConfigManager;
use Drupal\vu_rp_api\FormBuilder;
use Drupal\vu_rp_api\Provider\ProviderManager;

/**
 * Configuration form.
 */
function vu_rp_api_admin_settings($form, $form_state) {
  if (module_exists('status_report')) {
    $form['status'] = [
      '#markup' => t('<div class="admin-panel">Check API status at !link</div>', [
        '!link' => l(t('Integration Status page'), 'admin/reports/integration-status-report'),
      ]),
    ];
  }

  $config_manager = new ConfigManager();
  $provider_manager = new ProviderManager($config_manager);
  $form_builder = new FormBuilder($config_manager, $provider_manager);
  $form = $form_builder->build($form, $form_state);

  $form['queues'] = [
    '#type' => 'fieldset',
    '#title' => t('Queue settings'),
    '#collapsible' => TRUE,
    '#collpsed' => FALSE,
  ];

  $form['queues']['vu_rp_api_list_cache_lifetime'] = [
    '#type' => 'textfield',
    '#title' => t('Account list cache lifetime'),
    '#description' => t('How many seconds to cache the list of accounts.'),
    '#default_value' => variable_get('vu_rp_api_list_cache_lifetime', 1800),
    '#size' => 10,
    '#required' => TRUE,
  ];

  $form['queues']['vu_rp_api_queue_account_batch_size'] = [
    '#type' => 'textfield',
    '#title' => t('Account queue batch size'),
    '#description' => t('How many accounts will be fetched in a single run'),
    '#default_value' => variable_get('vu_rp_api_queue_account_batch_size', 5),
    '#size' => 4,
    '#required' => TRUE,
  ];

  $form['queues']['vu_rp_api_queue_account_remove'] = [
    '#type' => 'textfield',
    '#title' => t('Remove item from the Account queue'),
    '#description' => t('How many failed requeue attempts it takes to completely remove an item from the Account queue and mark it as error'),
    '#default_value' => variable_get('vu_rp_api_queue_account_remove', 3),
    '#size' => 4,
    '#required' => TRUE,
  ];

  $form['queues']['vu_rp_api_queue_node_batch_size'] = [
    '#type' => 'textfield',
    '#title' => t('Node queue batch size'),
    '#description' => t('How many node will be processed in a single run'),
    '#default_value' => variable_get('vu_rp_api_queue_node_batch_size', 5),
    '#size' => 4,
    '#required' => TRUE,
  ];

  $form['queues']['vu_rp_api_queue_node_remove'] = [
    '#type' => 'textfield',
    '#title' => t('Remove item from the Node queue'),
    '#description' => t('How many failed requeue attempts it takes to completely remove an item from the Node queue and mark it as error'),
    '#default_value' => variable_get('vu_rp_api_queue_node_remove', 3),
    '#size' => 4,
    '#required' => TRUE,
  ];

  $form['#submit'][] = 'vu_rp_api_admin_settings_submit';

  return system_settings_form($form);
}

/**
 * Validation callback for required fields using States API.
 */
function _vu_rp_api_states_required_validate($element, $form_state) {
  FormBuilder::elementValidateRequiredFields($element, $form_state);
}

/**
 * Settings form submit handler.
 */
function vu_rp_api_admin_settings_submit($form, $form_state) {
  // Clear caches related to data retrieved from endpoints provided by
  // the provider.
  cache_clear_all('vu_rp_api_fetch_list', 'cache');
}

/**
 * Form for running provisioning from UI.
 */
function vu_rp_api_admin_force_run($form, $form_state) {
  $form['info'] = [
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  ];

  $form['info']['intro'] = [
    '#markup' => t('Use this form to force running of Researcher Profile API data processing. The run may take a lot of time.') . '<br/><br/>',
  ];

  $items = [];
  /** @var \DrupalQueueInterface $queue_accounts */
  $queue_accounts = DrupalQueue::get(VU_RP_API_QUEUE_NAME_ACCOUNT);
  $account_count = $queue_accounts->numberOfItems();
  $item = t('<strong>Account queue:</strong> @count', ['@count' => $account_count]);
  if ($account_count > 0) {
    $item .= ' ' . l(t('Inspect'), 'admin/config/system/queue-ui/inspect/' . VU_RP_API_QUEUE_NAME_ACCOUNT);
  }
  $items[] = $item;

  /** @var \DrupalQueueInterface $queue_nodes */
  $queue_nodes = DrupalQueue::get(VU_RP_API_QUEUE_NAME_NODE);
  $node_count = $queue_nodes->numberOfItems();
  $item = t('<strong>Nodes queue:</strong> @count', ['@count' => $node_count]);
  if ($node_count > 0) {
    $item .= ' ' . l(t('Inspect'), 'admin/config/system/queue-ui/inspect/' . VU_RP_API_QUEUE_NAME_NODE);
  }
  $items[] = $item;

  $item = t('<strong>Total Researcher Profile Nodes: </strong> @count', ['@count' => vu_rp_count_nodes_of_type('researcher_profile')]);
  $item .= ' ' . l(t('Browse'), 'admin/content', ['query' => ['type' => 'researcher_profile']]);
  $items[] = $item;

  $form['info']['queues'] = [
    '#theme' => 'item_list',
    '#items' => $items,
  ];

  $options = [
    'fetch_list' => t('1. Fetch list'),
    'fetch_accounts' => t('2. Fetch accounts'),
    'process_nodes' => t('3. Process nodes'),
  ];
  $form['stages'] = [
    '#title' => t('Stages'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => array_keys($options),
    '#required' => TRUE,
  ];

  $form['count'] = [
    '#title' => t('Number of items to process'),
    '#type' => 'textfield',
    '#default_value' => 5,
    '#size' => 5,
    '#element_validate' => ['element_validate_integer_positive'],
    '#required' => TRUE,
  ];

  $form['run'] = [
    '#value' => t('Run'),
    '#type' => 'submit',
  ];

  $form['reset'] = [
    '#value' => t('Reset'),
    '#type' => 'submit',
    '#description' => t('Reset all cached data and all queued items'),
  ];

  return $form;
}

/**
 * Submit handler to forcefully run provisioning.
 */
function vu_rp_api_admin_force_run_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == 'Reset') {
    vu_rp_api_reset_all();
    drupal_set_message(t('Reset all caches and queues'));

    return;
  }

  /** @var \DrupalQueueInterface $queue_accounts */
  $queue_accounts = DrupalQueue::get(VU_RP_API_QUEUE_NAME_ACCOUNT);
  /** @var \DrupalQueueInterface $queue_nodes */
  $queue_nodes = DrupalQueue::get(VU_RP_API_QUEUE_NAME_NODE);

  $count = $form_state['values']['count'];
  if (!empty($form_state['values']['stages']['fetch_list'])) {
    drupal_set_message(t('STAGE 1. Accounts in queue BEFORE fetching list: @count', ['@count' => $queue_accounts->numberOfItems()]));
    vu_rp_api_fetch_list(0);
    drupal_set_message(t('STAGE 1. Accounts in queue AFTER fetching list: @count', ['@count' => $queue_accounts->numberOfItems()]));
  }

  if (!empty($form_state['values']['stages']['fetch_accounts'])) {
    drupal_set_message(t('STAGE 2. Accounts in queue BEFORE fetching accounts: @count', ['@count' => $queue_accounts->numberOfItems()]));
    drupal_set_message(t('STAGE 2. Nodes in queue BEFORE fetching accounts: @count', ['@count' => $queue_nodes->numberOfItems()]));
    vu_rp_api_fetch_accounts($count);
    drupal_set_message(t('STAGE 2. Accounts in queue AFTER fetching accounts: @count', ['@count' => $queue_accounts->numberOfItems()]));
    drupal_set_message(t('STAGE 2. Nodes in queue AFTER fetching accounts: @count', ['@count' => $queue_nodes->numberOfItems()]));
  }

  if (!empty($form_state['values']['stages']['process_nodes'])) {
    drupal_set_message(t('STAGE 3. Nodes in queue BEFORE processing nodes: @count', ['@count' => $queue_nodes->numberOfItems()]));
    vu_rp_api_process_nodes($count);
    drupal_set_message(t('STAGE 3. Nodes in queue AFTER processing nodes: @count', ['@count' => $queue_nodes->numberOfItems()]));
  }

  // Rebuild the form in order to keep filter values.
  $form_state['rebuild'] = TRUE;
}
