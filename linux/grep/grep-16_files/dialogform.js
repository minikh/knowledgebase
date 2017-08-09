function openDialogForm(holderId) {
	getDialogHolder(holderId).dialog('open');		
}

function initDialogForm(holderId) {
	getDialogHolder(holderId).dialog({
		autoOpen: false,
		/*autoResize: true,*/
	    position: ["top","center"],	    
	    show: 'slide',
	    hide: 'slide',    
		modal: true,
		closeText: '',
		closeOnEscape: false
	});  
}

function closeDialogForm(holderId) {
	getDialogHolder(holderId).dialog('close');		
}

function getDialogHolder(holderId) {
	if (holderId == null) {
		holderId = "uploadFormHolder"; 
	}
	return $("#" + holderId);		
}