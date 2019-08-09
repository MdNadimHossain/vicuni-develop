<?php

/**
 * @file
 * Template file for Researcher key details.
 */
?>
<?php if (count($content)): ?>
  <h3>Areas of expertise</h3>
  <ul>
    <?php foreach ($content as $item): ?>
      <li><?php print $item; ?></li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
