<?php

/**
 * @file
 * Template for a Bootstrap - Stacked - 3 3 3 3 panel layout.
 *
 * This template provides a very simple "Bootstrap - Stacked - 3 3 3 3" panel
 * display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout.
 */
?>
<div class="container">
  <?php if ($content['top']): ?>
  <div class="row top">
    <div class="col col-sm-12">
      <?php print $content['top']; ?>
    </div>
  </div>
  <?php endif; ?>
  <div class="row middle">
    <div class="col col-sm-3">
      <?php print $content['middle_1']; ?>
    </div>
    <div class="col col-sm-3">
      <?php print $content['middle_2']; ?>
    </div>
    <div class="col col-sm-3">
      <?php print $content['middle_3']; ?>
    </div>
    <div class="col col-sm-3">
      <?php print $content['middle_4']; ?>
    </div>
  </div>
  <?php if ($content['bottom']): ?>
  <div class="row bottom">
    <div class="col col-sm-12">
      <?php print $content['bottom']; ?>
    </div>
  </div>
  <?php endif; ?>
</div>
