/**
 * @file
 * External link icon functionality.
 */

/* global jQuery, Drupal */

(function ($, window, Drupal) {
  'use strict';

  // Add Victory behaviour.
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.popover = {
    attach: function () {
      $('.popover-trigger').popover({
        html: true,
        content: function () {
          return $($(this).attr('data-popover-content')).html();
        },
        container: 'body'
      });
    }
  };

}(jQuery, window, Drupal));
