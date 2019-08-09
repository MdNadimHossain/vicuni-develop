/**
 * @file
 * Scoping for theme related behaviours.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victory = {
    attach: function (context, settings) {
      // Abstract out to Drupal.victory.
      $.each(Drupal.victory, function () {
        if ($.isFunction(this.attach)) {
          this.attach(context, settings);
        }
      });
    }
  };
}(jQuery, Drupal));
