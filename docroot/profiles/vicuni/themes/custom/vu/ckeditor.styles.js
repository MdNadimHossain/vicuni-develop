/**
 * @file
 Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
 For licensing, see LICENSE.html or http://ckeditor.com/license.
 */

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if (typeof(CKEDITOR) !== 'undefined') {
  CKEDITOR.addStylesSet('drupal',
    [
      {name: 'Facebook', element: 'a', attributes: {'class': 'facebook'}},
      {name: 'Youtube', element: 'a', attributes: {'class': 'youtube'}},
      {name: 'Twitter', element: 'a', attributes: {'class': 'twitter'}},
      {name: 'Linkedin', element: 'a', attributes: {'class': 'linkedin'}},
      {
        name: 'Chat link wrapper',
        element: 'p',
        attributes: {'class': 'chat-link'}
      },
      {name: 'Text lead', element: 'p', attributes: {'class': 'text-lead'}}
    ]);
}
