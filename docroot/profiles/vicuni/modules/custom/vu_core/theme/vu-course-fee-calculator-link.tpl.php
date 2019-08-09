<?php

/**
 * @file
 * Template file for Fee Calculator Link International block.
 */
?>

<section class="fee-calculator-link">
  <h3>Fee Calculator</h3>
  <p>Use the fee calculator to get an indicator of your course and unit fees.</p>
  <?php print t('<a class="btn btn-secondary ext" href="@url" role="button">Calculate my fees</a>', ['@url' => $link]); ?>
</section>
