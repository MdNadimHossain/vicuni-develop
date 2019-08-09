<?php

/**
 * @file
 * VU page section single column Display Suite layout.
 */
?>
<div class="section <?php echo $classes; ?>">
  <?php if (!empty($top)) : ?>
    <?php echo $top; ?>
  <?php endif; ?>
  <div class="container">
    <div class="row">
      <div class="col-sm-12">
        <?php echo $middle; ?>
      </div>
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
