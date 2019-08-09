<?php

/**
 * @file
 * PW-5035 - Remove Short courses fees (Details).
 */

field_delete_field('field_short_fees_details');
field_purge_batch(0);
