<?php

/**
 * @file
 * Best bets template.
 *
 * Available variable:
 * - $curator: An array of curator information.
 */
?>
<?php if (!empty($curator['exhibits'])): ?>
  <div id="funnelback-curator">

    <?php foreach($curator['exhibits'] as $exhibit): ?>

    <a href="<?php print FunnelbackQueryString::funnelbackFilterCuratorLink($exhibit['linkUrl']) ?>" title="<?php print $exhibit['displayUrl'] ?>">
        <div class="funnelback-exhibit">
          <h3><span class="heading"><?php print $exhibit['titleHtml'] ?></span></h3>
          <p class="desc"><?php print $exhibit['descriptionHtml'] ?></p>
          <p><span class="display-url"><?php print $exhibit['displayUrl'] ?></span></p>
        </div>
      </a>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
