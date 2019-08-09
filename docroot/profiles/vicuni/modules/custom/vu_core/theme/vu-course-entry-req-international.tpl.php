<?php

/**
 * @file
 * Template file for Entry Requirements International.
 */
?>
<div>
  <h3>Entry requirements</h3>
  <?php if($entry_requirements): ?>
    <p><?php print $entry_requirements; ?></p>
  <?php endif; ?>
  <?php if($essential_requirements): ?>
    <?php print $essential_requirements; ?>
  <?php endif; ?>
  <?php if ($international_lang_requirements): ?>
    <?php print $international_lang_requirements ?>
  <?php else: ?>
    <p>Find out if you meet the <a href="/courses/how-to-apply/international-applications/entry-requirements">entry requirements</a>, including English language and academic requirements.</p>
  <?php endif; ?>
</div>
