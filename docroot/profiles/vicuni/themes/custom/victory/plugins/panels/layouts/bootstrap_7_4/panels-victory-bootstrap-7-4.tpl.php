<?php

/**
 * @file
 * Bootstrap 7/4 panels layout plugin definition.
 */
?>
<div class="container">
  <div class="row">
    <div class="col-md-7">
      <?php echo $content['left']; ?>
    </div>
    <?php if (!empty($content['right'])) : ?>
      <div class="col-md-push-1 col-md-4">
        <?php echo $content['right']; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
