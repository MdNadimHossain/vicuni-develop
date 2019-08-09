<?php

namespace Drupal\vu_rp_api\Endpoint;

/**
 * Interface EndpointInterface.
 *
 * @package Drupal\vu_rp_api\Endpoint
 */
interface EndpointInterface {

  /**
   * URL getter.
   */
  public function getUrl();

  /**
   * URL setter.
   */
  public function setUrl($url);

}
