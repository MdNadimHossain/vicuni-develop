<?php
/**
 * @file
 * Template for how to apply section near bottom of course pages.
 */

$wrapper_class = 'how-to-apply';
if ($short_course && !$delivery->hasOnlineApplication()):
  $wrapper_class .= ' short-course';
endif;

$heading_text = sprintf('How to %s for this course',
  $short_course ? 'register' : 'apply');

$header_id = $short_course ? '' : 'id="apply-now"';

$edited_how_to_apply = '';
if (0 < strlen(trim(strip_tags($how_to_apply)))):
  $edited_how_to_apply = vu_listify($how_to_apply);
endif;

$is_online = $delivery->hasOnlineApplication();
?><!-- how to apply -->
<div id="apply" class="<?php echo $wrapper_class ?>">
  <?php if ($delivery->isOpen()) : ?>
    <h2 <?php echo $header_id; ?> ><?php echo $heading_text ?></h2>
  <?php endif; ?>
  <?php if ($delivery->isTafe()): ?>
    <p>Prior to enrolment, all applicants will be required to complete a literacy and numeracy assessment to assist with determining eligibility and to identify learning support needs.</p>
  <?php endif; ?>
  <?php if (!$short_course || $is_online) : ?>
    <?php if (!$international) : // i.e. is local ?>
      <?php echo $application_methods; ?>
      <?php
      if (($delivery->isClosed() && $delivery->expressionOfInterest())) :
        ?>
        <p>VU is currently taking expressions of interest to commence this course.
          Many of our courses have flexible start dates dependent on demand.
          Please submit the form below to be notified of the next available commencement.</p>
        <?php
      endif; ?>
    <?php else : // Is international. ?>
      <?php echo $application_methods; ?>
      <br/>
      <p>If you have questions about your application, you can:</p>
      <ul>
        <li>speak to a staff member. Phone +61 3 9919 1164 and follow the prompts</li>
        <li>send an email to
          <a href="mailto:intapps@vu.edu.au">intapps@vu.edu.au</a>
        <li>
          <a href="/international-students/make-an-enquiry">make an online enquiry</a>
        </li>
      </ul>
      <?php
    endif;
// Is international.
  else :
    // Is short course.
    if (!empty($how_to_apply)) : echo $how_to_apply;
    else : ?>
      <p><strong>Phone:</strong> +61 3 9919 6100</p>
      <?php
    endif;
  endif; ?>
</div>
