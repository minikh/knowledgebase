/**
 * onBeforeUnload action 
 *
 */
 
var UNLOAD_MSG = "Файл еще до конца не загружен на сервер. Хотите прервать загрузку?";

var IGNORE_UNLOAD = true;

function doBeforeUnload() {
	if (IGNORE_UNLOAD) {
		return; // Let the page unload
	}

	if (window.event) {
		window.event.returnValue = UNLOAD_MSG; // IE
	} else {
		return UNLOAD_MSG; // FX
	}
}

if (window.body) {
	window.body.onbeforeunload = doBeforeUnload; // IE
} else {
	window.onbeforeunload = doBeforeUnload; // FX
}