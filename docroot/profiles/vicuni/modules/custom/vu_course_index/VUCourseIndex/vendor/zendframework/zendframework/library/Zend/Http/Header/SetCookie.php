<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Http\Header;

use Zend\Uri\UriFactory;

/**
 * @throws Exception\InvalidArgumentException
 * @see http://www.ietf.org/rfc/rfc2109.txt
 * @see http://www.w3.org/Protocols/rfc2109/rfc2109
 */
class SetCookie implements MultipleHeaderInterface {

  /**
   * Cookie name
   *
   * @var string|null
   */
  protected $name = NULL;

  /**
   * Cookie value
   *
   * @var string|null
   */
  protected $value = NULL;

  /**
   * Version
   *
   * @var int|null
   */
  protected $version = NULL;

  /**
   * Max Age
   *
   * @var int|null
   */
  protected $maxAge = NULL;

  /**
   * Cookie expiry date
   *
   * @var int|null
   */
  protected $expires = NULL;

  /**
   * Cookie domain
   *
   * @var string|null
   */
  protected $domain = NULL;

  /**
   * Cookie path
   *
   * @var string|null
   */
  protected $path = NULL;

  /**
   * Whether the cookie is secure or not
   *
   * @var bool|null
   */
  protected $secure = NULL;

  /**
   * If the value need to be quoted or not
   *
   * @var bool
   */
  protected $quoteFieldValue = FALSE;

  /**
   * @var bool|null
   */
  protected $httponly = NULL;

  /**
   * @static
   * @throws Exception\InvalidArgumentException
   *
   * @param  $headerLine
   * @param  bool $bypassHeaderFieldName
   *
   * @return array|SetCookie
   */
  public static function fromString($headerLine, $bypassHeaderFieldName = FALSE) {
    static $setCookieProcessor = NULL;

    if ($setCookieProcessor === NULL) {
      $setCookieClass = get_called_class();
      $setCookieProcessor = function ($headerLine) use ($setCookieClass) {
        $header = new $setCookieClass;
        $keyValuePairs = preg_split('#;\s*#', $headerLine);

        foreach ($keyValuePairs as $keyValue) {
          if (preg_match('#^(?P<headerKey>[^=]+)=\s*("?)(?P<headerValue>[^"]*)\2#', $keyValue, $matches)) {
            $headerKey = $matches['headerKey'];
            $headerValue = $matches['headerValue'];
          }
          else {
            $headerKey = $keyValue;
            $headerValue = NULL;
          }

          // First K=V pair is always the cookie name and value
          if ($header->getName() === NULL) {
            $header->setName($headerKey);
            $header->setValue(urldecode($headerValue));
            continue;
          }

          // Process the remaining elements
          switch (str_replace(array('-', '_'), '', strtolower($headerKey))) {
            case 'expires' :
              $header->setExpires($headerValue);
              break;
            case 'domain'  :
              $header->setDomain($headerValue);
              break;
            case 'path'    :
              $header->setPath($headerValue);
              break;
            case 'secure'  :
              $header->setSecure(TRUE);
              break;
            case 'httponly':
              $header->setHttponly(TRUE);
              break;
            case 'version' :
              $header->setVersion((int) $headerValue);
              break;
            case 'maxage'  :
              $header->setMaxAge((int) $headerValue);
              break;
            default:
              // Intentionally omitted
          }
        }

        return $header;
      };
    }

    list($name, $value) = GenericHeader::splitHeaderLine($headerLine);

    // some sites return set-cookie::value, this is to get rid of the second :
    $name = (strtolower($name) == 'set-cookie:') ? 'set-cookie' : $name;

    // check to ensure proper header type for this factory
    if (strtolower($name) !== 'set-cookie') {
      throw new Exception\InvalidArgumentException('Invalid header line for Set-Cookie string: "' . $name . '"');
    }

    $multipleHeaders = preg_split('#(?<!Sun|Mon|Tue|Wed|Thu|Fri|Sat),\s*#', $value);

    if (count($multipleHeaders) <= 1) {
      return $setCookieProcessor(array_pop($multipleHeaders));
    }
    else {
      $headers = array();
      foreach ($multipleHeaders as $headerLine) {
        $headers[] = $setCookieProcessor($headerLine);
      }
      return $headers;
    }
  }

  /**
   * Cookie object constructor
   *
   * @todo Add validation of each one of the parameters (legal domain, etc.)
   *
   * @param   string $name
   * @param   string $value
   * @param   int|string $expires
   * @param   string $path
   * @param   string $domain
   * @param   bool $secure
   * @param   bool $httponly
   * @param   string $maxAge
   * @param   int $version
   *
   * @return  SetCookie
   */
  public function __construct($name = NULL, $value = NULL, $expires = NULL, $path = NULL, $domain = NULL, $secure = FALSE, $httponly = FALSE, $maxAge = NULL, $version = NULL) {
    $this->type = 'Cookie';

    $this->setName($name)
      ->setValue($value)
      ->setVersion($version)
      ->setMaxAge($maxAge)
      ->setDomain($domain)
      ->setExpires($expires)
      ->setPath($path)
      ->setSecure($secure)
      ->setHttpOnly($httponly);
  }

