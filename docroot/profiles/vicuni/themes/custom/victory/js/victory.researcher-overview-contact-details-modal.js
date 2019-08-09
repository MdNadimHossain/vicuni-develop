/**
 * @file
 * Course page audience switcher modal functionality.
 */

/* global jQuery, Drupal */

(function ($, window, Drupal) {
  'use strict';

  // Add Victory behaviour.
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.researcher_overview_contact_details_modal = {
    attach: function () {
      $('footer').after($('#researcher-overview-contact-details-modal'));
      $('#researcher-overview-contact-details-modal').modal({show: false});

      $('.researcher-make-contact').click(function () {
        $('#researcher-overview-contact-details-modal').modal('show');
      });

      $('#researcher-overview-contact-details-modal').on('hidden.bs.modal', function () {
      });
    }
  };
}(jQuery, window, Drupal));
