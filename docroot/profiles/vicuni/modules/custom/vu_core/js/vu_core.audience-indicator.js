/**
 * @file
 * Javascript behaviours for Audience Indicator.
 */

/* global jQuery, Drupal, CKEDITOR */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.vuCoreAudienceIndicator = {
    attach: function (context, settings) {
      $('#audience-indicator').on('changed.bs.select', function (e) {
        $('.audience-indicator-advice').addClass('hidden');
        $('.audience-indicator-advice .selection-text').addClass('hidden');
        $('.audience-indicator-advice .selection-text').empty();

        var ai = 0;
        var obj = $(this).selectpicker('val');
        if (obj !== null) {
          $.each(obj, function (i, v) {
            ai = v > ai ? v : ai;
          });
        }
        $('.audience-indicator-advice[data-audience=' + ai + ']').removeClass('hidden');
        $('.audience-indicator-advice .selection-text[data-audience=' + ai + ']').removeClass('hidden');
        var selection = $('.atar-audience-indicator li.selected').length;
        if (selection > 1) {
          $('.audience-indicator-advice .selection-text').empty();
          $('.audience-indicator-selection[data-audience=' + 2 + ']').removeClass('hidden');
        }
        else {
          var selectionText = $('.atar-audience-indicator li.selected .text').text();
          $('.audience-indicator-advice .selection-text').append(' of <span>' + selectionText + '</span>');
          $('.audience-indicator-selection[data-audience=' + 2 + ']').addClass('hidden');
        }
      });
    }
  };
}(jQuery, Drupal));
