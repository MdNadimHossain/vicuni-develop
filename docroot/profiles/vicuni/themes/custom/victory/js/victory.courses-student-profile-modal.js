/**
 * @file
 * Course page Student profile modal functionality.
 */

/* global jQuery, Drupal */

(function ($, window, Drupal) {
  'use strict';

  // Add Victory behaviour.
  Drupal.victory = Drupal.victory || {};
  Drupal.victory.courses_student_profile_modal = {
    attach: function () {
      $('footer').after($('#student-profile-modal'));
      $('#student-profile-modal').modal({show: false});

      $('.js-student-profile').click(function () {
        $('#student-profile-modal').modal('show');
      });

      $('#student-profile-modal').on('hidden.bs.modal', function () {
        $('.js-student-profile').focus();
      });
    }
  };
}(jQuery, window, Drupal));
