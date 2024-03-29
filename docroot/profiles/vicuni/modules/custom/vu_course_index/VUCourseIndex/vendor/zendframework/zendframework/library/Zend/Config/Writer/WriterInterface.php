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

namespace Zend\Config\Writer;

interface WriterInterface {
  /**
   * Write a config object to a file.
   *
   * @param  string $filename
   * @param  mixed $config
   * @param  bool $exclusiveLock
   *
   * @return void
   */
  public function toFile($filename, $config, $exclusiveLock = TRUE);

  /**
   * Write a config object to a string.
   *
   * @param  mixed $config
   *
   * @return string
   */
  public function toString($config);
}
