<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright  Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license    http://framework.zend.com/license/new-bsd     New BSD License
 */

namespace Zend\Form\Element;

use Zend\Form\Element;

class Image extends Element {
  /**
   * Seed attributes
   *
   * @var array
   */
  protected $attributes = array(
    'type' => 'image',
  );
}
