<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT
 *   output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field.
 *   Do not use var_export to dump this object, as it can't handle the
 *   recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to
 *   use.
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
<div class="top">
  <?php if (!empty($fields['images']->content)): ?>
    <?php print $fields['images']->content; ?>
  <?php endif; ?>
  <div class="ig-author-pic-wrapper">
    <a href="//instagram.com/<?php print !empty($row->drupagram_username) ? $row->drupagram_username : ''; ?>" class="noext">
      <div class="ig-propic">
        <?php if (!empty($fields['profile_picture']->content)): ?>
          <?php print $fields['profile_picture']->content; ?>
        <?php endif; ?>
      </div>
      <div class="ig-author">
        <?php if (!empty($fields['full_name']->content)): ?>
          <?php print $fields['full_name']->content; ?>
        <?php endif; ?>
      </div>
    </a>
  </div>
</div>
<div class="bottom">
  <div class="ig-content">
    <?php if (!empty($fields['caption']->content)): ?>
      <?php print $fields['caption']->content; ?>
    <?php endif; ?>
  </div>
  <div class="ig-time">
    <?php if (!empty($fields['created_time']->content)): ?>
      <?php print $fields['created_time']->content; ?>
    <?php endif; ?>
  </div>
</div>
