/**
 * @file
 * Behaviours for Find Media Expert Form.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryMediaExpertSearch = {
    attach: function (context, settings) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      var self = this;

      var elementText = '#vu-core-expert-guide-search-form .form-text';
      var elementButton = '#vu-core-expert-guide-search-form .form-submit';

      $(window).on('load', self.changePlaceHolder(elementText, elementButton));
      // This may not necessary, good for testing.
      $(window).resize(function () {
        self.changePlaceHolder(elementText, elementButton);
      });

    },

    /**
     * Check the placeholder text.
     */
    changePlaceHolder: function (text, btn) {
      var self = this;
      var textWidth = $(text).width();
      var textPlaceHolder = Drupal.settings.data.longPlaceHolderText;
      var btnText = 'Search';

      // Placeholder text has to replace according to the width of text input.
      if (textWidth > 220 && textWidth < 280) {
        textPlaceHolder = Drupal.settings.data.defaultPlaceHolderText;
      }
      else if (textWidth < 220) {
        textPlaceHolder = Drupal.settings.data.shortPlaceHolderText;
      }
      else {
        textPlaceHolder = Drupal.settings.data.longPlaceHolderText;
      }

      // Check for XS devices.
      if (self.isXSDevice()) {
        // Fixed for iPad.
        if (navigator.userAgent.match(/iPad/i)) {
          btnText = 'Search';
        }
        else {

          // Rest of small devices, remove button text.
          btnText = '';
        }
      }

      $(btn).text(btnText);
      $(text).attr('placeholder', textPlaceHolder);
    },

    /**
     * Check that current device is XS.
     */
    isXSDevice: function () {
      if ($(window).width() <= 768) {
        return true;
      }

      return false;
    }
  };
}(jQuery, Drupal));
