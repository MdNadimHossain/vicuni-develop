<?php

/**
 * @file
 * Views page template for Researchers Profile search page.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists.
 *   - This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling
 *   - this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the
 *   - inline_html to use.
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
<div class="rp-content">
  <a href="<?php print strip_tags($fields['nothing']->content); ?>">
    <div class="rp-left-content">
      <div class="rp-photo"><?php print $fields['field_rp_photo']->content; ?></div>
      <div class="staff-photo"><?php print $fields['field_staff_picture']->content; ?></div>
    </div>
    <div class="rp-right-content">
      <div class="rp-title"><?php print $fields['title']->content; ?></div>
      <div class="availability">
        <div class="supervisor-unknown"><?php print $fields['supervisor_unknown']->content; ?></div>
        <div class="rp-av-to-supervise"><?php print $fields['field_rp_sup_is_available']->content; ?></div>
        <div class="media-ready"><?php print $fields['field_media_ready']->content; ?></div>
        <div class="rp-av-to-media"><?php print $fields['field_rp_available_to_media']->content; ?></div>
      </div>
      <div class="staff-expertise"><?php print $fields['field_staff_expertise']->content; ?><?php print $fields['field_rp_expertise']->content; ?></div>
      <div class="staff-bio"><?php print $fields['field_staff_search_snippet']->content; ?><?php print $fields['field_rp_shorter_biography']->content; ?></div>
      <div class="profile-link"><?php print $fields['field_rpa_first_name']->content; ?></div>
    </div>
  </a>
</div>
