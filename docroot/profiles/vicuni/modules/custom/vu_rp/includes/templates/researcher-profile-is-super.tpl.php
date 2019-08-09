<?php

/**
 * @file
 * Template file for supervise and media queries flags.
 */
?>
<?php if ($is_supervising): ?>
  <div class="supervise-higher">
    <p>Available to supervise research students</p>
  </div>
<?php else : ?>
  <div class="supervise-no-higher">
    <p>Not available to supervise research students</p>
  </div>
<?php endif ?>
<?php if ($is_media): ?>
  <div class="media-higher">
    <p>Available for media queries</p>
  </div>
<?php else : ?>
  <div class="media-no-higher">
    <p>Not available for media queries</p>
  </div>
<?php endif ?>
