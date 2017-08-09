var HELPER_IFRAME_ID = "IFrmHelper";
var LOADER_DIV_ID = 'dProgress';

function initLoadingProgressEl() {
	var oBody = document.getElementsByTagName("body").item(0);
	var oHelperIframe = document.createElement("div");
	oHelperIframe.setAttribute("id", HELPER_IFRAME_ID);
	oHelperIframe.style.border = 0;
	//oHelperIframe.width = 0;
	//oHelperIframe.height = 0;
	oHelperIframe.style.position = "absolute";
	var obj_val = document.createTextNode(" ");
	oHelperIframe.appendChild(obj_val);
	oBody.appendChild(oHelperIframe);
}

function getLoaderDivWidth(divId) {
	return document.getElementById(divId).offsetWidth;
}

function getLoaderDivHeight(divId) {
	return document.getElementById(divId).offsetHeight;
}

function showLoaderDiv() {
	var oHelperIframe = document.getElementById(HELPER_IFRAME_ID);
	
	if (!oHelperIframe) {
		throw new Error("001", "Can't find element with ID="+HELPER_IFRAME_ID);
	}
	
	var oDiv = document.getElementById(LOADER_DIV_ID);
	
	if (!oDiv) {
		throw new Error("001", "Can't find element with ID="+LOADER_DIV_ID);
	}
	
	var topDivZIndex = 10000;
	oDiv.style.zIndex = topDivZIndex;
	oHelperIframe.style.zIndex = topDivZIndex - 1000;
	topDivZIndex += 1;
	oHelperIframe.style.top = oDiv.style.top;
	oHelperIframe.style.left = oDiv.style.left;
	oHelperIframe.width = (getLoaderDivWidth(LOADER_DIV_ID));
	oHelperIframe.height = (getLoaderDivHeight(LOADER_DIV_ID));
	
	showme(HELPER_IFRAME_ID);
	showme(LOADER_DIV_ID);
}

function hideLoaderDiv(divId) {
	var oDiv = document.getElementById(divId);
	hideLoaderDivEl(oDiv);
}

function hideLoaderDivEl(oDiv) {
	var oHelperIframe = document.getElementById(HELPER_IFRAME_ID);
	oHelperIframe.style.visibility = 'hidden';
	oHelperIframe.style.display = 'none';
	oDiv.style.visibility = 'hidden';
	oDiv.style.display = 'none';
}

function moveLoaderDiv(divId, Xpos, Ypos) {
	var oHelperIframe = document.getElementById(HELPER_IFRAME_ID);
	var oDiv = document.getElementById(divId);
	Xpos = Math.round(Xpos);
	Ypos = Math.round(Ypos);

	oHelperIframe.style.top = (Ypos + 1) + "px";
	oHelperIframe.style.left = (Xpos + 1) + "px";
	oDiv.style.top = Ypos + "px";
	oDiv.style.left = Xpos + "px";
}

function showLoadingProgress(obj) {
	var x = 0;
	var y = 0;
	var winW = 200;
	var winH = 200;
	
	var isDOM = document.getElementById;
	var isOpera = window.opera && isDOM;
	var isIE6 = false /*@cc_on || @_jscript_version < 5.7 @*/;
	
	if (parseInt(navigator.appVersion) > 3) {
		if (navigator.appName=="Netscape" || isOpera) {
			winW = window.innerWidth;
			winH = window.innerHeight;
	 	} 
	 	
	 	if (navigator.appName.indexOf("Microsoft") != -1) {
			winW = document.body.offsetWidth;
			winH = document.documentElement.clientHeight; //IE7
//			winH = document.body.offsetHeight; //pre-IE7
	 	}
		
		if (obj) {
  			x = winW / 2 - 50 + posLeft();
  			y = winH / 2 - 50 + posTop();
  		}
  	} else if (obj) {
		var x = findPosX(obj);
		var y = findPosY(obj);
	}
	
	x = x - 100;
	y = (isIE6) ? y : y/2

	moveLoaderDiv(LOADER_DIV_ID, x, y);
	showLoaderDiv();
}

function hideLoadingProgress() {
	hideLoaderDiv(LOADER_DIV_ID);
}