<?php

/**
 * @file
 * Template file for Releated links.
 */
?>
<?php if (count($content)): ?>
  <div class="list__style--default">
    <div class="victory-researcher-profile-related-links">
      <h3>
        <div class="label-above">Related links</div>
      </h3>
      <ul>
        <?php foreach ($content as $link): ?>
          <li>
            <a href="<?php print $link['link']; ?>" class="noext">
              <div class="icon"></div>
              <div class="text">
                <span class="title"><?php print $link['link_label']; ?></span>
              </div>
              <div class="arrow"></div>
            </a>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
<?php endif; ?>
