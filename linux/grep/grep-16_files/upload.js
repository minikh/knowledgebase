function initUploadActions() {
	Gallery.addOnAfterActionHandler('loadSimpleContent', function(reqUri, dispId, contextPath) {		
		if (dispId == 'uploadFormHolder') {
			openDialogForm('uploadFormHolder');
		}
	});
}

function toggleUploadFormFields() {
	
	if (document.getElementById("uploadLabel1").checked) {
		showme('uploadFileInput'); 
		hideme('uploadFromInetInput');
				
	} else if (document.getElementById("uploadLabel2").checked) {
		
		var fileElem = document.getElementById("file");
		if (fileElem != null) {
			cleanFileInput('uploadFileInput', fileElem);
		}
		
		hideme('uploadFileInput'); 
		showme('uploadFromInetInput');
		
		document.getElementById("uplUrl").value = '';
	} 
}

function loadUploadForm(type, selector, textEditor, contextPath, paramString) {	
	var uri = 'ajax/uploadform/show?type=' + type+"&textEditor=" + textEditor + "&" + paramString;
	Gallery.loadSimpleContent(uri, selector, contextPath)
}

function validateUploadForm() {	
	/*if (document.getElementById("uploadLabel2").checked) {
		var urlInput = document.getElementById("uplUrl");	
		// trim the url
		urlInput.value = urlInput.value.replace(/^\s+|\s+$/g, '');
		if (urlInput.value == '') {
			alert('Выбран пустой адрес (URL)');			
			return false;
		} else if (!isValidURL(urlInput.value)) {
			alert('Неверный формат адрес (URL)');
			return false;
		}
	} else {
		var fileInput = document.getElementById("file");
		if (fileInput.value == '') {
			alert('Не выбран файл с изображением');
			return false;
		}		
	}*/
	return true;
}

function showAllErrors(allErrors) {
	var e = document.getElementById("uploadErrorMsg");
	e.style.display = "block";
	e.style.visibility = "visible";
	e.innerHTML = allErrors;
}
function cleanAllErrors() {
	var e = document.getElementById("uploadErrorMsg");
	e.innerHTML = "";
	e.style.display = "none";
	e.style.visibility = "hidden";
}	
function hideUploadProgress() {
	document.getElementById("upload_progress").style.display = 'none';
}
function setContentOk(ed) {			
	tinymce.dom.Event.add(tinyMCE.activeEditor.getDoc(), 'keyup', function(e) {
       	rememberCursorPos();
    });			
}
function insertUploadedPhoto(imgUrl, contextPath, editor) {
	var imgSrc = contextPath + imgUrl;
	var imgTag = '<img src="' + imgSrc + '" alt="" />';
	if (editor == "tinymce") {
		insertAtCursorPos(imgTag);
	} else {   // markitup	
		$.markItUp({ replaceWith: imgTag});
	}
}

function insertUploadedVideo(imgUrl, type, contextPath, editor) {
	var imgSrc = contextPath + imgUrl;
	var sizes = '';
	if (type == 1) {
		sizes = 'width="640" height="390"';
	} else if (type == 2) {
		sizes = 'width="400" height="353"';
	}
	var imgTag = '<img src="' + imgSrc + '" alt="" ' + sizes + ' /><br />';
	if (editor == "tinymce") {
		insertAtCursorPos(imgTag);
	} else {	// markitup
		$.markItUp({ replaceWith: imgTag});
	}	
}

function insertUploadedCode(form, editor) {
	var currentForm = document.forms[form];
	var errorMessage = "";
    var code = document.forms[form].uplCode.value;
    if (code == "") {
    	errorMessage = "Введите код";    	
    }
    var codeLang = document.forms[form].uplCodeLang.value;       
    var codeFirstLine = document.forms[form].uplCodeFirstLine.value;    
    var reg = /^\d*$/;
    if (!reg.test(codeFirstLine)) {
    	errorMessage = addErrorMessage(errorMessage, "Начальное значение для нумерации строк должно быть целым числом либо без значения (если нумерация не нужна)");    		
    }
    var codeHighlight = document.forms[form].uplCodeHighlight.value;
    reg = /^[\d,]*$/;
    if (!reg.test(codeHighlight)) {
    	errorMessage = addErrorMessage(errorMessage, "Значение нумерации строк для подсветки должно содержать целые числа, разделенные запятыми, либо быть без значения (если подсветка не нужна)");    	    	
    }
	var codeTabSize = document.forms[form].uplCodeTabSize.value;
	reg = /^\d+$/;
	if (!reg.test(codeTabSize)) {
		errorMessage = addErrorMessage(errorMessage, "Размер табуляции должен быть целым числом");
    }
	if (errorMessage != "") {
		document.getElementById("uploadErrorMsg").innerHTML = errorMessage;
   		return;
   	}
    var codeTag = '<pre class="brush: ' + codeLang + ';';
	if (codeFirstLine == "") {
		codeTag += 'gutter: false;';
	} else {
		codeTag += 'gutter: true;';
		codeTag += 'first-line: ' + codeFirstLine + ';';
	}
	if (codeHighlight != "") {
		codeTag += 'highlight: [' + codeHighlight + '];';
	}
	codeTag += 'tab-size: ' + codeTabSize + ';';
	codeTag += 'toolbar: false;';
	codeTag += '">';
	codeTag +=  code.replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;");
	codeTag += '</pre>';
   	
	window.parent.closeDialogForm('uploadFormHolder');
	
	if (editor == "tinymce") {
		insertAtCursorPos(codeTag);
	} else {   // markitup
		$.markItUp({ replaceWith: codeTag});
	}
}


