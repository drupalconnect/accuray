$Id

Rules Geocoder provides a geocoding action for the Rules module.
You can specify one or more CCK text fields that will be concatenated
and geocoded using the Google Maps API (v3). The result is then saved in an
OpenLayer CCK WKT field. 

A typical use case is when you have an node type containing an address comprised of multiple CCK
text fields (e.g. Street address, Zip, City, Country, etc.) that you want to
automatically geocode when saved. You can optionally specify a prefix or
suffix to help the geocoding (e.g. you can use the suffix "Stockholm,
Sweden" you know that all your content is located there).

Since the module is intended to be used instead of the regular
OpenLayers CCK map widget, an "Open Layers Hidden Value" widget is
provided that hides it from the node form. 

This module was written by Henrik Sjökvist // Newsfactory Media Group
