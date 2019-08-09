<?php

/**
 * @file
 * Cron functionality for Researcher Profile API integration.
 */

use Drupal\vu_rp_api\Client\Client;
use Drupal\vu_rp_api\Exception;
use Drupal\vu_rp_api\Logger\Logger;

/**
 * Implements hook_cronapi().
 */
function vu_rp_api_cronapi($op, $job = NULL) {
  $items['vu_rp_api_fetch_list'] = [
    'description' => 'VU RP API: Fetch list of accounts',
    // Every day at 10 pm.
    'rule' => '0 22 1/1 * *',
  ];

  $items['vu_rp_api_fetch_accounts'] = [
    'description' => 'VU RP API: Fetch accounts',
    // Every 15 minutes.
    'rule' => '*/10 * * * *',
  ];

  $items['vu_rp_api_process_nodes'] = [
    'description' => 'VU RP API: Process nodes',
    // Every 15 minutes.
    'rule' => '*/10 * * * *',
  ];

  $items['vu_rp_clean_rp_log_db_table'] = [
    'description' => 'VU RP: log clean up',
    // Every day at 9 pm.
    'rule' => '0 21 1/1 * *',
  ];

  return $items;
}

/**
 * Callback to fetch accounts list.
 *
 * This will fetch a list of accounts, but all payload processing is
 * delegated to vu_rp_api_process_fetched_list().
 *
 * @param null|int $expire
 *   Number of seconds to cache the response for. If not specified, internal
 *   configuration value will be used or, if it is not specified as well,
 *   30 minutes is used.
 *
 * @see vu_rp_api_process_fetched_list()
 */
function vu_rp_api_fetch_list($expire = NULL) {
  $expire = $expire ? $expire : variable_get('vu_rp_api_list_cache_lifetime', 1800);

  $cid = __FUNCTION__;
  $cache = cache_get($cid);
  $content = $cache ? $cache->data : NULL;

  $logger = vu_rp_api_get_logger();
  if (!$content) {
    $client = vu_rp_api_get_client();

    if (!vu_rp_api_is_allowed_list_fetching()) {
      $logger->log(__FUNCTION__, 'List fetching is disabled', Logger::SEVERITY_WARNING);

      return;
    }

    try {
      $response = $client->fetch('list');
    }
    catch (Exception $exception) {
      $logger->log(__FUNCTION__, 'Unable to fetch the list of accounts: ' . $exception->getMessage(), Logger::SEVERITY_WARNING);

      return;
    }

    $content = $response->getContent();

    cache_set($cid, $content, 'cache', REQUEST_TIME + $expire);
  }
  else {
    $logger->log(__FUNCTION__, 'Using cached list');
  }

  vu_rp_api_process_fetched_list($content);
}

/**
 * Process accounts list payload.
 *
 * This will add extracted items to VU_RP_API_QUEUE_NAME_ACCOUNT queue for
 * processing.
 *
 * @param string $payload
 *   Payload received from the remote location.
 */
function vu_rp_api_process_fetched_list($payload) {
  $client = vu_rp_api_get_client();
  $logger = $client->getLogger();

  /** @var \DrupalQueueInterface $queue */
  $queue = DrupalQueue::get(VU_RP_API_QUEUE_NAME_ACCOUNT);

  $data = json_decode($payload, TRUE);
  $messages = [];
  // @note: Refactor this to use endpoint's field mapping.
  foreach ($data['Researchers'] as $researcher) {
    $id = vu_core_normalise_staff_id($researcher['staffID']);
    if (!_vu_rp_api_account_is_blacklisted($id)) {
      $added = $queue->createItem([
        'attempts' => 0,
        'content' => $id,
      ]);
      if ($added) {
        $messages[] = sprintf('Added to account queue: "%s"', $id);
      }
      else {
        $logger->log(__FUNCTION__, sprintf('Unable to add an account "%s" to queue for fetching', $id), Logger::SEVERITY_WARNING);
      }
    }
    else {
      $messages[] = sprintf('Skipped: "%s" (not whitelisted)', $id);
    }
  }

  $logger->log(__FUNCTION__, implode(PHP_EOL, $messages));
}

