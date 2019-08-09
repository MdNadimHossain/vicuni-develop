<?php

namespace Drupal\vu_rp_api\Client;

use Drupal\vu_rp_api\Exception;
use Drupal\vu_rp_api\Logger\Logger;

/**
 * @file
 * Client class to handle all communication with API providers.
 */

/**
 * Class Client.
 */
class Client {

  /**
   * Defines default HTTP client class.
   */
  const HTTP_CLIENT_CLASS_DEFAULT = __NAMESPACE__ . '\HttpClient';

  /**
   * HTTP client.
   *
   * @var HttpClient
   */
  protected $httpClient;

  /**
   * Config manager.
   *
   * @var \Drupal\vu_rp_api\Config\ConfigManager
   */
  protected $configManager;

  /**
   * Provider manager.
   *
   * @var \Drupal\vu_rp_api\Provider\ProviderManager
   */
  protected $providerManager;

  /**
   * Current provider.
   *
   * @var \Drupal\vu_rp_api\Provider\Provider
   */
  protected $currentProvider;

  /**
   * Logger instance.
   *
   * @var \Drupal\vu_rp_api\Logger\Logger
   */
  protected $logger;

  /**
   * Client constructor.
   *
   * @param \Drupal\vu_rp_api\Config\ConfigManager $configManager
   *   The config manager.
   * @param \Drupal\vu_rp_api\Provider\ProviderManager $providerManager
   *   The provider manager.
   * @param \Drupal\vu_rp_api\Logger\LoggerInterface $logger
   *   Logger instance.
   */
  public function __construct($configManager, $providerManager, $logger) {
    $this->configManager = $configManager;
    $this->providerManager = $providerManager;
    $this->logger = $logger;
    $this->initHttpClient();
    $this->initCurrentProvider();
  }

  /**
   * Get current HTTP client.
   *
   * @return \Drupal\vu_rp_api\Client\HttpClient
   *   The HTTP client instance.
   */
  public function getHttpClient() {
    return $this->httpClient;
  }

  /**
   * Set HTTP client.
   *
   * @param \Drupal\vu_rp_api\Client\HttpClient $httpClient
   *   The HTTP client instance.
   *
   * @return Client
   *   Current client.
   */
  public function setHttpClient($httpClient) {
    $this->httpClient = $httpClient;

    return $this;
  }

  /**
   * Config manager getter.
   */
  public function getConfigManager() {
    return $this->configManager;
  }

  /**
   * Config manager setter.
   */
  public function setConfigManager($configManager) {
    $this->configManager = $configManager;

    return $this;
  }

  /**
   * Provider manager getter.
   */
  public function getProviderManager() {
    return $this->providerManager;
  }

  /**
   * Provider manager setter.
   */
  public function setProviderManager($providerManager) {
    $this->providerManager = $providerManager;

    return $this;
  }

  /**
   * Current provider getter.
   */
  public function getCurrentProvider() {
    return $this->currentProvider;
  }

  /**
   * Current provider setter.
   */
  public function setCurrentProvider($currentProvider) {
    $this->currentProvider = $currentProvider;

    return $this;
  }

  /**
   * Logger getter.
   */
  public function getLogger() {
    return $this->logger;
  }

  /**
   * Logger setter.
   */
  public function setLogger($logger) {
    $this->logger = $logger;

    return $this;
  }

  /**
   * Fetch data from the endpoint.
   *
   * @param string $endpoint_name
   *   Endpoint name.
   * @param array $tokens
   *   Array of tokens to pass to an endpoint.
   *
   * @return \Drupal\vu_rp_api\Client\Response
   *   Response object.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If unable to get an endpoint instance by name from the current provider.
   *   If unable to fetch the payload.
   */
  public function fetch($endpoint_name, $tokens = []) {
    /** @var \Drupal\vu_rp_api\Endpoint\Endpoint $endpoint */
    $endpoint = $this->currentProvider->getEndpoint($endpoint_name);
    if (!$endpoint) {
      throw new Exception(sprintf('Endpoint "%s" for provider "%s" is not configured', $endpoint_name, $this->currentProvider->getTitle()));
    }

    $request = $endpoint->prepareRequest();
    $request->setUri(self::replacePathTokens($request->getUri(), $tokens));

    $response = $this->sendRequest($request);

    if ($response->getStatus() == RestInterface::HTTP_OK) {
      $this->validateResponseFormat($endpoint->getFormat(), $response->getContent());
      $endpoint->getFieldMapper()->validateResponseSchema($response->getContent());

      return $response;
    }

    throw new Exception(sprintf('Unable to connect to provider "%s" endpoint "%s": Status %s, Content %s',
      $this->currentProvider->getTitle(),
      $endpoint->getTitle(),
      $response->getStatus(),
      $response->getContent()
    ));
  }

