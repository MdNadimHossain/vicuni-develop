<?php

/**
 * @file
 * Theme implementation for modal video file entities.
 *
 * @ingroup themeable
 */
?>
<div id="<?php print $id; ?>" class="<?php print $classes ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <div class="modal-thumb-wrapper">
      <a class="noext colorbox-load" href="<?php print $popup_url; ?>">
        <img src="https://img.youtube.com/vi/<?php print substr($uri, 12)?>/hqdefault.jpg" width="100%" alt="<?php print preg_replace("/ transcript/", '', $filename); ?>" />
      </a>
    </div>
    <?php print l($filename, $file_url, ['attributes' => ['class' => ['modal-video-transcript']]]); ?>
  </div>
</div>
