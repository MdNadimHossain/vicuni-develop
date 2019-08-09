<?php

/**
 * @file
 * Template for international how to apply summary on upper left of course page.
 */
?>
<p><?php print t('We are currently accepting applications for this course.'); ?></p>
<p><?php print t('Methods of applying:'); ?></p>
<p><?php print t('International students can apply directly to Victoria University using our online application system, or apply through an education agent.'); ?></p>
<?php print t('<a href="@url" class="btn btn-secondary" role="button" target="_blank">Direct online application</a>', array('@url' => 'http://eaams.vu.edu.au/')); ?>
<?php print t('<a href="@url" class="btn btn-secondary" role="button" target="_blank">Find an education agent</a>', array('@url' => 'http://eaams.vu.edu.au/BrowseAgents.aspx')); ?>
<br>