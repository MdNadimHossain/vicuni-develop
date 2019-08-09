<?php

/**
 * @file
 * Template file for 'Request callback' block.
 */
?>

<section id="request-callback" class="course-details-box">
  <h3><?php print $title; ?></h3>
  <p>
    Request a call back from one of our experienced <?php echo $advice_center ?> course advisers to get your questions answered.
  </p>
  <?php print t('<a class="btn btn-secondary ext" href="@url" role="button">Request a call back</a>', ['@url' => $callback_link]); ?>
</section>
