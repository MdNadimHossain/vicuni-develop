/**
 * @file
 * Custom configuration for CKEditor.
 */

CKEDITOR.editorConfig = function (config) {
  config.allowedContent = true;
  config.extraAllowedContent = "section;article;header;nav;aside;a;em;strong;cite;blockquote;code;ul;ol;li;dl;dt;dd;h3;h4;h5;h6;address;p;h2;hr;table;th;tr;td;i";
  config.scayt_sLang = 'en_GB';

  // Allow <i></i> empty tags.
  CKEDITOR.dtd.$removeEmpty['i'] = false;

  // Make source code wrap inside CKEditor.
  if (jQuery('#ckeditor-config-custom').length == 0) {
    jQuery('<style type="text/css" id="ckeditor-config-custom">.cke_source { white-space: pre-wrap !important;}</style>').appendTo(document.head);
  }
};
