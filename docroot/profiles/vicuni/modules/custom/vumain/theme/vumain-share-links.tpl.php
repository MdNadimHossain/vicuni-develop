<?php

/**
 * @file
 */
?>
<section class="social-media-links">
  <strong>Share this <?php echo $node_type; ?></strong>
  <ul class="social-media-links">
    <li>
      <a class="facebook" href="http://www.facebook.com/sharer.php?u=<?php print $encoded_url; ?>&t=<?php print $encoded_title; ?>"><span>Facebook</span></a>
    </li>
    <li>
      <a class="twitter" href="https://twitter.com/share?text=<?php print $encoded_title; ?>+/via+@victoriauninews"><span>Twitter</span></a>
    </li>
    <li>
      <a class="linkedin" href="http://www.linkedin.com/shareArticle?mini=true&url=<?php print $encoded_url; ?>&title=<?php print $encoded_title; ?>&source=<?php print $encoded_source; ?>"><span>LinkedIn</span></a>
    </li>
    <li>
      <a class="google-plus" href="https://m.google.com/app/plus/x/?v=compose&content=<?php print $encoded_title_url; ?>"><span>Google Plus</span></a>
    </li>
    <li>
      <a class="tumblr" href="http://www.tumblr.com/share/link?url=<?php print $encoded_url; ?>&name=<?php print $encoded_title; ?>"><span>Tumblr</span></a>
    </li>
    <li>
      <a class="email" href="mailto:?subject=<?php print $node->title; ?>&amp;body=<?php print $encoded_url; ?>"><span>Email</span></a></lic>
  </ul>
</section>
