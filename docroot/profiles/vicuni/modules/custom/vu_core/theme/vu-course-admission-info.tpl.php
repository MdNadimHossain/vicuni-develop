<?php

/**
 * @file
 * Admission information.
 */
if (!empty($admission_information)): ?>
  <section id="admission-information">
    <?php if ($title): ?>
      <h2><?php print $title; ?></h2>
    <?php endif ?>

    <?php print $admission_information; ?>

  </section>
<?php endif; ?>
