<?php

/**
 * @file
 * Template for social media links.
 */
?>

<div class="social-media-links page-connect">
  <ul class="social-media-links">
    <li>
      <a href="https://twitter.com/share?text=<?php echo vumain_media_add_twitter_handle($title_plain) ?>" class="fa fa-twitter noext"><span>Share on Twitter</span></a>
    </li>
    <li>
      <a href="http://www.facebook.com/sharer.php?u=<?php echo $url ?>&t=<?php echo $title ?>" class="fa fa-facebook-f noext"><span>Share on Facebook</span></a>
    </li>
    <li>
      <a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php echo $url ?>&title=<?php echo $title; ?>&source=<?php echo $site_name ?>>" class="fa fa-linkedin noext"><span>Share on LinkedIn</span></a>
    </li>
    <li>
      <a href="mailto:?subject=<?php echo str_replace('+', '%20', $title) ?>&body=<?php echo $url ?>" class="fa fa-envelope-o noext"><span>Share via email</span></a>
    </li>
  </ul>
</div>
