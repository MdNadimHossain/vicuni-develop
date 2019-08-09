<?php

/**
 * @file
 * Clear out the data from the field_location_other_editable tables.
 */

db_truncate('field_data_field_location_other_editable')->execute();
db_truncate('field_revision_field_location_other_editable')->execute();
