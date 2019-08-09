<?php

namespace Drupal\vu_rp_api\Provider;

use Drupal\vu_rp_api\AbstractEntity;
use Drupal\vu_rp_api\ConfigurableEntityTrait;
use Drupal\vu_rp_api\Endpoint\EndpointManager;

/**
 * Class Provider.
 *
 * @package Drupal\vu_rp_api\Provider
 */
class Provider extends AbstractEntity implements ProviderInterface {

  use ConfigurableEntityTrait {
    ConfigurableEntityTrait::__construct as private _configurableEntityConstructor;
  }

  /**
   * The endpoint manager.
   *
   * @var \Drupal\vu_rp_api\Endpoint\EndpointManager
   */
  protected $endpointManager;

  /**
   * Array of endpoints.
   *
   * @var \Drupal\vu_rp_api\Endpoint\Endpoint[]
   */
  protected $endpoints;

  /**
   * Provider constructor.
   *
   * @param string $type
   *   Provider type.
   * @param string $name
   *   Provider name.
   * @param string $title
   *   Provider title.
   * @param \Drupal\vu_rp_api\Config\ConfigManager $configManager
   *   The config manager.
   * @param null $config
   *   Optional default config.
   */
  public function __construct($type, $name, $title, $configManager, $config = NULL) {
    parent::__construct($type, $name, $title);
    $this->_configurableEntityConstructor($configManager, $config);
    $this->endpointManager = new EndpointManager($this->configManager);
    $this->initEndpoints();
  }

  /**
   * {@inheritdoc}
   */
  public function getEndpoint($name) {
    return isset($this->endpoints[$name]) ? $this->endpoints[$name] : NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getEndpoints() {
    return $this->endpoints;
  }

  /**
   * Initialise endpoints.
   */
  protected function initEndpoints() {
    $this->endpoints = $this->endpointManager->getAll();

    /** @var \Drupal\vu_rp_api\Endpoint\Endpoint $endpoint */
    foreach ($this->endpoints as $endpoint_type => $endpoint) {
      if (!isset($this->config[$endpoint_type])) {
        continue;
      }

      $endpoint_config = $this->config[$endpoint_type];

      // @todo: Refactor below - this is domain-specific and should never be
      // here. Provider should be using endpoint definition to automatically
      // resolve these settings or provide a way to do so from the client
      // consumer.
      $self_host = $this->configManager->getValueGlobal('self_server_request_host');
      $endpoint->setUrl($endpoint_config['url'], $self_host);

      if (!empty($endpoint_config['auth_username'])) {
        $endpoint->setAuthUsername($endpoint_config['auth_username']);
      }

      if (!empty($endpoint_config['auth_password'])) {
        $endpoint->setAuthPassword($endpoint_config['auth_password']);
      }

      if (!empty($endpoint_config['timeout'])) {
        $endpoint->setTimeout($endpoint_config['timeout']);
      }
    }
  }

}
