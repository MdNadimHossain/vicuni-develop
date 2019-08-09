<?php

/**
 * @file
 * Accordion.
 *
 * @TODO - Merge with bootstrap-accordion.tpl.php.
 */
?>
<div class="accordion" id="<?php echo $name ?>">
  <div class="accordion-inner">
    <h3 id="<?php echo $name ?>-heading">
      <a role="button" data-toggle="collapse" data-parent="#<?php echo $name ?>" href="#<?php echo $name ?>-content" aria-expanded="false" aria-controls="<?php echo $name ?>-content">
        <?php echo $title ?>
        <span aria-hidden="true" class="accordion-title-icon"><?php echo $icon ?></span>
      </a>
    </h3>
    <div id="<?php echo $name ?>-content" class="accordion-content collapse" aria-labelledby="accordion-<?php echo $name ?>-heading">
      <?php echo $content ?>
    </div>
  </div>
</div>
