<?php

namespace Doctrine\Tests\ORM\Tools;

use Doctrine\ORM\Tools\SchemaTool;
use Doctrine\ORM\Tools\ToolEvents;
use Doctrine\ORM\Tools\Event\GenerateSchemaTableEventArgs;
use Doctrine\ORM\Tools\Event\GenerateSchemaEventArgs;

class SchemaToolTest extends \Doctrine\Tests\OrmTestCase {
  public function testAddUniqueIndexForUniqueFieldAnnotation() {
    $em = $this->_getTestEntityManager();
    $schemaTool = new SchemaTool($em);

    $classes = array(
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsAddress'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsArticle'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsComment'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsEmployee'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsGroup'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsPhonenumber'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsUser'),
    );

    $schema = $schemaTool->getSchemaFromMetadata($classes);

    $this->assertTrue($schema->hasTable('cms_users'), "Table cms_users should exist.");
    $this->assertTrue($schema->getTable('cms_users')
      ->columnsAreIndexed(array('username')), "username column should be indexed.");
  }

  public function testAnnotationOptionsAttribute() {
    $em = $this->_getTestEntityManager();
    $schemaTool = new SchemaTool($em);

    $classes = array(
      $em->getClassMetadata(__NAMESPACE__ . '\\TestEntityWithAnnotationOptionsAttribute'),
    );

    $schema = $schemaTool->getSchemaFromMetadata($classes);

    $expected = array('foo' => 'bar', 'baz' => array('key' => 'val'));

    $this->assertEquals($expected, $schema->getTable('TestEntityWithAnnotationOptionsAttribute')
      ->getOptions(), "options annotation are passed to the tables options");
    $this->assertEquals($expected, $schema->getTable('TestEntityWithAnnotationOptionsAttribute')
      ->getColumn('test')
      ->getCustomSchemaOptions(), "options annotation are passed to the columns customSchemaOptions");
  }

  /**
   * @group DDC-200
   */
  public function testPassColumnDefinitionToJoinColumn() {
    $customColumnDef = "MEDIUMINT(6) UNSIGNED NOT NULL";

    $em = $this->_getTestEntityManager();
    $schemaTool = new SchemaTool($em);

    $avatar = $em->getClassMetadata('Doctrine\Tests\Models\Forum\ForumAvatar');
    $avatar->fieldMappings['id']['columnDefinition'] = $customColumnDef;
    $user = $em->getClassMetadata('Doctrine\Tests\Models\Forum\ForumUser');

    $classes = array($avatar, $user);

    $schema = $schemaTool->getSchemaFromMetadata($classes);

    $this->assertTrue($schema->hasTable('forum_users'));
    $table = $schema->getTable("forum_users");
    $this->assertTrue($table->hasColumn('avatar_id'));
    $this->assertEquals($customColumnDef, $table->getColumn('avatar_id')
      ->getColumnDefinition());
  }

  /**
   * @group DDC-283
   */
  public function testPostGenerateEvents() {
    $listener = new GenerateSchemaEventListener();

    $em = $this->_getTestEntityManager();
    $em->getEventManager()->addEventListener(
      array(
        ToolEvents::postGenerateSchemaTable,
        ToolEvents::postGenerateSchema
      ), $listener
    );
    $schemaTool = new SchemaTool($em);

    $classes = array(
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsAddress'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsArticle'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsComment'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsEmployee'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsGroup'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsPhonenumber'),
      $em->getClassMetadata('Doctrine\Tests\Models\CMS\CmsUser'),
    );

    $schema = $schemaTool->getSchemaFromMetadata($classes);

    $this->assertEquals(count($classes), $listener->tableCalls);
    $this->assertTrue($listener->schemaCalled);
  }

  public function testNullDefaultNotAddedToCustomSchemaOptions() {
    $em = $this->_getTestEntityManager();
    $schemaTool = new SchemaTool($em);

    $classes = array(
      $em->getClassMetadata('Doctrine\Tests\Models\NullDefault\NullDefaultColumn'),
    );

    $customSchemaOptions = $schemaTool->getSchemaFromMetadata($classes)
      ->getTable('NullDefaultColumn')
      ->getColumn('nullDefault')
      ->getCustomSchemaOptions();

    $this->assertSame(array(), $customSchemaOptions);
  }

  /**
   * @group DDC-3671
   */
  public function testSchemaHasProperIndexesFromUniqueConstraintAnnotation() {
    $em = $this->_getTestEntityManager();
    $schemaTool = new SchemaTool($em);

    $classes = [
      $em->getClassMetadata(__NAMESPACE__ . '\\UniqueConstraintAnnotationModel'),
    ];

    $schema = $schemaTool->getSchemaFromMetadata($classes);

    $this->assertTrue($schema->hasTable('unique_constraint_annotation_table'));
    $table = $schema->getTable('unique_constraint_annotation_table');

    $this->assertEquals(2, count($table->getIndexes()));
    $this->assertTrue($table->hasIndex('primary'));
    $this->assertTrue($table->hasIndex('uniq_hash'));
  }
}

/**
 * @Entity
 * @Table(options={"foo": "bar", "baz": {"key": "val"}})
 */
class TestEntityWithAnnotationOptionsAttribute {
  /** @Id @Column */
  private $id;

  /**
   * @Column(type="string", options={"foo": "bar", "baz": {"key": "val"}})
   */
  private $test;
}

class GenerateSchemaEventListener {
  public $tableCalls = 0;
  public $schemaCalled = FALSE;

  public function postGenerateSchemaTable(GenerateSchemaTableEventArgs $eventArgs) {
    $this->tableCalls++;
  }

  public function postGenerateSchema(GenerateSchemaEventArgs $eventArgs) {
    $this->schemaCalled = TRUE;
  }
}

/**
 * @Entity
 * @Table(name="unique_constraint_annotation_table", uniqueConstraints={
 *   @UniqueConstraint(name="uniq_hash", columns={"hash"})
 * })
 */
class UniqueConstraintAnnotationModel {
  /** @Id @Column */
  private $id;

  /**
   * @Column(name="hash", type="string", length=8, nullable=false, unique=true)
   */
  private $hash;
}
