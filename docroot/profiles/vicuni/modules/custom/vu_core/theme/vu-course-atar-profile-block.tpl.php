<?php

/**
 * @file
 * Courses - ATAR profile ranking data block.
 */
?>
<div class="atar-profile-block-data">
<?php  if($variables['data']) :?>
  <p><h4>ATAR profile</h4></p>
  <p><?php  print $variables['data']?></p>
<?php  else :?>
  <p><h4>Why is ATAR not applicable?</h4></p>
  <p>You will <strong>not need an ATAR score</strong> to meet the admission requirements for this course. Only the successful completion of your secondary school studies, and any additional prerequisites.
  Our courses and support programs are designed to prepare students from diverse cultures for success, regardless of their prior experience, ATAR, age, socioeconomic or educational background.</p>
<?php endif;?>
</div>
