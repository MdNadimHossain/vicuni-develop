<?php

/**
 * @file
 * Template file for ATAR SE requirements block.
 */
?>
<h4>Admission criteria</h4>
<?php if (!empty($se_requirements)): ?>
  <p><?php print $se_requirements; ?></p>
<?php else: ?>
  <p>Find out if you meet the <a href="/study-at-vu/how-to-apply/admissions-at-vu">admission criteria for a bachelor degree</a> at VU.</p>
<?php endif; ?>
