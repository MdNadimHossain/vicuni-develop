<?php

/**
 * @file
 * Status report integration.
 */

/**
 * Class VuRpApiStatus.
 */
abstract class VuRpApiStatus extends StatusReport {

  /**
   * Returns the name of the specific endpoint.
   */
  abstract protected function getEndpointName();

  /**
   * Define tokens supported by this endpoint.
   *
   * @param \Drupal\vu_rp_api\Provider\Provider $provider
   *   THe provider this endpoint is a part of.
   *
   * @return array
   *   Array of tokens that this endpoint supports.
   */
  protected function getTokens($provider) {
    return [];
  }

  /**
   * {@inheritdoc}
   */
  public function callback() {
    $success = FALSE;
    $messages = [];

    try {
      /** @var \Drupal\vu_rp_api\Client\Client $client */
      $client = vu_rp_api_get_client();
      $client->fetch($this->getEndpointName(), $this->getTokens($client->getCurrentProvider()));
      $messages[] = t('Successfully fetched status information for an endpoint "@endpoint"', ['@endpoint' => $this->getEndpointName()]);
      $success = TRUE;
    }
    catch (Exception $exception) {
      $messages[] = $exception->getMessage();
    }

    return [
      'success' => $success,
      'messages' => $messages,
    ];
  }

}

/**
 * Class VuRpApiStatusList.
 */
class VuRpApiStatusList extends VuRpApiStatus {

  /**
   * {@inheritdoc}
   */
  protected function getEndpointName() {
    return 'list';
  }

  /**
   * {@inheritdoc}
   */
  public function info() {
    return [
      'name' => t('Researcher Profile API: List status'),
      'description' => t('Check whether API for List can be reached.'),
    ];
  }

}

/**
 * Class VuRpApiStatusAccount.
 */
class VuRpApiStatusAccount extends VuRpApiStatus {

  /**
   * {@inheritdoc}
   */
  protected function getEndpointName() {
    return 'account';
  }

  /**
   * {@inheritdoc}
   */
  protected function getTokens($provider) {
    $config = $provider->getConfig();

    return [
      'account' => $config['account']['status']['test_account'],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function info() {
    return [
      'name' => t('Researcher Profile API: Account status'),
      'description' => t('Check whether API for Account can be reached.'),
    ];
  }

}
