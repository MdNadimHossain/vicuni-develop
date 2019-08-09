<?php

/**
 * @file
 * Template file for Youtube video media.
 *
 * Variables available:
 *  $uri - The media uri for the YouTube video (e.g., youtube://v/xsy7x8c9).
 *  $video_id - The unique identifier of the YouTube video (e.g., xsy7x8c9).
 *  $id - The file entity ID (fid).
 *  $url - The full url including query options for the Youtube iframe.
 *  $options - An array containing the Media Youtube formatter options.
 *  $api_id_attribute - An id attribute if the Javascript API is enabled;
 *  otherwise NULL.
 *  $width - The width value set in Media: Youtube file display options.
 *  $height - The height value set in Media: Youtube file display options.
 *  $title - The Media: YouTube file's title.
 *  $alternative_content - Text to display for browsers that don't support
 *  iframes.
 */
$style = !empty($options['attributes']['style']) ? $options['attributes']['style'] : '';
$width = !empty($options['attributes']['width']) ? $options['attributes']['width'] : $width;
$height = !empty($options['attributes']['height']) ? $options['attributes']['height'] : $height;
?>
<div class="<?php print $classes; ?> media-youtube-<?php print $id; ?>" style="max-width:<?php print $width; ?>">
  <iframe class="media-youtube-player" <?php print $api_id_attribute; ?>width="100%" height="<?php print $height; ?>" title="<?php print $title; ?>" src="<?php print $url; ?>" frameborder="0" allowfullscreen style="<?php print $style; ?>"><?php print $alternative_content; ?></iframe>
  <?php if (!empty($options['attributes']['alt'])): ?>
    <div class="video-embed-description"><?php print $options['attributes']['alt']; ?></div>
  <?php endif; ?>
</div>
