/**
 * @file
 * File size/info functionality.
 */

/* global jQuery, Drupal */

(function ($, window, Drupal) {
  'use strict';

  // Add Victory behaviour.
  Drupal.behaviors.vu_file_link_info = {
    attach: function (context, settings) {
      var that = this;
      $('a[type]', context).each(function () {
        var map = {
          'application/pdf': 'PDF',
          'application/msword': 'DOC',
          'application/vnd.openxmlformats-officedocument.wordprocessingml.document': 'DOCX'
        };
        var fileMeta = $(this).attr('type');
        var fileType;
        var fileSize;
        if (typeof fileMeta !== 'undefined') {
          var splitFileMeta = fileMeta.split('; ');
          if (splitFileMeta.length > 1 && typeof map[splitFileMeta[0]] !== 'undefined') {
            fileType = map[splitFileMeta[0]];
            fileSize = fileMeta.split('=')[1];
            $(this).append(' <span class="filesize">(' + fileType + ', ' + that.humanReadableSize(fileSize) + ')</span>');
            // Open link in new page.
            $(this).attr('target', '_blank');
          }
        }
      });
    },

    // Returns file size unit in a human-readable format.
    humanReadableSize: function (bytes) {
      if (bytes === 0) {
        return '0 Bytes';
      }
      var kilobytes = 1000;
      var units = ['Bytes', 'KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'];
      var i = Math.floor(Math.log(bytes) / Math.log(kilobytes));
      return parseFloat((bytes / Math.pow(kilobytes, i)).toFixed(0)) + ' ' + units[i];
    }
  };
}(jQuery, window, Drupal));
