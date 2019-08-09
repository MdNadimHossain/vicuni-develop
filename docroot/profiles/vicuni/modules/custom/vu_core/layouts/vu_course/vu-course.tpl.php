<?php

/**
 * @file
 * Course page template.
 */
?>
<article id="node-<?php print $node->nid; ?>" class="content course courses clear-block node<?php print !$status ? ' node-unpublished' : ''; ?>">

  <!-- Introduction / Course essentials. -->
  <div class="section" id="overview">
    <h2 class="victory-title__stripe">Overview</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-7">
          <?php if (!empty($secondary_tasks)): ?>
            <?php print $secondary_tasks; ?>
          <?php endif; ?>

          <?php print $course_introduction; ?>

          <?php print $introduction; ?>
          <?php if ($description) : ?>
            <section id="description">
              <?php print $description; ?>
            </section>
          <?php endif; ?>
        </div>

        <div class="col-md-push-1 col-md-4">

          <?php if (!empty($overview_right)) : ?>
            <?php print $overview_right ?>
          <?php endif ?>

          <?php if (!empty($associated_courses)) : ?>
            <?php print $associated_courses ?>
          <?php endif ?>

          <?php if (!empty($tafe_resources_block)) : ?>
            <?php print $tafe_resources_block ?>
          <?php endif ?>

          <!-- Domestic promotional tiles. -->
          <?php if (!$international) : ?>
            <?php print theme('course-tile', ['feature' => 'midyear-course-tile']) ?>
            <?php print theme('course-tile', ['feature' => 'open-day']) ?>
            <?php print theme('course-tile', ['feature' => 'preference-course-tile']) ?>
            <?php print theme('course-tile', ['feature' => 'csa-course-tile']) ?>
            <?php print theme('course-tile', ['feature' => 'startnow-course-tile']) ?>

            <?php if ($course_level != 'postgrad') : ?>
              <?php print theme('course-tile', ['feature' => 'cop-course-tile']) ?>
            <?php else : ?>
              <?php print theme('course-tile', ['feature' => 'pg-course-tile']) ?>
            <?php endif ?>
          <?php endif ?>

          <?php if (!empty($overview_right_lower_middle)): ?>
            <?php print $overview_right_lower_middle; ?>
          <?php endif; ?>

        </div>
      </div>
    </div>
  </div>

  <!-- Careers. -->
  <?php if (!empty($careers) || !empty($careers_right)): ?>
    <div class="section" id="careers">
      <h2 class="victory-title__stripe" data-short-title="Careers"><?php print _vu_courses_extract_first_h2($careers) ?: t('Careers') ?></h2>
      <div class="container">
        <div class="row h2-heading-dotted">
          <div class="col-md-7">
            <?php print $careers; ?>
          </div>
          <div class="col-md-push-1 col-md-4 right-sidebar">
            <?php print $careers_right; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <!-- Learning outcomes section for courses with nothing in units_and_electives. -->
  <?php if (!empty($course_partials['course_objectives']) && empty($course_partials['units_and_electives'])): ?>
    <div class="section">
      <h2 class="victory-title__stripe"><?php print t('Learning outcomes') ?></h2>
      <div class="container">
        <div class="row">
          <div class="col-md-7">
            <?php print $course_partials['course_objectives']; ?>
          </div>
          <div class="col-md-push-1 col-md-4 right-sidebar"></div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <!-- Course contents / structure. -->
  <?php if (!empty($course_partials['units_and_electives'])): ?>
    <div class="section" id="course-structure">
      <h2 class="victory-title__stripe"><?php print $short_course ? t('Course contents') : t('Course structure') ?></h2>
      <div class="container">
        <div class="row course-structure">
          <div class="col-md-7">
            <?php if (!empty($completion_rules)): ?>
              <div class="completion-rules">
                <?php print render($completion_rules); ?>
              </div>
            <?php endif; ?>
            <?php
              print theme('vu_accordion', [
                'name' => 'accordion-course-structure',
                'title' => t('Course structure and units'),
                'content' => $course_partials['units_and_electives'],
              ]);
              if ($course_level === 'undergrad' && !($aqf === VU_CBS_AQF_ASSOC_DEGREE || $aqf === VU_CBS_AQF_BACHE_HON_DEGREE_SA)) {
                print theme('vu_accordion', [
                  'name' => 'accordion-fym-info',
                  'title' => t('Achieve more with the VU Block Model'),
                  'content' => $first_year_model_info,
                ]);
              }
              if (!empty($course_partials['course_objectives'])) {
                print theme('vu_accordion', [
                  'name' => 'accordion-course-objectives',
                  'title' => t('Learning outcomes'),
                  'content' => $course_partials['course_objectives'],
                ]);
              }
            ?>
          </div>

          <div class="col-md-push-1 col-md-4">
            <?php if (!$short_course): ?>
              <section id="whats-a-unit" class="course-details-box">
                <h3><?php print t("What's a unit?"); ?></h3>
                <p><?php print t("A unit or 'subject' is the actual class you'll attend in the process of completing a course."); ?></p>
                <p><?php print t("Most courses have a mixture of compulsory 'core' units that you need to take and optional elective units that you can choose to take based on your area of interest, expertise or experience."); ?></p>
              </section>

              <?php if (!$tafe_course): ?>
                <section>
                  <h3><?php print t('Credits'); ?></h3>
                  <p><?php print t('Each unit is worth a set amount of study credits based on the amount of time you study. Generally, 1 credit is equal to 1 hour of study per week.'); ?></p>
                </section>
              <?php endif; ?>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($fees_scholarships)): ?>
    <!-- Fees and scholarships. -->
    <div class="section">
      <h2 class="victory-title__stripe"><?php print _vu_courses_extract_first_h2($fees_scholarships) ?: t('Fees & scholarships') ?></h2>
      <div class="container">
        <div class="row">
          <div class="col-md-7">
            <?php print $fees_scholarships; ?>
          </div>
          <div class="col-md-push-1 col-md-4 right-sidebar">
            <?php if (!empty($fees_scholarships_right)): ?>
              <?php print $fees_scholarships_right; ?>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <!-- Admission and pathways. -->
  <div class="section">
    <h2 class="victory-title__stripe" id="admission"><?php print $admission_pathways_title; ?></h2>
    <div class="container">
      <div class="row">
        <div class="col-md-7">
          <?php print $admission_pathways; ?>
        </div>
        <div class="col-md-push-1 col-md-4 right-sidebar">
          <?php if (!empty($admission_pathways_right)): ?>
            <?php print $admission_pathways_right; ?>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>

  <!-- Pathways and Credits. -->
  <?php if (!empty($pathways_credits)): ?>
    <div class="section">
      <h2 class="victory-title__stripe" id="pathways"><?php print t('Pathways & credits'); ?></h2>
      <div class="container">
        <div class="row">
          <div class="col-md-7">
            <?php print $pathways_credits; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($how_to_apply): ?>
    <!-- How to apply. -->
    <div class="section clearfix" id="apply-now">
      <?php print $how_to_apply ?>
    </div>
  <?php endif; ?>

  <!-- Enquire now. -->
  <?php if (!empty($course_partials['enquire_now'])) : ?>
    <div class="section" id="enquire-now">
      <h2 class="victory-title__stripe"><?php print _vu_courses_extract_first_h2($course_partials['enquire_now']) ?: t('Enquire now') ?></h2>
      <div class="container">
        <?php print $course_partials['enquire_now'] ?>
      </div>
    </div>
  <?php endif ?>

  <?php if ($bottom) : ?>
    <div class="container container__bottom">
      <?php print $bottom ?>
    </div>
  <?php endif ?>

</article>
