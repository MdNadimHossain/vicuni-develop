/**
 * @file
 * Enhancements for Enquire Now node type forms.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.courseEnquireNow = {
    attach: function (context) {
      // Provide the vertical tab summaries.
      $('fieldset#edit-enquire-now', context).drupalSetSummary(function (context) {
        var vals = [];
        $('input[type=checkbox]', context).each(function () {
          if (this.checked && this.attributes['data-enabled-description']) {
            vals.push(this.attributes['data-enabled-description'].value);
          }
          else if (!this.checked && this.attributes['data-disabled-description']) {
            vals.push(this.attributes['data-disabled-description'].value);
          }
        });
        return vals.join(', ');
      });
    }
  };
}(jQuery));
