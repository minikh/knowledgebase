var localizedMessages = {};

function $(id) {
	var el = document.getElementById(id);
	
	if (!el) {
		var err = new Error('getElementById ERROR', 'Can not find the element with ID=' + id);
		err.name = 'getElementById ERROR';
		throw (err);
	}
	
    return el;
}

function hideElem(el) {
	el.style.display = 'none';
	el.style.visibility = 'hidden';	
}

function showElem(el) {
	el.style.display = 'block';
	el.style.visibility = 'visible';
}


function hideme(divId) {
	var oDiv = document.getElementById(divId);
	if (oDiv == null) {
		alert(divId + " is null");	
	} else {
		hideElem(oDiv);	
	}
}

function showme(divId) {
	var oDiv = document.getElementById(divId);
	if (oDiv == null) {
		alert(divId + " is null");	
	} else {
		showElem(oDiv);
	}
}

function toggleme(divId) {
	var oDiv = document.getElementById(divId);	
	if (oDiv.style.display == 'block') {
		hideme(divId);
	} else {
		showme(divId);
	}	
}

function copyToClipboard(inputId) {
    var input = document.getElementById(inputId);
    input.select();
    if (navigator.appName != "Microsoft Internet Explorer") {
		alert("Ваш браузер не поддерживает функцию копирования текста. Пожалуйста, скопируйте адрес ролика вручную");
		return;
	}
 	copiedTxt = document.selection.createRange();
    copiedTxt.execCommand("Copy");
}

function ctrlEnter(event) {
	var pressed = false;
	if((event.ctrlKey) && ((event.keyCode == 0xA)||(event.keyCode == 0xD))) {  
		pressed = true;   
	}
	return pressed;
}

function capitalize(str) {
	return str.charAt(0).toUpperCase() + str.substr(1);
}

function clearHolder(id) {
	var el = document.getElementById(id);
	
	if (!el) {
		var err = new Error('001', 'Can not find the element with ID=' + id);
		err.name = 'getElementById error';
		throw (err);
	} else {
		el.innerHTML = "";
	}
}
  
function addFormEventHandler( obj, type, fn ) {
  if ( obj.attachEvent ) {
    obj['e'+type+fn] = fn;
    obj[type+fn] = function(){obj['e'+type+fn]( window.event );};
    obj.attachEvent( 'on'+type, obj[type+fn] );
  } else
    obj.addEventListener( type, fn, false );
} 

function cleanFileInput(outerElemId, fileElem) {
	if (fileElem.value != '') {
		var isIE = /msie/i.test(navigator.userAgent) && !/opera/i.test(navigator.userAgent);
		if (!isIE) {
			fileElem.value = '';		
		} else { 
			var outerElem = document.getElementById(outerElemId);
			if (outerElemId == fileElem.parentNode.id) {		
				outerElem.innerHTML = outerElem.innerHTML.replace('value="' + fileElem.value + '"', 'value=""');
			} else {
				var len = outerElem.childNodes.length;
				for (var i = 0; i < len; i++) {           
					if (outerElem.childNodes[i].id == fileElem.parentNode.id) {
						var innerElem = outerElem.childNodes[i];
						innerElem.innerHTML = innerElem.innerHTML.replace('value="' + fileElem.value + '"', 'value=""');				
						break;
					}
				}
			}
		}
	}
}

