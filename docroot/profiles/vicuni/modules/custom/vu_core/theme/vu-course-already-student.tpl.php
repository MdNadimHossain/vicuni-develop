<?php

/**
 * @file
 * Template file for "Already a VU Student" block.
 */
?>

<div class="already-vu-student">
  <h3><?php print t('Already a VU student?'); ?></h3>
  <p>
    <?php print t('To transfer into this course from another <a href="@href">apply online at our Admissions centre</a>.', ['@href' => $link]); ?>
  </p>
  <p>
    <?php print t('Remember it’s best to be accepted into your new course before withdrawing from your current one.'); ?>
  </p>
</div>
