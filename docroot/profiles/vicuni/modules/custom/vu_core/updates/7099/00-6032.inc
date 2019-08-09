<?php

/**
 * @file
 * PW-6032 - Add Researcher Profile log clean up cron job to run every night.
 */

module_load_include('inc', 'vu_rp_api', 'vu_rp_api.cron');

// Delete records.
vu_rp_clean_rp_log_db_table();
