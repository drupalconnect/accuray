Drupal.behaviors.divHeight = function (context) {
  
  var sidebarFirst = $(".region-sidebar-first");
  var sidebarFirstSection = $(".region-sidebar-first .section");
  var content = $("#content");  
  
  if (content.height() < sidebarFirst.height()) {
    return FALSE;
  }
  
  var offset = sidebarFirst.height() - sidebarFirstSection.height();
  
  var toHeight = content.height() - offset;

  sidebarFirstSection.height(toHeight);
}