  /**
   * Initialise HTTP client.
   */
  protected function initHttpClient() {
    $http_client_class = $this->configManager->getHttpClientClass(self::HTTP_CLIENT_CLASS_DEFAULT);
    $this->httpClient = new $http_client_class();
  }

  /**
   * Helper to init current provider.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If provider cannot be initialised.
   */
  protected function initCurrentProvider() {
    $provider = $this->providerManager->getCurrentSingle();
    if (!$provider) {
      throw new Exception('Providers are not configured');
    }
    $this->currentProvider = $provider;
  }

  /**
   * Replace path placeholders with tokens.
   *
   * @param string $path
   *   Path with placeholders.
   * @param array|null $tokens
   *   Variable number of tokens to replace placeholders.
   *
   * @return string
   *   Path with placeholders replaced with tokens taken from arguments.
   */
  protected static function replacePathTokens($path, $tokens) {
    $replacement = [];
    foreach ($tokens as $token => $value) {
      $replacement[self::makePathToken($token)] = $value;
    }

    // Perform token replacement.
    return strtr($path, $replacement);
  }

  /**
   * Convert a string into a placeholder in expected format.
   */
  protected static function makePathToken($string) {
    return preg_match('/(\\{[^{]+\\})/', $string) ? $string : '{' . $string . '}';
  }

  /**
   * Send request and retrieve a result.
   *
   * @param \Drupal\vu_rp_api\Client\Request $request
   *   Request object.
   * @param bool $wait_for_content
   *   Optional flag to wait for content. It is up to specific HTTP client to
   *   support waiting for content. Defaults to TRUE.
   *
   * @return \Drupal\vu_rp_api\Client\Response
   *   Response object.
   */
  protected function sendRequest(Request $request, $wait_for_content = TRUE) {
    if ($this->configManager->logIsEnabled()) {
      $this->logger->log('request', (string) $request);
    }

    // Use on-screen debugging, if enabled.
    if ($this->configManager->getDebugRequest()) {
      $this->debugRequestAdd($request);
    }

    $response = $this->httpClient->request($request, $wait_for_content);

    if ($this->configManager->logIsEnabled()) {
      $this->logger->log('response', (string) $response);
    }

    return $response;
  }

  /**
   * Add debug information about request.
   *
   * @param \Drupal\vu_rp_api\Client\Request $request
   *   Request object with 'url' and 'method' properties set.
   */
  protected function debugRequestAdd(Request $request) {
    // Work on the clone of request to avoid any data damage.
    $request_clone = clone $request;

    if (!isset($_SESSION['vu_rp_api_debug_request'])) {
      $_SESSION['vu_rp_api_debug_request'] = [];
    }

    $content = $request_clone->getContent();
    if ($content) {
      // Decode any sent data in order to properly output it later.
      $request_clone->setContent($content);
    }

    $_SESSION['vu_rp_api_debug_request'][current_path()][] = (string) $request_clone;
  }

  /**
   * Output debug information about performed requests.
   *
   * The information is printed into browser console and contains request
   * objects keyed by page path where they originated.
   */
  public function debugRequestOutput() {
    if (!isset($_SESSION['vu_rp_api_debug_request'])) {
      return;
    }

    // Add total requests count for each page.
    $grand_total = 0;
    foreach ($_SESSION['vu_rp_api_debug_request'] as $path => $info) {
      $_SESSION['vu_rp_api_debug_request'][$path]['total requests'] = count($info);
      $grand_total += count($info);
    }
    $_SESSION['vu_rp_api_debug_request']['grand total requests'] = $grand_total;

    // To pass full PHP object into JS, we need to store it in settings.
    drupal_add_js([
      'api' => [
        'debug' => $_SESSION['vu_rp_api_debug_request'],
      ],
    ], [
      'type' => 'setting',
      'every_page' => FALSE,
      'scope' => 'footer',
    ]);

    // Add inline JS to render output as prettified JSON.
    drupal_add_js('
    jQuery(document).ready(function () {
      console.log(JSON.stringify(Drupal.settings.api.debug,null,2));
    });', [
      'type' => 'inline',
      'every_page' => FALSE,
      'scope' => 'footer',
    ]);

