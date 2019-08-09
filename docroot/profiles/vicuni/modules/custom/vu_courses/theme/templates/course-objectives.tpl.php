<?php

/**
 * @file
 * Course objectives template.
 */
if ($course_objectives): ?>
  <section id="course-objectives">
    <?php if ($title): ?>
      <h2><?php echo check_plain($title) ?></h2>
    <?php endif ?>
    <?php echo filter_xss_admin($course_objectives); ?>
  </section>
<?php endif ?>
