<?php

/**
 * @file
 * Courses - How to Apply - Direct open course.
 */
?>
<div class="hta-method-container <?php print (!$modal) ? $direct_class : ''; ?>">
  <div class="hta-direct">
    <?php if (!$modal): ?>
      <h3><?php print $direct_title; ?></h3>
    <?php endif; ?>
    <?php if($vtac_open): ?>
      <p>You should apply direct to VU if you are:</p>
      <ul>
        <li>only applying for this course; and</li>
        <li>not completing Year 12.</li>
      </ul>
      <p>
        If you have already applied through VTAC you must not apply directly to VU.
      </p>
    <?php else: ?>
      Apply direct to VU using our admission centre submit applications for one or more courses, track and save your progress and upload additional information.
      <?php if ($is_vicpoly): ?>
        <?php if ($supplementary_date_info): ?>
          <div class="supplementary-date-info">
            <?php print $supplementary_date_info; ?>
          </div>
        <?php endif; ?>
      <?php endif; ?>
    <?php endif; ?>
    <?php if (empty($application_start_date)): ?>
      <?php if (!$is_vicpoly): ?>
        <p>
            Direct applications are due on <b><?php print $application_end_date; ?></b>
            <?php if (!is_null($intake_date)) : ?>
              for our next intake which starts on <b><?php print $intake_date ?></b>.
            <?php endif; ?>
        </p>
        <?php if ($supplementary_date_info): ?>
          <div class="supplementary-date-info">
            <?php print $supplementary_date_info; ?>
          </div>
        <?php endif; ?>
      <?php endif; ?>
      <?php if (!empty($register_button['label']) && $modal): ?>
        <a href="<?php print $register_button['link']; ?>" <?php print drupal_attributes($register_button['attributes']); ?>>
          <?php print $register_button['label']; ?>
        </a>
      <?php else: ?>
        <a href="<?php echo $direct_link ?>" class="btn btn-secondary <?php print $modal ? 'btn-apply-direct-modal' : '' ?>" role="button"><?php print $button_text; ?></a>
      <?php endif ?>
    <?php else: ?>
      <p>
        Direct applications open
        <b><?php print $application_start_date; ?></b>.
      </p>
      <?php if ($is_vu_online): ?>
        <a href="#goto-enquire-now" data-smoothscroll="1" class="btn btn-secondary <?php print $modal ? 'btn-register-interest' : '' ?>" role="button">Register your interest</a>
      <?php endif; ?>
    <?php endif; ?>
    <?php if (!$modal && !empty($vu_student)): ?>
      <?php print $vu_student; ?>
    <?php endif; ?>
    <?php if (!$modal && $after_apply): ?>
      <?php print $after_apply; ?>
    <?php endif; ?>
  </div>
</div>
