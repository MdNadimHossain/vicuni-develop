/**
 * @file
 * Additional functionality for the course search form.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victoryCourseSearchForm = {
    attach: function (context) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }
      $('.js-search_button span.input-group-addon').click(function () {
        $(this).closest('form').submit();
      });
    }
  };
}(jQuery, Drupal));
