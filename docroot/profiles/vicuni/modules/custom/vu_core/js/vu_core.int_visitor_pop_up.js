/**
 * @file
 * Javascript behaviours for visitor outside australia popup.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreIntVisitorPopUp = {
    attach: function (context, settings) {

      $('#audience-switcher-modal').modal('show');
      $('.modal-backdrop.in').css('position', 'fixed');
    }
  };
})(jQuery);
