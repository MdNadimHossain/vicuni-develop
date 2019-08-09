<?php

/**
 * @file
 * Courses - How to Apply - VU Online.
 */
?>
<div class="hta-method-container <?php print (!$modal) ? $vu_online_class : ''; ?>">
  <div class="hta-vu-online">
    <?php if(!$modal): ?>
      <h3>Apply for online study</h3>
    <?php else: ?>
      <h4>Apply for online study</h4>
    <?php endif; ?>
    <p>Applications to study completely online <b>are open year-round.</b></p>
    <p>Start your application today to find out if you’re eligible for our accelerated online course.</p>
    <a href="<?php echo $online_link ?>" class="btn btn-secondary <?php print $modal ? 'btn-apply-direct-modal' : '' ?>" role="button">Apply for online study</a>
  </div>
</div>
