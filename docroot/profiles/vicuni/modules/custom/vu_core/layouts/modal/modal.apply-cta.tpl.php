<?php

/**
 * @file
 * Hero Banner Display Suite layout.
 */
?>
<div class="modal fade" id="apply-cta-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close" ></button>
        <h3>Apply for <?php print $course_title; ?></h3>
        <?php if (vu_courses_is_international_course_url()): ?>
          <?php print theme('vu_course_apply_cta_international') ?>
        <?php else: ?>
          <?php print $overview_right ?>
          <?php print theme('vu_course_hta_vtac_open') ?>
          <?php print theme('vu_course_hta_direct_open') ?>
        <?php endif; ?>

        <div class="dismiss-modal">
          <button tabindex="0" class="close-text" data-dismiss="modal">Close</button>
        </div>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->
