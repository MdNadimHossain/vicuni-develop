/**
 * @file
 * Additional functionality for the site search form.
 */

/* global jQuery, Drupal */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.victorySiteSearchForm = {
    attach: function (context) {
      // Do not attach to AJAX responses.
      if (context !== window.document) {
        return;
      }

      $(window).load(function () {
        var win = $(this);
        if (win.width() < 768) {
          $('.main-content .row .site-search-form.section .form-text').attr('placeholder', 'Search eg., courses, units');
        }
      });

      $('.query-input-container').on('keydown keyup keypress', function (e) {
        if (e.keyCode === 40 || e.keyCode === 38) {
          var text = $(this).find('.dropdown .dropdown-menu li.active').text();
          if (text !== '') {
            var inputField = $(this).find('input.form-text');
            if (inputField !== 'undefined') {
              inputField.val(text);
            }
          }
        }
      });
    }
  };
}(jQuery, Drupal));
