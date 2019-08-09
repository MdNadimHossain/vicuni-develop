<?php

/**
 * @file
 * Template file for ATAR Adjustment block.
 */
?>

<?php if (!empty($text)): ?>
  <strong class="label-above">Application due dates:</strong>
  <div class="off-campus-text">
    <div class="apply-block__message">
      <?php print $text; ?>
      <?php if (!is_null($intake_date)) : ?>
        for our next intake which starts on <b><?php print $intake_date ?></b>.
      <?php endif; ?>
    </div>
    <?php if (!empty($sup_text)): ?>
      <?php print $sup_text; ?>
    <?php endif; ?>
  </div>
<?php endif; ?>
