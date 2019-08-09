/**
 * @file
 * Submit library search form with additional query parameters.
 */

/* global jQuery, Drupal */

(function ($) {
  'use strict';
  Drupal.behaviors.vuCoreLibrarySearchForm = {
    attach: function (context, settings) {
      // Serialize and submit library search form.
      $('.library-search-form', context).submit(function (e) {
        // Prevent default form submission behaviour.
        e.preventDefault();

        // Build variables.
        var url = 'https://wallaby.vu.edu.au:4433/login?url=https://search.ebscohost.com/login.aspx?direct=true&authtype=' + $('input[name="authtype"]').val() + '&custid=' + $('input[name="custid"]').val() + '&groupid=' + $('input[name="groupid"]').val() + '&profid=' + $('input[name="profid"]').val();
        var query = $(this).find('input[name=query]');
        var bquery = query.val();
        var ptoption = $(this).find('input[name=options]:checked');

        // Modify bquery value.
        if (ptoption.length > 0 && ptoption.val()) {
          // The library site concatenates the query string and
          // the filter in one variable for processing.
          bquery = encodeURIComponent(query.val() + ' ' + ptoption.val());
        }

        // Build and redirect to URL.
        url = url + '&bquery=' + bquery;
        window.location.href = url;
      });
    }
  };
})(jQuery);
