<?php
/**
 * @file
 * Contains template for Course finder/browser section in the homepage.
 */
?>
<div class="angled-overlay"></div>
<section class="homepage-course-info">
  <section class="find-course">
    <?php print render($form); ?>
  </section>
  <section class="browse-courses">
    <h2>Browse for courses</h2>
    <?php print $course_list; ?>
  </section>
  <section class="link-courses">
    <div class="special-cta special-cta--vicpoly">
      <a class="special-cta__link" href="https://www.vupolytechnic.edu.au">Find a TAFE course</a>
    </div>
  </section>
</section>
