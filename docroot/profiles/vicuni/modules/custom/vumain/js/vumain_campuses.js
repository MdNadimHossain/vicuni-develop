/**
 * @file
 */

(function($, Drupal) {
  Drupal.behaviors.vumain_gmaps = {
    attach: function(context, settings) {

      var latLong = Drupal.settings.campus.lat_long;
      var customIcon = Drupal.settings.campus.map_marker;
      var customTitle = Drupal.settings.campus.title;
      var zoom = Drupal.settings.campus.zoom;
      var hide = Drupal.settings.campus.hide;
      var disableUI = Drupal.settings.campus.disableUI;
      // Set all campus markers by default.
      var allCampuses = Drupal.settings.campus.all_campuses;

      if (typeof latLong === 'undefined' || !latLong[0]) {
        return;
      }

      function map_init() {
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

        var map = new google.maps.Map(document.getElementById("campus-location-map"), mapOptions);
        
        if (hide) {
          map.setOptions({styles: styles['hide']});
        }

        // Change latitude to all campuses if present.
        if (typeof(allCampuses) !== 'undefined') {
          latLong = allCampuses;
        }

        var marker, markerTitle;
        for (var i = 0; i < latLong.length; i++) {
          // Load title.
          if (typeof(latLong[i].title) !== 'undefined') {
            markerTitle = latLong[i].title;
          } else {
            markerTitle = customTitle;
          }
          if (typeof latLong[i].address !== 'undefined' && latLong[i].address.length > 0) {
            markerTitle += ": " + latLong[i].address;
          }
          marker = new google.maps.Marker({
            position: new google.maps.LatLng(latLong[i].lat, latLong[i].long),
            map: map,
            icon: customIcon,
            title: markerTitle,
            animation: google.maps.Animation.DROP
          });
        }
      }

      google.maps.event.addDomListener(window, "load", map_init);

      $('.locations a').on('click', function(e) {
        e.preventDefault();
        var location = $(this);
        var nid = location.data('nid');

        $.ajax({
          url: '/campus/load/' + nid,
          type: 'GET',
          dataType: 'json',
          success: function(response) {
            latLong = response.campus.lat_long;
            customTitle = response.campus.title;
            zoom = response.campus.zoom;

            var campus_title = response.campus.campus_title;
            var campus_addr = response.campus.campus_addr;
            var campus_link = response.campus.title;

            location.parents().find('.locations a.active').removeClass('active');
            location.addClass('active');

            if (campus_title !== undefined) {
              location.parents().find('.location-title').html(campus_title);
            }

            if (campus_addr !== undefined) {
              location.parents().find('.location-addr').html(campus_addr);
            }

            if (campus_link !== undefined) {
              location.parents().find('.campus-link').attr("href", campus_link);
            }

            map_init();
          },
        });
        
      });
    }
  };
}(jQuery, Drupal));
