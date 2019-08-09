<?php

/**
 * @file
 * VU Staff profile.
 */
?>
<div class="section <?php echo $classes; ?>">
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
  </div>
</div>

<?php print $bottom; ?>
