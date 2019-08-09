/**
 * @file
 * Javascript behaviours for the Course Search International.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreLibraryHours = {
    attach: function (context, settings) {
      $(function () {
        var radio1 = $('#edit-iam').children('div').eq(0);
        var radio1HTML = $('#edit-iam').children('div').eq(0).html();
        var radio2 = $('#edit-iam').children('div').eq(1);
        var radio2HTML = $('#edit-iam').children('div').eq(1).html();

        radio1.html(radio2HTML);
        radio2.html(radio1HTML);

        $("input:radio[id='edit-iam-non-resident']").prop('checked', true);
      });

    }
  };
})(jQuery);
