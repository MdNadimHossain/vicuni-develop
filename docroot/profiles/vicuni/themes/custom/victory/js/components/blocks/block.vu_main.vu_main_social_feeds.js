/**
 * @file
 * Additional JS for social media feeds.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.blockVumainVumainSocialFeeds = {
    attach: function (context) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      var js;
      var fjs = document.getElementsByTagName('script')[0];
      if (document.getElementById('facebook-jssdk')) {
        return;
      }
      js = document.createElement('script');
      js.id = 'facebook-jssdk';
      js.src = '//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.5&appId=428326074000298';
      fjs.parentNode.insertBefore(js, fjs);
    }
  };
}(jQuery, Drupal));
