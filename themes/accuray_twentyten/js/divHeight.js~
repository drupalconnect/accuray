Drupal.behaviors.divHeight = function (context) {
  var lengths = [];

  lengths.push($(".region-sidebar-first").height());
  lengths.push($("#content").height());
  lengths.push($(".region-sidebar-second").height());
  
  var max = lengths[0];
  
  $(lengths).each(function(i, val){
    console.log(val);
    if (val > max) {
      max = val;
    }
  });
  
  var offset = $("#content").height() - $("#content .section").height();
  $("#content .section").css({"min-height": max - offset});
  
  var offset = $(".region-sidebar-first").height() - $(".region-sidebar-first .section").height();
  $(".region-sidebar-first .section").css({"min-height": max - offset});
  
  var offset = $(".region-sidebar-second").height() - $(".region-sidebar-second .section").height();
  $(".region-sidebar-second .section").css({"min-height": max  - offset});

}