    // Remove storage info.
    unset($_SESSION['vu_rp_api_debug_request']);
  }

  /**
   * Wrapper for json_decode that throws when an error occurs.
   *
   * @param string $json
   *   JSON data to parse.
   * @param bool $assoc
   *   When true, returned objects will be converted into associative arrays.
   * @param int $depth
   *   User specified recursion depth.
   * @param int $options
   *   Bitmask of JSON decode options.
   *
   * @return mixed
   *   Decoded json.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If the JSON cannot be decoded.
   */
  public static function jsonDecode($json, $assoc = FALSE, $depth = 512, $options = 0) {
    $data = \json_decode($json, $assoc, $depth, $options);
    if (JSON_ERROR_NONE !== json_last_error()) {
      throw new Exception('json_decode error: ' . json_last_error_msg());
    }

    return $data;
  }

  /**
   * Wrapper for JSON encoding that throws when an error occurs.
   *
   * @param mixed $value
   *   The value being encoded.
   * @param int $options
   *   JSON encode option bitmask.
   * @param int $depth
   *   Set the maximum depth. Must be greater than zero.
   *
   * @return string
   *   Encoded json as a string.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If the JSON cannot be encoded.
   */
  public static function jsonEncode($value, $options = 0, $depth = 512) {
    $json = \json_encode($value, $options, $depth);
    if (JSON_ERROR_NONE !== json_last_error()) {
      throw new Exception('json_encode error: ' . json_last_error_msg());
    }

    return $json;
  }

  /**
   * Process entity.
   *
   * @todo: This whole function needs to be refactored. This is here for MVP.
   */
  public function processEntity($data) {
    /** @var \Drupal\vu_rp_api\Endpoint\Endpoint $endpoint */
    // @hack! Hardcoded account endpoint.
    $endpoint = $this->currentProvider->getEndpoint('account');

    $primary_keys = $endpoint->getFieldMapper()->getPrimaryKeyFields();
    if (empty($primary_keys)) {
      throw new Exception('Unable to find primary keys');
    }
    $primary_field_values = $this->processSchemaValues($data, $primary_keys);

    if (empty($primary_field_values)) {
      throw new Exception('Unable to find primary values');
    }

    $existing_nodes = $this->findNodesByField('researcher_profile', $primary_field_values);

    if ($existing_nodes) {
      $node = reset($existing_nodes);
      $node = node_load($node->nid);
      $this->logger->log('processing node', sprintf('Found existing node "%s" for primary field(s): %s; %s', $node->nid, implode(', ', array_keys($primary_keys)), print_r($primary_field_values, TRUE)));
      $node->log = 'Updated node using API data';
    }
    else {
      $this->logger->log('processing node', sprintf('Creating new node for primary field(s): %s; %s', implode(', ', array_keys($primary_keys)), print_r($primary_field_values, TRUE)));
      $node = $this->createNode([
        'type' => 'researcher_profile',
      ]);
      $node->log = sprintf('Created node using API data with primary field(s): %s', implode(', ', array_keys($primary_keys)));
    }

    $schema = $endpoint->getFieldMapper()->getSchema(TRUE);

    // This will fill-in node object with all required values.
    $this->processSchemaValues($data, $schema, $node);

    $this->logger->log('processing node: save', sprintf('Saving processed node: %s', json_encode($node, JSON_PRETTY_PRINT)));
    node_save($node);
    // Update revisions.
    if (isset($node->workbench_moderation['current']->vid)) {
      // Check if there is a revision.
      if ($node->vid != $node->workbench_moderation['current']->vid) {
        // Load current revision.
        $node_revision = node_load($node->nid, $node->workbench_moderation['current']->vid);

        // This will fill-in node object with all required values.
        $this->processSchemaValues($data, $schema, $node_revision);

        $node_revision->original = $node;
        $node_revision->revision = TRUE;
        $node_revision->is_draft_revision = TRUE;
        $node_revision->log = 'Updated node using API data';
        entity_save('node', $node_revision);
      }
    }

    return $node->nid;
  }

  /**
   * Traverse to the root of the data object using root path set in field map.
   *
   * @param array $data
   *   Data to traverse.
   *
   * @return mixed
   *   Data at the depth of the root path.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If the data does not have expected root path.
   */
  protected function getDataRoot($data) {
    /** @var \Drupal\vu_rp_api\Endpoint\Endpoint $endpoint */
    $endpoint = $this->currentProvider->getEndpoint('account');
    $path = $endpoint->getFieldMapper()->findRootPath();

    $data_clone = $data;
    foreach ($path as $part) {
      if (!array_key_exists($part, $data_clone)) {
        throw new Exception(sprintf('Unable to traverse through root objects to the data: %s', print_r($data, TRUE)));
      }
      $data_clone = $data_clone[$part];
    }

    return $data_clone;
  }

  /**
   * Process schema values from mapped fields.
   *
   * @param array $data
   *   Data to process.
   * @param array $schema
   *   Normalised field schema map.
   * @param null $node
   *   Optional node to fill with values. If not passed, the values will be
   *   only returned and no callbacks will be called (because we have no node
   *   to attach their results to).
   *
   * @return array
   *   Array of processed values.
   *
   * @throws \Drupal\vu_rp_api\Exception
   *   If there was an error with field mapping processing.
   */
  protected function processSchemaValues($data, $schema, $node = NULL) {
    $data = $this->getDataRoot($data);

    $values = [];
    foreach ($schema as $source_field => $dst) {
      if (empty($dst['field'])) {
        // Skip fields without proper mapping.
        continue;
      }

      if (!array_key_exists($source_field, $data)) {
        // Skip fields without provided data, but log this problem.
        $this->logger->log(__METHOD__, sprintf('Data does not contain field "%s"', $source_field));
        continue;
      }

      $source_value = $data[$source_field];

      $dst_field = isset($dst['field']) ? $dst['field'] : NULL;
      $dst_value_key = isset($dst['value_key']) ? $dst['value_key'] : NULL;

      if ($node) {
        try {
          call_user_func($dst['callback'], $data, $source_field, $source_value, $node, $dst_field, $dst_value_key);
        }
        // Purposely using global Exception class to capture any incorrect
        // processing of field mappings.
        catch (\Exception $exception) {
          $this->logger->log(__METHOD__, sprintf('Error occurred while processing field "%s" with source value "%s"', $source_field, $source_value), Logger::SEVERITY_WARNING);
        }
      }

      // Only capture values with standard callback.
      // @todo: Refactor this to allow values from custom callbacks (as above).
      if ($dst_field && $dst_value_key) {
        $values[$dst_field][$dst_value_key] = $source_value;
      }
    }

    return $values;
  }

  /**
   * Validate supported response format.
   */
  public function validateResponseFormat($format, $content) {
    switch ($format) {
      case RestInterface::FORMAT_JSON:
        if (Response::isJson($content)) {
          return;
        }
        break;

      case RestInterface::FORMAT_XML:
        // @todo: Implement this.
        break;
    }

    throw new Exception('Current format is not supported');
  }

  /**
   * Helper to create node.
   */
  protected function createNode($values = []) {
    $node = (object) [
      'type' => $values['type'],
      'language' => LANGUAGE_NONE,
      'is_new' => TRUE,
    ];
    // Set some defaults.
    $node_options = variable_get('node_options_' . $node->type, ['status', 'promote']);
    foreach (['status', 'promote', 'sticky'] as $key) {
      $node->$key = (int) in_array($key, $node_options);
    }
    if (module_exists('comment') && !isset($node->comment)) {
      $node->comment = variable_get("comment_$node->type", COMMENT_NODE_OPEN);
    }
    // Apply the given values.
    foreach ($values as $key => $value) {
      $node->$key = $value;
    }

    return $node;
  }

  /**
   * Helper to find nodes using fields values.
   */
  protected function findNodesByField($bundle, $fields) {
    $query = new \EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle);

    foreach ($fields as $field => $value) {
      foreach ($value as $key => $v) {
        $query->fieldCondition($field, $key, $v, '=');
      }
    }

    // Bypass access checks to load all nodes.
    $query->addMetaData('account', user_load(1));

    $result = $query->execute();

    return isset($result['node']) ? $result['node'] : [];
  }

}
