<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Db\Sql\Ddl\Column;

class Char extends Column {
  /**
   * @var string
   */
  protected $specification = '%s CHAR(%s) %s %s';

  /**
   * @var int
   */
  protected $length;

  /**
   * @param string $name
   * @param int $length
   */
  public function __construct($name, $length) {
    $this->name = $name;
    $this->length = $length;
  }

  /**
   * @return array
   */
  public function getExpressionData() {
    $spec = $this->specification;
    $params = array();

    $types = array(self::TYPE_IDENTIFIER, self::TYPE_LITERAL);
    $params[] = $this->name;
    $params[] = $this->length;

    $types[] = self::TYPE_LITERAL;
    $params[] = (!$this->isNullable) ? 'NOT NULL' : '';

    $types[] = ($this->default !== NULL) ? self::TYPE_VALUE : self::TYPE_LITERAL;
    $params[] = ($this->default !== NULL) ? $this->default : '';

    return array(
      array(
        $spec,
        $params,
        $types,
      )
    );
  }
}
