<?php

/**
 * @file
 * Template for Unit assessment.
 */
?>
<?php if ($show_titles): ?>
  <h3>Melbourne campuses</h3>
  <p>Students studying under the VU Block Model.</p>
<?php endif; ?>
<?php print $assessment; ?>

<?php if ($show_titles): ?>
  <h3>Other locations</h3>
<?php endif; ?>
<?php print $assessment_offshore; ?>
