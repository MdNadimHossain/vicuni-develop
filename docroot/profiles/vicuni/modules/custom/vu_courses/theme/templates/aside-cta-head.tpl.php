<?php

/**
 * @file
 * Component template.
 */
?>
<div class="aside-cta-head<?php echo $modifier ? ' aside-cta-head--' . $modifier : '' ?>">
  <span class="fa-stack aside-cta-head__icon">
    <i class="fa fa-circle fa-stack-2x"></i>
    <i class="fa fa-<?php echo $icon ?> fa-stack-1x fa-inverse"></i>
  </span>
  <h2 class="aside-cta-head__label" data-neon-onthispage="false">
    <?php if (!empty($url)): ?>
      <a href="<?php echo $url ?>" data-smoothscroll><?php echo check_plain($label) ?></a>
    <?php else: echo check_plain($label);
    endif ?>
  </h2>
</div>
