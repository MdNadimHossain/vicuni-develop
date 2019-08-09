/**
 * @file
 * Javascript behaviours for the Staff profile content type.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreStaffProfile = {
    attach: function (context, settings) {
      this.initPhoto(context);
    },

    initPhoto: function (context) {
      // Move staff to the first tab and make it available
      // in mobile only.
      $('.js-staff-photo:not(.processed)', context)
        .first()
        .addClass('processed')
        .clone()
        .addClass('visible-xs-inline')
        .prependTo('.js-staff-image-target')
        .wrap('<div class="staff-image-wrapper text-center"></div>');
    }
  };
})(jQuery);
