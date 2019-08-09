<?php

namespace Drupal\vu_rp_api\Client;

use Drupal\vu_rp_api\Exception;

/**
 * Class Response.
 *
 * @package Drupal\vu_rp_api
 */
class Response {

  /**
   * Response content.
   *
   * @var string
   */
  protected $content;

  /**
   * Response status code.
   *
   * @var int
   */
  protected $status;

  /**
   * Array of headers.
   *
   * @var array
   */
  protected $headers;

  /**
   * Response constructor.
   *
   * @param array $options
   *   Optional array of response options.
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
   * Gets the response content.
   *
   * @return string
   *   The response content
   */
  public function getContent() {
    return $this->content;
  }

  /**
   * Content setter.
   */
  public function setContent($content) {
    $this->content = $content;
  }

  /**
   * Gets the response status code.
   *
   * @return int
   *   The response status code
   */
  public function getStatus() {
    return $this->status;
  }

  /**
   * Set status.
   */
  public function setStatus($status) {
    $this->validateStatus($status);
    $this->status = $status;
  }

  /**
   * Gets the response headers.
   *
   * @return array
   *   The response headers.
   */
  public function getHeaders() {
    return $this->headers;
  }

  /**
   * Set headers.
   */
  public function setHeaders($headers) {
    $this->headers = $headers;
  }

  /**
   * Validate status before it is set.
   *
   * @param int $status
   *   Status code.
   *
   * @return bool
   *   TRUE if status is valid, FALSE otherwise.
   */
  protected function validateStatus($status) {
    // Special case for statuses returned by some clients usually used when a
    // network error occurs.
    if ($status < 0) {
      return TRUE;
    }

    $interface = new \ReflectionClass(__NAMESPACE__ . '\RestInterface');
    $constants = $interface->getConstants();

    foreach ($constants as $constant_name => $constant_value) {
      if (strpos($constant_name, 'HTTP_') === 0 && $constant_value == $status) {
        return TRUE;
      }
    }

    throw new Exception("Undefined REST value $status provided. Use status codes defined in RestInterface");
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

  /**
   * Check to see if provided data is JSON string.
   */
  public static function isJson($data) {
    if (!is_string($data)) {
      return FALSE;
    }

    json_decode($data);

    return json_last_error() === JSON_ERROR_NONE;
  }

}
