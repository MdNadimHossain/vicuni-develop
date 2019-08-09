<?php

/**
 * @file
 * Updates for PW-2991].
 *
 * Added redirect from /units to /units/search.
 */

$redirect = new stdClass();
redirect_object_prepare($redirect);
$redirect->source = 'node/10888896';
$redirect->redirect = 'units/search';
redirect_save($redirect);
