<?php

/**
 * @file
 * Bootstrap 9/3 stacked Display Suite layout.
 */
?>
<div class="section <?php echo $classes; ?>">
  <?php if (!empty($top)) : ?>
    <div id="event-essentials-block">
      <div class="container">
        <?php echo $top; ?>
      </div>
    </div>
  <?php endif; ?>
  <div id="event-content" class="container">
    <div class="row">
      <div class="col-sm-8 event-content-left">
        <?php echo $left; ?>
        <p class="news-media-see-all">
          <a href="<?php print url('about-vu/news-events/events'); ?>"><?php print t('See all events'); ?></a>
        </p>
      </div>
      <?php if (!empty($right)) : ?>
        <div class="col-sm-4 col-md-4 event-content-right">
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
