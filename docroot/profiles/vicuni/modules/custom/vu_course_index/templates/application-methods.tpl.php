<?php
/**
 * @file
 * Template to display application methods on a course page.
 */

$supplementary_forms = array_map(
  'vu_course_index_supplementary_form_link',
  array_merge(
    $delivery->supplementaryForms(),
    $delivery->refereeReports()
  )
);

$direct_open_date = $delivery->openDate('direct');
$vtac_open_date = $delivery->openDate('vtac');
$post_bachelor = vu_courses_above_bachelors($course);
if ($international): ?>

  <?php if (vu_feature_switches_switch_state('courses-new-course-info') && $new_course): ?>
    <p>This course will be offered from <?php print $new_course ?> onwards.</p>
  <?php endif; ?>
  <p>International students can apply directly to Victoria University using our online application system, or apply through an education agent. </p>
  <a href="http://eaams.vu.edu.au/" class="btn btn-secondary" role="button">Direct online application</a>
  <a href="http://eaams.vu.edu.au/BrowseAgents.aspx" class="btn btn-secondary" role="button">Find an education agent</a>
  <br>

<?php else: ?>

  <?php if (vu_feature_switches_switch_state('courses-new-course-info') && $new_course && !($delivery->isOpen() || $direct_open_date || $vtac_open_date)): ?>
    <p>This course will be offered from <?php print $new_course ?> onwards. Apply for this course from August <?php print ($new_course - 1); ?>.</p>
    <p>
      <a href="#goto-enquire-now">Enquire now</a> and find out more about this course.
    </p>
  <?php elseif ($is_pgr):
    print theme('pgr-how-to-apply', ['contact' => FALSE]);
  elseif ($delivery->isOpen() || $direct_open_date || $vtac_open_date):
    /* Open */ ?>
    <?php if ($delivery->isTafe() && !($delivery->isOpen('vtac') || $vtac_open_date)): ?>
      <?php if ($direct_open_date && $delivery->hasOnlineApplication()): ?>
        <p>
          You can apply online direct to VU from
          <b><?php print date('j F Y', $direct_open_date) ?>.</b>
        </p>
      <?php else: ?>
        <p>
          Direct applications due
          <b><?php print date('j F Y', $delivery->isApprenticeship() ? $delivery->closingDate('app-train') : $delivery->closingDate('direct')) ?>.</b>
        </p>
      <?php endif; ?>
    <?php endif; ?>

    <?php if (count($supplementary_forms) > 1): ?>
      <p>
        All applicants must complete the following supplementary forms:
      <ul><?php foreach ($supplementary_forms as $link): ?>
          <li><?php print $link ?></li>
        <?php endforeach; ?></ul>
      </p>
    <?php elseif (count($supplementary_forms) == 1): ?>
      <p>
        All applicants must complete an <?php print current($supplementary_forms) ?>.
      </p>
    <?php endif ?>

    <p>
      Before you apply, consider whether you also wish to apply for:
      <ul>
        <li>
          Special admission: You can request special consideration be given to your application based on your individual situation.<br>
          Find out more
          <a href="/courses/how-to-apply/special-admission-programs">about special admission</a> or complete the
          <a href="/sites/default/files/student-connections/pdfs/A126-Direct-admission-special-consideration-application.pdf">Direct admissions special consideration application</a>
        </li>
        <li>
          Extra credit for past skills and study - known as Recognition for Prior Learning (RPL) or
          <a href="/study-with-us/your-study-options/pathways-credits/credit-for-skills-past-study">Skills recognition</a>.
        </li>
      </ul>
    </p>

    <h3>When you're ready:</h3>
    <?php ob_start(); ?>
    <?php if ($delivery->isOpen('vtac') || $vtac_open_date): ?>
      <?php if ($delivery->isOpen('direct') || $direct_open_date): ?>
        <p><strong>
            <?php if ($post_bachelor): ?>
              Applying to multiple institutions?
            <?php endif; ?>
          </strong></p>
      <?php endif; ?>

      <?php if ($delivery->isOpen('vtac') && $delivery->closingDate('vtac')): ?>
        <p>You must apply via VTAC if you are:
          <ul>
            <li>currently enrolled in Year 12 (or equivalent)<br /><strong>or</strong></li>
            <li>applying for more than one course</li>
          </ul>
        </p>
        <p>
          VTAC applications due
          <b><?php print date('j F Y', $delivery->closingDate('vtac')) ?></b>.
        </p>
        <a href="http://www.vtac.edu.au/" class="btn btn-secondary" role="button">Apply via VTAC</a>
      <?php elseif ($vtac_open_date): ?>
        <p>
          VTAC applications open
          <b><?php print date('j F Y', $vtac_open_date) ?></b>.
        </p>
      <?php endif; ?>
    <?php endif; ?>
    <?php $vtac_info = ob_get_clean(); ?>

    <?php ob_start(); ?>
    <?php if ($delivery->isOpen('direct') || $delivery->isOpen('app-train') || $direct_open_date): ?>
      <?php if ($delivery->isOpen('vtac') || $vtac_open_date): ?>
      <?php if (!$post_bachelor) : ?>
        <p>You can apply directly to VU if you:
          <ul>
            <li>are not currently enrolled in Year 12 (or equivalent), and</li>
            <li>are only applying for one course at VU, and</li>
            <li>have not already applied through VTAC<br /><strong>or</strong></li>
            <li>are a current VU student</li>
          </ul>
        </p>
      <?php else: ?>
        <p><strong>Only applying to VU?</strong></p>
      <?php endif; ?>
    <?php endif; ?>
      <?php if (($delivery->isOpen('direct') || $delivery->isOpen('app-train')) && $delivery->hasOnlineApplication()): ?>
      <p>
        You will need to create an account (or use your existing VU one).
      </p>
      <p>Direct applications due
        <b><?php print date('j F Y', $delivery->isApprenticeship() ? $delivery->closingDate('app-train') : $delivery->closingDate('direct')) ?>.</b>
      </p>
      <a href="<?php print vu_courses_apply_url($course_code, $delivery->isTafe()) ?>" class="btn btn-secondary" role="button">Apply direct to VU</a>
    <?php elseif ($delivery->hasOnlineApplication() && $direct_open_date): ?>
      <p>Direct applications open 
      <b><?php print date('j F Y', $direct_open_date) ?>.</b></p>
    <?php elseif (!$delivery->hasOnlineApplication()): ?>
      <p>Complete the
        <a href="/sites/default/files/student-connections/pdfs/A120-direct-entry-application.pdf">direct entry application form</a>.
      </p>
      <p>Direct applications due
        <b><?php print date('j F Y', $delivery->isApprenticeship() ? $delivery->closingDate('app-train') : $delivery->closingDate('direct')) ?>.</b>
      </p>
    <?php endif; ?>
    <?php endif; ?>
    <?php
    $direct_info = ob_get_clean();
    print $post_bachelor ? $direct_info . $vtac_info : $vtac_info . $direct_info;
    ?>

  <?php endif; /* Open */ ?>

<?php endif;
