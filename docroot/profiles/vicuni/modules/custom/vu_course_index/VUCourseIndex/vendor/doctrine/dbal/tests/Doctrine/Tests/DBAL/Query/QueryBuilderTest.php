<?php

namespace Doctrine\Tests\DBAL\Query;

use Doctrine\DBAL\Query\Expression\ExpressionBuilder;
use Doctrine\DBAL\Query\QueryBuilder;

require_once __DIR__ . '/../../TestInit.php';

/**
 * @group DBAL-12
 */
class QueryBuilderTest extends \Doctrine\Tests\DbalTestCase {
  protected $conn;

  public function setUp() {
    $this->conn = $this->getMock('Doctrine\DBAL\Connection', array(), array(), '', FALSE);

    $expressionBuilder = new ExpressionBuilder($this->conn);

    $this->conn->expects($this->any())
      ->method('getExpressionBuilder')
      ->will($this->returnValue($expressionBuilder));
  }

  public function testSimpleSelect() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.id')
      ->from('users', 'u');

    $this->assertEquals('SELECT u.id FROM users u', (string) $qb);
  }

  public function testSelectWithSimpleWhere() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.id')
      ->from('users', 'u')
      ->where($expr->andX($expr->eq('u.nickname', '?')));

    $this->assertEquals("SELECT u.id FROM users u WHERE u.nickname = ?", (string) $qb);
  }

  public function testSelectWithLeftJoin() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->leftJoin('u', 'phones', 'p', $expr->eq('p.user_id', 'u.id'));

    $this->assertEquals('SELECT u.*, p.* FROM users u LEFT JOIN phones p ON p.user_id = u.id', (string) $qb);
  }

  public function testSelectWithJoin() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->Join('u', 'phones', 'p', $expr->eq('p.user_id', 'u.id'));

    $this->assertEquals('SELECT u.*, p.* FROM users u INNER JOIN phones p ON p.user_id = u.id', (string) $qb);
  }

  public function testSelectWithInnerJoin() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->innerJoin('u', 'phones', 'p', $expr->eq('p.user_id', 'u.id'));

    $this->assertEquals('SELECT u.*, p.* FROM users u INNER JOIN phones p ON p.user_id = u.id', (string) $qb);
  }

  public function testSelectWithRightJoin() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->rightJoin('u', 'phones', 'p', $expr->eq('p.user_id', 'u.id'));

    $this->assertEquals('SELECT u.*, p.* FROM users u RIGHT JOIN phones p ON p.user_id = u.id', (string) $qb);
  }

  public function testSelectWithAndWhereConditions() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->where('u.username = ?')
      ->andWhere('u.name = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u WHERE (u.username = ?) AND (u.name = ?)', (string) $qb);
  }

  public function testSelectWithOrWhereConditions() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->where('u.username = ?')
      ->orWhere('u.name = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u WHERE (u.username = ?) OR (u.name = ?)', (string) $qb);
  }

  public function testSelectWithOrOrWhereConditions() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->orWhere('u.username = ?')
      ->orWhere('u.name = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u WHERE (u.username = ?) OR (u.name = ?)', (string) $qb);
  }

  public function testSelectWithAndOrWhereConditions() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->where('u.username = ?')
      ->andWhere('u.username = ?')
      ->orWhere('u.name = ?')
      ->andWhere('u.name = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u WHERE (((u.username = ?) AND (u.username = ?)) OR (u.name = ?)) AND (u.name = ?)', (string) $qb);
  }

  public function testSelectGroupBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id', (string) $qb);
  }

  public function testSelectEmptyGroupBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->groupBy(array())
      ->from('users', 'u');

    $this->assertEquals('SELECT u.*, p.* FROM users u', (string) $qb);
  }

  public function testSelectEmptyAddGroupBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->addGroupBy(array())
      ->from('users', 'u');

    $this->assertEquals('SELECT u.*, p.* FROM users u', (string) $qb);
  }

  public function testSelectAddGroupBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->addGroupBy('u.foo');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id, u.foo', (string) $qb);
  }

  public function testSelectAddGroupBys() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->addGroupBy('u.foo', 'u.bar');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id, u.foo, u.bar', (string) $qb);
  }

  public function testSelectHaving() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->having('u.name = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id HAVING u.name = ?', (string) $qb);
  }

  public function testSelectAndHaving() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->andHaving('u.name = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id HAVING u.name = ?', (string) $qb);
  }

  public function testSelectHavingAndHaving() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->having('u.name = ?')
      ->andHaving('u.username = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id HAVING (u.name = ?) AND (u.username = ?)', (string) $qb);
  }

  public function testSelectHavingOrHaving() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->having('u.name = ?')
      ->orHaving('u.username = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id HAVING (u.name = ?) OR (u.username = ?)', (string) $qb);
  }

  public function testSelectOrHavingOrHaving() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->orHaving('u.name = ?')
      ->orHaving('u.username = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id HAVING (u.name = ?) OR (u.username = ?)', (string) $qb);
  }

  public function testSelectHavingAndOrHaving() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->groupBy('u.id')
      ->having('u.name = ?')
      ->orHaving('u.username = ?')
      ->andHaving('u.username = ?');

    $this->assertEquals('SELECT u.*, p.* FROM users u GROUP BY u.id HAVING ((u.name = ?) OR (u.username = ?)) AND (u.username = ?)', (string) $qb);
  }

  public function testSelectOrderBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->orderBy('u.name');

    $this->assertEquals('SELECT u.*, p.* FROM users u ORDER BY u.name ASC', (string) $qb);
  }

  public function testSelectAddOrderBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->orderBy('u.name')
      ->addOrderBy('u.username', 'DESC');

    $this->assertEquals('SELECT u.*, p.* FROM users u ORDER BY u.name ASC, u.username DESC', (string) $qb);
  }

  public function testSelectAddAddOrderBy() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*', 'p.*')
      ->from('users', 'u')
      ->addOrderBy('u.name')
      ->addOrderBy('u.username', 'DESC');

    $this->assertEquals('SELECT u.*, p.* FROM users u ORDER BY u.name ASC, u.username DESC', (string) $qb);
  }

  public function testEmptySelect() {
    $qb = new QueryBuilder($this->conn);
    $qb2 = $qb->select();

    $this->assertSame($qb, $qb2);
    $this->assertEquals(QueryBuilder::SELECT, $qb->getType());
  }

  public function testSelectAddSelect() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*')
      ->addSelect('p.*')
      ->from('users', 'u');

    $this->assertEquals('SELECT u.*, p.* FROM users u', (string) $qb);
  }

  public function testEmptyAddSelect() {
    $qb = new QueryBuilder($this->conn);
    $qb2 = $qb->addSelect();

    $this->assertSame($qb, $qb2);
    $this->assertEquals(QueryBuilder::SELECT, $qb->getType());
  }

  public function testSelectMultipleFrom() {
    $qb = new QueryBuilder($this->conn);
    $expr = $qb->expr();

    $qb->select('u.*')
      ->addSelect('p.*')
      ->from('users', 'u')
      ->from('phonenumbers', 'p');

    $this->assertEquals('SELECT u.*, p.* FROM users u, phonenumbers p', (string) $qb);
  }

  public function testUpdate() {
    $qb = new QueryBuilder($this->conn);
    $qb->update('users', 'u')
      ->set('u.foo', '?')
      ->set('u.bar', '?');

    $this->assertEquals(QueryBuilder::UPDATE, $qb->getType());
    $this->assertEquals('UPDATE users u SET u.foo = ?, u.bar = ?', (string) $qb);
  }

  public function testUpdateWithoutAlias() {
    $qb = new QueryBuilder($this->conn);
    $qb->update('users')
      ->set('foo', '?')
      ->set('bar', '?');

    $this->assertEquals('UPDATE users SET foo = ?, bar = ?', (string) $qb);
  }

  public function testUpdateWhere() {
    $qb = new QueryBuilder($this->conn);
    $qb->update('users', 'u')
      ->set('u.foo', '?')
      ->where('u.foo = ?');

    $this->assertEquals('UPDATE users u SET u.foo = ? WHERE u.foo = ?', (string) $qb);
  }

  public function testEmptyUpdate() {
    $qb = new QueryBuilder($this->conn);
    $qb2 = $qb->update();

    $this->assertEquals(QueryBuilder::UPDATE, $qb->getType());
    $this->assertSame($qb2, $qb);
  }

  public function testDelete() {
    $qb = new QueryBuilder($this->conn);
    $qb->delete('users', 'u');

    $this->assertEquals(QueryBuilder::DELETE, $qb->getType());
    $this->assertEquals('DELETE FROM users u', (string) $qb);
  }

  public function testDeleteWithoutAlias() {
    $qb = new QueryBuilder($this->conn);
    $qb->delete('users');

    $this->assertEquals(QueryBuilder::DELETE, $qb->getType());
    $this->assertEquals('DELETE FROM users', (string) $qb);
  }

  public function testDeleteWhere() {
    $qb = new QueryBuilder($this->conn);
    $qb->delete('users', 'u')
      ->where('u.foo = ?');

    $this->assertEquals('DELETE FROM users u WHERE u.foo = ?', (string) $qb);
  }

  public function testEmptyDelete() {
    $qb = new QueryBuilder($this->conn);
    $qb2 = $qb->delete();

    $this->assertEquals(QueryBuilder::DELETE, $qb->getType());
    $this->assertSame($qb2, $qb);
  }

  public function testInsertValues() {
    $qb = new QueryBuilder($this->conn);
    $qb->insert('users')
      ->values(
        array(
          'foo' => '?',
          'bar' => '?'
        )
      );

    $this->assertEquals(QueryBuilder::INSERT, $qb->getType());
    $this->assertEquals('INSERT INTO users (foo, bar) VALUES(?, ?)', (string) $qb);
  }

  public function testInsertReplaceValues() {
    $qb = new QueryBuilder($this->conn);
    $qb->insert('users')
      ->values(
        array(
          'foo' => '?',
          'bar' => '?'
        )
      )
      ->values(
        array(
          'bar' => '?',
          'foo' => '?'
        )
      );

    $this->assertEquals(QueryBuilder::INSERT, $qb->getType());
    $this->assertEquals('INSERT INTO users (bar, foo) VALUES(?, ?)', (string) $qb);
  }

  public function testInsertSetValue() {
    $qb = new QueryBuilder($this->conn);
    $qb->insert('users')
      ->setValue('foo', 'bar')
      ->setValue('bar', '?')
      ->setValue('foo', '?');

    $this->assertEquals(QueryBuilder::INSERT, $qb->getType());
    $this->assertEquals('INSERT INTO users (foo, bar) VALUES(?, ?)', (string) $qb);
  }

  public function testInsertValuesSetValue() {
    $qb = new QueryBuilder($this->conn);
    $qb->insert('users')
      ->values(
        array(
          'foo' => '?'
        )
      )
      ->setValue('bar', '?');

    $this->assertEquals(QueryBuilder::INSERT, $qb->getType());
    $this->assertEquals('INSERT INTO users (foo, bar) VALUES(?, ?)', (string) $qb);
  }

  public function testEmptyInsert() {
    $qb = new QueryBuilder($this->conn);
    $qb2 = $qb->insert();

    $this->assertEquals(QueryBuilder::INSERT, $qb->getType());
    $this->assertSame($qb2, $qb);
  }

  public function testGetConnection() {
    $qb = new QueryBuilder($this->conn);
    $this->assertSame($this->conn, $qb->getConnection());
  }

  public function testGetState() {
    $qb = new QueryBuilder($this->conn);

    $this->assertEquals(QueryBuilder::STATE_CLEAN, $qb->getState());

    $qb->select('u.*')->from('users', 'u');

    $this->assertEquals(QueryBuilder::STATE_DIRTY, $qb->getState());

    $sql1 = $qb->getSQL();

    $this->assertEquals(QueryBuilder::STATE_CLEAN, $qb->getState());
    $this->assertEquals($sql1, $qb->getSQL());
  }

  public function testSetMaxResults() {
    $qb = new QueryBuilder($this->conn);
    $qb->setMaxResults(10);

    $this->assertEquals(QueryBuilder::STATE_DIRTY, $qb->getState());
    $this->assertEQuals(10, $qb->getMaxResults());
  }

  public function testSetFirstResult() {
    $qb = new QueryBuilder($this->conn);
    $qb->setFirstResult(10);

    $this->assertEquals(QueryBuilder::STATE_DIRTY, $qb->getState());
    $this->assertEQuals(10, $qb->getFirstResult());
  }

  public function testResetQueryPart() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.*')->from('users', 'u')->where('u.name = ?');

    $this->assertEquals('SELECT u.* FROM users u WHERE u.name = ?', (string) $qb);
    $qb->resetQueryPart('where');
    $this->assertEquals('SELECT u.* FROM users u', (string) $qb);
  }

  public function testResetQueryParts() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.*')
      ->from('users', 'u')
      ->where('u.name = ?')
      ->orderBy('u.name');

    $this->assertEquals('SELECT u.* FROM users u WHERE u.name = ? ORDER BY u.name ASC', (string) $qb);
    $qb->resetQueryParts(array('where', 'orderBy'));
    $this->assertEquals('SELECT u.* FROM users u', (string) $qb);
  }

  public function testCreateNamedParameter() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.*')->from('users', 'u')->where(
      $qb->expr()->eq('u.name', $qb->createNamedParameter(10, \PDO::PARAM_INT))
    );

    $this->assertEquals('SELECT u.* FROM users u WHERE u.name = :dcValue1', (string) $qb);
    $this->assertEquals(10, $qb->getParameter('dcValue1'));
    $this->assertEquals(\PDO::PARAM_INT, $qb->getParameterType('dcValue1'));
  }

  public function testCreateNamedParameterCustomPlaceholder() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.*')->from('users', 'u')->where(
      $qb->expr()
        ->eq('u.name', $qb->createNamedParameter(10, \PDO::PARAM_INT, ':test'))
    );

    $this->assertEquals('SELECT u.* FROM users u WHERE u.name = :test', (string) $qb);
    $this->assertEquals(10, $qb->getParameter('test'));
    $this->assertEquals(\PDO::PARAM_INT, $qb->getParameterType('test'));
  }

  public function testCreatePositionalParameter() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.*')->from('users', 'u')->where(
      $qb->expr()
        ->eq('u.name', $qb->createPositionalParameter(10, \PDO::PARAM_INT))
    );

    $this->assertEquals('SELECT u.* FROM users u WHERE u.name = ?', (string) $qb);
    $this->assertEquals(10, $qb->getParameter(1));
    $this->assertEquals(\PDO::PARAM_INT, $qb->getParameterType(1));
  }

  /**
   * @group DBAL-172
   */
  public function testReferenceJoinFromJoin() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('COUNT(DISTINCT news.id)')
      ->from('cb_newspages', 'news')
      ->innerJoin('news', 'nodeversion', 'nv', 'nv.refId = news.id AND nv.refEntityname=\'News\'')
      ->innerJoin('invalid', 'nodetranslation', 'nt', 'nv.nodetranslation = nt.id')
      ->innerJoin('nt', 'node', 'n', 'nt.node = n.id')
      ->where('nt.lang = :lang AND n.deleted != 1');

    $this->setExpectedException('Doctrine\DBAL\Query\QueryException', "The given alias 'invalid' is not part of any FROM or JOIN clause table. The currently registered aliases are: news, nv.");
    $this->assertEquals('', $qb->getSQL());
  }

  /**
   * @group DBAL-172
   */
  public function testSelectFromMasterWithWhereOnJoinedTables() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('COUNT(DISTINCT news.id)')
      ->from('newspages', 'news')
      ->innerJoin('news', 'nodeversion', 'nv', "nv.refId = news.id AND nv.refEntityname='Entity\\News'")
      ->innerJoin('nv', 'nodetranslation', 'nt', 'nv.nodetranslation = nt.id')
      ->innerJoin('nt', 'node', 'n', 'nt.node = n.id')
      ->where('nt.lang = ?')
      ->andWhere('n.deleted = 0');

    $this->assertEquals("SELECT COUNT(DISTINCT news.id) FROM newspages news INNER JOIN nodeversion nv ON nv.refId = news.id AND nv.refEntityname='Entity\\News' INNER JOIN nodetranslation nt ON nv.nodetranslation = nt.id INNER JOIN node n ON nt.node = n.id WHERE (nt.lang = ?) AND (n.deleted = 0)", $qb->getSQL());
  }

  /**
   * @group DBAL-442
   */
  public function testSelectWithMultipleFromAndJoins() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('DISTINCT u.id')
      ->from('users', 'u')
      ->from('articles', 'a')
      ->innerJoin('u', 'permissions', 'p', 'p.user_id = u.id')
      ->innerJoin('a', 'comments', 'c', 'c.article_id = a.id')
      ->where('u.id = a.user_id')
      ->andWhere('p.read = 1');

    $this->assertEquals('SELECT DISTINCT u.id FROM users u INNER JOIN permissions p ON p.user_id = u.id, articles a INNER JOIN comments c ON c.article_id = a.id WHERE (u.id = a.user_id) AND (p.read = 1)', $qb->getSQL());
  }

  /**
   * @group DBAL-774
   */
  public function testSelectWithJoinsWithMultipleOnConditionsParseOrder() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('a.id')
      ->from('table_a', 'a')
      ->join('a', 'table_b', 'b', 'a.fk_b = b.id')
      ->join('b', 'table_c', 'c', 'c.fk_b = b.id AND b.language = ?')
      ->join('a', 'table_d', 'd', 'a.fk_d = d.id')
      ->join('c', 'table_e', 'e', 'e.fk_c = c.id AND e.fk_d = d.id');

    $this->assertEquals(
      'SELECT a.id ' .
      'FROM table_a a ' .
      'INNER JOIN table_b b ON a.fk_b = b.id ' .
      'INNER JOIN table_d d ON a.fk_d = d.id ' .
      'INNER JOIN table_c c ON c.fk_b = b.id AND b.language = ? ' .
      'INNER JOIN table_e e ON e.fk_c = c.id AND e.fk_d = d.id',
      (string) $qb
    );
  }

  /**
   * @group DBAL-774
   */
  public function testSelectWithMultipleFromsAndJoinsWithMultipleOnConditionsParseOrder() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('a.id')
      ->from('table_a', 'a')
      ->from('table_f', 'f')
      ->join('a', 'table_b', 'b', 'a.fk_b = b.id')
      ->join('b', 'table_c', 'c', 'c.fk_b = b.id AND b.language = ?')
      ->join('a', 'table_d', 'd', 'a.fk_d = d.id')
      ->join('c', 'table_e', 'e', 'e.fk_c = c.id AND e.fk_d = d.id')
      ->join('f', 'table_g', 'g', 'f.fk_g = g.id');

    $this->assertEquals(
      'SELECT a.id ' .
      'FROM table_a a ' .
      'INNER JOIN table_b b ON a.fk_b = b.id ' .
      'INNER JOIN table_d d ON a.fk_d = d.id ' .
      'INNER JOIN table_c c ON c.fk_b = b.id AND b.language = ? ' .
      'INNER JOIN table_e e ON e.fk_c = c.id AND e.fk_d = d.id, ' .
      'table_f f ' .
      'INNER JOIN table_g g ON f.fk_g = g.id',
      (string) $qb
    );
  }

  public function testClone() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.id')
      ->from('users', 'u')
      ->where('u.id = :test');

    $qb->setParameter(':test', (object) 1);

    $qb_clone = clone $qb;

    $this->assertEquals((string) $qb, (string) $qb_clone);

    $qb->andWhere('u.id = 1');

    $this->assertFalse($qb->getQueryParts() === $qb_clone->getQueryParts());
    $this->assertFalse($qb->getParameters() === $qb_clone->getParameters());
  }

  public function testSimpleSelectWithoutTableAlias() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('id')
      ->from('users');

    $this->assertEquals('SELECT id FROM users', (string) $qb);
  }

  public function testSelectWithSimpleWhereWithoutTableAlias() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('id', 'name')
      ->from('users')
      ->where('awesome=9001');

    $this->assertEquals("SELECT id, name FROM users WHERE awesome=9001", (string) $qb);
  }

  public function testComplexSelectWithoutTableAliases() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('DISTINCT users.id')
      ->from('users')
      ->from('articles')
      ->innerJoin('users', 'permissions', 'p', 'p.user_id = users.id')
      ->innerJoin('articles', 'comments', 'c', 'c.article_id = articles.id')
      ->where('users.id = articles.user_id')
      ->andWhere('p.read = 1');

    $this->assertEquals('SELECT DISTINCT users.id FROM users INNER JOIN permissions p ON p.user_id = users.id, articles INNER JOIN comments c ON c.article_id = articles.id WHERE (users.id = articles.user_id) AND (p.read = 1)', $qb->getSQL());
  }

  public function testComplexSelectWithSomeTableAliases() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('u.id')
      ->from('users', 'u')
      ->from('articles')
      ->innerJoin('u', 'permissions', 'p', 'p.user_id = u.id')
      ->innerJoin('articles', 'comments', 'c', 'c.article_id = articles.id');

    $this->assertEquals('SELECT u.id FROM users u INNER JOIN permissions p ON p.user_id = u.id, articles INNER JOIN comments c ON c.article_id = articles.id', $qb->getSQL());
  }

  public function testSelectAllFromTableWithoutTableAlias() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('users.*')
      ->from('users');

    $this->assertEquals("SELECT users.* FROM users", (string) $qb);
  }

  public function testSelectAllWithoutTableAlias() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('*')
      ->from('users');

    $this->assertEquals("SELECT * FROM users", (string) $qb);
  }

  /**
   * @group DBAL-959
   */
  public function testGetParameterType() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('*')->from('users');

    $this->assertNull($qb->getParameterType('name'));

    $qb->where('name = :name');
    $qb->setParameter('name', 'foo');

    $this->assertNull($qb->getParameterType('name'));

    $qb->setParameter('name', 'foo', \PDO::PARAM_STR);

    $this->assertSame(\PDO::PARAM_STR, $qb->getParameterType('name'));
  }

  /**
   * @group DBAL-959
   */
  public function testGetParameterTypes() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('*')->from('users');

    $this->assertSame(array(), $qb->getParameterTypes());

    $qb->where('name = :name');
    $qb->setParameter('name', 'foo');

    $this->assertSame(array(), $qb->getParameterTypes());

    $qb->setParameter('name', 'foo', \PDO::PARAM_STR);

    $qb->where('is_active = :isActive');
    $qb->setParameter('isActive', TRUE, \PDO::PARAM_BOOL);

    $this->assertSame(array(
      'name' => \PDO::PARAM_STR,
      'isActive' => \PDO::PARAM_BOOL
    ), $qb->getParameterTypes());
  }

  /**
   * @group DBAL-1137
   */
  public function testJoinWithNonUniqueAliasThrowsException() {
    $qb = new QueryBuilder($this->conn);

    $qb->select('a.id')
      ->from('table_a', 'a')
      ->join('a', 'table_b', 'a', 'a.fk_b = a.id');

    $this->setExpectedException(
      'Doctrine\DBAL\Query\QueryException',
      "The given alias 'a' is not unique in FROM and JOIN clause table. The currently registered aliases are: a."
    );

    $qb->getSQL();
  }
}
