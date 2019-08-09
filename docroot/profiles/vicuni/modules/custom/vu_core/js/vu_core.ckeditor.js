/**
 * @file
 * Javascript behaviours for CKEditor overrides.
 */

/* global jQuery, Drupal */

(function ($, Drupal, CKEDITOR) {
  'use strict';

  Drupal.behaviors.vuCoreCkeditor = {
    attach: function (context, settings) {
      CKEDITOR = CKEDITOR || {};

      CKEDITOR.config.disableNativeSpellChecker = false;

      // Add a label to the 'code' element in the Format dropdown.
      CKEDITOR.on('instanceReady', function (e) {
        for (var i in CKEDITOR.instances) {
          if (typeof CKEDITOR.instances[i] !== 'undefined') {
            var editor = CKEDITOR.instances[i];
            if (typeof editor.config.format_code !== 'undefined' && typeof editor.config.format_small !== 'undefined') {
              editor.config.format_code.name = Drupal.t('Example (Code)');
              editor.config.format_small.name = Drupal.t('Small');
            }
          }
        }
      });

      // Resize for page_builder form basic text component. [PW-1018].
      CKEDITOR.on('instanceReady', function (e) {
        var editor = e.editor;
        // This width was requested as part of [PW-1018] for page builder admin.
        var instance_width = 900;
        if (!editor.hasOwnProperty('resizeTriggered') && editor.hasOwnProperty('name') && editor.name.indexOf('field-paragraphs-left') !== -1 && editor.config.width !== instance_width) {
          editor.resize(instance_width, 420);
          // Otherwise this gets called 6 times.
          editor['resizeTriggered'] = true;
        }
      });
    }
  };
}(jQuery, Drupal, CKEDITOR));
