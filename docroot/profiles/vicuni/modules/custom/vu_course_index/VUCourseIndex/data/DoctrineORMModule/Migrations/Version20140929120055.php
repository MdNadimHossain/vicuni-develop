<?php

namespace DoctrineORMModule\Migrations;

use Doctrine\DBAL\Migrations\AbstractMigration;
use Doctrine\DBAL\Schema\Schema;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
class Version20140929120055 extends AbstractMigration {

  /**
   *
   */
  public function up(Schema $schema) {
    // This up() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');
    $this->addSql('ALTER TABLE course_intake ADD vtac_course_code VARCHAR(20) DEFAULT NULL');
  }

  /**
   *
   */
  public function down(Schema $schema) {
    // This down() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');
    $this->addSql('ALTER TABLE course_intake DROP COLUMN vtac_course_code');
  }

}
