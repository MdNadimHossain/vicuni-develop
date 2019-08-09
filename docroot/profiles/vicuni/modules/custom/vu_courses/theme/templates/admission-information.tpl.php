<?php

/**
 * @file
 * Admission information.
 */
if (!empty($admission_information)): ?>
  <section id="admission-information">
    <?php if ($title): ?>
      <h2><?php echo check_plain($title) ?></h2>
    <?php endif ?>

    <?php echo filter_xss_admin($admission_information); ?>

    <?php if (!empty($international_lang_requirements)): ?>
      <h3><?php print t('English language requirements'); ?></h3>
      <?php echo filter_xss_admin($international_lang_requirements); ?>
    <?php endif; ?>

  </section>
<?php endif; ?>
