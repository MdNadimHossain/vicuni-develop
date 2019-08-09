<?php

namespace Drupal\vu_rp_api\Client;

/**
 * Interface ClientInterface.
 *
 * @package Drupal\vu_rp_api\Client
 */
interface ClientInterface {

  /**
   * Make request.
   *
   * @param \Drupal\vu_rp_api\Client\Request $request
   *   Request object with 'url' and 'method' properties set.
   * @param bool $wait_for_content
   *   Flag to wait for content or just report status code.
   *
   * @return \Drupal\vu_rp_api\Client\Response
   *   Response object.
   */
  public function request(Request $request, $wait_for_content = TRUE);

}
