function getCookie(c_name)
{
var i,x,y,ARRcookies=document.cookie.split(";");
for (i=0;i<ARRcookies.length;i++)
  {
  x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
  y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
  x=x.replace(/^\s+|\s+$/g,"");
  if (x==c_name)
    {
    return unescape(y);
    }
  }
}

function setCookie(c_name,value,exdays)
{
var exdate=new Date();
exdate.setDate(exdate.getDate() + exdays);
var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
document.cookie=c_name + "=" + c_value;
}

function surveryCookie()
{
var oldval=getCookie("accuray_survey_cookie");
if (isNaN(oldval))
{
oldval=0;
}
//alert(oldval);
var newval=parseInt(oldval)+1;
//alert(newval);
setCookie("accuray_survey_cookie",newval,30);
return newval;
}

$(function(){
	var surveyval = surveryCookie();
	var slideout = false;
	if(surveyval == "3"){
		slideout = true;
	}
	$('.slide-out-div').tabSlideOut({
			tabHandle: '.handle',                     //class of the element that will become your tab
			pathToTabImage: '/sites/all/themes/accuray/images/feedback.png', //path to the image for the tab //Optionally can be set using css
			imageHeight: '114px',                     //height of tab image           //Optionally can be set using css
			imageWidth: '16px',                       //width of tab image            //Optionally can be set using css
			tabLocation: 'right',                      //side of screen where tab lives, top, right, bottom, or left
			speed: 300,                               //speed of animation
			action: 'click',                          //options: 'click' or 'hover', action to trigger animation
			topPos: '200px',                          //position from the top/ use if tabLocation is left or right
			leftPos: '20px',                          //position from left/ use if tabLocation is bottom or top
			fixedPosition: true,                      //options: true makes it stick(fixed position) on scroll
			onLoadSlideOut: slideout
	});
			
});
