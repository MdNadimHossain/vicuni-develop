<?php

/**
 * @file
 * Template file for Qualifications.
 */
?>
<?php if (!empty($content)): ?>
  <ul>
    <?php foreach ($content as $link): ?>
      <li><?php print $link['value']; ?></li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
