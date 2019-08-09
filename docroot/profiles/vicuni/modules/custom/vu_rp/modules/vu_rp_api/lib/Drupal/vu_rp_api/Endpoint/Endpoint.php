<?php

namespace Drupal\vu_rp_api\Endpoint;

use Drupal\vu_rp_api\AbstractEntity;
use Drupal\vu_rp_api\Client\Request;
use Drupal\vu_rp_api\Client\RestInterface;

/**
 * Class Endpoint.
 *
 * @package Drupal\vu_rp_api
 */
class Endpoint extends AbstractEntity implements EndpointInterface {

  /**
   * Endpoint name.
   *
   * @var string
   */
  protected $name;

  /**
   * Endpoint title.
   *
   * @var string
   */
  protected $title;

  /**
   * Endpoint URL.
   *
   * @var string
   */
  protected $url;

  /**
   * Payload delivery HTTP method.
   *
   * @var string
   */
  protected $method;

  /**
   * Expected format.
   *
   * @var string
   */
  protected $format;

  /**
   * HTTP authentication username.
   *
   * @var string
   */
  // @codingStandardsIgnoreStart
  protected $auth_username;
  // @codingStandardsIgnoreEnd

  /**
   * HTTP authentication password.
   *
   * @var string
   */
  // @codingStandardsIgnoreStart
  protected $auth_password;
  // @codingStandardsIgnoreEnd

  /**
   * Timeout in seconds after which the response will be considered failed.
   *
   * @var int
   */
  protected $timeout;

  /**
   * Endpoint field mapper.
   *
   * @var \Drupal\vu_rp_api\Endpoint\FieldMapper
   */
  protected $fieldMapper;

  /**
   * {@inheritdoc}
   */
  public static function getRequiredFields() {
    return array_merge(parent::getRequiredFields(), [
      'method',
      'format',
      'schema',
    ]);
  }

  /**
   * {@inheritdoc}
   */
  public function postCreate($info) {
    $this->fieldMapper = new FieldMapper($info['schema']);
    $this->method = $info['method'];
    $this->format = $info['format'];
    $this->timeout = $info['timeout'];
  }

  /**
   * {@inheritdoc}
   */
  public function getUrl() {
    return $this->url;
  }

  /**
   * {@inheritdoc}
   */
  public function setUrl($url, $hostname = NULL) {
    // All local URLs should always be converted to external.
    if (!url_is_external($url)) {
      // Use provided or global hostname.
      $url = $hostname ? ltrim($hostname, '/') . '/' . ltrim($url, '/') : url($url, ['absolute' => TRUE]);
    }

    $this->url = $url;

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
    $this->method = $method;

    return $this;
  }

  /**
   * Format getter.
   */
  public function getFormat() {
    return $this->format;
  }

  /**
   * Format setter.
   */
  public function setFormat($format) {
    $this->format = $format;

    return $this;
  }

  /**
   * HTTP auth username getter.
   */
  public function getAuthUsername() {
    return $this->auth_username;
  }

  /**
   * HTTP auth username setter.
   */
  public function setAuthUsername($auth_username) {
    $this->auth_username = $auth_username;

    return $this;
  }

  /**
   * HTTP auth password getter.
   */
  public function getAuthPassword() {
    return $this->auth_password;
  }

  /**
   * HTTP auth password setter.
   */
  public function setAuthPassword($auth_password) {
    $this->auth_password = $auth_password;

    return $this;
  }

  /**
   * Field mapper getter.
   */
  public function getFieldMapper() {
    return $this->fieldMapper;
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
    $this->timeout = intval($timeout);

    return $this;
  }

  /**
   * Prepare request.
   *
   * @return \Drupal\vu_rp_api\Client\Request
   *   Request instance ready to be sent.
   */
  public function prepareRequest() {
    $request = new Request();

    $request->setMethod($this->method);
    $request->setTimeout($this->timeout);

    $url = $this->url;
    $request->setUri($url);

    switch ($this->format) {
      case RestInterface::FORMAT_JSON:
        $request->setHeaders(['Accept' => 'application/json']);
        break;

      case RestInterface::FORMAT_XML:
        $request->setHeaders(['Accept' => 'application/xml']);
        break;
    }

    if (!empty($this->auth_username)) {
      $request->setAuth($this->auth_username, $this->auth_password);
    }

    return $request;
  }

}
