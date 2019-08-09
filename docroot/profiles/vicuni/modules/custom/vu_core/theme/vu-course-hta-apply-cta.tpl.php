<?php

/**
 * @file
 * Template for apply CTA block on course pages.
 */
?>
<div class="apply-block container">
  <div class="apply-block__button-container">
    <?php if (!empty($button['label'])): ?>
      <a href="<?php print $button['link']; ?>" <?php print drupal_attributes($button['attributes']); ?>>
        <?php print $button['label']; ?>
      </a>
    <?php endif; ?>
  </div>
</div>

<div class="modal fade" id="apply-cta-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close btn-apply-modal-close" data-dismiss="modal" aria-label="Close" ></button>
        <h3>Apply for <?php print $course_title; ?></h3>

        <?php if (vu_courses_is_international_course_url()): ?>
          <?php print theme('vu_course_hta_international_summary', ['modal' => TRUE]) ?>

        <?php else: ?>
          <p><strong><?php print $application_method_text; ?></strong></p>
          <?php if ($vu_online): ?>
            <p>Applications to study at our city campus are open twice yearly.</p>
            <p>Applications to study 100% online are open year-round.</p>
          <?php endif; ?>
          <div class="row">
            <?php print $overview_right ?>
            <?php if ($vtac): ?>
              <div id="vtac-apply-info" class="col-md-6">
                <h4><?php print $vtac['title_text']; ?></h4>
                <?php print theme('vu_course_hta_vtac_open', $vtac) ?>
              </div>
            <?php endif; ?>

            <div id="direct-apply-info" class="col-md-6">
              <?php if ($direct_closed && $vu_online): ?>
                <?php print theme('vu_course_hta_direct_closed', $direct) ?>
              <?php else: ?>
                <h4><?php print $direct['title_text']; ?></h4>
                <?php print theme('vu_course_hta_direct_open', $direct) ?>
              <?php endif; ?>
            </div>

            <?php if ($vu_online): ?>
              <div id="vuonline-apply-info" class="col-md-6">
               <?php print theme('vu_course_hta_vu_online', $vu_online) ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <div class="dismiss-modal">
          <button tabindex="0" class="close-text btn-apply-modal-close" data-dismiss="modal">Close</button>
        </div>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->
