<?php

namespace DoctrineORMModule\Migrations;

use Doctrine\DBAL\Migrations\AbstractMigration;
use Doctrine\DBAL\Schema\Schema;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
class Version20141024103018 extends AbstractMigration {

  /**
   *
   */
  public function up(Schema $schema) {
    // This up() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');
    $this->addSql('ALTER TABLE course_intake CHANGE course_code course_code VARCHAR(20) NOT NULL');
  }

  /**
   *
   */
  public function down(Schema $schema) {
    // This down() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');
    $this->addSql('ALTER TABLE course_intake CHANGE course_code course_code VARCHAR(10) NOT NULL');
  }

}
