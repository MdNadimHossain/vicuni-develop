<?php

/**
 * @file
 * Template file for course switcher international info partial.
 */
?>
<div id="international-info-content">
  <?php echo t('You are considered an <strong>international student</strong> if you:'); ?>
  <ul>
    <li><?php echo t('do not fit any of the above criteria; and'); ?></li>
    <li><?php echo t('hold a temporary visa (or are seeking to apply for one).'); ?></li>
  </ul>

  <p><?php echo t('Visit the <a href="@href1">Department of Home Affairs</a> website for more information about studying in Australia on a student visa.', ['@href1' => 'https://immi.homeaffairs.gov.au/visas/getting-a-visa/visa-listing/student-500']); ?></p>
</div>
