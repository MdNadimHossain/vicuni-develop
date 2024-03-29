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

namespace Zend\Http\Header\Accept\FieldValuePart;

/**
 * Field Value Part
 *
 *
 * @see        http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.1
 */
class AcceptFieldValuePart extends AbstractFieldValuePart {

  /**
   * @return string
   */
  public function getSubtype() {
    return $this->getInternalValues()->subtype;
  }

  /**
   * @return string
   */
  public function getSubtypeRaw() {
    return $this->getInternalValues()->subtypeRaw;
  }

  /**
   * @return string
   */
  public function getFormat() {
    return $this->getInternalValues()->format;
  }
}
