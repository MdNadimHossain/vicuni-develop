/**
 * @file
 * Javascript behaviours for the Library Opening Hours.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreLibraryHours = {
    attach: function (context, settings) {
      $(window).load(function () {
        $('.s-lc-whw-pr').after("<i class='fal fa-calendar'></i>");
      });

      $(window).load(function () {
        $('.s-lc-whw-bh').wrapInner("<div class='cbutton'><div>");
      });

    }
  };
})(jQuery);
