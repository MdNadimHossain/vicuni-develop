<?php

/**
 * @file
 * Associated courses template.
 */
$this_year = date('Y');
$next_year = $this_year + 1;

if (vu_feature_switches_switch_state('courses-new-course-info') && $new_course && $course_preceded_by && $course_preceded_by->url) : ?>
  <!-- Display preceding course -->
  <?php if ($is_international) : ?>
    <h3>July <?php echo $this_year; ?> intake</h3>
  <?php else : ?>
    <h3>Open for mid-year entry</h3>
  <?php endif; ?>
  <p>Want to study sooner? Apply to
    <a href='<?php echo $course_preceded_by->url; ?>'>start this course in July <?php echo $this_year; ?></a>.
  </p>

<?php elseif ($course_followed_by && $course_followed_by->url) : ?>
  <!-- Display following course -->
  <h3>Entry in <?php echo $next_year; ?></h3>
  <p>This course is
    <a href='<?php echo $course_followed_by->url; ?>'>available for entry in <?php echo $next_year; ?></a> from February onwards.
  </p>
<?php endif; ?>
