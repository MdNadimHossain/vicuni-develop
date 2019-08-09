<?php

/**
 * @file
 * Unit page template.
 *
 * @ingroup vu
 * @ingroup templates
 */

hide($content['field_unit_lev']);
$college = preg_replace('/<\\/?div[^>]*>/i', '', render($content['field_college']));
$more_info = empty($college) ?
  t('Contact your course coordinator to see if you are able to take the elective unit.') :
  t('For more info contact the !college.', ['!college' => $college]);

// This code merges in imported locations that aren't able to be
// stored in the entityreference type field. This can't live in the
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
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="row">
    <div class="col-md-7">
      <div class="unitsets-content-wrapper no-border-bottom">

        <div class="field-name-field-on-this-page-on-fly field field-name-field-on-this-page field-type-link-field field-label-above">
          <div class="field-label"><?php print t('On this page'); ?>:</div>
          <div class="field-items"></div>
        </div>

        <?php print render($content['body']); ?>

        <h2><?php print t('Unit details'); ?></h2>
        <div class="unitsets-details">
          <?php if (isset($content['field_locations'])): ?>
            <div class="unitsets-detail-item">
              <div class="course-essentials__item__label">
                <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-map-marker fa-stack-1x fa-inverse"></i></span><?php print t('Location:'); ?>
              </div>
              <div class="course-essentials__item__value">
                <?php print render($content['field_locations']); ?>
              </div>
            </div>
          <?php endif; ?>

          <?php if (!empty($unit_level)): ?>
            <div class="unitsets-detail-item">
              <div class="course-essentials__item__label">
                <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-line-chart fa-stack-1x fa-inverse"></i></span><?php print t('Study level:'); ?>
              </div>
              <div class="course-essentials__item__value">
                <?php print $unit_level; ?>
              </div>
            </div>
          <?php endif; ?>

          <?php if (isset($content['field_credit_points'])): ?>
            <div class="unitsets-detail-item">
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
            <div class="unitsets-detail-item">
              <div class="course-essentials__item__label">
                <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-tag fa-stack-1x fa-inverse"></i></span><?php print t('Unit code:'); ?>
              </div>
              <div class="course-essentials__item__value">
                <?php print render($content['field_unit_code']); ?>
              </div>
            </div>
          <?php endif; ?>
        </div>

        <?php
        // Hide comments, tags, and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_tags']);
        hide($content['field_college']);
        // Don't print original special locations field output.
        hide($content['field_locations_special']);
        print render($content);
        ?>
      </div>

      <div id="where-to-next">
        <h2 id="goto-where-to-next"><?php print t('Where to next?'); ?></h2>
        <ul>
          <li><?php print t('If you would like to take this unit as part of a course listed on this page, see the relevant course page for information about how to apply.'); ?></li>
          <?php if (!$is_first_year_college): ?>
            <li><?php print t('If you are a current VU student, you may be able to enrol in this unit as an elective. !more-info', ['!more-info' => $more_info]); ?></li>
          <?php endif; ?>
        </ul>
        <?php if ($study_single_unit): ?>
          <div class="study-single-unit">
            <h3><?php print $study_single_unit['heading']; ?></h3>
            <?php print render($study_single_unit['content']); ?>
          </div>
        <?php endif; ?>
        <h3><?php print t('You can also contact us directly:'); ?></h3>
        <ul>
          <li><?php print t('Ring us on <strong>+61 3 9919 6100</strong>'); ?></li>
          <li><?php print t('Find answers and ask questions at <a href="/gotovu?r=cst">GOTOVU</a>'); ?></li>
        </ul>
        <p>
          <small><?php print t('VU takes care to ensure the accuracy of this unit information, but reserves the right to change or withdraw courses offered at any time. Please check that unit information is current with the <a href="/contact-us">Student Contact Centre</a>.'); ?></small>
        </p>
      </div>
    </div>
    <div class="col-md-5 unitsets-rightside">
      <?php if (!$is_first_year_college): ?>
        <div class="aside-cta-head">
          <span class="fa-stack">
            <i class="fa fa-circle fa-stack-2x"></i>
            <i class="fa fa-pencil fa-stack-1x fa-inverse"></i>
          </span>
          <h2><a href="#where-to-next"><?php print t('How to apply'); ?></a></h2>
        </div>
        <div class="aside-cta-box">
          <h3><?php print t('Already a VU student?'); ?></h3>
          <p><?php print t('You may be able to enrol in this unit as an elective.'); ?></p>
          <p><?php print $more_info; ?></p>
        </div>
        <div class="aside-cta-box">
          <p>
            <a href="#where-to-next"><strong><?php print t('More on applying for this unit'); ?></strong></a>
          </p>
        </div>
      <?php endif; ?>
      <?php print $courses_this_unit_belongs_to; ?>
      <?php print $specialisations_this_unit_belongs_to; ?>
      <?php if ($study_single_unit): ?>
        <div class="study-single-unit aside-cta-box aside-cta-box--secondary">
          <h3><?php print $study_single_unit['heading']; ?></h3>
          <?php print render($study_single_unit['content']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</article>