function addErrorMessage(summaryErrorMessage, errorMessage) {
	if (summaryErrorMessage != "") {
		summaryErrorMessage += "<br>" + errorMessage;    		
   	} else {
		summaryErrorMessage = errorMessage;
	}
	return summaryErrorMessage;
}

function insertAtCursorPos(text) {
	if (cursorPosition != null) {
		tinyMCE.activeEditor.selection.moveToBookmark(cursorPosition);
	}
	tinyMCE.activeEditor.execCommand('mceInsertContent', false, text);
	rememberCursorPos();
}

var cursorPosition;
function rememberCursorPos() {
	var cp = tinyMCE.activeEditor.selection.getBookmark(1, false);
	if (cp.start != 0) {
		cursorPosition = cp;
	}
}

function hideUploadForm() {
	cleanAllErrors();
	hideme('uploadFormHolder');
}

function showUploadForm() {
	showme('uploadFormHolder'); 
}

function setEditorProgress(isSet) {
	if (typeof(tinyMCE) !== undefined) {
		if (tinyMCE.activeEditor) {
    		tinyMCE.activeEditor.setProgressState(isSet);
    	}
	}
	tinyMCE.activeEditor.execCommand(arg0,arg1,text)
}

function loadHighlighterModulesAndRun() {
	
	function path()	{
		var args = arguments, result = [];
       
		for(var i = 0; i < args.length; i++)
   			result.push(args[i].replace('@', '/js/syntaxhighlighter/scripts/'));      						
		return result
	};
	SyntaxHighlighter.autoloader.apply(null, path(
  		'applescript            @shBrushAppleScript.js',
  		'actionscript3 as3      @shBrushAS3.js',
  		'bash shell             @shBrushBash.js',
  		'coldfusion cf          @shBrushColdFusion.js',
  		'cpp c                  @shBrushCpp.js',
  		'c# c-sharp csharp      @shBrushCSharp.js',
  		'css                    @shBrushCss.js',
  		'delphi pascal          @shBrushDelphi.js',
  		'diff patch pas         @shBrushDiff.js',
  		'erl erlang             @shBrushErlang.js',
  		'groovy                 @shBrushGroovy.js',
  		'java                   @shBrushJava.js',
  		'jfx javafx             @shBrushJavaFX.js',
  		'js jscript javascript  @shBrushJScript.js',
  		'perl pl                @shBrushPerl.js',
  		'php                    @shBrushPhp.js',
  		'text plain             @shBrushPlain.js',
//  		'powershell	ps			@shBrushPowerShell', don't work
  		'py python              @shBrushPython.js',
  		'ruby rails ror rb      @shBrushRuby.js',
  		'sass scss              @shBrushSass.js',
  		'scala                  @shBrushScala.js',
  		'sql                    @shBrushSql.js',
  		'vb vbnet               @shBrushVb.js',
  		'xml xhtml xslt html    @shBrushXml.js'
	));
	SyntaxHighlighter.config.strings.expandSource = "Раскрыть код";
	SyntaxHighlighter.all();
}

function changeCodeEditorMode() {
	if (document.getElementById("isAdvancedMode").value == "0") {
		showme('advancedMode');
		document.getElementById("changeCodeEditorModeLink").innerHTML = "Стандартные настройки";
		document.getElementById("isAdvancedMode").value = "1";
	} else {
		hideme('advancedMode');
		document.getElementById("changeCodeEditorModeLink").innerHTML = "Расширенные настройки";
		document.getElementById("isAdvancedMode").value = "0";
		// clean advanced settings
		document.getElementById("uplCodeHighlight").value="";
		document.getElementById("uplCodeTabSize").value="4";
		document.getElementById("uplCodeFirstLine").value="1";
	}	
}




