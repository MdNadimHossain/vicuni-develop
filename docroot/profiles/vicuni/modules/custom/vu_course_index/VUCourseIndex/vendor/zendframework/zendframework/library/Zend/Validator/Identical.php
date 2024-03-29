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

namespace Zend\Validator;

use Traversable;
use Zend\Stdlib\ArrayUtils;

class Identical extends AbstractValidator {
  /**
   * Error codes
   *
   * @const string
   */
  const NOT_SAME = 'notSame';
  const MISSING_TOKEN = 'missingToken';

  /**
   * Error messages
   *
   * @var array
   */
  protected $messageTemplates = array(
    self::NOT_SAME => "The two given tokens do not match",
    self::MISSING_TOKEN => 'No token was provided to match against',
  );

  /**
   * @var array
   */
  protected $messageVariables = array(
    'token' => 'tokenString'
  );

  /**
   * Original token against which to validate
   *
   * @var string
   */
  protected $tokenString;
  protected $token;
  protected $strict = TRUE;
  protected $literal = FALSE;

  /**
   * Sets validator options
   *
   * @param  mixed $token
   */
  public function __construct($token = NULL) {
    if ($token instanceof Traversable) {
      $token = ArrayUtils::iteratorToArray($token);
    }

    if (is_array($token) && array_key_exists('token', $token)) {
      if (array_key_exists('strict', $token)) {
        $this->setStrict($token['strict']);
      }

      if (array_key_exists('literal', $token)) {
        $this->setLiteral($token['literal']);
      }

      $this->setToken($token['token']);
    }
    elseif (NULL !== $token) {
      $this->setToken($token);
    }

    parent::__construct(is_array($token) ? $token : NULL);
  }

  /**
   * Retrieve token
   *
   * @return mixed
   */
  public function getToken() {
    return $this->token;
  }

  /**
   * Set token against which to compare
   *
   * @param  mixed $token
   *
   * @return Identical
   */
  public function setToken($token) {
    $this->tokenString = (is_array($token) ? var_export($token, TRUE) : (string) $token);
    $this->token = $token;
    return $this;
  }

  /**
   * Returns the strict parameter
   *
   * @return bool
   */
  public function getStrict() {
    return $this->strict;
  }

  /**
   * Sets the strict parameter
   *
   * @param  bool $strict
   *
   * @return Identical
   */
  public function setStrict($strict) {
    $this->strict = (bool) $strict;
    return $this;
  }

  /**
   * Returns the literal parameter
   *
   * @return bool
   */
  public function getLiteral() {
    return $this->literal;
  }

  /**
   * Sets the literal parameter
   *
   * @param  bool $literal
   *
   * @return Identical
   */
  public function setLiteral($literal) {
    $this->literal = (bool) $literal;
    return $this;
  }

  /**
   * Returns true if and only if a token has been set and the provided value
   * matches that token.
   *
   * @param  mixed $value
   * @param  array $context
   *
   * @return bool
   * @throws Exception\RuntimeException if the token doesn't exist in the
   *   context array
   */
  public function isValid($value, array $context = NULL) {
    $this->setValue($value);

    $token = $this->getToken();

    if (!$this->getLiteral() && $context !== NULL) {
      if (is_array($token)) {
        while (is_array($token)) {
          $key = key($token);
          if (!isset($context[$key])) {
            break;
          }
          $context = $context[$key];
          $token = $token[$key];
        }
      }

      // if $token is an array it means the above loop didn't went all the way down to the leaf,
      // so the $token structure doesn't match the $context structure
      if (is_array($token) || !isset($context[$token])) {
        $token = $this->getToken();
      }
      else {
        $token = $context[$token];
      }
    }

    if ($token === NULL) {
      $this->error(self::MISSING_TOKEN);
      return FALSE;
    }

    $strict = $this->getStrict();
    if (($strict && ($value !== $token)) || (!$strict && ($value != $token))) {
      $this->error(self::NOT_SAME);
      return FALSE;
    }

    return TRUE;
  }
}
