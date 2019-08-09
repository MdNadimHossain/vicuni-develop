<?php

/**
 * @file
 * Template file for pathways to this course block.
 */
?>
<?php if ($introText): ?>
<p>
  <?php print t('There are many ways you can start your education journey at VU.
  Pathways offer an easy transition between courses at different levels,
  so that you can start with a certificate and progress right through
  to postgraduate study.'); ?>
</p>
<?php endif; ?>
<?php if (count($pathways)): ?>
  <p>
    <?php print t('If you have completed any of the following course(s),
    you will be guaranteed a place in this course. In some cases you may
    receive credit for your previous study, reducing the time it takes to
    complete your course.'); ?>
  </p>
  <?php foreach ($pathways as $pathway): ?>
    <?php print theme('pathway', ['pathway' => $pathway]); ?>
  <?php endforeach; ?>
<?php endif; ?>
<?php if ($type !== 'Offshore'): ?>
  <p><?php print t('Find out more about <a href="@href">pathways and credits</a>.', ['@href' => '/pathways-to-vu']); ?></p>
<?php endif; ?>
