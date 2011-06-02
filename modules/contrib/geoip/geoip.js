(function ($) {
  Drupal.geoip = {
    /**
     * Make a country lookup request.
     *
     * @param callback
     *   Callback function which will be called when the request completes.
     * @param param
     *   Optional, value that will be passed to the callback after the data.
     */
    lookupCountry: function(callback, param) {
      // Save a request if we've got the country stored in a cookie.
      cookie = Drupal.geoip.readCookie('geoip_country');
      if (cookie) {
        callback(cookie, param);
        return;
      }

      // If there's a debug IP address in URL, pass that back to the server.
      var url =  Drupal.settings.basePath + 'geoip/json/country',
        debug = /geoip_debug=(?:[0-9]+).(?:[0-9]+).(?:[0-9]+).(?:[0-9]+)/.exec(window.location.search);
      if (debug !== null) {
        url += '?'+ debug[0];
      }

      $.ajax({
        url: url,
        dataType: 'json',
        success: function(data) {
          var expires = null;
          if (Drupal.settings.geoip.lifetime) {
            expires = new Date();
            expires.setDate(expires.getDate() + Drupal.settings.geoip.lifetime);
          }
          Drupal.geoip.createCookie('geoip_country', data, expires);
          callback(data, param);
        }
      });
    },

    /**
     * Creates a cookie.
     *
     * @param name
     *   Name of the cookie.
     * @param value
     *   String value to store.
     * @param expires
     *   Optional Date object specifying when the cookie should expire.
     */
    createCookie: function(name, value, expires) {
      var cookie = name + "=" + value + "; path=" + Drupal.settings.basePath;
      if (expires && expires instanceof Date) {
        cookie += "; expires=" + expires.toGMTString();
      }
      document.cookie = cookie;
    },

    /**
     * Reads a cookie.
     *
     * @param name
     *   Name of the cookie.
     *
     * @return
     *   The value of the cookie, or null if none was found.
     */
    readCookie: function(name) {
      var nameEQ = name + '=',
        ca = document.cookie.split(';'),
        i, c;
      for (i = 0; i < ca.length; i++) {
        c = ca[i];
        while (c.charAt(0) === ' ') {
          c = c.substring(1,c.length);
        }
        if (c.indexOf(nameEQ) === 0) {
          return c.substring(nameEQ.length, c.length);
        }
      }
      return null;
    }
  };
}(jQuery));