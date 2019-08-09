<?php

/**
 * @file
 * Template file for 'Structure' field on Course nodes.
 */
?>
<div class="<?php print $classes; ?> course-structure" <?php print $attributes; ?>>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="accordion-container">
        <h3 class="accordion-heading">
          <span class="toggle"><span class="show-structure">Show </span><span class="hide-structure">Hide </span>course structure</span>
        </h3>
        <div class="accordion view-group well">
          <?php
          // @todo: Move the below into a variable/preprocess
          ?>
          <?php print vumain_courses_transform_structure($element['#object']); ?>
          <div class="units-and-electives-close">
            <a class="close-link">
              Hide course structure
            </a>
          </div>
        </div>
      </div>
    <?php endforeach; ?>
  </div>
</div>
