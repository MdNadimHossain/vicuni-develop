<?php

namespace Doctrine\Tests\ORM\Hydration;

use Doctrine\ORM\Query\ParserResult;
use Doctrine\ORM\Query\Parser;

class HydrationTestCase extends \Doctrine\Tests\OrmTestCase {
  protected $_em;

  protected function setUp() {
    parent::setUp();
    $this->_em = $this->_getTestEntityManager();
  }

  /** Helper method */
  protected function _createParserResult($resultSetMapping, $isMixedQuery = FALSE) {
    $parserResult = new ParserResult;
    $parserResult->setResultSetMapping($resultSetMapping);
    //$parserResult->setDefaultQueryComponentAlias(key($queryComponents));
    //$parserResult->setTableAliasMap($tableToClassAliasMap);
    $parserResult->setMixedQuery($isMixedQuery);
    return $parserResult;
  }
}
