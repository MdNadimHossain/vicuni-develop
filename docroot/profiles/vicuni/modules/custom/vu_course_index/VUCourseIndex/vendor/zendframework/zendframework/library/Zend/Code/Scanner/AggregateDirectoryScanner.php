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

use Zend\Code\Exception;

class AggregateDirectoryScanner extends DirectoryScanner {
  /**
   * @var bool
   */
  protected $isScanned = FALSE;

  /**
   * @param  bool $returnScannerClass
   *
   * @todo not implemented
   */
  public function getNamespaces($returnScannerClass = FALSE) {
    // @todo
  }

  /*
  public function getUses($returnScannerClass = false)
  {}
  */

  public function getIncludes($returnScannerClass = FALSE) {
  }

  public function getClasses($returnScannerClass = FALSE, $returnDerivedScannerClass = FALSE) {
    $classes = array();
    foreach ($this->directories as $scanner) {
      $classes += $scanner->getClasses();
    }
    if ($returnScannerClass) {
      foreach ($classes as $index => $class) {
        $classes[$index] = $this->getClass($class, $returnScannerClass, $returnDerivedScannerClass);
      }
    }

    return $classes;
  }

  /**
   * @param  string $class
   *
   * @return bool
   */
  public function hasClass($class) {
    foreach ($this->directories as $scanner) {
      if ($scanner->hasClass($class)) {
        break;
      }
      else {
        unset($scanner);
      }
    }

    return (isset($scanner));
  }

  /**
   * @param  string $class
   * @param  bool $returnScannerClass
   * @param  bool $returnDerivedScannerClass
   *
   * @return ClassScanner|DerivedClassScanner
   * @throws Exception\RuntimeException
   */
  public function getClass($class, $returnScannerClass = TRUE, $returnDerivedScannerClass = FALSE) {
    foreach ($this->directories as $scanner) {
      if ($scanner->hasClass($class)) {
        break;
      }
      else {
        unset($scanner);
      }
    }

    if (!isset($scanner)) {
      throw new Exception\RuntimeException('Class by that name was not found.');
    }

    $classScanner = $scanner->getClass($class);

    return new DerivedClassScanner($classScanner, $this);
  }

  /**
   * @param bool $returnScannerClass
   */
  public function getFunctions($returnScannerClass = FALSE) {
    $this->scan();

    if (!$returnScannerClass) {
      $functions = array();
      foreach ($this->infos as $info) {
        if ($info['type'] == 'function') {
          $functions[] = $info['name'];
        }
      }

      return $functions;
    }
    $scannerClass = new FunctionScanner();
    // @todo
  }
}
