<?php

/**
 * @file
 * Social media links block template.
 */
?>

<?php
$return_url = urlencode('http://' . $_SERVER['HTTP_HOST'] . request_uri());
$title_plain = empty($title) ? '' : filter_xss($title);
$title_encoded = urlencode($title_plain);
?>
<?php if ($is_sydney): ?>
  <ul class="social-media-links vu-sydney-footer-media">
    <li>
      <a href="https://www.facebook.com/vusydney.australia/" class="fa fa-2x fa-facebook-official noext" aria-hidden="true"><span>Visit VU on Facebook</span></a>
    </li>
    <li>
      <a href="https://www.youtube.com/channel/UCSd5EvwYPPtGoMZEWvUyIVQ" class="fa fa-2x fa-youtube noext" aria-hidden="true"><span>Visit VU on Youtube</span></a>
    </li>
    <li>
      <a href="https://www.instagram.com/vusydney/" class="fa fa-2x fa-instagram noext" aria-hidden="true"><span>Visit VU on Instagram</span></a><br>
    </li>
    <li>
      <a href="https://www.linkedin.com/school/victoria-university-sydney/" class="fa fa-2x fa-linkedin-square noext" aria-hidden="true"><span>Visit VU on LinkedIn</span></a>
    </li>
  </ul>
<?php else: ?>
  <ul class="social-media-links">
    <li>
      <a href="https://twitter.com/#!/victoriauninews" class="fa fa-2x fa-twitter noext" aria-hidden="true"><span>Visit VU on Twitter</span></a>
    </li>
    <li>
      <a href="http://www.facebook.com/victoria.university" class="fa fa-2x fa-facebook-official noext" aria-hidden="true"><span>Visit VU on Facebook</span></a>
    </li>
    <li>
      <a href="http://www.youtube.com/user/VictoriaUniversity" class="fa fa-2x fa-youtube noext" aria-hidden="true"><span>Visit VU on Twitter Youtube</span></a>
    </li>
    <li>
      <a href="https://instagram.com/victoriauniversity/" class="fa fa-2x fa-instagram noext" aria-hidden="true"><span>Visit VU on Instagram</span></a>
    </li>
    <li>
      <a href="http://www.linkedin.com/company/victoria-university" class="fa fa-2x fa-linkedin-square noext" aria-hidden="true"><span>Visit VU on LinkedIn</span></a>
    </li>
    <li>
      <a href="https://www.snapchat.com/add/vicunimelb" class="fa fa-2x fa-snapchat-ghost noext" aria-hidden="true"><span>Visit VU on Snapchat</span></a>
    </li>
  </ul>
<?php endif ?>