  /**
   * @return string 'Set-Cookie'
   */
  public function getFieldName() {
    return 'Set-Cookie';
  }

  /**
   * @throws Exception\RuntimeException
   * @return string
   */
  public function getFieldValue() {
    if ($this->getName() == '') {
      return '';
    }

    $value = urlencode($this->getValue());
    if ($this->hasQuoteFieldValue()) {
      $value = '"' . $value . '"';
    }

    $fieldValue = $this->getName() . '=' . $value;

    $version = $this->getVersion();
    if ($version !== NULL) {
      $fieldValue .= '; Version=' . $version;
    }

    $maxAge = $this->getMaxAge();
    if ($maxAge !== NULL) {
      $fieldValue .= '; Max-Age=' . $maxAge;
    }

    $expires = $this->getExpires();
    if ($expires) {
      $fieldValue .= '; Expires=' . $expires;
    }

    $domain = $this->getDomain();
    if ($domain) {
      $fieldValue .= '; Domain=' . $domain;
    }

    $path = $this->getPath();
    if ($path) {
      $fieldValue .= '; Path=' . $path;
    }

    if ($this->isSecure()) {
      $fieldValue .= '; Secure';
    }

    if ($this->isHttponly()) {
      $fieldValue .= '; HttpOnly';
    }

    return $fieldValue;
  }

  /**
   * @param string $name
   *
   * @throws Exception\InvalidArgumentException
   * @return SetCookie
   */
  public function setName($name) {
    $this->name = $name;
    return $this;
  }

  /**
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param string $value
   *
   * @return SetCookie
   */
  public function setValue($value) {
    $this->value = $value;
    return $this;
  }

  /**
   * @return string
   */
  public function getValue() {
    return $this->value;
  }

  /**
   * Set version
   *
   * @param int $version
   *
   * @throws Exception\InvalidArgumentException
   * @return SetCookie
   */
  public function setVersion($version) {
    if ($version !== NULL && !is_int($version)) {
      throw new Exception\InvalidArgumentException('Invalid Version number specified');
    }
    $this->version = $version;
    return $this;
  }

  /**
   * Get version
   *
   * @return int
   */
  public function getVersion() {
    return $this->version;
  }

  /**
   * Set Max-Age
   *
   * @param int $maxAge
   *
   * @throws Exception\InvalidArgumentException
   * @return SetCookie
   */
  public function setMaxAge($maxAge) {
    if ($maxAge !== NULL && (!is_int($maxAge) || ($maxAge < 0))) {
      throw new Exception\InvalidArgumentException('Invalid Max-Age number specified');
    }
    $this->maxAge = $maxAge;
    return $this;
  }

  /**
   * Get Max-Age
   *
   * @return int
   */
  public function getMaxAge() {
    return $this->maxAge;
  }

  /**
   * @param  int|string $expires
   *
   * @throws Exception\InvalidArgumentException
   * @return SetCookie
   */
  public function setExpires($expires) {
    if ($expires === NULL) {
      $this->expires = NULL;
      return $this;
    }

    $tsExpires = $expires;
    if (is_string($expires)) {
      $tsExpires = strtotime($expires);

      // if $tsExpires is invalid and PHP is compiled as 32bit. Check if it fail reason is the 2038 bug
      if (!is_int($tsExpires) && PHP_INT_SIZE === 4) {
        $dateTime = new \DateTime($expires);
        if ($dateTime->format('Y') > 2038) {
          $tsExpires = PHP_INT_MAX;
        }
      }
    }

    if (!is_int($tsExpires) || $tsExpires < 0) {
      throw new Exception\InvalidArgumentException('Invalid expires time specified');
    }

    $this->expires = $tsExpires;
    return $this;
  }

  /**
   * @param bool $inSeconds
   *
   * @return int|string
   */
  public function getExpires($inSeconds = FALSE) {
    if ($this->expires === NULL) {
      return;
    }
    if ($inSeconds) {
      return $this->expires;
    }
    return gmdate('D, d-M-Y H:i:s', $this->expires) . ' GMT';
  }

  /**
   * @param string $domain
   *
   * @return SetCookie
   */
  public function setDomain($domain) {
    $this->domain = $domain;
    return $this;
  }

  /**
   * @return string
   */
  public function getDomain() {
    return $this->domain;
  }

  /**
   * @param string $path
   *
   * @return SetCookie
   */
  public function setPath($path) {
    $this->path = $path;
    return $this;
  }

  /**
   * @return string
   */
  public function getPath() {
    return $this->path;
  }

