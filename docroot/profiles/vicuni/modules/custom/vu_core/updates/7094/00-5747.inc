<?php

/**
 * @file
 * PW-5747 - Delete records from researcher log.
 */

module_load_include('inc', 'vu_rp_api', 'vu_rp_api.cron');

// Delete records.
vu_rp_clean_rp_log_db_table();

// Optimize table.
db_query('OPTIMIZE TABLE vu_rp_log');
