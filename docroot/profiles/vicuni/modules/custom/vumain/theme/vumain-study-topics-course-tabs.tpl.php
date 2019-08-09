<?php
/**
 * @file
 * Theme implementation for course tabs.
 */
?>
<ul class="nav nav-tabs">
  <li class="<?php print (!$is_international_audience) ? 'active' : '' ?>">
    <a href="<?php print $node_url; ?>"><?php print t('Courses for Australian residents'); ?></a>
  </li>
  <li class="<?php print ($is_international_audience) ? 'active' : '' ?>">
    <a href="<?php print $node_url; ?>?audience=international"><?php print t('Courses for International students'); ?></a>
  </li>
</ul>
