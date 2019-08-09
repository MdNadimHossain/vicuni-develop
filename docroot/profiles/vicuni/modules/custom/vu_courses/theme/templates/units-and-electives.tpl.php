<?php

/**
 * @file
 * Structure template.
 */
if (!empty($structure) || !empty($prerequisite_units)): ?>
  <section id="units-and-electives">
    <?php if ($title): ?>
      <h2><?php print check_plain($title); ?></h2>
    <?php endif ?>
    <?php if (!empty($structure)) : ?>
      <?php print $structure ?>
    <?php endif; ?>
    <?php if (!empty($prerequisite_units)) : ?>
      <?php print $prerequisite_units ?>
    <?php endif ?>
  </section>
<?php endif ?>
