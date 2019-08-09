<?php

/**
 * @file
 * Bootstrap 9/3 stacked Display Suite layout.
 */
?>
<div class="section <?php echo $classes; ?>">
  <?php if (!empty($top)) : ?>
    <?php echo $top; ?>
  <?php endif; ?>
  <div class="container">
    <div class="row">
      <div class="col-sm-8">
        <?php echo $left; ?>
      </div>
      <?php if (!empty($right)) : ?>
        <div class="col-sm-4 col-md-4">
          <?php echo $right; ?>
        </div>
      <?php endif; ?>
    </div>
    <?php if (!empty($bottom)) : ?>
      <div class="row">
        <div class="col-sm-12">
          <?php echo $bottom; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>
