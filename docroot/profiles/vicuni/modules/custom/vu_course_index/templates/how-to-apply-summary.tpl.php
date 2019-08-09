<?php

/**
 * @file
 * Template for how to apply summary on upper left of course page.
 */

$is_direct = $delivery->isOpen('direct');
// @TODO: kill this with fire - hack
$direct_open_date = $delivery->openDate('direct');

$is_vtac = $delivery->isOpen('vtac');
$vtac_open_date = $delivery->openDate('vtac');
$is_apprenticeship = $delivery->isApprenticeship();
$is_online = $delivery->hasOnlineApplication();

$study_area_link = t('<a href="@href">other courses</a>', ['@href' => '/courses/browse-for-courses']);
if (!empty($course->field_study_topic_area)) {
  $course_wrapper = entity_metadata_wrapper('node', $course);
  $study_area = $course_wrapper->field_study_topic_area[0]->value();

  $study_area_title = $study_area->title;
  $study_area_path = drupal_get_path_alias('node/' . $study_area->nid);
  $study_area_link = t('other <a href="@href">@title</a> courses', [
    '@href' => $study_area_path,
    '@title' => $study_area_title,
  ]);
}
$post_bachelor = vu_courses_above_bachelors($course);

if (!vu_feature_switches_switch_state('courses-new-course-info')) {
  $new_course = FALSE;
}
?>

<?php if ($is_pgr && !$new_course) :
  /* PGR SHOW AS CLOSED BECAUSE THEY */
  /* AREN'T IN THE COURSE INDEX */
  echo theme('pgr-how-to-apply');

elseif ($delivery->isClosed() && $delivery->expressionOfInterest()): ?>
  <p>VU is currently taking expressions of interest for this course.
    Many of our courses have flexible start dates and are dependent on demand.</p>
  <p>Please
    <a href="#goto-enquire-now">send us an enquiry</a> to be notified of the next available start date.
  </p>
  ￼<?php elseif ($delivery->isClosed() && !($direct_open_date || $vtac_open_date)): ?>

  <?php if (!$new_course): ?>
    <p>Applications for this course are not being taken at this time.</p>
    <p>Browse our <?php echo $study_area_link; ?> or
      <a href="#goto-enquire-now">send us an enquiry</a> to be notified of updates relating to this course.
    </p>
  <?php else: ?>

    <!-- NEW COURSE ENTRY -->
    <div class="badge-new-course badge-new-course-<?php echo $new_course; ?>">Entry in <?php echo $new_course ?></div>

    <p>This course will be offered from <?php echo $new_course ?> onwards. Apply for this course from August <?php echo ($new_course - 1); ?>.</p>
    <p>
      <a href="#goto-enquire-now">Enquire now</a> and find out more about this course.
    </p>
  <?php endif; ?>
  <?php /* @TODO: register your interest */ ?>

<?php else: /* APPLICATIONS ARE OPEN! */ ?>
  <!-- MIDYEAR -->
  <?php if (vu_feature_switches_switch_state('courses-midyear-info') && $midyear): ?>
    <div class="badge-midyear">Open for mid-year entry</div>
  <?php endif; ?>
  <!-- END MIDYEAR -->

  <!-- NEW COURSE ENTRY -->
  <?php if ($new_course): ?>
    <div class="badge-new-course badge-new-course-<?php echo $new_course; ?>">Entry in <?php echo $new_course ?></div>
  <?php endif; ?>
  <!-- END NEW COURSE ENTRY -->
  <?php ob_start(); ?>
  <!-- VTAC -->
  <?php if ($is_vtac || $vtac_open_date): ?>
      <?php if ($is_direct || $direct_open_date): ?>
        <?php if ($post_bachelor): ?>
          <h3>Applying to multiple institutions?</h3>
        <?php endif; ?>
      <?php endif; ?>
    <!-- VTAC CLOSING DATE -->
    <?php if ($is_vtac && $delivery->closingDate('vtac')): ?>
      <p>You must apply via VTAC if you are:
        <ul>
          <li>currently enrolled in Year 12 (or equivalent)<br /><strong>or</strong></li>
          <li>applying for more than one course</li>
        </ul>
      </p>
      <p>
        VTAC applications due
        <b><?php echo date('j F Y', $delivery->closingDate('vtac')) ?></b>.
      </p>
      <a href="http://www.vtac.edu.au/" class="btn btn-secondary" role="button">Apply via VTAC</a>
    <?php elseif ($vtac_open_date): ?>
      <p>
        VTAC applications open
        <b><?php echo date('j F Y', $vtac_open_date) ?></b>.
      </p>
    <?php endif; ?>
    <!-- END VTAC CLOSING DATE -->
  <?php endif; ?>
  <!-- END VTAC -->
  <?php $vtac_info = ob_get_clean(); ?>

  <?php ob_start(); ?>
  <!-- DIRECT/APP -->
  <?php if ($is_direct || $direct_open_date || $is_apprenticeship):
    if ($is_vtac || $vtac_open_date):
      if (!$post_bachelor): ?>
        <p>You can apply directly to VU if you:
          <ul>
            <li>are not currently enrolled in Year 12 (or equivalent), and</li>
            <li>are only applying for one course at VU, and</li>
            <li>have not already applied through VTAC<br /><strong>or</strong></li>
            <li>are a current VU student</li>
          </ul>
        </p>
      <?php else: ?>
        <h3>Only applying to VU?</h3>
      <?php endif; ?>
    <?php endif; ?>
    <p>
      <!-- DIRECT CLOSING DATE -->
      <?php if (($is_direct && !$is_apprenticeship) || ($direct_open_date && !$is_online && !$is_apprenticeship)): ?>

        Direct applications due
        <b><?php echo date('j F Y', $delivery->closingDate('direct')) ?>.</b>
      <?php endif; ?>
      <!-- END DIRECT CLOSING DATE -->

      <!-- APPRENTICESHIP CLOSING DATE -->
      <?php if ($is_apprenticeship): ?>
        Direct applications due
        <b><?php echo date('j F Y', $delivery->closingDate('app-train')) ?>.</b>
      <?php endif; ?>
      <!-- APPRENTICESHIP CLOSING DATE -->
    </p>
    <p>
      <!-- DIRECT ANCHOR LINK -->
      <?php if (!$is_online): ?>
        <a href="#apply-now">Apply direct to VU</a>.
      <?php endif; ?>
      <!-- END DIRECT ANCHOR LINK -->

    </p>
    <!-- DIRECT ONLINE -->
    <?php if (($is_direct || $is_apprenticeship) && $is_online): ?>
    <a href="<?php echo vu_courses_apply_url($course_code, $delivery->isTafe()); ?>" class="btn btn-secondary" role="button">Apply direct to VU</a>
    <?php echo $specialisation_text ?>

  <?php elseif ($direct_open_date && $is_online): ?>
    <p>Direct applications open 
    <b><?php echo date('j F Y', $direct_open_date) ?>.</b></p>
  <?php endif; ?>
    <!-- END DIRECT ONLINE -->
    <?php if ($is_apprenticeship): ?>
    <p>
      Learn more about
      <a href="https://www.vupolytechnic.edu.au/apprenticeships-traineeships">apprenticeships at VU</a>.
    </p>
    <p>
      <a href="#goto-enquire-now">Contact us</a> if you have questions about this course.
    </p>
  <?php endif; ?>
  <?php endif; ?>
  <!-- END DIRECT -->
  <?php
  $direct_info = ob_get_clean();
  echo $post_bachelor ? $direct_info . $vtac_info : $vtac_info . $direct_info;
endif;
