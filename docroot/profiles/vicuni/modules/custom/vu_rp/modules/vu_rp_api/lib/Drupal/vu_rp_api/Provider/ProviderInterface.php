<?php

namespace Drupal\vu_rp_api\Provider;

/**
 * Interface ProviderInterface.
 *
 * @package Drupal\vu_rp_api\Provider
 */
interface ProviderInterface {

  /**
   * Return array of endpoint instances.
   *
   * @return \Drupal\vu_rp_api\Endpoint\Endpoint[]
   *   Array of endpoint instances.
   */
  public function getEndpoints();

  /**
   * Get endpoint by name.
   *
   * @param string $name
   *   Endpoint name.
   *
   * @return \Drupal\vu_rp_api\Endpoint\Endpoint
   *   Endpoint instance or NULL if endpoint does not exist.
   */
  public function getEndpoint($name);

}
