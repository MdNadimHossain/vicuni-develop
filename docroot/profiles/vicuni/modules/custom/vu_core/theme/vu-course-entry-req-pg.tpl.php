<?php

/**
 * @file
 * Template file for Entry Requirements PG.
 */
?>
<?php if ($entry_requirements || $essential_requirements): ?>
  <div>
    <h3>Entry requirements</h3>
    <?php if($entry_requirements): ?>
      <p><?php print $entry_requirements; ?></p>
    <?php endif; ?>
    <?php if($essential_requirements): ?>
      <?php print $essential_requirements; ?>
    <?php endif; ?>
  </div>
<?php endif; ?>
