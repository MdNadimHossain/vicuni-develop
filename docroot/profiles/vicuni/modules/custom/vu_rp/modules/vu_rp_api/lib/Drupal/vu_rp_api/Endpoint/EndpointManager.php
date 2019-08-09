<?php

namespace Drupal\vu_rp_api\Endpoint;

use Drupal\vu_rp_api\AbstractEntityManager;

/**
 * Class EndpointManager.
 *
 * @package Drupal\vu_rp_api\Endpoint
 */
class EndpointManager extends AbstractEntityManager {

  /**
   * {@inheritdoc}
   */
  protected function getEntityType() {
    return 'endpoint';
  }

}
