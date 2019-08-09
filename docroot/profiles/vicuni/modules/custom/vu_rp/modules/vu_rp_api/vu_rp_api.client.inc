<?php

/**
 * @file
 * Code for the VU Researcher Profile API integration.
 */

use Drupal\vu_rp_api\Client\Client;
use Drupal\vu_rp_api\Client\RestInterface;
use Drupal\vu_rp_api\Config\ConfigManager;
use Drupal\vu_rp_api\Endpoint\FieldMapper;
use Drupal\vu_rp_api\FormBuilder;
use Drupal\vu_rp_api\Logger\Logger;
use Drupal\vu_rp_api\Provider\ProviderManager;

/**
 * API client instantiation.
 *
 * Use this function to get access to an API client from any function.
 *
 * @param bool $reset
 *   Optional flag to reset cached client. Setting this to TRUE will reload
 *   client's configuration and will reset all internal client's caches.
 *
 * @return Drupal\vu_rp_api\Client\Client
 *   API client instance.
 *
 * @throws \Exception
 *   In case if there is a problem with configuration instantiation.
 */
function vu_rp_api_get_client($reset = FALSE) {
  $client =& drupal_static(__FUNCTION__);

  if (!$client || $reset) {
    try {
      $config_manager = new ConfigManager();
      $provider_manager = new ProviderManager($config_manager);
      $logger = vu_rp_api_get_logger();
      $client = new Client($config_manager, $provider_manager, $logger);
    }
    // Purposely using main \Exception to catch anything.
    catch (\Exception $exception) {
      throw new \Exception(t('Unable to initialise API client: @message', [
        '@message' => $exception->getMessage(),
      ]));
    }
  }

  return $client;
}

/**
 * API logger instantiation.
 *
 * Use this function everywhere in code where logger is required.
 *
 * @param bool $reset
 *   Optional flag to reset internal logger cache.
 *
 * @return \Drupal\vu_rp_api\Logger\LoggerInterface
 *   Logger instance.
 */
function vu_rp_api_get_logger($reset = FALSE) {
  $logger =& drupal_static(__FUNCTION__);

  if (!$logger || $reset) {
    $logger = new Logger();
  }

  return $logger;
}

/**
 * Implements hook_vu_rp_api_providers().
 */
function vu_rp_api_vu_rp_api_providers() {
  return [
    'dev' => t('VU Dev'),
    'prod' => t('VU Prod'),
    'local' => t('Local'),
    'test2' => t('Test2'),
  ];
}

/**
 * Implements hook_vu_rp_api_endpoints().
 */
function vu_rp_api_vu_rp_api_endpoints() {
  return [
    'list' => [
      'title' => t('List'),
      'method' => RestInterface::METHOD_GET,
      'format' => RestInterface::FORMAT_JSON,
      'timeout' => 180,
      'schema' => _vu_rp_api_list_schema(),
    ],
    'account' => [
      'title' => t('Account'),
      'method' => RestInterface::METHOD_GET,
      'format' => RestInterface::FORMAT_JSON,
      'timeout' => 180,
      'schema' => _vu_rp_api_account_schema(),
    ],
  ];
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_prod_list_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_list_form($form_builder);
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_dev_list_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_list_form($form_builder);
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_local_list_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_list_form($form_builder);
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_test2_list_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_list_form($form_builder);
}

/**
 * List endpoint configuration form.
 */
