(function($, window) {
  'use strict';

  // Just make a hash to create a group per gallery.
  function hashCode(s) {
    return Math.abs(s.split('').reduce(function(a, b) {
      a = ((a << 5) - a) + b.charCodeAt(0);
      return a & a;
    }, 0)).toString();
  }

  function prepareGallery(user_id, gallery_title, element, plus) {
    var title_hash = hashCode(gallery_title);

    var gallery_style = element.data('display');
    if (gallery_style === undefined) {
      gallery_style = 'thumbs';
    }
    var thumb_count = element.data('thumbcount');
    if (thumb_count === undefined) {
      switch (gallery_style) {

        case 'singleimage':
          thumb_count = 1;
          break;

        case 'featureone':
          thumb_count = 5;
          break;

        default:
          thumb_count = 8;

      }
    }

    var title_element = element.data('titleelement');
    if (title_element === undefined) {
      title_element = 'h3';
    }

    // Callback function to create gallery markup.
    function createGallery(images) {
      var image;
      var thumb;
      var style = this.data('display');
      var thumb_count = this.data('thumbcount');
      var title_element = this.data('titleelement');
      var $ul = $('<ul></ul>');
      for (var j in images) {
        if (images.hasOwnProperty(j)) {
          image = images[j];
          if (image === null || typeof image !== 'object') {
            continue;
          }
          thumb = (j === '0' && (style === 'featureone' || style === 'singleimage')) ? 1 : 0;

          var img = $('<img/>')
            .attr('src', image.thumbs[thumb].url)
            .height(image.thumbs[thumb].height)
            .width(image.thumbs[thumb].width);
          var anchor = $('<a></a>')
            .attr('href', image.url)
            .attr('title', image.title)
            .attr('rel', 'gallery' + title_hash)
            .attr('class', 'picasa-gallery-thumb')
            .append(img);
          var li = $('<li></li>')
            .addClass((j >= thumb_count) ? 'hide' : '')
            .addClass(j === thumb_count - 1 ? 'last-visible' : '')
            .addClass(thumb === 1 ? 'gallery-featured' : '')
            .addClass(gallery_style)
            .append(anchor)
            .height(image.thumbs[thumb].height)
            .width(image.thumbs[thumb].width);
          $($ul).append(li);
        }
      }
      this.append($ul).addClass('picasa-gallery');
      this.before('<' + title_element + ' class="picasa-gallery-title">' + element.html() + '</' + title_element + '>');
      $('a[rel="gallery' + title_hash + '"]').butterfly();
    }

    // Picasa
    if (!plus) {
      // Query Picasa for albums and try to match the title we have.
      $.picasa.albums(user_id, function(albums) {
        var album;
        var href = element.attr('href');
        for (var i in albums) {
          if (albums.hasOwnProperty(i)) {
            album = albums[i];
            if (album.link === href) {
              var $ul = $('<div></div>');
              $ul.data('display', gallery_style);
              $ul.data('thumbcount', thumb_count);
              $ul.data('titleelement', title_element);
              $ul.picasaGallery(user_id, album.id, createGallery);
              element.replaceWith($ul);
            }
          }
        }
      });
      // Google plus
    }
    else {
      // we have the album ID so just go ahead and create the thumbnails
      var $ul = $('<div></div>');
      $ul.data('display', gallery_style);
      $ul.addClass(gallery_style);
      $ul.data('thumbcount', thumb_count);
      $ul.data('titleelement', title_element);
      $ul.picasaGallery(user_id, gallery_title, createGallery);
      element.replaceWith($ul);
    }
  }

  $(function() {
    // Stub deprecated $.browser so Butterfly's browser sniffs don't break.
    // We assume in doing this there is no need to target IE10+ in this way.
    if ($.browser === undefined) {
      $.browser = {
        msie: false
      };
    }

    // Select all A tags where the href matches picasaweb.google.com
    $('a[href*="picasaweb.google.com"].ext').each(function() {
      // 'this' === matched element
      var $el = $(this);
      var href = $el.attr('href');

      // Check if the HREF attribute matches the format of a Picasa gallery link
      var matches = href.match(/picasaweb\.google\.com\/([0-9]+)\/([^\/#\?]+)\/?$/);

      if (matches) {
        var user_id = matches[1];
        var gallery_title = matches[2];
        prepareGallery(user_id, gallery_title, $el, false);
      }
    });

    // Select all A tags where the href matches plus.google.com/photos
    $('a[href*="plus.google.com/photos"].ext').each(function() {
      // 'this' === matched element
      var $el = $(this);
      var href = $el.attr('href');

      // Check if the HREF attribute matches the format of a Google plus gallery link
      var matches = href.match(/plus\.google\.com\/photos\/([0-9]+)\/albums\/([0-9]+)\/?$/);

      if (matches) {
        var user_id = matches[1];
        var album = matches[2];
        prepareGallery(user_id, album, $el, true);
      }
    });
  });
}(window.jQuery, window));
