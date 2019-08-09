<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="entity-accordion-item accordion-item-accordion-item">
  <?php if (!empty($title)): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>
  <div class="content accordion">
    <?php print theme('vu_core_study_level_info_box', ['level' => $level]); ?>
    <?php foreach ($rows as $id => $row): ?>
      <div<?php print !empty($classes_array[$id]) ? ' class="' . $classes_array[$id] . '"' : ''; ?>>
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
