<?php

namespace Drupal\vu_rp_api\Provider;

use Drupal\vu_rp_api\AbstractEntityManager;

/**
 * Class ProviderManager.
 *
 * @package Drupal\vu_rp_api\Provider
 */
class ProviderManager extends AbstractEntityManager {

  /**
   * The endpoint manager.
   *
   * @var \Drupal\vu_rp_api\Endpoint\EndpointManager
   */
  protected $endpointManager;

  /**
   * {@inheritdoc}
   */
  protected function getEntityType() {
    return 'provider';
  }

}
