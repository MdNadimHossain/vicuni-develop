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

namespace Zend\Code\Generator\DocBlock\Tag;

class MethodTag extends AbstractTypeableTag implements TagInterface {
  /**
   * @var string
   */
  protected $methodName = NULL;

  /**
   * @var bool
   */
  protected $isStatic = FALSE;

  /**
   * @param string $methodName
   * @param array $types
   * @param string $description
   * @param bool $isStatic
   */
  public function __construct($methodName = NULL, $types = array(), $description = NULL, $isStatic = FALSE) {
    if (!empty($methodName)) {
      $this->setMethodName($methodName);
    }

    $this->setIsStatic((bool) $isStatic);

    parent::__construct($types, $description);
  }

  /**
   * @return string
   */
  public function getName() {
    return 'method';
  }

  /**
   * @param boolean $isStatic
   *
   * @return MethodTag
   */
  public function setIsStatic($isStatic) {
    $this->isStatic = $isStatic;
    return $this;
  }

  /**
   * @return boolean
   */
  public function isStatic() {
    return $this->isStatic;
  }

  /**
   * @param string $methodName
   *
   * @return MethodTag
   */
  public function setMethodName($methodName) {
    $this->methodName = rtrim($methodName, ')(');
    return $this;
  }

  /**
   * @return string
   */
  public function getMethodName() {
    return $this->methodName;
  }

  /**
   * @return string
   */
  public function generate() {
    $output = '@method'
      . (($this->isStatic) ? ' static' : '')
      . ((!empty($this->types)) ? ' ' . $this->getTypesAsString() : '')
      . ((!empty($this->methodName)) ? ' ' . $this->methodName . '()' : '')
      . ((!empty($this->description)) ? ' ' . $this->description : '');

    return $output;
  }
}
