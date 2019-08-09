/**
 * @file
 * Remove 'no-js' class from <body>.
 */

/* global jQuery, window, Drupal */

(function ($, window, Drupal) {
  'use strict';
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.removeJs = {
    attach: function () {
      $('body').removeClass('no-js');
    }
  };
}(jQuery, window, Drupal));
