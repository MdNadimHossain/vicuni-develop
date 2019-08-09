/**
 * @file
 * Course page audience switcher modal functionality.
 */

/* global jQuery, Drupal */

(function ($, window, Drupal) {
  'use strict';

  // Add Victory behaviour.
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.courses_audience_switcher = {
    attach: function () {
      $('footer').after($('#audience-switcher-modal'));
      $('#audience-switcher-modal').modal({show: false});

      $('.js-aud-btn-modal').click(function () {
        $('#audience-switcher-modal').modal('show');
      });

      $('#audience-switcher-modal').on('hidden.bs.modal', function () {
        $('.js-aud-btn-modal').focus();
      });
    }
  };
}(jQuery, window, Drupal));
