<?php

/**
 * @file
 * Unit page template.
 *
 * @ingroup vu
 * @ingroup templates
 */

$college = preg_replace('/<\\/?div[^>]*>/i', '', render($content['field_college']));
$more_info = empty($college) ?
  t('Contact your course coordinator to see if you are able to take the elective unit.') :
  t('For more info contact the !college.', ['!college' => $college]);
?>
<article id="node-<?php print $node->nid; ?>" class="content unit units clear-block node<?php print !$status ? ' node-unpublished' : ''; ?>">

  <!-- Introduction / Course essentials. -->
  <div class="section" id="overview">
    <div class="container">
      <div class="row first">

        <div class="col-md-7">

          <!-- Introduction -->
          <?php print render($ds_content) ?>

          <!-- Unit details -->
          <div id="unit-details" class="clearfix">
            <h3><?php print t('Unit details'); ?></h3>

            <?php
              // This code merges in imported locations that aren't able to be
              // stored in entityreference type field. This can't live in the
              // precprocess hook becuase it merges pre and post process field
              // items.
              // Deal with case that only special locations exist for this node.
              if (!isset($content['field_locations']) && !empty($special_locations)) {
                $content['field_locations'] = $field_locations_base_render_array;
              }
              // Merge preprocessed special locations into the regular locations
              // entityreference field display.
              if (!empty($special_locations)) {
                $content['field_locations']['#items'] = array_merge($content['field_locations']['#items'], $special_locations);
                $content['field_locations'] = array_merge($content['field_locations'], $special_locations);
              }
            ?>
            <?php if (isset($content['field_locations'])): ?>
              <!-- Locations -->
              <div class="unit-detail-item col-sm-12">
                <div class="course-essentials__item__label">
                  <span class="fa-stack fa-fw">
                    <i class="fa fa-circle fa-stack-2x"></i>
                    <i class="fa fa-map-marker fa-stack-1x fa-inverse"></i>
                  </span>
                  <?php print t('Location:'); ?>
                </div>
                <div class="course-essentials__item__value">
                  <?php print render($content['field_locations']); ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($unit_level)): ?>
              <!-- Study level -->
              <div class="unit-detail-item col-sm-12">
                <div class="course-essentials__item__label">
                  <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-line-chart fa-stack-1x fa-inverse"></i></span><?php print t('Study level:'); ?>
                </div>
                <div class="course-essentials__item__value">
                  <?php print $unit_level; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (isset($content['field_credit_points'])): ?>
              <!-- Credit points -->
              <div class="unit-detail-item col-sm-12">
                <div class="course-essentials__item__label">
                  <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-clock-o fa-stack-1x fa-inverse"></i></span>
                  <?php print t('Credit points:'); ?>
                  <i class="fa fa-question-circle" data-toggle="tooltip" data-placement="right" title="One credit point is usually equivalent to one hour of study per week."></i>
                </div>
                <div class="course-essentials__item__value">
                  <?php print render($content['field_credit_points']); ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (isset($content['field_unit_code'])): ?>
              <!-- Unit code -->
              <div class="unit-detail-item col-sm-12">
                <div class="course-essentials__item__label">
                  <span class="fa-stack fa-fw">
                    <i class="fa fa-circle fa-stack-2x"></i>
                    <i class="fa fa-tag fa-stack-1x fa-inverse"></i>
                  </span>
                  <?php print t('Unit code:'); ?>
                </div>
                <div class="course-essentials__item__value">
                  <?php print render($content['field_unit_code']); ?>
                </div>
              </div>
            <?php endif; ?>

          </div>

          <?php if ($field_prerequisites): ?>
            <!-- Prerequisites -->
            <h3><?php print t('Prerequisites'); ?></h3>
            <?php print render($content['field_prerequisites']); ?>
          <?php endif; ?>

          <?php if ($field_co_requisites): ?>
            <!-- Co-requisites -->
            <h3><?php print t('Co-requisites'); ?></h3>
            <?php print render($content['field_co_requisites']); ?>
          <?php endif; ?>
        </div>

        <?php if (!empty($overview_rhs)) : ?>
          <div class="col-md-push-1 col-md-4">
            <?php print $overview_rhs ?>
          </div>
        <?php endif ?>

      </div>
    </div>
  </div>

  <?php if (!empty(trim(strip_tags($learning)))) : ?>
    <!-- Learning Outcomes. -->
    <div class="section" id="learning-outcomes">
      <h2 class="victory-title__stripe" id="goto-learning-outcomes"><?php print t('Learning Outcomes') ?></h2>
      <div class="container">
        <div class="row">

          <div class="col-md-7">
            <?php print $learning ?>
          </div>

        </div>
      </div>
    </div>
  <?php endif ?>

  <?php if (!empty($assessment)) : ?>
    <!--Assessment. -->
    <div class="section" id="assessment">
      <h2 class="victory-title__stripe" id="goto-assessment"><?php print t('Assessment') ?></h2>
      <div class="container">
        <div class="row">

          <div class="col-md-7">
            <?php print $assessment ?>
          </div>

        </div>
      </div>
    </div>
  <?php endif ?>

  <?php if (!empty(trim(strip_tags($reading)))) : ?>
    <!-- Required reading. -->
    <div class="section" id="required-reading">
      <h2 class="victory-title__stripe" id="goto-required-reading"><?php print t('Required reading') ?></h2>
      <div class="container">
        <div class="row">

          <div class="col-md-7">
            <?php print $reading ?>
          </div>

        </div>
      </div>
    </div>
  <?php endif ?>

  <!-- Where to next section. -->
  <div class="section" id="where-to-next">
    <h2 class="victory-title__stripe" id="goto-where-to-next"><?php print t('Where to next?') ?></h2>
    <div class="container">
      <div class="row">
        <div class="col-md-7">

          <?php if (!empty(trim(strip_tags($courses_this_unit_belongs_to))) || !empty(trim(strip_tags($specialisations_this_unit_belongs_to)))): ?>
            <h3><?php print t('As part of a course'); ?></h3>

            <?php if (!empty(trim(strip_tags($courses_this_unit_belongs_to)))) : ?>
              <p><?php print t('This unit is studied as part of the following courses. Refer to the course page for information on how to apply for the course.'); ?></p>
              <?php print $courses_this_unit_belongs_to; ?>
            <?php endif; ?>

            <?php if (!empty(trim(strip_tags($specialisations_this_unit_belongs_to)))): ?>
              <p><?php print t('You can choose to study this unit as part of the following courses. Refer to the course page for information on how to structure your course to include this unit.'); ?></p>
              <?php print $specialisations_this_unit_belongs_to; ?>
            <?php endif; ?>
          <?php endif; ?>

          <?php if ($study_single_unit): ?>
            <div class="study-single-unit">
              <h3><?php print $study_single_unit['heading']; ?></h3>
              <?php print render($study_single_unit['content']); ?>
            </div>
          <?php endif; ?>

          <p>
            <small><?php print t('VU takes care to ensure the accuracy of this unit information, but reserves the right to change or withdraw courses offered at any time. Please check that unit information is current with the <a href="/contact-us">Student Contact Centre</a>.'); ?></small>
          </p>

        </div>
      </div>
    </div>
  </div>

</article>
