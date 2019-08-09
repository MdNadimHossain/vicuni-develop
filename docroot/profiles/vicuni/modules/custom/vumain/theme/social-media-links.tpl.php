<?php
/**
 * @file
 */
$url = urlencode('http://' . $_SERVER['HTTP_HOST'] . request_uri()) ?>
<?php $title_plain = $title ?>
<?php $title = urlencode($title) ?>
<?php $site_name = urlencode(variable_get('site_name', '')) ?>
<section class="social-media-links">
  <strong>Share this <?php echo $node_type; ?></strong>
  <ul class="social-media-links">
    <li>
      <a href="http://www.facebook.com/sharer.php?u=<?php echo $url ?>&t=<?php echo $title ?>" class="facebook"><span>Share on Facebook</span></a>
    </li>
    <li>
      <a href="https://twitter.com/share?text=<?php echo vumain_media_add_twitter_handle($title_plain) ?>" class="twitter"><span>Share on Twitter</span></a>
    </li>
    <li>
      <a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php echo $url ?>&title=<?php echo $title; ?>&source=<?php echo $site_name ?>>" class="linkedin"><span>Share on LinkedIn</span></a>
    </li>
    <li>
      <a href="https://m.google.com/app/plus/x/?v=compose&content=<?php echo $title . ' ' . $url ?>" class="google-plus"><span>Share on Google+</span></a>
    </li>
    <li>
      <a href="http://www.tumblr.com/share/link?url=<?php echo $url ?>&name=<?php echo $title ?>" class="tumblr"><span>Share on Tumblr</span></a>
    </li>
    <li>
      <a href="mailto:?subject=<?php echo str_replace('+', '%20', $title) ?>&body=<?php echo $url ?>" class="email"><span>Share via email</span></a>
    </li>
  </ul>
</section>
