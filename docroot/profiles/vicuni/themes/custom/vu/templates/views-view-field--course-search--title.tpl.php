<?php

/**
 * @file
 * Add the title link to a course search result.
 *
 * @see vu_core_views_pre_render().
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 */
?>

<a href="/<?php print $row->_entity_properties['link_path']; ?>"><?php print $output; ?></a>