function isValidURL(url){
    var RegExp = /^(http+:\/\/)([\d\w]+\.){0,2}([\d\w][-\d\w]{0,253}[\d\w]\.)+([\w]{2,4}|travel|museum)(:[\d]+)?(\/([-+_~.\d\w]|%[a-fA-f\d]{2,2})*)*(\?(&?([-+_~.\d\w]|%[a-fA-f\d]{2,2})=?)*)?(#([-+_~.\d\w]|%[a-fA-f\d]{2,2})*)?$/;
    if (RegExp.test(url)) {
        return true;
    } else {
        return false;
    }
} 

//Browser Window Size and Position
//http://javascript.about.com/od/guidesscriptindex/a/screen.htm

function pageWidth() {
	return window.innerWidth != null? window.innerWidth : 
		document.documentElement && document.documentElement.clientWidth ?  document.documentElement.clientWidth : document.body != null ? document.body.clientWidth : null;
} 

function pageHeight() {
	return  window.innerHeight != null? window.innerHeight : 
		document.documentElement && document.documentElement.clientHeight ? document.documentElement.clientHeight : document.body != null? document.body.clientHeight : null;
} 

function posLeft() {
	return typeof window.pageXOffset != 'undefined' ? window.pageXOffset : 
		document.documentElement && document.documentElement.scrollLeft ?   document.documentElement.scrollLeft : document.body.scrollLeft ? document.body.scrollLeft : 0;
} 

function posTop() {
	return typeof window.pageYOffset != 'undefined' ?  window.pageYOffset : 
		document.documentElement && document.documentElement.scrollTop ?    document.documentElement.scrollTop : document.body.scrollTop ? document.body.scrollTop : 0;
} 

function posRight() {
	return posLeft()+pageWidth();
} 

function posBottom() {
	return posTop()+pageHeight();
}

/**
 * Escaped dots in the elemnt id - needs for jQuery
 * 
 * @param myid
 * @return
 */
function jqID(myid) { 
	return myid.replace(/(:|\.)/g,'\\$1');
}

/**
 * Calculates element position.
 * 
 * @param myid
 * @return
 */
function getOffset(elem) {
	var offsetObj;
    if (elem.getBoundingClientRect) {
        offsetObj = getOffsetRect(elem);
    } else {
    	offsetObj = getOffsetSum(elem);
    }
    return offsetObj;
}

function getOffsetSum(elem) {
    var top=0, left=0;
    while(elem) {
        top = top + parseInt(elem.offsetTop);
        left = left + parseInt(elem.offsetLeft);
        elem = elem.offsetParent;
    }

    return {top: top, left: left}
}

function getOffsetRect(elem) {
    var box = elem.getBoundingClientRect();

    var body = document.body;
    var docElem = document.documentElement;

    var scrollTop = window.pageYOffset || docElem.scrollTop || body.scrollTop;
    var scrollLeft = window.pageXOffset || docElem.scrollLeft || body.scrollLeft;

    var clientTop = docElem.clientTop || body.clientTop || 0;
    var clientLeft = docElem.clientLeft || body.clientLeft || 0;

    var top  = box.top + scrollTop - clientTop;
    var left = box.left + scrollLeft - clientLeft;

    return { top: Math.round(top), left: Math.round(left) }
}

/**
 * Set focus by ID for some element.
 */
function setFocus(id) {
	if (id != 'undefined' && id != '') {
		document.getElementById(id).focus();
	}
}

function jump2Anchor(id) {
	if (id != 'undefined' && id != '') {
		window.location.hash=id;
	}
}

/*
 * Return GET value by parameter name
 */
function getParameter(name) {
  name = name.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");
  var regexS = "[\\?&]"+name+"=([^&#]*)";
  var regex = new RegExp(regexS);
  var results = regex.exec(window.location.href);
  if (results == null)
    return "";
  else
    return results[1];
}

/*
 * Sets cookie value
 */
function Set_Cookie(name, value, expires, path, domain, secure) {
	// set time, it's in milliseconds
	var today = new Date();
	today.setTime(today.getTime());
	// if the expires variable is set, make the correct expires time, the
	// current script below will set it for x number of days, to make it
	// for hours, delete * 24, for minutes, delete * 60 * 24
	if (expires)
	{
		expires = expires * 1000 * 60 * 60 * 24;
	}
	//alert('today ' + today.toGMTString());// this is for testing purpose only
	var expires_date = new Date(today.getTime() + (expires));
	//alert('expires ' + expires_date.toGMTString());// this is for testing purposes only

	document.cookie = name + "=" +escape(value) +
		((expires) ? ";expires=" + expires_date.toGMTString() : "") + //expires.toGMTString()
		((path) ? ";path=" + path : "") + 
		((domain) ? ";domain=" + domain : "") +
		((secure) ? ";secure" : "");
}

/*
 * Gets cookie value
 */
function Get_Cookie(check_name) {
	// first we'll split this cookie up into name/value pairs
	// note: document.cookie only returns name=value, not the other components
	var a_all_cookies = document.cookie.split(';');
	var a_temp_cookie = '';
	var cookie_name = '';
	var cookie_value = '';
	var b_cookie_found = false; // set boolean t/f default f
	
	for (i = 0; i < a_all_cookies.length; i++)
	{
		// now we'll split apart each name=value pair
		a_temp_cookie = a_all_cookies[i].split('=');
		
		
		// and trim left/right whitespace while we're at it
		cookie_name = a_temp_cookie[0].replace(/^\s+|\s+$/g, '');
	
		// if the extracted name matches passed check_name
		if (cookie_name == check_name)
		{
			b_cookie_found = true;
			// we need to handle case where cookie has no value but exists (no = sign, that is):
			if (a_temp_cookie.length > 1)
			{
				cookie_value = unescape(a_temp_cookie[1].replace(/^\s+|\s+$/g, ''));
			}
			// note that in cases where cookie is initialized but no value, null is returned
			return cookie_value;
			break;
		}
		a_temp_cookie = null;
		cookie_name = '';
	}
	if (!b_cookie_found)
	{
		return null;
	}
}

/*
 * Deletes cookie
 */
function Delete_Cookie(name, path, domain) {
	if (Get_Cookie(name)) document.cookie = name + "=" +
			((path) ? ";path=" + path : "") +
			((domain) ? ";domain=" + domain : "") +
			";expires=Thu, 01-Jan-1970 00:00:01 GMT";
}

function checkCookies() {
	Set_Cookie('test', 'none', '', '/', '', '');
	if (Get_Cookie('test')) {
		Delete_Cookie('test', '/', '');
	} else {
		alert('Для корректной роботы сайта необходимо включить Cookies!');
		return false;
	}
	return true;
}

function getNoticeText(txt) {
	return '<p class="notice">' + txt + '</p>'
}