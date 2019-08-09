<?php

/**
 * @file
 * Careers template.
 */
if (!empty($careers)): ?>
  <section id="careers">
    <?php if ($title): ?>
      <h2><?php echo check_plain($title) ?></h2>
    <?php endif ?>

    <?php echo $careers ?>
  </section>
<?php endif ?>
