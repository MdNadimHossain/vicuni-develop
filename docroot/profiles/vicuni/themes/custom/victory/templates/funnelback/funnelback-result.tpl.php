<?php

/**
 * @file
 * Single search result template.
 *
 * Available variables:
 * - $display_url: The url string for display.
 * - $live_url: The live url string.
 * - $title: The result title string.
 * - $date: The result date string.
 * - $summary: The result summary string.
 * - $metadata: An array of additional metadata with the result.
 */
?>
<a href="<?php print $display_url ?>" title="<?php print $live_url ?>">
  <div class="result-content">
    <?php if (substr($live_url, -4) == '.pdf'): ?>
      <h3><span class="heading-with-pdf"><span class="pdf-text">[PDF]</span> <?php print $title ?></span></h3>
    <?php elseif (substr($live_url, -5) == '.docx'): ?>
      <h3><span class="heading-with-docx"><span class="docx-text">[DOC]</span> <?php print $title ?></span></h3>
    <?php else: ?>
      <h3><span class="heading"><?php print $title ?></span></h3>
    <?php endif; ?>
    <p><span class="summary"><?php print $summary; ?></span></p>
    <p><span class="display-url"><?php print $live_url ?></span></p>
  </div>
</a>
