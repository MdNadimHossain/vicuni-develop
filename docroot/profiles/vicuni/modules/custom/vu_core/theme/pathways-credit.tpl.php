<?php

/**
 * @file
 * Template file for pathways credit block.
 */
?>
<?php if (!$is_ve) : ?>
  <p>
    <?php print t('If you have completed study with another university or institution and believe you are eligible to receive credit for skills and past study, you can
    <a href="@href">apply for advanced standing</a>.', ['@href' => '/pathways-to-vu/credit-for-skills-past-study/higher-education-students']); ?>
  </p>
  <p>
    <?php print t('Applications for advanced standing can be made after a discussion with your course coordinator or academic adviser.'); ?>
  </p>
<?php else : ?>
  <p><?php print t('You may be able to complete your qualification sooner through formal recognition of your existing skills. <a href="@href">This is known as Recognition of Prior Learning (RPL)</a>.', ['@href' => '/pathways-to-vu/credit-for-skills-past-study/tafe-students']); ?></p>
  <p><?php print t('To receive RPL, we assess your previous work, education and life experiences against recognised qualifications. Applications for RPL can be made prior to enrolling.'); ?></p>
  <p><?php print t('Call us on <strong>1300 TAFE VP (1300 823 387)</strong> to discuss RPL options with the course manager.'); ?></p>
<?php endif ?>
