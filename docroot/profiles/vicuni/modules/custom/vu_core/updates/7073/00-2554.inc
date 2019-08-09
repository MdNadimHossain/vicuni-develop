<?php

/**
 * @file
 * PW-2554 - Remove old title area image field for courses.
 */

field_delete_field('field_course_feature_image');
field_purge_batch(0);