/**
 * Callback to fetch multiple accounts.
 *
 * This will try to fetch accounts using the data from
 * VU_RP_API_QUEUE_NAME_ACCOUNT queue. Each items will be re-tried
 * 'vu_rp_api_queue_account_remove' times. Failed items are added to the
 * beginning of the queue. After reaching the limit of re-tries, the item is
 * permanently removed from the queue.
 *
 * IMPORTANT: If all items from the batch fail - the fetching mechanism
 * considers that API is not available and disables processing until it is
 * enabled again manually.
 *
 * Processing of each item happens in vu_rp_api_process_fetched_account().
 *
 * @param null|int $batch_size
 *   Optional batch size. If not provided, the value from
 *   'vu_rp_api_queue_account_batch_size' variable will be used or, if this
 *   variable is not set, the size will be set to 5.
 *
 * @see vu_rp_api_process_fetched_account()
 */
function vu_rp_api_fetch_accounts($batch_size = NULL) {
  $batch_size = $batch_size ? $batch_size : variable_get('vu_rp_api_queue_account_batch_size', 5);

  $client = vu_rp_api_get_client();

  // Gate to stop processing.
  if (!vu_rp_api_is_allowed_account_fetching()) {
    $client->getLogger()->log(__FUNCTION__, 'Account processing is disabled', Logger::SEVERITY_WARNING);

    return;
  }

  /** @var \DrupalQueueInterface $queue */
  $queue = DrupalQueue::get(VU_RP_API_QUEUE_NAME_ACCOUNT);

  if ($queue->numberOfItems() == 0) {
    $client->getLogger()->log(__FUNCTION__, 'Account fetch queue is empty');

    return;
  }

  $remove_after = variable_get('vu_rp_api_queue_account_remove', 3);

  $unclaimed_items_count = 0;
  for ($i = 0; $i < $batch_size; $i++) {
    if ($queue->numberOfItems() == 0) {
      // No more items to process.
      break;
    }

    $item = $queue->claimItem();

    if (!$item) {
      // Track unclaimed items count to then disable fetching on too many
      // errors.
      $unclaimed_items_count++;
      $client->getLogger()->log(__FUNCTION__, 'Unable to claim an item', Logger::SEVERITY_WARNING);
      continue;
    }

    $staff_id = $item->data['content'];
    try {
      $response = $client->fetch('account', ['account' => $staff_id]);
    }
    catch (Exception $exception) {
      $client->getLogger()->log(__FUNCTION__, sprintf('Unable to fetch account "%s": %s', $staff_id, $exception->getMessage()), Logger::SEVERITY_WARNING);
      // Re-queue an item, if it has not been re-queued enough times before.
      $queue->deleteItem($item);
      if ($item->data['attempts'] < $remove_after) {
        $item->data['attempts']++;
        $queue->createItem($item->data);
        $client->getLogger()->log(__FUNCTION__, sprintf('Re-queued account "%s" (attempt %s)', $staff_id, $item->data['attempts']), Logger::SEVERITY_WARNING);
      }
      else {
        $client->getLogger()->log(__FUNCTION__, sprintf('Unable to requeue account "%s" - attempts threshold is reached (attempt %s)', $staff_id, $item->data['attempts']), Logger::SEVERITY_ERROR);
      }
      continue;
    }

    vu_rp_api_process_fetched_account($staff_id, $response->getContent());

    // Successfully processed an item - remove it from the queue.
    $queue->deleteItem($item);
  }

  if ($unclaimed_items_count == $batch_size) {
    vu_rp_api_disable_account_processing('Too many unclaimed items while fetching an account');
  }
}

/**
 * Process account payload.
 *
 * This converts account payload data into expected internal format and adds
 * it to VU_RP_API_QUEUE_NAME_NODE queue for further processing.
 *
 * @param string $staff_id
 *   Staff ID.
 * @param string $payload
 *   Payload for account.
 */
