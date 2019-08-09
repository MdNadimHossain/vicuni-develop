(function($, window) {

  'use strict';

  var location = window.location;

  $.fn.extLinks = function(options) {

    $.fn.extLinks.defaultSettings = {
      selector: 'a[href]:not([href^=mailto])',
      hostname: location.hostname,
      ignoreClass: 'noext',
      extClass: 'ext',
      newWindow: true
    };

    var settings = $.extend({}, $.fn.extLinks.defaultSettings, options);
    // Always add (external link) accessible text and a blank window
    this.find(settings.selector).each(function() {
      if (this.hostname !== settings.hostname) {
        if ($(this).find('span.accessibility').length === 0) {
          $(this).append('<span class="accessibility"> (external link)</span>');
        }
        if (settings.newWindow) {
          this.target = '_blank';
        }
      }
    });

    this.find(settings.selector).not('.' + settings.ignoreClass).each(function() {
      if (this.hostname !== settings.hostname) {
        $(this).addClass(settings.extClass);
      }
    });

    return this;

  };

})(window.jQuery, window);
