<?php

/**
 * @file
 * Template for menu item section within Main Menu and level 2 depth.
 *
 * This menu item is a parent menu item prepended to a list of children.
 */
?>

<li <?php print drupal_attributes($attributes); ?>>
  <a href="<?php print url($href); ?>" class="collapsible">
    <div class="inner collapsible js-use-height">
      <h2 class="title"><?php print $title; ?> overview</h2>
      <?php if ($summary) : ?>
        <span class="summary"><?php print $summary; ?></span>
      <?php endif; ?>
      <span class="button">Find out more</span>
    </div>
  </a>
</li>
