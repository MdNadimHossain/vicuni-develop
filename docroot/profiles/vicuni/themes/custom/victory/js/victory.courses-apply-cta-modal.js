/**
 * @file
 * Course page Apply CTA modal functionality.
 */

/* global jQuery, Drupal */

(function ($, window, Drupal) {
  'use strict';

  // Add Victory behaviour.
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.courses_apply_cta_modal = {
    attach: function () {
      $('footer').after($('#apply-cta-modal'));
      $('#apply-cta-modal').modal({show: false});

      $('.js-apply-btn-modal').click(function () {
        $('#apply-cta-modal').modal('show');
      });

      $('#apply-cta-modal').on('hidden.bs.modal', function () {
        $('.js-apply-btn-modal').focus();
      });

      $('#direct-apply-info .btn-register-interest').click(function () {
        $('#apply-cta-modal').modal('hide');
      });
    }
  };
}(jQuery, window, Drupal));
