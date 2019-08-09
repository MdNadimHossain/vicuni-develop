<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field.
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?> 
<div class="important-dates-block clearfix">
  <div class="event-container-left">
    <?php foreach (["field_date", "field_event_date"] as $key): ?>
      <?php if (isset($fields[$key])): ?>
        <?php print $fields[$key]->content; ?>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
  <div class="event-container-right">
    <?php foreach (["title", "title_field", "field_feature_link", "nid"] as $key): ?>
      <?php if (isset($fields[$key])): ?>
        <?php print $fields[$key]->content; ?>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
</div>
