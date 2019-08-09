<?php

namespace DoctrineORMModule\Migrations;

use Doctrine\DBAL\Migrations\AbstractMigration;
use Doctrine\DBAL\Schema\Schema;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
class Version20140929163304 extends AbstractMigration {

  /**
   *
   */
  public function up(Schema $schema) {
    // This up() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');

    $this->addSql('ALTER TABLE course_intake ADD application_entry_method VARCHAR(20) NOT NULL, ADD supplementary_forms VARCHAR(500) DEFAULT NULL, ADD referee_reports VARCHAR(200) DEFAULT NULL, ADD expression_of_interest DATETIME NOT NULL, DROP update_date_time, CHANGE course_index_id course_index_id VARCHAR(255) NOT NULL, CHANGE academic_year academic_year VARCHAR(4) NOT NULL, CHANGE academic_calendar_type academic_calendar_type VARCHAR(255) NOT NULL, CHANGE academic_calendar_sequence_number academic_calendar_sequence_number INT NOT NULL, CHANGE academic_start_date academic_start_date DATETIME NOT NULL, CHANGE academic_end_date academic_end_date DATETIME NOT NULL, CHANGE is_mid_year_intake is_mid_year_intake VARCHAR(1) NOT NULL, CHANGE admissions_calendar_type admissions_calendar_type VARCHAR(15) NOT NULL, CHANGE admissions_calendar_sequence_number admissions_calendar_sequence_number INT NOT NULL, CHANGE admissions_start_date admissions_start_date DATETIME NOT NULL, CHANGE admissions_end_date admissions_end_date DATETIME NOT NULL, CHANGE admissions_category admissions_category VARCHAR(10) NOT NULL, CHANGE course_offering_id course_offering_id INT NOT NULL, CHANGE sector_code sector_code VARCHAR(10) NOT NULL, CHANGE course_code course_code VARCHAR(10) NOT NULL, CHANGE course_version course_version SMALLINT NOT NULL, CHANGE course_name course_name VARCHAR(100) NOT NULL, CHANGE is_vtac_course is_vtac_course VARCHAR(1) NOT NULL, CHANGE location location VARCHAR(10) NOT NULL, CHANGE attendance_type attendance_type VARCHAR(2) NOT NULL, CHANGE attendance_mode attendance_mode VARCHAR(2) NOT NULL, CHANGE place_type place_type VARCHAR(10) NOT NULL, CHANGE course_intake_status course_intake_status VARCHAR(10) NOT NULL, CHANGE college college VARCHAR(10) NOT NULL, CHANGE college_name college_name VARCHAR(60) NOT NULL, CHANGE is_admissions_centre_available is_admissions_centre_available VARCHAR(1) NOT NULL, CHANGE published_date published_date DATETIME NOT NULL');
  }

  /**
   *
   */
  public function down(Schema $schema) {
    // This down() migration is auto-generated, please modify it to your needs.
    $this->abortIf($this->connection->getDatabasePlatform()
        ->getName() != 'mysql', 'Migration can only be executed safely on \'mysql\'.');
    $this->addSql('ALTER TABLE course_intake ADD update_date_time DATETIME DEFAULT NULL, DROP vtac_course_code, DROP application_entry_method, DROP supplementary_forms, DROP referee_reports, DROP expression_of_interest, CHANGE course_index_id course_index_id VARCHAR(255) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE academic_year academic_year VARCHAR(4) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE academic_calendar_type academic_calendar_type VARCHAR(255) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE academic_calendar_sequence_number academic_calendar_sequence_number INT DEFAULT NULL, CHANGE academic_start_date academic_start_date DATETIME DEFAULT NULL, CHANGE academic_end_date academic_end_date DATETIME DEFAULT NULL, CHANGE is_mid_year_intake is_mid_year_intake VARCHAR(1) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE admissions_calendar_type admissions_calendar_type VARCHAR(15) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE admissions_calendar_sequence_number admissions_calendar_sequence_number INT DEFAULT NULL, CHANGE admissions_start_date admissions_start_date DATETIME DEFAULT NULL, CHANGE admissions_end_date admissions_end_date DATETIME DEFAULT NULL, CHANGE admissions_category admissions_category VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE course_offering_id course_offering_id INT DEFAULT NULL, CHANGE sector_code sector_code VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE course_code course_code VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE course_version course_version SMALLINT DEFAULT NULL, CHANGE course_name course_name VARCHAR(100) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE is_vtac_course is_vtac_course VARCHAR(1) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE location location VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE attendance_type attendance_type VARCHAR(2) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE attendance_mode attendance_mode VARCHAR(2) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE place_type place_type VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE course_intake_status course_intake_status VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE college college VARCHAR(10) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE college_name college_name VARCHAR(60) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE is_admissions_centre_available is_admissions_centre_available VARCHAR(1) DEFAULT NULL COLLATE utf8_unicode_ci, CHANGE published_date published_date DATETIME DEFAULT NULL');
  }

}
