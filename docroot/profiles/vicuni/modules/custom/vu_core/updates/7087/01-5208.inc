<?php

/**
 * @file
 * PW-5208 - Migrate data to new field.
 */

$fund_rows = db_select('field_data_field_rp_fund_source', 's')
  ->fields('s')
  ->execute()
  ->fetchAll();

if (!empty($fund_rows)) {
  foreach ($fund_rows as $row) {
    db_insert('field_data_field_rp_fund_sources')
      ->fields([
        'entity_type' => $row->entity_type,
        'bundle' => $row->bundle,
        'deleted' => $row->deleted,
        'entity_id' => $row->entity_id,
        'revision_id' => $row->revision_id,
        'language' => $row->language,
        'delta' => $row->delta,
        'field_rp_fund_sources_value' => $row->field_rp_fund_source_value,
        'field_rp_fund_sources_format' => '',
      ])
      ->execute();
  }
}

$fund_revision_rows = db_select('field_revision_field_rp_fund_source', 's')
  ->fields('s')
  ->execute()
  ->fetchAll();

if (!empty($fund_revision_rows)) {
  foreach ($fund_revision_rows as $row) {
    db_insert('field_revision_field_rp_fund_sources')
      ->fields([
        'entity_type' => $row->entity_type,
        'bundle' => $row->bundle,
        'deleted' => $row->deleted,
        'entity_id' => $row->entity_id,
        'revision_id' => $row->revision_id,
        'language' => $row->language,
        'delta' => $row->delta,
        'field_rp_fund_sources_value' => $row->field_rp_fund_source_value,
        'field_rp_fund_sources_format' => '',
      ])
      ->execute();
  }
}

// Remove the field that was used to generate the alias.
field_delete_field('field_rp_fund_source');
field_purge_batch(0);
