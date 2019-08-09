<?php

/**
 * @file
 * Template for international how to apply summary bock on course pages.
 */
?>
<p><?php print t('We are currently accepting applications for this course.'); ?></p>
<p><?php print t('Methods of applying:'); ?></p>
<p><?php print t('International students can apply directly to Victoria University using our online application system, or apply through an education agent.'); ?></p>
<?php if (!empty($supplementary_information)): ?>
  <?php print $supplementary_information ?>
<?php endif; ?>
<?php print t('<a href="@url" class="btn btn-secondary @class" role="button" target="_blank">Direct online application</a>', ['@url' => 'http://eaams.vu.edu.au/', '@class' => $modal ? 'btn-apply-intl-direct-modal' : '']); ?>
<?php print t('<a href="@url" class="btn btn-secondary @class" role="button" target="_blank">Find an education agent</a>', ['@url' => 'http://eaams.vu.edu.au/BrowseAgents.aspx', '@class' => $modal ? 'btn-apply-agent-modal' : '']); ?>
