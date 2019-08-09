/**
 * @file
 */

(function($, Drupal) {
  Drupal.behaviors.vumain_course_search = {
    attach: function(context, settings) {
      $('a[data-search-type]', context).click(function(e) {
        var link = $(this);
        var form = link.parents('form');
        var type = link.attr('data-search-type');

        form.find('input[name=type]').attr('value', type);
        form.submit();

        e.preventDefault();
      });
    }
  };
}(jQuery, Drupal));
