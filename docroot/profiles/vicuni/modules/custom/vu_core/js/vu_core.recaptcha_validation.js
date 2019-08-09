/**
 * @file
 * Javascript behaviours for the Recaptcha Validation.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreRecaptchaValidation = {
    attach: function (context, settings) {
      $(window).load(function () {
        $(document).ready(function () {
          // Handler for .ready() called.
          $('html, body').animate({
            scrollTop: $('.webform-client-form').offset().top
          }, 'slow');
        });
        var newval = 30;
        $('.captcha').css('margin-bottom', newval);
        $('.g-recaptcha > *:first-child').addClass('recaptcha-validate');
      });
    }
  };
})(jQuery);
