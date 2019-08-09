<?php

namespace Drupal\vu_rp_api\Client;

use Drupal\vu_rp_api\Exception;

/**
 * Class Request.
 *
 * @package Drupal\vu_rp_api
 */
class Request {

  /**
   * Request URI.
   *
   * @var string
   */
  protected $uri;

  /**
   * Request query.
   *
   * @var string
   */
  protected $query;

  /**
   * Content of the payload to sent.
   *
   * @var string
   */
  protected $content;

  /**
   * Additional request options.
   *
   * @var array
   */
  protected $options;

  /**
   * Request method.
   *
   * @var string
   */
  protected $method;

  /**
   * Array of headers.
   *
   * @var array
   */
  protected $headers = [];

  /**
   * Timeout in seconds to wait for response.
   *
   * @var int
   */
  protected $timeout = 180;

  /**
   * Request constructor.
   */
  public function __construct($options = []) {
    $this->init($options);
  }

  /**
   * Init properties from passed options.
   */
  public function init($options = []) {
    foreach ($options as $k => $v) {
      $method = 'set' . ucfirst($k);
      if (method_exists($this, $method)) {
        $this->{$method}($v);
      }
    }
  }

  /**
   * URI getter.
   */
  public function getUri() {
    return $this->uri;
  }

  /**
   * URI setter.
   */
  public function setUri($uri) {
    $this->uri = $uri;

    return $this;
  }

  /**
   * Query getter.
   */
  public function getQuery() {
    return $this->query;
  }

  /**
   * Query setter.
   */
  public function setQuery($query) {
    $this->query = $query;

    return $this;
  }

  /**
   * Content getter.
   */
  public function getContent() {
    return $this->content;
  }

  /**
   * Content setter.
   */
  public function setContent($content) {
    $this->content = $content;

    return $this;
  }

  /**
   * Options getter.
   */
  public function getOptions() {
    return $this->options;
  }

  /**
   * Options setter.
   */
  public function setOptions($options) {
    $this->options = $options;

    return $this;
  }

  /**
   * Method getter.
   */
  public function getMethod() {
    return $this->method;
  }

  /**
   * Method setter.
   */
  public function setMethod($method) {
    $this->validateMethod($method);
    $this->method = $method;

    return $this;
  }

  /**
   * Headers getter.
   */
  public function getHeaders() {
    return $this->headers;
  }

  /**
   * Timeout getter.
   */
  public function getTimeout() {
    return $this->timeout;
  }

  /**
   * Timeout setter.
   */
  public function setTimeout($timeout) {
    $this->timeout = $timeout;

    return $this;
  }

  /**
   * Helper to set headers.
   */
  public function setHeaders($headers = []) {
    $this->headers = array_merge($this->headers, $headers);

    return $this;
  }

  /**
   * Helper to set HTTP auth as encoded values.
   */
  public function setAuth($username, $password) {
    $this->setHeaders(['Authorization' => 'Basic ' . base64_encode($username . ':' . $password)]);
  }

  /**
   * Render full url.
   */
  public function getFullUri() {
    return url($this->uri, ['query' => $this->getQuery()]);
  }

  /**
   * Validate that provided method is correct.
   */
  protected function validateMethod($method) {
    $interface = new \ReflectionClass(__NAMESPACE__ . '\RestInterface');
    $constants = $interface->getConstants();

    foreach ($constants as $constant_name => $constant_value) {
      if (strpos($constant_name, 'METHOD_') === 0 && $constant_value == $method) {
        return TRUE;
      }
    }

    throw new Exception("Undefined REST method $method provided. Use methods defined in RestInterface");
  }

  /**
   * Convert response to string.
   */
  public function __toString() {
    $properties = get_object_vars($this);
    ksort($properties);

    return array_reduce(array_keys($properties), function ($carry, $key) use ($properties) {
      return $carry . $key . ': ' . print_r($properties[$key], TRUE) . PHP_EOL;
    }, '');
  }

}
