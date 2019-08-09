<?php

/**
 * @file
 * Custom theme implementation for the search block form.
 *
 * - Added 'row' class for warpping container.
 */
?>
<div class="container-inline row">
  <?php if (empty($variables['form']['#block']->subject)) : ?>
    <h2 class="element-invisible"><?php print t('Search Google Appliance'); ?></h2>
  <?php endif; ?>
  <?php print $block_search_form_complete; ?>
</div>
