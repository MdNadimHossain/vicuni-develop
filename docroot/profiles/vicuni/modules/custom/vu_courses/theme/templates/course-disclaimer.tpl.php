<?php

/**
 * @file
 * Course disclaimer template.
 */
?>
<div class="row">
  <div class="col-md-7">
    <div class="disclaimer">
      <?php if ($is_tafe): ?>
        <p><?php echo t('Please note that if changes to this course occur, VU will notify students as soon as possible.'); ?></p>
      <?php endif ?>
      <p>
        <?php echo t('At Victoria University, we make every reasonable effort to make sure the information displayed online about our courses is accurate and complete. We continually look to provide innovative courses. Those courses are shaped by a number of things including your feedback and changes in Government funding arrangements.  As a result there may be changes to the courses we deliver and fees charged. We will update the website regularly to reflect any changes.'); ?>
      </p>
      <p>
        <?php echo t('Information about course fees, articulation and credit transfer, recognition of prior learning, admission and enrolment procedures, examinations, and services available to students can be accessed on the University’s website or by contacting the University directly on +61 3 9919 6100.'); ?>
      </p>
    </div>
  </div>
</div>
