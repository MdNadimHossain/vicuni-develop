<?php

/**
 * @file
 * Courses - How to Apply - Direct closed course.
 */
?>
<div class="hta-method-container <?php print (!$modal) ? $direct_class : ''; ?>">
  <div class="hta-direct">
    <?php if (!$modal): ?>
      <h3>Apply for on-campus study</h3>
    <?php else: ?>
      <h4>Apply for on-campus study</h4>
    <?php endif; ?>
    <p>Applications for on-campus study are not being taken at this time.</p>

    <p>Browse our other <a href="/study-at-vu/courses/browse-for-courses/by-topic/business">Business courses</a> or send us an enquiry to be notified of updates on studying at our city campus.</p>
    <a href="#goto-enquire-now" data-smoothscroll="1" class="btn btn-secondary <?php print $modal ? 'btn-register-interest' : '' ?>" role="button">Register your interest</a>
    <?php if (!$modal && $after_apply):?>
      <?php print $after_apply; ?>
    <?php endif; ?>
  </div>
</div>
