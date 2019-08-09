/**
 * @file
 * Javascript behaviours for the Page Builder content type.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCorePageBuilder = {
    attach: function (context, settings) {
      // Move body summary field. This isn't adjustable in the content type.
      var $summary = $('.field-name-body div.text-summary-wrapper');
      if ($summary.length) {
        $('#edit-title-field').after($summary);
      }
    }
  };
})(jQuery);
