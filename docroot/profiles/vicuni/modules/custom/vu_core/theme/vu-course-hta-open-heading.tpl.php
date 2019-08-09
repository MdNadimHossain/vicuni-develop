<?php

/**
 * @file
 * Template for HTA - open - heading block on course pages.
 */
?>
<?php if ($is_vu_online): ?>
  <?php if ($title): ?>
    <h4><?php print $title; ?></h4>
  <?php endif; ?>
<?php else: ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
