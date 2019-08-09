<?php

/**
 * @file
 * Bootstrap accordion Display Suite layout.
 */
?>
<div class="accordion" id="accordion-<?php echo $accordion_id ?>">
  <div <?php echo drupal_attributes($item_attributes_array) ?>>
    <h3 id="accordion-<?php echo $accordion_id ?>-heading">
      <a <?php echo $title_attributes ?> role="button" data-toggle="collapse" data-parent="#accordion-<?php echo $accordion_id ?>" href="#accordion-<?php echo $accordion_id ?>-content" aria-expanded="false" aria-controls="accordion-<?php echo $accordion_id ?>-content">
        <?php echo $title ?>
        <span aria-hidden="true" class="accordion-title-icon"><?php echo $icon ?></span>
      </a>
    </h3>
    <div id="accordion-<?php echo $accordion_id ?>-content" <?php echo $content_attributes ?> aria-labelledby="accordion-<?php echo $accordion_id ?>-heading">
      <?php echo $ds_content ?>
    </div>
  </div>
</div>
