<?php

/**
 * @file
 * Browse for courses tmeplate.
 */
?>
<h2><?php echo t('Browse for other courses'); ?></h2>
<?php if (count($types)): ?>
  <ul><?php foreach ($types as $nid => $type): ?>
    <li>
      <a href="/<?php echo drupal_get_path_alias('node/' . $nid) ?>"><?php echo check_plain($type) ?></a>
    </li>
 <?php endforeach ?></ul><?php
endif ?>
