<?php

/**
 * @file
 * Template file for 'How to apply legacy' block.
 */
?>

<section id="how-to-apply" class="course-details-box">
  <?php if (!$international): ?>
    <a href="#goto-enquire-now" class="btn btn-primary" role="button">Enquire now</a>
  <?php endif; ?>
  <!-- How to apply: Short course with no online application. -->
  <?php if ($short_course && !$delivery->hasOnlineApplication()) : ?>
    <?php if ($admission_information) : ?>
      <h3><a href="#admission">How to register</a></h3>
    <?php else : ?>
      <h3>How to register</h3>
    <?php endif ?>
    <?php if (!empty($how_to_apply)) : ?>
      <?php print $how_to_apply ?>
    <?php endif ?>
  <?php endif ?>
  <!-- How to apply: Not short course or online application. -->
  <?php if (!$short_course || $delivery->hasOnlineApplication()) : ?>

    <?php if ($international || $how_to_apply) : ?>
      <?php if ($delivery->isOpen()) : ?>
        <a href="#apply-now" class="btn btn-primary" role="button">How to apply</a>
      <?php else : ?>
        <h3>How to apply</h3>
      <?php endif ?>
    <?php endif ?>

    <?php if (!empty($how_to_apply_summary)) : ?>
      <?php print $how_to_apply_summary ?>
    <?php endif ?>
  <?php endif ?>
</section>
