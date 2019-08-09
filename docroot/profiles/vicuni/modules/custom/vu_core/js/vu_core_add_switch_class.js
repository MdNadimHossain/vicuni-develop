/**
 * @file
 * Add 'rebrand-homepage' class in hero-banner.
 */

/* global jQuery, window, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreAddSwitchClass = {
    attach: function (context, settings) {
      $('.pane-bean-bundle-hero-banner').addClass('rebrand-homepage');
      $('.hero-title-box').addClass('rebrand-homepage');
      $('.field-name-field-hero-banner').addClass('rebrand-homepage');

      // Adding radio button image when it loads the page.
      $(window).load(function () {
        if ($('#edit-iam-resident').prop('checked') === true) {
          $('#edit-iam-resident').parent().addClass('custom-radio-selected-image');
          $('#edit-iam-non-resident').parent().removeClass('custom-radio-selected-image');
          $('#edit-iam-non-resident').parent().addClass('custom-radio-image');
        }
        if ($('#edit-iam-non-resident').prop('checked') === true) {
          $('#edit-iam-resident').parent().removeClass('custom-radio-selected-image');
          $('#edit-iam-resident').parent().addClass('custom-radio-image');
          $('#edit-iam-non-resident').parent().addClass('custom-radio-selected-image');
        }
      });

      // Switching radio button images according to the status.
      $('.rebrand-homepage .pane-content #vu-core-course-search-form input:radio').click(function () {
        if ($('#edit-iam-resident').prop('checked') === true) {
          $('#edit-iam-resident').parent().addClass('custom-radio-selected-image');
          $('#edit-iam-non-resident').parent().removeClass('custom-radio-selected-image');
          $('#edit-iam-non-resident').parent().addClass('custom-radio-image');
        }
        if ($('#edit-iam-non-resident').prop('checked') === true) {
          $('#edit-iam-resident').parent().removeClass('custom-radio-selected-image');
          $('#edit-iam-resident').parent().addClass('custom-radio-image');
          $('#edit-iam-non-resident').parent().addClass('custom-radio-selected-image');
        }
      });
    }
  };
})(jQuery);
