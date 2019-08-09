<?php

/**
 * @file
 * Courses - Student profile block.
 */
?>

<h3><?php print $variables['title'] ?></h3>
<?php if ($display_table): ?>
  <p>Take a look at a <a class="js-student-profile" data-tracking="student-profile-modal">student profile</a> to get an overview of students who have previously enrolled in this course.</p>
<?php else: ?>
  <p>No student profile information available for this study period. This is a new course.</p>
<?php endif; ?>
<div class="modal fade" id="student-profile-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close btn-apply-modal-close" data-dismiss="modal" aria-label="Close" ></button>
        <h3><?php print $variables['table_title']; ?></h3>
        <?php print $variables['table']; ?>
        <div class="table-notes">
        "&lt;5" – the number of students is less than 5.<br/>
        N/A – Students not accepted in this category.<br/>
        N/P – Not published: the number is hidden to prevent calculation of numbers in cells with less than 5 students.<br/>
        </div>
        <div class="dismiss-modal">
          <button tabindex="0" class="close-text btn-apply-modal-close" data-dismiss="modal">Close</button>
        </div>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->
