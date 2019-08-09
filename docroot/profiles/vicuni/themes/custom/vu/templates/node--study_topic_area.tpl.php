<?php

/**
 * @file
 * Default theme implementation to display a node.
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="row first-row">
    <div class="col-md-8 left-column">
      <?php if (empty($is_international_audience)): ?>
        <?php print render($content['field_introduction_teaser']); ?>
        <div class="row study-topics-column-wrapper">
          <div class="col-md-8 browse-careers study-topics-column">
            <h2><?php print t('Careers'); ?></h2>
            <?php print render($content['field_career_editable']); ?>
          </div>
          <div class="col-md-4 browse-colleges study-topics-column">
            <h2><?php print t('Colleges'); ?></h2>
            <?php print render($content['field_study_topic_colleges']); ?>
          </div>
        </div>
      <?php else: ?>
        <?php print render($content['field_international_introduction']); ?>
        <div class="row study-topics-column-wrapper">
          <div class="col-md-8 browse-careers study-topics-column">
            <h2><?php print t('Careers'); ?></h2>
            <?php print render($content['field_international_career']); ?>
          </div>
          <div class="col-md-4 browse-colleges study-topics-column">
            <h2><?php print t('Colleges'); ?></h2>
            <?php print render($content['field_international_colleges']); ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-md-4 right-column">
      <?php if (!empty($jump_menu['content'])): ?>
        <?php print render($jump_menu); ?>
      <?php endif; ?>

      <?php print render($content['field_image']); ?>
    </div>
  </div>

  <div class="row">
    <div class="col-md-12">
      <?php if (!empty($course_study_level_block)): ?>
        <?php if (!empty($course_tabs)): ?>
          <?php print $course_tabs; ?>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  </div>

  <div class="row">
    <div class="col-md-8 left-column">
      <?php if (!empty($course_study_level_block)): ?>
        <?php print $course_study_level_block; ?>
      <?php endif; ?>

      <div class="course-guides">
        <?php if (empty($is_international_audience)): ?>
          <h3><?php print t('Course guides'); ?></h3>
          <?php print t('View all our courses for Australian residents, plus learn about'); ?>:
          <ul>
            <li>
              <a href="/courses/how-to-apply"><?php print t('How to apply for courses'); ?></a>
            </li>
            <li>
              <a href="/campuses-services/student-support"><?php print t('Student services and assistance'); ?></a>
            </li>
            <li>
              <a href="/campuses-services/our-facilities"><?php print t('Facilities'); ?></a> <?php print t('and'); ?>
              <a href="/campuses-services/our-campuses"><?php print t('campuses'); ?></a>
            </li>
            <li>
              <a href="/sites/default/files/vu-polytechnic-course-guide.pdf" target="_blank"><?php print t('VU Polytechnic 2019 TAFE Course Guide'); ?>
                <small class="pdfsize">(PDF, 8 MB)</small>
              </a>
            </li>
            <li>
              <a href="/sites/default/files/vu-course-guide-undergraduate.pdf" target="_blank"><?php print t('VU 2019 Undergraduate Course Guide'); ?>
                <small class="pdfsize">(PDF, 4 MB)</small>
              </a>
            </li>
            <li>
              <a href="/sites/default/files/vu-course-guide-postgraduate.pdf" target="_blank"><?php print t('VU 2019 Postgraduate Course Guide'); ?>
                <small class="pdfsize">(PDF, 3 MB)</small>
              </a>
            </li>
          </ul>
        <?php else: ?>
          <h3><?php print t('Studying at VU'); ?></h3>
          <?php print t('Learn more about studying at VU as a non-resident'); ?>:
          <ul>
            <li>
              <a href="/courses/how-to-apply/international-applications"><?php print t('How to apply for courses'); ?></a>
            </li>
            <li>
              <a href="/campuses-services/student-support/international-student-support"><?php print t('International student support'); ?></a>
            </li>
            <li>
              <a href="/campuses-services/our-facilities"><?php print t('Facilities'); ?></a> <?php print t('and'); ?>
              <a href="/campuses-services/our-campuses"><?php print t('campuses'); ?></a>
            </li>
            <li>
              <a href="/<?php print VUMAIN_URLS_INTERNATIONAL_STUDENTS; ?>/life-in-melbourne"><?php print t('Life in Melbourne'); ?></a>
            </li>
            <li>
              <a href="http://eaams.vu.edu.au/lava/MyBrochure/CreateBrochure.aspx"><?php print t('Create your own course e-brochure'); ?></a>
            </li>
          </ul>
        <?php endif; ?>
      </div>

      <?php if (!empty($featured_success_story)): ?>
        <?php print render($featured_success_story); ?>
      <?php endif; ?>

      <?php if (!empty($content_course_search_form_block) && empty($kiosk)): ?>
        <div class="course-search-form-content-wrapper clearfix">
          <?php print render($content_course_search_form_block); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-md-4 right-column">
      <div class="sidebar-related-study-areas">
        <h2 class="title-study-areas"><?php echo t('Study areas'); ?></h2>
        <?php
        // If field_study_topic is empty, then this is a study topic area
        // otherwise it is a study area page.
        $view = empty($node->field_study_topic) ? 'list_study_areas' : 'related_study_areas';

        // Using the views embed directly, as it crashes PHP when used
        // in preprocess_node.
        print views_embed_view('study_areas', $view, $node->nid);
        ?>
      </div>

      <?php if (!empty($rhs_boxes)): ?>
        <div class="study-areas-rhs-boxes">
          <?php foreach ($rhs_boxes as $rhs_box): ?>
            <?php print $rhs_box; ?>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</article>
