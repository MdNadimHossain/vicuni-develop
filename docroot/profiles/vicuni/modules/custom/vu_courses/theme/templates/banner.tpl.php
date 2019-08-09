<?php

/**
 * @file
 * Template for full width banner.
 */
?>
<div class="banner__content">
  <p><?php echo filter_xss_admin($text); ?></p>
  <?php if (!empty($url) && !empty($link)) : ?>
    <a href="<?php echo $url; ?>"><?php echo check_plain($link); ?></a><?php
  endif; ?>
</div>
