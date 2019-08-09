--
-- This file is used to run custom SQL commands to additionally sanitise or
-- trim the database in order to speed-up database import when the project is
-- built.
--

-- Remove webform submissions.
create table if not exists `webform_submitted_data`;
TRUNCATE TABLE `webform_submitted_data`;

-- Below are the largest tables in the database that can be truncated.
-- They are currently not active because it may affect testing.
--
-- create table if not exists `field_revision_field_destination_page`;
-- TRUNCATE TABLE `field_revision_field_destination_page`;
--
-- create table if not exists `field_data_field_destination_page`;
-- TRUNCATE TABLE `field_data_field_destination_page`;
--
-- create table if not exists `field_revision_field_imp_structure`;
-- TRUNCATE TABLE `field_revision_field_imp_structure`;
--
-- create table if not exists `field_revision_body`;
-- TRUNCATE TABLE `field_revision_body`;
--
-- create table if not exists `field_revision_field_body`;
-- TRUNCATE TABLE `field_revision_field_body`;
--
-- create table if not exists `field_data_field_body`;
-- TRUNCATE TABLE `field_data_field_body`;
