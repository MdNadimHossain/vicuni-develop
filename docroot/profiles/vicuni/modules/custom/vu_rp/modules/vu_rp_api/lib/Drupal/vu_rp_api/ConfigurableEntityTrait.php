<?php

namespace Drupal\vu_rp_api;

/**
 * Trait ConfigurableEntityTrait.
 *
 * Allows to make entities to store their configuration.
 *
 * @package Drupal\vu_rp_api
 */
trait ConfigurableEntityTrait {

  /**
   * The configuration manager.
   *
   * @var \Drupal\vu_rp_api\Config\ConfigManager
   */
  protected $configManager;

  /**
   * The configuration object for this entity.
   *
   * @var mixed
   */
  protected $config;

  /**
   * ConfigurableEntityTrait constructor.
   *
   * @param \Drupal\vu_rp_api\Config\ConfigManager $configManager
   *   The configuration manager.
   * @param null $config
   *   Optional initial configuration.
   */
  public function __construct($configManager, $config = NULL) {
    $this->configManager = $configManager;
    if ($config) {
      $this->config = $config;
    }
  }

  /**
   * Configuration getter.
   */
  public function getConfig() {
    return $this->config;
  }

  /**
   * Configuration setter.
   */
  public function setConfig($config) {
    $this->config = $config;

    return $this;
  }

}
