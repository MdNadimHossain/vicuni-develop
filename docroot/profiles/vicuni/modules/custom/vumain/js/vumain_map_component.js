/**
 * @file
 */

(function($, Drupal) {
  Drupal.behaviors.vumain_map_component = {
    attach: function(context, settings) {
      if (!$('.map-component').length) {
        return;
      }

      var customIcon = Drupal.settings.mapComponent.map_marker;
      var customTitle = Drupal.settings.mapComponent.title;
      var zoom = Drupal.settings.mapComponent.zoom;
      var hide = Drupal.settings.mapComponent.hide;
      var disableUI = Drupal.settings.mapComponent.disableUI;
      // Set all campus markers by default.
      var allCampuses = Drupal.settings.mapComponent.all_campuses;
      var markers = [];
      var map;
      var infowindow = new google.maps.InfoWindow;

      // Change latitude to all campuses if present.
      if (typeof(allCampuses) !== 'undefined') {
        var latLong = allCampuses;
      }

      if (latLong === null || typeof latLong === 'undefined' || !latLong[0]) {
        return;
      }

      function initialize() {
        var mapOptions = {
          scrollwheel: false,
          zoom: zoom,
          center: new google.maps.LatLng(latLong[0].lat, latLong[0].long),
          mapTypeId: google.maps.MapTypeId.ROADMAP,
          disableDefaultUI: disableUI,
          width: 'auto',
          height: 'auto'
        };

        var styles = {
          hide: [
            {
              featureType: 'poi.business',
              stylers: [{visibility: 'off'}]
            },
            {
              featureType: 'transit',
              elementType: 'labels.icon',
              stylers: [{visibility: 'off'}]
            }
          ]
        }; 

        if ($('#map-component-section').length){
          map = new google.maps.Map($('#map-component-section')[0], mapOptions);
          if (hide) {
            map.setOptions({styles: styles['hide']});
          }
        }
        var marker, markerTitle, content;
        var bounds = new google.maps.LatLngBounds();
        $.each(latLong, function(index, latLong) {
          // Load title.
          markerTitle = typeof(latLong.title) !== 'undefined' ? latLong.title : customTitle;
          var linkTitle = markerTitle;
          if (typeof latLong.address !== 'undefined' && latLong.address.length > 0) {
            markerTitle = (markerTitle === false) ? latLong.address : markerTitle + ":<br> " + latLong.address;
          }

          marker = new google.maps.Marker({
            position: new google.maps.LatLng(latLong.lat, latLong.long),
            map: map,
            icon: customIcon,
            animation: google.maps.Animation.DROP,
            title: linkTitle,
          });

          markers.push(marker);
          // Adding info window on marker click.
          content = '<div id="marker-Pin-info" style="display:table" aria-hidden="true">' + markerTitle + '<br><a href="https://www.google.com/maps?daddr=' + latLong.lat + ',' + latLong.long + '" target="_blank">Get directions</a></div>';
          google.maps.event.addListener(marker,'click', (function(marker, content, infowindow){
            return function() {
              infowindow.setContent(content);
              infowindow.open(map, marker);
              map.setCenter(marker.getPosition());
              map.setZoom(18);

              // Add active to link.
              var linkTitle = marker.getTitle();
              if (linkTitle !== undefined) {
                $('.place-name .location-title').filter(function() {
                  return $(this).text().trim() == linkTitle;
                }).closest('li').addClass('active');
              }
            };
          })(marker, content, infowindow));
          // Getting area of all markers.
          bounds.extend(marker.getPosition());
        });

        // Showing all markers on first load.
        if (latLong.length > 1) {
          map.fitBounds(bounds);
        }
        infowindow.open(map);
      }

      google.maps.event.addDomListener(window, "load", initialize);

      // Things to do when individual location div are clicked.
      $('.map-component-places ul li').on('click', function(e) {
        e.preventDefault();
        var location = $(this);
        // Setting active class.
        location.parents().find('.map-component-places ul li.active').removeClass('active');
        // Getting lat & long of clicked div location.
        var nid = location.find('a').data('lat-long');
        var arr = nid.split(',');
        // Trigger info window.
        var marker = getLocation(markers, parseFloat(arr[0]).toFixed(4), parseFloat(arr[1]).toFixed(4));
        if (marker !== undefined) {
          google.maps.event.trigger(marker, 'click');
        }
        window.open('#map-component-section','_self');

        // scroll to map container.
        var target = $('.sticky-header').data('offset-top');
        if (target === undefined) {
          target = 0;
        }
        $('html, body').animate({
          scrollTop: $('#map-component-container').offset().top - target
        }, 'slow');
      });

      function getLocation(markers, lat, long) {
        var marker;
        $.each(markers, function(index, location) {
          if (location.position.lat().toFixed(4) == lat && location.position.lng().toFixed(4) == long) {
            marker = location;
            return false;
          }
        });
        return marker;
      }
    },
  };
}(jQuery, Drupal));