function vu_rp_api_process_fetched_account($staff_id, $payload) {
  $client = vu_rp_api_get_client();

  try {
    $data = Client::jsonDecode($payload, TRUE);
  }
  catch (Exception $exception) {
    $client->getLogger()->log(__FUNCTION__, sprintf('Unable to decode JSON payload: %s', $payload), Logger::SEVERITY_WARNING);

    return;
  }

  /** @var \DrupalQueueInterface $queue */
  $queue = DrupalQueue::get(VU_RP_API_QUEUE_NAME_NODE);
  $added = $queue->createItem([
    'attempts' => 0,
    'content' => $data,
  ]);

  if ($added) {
    $messages[] = sprintf('Added to node queue: "%s"', $staff_id);
  }
  else {
    $client->getLogger()->log(__FUNCTION__, sprintf('Unable to add an account "%s" to node queue for processing', $staff_id), Logger::SEVERITY_WARNING);
  }

  $client->getLogger()->log(__FUNCTION__, implode(PHP_EOL, $messages));
}

/**
 * Callback to process nodes.
 *
 * This will try to process nodes using the data from VU_RP_API_QUEUE_NAME_NODE
 * queue. Each items will be re-tried 'vu_rp_api_queue_node_remove' times.
 * Failed items are added to the beginning of the queue. After reaching the
 * limit of re-tries, the item is permanently removed from the queue.
 *
 * IMPORTANT: If all items from the batch fail - the fetching mechanism
 * considers that API is not available and disables processing until it is
 * enabled again manually.
 *
 * @param null|int $batch_size
 *   Optional batch size to process. If not specified, the value from variable
 *   'vu_rp_api_queue_node_batch_size' will be used or, if not set, the size
 *   will be set to 5.
 */
function vu_rp_api_process_nodes($batch_size = NULL) {
  $batch_size = $batch_size ? $batch_size : variable_get('vu_rp_api_queue_node_batch_size', 5);

  $client = vu_rp_api_get_client();

  $logger = vu_rp_api_get_logger();

  // Gate to stop processing.
  if (!vu_rp_api_is_allowed_account_fetching()) {
    $logger->log(__FUNCTION__, 'Account processing is disabled', Logger::SEVERITY_WARNING);

    return;
  }

  /** @var \DrupalQueueInterface $queue */
  $queue = DrupalQueue::get(VU_RP_API_QUEUE_NAME_NODE);

  if ($queue->numberOfItems() == 0) {
    $logger->log(__FUNCTION__, 'Node processing queue is empty');

    return;
  }

  $remove_after = variable_get('vu_rp_api_queue_node_remove', 3);

  $unclaimed_items_count = 0;
  for ($i = 0; $i < $batch_size; $i++) {
    if ($queue->numberOfItems() == 0) {
      // No more items to process.
      break;
    }

    $item = $queue->claimItem();

    if (!$item) {
      // Track unclaimed items count to then disable processing on too many
      // errors.
      $unclaimed_items_count++;
      $logger->log(__FUNCTION__, 'Unable to claim a node item', Logger::SEVERITY_WARNING);
      continue;
    }

    $data = $item->data['content'];
    try {
      $id = $client->processEntity($data);
    }
    catch (Exception $exception) {
      $logger->log(__FUNCTION__, sprintf('Unable to process node: %s', $exception->getMessage()), Logger::SEVERITY_WARNING);

      // Re-queue an item, if it has not been re-queued enough times before.
      $queue->deleteItem($item);
      if ($item->data['attempts'] < $remove_after) {
        $item->data['attempts']++;
        $queue->createItem($item->data);
        $client->getLogger()->log(__FUNCTION__, sprintf('Re-queued node processing (attempt %s)', $item->data['attempts']), Logger::SEVERITY_WARNING);
      }
      else {
        $client->getLogger()->log(__FUNCTION__, sprintf('Unable to requeue node - attempts threshold is reached (attempt %s)', $item->data['attempts']), Logger::SEVERITY_ERROR);
      }

      continue;
    }

    $logger->log(__FUNCTION__, sprintf('Processed node "%s"', $id));

    // Successfully processed an item - remove it from the queue.
    $queue->deleteItem($item);
  }

  if ($unclaimed_items_count == $batch_size) {
    vu_rp_api_disable_account_processing('Too many unclaimed items while processing nodes');
  }
}

/**
 * Implements function to delete the rp logs older than a month.
 */
function vu_rp_clean_rp_log_db_table() {
  $interval = strtotime('-1 month');
  $time_delete_rp_log = variable_get('time_delete_rp_log', $interval);

  if (!empty($time_delete_rp_log)) {
    $query = db_delete('vu_rp_log');
    $query->condition('timestamp', $time_delete_rp_log, '<');
    $query->execute();
  }
}
