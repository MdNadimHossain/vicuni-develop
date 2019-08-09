<?php

/**
 * @file
 * Browse for courses link template.
 */
?>
<a href="/courses/search?iam=resident&type=Course&query=<?php echo urlencode($type); ?>">
  See all <?php echo check_plain($type) ?>
</a>
