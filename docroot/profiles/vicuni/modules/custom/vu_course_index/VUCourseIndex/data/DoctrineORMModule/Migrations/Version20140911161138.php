<?php

namespace DoctrineORMModule\Migrations;

use Doctrine\DBAL\Migrations\AbstractMigration;
use Doctrine\DBAL\Schema\Schema;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
class Version20140911161138 extends AbstractMigration {

  /**
   *
   */
  public function up(Schema $schema) {
    // This up() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');
    $this->addSql('CREATE TABLE course_intake (id INT AUTO_INCREMENT NOT NULL, course_index_id VARCHAR(255) DEFAULT NULL, academic_year VARCHAR(4) DEFAULT NULL, academic_calendar_type VARCHAR(255) DEFAULT NULL, academic_calendar_sequence_number INT DEFAULT NULL, academic_start_date DATETIME DEFAULT NULL, academic_end_date DATETIME DEFAULT NULL, is_mid_year_intake VARCHAR(1) DEFAULT NULL, admissions_calendar_type VARCHAR(15) DEFAULT NULL, admissions_calendar_sequence_number INT DEFAULT NULL, admissions_start_date DATETIME DEFAULT NULL, early_admissions_end_date DATETIME DEFAULT NULL, admissions_end_date DATETIME DEFAULT NULL, vtac_open_date DATETIME DEFAULT NULL, vtac_timely_date DATETIME DEFAULT NULL, vtac_late_date DATETIME DEFAULT NULL, vtac_very_late_date DATETIME DEFAULT NULL, admissions_category VARCHAR(10) DEFAULT NULL, course_offering_id INT DEFAULT NULL, sector_code VARCHAR(10) DEFAULT NULL, course_code VARCHAR(10) DEFAULT NULL, course_version SMALLINT DEFAULT NULL, course_name VARCHAR(100) DEFAULT NULL, is_vtac_course VARCHAR(1) DEFAULT NULL, location VARCHAR(10) DEFAULT NULL, attendance_type VARCHAR(2) DEFAULT NULL, attendance_mode VARCHAR(2) DEFAULT NULL, course_type VARCHAR(60) DEFAULT NULL, place_type VARCHAR(10) DEFAULT NULL, specialisation_code VARCHAR(10) DEFAULT NULL, specialisation_name VARCHAR(90) DEFAULT NULL, unit_set_version SMALLINT DEFAULT NULL, application_Start_date DATETIME DEFAULT NULL, application_end_date DATETIME DEFAULT NULL, early_application_end_date DATETIME DEFAULT NULL, vtac_start_date DATETIME DEFAULT NULL, vtac_end_date DATETIME DEFAULT NULL, course_intake_status VARCHAR(10) DEFAULT NULL, college VARCHAR(10) DEFAULT NULL, college_name VARCHAR(60) DEFAULT NULL, is_admissions_centre_available VARCHAR(1) DEFAULT NULL, additional_requirements VARCHAR(200) DEFAULT NULL, update_date_time DATETIME DEFAULT NULL, published_date DATETIME DEFAULT NULL, created_date_time DATETIME NOT NULL, intake_enabled TINYINT(1) NOT NULL, INDEX find_latest (course_code, intake_enabled), PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci ENGINE = InnoDB');
  }

  /**
   *
   */
  public function down(Schema $schema) {
    // This down() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');

    $this->addSql('DROP TABLE course_intake');
  }

}
