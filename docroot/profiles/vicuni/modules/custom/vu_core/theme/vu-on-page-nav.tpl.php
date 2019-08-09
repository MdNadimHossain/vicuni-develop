<?php

/**
 * @file
 * Template file for 'On page navigation' block.
 */
?>
<?php if (!empty($items)): ?>
  <ul>
  <?php foreach ($items as $fragment => $title): ?>
    <li><a href="<?php echo $fragment ?>" data-smoothscroll data-tracking="FindOnPage"><?php echo $title ?></a></li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>
