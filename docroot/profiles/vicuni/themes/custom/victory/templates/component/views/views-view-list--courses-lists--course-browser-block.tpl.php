<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<div class="item-list-wrapper">
  <?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <?php if ($id % (round(count($rows) / 3)) == 0): ?>
      <?php print $list_type_prefix; ?>
    <?php endif; ?>
    <li class="<?php print $classes_array[$id]; ?>"><?php print $row; ?></li>
    <?php if ($id % (round(count($rows) / 3)) == 2): ?>
      <?php print $list_type_suffix; ?>
    <?php endif; ?>
  <?php endforeach; ?>
  <?php print $wrapper_suffix; ?>
</div>
