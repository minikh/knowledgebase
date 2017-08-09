function openDropDownMenu(dropDownElement, dropDownHolder) {
	$('#'+dropDownElement).slideDown(50).show();
	$('#'+dropDownHolder).hover(function() {
	}, function(){
		$('#'+dropDownElement).slideUp(600);
	});
}

function openDropDownMenuForAuthors(dropDownElement, dropDownHolder) {
	var isOldIE = false;  // true if IE6 or IE7
	/*@cc_on
		@if (@_jscript_version <= 5.7)
   			isOldIE = true;
		@end
	@*/
	var $startLeftColumnOverflow=$('#leftColumn').css("overflow");
	if ($startLeftColumnOverflow!='visible') {
		$('#leftColumn').css("overflow", "visible");
	}
	var id = parseInt(dropDownElement.replace(/\D/g, ''), 10);  //detect element id
	if (isOldIE && id>0) {		
		$('#'+id).css('display', 'none');
	}

	$('#'+dropDownElement).slideDown(50).show();
	$('#'+dropDownHolder).hover(function() {
	}, function(){
		$('#'+dropDownElement).slideUp(600);
		if ($startLeftColumnOverflow!='visible') {
			$('#leftColumn').css("overflow", $startLeftColumnOverflow);
		}
		if (isOldIE && id>0) {			
			$('#'+id).css('display', 'inline');
		}	
	});
}
