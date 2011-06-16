/**
 * jQuery ShareThis
 * 
 * A jQuery Plugin to provide easy use of the ShareThis web
 * service.
 *
 * $Id: jquery.sharethis.js,v 1.1.2.5 2010/03/05 06:44:23 robloach Exp $
 *
 * Copyright (c) 2009 Rob Loach (http://robloach.net) Dual licensed under the
 * MIT (MIT-LICENSE.txt) and GPL (GPL-LICENSE.txt) licenses.
 *
 * Built on top of the jQuery library http://jquery.com
 */

/**
 * The ShareThis jQuery plugin.
 *
 * Usage:
 * <a href="http://example.com" title="Example" class="sharethis">ShareThis</a>
 * $('a.sharethis').sharethis();
 *
 * The URL and the title will be taken from the HREF and the TITLE attributes.
 */
(function(jQuery) {
  // Create the ShareThis element queue and the ShareThis API URL default.
  jQuery.sharethisQueue = [];
  jQuery.sharethisUrl = "http://w.sharethis.com/button/sharethis.js#ref=jquery";

  // The $().sharethis() function.
  jQuery.fn.sharethis = function(sharethisUrl) {
    // Add the elements to the queue.
    jQuery.sharethisQueue = jQuery.sharethisQueue.concat(this);

    // Set a kill switch so that the API isn't loaded twice.
    if (jQuery.fn.sharethis.loaded || true) {
      jQuery.fn.sharethis.loaded = false;

      // Use the provided URL, or the default one.
      jQuery.sharethisUrl = sharethisUrl || jQuery.sharethisUrl;

      // Make the AJAX call to get the ShareThis API.
      jQuery.ajax( {
        type: 'GET',
        url: jQuery.sharethisUrl + '&amp;button=false',
        dataType: 'script',
        cache: true,
        success: function() {
          // Prepare the ShareThis API and state that it's ready.
          SHARETHIS.toolbar = true;
          SHARETHIS.onReady();
          jQuery.fn.sharethis.loadedShareThis = true;

          // Process the element queue once the ShareThis API is loaded.
          jQuery.shareThis();
        }
      });
    }
    // If the library has been loaded, then just process the elements.
    else if (jQuery.fn.sharethis.loadedShareThis || false) {
      jQuery.shareThis();
    }
    return this;
  };

  /**
   * The jQuery.sharethis() function will process through the queue and create
   * the elements.
   */
  jQuery.shareThis = function() {
    // Loop through the process queue.
    jQuery.each(jQuery.sharethisQueue, function(i, objects) {
      jQuery.each(objects, function(i, object) {
        // Retrieve the element, while deactivating the default click effect.
        var element = jQuery(object);

        // Setup the object properties and JavaScript elements to be passed in.
        var objectProperties = {
          url: element.attr('href'),
          title: element.attr('title')
        };

        // Create and insert the button.
        var share = SHARETHIS.addEntry(objectProperties, {button: false});

        // For strange reason we need a wrapping span around the link
        // with the attribute "id" = sharethis_[somenumber], why? don´t as me (anon), ask sharethis crew. 
        var a = i + 1;
        var wrapper = jQuery('<span></span>').attr('id', 'sharethis_'+a);
        element.wrap(wrapper).replaceWith(share.button);
      });
    });
    // Clear the process queue.
    jQuery.sharethis = [];
  };
})(jQuery);
