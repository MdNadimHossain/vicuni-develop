<?php

/**
 * @file
 * Template file for Media appearance.
 */
?>
<?php if (count($content)): ?>
  <div class="section research-career-media" id="research-career-media">
    <h2 class="victory-title__stripe">Media appearances</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-10">
          <?php foreach ($content as $media): ?>
            <div class="researcher-career-media">
              <p><?php print $media['field_rp_ma_date']; ?></p>
              <p>
                <a href="<?php print $media['field_rp_ma_link']; ?>"><?php print $media['field_rp_ma_title']; ?></a>
              </p>
              <p><?php print $media['field_rp_ma_summary']; ?></p>
            </div>
          <?php endforeach; ?>
        </div>
        <div class="col-md-push-1 col-md-1"></div>
      </div>
    </div>
  </div>
<?php endif; ?>
