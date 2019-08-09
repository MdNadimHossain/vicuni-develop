/**
 * @file
 * Javascript behaviours for the Accordion paragraph type.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreAdmissionAtar = {
    attach: function (context, settings) {

      // Atar according expands when clicks on more about ATAR.
      $('.atar-min-entry-more-a').on('click', function () {
        if ($('.atar-indicator').is(':hidden')) {
          $('.group-secondary-education .accordion-inner a').click();
        }
      });
    }
  };
})(jQuery);
