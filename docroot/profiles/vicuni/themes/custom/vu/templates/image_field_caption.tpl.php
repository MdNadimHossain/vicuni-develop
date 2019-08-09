<?php

/**
 * @file
 * Template for image with caption.
 *
 * Available variables:
 * - $image: Image HTML rendered by Drupal.
 * - $caption: Image field caption string.
 */
?>
<figure>
  <?php print $image; ?>
  <figcaption><?php print $caption; ?></figcaption>
</figure>
