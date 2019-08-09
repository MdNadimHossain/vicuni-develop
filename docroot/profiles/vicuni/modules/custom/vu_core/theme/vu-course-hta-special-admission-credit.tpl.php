<?php

/**
 * @file
 * Template for HTA - open - special admission credit on course pages.
 */
?>
<div class="before-you-apply">
  <h3>Before you apply</h3>
  <p>
    Before applying, you should consider whether you also want to apply for:
  <ul>
    <li>
      <a href="/courses/how-to-apply/special-admission-programs">Special admission programs:</a> Depending on your life circumstances you may be eligible for special consideration of your application.
    </li>
    <li>
      <a href="/study-at-vu/courses/pathways-to-vu/credit-for-skills-past-study/advanced-standing">Advanced standing:</a>
      If you have significant experience or studies elsewhere you may be eligible for credit for some units of your course and not have to undertake them.
    </li>
  </ul>
  </p>
  <?php if (!empty($supplementary_information)): ?>
    <?php print $supplementary_information ?>
  <?php endif; ?>
</div>
