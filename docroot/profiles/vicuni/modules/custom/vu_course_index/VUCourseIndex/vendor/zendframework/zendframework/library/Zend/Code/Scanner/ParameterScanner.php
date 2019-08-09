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

namespace Zend\Code\Scanner;

use Zend\Code\NameInformation;

class ParameterScanner {
  /**
   * @var bool
   */
  protected $isScanned = FALSE;

  /**
   * @var null|ClassScanner
   */
  protected $declaringScannerClass = NULL;

  /**
   * @var null|string
   */
  protected $declaringClass = NULL;

  /**
   * @var null|MethodScanner
   */
  protected $declaringScannerFunction = NULL;

  /**
   * @var null|string
   */
  protected $declaringFunction = NULL;

  /**
   * @var null|string
   */
  protected $defaultValue = NULL;

  /**
   * @var null|string
   */
  protected $class = NULL;

  /**
   * @var null|string
   */
  protected $name = NULL;

  /**
   * @var null|int
   */
  protected $position = NULL;

  /**
   * @var bool
   */
  protected $isArray = FALSE;

  /**
   * @var bool
   */
  protected $isDefaultValueAvailable = FALSE;

  /**
   * @var bool
   */
  protected $isOptional = FALSE;

  /**
   * @var bool
   */
  protected $isPassedByReference = FALSE;

  /**
   * @var array|null
   */
  protected $tokens = NULL;

  /**
   * @var null|NameInformation
   */
  protected $nameInformation = NULL;

  /**
   * @param  array $parameterTokens
   * @param  NameInformation $nameInformation
   */
  public function __construct(array $parameterTokens, NameInformation $nameInformation = NULL) {
    $this->tokens = $parameterTokens;
    $this->nameInformation = $nameInformation;
  }

  /**
   * Set declaring class
   *
   * @param  string $class
   *
   * @return void
   */
  public function setDeclaringClass($class) {
    $this->declaringClass = (string) $class;
  }

  /**
   * Set declaring scanner class
   *
   * @param  ClassScanner $scannerClass
   *
   * @return void
   */
  public function setDeclaringScannerClass(ClassScanner $scannerClass) {
    $this->declaringScannerClass = $scannerClass;
  }

  /**
   * Set declaring function
   *
   * @param  string $function
   *
   * @return void
   */
  public function setDeclaringFunction($function) {
    $this->declaringFunction = $function;
  }

  /**
   * Set declaring scanner function
   *
   * @param  MethodScanner $scannerFunction
   *
   * @return void
   */
  public function setDeclaringScannerFunction(MethodScanner $scannerFunction) {
    $this->declaringScannerFunction = $scannerFunction;
  }

  /**
   * Set position
   *
   * @param  int $position
   *
   * @return void
   */
  public function setPosition($position) {
    $this->position = $position;
  }

  /**
   * Scan
   *
   * @return void
   */
  protected function scan() {
    if ($this->isScanned) {
      return;
    }

    $tokens = &$this->tokens;

    reset($tokens);

    SCANNER_TOP:

    $token = current($tokens);

    if (is_string($token)) {
      // check pass by ref
      if ($token === '&') {
        $this->isPassedByReference = TRUE;
        goto SCANNER_CONTINUE;
      }
      if ($token === '=') {
        $this->isOptional = TRUE;
        $this->isDefaultValueAvailable = TRUE;
        goto SCANNER_CONTINUE;
      }
    }
    else {
      if ($this->name === NULL && ($token[0] === T_STRING || $token[0] === T_NS_SEPARATOR)) {
        $this->class .= $token[1];
        goto SCANNER_CONTINUE;
      }
      if ($token[0] === T_VARIABLE) {
        $this->name = ltrim($token[1], '$');
        goto SCANNER_CONTINUE;
      }
    }

    if ($this->name !== NULL) {
      $this->defaultValue .= trim((is_string($token)) ? $token : $token[1]);
    }

    SCANNER_CONTINUE:

    if (next($this->tokens) === FALSE) {
      goto SCANNER_END;
    }
    goto SCANNER_TOP;

    SCANNER_END:

    if ($this->class && $this->nameInformation) {
      $this->class = $this->nameInformation->resolveName($this->class);
    }

    $this->isScanned = TRUE;
  }

  /**
   * Get declaring scanner class
   *
   * @return ClassScanner
   */
  public function getDeclaringScannerClass() {
    return $this->declaringScannerClass;
  }

  /**
   * Get declaring class
   *
   * @return string
   */
  public function getDeclaringClass() {
    return $this->declaringClass;
  }

  /**
   * Get declaring scanner function
   *
   * @return MethodScanner
   */
  public function getDeclaringScannerFunction() {
    return $this->declaringScannerFunction;
  }

  /**
   * Get declaring function
   *
   * @return string
   */
  public function getDeclaringFunction() {
    return $this->declaringFunction;
  }

  /**
   * Get default value
   *
   * @return string
   */
  public function getDefaultValue() {
    $this->scan();

    return $this->defaultValue;
  }

  /**
   * Get class
   *
   * @return string
   */
  public function getClass() {
    $this->scan();

    return $this->class;
  }

  /**
   * Get name
   *
   * @return string
   */
  public function getName() {
    $this->scan();

    return $this->name;
  }

  /**
   * Get position
   *
   * @return int
   */
  public function getPosition() {
    $this->scan();

    return $this->position;
  }

  /**
   * Check if is array
   *
   * @return bool
   */
  public function isArray() {
    $this->scan();

    return $this->isArray;
  }

  /**
   * Check if default value is available
   *
   * @return bool
   */
  public function isDefaultValueAvailable() {
    $this->scan();

    return $this->isDefaultValueAvailable;
  }

  /**
   * Check if is optional
   *
   * @return bool
   */
  public function isOptional() {
    $this->scan();

    return $this->isOptional;
  }

  /**
   * Check if is passed by reference
   *
   * @return bool
   */
  public function isPassedByReference() {
    $this->scan();

    return $this->isPassedByReference;
  }
}
