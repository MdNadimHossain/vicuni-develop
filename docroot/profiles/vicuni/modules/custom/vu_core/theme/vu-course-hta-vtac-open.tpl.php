<?php

/**
 * @file
 * Courses - How to Apply - VTAC open course.
 */
?>
<div class="hta-method-container <?php print (!$modal) ? $vtac_class : ''; ?>">
  <div class="hta-vtac">
    <?php if (!$modal): ?>
      <h3>Apply through VTAC</h3>
    <?php endif; ?>
    <p>You should apply through VTAC if you:
      <ul>
        <li>are applying for more than one course</li>
        <li>are completing Year 12 in 2018</li>
        <li>have an existing VTAC application to study in 2019.</li>
      </ul>
    </p>
    <?php if (empty($application_start_date)): ?>
      <?php print $vtac_codes; ?>
      <p>
        VTAC <?php print $due_date_method; ?> applications are due
        <b><?php print $application_end_date; ?></b>.
      </p>
      <a href="http://www.vtac.edu.au/" class="btn btn-secondary <?php print $modal ? 'btn-apply-vtac-modal' : '' ?>" role="button">Apply via VTAC</a>
    <?php else: ?>
      <?php print $vtac_codes; ?>
      <p>
        VTAC applications open
        <b><?php print $application_start_date; ?></b>.
      </p>
    <?php endif; ?>
    <?php if (!$modal): ?>
      <h3>Special Entry Access Scheme</h3>
      <p>
        You can apply for consideration of your life circumstances during the application process by submitting a <a href="http://www.vtac.edu.au/who/seas/applying.html">VTAC Special Entry Access Scheme (SEAS) application</a>.
      </p>
    <?php endif; ?>
  </div>
</div>
