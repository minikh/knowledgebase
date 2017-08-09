var ie67 = ''; // IE 6 or 7 version
function onTinyMCE() {
	var memoFF='';
	if (navigator.userAgent.indexOf('Firefox')!=-1) {
		memoFF=document.getElementById('memo').value
	};
	tinyMCE.execCommand('mceToggleEditor', true, 'memo');
	$('#memo').markItUpRemove();
	if (memoFF!='') {
		tinyMCE.activeEditor.setContent(memoFF);
	}	
	if (navigator.userAgent.indexOf('MSIE')>-1) {
		setTimeout("tinymce.execCommand('mceFocus', false, tinymce.activeEditor.editorId)", 100);
	} else {
		tinymce.execCommand('mceFocus', false, tinymce.activeEditor.editorId);
	}
	document.getElementById('editor').value='tinymce';	
	setAttribute('tinymceEditor', 'class', 'tinyMceTabActive');
	setAttribute('markitupEditor', 'class', 'markItUpTabPassive');
	setAttribute('tinymceEditor', 'onclick', 'return false;');
	setAttribute('markitupEditor', 'onclick', 'onMarkItUp();');
	changeEditorHelp();
	return false;
}
	
function onMarkItUp() {
	tinyMCE.execCommand('mceToggleEditor', false, 'memo');
	$('#memo').markItUp(articleSettings);
	$('#memo').css({height: '659px'});
	if (navigator.userAgent.indexOf('Firefox')>-1 || navigator.userAgent.indexOf('MSIE')>-1) {
		setTimeout("$('#memo').focus()", 100);
	} else {
		$('#memo').focus();
	}
	document.getElementById('editor').value='markitup';
	setAttribute('tinymceEditor', 'class', 'tinyMceTabPassive');
	setAttribute('markitupEditor', 'class', 'markItUpTabActive');
	setAttribute('markitupEditor', 'onclick', 'return false;');
	setAttribute('tinymceEditor', 'onclick', 'onTinyMCE();');
	changeEditorHelp();
	return false;
}

function changeEditorHelp() {
	var help1 = document.getElementById('editorHelp1').innerHTML;
	document.getElementById('editorHelp1').innerHTML = document.getElementById('editorHelp2').innerHTML;
	document.getElementById('editorHelp2').innerHTML = help1;
}

function setAttribute(elementId, attrName, attrValue) {
	if (isIEold()==false) {
		document.getElementById(elementId).setAttribute(attrName, attrValue);
	} else {
		// IE 6,7 cannot process setAttribute
		if (attrName=='class') {		
			document.getElementById(elementId).className = attrValue;
		} else {
			if (attrName=='onclick') {	
				document.getElementById(elementId).onclick = new Function( attrValue );
			} else {
				document.getElementById(elementId).setAttribute(attrName, attrValue);  // but dont work for IE6,7
			}
		}	
	}
}

function isIEold() {
	if (ie67 == '') {
		ie67 = false;
		/*@cc_on
		@if (@_jscript_version <= 5.7)
   			ie67 = true;
		@end
		@*/
	}
	return ie67;
}

function checkTab(event)
{
  // First we check if the key pressed was a tab
  if (event.keyCode == 9)
  { 
    // Is this IE?
    if (navigator.appName == 'Microsoft Internet Explorer')
    {
      // This stops the default behavior of the tab key. preventDefault does not work in IE.
      event.returnValue = false;
      // This gets the current selection or cursor location
      range = document.selection.createRange();
      // Replaces the current selection with a tab character or simply inserts it at the current cursor position
      range.text = "\t";
      // This resets the selection
      range.collapse(true);
      // And this executes above statement.
      range.select();
    }
    else
    {
      // This stops the default behavior of the tab key
      event.preventDefault();
      // We need to save the current position of the cursor.
      var c = event.target.selectionStart;
      // Inserting a tab into the string.
      // First we grab what comes before the current selection (or cursor position).
      // Then we add the tab character. Finally we add the part the comes after the
      // current selection (or cursor position).
      event.target.value = event.target.value.slice(0,event.target.selectionStart).concat("\t").concat(event.target.value.slice(event.target.selectionEnd,event.target.value.length));
      // This sets the cursor position.
      event.target.selectionStart = c + 1;
      // And this cancels selection. Opera requires that this is on a seperate line.
      event.target.selectionEnd = c + 1;
    }
  }
}
 
function operaTab(event)
{
  if (navigator.appName == 'Opera' && event.keyCode == 9)
  {
      // This stops the default behavior of the tab key
      // Opera is unable to do that when called from onkeydown
      event.preventDefault();
  }
}

var lastAutosaveTime;
var autosaveInProgress = false;

function initAutosaveTimer(contextPath) {
	lastAutosaveTime = (new Date()).getTime();
	setInterval("checkAndAutosave('" + contextPath + "')", 30*1000);
	setInterval("updateAutoSaveHint()", 30*1000);
}

function checkAndAutosave(contextPath) {
	if (autosaveInProgress) {
		return;
	} 
	autosaveInProgress = true;
	try {
		var sel = document.getElementById('autosavePeriod'); 
		var periodMinutes = sel.value;
		
		var nowTime = (new Date()).getTime();
		if (nowTime > lastAutosaveTime + (periodMinutes * 60 * 1000)) {
		
			showLoadingProgress(document.getElementById("defaultDisplayElement"));
			
			onSubmitArticleForm();
			
			var sf = document.forms['f_article_edit']; 
			var df = document.forms['autosave_form'];
			
			df.subject.value = sf.subject.value;
			df.memo.value = sf.memo.value; 
			df.originalLink.value = sf.originalLink.value;
			
			df.submit();
			
			lastAutosaveTime = nowTime;
						
			updateAutoSaveHint(true);
		}
	} catch (e) {
		// do nothing
	}
	hideLoadingProgress();
	autosaveInProgress = false;
}

function updateAutoSaveHint(forceUpd) {
	var hintEl = document.getElementById('autosaveHintText');
	if (hintEl.innerHTML != "" || forceUpd != null) {
		var currentDate = new Date(); 
		var timeDiffMn = (currentDate.getTime() - lastAutosaveTime) / 1000 / 60;
		
		var autosaveDate = new Date();
		autosaveDate.setTime(lastAutosaveTime);

		var minutes = autosaveDate.getMinutes();
		if (minutes < 10) {
			minutes = "0" + minutes;
		}
		var txt = "Черновик сохранен в " + autosaveDate.getHours() + ":" + minutes;
		if (parseInt(timeDiffMn) > 0) {
			txt = txt + " (" + parseInt(timeDiffMn) + " мин назад)"; 
		}
		hintEl.innerHTML = txt; 
	}
}