function _vu_rp_api_list_form(FormBuilder $form_builder) {
  $form['url'] = [
    '#type' => 'textfield',
    '#title' => t('List endpoint URL'),
    '#description' => t('Endpoint URL to retrieve a list of accounts'),
    '#required' => TRUE,
    '#default_value' => $form_builder->getDefaultValue('url'),
  ];

  $form['auth_username'] = [
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('HTTP Authentication username'),
    '#required' => FALSE,
    '#default_value' => $form_builder->getDefaultValue('auth_username'),
  ];

  $form['auth_password'] = [
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('HTTP Authentication password'),
    '#required' => FALSE,
    '#default_value' => $form_builder->getDefaultValue('auth_password'),
  ];

  $form['timeout'] = [
    '#type' => 'textfield',
    '#title' => t('Timeout'),
    '#description' => t('Timeout in seconds after which the response is no longer expected'),
    '#required' => TRUE,
    '#default_value' => $form_builder->getDefaultValue('timeout'),
  ];

  return $form;
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_prod_account_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_account_form($form_builder);
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_dev_account_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_account_form($form_builder);
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_local_account_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_account_form($form_builder);
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_form().
 */
function vu_rp_api_vu_rp_api_test2_account_form($form, $form_state, FormBuilder $form_builder) {
  return _vu_rp_api_account_form($form_builder);
}

/**
 * Account endpoint configuration form.
 */
function _vu_rp_api_account_form(FormBuilder $form_builder) {
  $form['url'] = [
    '#type' => 'textfield',
    '#title' => t('Account endpoint URL'),
    '#description' => t('Endpoint URL to retrieve each separate account'),
    '#required' => TRUE,
    '#default_value' => $form_builder->getDefaultValue('url'),
  ];

  $form['auth_username'] = [
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('HTTP Authentication username'),
    '#required' => FALSE,
    '#default_value' => $form_builder->getDefaultValue('auth_username'),
  ];

  $form['auth_password'] = [
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('HTTP Authentication password'),
    '#required' => FALSE,
    '#default_value' => $form_builder->getDefaultValue('auth_password'),
  ];

  $form['timeout'] = [
    '#type' => 'textfield',
    '#title' => t('Timeout'),
    '#description' => t('Timeout in seconds after which the response is no longer expected'),
    '#required' => TRUE,
    '#default_value' => $form_builder->getDefaultValue('timeout'),
  ];

  $form_builder->formStackPush('status');
  $test_account_default = $form_builder->getDefaultValue('test_account');
  $form['status'] = [
    '#title' => t('Status'),
    '#description' => t('Check the status of the endpoints by going to !link', [
      '!link' => l(t('API status report page'), 'admin/reports/integration-status-report'),
    ]),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => $test_account_default,
  ];

  $form['status']['test_account'] = [
    '#type' => 'textfield',
    '#title' => t('Account for status check'),
    '#description' => t('Existing staff account to use for status checks'),
    '#required' => TRUE,
    '#default_value' => $test_account_default,
  ];

  $form_builder->formStackPop();

  return $form;
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_schema().
 */
function vu_rp_api_vu_rp_api_prod_list_schema($entity, $provider, $endpoint) {
  return _vu_rp_api_list_schema();
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_schema().
 */
function vu_rp_api_vu_rp_api_dev_list_schema($entity, $provider, $endpoint) {
  return _vu_rp_api_list_schema();
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_schema().
 */
function vu_rp_api_vu_rp_api_local_list_schema($entity, $provider, $endpoint) {
  return _vu_rp_api_list_schema();
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_schema().
 */
function vu_rp_api_vu_rp_api_dev_account_schema($entity, $provider, $endpoint) {
  return _vu_rp_api_account_schema();
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_schema().
 */
function vu_rp_api_vu_rp_api_prod_account_schema($entity, $provider, $endpoint) {
  return _vu_rp_api_account_schema();
}

/**
 * Implements hook_vu_rp_api_PROVIDER_ENDPOINT_schema().
 */
function vu_rp_api_vu_rp_api_local_account_schema($entity, $provider, $endpoint) {
  return _vu_rp_api_account_schema();
}

/**
 * Schema for 'list' endpoint.
 */
function _vu_rp_api_list_schema() {
  return [
    'Researchers' => [
      'type' => FieldMapper::TYPE_ARRAY,
      'children' => [
        'staffID' => ['type' => FieldMapper::TYPE_STRING],
      ],
    ],
  ];
}

/**
 * Schema for 'account' endpoint.
 */
function _vu_rp_api_account_schema() {
  return [
    'ResearcherProfile' => [
      'type' => FieldMapper::TYPE_ARRAY,
      'is_root' => TRUE,
      'children' => [
        'staffID' => [
          'field' => 'field_rpa_staff_id',
          'type' => FieldMapper::TYPE_STRING,
          'is_primary' => TRUE,
        ],
        'firstName' => [
          'field' => 'field_rpa_first_name',
          'callback' => 'vu_rp_api_field_callback_first_name',
        ],
        'secondName' => [
          'field' => 'field_rpa_middle_name',
          'callback' => 'vu_rp_api_field_callback_first_name',
        ],
        'lastName' => [
          'field' => 'field_rpa_last_name',
          'callback' => 'vu_rp_api_field_callback_last_name',
        ],
        'preferredName' => [
          'field' => 'field_rpa_preferred_name',
          'callback' => 'vu_rp_api_field_callback_first_name',
        ],
        'orcID' => 'field_rpa_orcid_id',
        'email' => [
          'field' => 'field_rpa_email',
          'callback' => 'vu_rp_api_field_callback_email',
          'value_key' => 'email',
        ],
        'jobTitle' => 'field_rpa_job_title',
        'publications' => [
          'type' => FieldMapper::TYPE_ARRAY,
          'callback' => 'vu_rp_api_field_callback_publications',
          'field' => 'MULTIPLE_FIELDS_IN_CALLBACK',
          'children' => [
            'type' => FieldMapper::TYPE_STRING,
            'title' => FieldMapper::TYPE_STRING,
            'publicationDate' => FieldMapper::TYPE_STRING,
            'authors' => FieldMapper::TYPE_STRING,
            'url' => FieldMapper::TYPE_STRING,
            'recordID' => FieldMapper::TYPE_STRING,
            'favouritePublication' => FieldMapper::TYPE_STRING,
            'journalTitle' => FieldMapper::TYPE_STRING,
            'volume' => FieldMapper::TYPE_INTEGER,
            'issue' => FieldMapper::TYPE_INTEGER,
            'paginationBegin' => FieldMapper::TYPE_INTEGER,
            'paginationEnd' => FieldMapper::TYPE_INTEGER,
            'location' => FieldMapper::TYPE_STRING,
            'publisher' => FieldMapper::TYPE_STRING,
            'bookTitle' => FieldMapper::TYPE_STRING,
            'DOI' => FieldMapper::TYPE_STRING,
            'titleOfPaper' => FieldMapper::TYPE_STRING,
            'titleOfConf' => FieldMapper::TYPE_STRING,
            'editor' => FieldMapper::TYPE_STRING,
            'edition' => FieldMapper::TYPE_STRING,
          ],
        ],
        'grantDetails' => [
          'type' => FieldMapper::TYPE_ARRAY,
          'callback' => 'vu_rp_api_field_callback_funding',
          'field' => 'MULTIPLE_FIELDS_IN_CALLBACK',
          'children' => [
            'projectType' => FieldMapper::TYPE_STRING,
            'startDate' => FieldMapper::TYPE_STRING,
            'endDate' => FieldMapper::TYPE_STRING,
            'grantAmount' => FieldMapper::TYPE_INTEGER,
            'grantFundSource' => FieldMapper::TYPE_STRING | FieldMapper::TYPE_NULL,
            'otherInvestigators' => [
              'type' => FieldMapper::TYPE_ARRAY,
              'children' => [
                'staffID' => FieldMapper::TYPE_STRING,
                'role' => FieldMapper::TYPE_STRING,
                'firstName' => FieldMapper::TYPE_STRING,
                'lastName' => FieldMapper::TYPE_STRING,
                'honorific' => FieldMapper::TYPE_STRING,
              ],
            ],
          ],
          'confidential' => FieldMapper::TYPE_BOOLEAN,
        ],
        'HDRDetails' => [
          'type' => FieldMapper::TYPE_ARRAY,
          'callback' => 'vu_rp_api_field_callback_supervision',
          'field' => 'MULTIPLE_FIELDS_IN_CALLBACK',
          'children' => [
            'yearOfCompletion' => FieldMapper::TYPE_STRING | FieldMapper::TYPE_NULL,
            'HDRType' => FieldMapper::TYPE_STRING,
            'supervisionRole' => FieldMapper::TYPE_STRING,
          ],
        ],
      ],
    ],
  ];
}

/**
 * Check that staff id is blacklisted for processing.
 */
function _vu_rp_api_account_is_blacklisted($staff_id) {
  $is_blacklisted = FALSE;

  // Allow to alter the list for blacklisting some ids.
  drupal_alter('vu_rp_api_account_is_blacklisted', $is_blacklisted, $staff_id);

  return $is_blacklisted;
}

/**
 * Disable API processing for accounts.
 */
function vu_rp_api_disable_account_processing($message = '') {
  $logger = vu_rp_api_get_logger();

  variable_set(VU_RP_API_VARIABLE_NAME_ALLOW_ACCOUNT_PROCESSING, FALSE);
  $logger->log(__FUNCTION__, 'Suspended account processing: ' . $message, Logger::SEVERITY_WARNING);
}

/**
 * Enable API processing for accounts.
 */
function vu_rp_api_enable_account_processing($message = '') {
  $logger = vu_rp_api_get_logger();

  variable_set(VU_RP_API_VARIABLE_NAME_ALLOW_ACCOUNT_PROCESSING, TRUE);
  $logger->log(__FUNCTION__, 'Allowed account processing: ' . $message, Logger::SEVERITY_INFO);
}

/**
 * Check if it is allowed to fetch accounts.
 */
function vu_rp_api_is_allowed_account_fetching() {
  return variable_get(VU_RP_API_VARIABLE_NAME_ALLOW_ACCOUNT_PROCESSING, TRUE);
}

/**
 * Check if it is allowed to fetch list.
 */
function vu_rp_api_is_allowed_list_fetching() {
  // @note: This may later have more conditions to stop list fetching.
  return vu_rp_api_is_allowed_account_fetching();
}

/**
 * Reset API processing state, queues and caches.
 */
function vu_rp_api_reset_all() {
  /** @var \DrupalQueueInterface $queue_accounts */
  $queue_accounts = DrupalQueue::get(VU_RP_API_QUEUE_NAME_ACCOUNT);
  $queue_accounts->deleteQueue();
  /** @var \DrupalQueueInterface $queue_nodes */
  $queue_nodes = DrupalQueue::get(VU_RP_API_QUEUE_NAME_NODE);
  $queue_nodes->deleteQueue();

  cache_clear_all('vu_rp_api_fetch_list', 'cache');
}

/**
 * Provision profile for account with specified staff id.
 *
 * @param string $staff_id
 *   Staff id.
 * @param bool $verbose
 *   Flag to print verbose messages during provisioning. Defaults to TRUE.
 *
 * @return string
 *   Node id of provisioned node.
 */
function vu_rp_api_provision_profile($staff_id, $verbose = TRUE) {
  $client = vu_rp_api_get_client();

  try {
    vu_core_staff_id_validate($staff_id);
  }
  catch (\Exception $exception) {
    $message = sprintf('Invalid staff id provided "%s"', $staff_id);
    $client->getLogger()->log(__FUNCTION__, $message, Logger::SEVERITY_WARNING);
    if ($verbose) {
      drupal_set_message($message, 'error');
    }

    return FALSE;
  }

  try {
    $response = $client->fetch('account', ['account' => $staff_id]);
  }
  catch (Exception $exception) {
    $message = sprintf('Unable to fetch account "%s": %s', $staff_id, $exception->getMessage());
    $client->getLogger()->log(__FUNCTION__, $message, Logger::SEVERITY_WARNING);
    if ($verbose) {
      drupal_set_message($message, 'error');
    }

    return FALSE;
  }

  $payload = $response->getContent();

  try {
    $data = Client::jsonDecode($payload, TRUE);
  }
  catch (Exception $exception) {
    $message = sprintf('Unable to decode JSON payload: %s', $payload);
    $client->getLogger()->log(__FUNCTION__, $message, Logger::SEVERITY_WARNING);
    if ($verbose) {
      drupal_set_message($message, 'error');
    }

    return FALSE;
  }

  try {
    $nid = $client->processEntity($data);
  }
  catch (Exception $exception) {
    $message = sprintf('Unable to process node: %s', $exception->getMessage());
    $client->getLogger()->log(__FUNCTION__, $message, Logger::SEVERITY_WARNING);
    if ($verbose) {
      drupal_set_message($message, 'error');
    }

    return FALSE;
  }

  $message = sprintf('Processed node "%s"', $staff_id);
  $client->getLogger()->log(__FUNCTION__, $message);

  return $nid;
}
