<?php
/**
 * @file
 * Homepage social media.
 */
?>
<div class="row">
  <?php if ($content['fb']['show']): ?>
    <div class="col-md-4">
      <div class="logo-widget">
        <img class="logo" src="<?php print base_path() . drupal_get_path('theme', 'vu'); ?>/images/facebook.png" alt=""/>
        <div class="fb-like" data-href="https://www.facebook.com/victoria.university/" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div>
      </div>
      <div id="fb-root"></div>
      <script>(function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/en_GB/sdk.js#xfbml=1&version=v2.10&appId=428326074000298";
        fjs.parentNode.insertBefore(js, fjs);
      }(document, 'script', 'facebook-jssdk'));</script>
      <div class="fb-page" data-href="https://www.facebook.com/victoria.university/" data-tabs="timeline" data-small-header="true" data-width="500" data-hide-cover="true" data-show-facepile="false">
        <blockquote cite="https://www.facebook.com/victoria.university/" class="fb-xfbml-parse-ignore"><a href="https://www.facebook.com/victoria.university/">Victoria University, Melbourne Australia</a></blockquote>
      </div>
    </div>
  <?php endif; ?>
  <?php if (isset($content['twitter'])): ?>
    <div class="col-md-4">
      <div class="logo-widget">
        <img class="logo" src="<?php print base_path() . drupal_get_path('theme', 'vu'); ?>/images/twitter.png" alt=""/>
        <a href="https://twitter.com/victoriauninews" class="twitter-follow-button noext" data-show-count="false" data-show-screen-name="false">Follow @victoriauninews</a>
        <script>!function (d, s, id) {
            var js, fjs = d.getElementsByTagName(s)[0], p = /^http:/.test(d.location) ? 'http' : 'https';
            if (!d.getElementById(id)) {
              js = d.createElement(s);
              js.id = id;
              js.src = p + '://platform.twitter.com/widgets.js';
              fjs.parentNode.insertBefore(js, fjs);
            }
          }(document, 'script', 'twitter-wjs');</script>
      </div>
      <?php print $content['twitter']; ?>
    </div>
  <?php endif; ?>
  <?php if (isset($content['ig'])): ?>
    <div class="col-md-4">
      <div class="logo-widget">
        <img class="logo" src="<?php print base_path() . drupal_get_path('theme', 'vu'); ?>/images/instagram.png" alt=""/>
        <span class="ig-follow" data-id="73d3fd" data-handle="victoriauniversity" data-count="true" data-size="small" data-username="false"></span>

        <a class="noext instagram-follow-button" href="https://www.instagram.com/victoriauniversity/">
          Follow
        </a>

      </div>
      <?php print $content['ig']; ?>
    </div>
  <?php endif; ?>
</div>