  /**
   * @param  bool $secure
   *
   * @return SetCookie
   */
  public function setSecure($secure) {
    $this->secure = $secure;
    return $this;
  }

  /**
   * Set whether the value for this cookie should be quoted
   *
   * @param  bool $quotedValue
   *
   * @return SetCookie
   */
  public function setQuoteFieldValue($quotedValue) {
    $this->quoteFieldValue = (bool) $quotedValue;
    return $this;
  }

  /**
   * @return bool
   */
  public function isSecure() {
    return $this->secure;
  }

  /**
   * @param  bool $httponly
   *
   * @return SetCookie
   */
  public function setHttponly($httponly) {
    $this->httponly = $httponly;
    return $this;
  }

  /**
   * @return bool
   */
  public function isHttponly() {
    return $this->httponly;
  }

  /**
   * Check whether the cookie has expired
   *
   * Always returns false if the cookie is a session cookie (has no expiry time)
   *
   * @param int $now Timestamp to consider as "now"
   *
   * @return bool
   */
  public function isExpired($now = NULL) {
    if ($now === NULL) {
      $now = time();
    }

    if (is_int($this->expires) && $this->expires < $now) {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Check whether the cookie is a session cookie (has no expiry time set)
   *
   * @return bool
   */
  public function isSessionCookie() {
    return ($this->expires === NULL);
  }

  /**
   * Check whether the value for this cookie should be quoted
   *
   * @return bool
   */
  public function hasQuoteFieldValue() {
    return $this->quoteFieldValue;
  }

  public function isValidForRequest($requestDomain, $path, $isSecure = FALSE) {
    if ($this->getDomain() && (strrpos($requestDomain, $this->getDomain()) === FALSE)) {
      return FALSE;
    }

    if ($this->getPath() && (strpos($path, $this->getPath()) !== 0)) {
      return FALSE;
    }

    if ($this->secure && $this->isSecure() !== $isSecure) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Checks whether the cookie should be sent or not in a specific scenario
   *
   * @param string|\Zend\Uri\Uri $uri URI to check against (secure, domain,
   *   path)
   * @param bool $matchSessionCookies Whether to send session cookies
   * @param int $now Override the current time when checking for expiry time
   *
   * @return bool
   * @throws Exception\InvalidArgumentException If URI does not have HTTP or
   *   HTTPS scheme.
   */
  public function match($uri, $matchSessionCookies = TRUE, $now = NULL) {
    if (is_string($uri)) {
      $uri = UriFactory::factory($uri);
    }

    // Make sure we have a valid Zend_Uri_Http object
    if (!($uri->isValid() && ($uri->getScheme() == 'http' || $uri->getScheme() == 'https'))) {
      throw new Exception\InvalidArgumentException('Passed URI is not a valid HTTP or HTTPS URI');
    }

    // Check that the cookie is secure (if required) and not expired
    if ($this->secure && $uri->getScheme() != 'https') {
      return FALSE;
    }
    if ($this->isExpired($now)) {
      return FALSE;
    }
    if ($this->isSessionCookie() && !$matchSessionCookies) {
      return FALSE;
    }

    // Check if the domain matches
    if (!self::matchCookieDomain($this->getDomain(), $uri->getHost())) {
      return FALSE;
    }

    // Check that path matches using prefix match
    if (!self::matchCookiePath($this->getPath(), $uri->getPath())) {
      return FALSE;
    }

    // If we didn't die until now, return true.
    return TRUE;
  }

  /**
   * Check if a cookie's domain matches a host name.
   *
   * Used by Zend\Http\Cookies for cookie matching
   *
   * @param  string $cookieDomain
   * @param  string $host
   *
   * @return bool
   */
  public static function matchCookieDomain($cookieDomain, $host) {
    $cookieDomain = strtolower($cookieDomain);
    $host = strtolower($host);
    // Check for either exact match or suffix match
    return ($cookieDomain == $host ||
      preg_match('/' . preg_quote($cookieDomain) . '$/', $host));
  }

  /**
   * Check if a cookie's path matches a URL path
   *
   * Used by Zend\Http\Cookies for cookie matching
   *
   * @param  string $cookiePath
   * @param  string $path
   *
   * @return bool
   */
  public static function matchCookiePath($cookiePath, $path) {
    return (strpos($path, $cookiePath) === 0);
  }

  public function toString() {
    return 'Set-Cookie: ' . $this->getFieldValue();
  }

  public function toStringMultipleHeaders(array $headers) {
    $headerLine = $this->toString();
    /* @var $header SetCookie */
    foreach ($headers as $header) {
      if (!$header instanceof SetCookie) {
        throw new Exception\RuntimeException(
          'The SetCookie multiple header implementation can only accept an array of SetCookie headers'
        );
      }
      $headerLine .= "\n" . $header->toString();
    }
    return $headerLine;
  }


}
