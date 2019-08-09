<?php

namespace Drupal\vu_rp_api\Client;

/**
 * @file
 * HTTP client.
 *
 * Used as a DI service for a Client class.
 */

/**
 * Class HttpClient.
 *
 * @package Drupal\vu_rp_api\Client
 */
class HttpClient implements ClientInterface, RestInterface {

  /**
   * Constructor.
   *
   * @param array|null $config
   *   Array of configuration to be passed to the client.
   */
  public function __construct($config = []) {
    foreach ($config as $k => $v) {
      $this->{$k} = $v;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function request(Request $request, $wait_for_content = TRUE) {
    $url = $request->getFullUri();
    $options['method'] = $request->getMethod();
    $options['headers'] = $request->getHeaders();
    $options['data'] = $request->getContent();
    $options['timeout'] = $request->getTimeout();

    $response_generic = drupal_http_request($url, $options);

    $response = new Response();
    $response->setStatus($response_generic->code);
    $response->setContent($response_generic->data);
    $response->setHeaders($response_generic->headers);

    return $response;
  }

}
