<?php

/**
 * @file
 * Template for a Bootstrap 12 panel layout.
 *
 * This template provides a very simple "Bootstrap 12" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['middle']: The only panel in the layout.
 */
?>
<div class="container">
  <div class="row">
    <div class="col-sm-12">
      <div class="row">
        <?php print $content['middle']; ?>
      </div>
    </div>
  </div>
</div>
