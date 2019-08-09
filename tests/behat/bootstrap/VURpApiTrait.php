<?php

use Drupal\vu_rp_api\Client\RestInterface;

/**
 * Trait VURpApiTrait.
 */
trait VURpApiTrait {

  /**
   * The name of the variable for the test mode.
   *
   * @var string
   */
  protected $vuRpApiVariableNameIsTestMode;

  /**
   * The name of the variable for the list of test responses.
   *
   * @var string
   */
  protected $vuRpApiVariableNameTestResponsesList;

  /**
   * Path prefix for test REST responses.
   *
   * @var string
   */
  protected $vuRpApiResponsePathPrefix;

  /**
   * Array of staff ids added to a researcher list.
   *
   * @var array
   */
  protected $vuRpApiStaffIds = [];

  /**
   * VURpApiTrait constructor.
   */
  public function __construct($variableNameIsTestMode, $variableNameTestResponsesList, $responsePathPrefix = 'test-') {
    require_once module_load_include('inc', 'vu_rp_test', 'vu_rp_test.rest');

    $this->vuRpApiVariableNameIsTestMode = $variableNameIsTestMode;
    $this->vuRpApiVariableNameTestResponsesList = $variableNameTestResponsesList;
    $this->vuRpApiResponsePathPrefix = $responsePathPrefix;
  }

  /**
   * @BeforeScenario @VURpAPIServer
   */
  public function vuRpApiEnableTestServer() {
    $this->vuRpApiRestResponsesCleanList();
    $this->variableSet($this->vuRpApiVariableNameIsTestMode, TRUE);
    $this->variableSet('vu_rp_api_provider', 'local');
    $this->vuRpApiResearcherClearList();
  }

  /**
   * Enable the vu_core_test module.
   *
   * @AfterScenario @VURpAPIServer
   */
  public function vuRpApiDisableTestServer() {
    $this->vuRpApiRestResponsesCleanList();
    variable_del($this->vuRpApiVariableNameIsTestMode);
    variable_del($this->vuRpApiVariableNameTestResponsesList);
    $this->vuRpApiResearcherClearList();
  }

  /**
   * Helper to process variables key/value.
   */
  protected function vuRpApiVariableProcessKeyValue(&$key, &$value) {
    $parts = explode('.', $key);
    if (count($parts) == 1) {
      return;
    }

    $key = array_shift($parts);

    $new_value = [];
    drupal_array_set_nested_value($new_value, $parts, $value);

    $value = $new_value;
  }

  /**
   * @When researcher profile api response :url exists
   */
  public function vuRpApiResponseExistsFromFile($url) {
    // Construct internal path from provided URL.
    $fixture_path_prefix = 'rp_api';
    $path = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR . $fixture_path_prefix . DIRECTORY_SEPARATOR . $url . '.json';

    if (!is_file($path)) {
      throw new Exception(sprintf('Unable to find Researcher Profile API fixture file "%s"', $path));
    }

    // The name of the endpoint.
    $pathinfo = pathinfo(substr($path, strpos($path, $url)));
    $name = ltrim($pathinfo['dirname'] . '/' . $pathinfo['filename'], '/');

    $this->vuRpApiRestCreateRecord($name, file_get_contents($path));
  }

  /**
   * Create test record.
   */
  protected function vuRpApiRestCreateRecord($path, $content) {
    $values = [
      'request_path' => $path,
      'request_method' => RestInterface::METHOD_GET,
      'response_content' => $content,
      'comment' => 'Created by Behat test',
    ];

    $saved = vu_rp_test_rest_record_update($values);
    $this->vuRpApiRestResponseAddToList($saved, $path);
  }

  /**
   * @When researcher profile api response :url has content:
   */
  public function vuRpApiRestResponseContent($url, $content) {
    $this->vuRpApiRestCreateRecord($url, (string) $content);
  }

  /**
   * Add test response to internal response list.
   */
  protected function vuRpApiRestResponseAddToList($id, $value) {
    $list = variable_get($this->vuRpApiVariableNameTestResponsesList, []);
    $list[$id] = $value;
    $list = array_filter(array_unique($list));
    variable_set($this->vuRpApiVariableNameTestResponsesList, $list);
  }

  /**
   * Helper to remove all records from test REST responses list.
   */
  protected function vuRpApiRestResponsesCleanList() {
    $list = vu_rp_test_rest_record_get_all();
    foreach ($list as $id => $record) {
      if (strpos($record['request_path'], $this->vuRpApiResponsePathPrefix) !== FALSE) {
        vu_rp_test_rest_record_delete($id);
      }
    }
  }

  /**
   * @When research profile api provider :endpoint endpoint :key value is set to :value
   */
  public function vuRpApiSetProviderEnpointUrl($endpoint, $key, $value) {
    $provider_config = variable_get('vu_rp_api_provider_config');
    $this->vuRpApiVariableProcessKeyValue($key, $value);
    $provider_config['local'][$endpoint][$key] = $value;
    $this->variableSet('vu_rp_api_provider_config', $provider_config);
    // Init the client with the new variables.
    vu_rp_api_get_client(TRUE);
  }

  /**
   * @Then I reset research profile api queues
   */
  public function vuRpApiResetQueues() {
    vu_rp_api_reset_all();
  }

  /**
   * @Then research profile api :name queue has :count items
   */
  public function vuRpApiAssertQueueHasNumberOfItems($name, $count) {
    $name = 'vu_rp_api_' . $name;

    /** @var \DrupalQueueInterface $queue */
    $queue = DrupalQueue::get($name);
    $actual_count = $queue->numberOfItems();
    if ($count != $actual_count) {
      throw new Exception(sprintf('Queue "%s" has %s items, but expected to have %s.', $name, $actual_count, $count));
    }
  }

  /**
   * @Given I add staff id :value to researcher profile list
   */
  public function vuRpApiAddValueToList($staff_id) {
    vu_rp_list_record_save($staff_id);
    $this->vuRpApiStaffIds[$staff_id] = $staff_id;
  }

  /**
   * @Given I remove :value from researcher profile list
   */
  public function vuRpApiRemoveValueFromList($staff_id) {
    vu_rp_list_record_delete($staff_id);
    unset($this->vuRpApiStaffIds[$staff_id]);
  }

  /**
   * @Then researcher profile list has staff id :value
   */
  public function vuRpApiAssertListHasValue($staff_id) {
    if (!vu_rp_list_is_existing_staff_id($staff_id)) {
      throw new Exception(sprintf('Staff ID "%s" should exist in the list, but it does not', $staff_id));
    }
  }

  /**
   * @Then researcher profile list does not have staff id :value
   */
  public function vuRpApiAssertListHasNoValue($staff_id) {
    if (vu_rp_list_is_existing_staff_id($staff_id)) {
      throw new Exception(sprintf('Staff ID "%s" should not exist in the list, but it does', $staff_id));
    }
  }

  /**
   * Helper to remove all test records from the researchers list.
   */
  protected function vuRpApiResearcherClearList() {
    foreach ($this->vuRpApiStaffIds as $staff_id) {
      $this->vuRpApiRemoveValueFromList($staff_id);
    }
  }

}
