/**
 * @file
 * Javascript behaviours for the Accordion paragraph type.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreAccordion = {
    attach: function (context, settings) {
      $(document).on('hide.bs.collapse', '.accordion-inner', function (e) {
        $(this).removeClass('accordion-inner--active');
      }).on('show.bs.collapse', '.accordion-inner', function (e) {
        $(this).addClass('accordion-inner--active');
      });

    }
  };
})(jQuery);
