<?php

/**
 * @file
 * Template a single pathway.
 */
?>
<div class="pathway">
  <div class="pathway__title">
    <b><?php print empty($pathway['nid']) ? $pathway['name'] : l($pathway['name'], 'node/' . $pathway['nid']); ?></b>
    <?php if ($pathway['type'] !== 'Internal to VU'): ?>
    <p><?php print $pathway['institution']; ?><?php print !empty($pathway['country']) ? ', ' . $pathway['country'] : ''; ?></p>
    <?php endif; ?>
  </div>
  <p>
    <?php if ($pathway['credit_units'] > 0): ?>
      <?php print t('You will be credited for up to <strong>@credit</strong> of study.', [
        '@credit' => format_plural($pathway['credit_units'], '@count credit point', '@count credit points', ['@count' => $pathway['credit_units']]),
      ]); ?>
    <?php else: ?>
      <?php print t('You will be <strong>guaranteed entry only</strong>.'); ?>
    <?php endif; ?>
  </p>
</div>
