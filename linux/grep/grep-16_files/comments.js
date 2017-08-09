var currentCEContainerId = 'commentFormHolder';
var isStartWriting = false;
var currentArticleId;

function initCommentActions(articleId, contextPath) { 
	currentArticleId = articleId;
	Gallery.addOnSuccessHandler('submitViaAjax', function(formName, listName, data) {
		if (formName == 'f_comment') {
			if (data.indexOf("commentid_") != -1) {
				var commentId = data.substring("commentid_".length, data.length);
				reloadCommentsBlock(contextPath);
				window.location.hash = "comment" + commentId;
			} else {
				document.getElementById("errorMsg").innerHTML = data;
			}
		}
	});	
	Gallery.addOnBeforeActionHandler('submitViaAjax', function(formName) {
		if (formName == 'f_comment') {
			document.getElementById("errorMsg").innerHTML = "";
		}
	});
	Gallery.addOnAfterActionHandler('loadSimpleContent', function(reqUri, dispId, contextPath) {
		if (dispId == 'commentsBlock') {
			loadHighlighterModulesAndRun();
		} else if (dispId.indexOf('commentFormHolder') != -1) {
			initCommentEditor(dispId);
		}
	});
	Gallery.addOnSuccessHandler('deleteItem', function(data, listName, reqUri, commentId, perPage, contextPath) {
		if (listName == 'comments') {
			reloadCommentsBlock(contextPath);
			if (data != "success") {
				alert(data);
			}
		}
	});
	Gallery.addOnSuccessHandler('performAction', function(action, commentId, reqUri, response) {
		if (action == 'ratepos' || action == 'rateneg') {
			if (response == "success") {
				hideme("commentRatePos" + commentId);
				hideme("commentRateNeg" + commentId);
				document.getElementById("commentErrorMsg" + commentId).innerHTML = "";
				var rate;
				if (action == 'ratepos') {
					rate = 1;
				} else {
					rate = -1;
				}
				showme("commentRate" + commentId);
				var el = document.getElementById("commentRate" + commentId);
				var elValue = $.trim(el.innerHTML);

				if (elValue) {
					elValue = parseInt(elValue) + rate;					
				} else {
					elValue = rate;
				}
				if (elValue > 0) {
					elValue = "+" + elValue;
				}
				el.innerHTML = elValue;
				
			} else {
				document.getElementById("commentErrorMsg" + commentId).innerHTML = response;
			}	
		}
		if (action == 'canedit') {
			if (response == "success") {
				removeCommentEditor();
				hiddenComment = 'comment' + commentId;
				hideme(hiddenComment);
				Gallery.loadSimpleContent("reader/ajax/comments/edit/" + commentId, 'commentFormHolder' + commentId, Gallery.getCurrentContextPath());				
			} else {
				alert("К сожалению Вы уже не можете редактировать данный комментарий");
				if (document.getElementById("commentRate" + commentId)) {
					document.getElementById("commentRate" + commentId).innerHTML = response;
					hideme("commentEdit" + commentId);
				}
			}
		}
	});
	
	
	
}

function initCommentEditor(containerId, notFocus) {
	currentCEContainerId = containerId;
	$('#memo').markItUp(commentSettings);	
	$('#memo').css({height: '159px'});
	correctAnswerEditorWidth();
	if (! notFocus) {
		setCommentEditorFocus()
	}
}

/*
 * Used when parent comment contains big picture (hidden partly) to prevent editor cut
*/
function correctAnswerEditorWidth() {
	var parentCommentId = document.getElementById('parentCommentId');
	if (parentCommentId) {
		var commentId = parentCommentId.value;
		$(".markItUpContainer").css("max-width", $("#leftColumn").css("width"));
		var realWidth = parseInt($("#leftColumn").css("width")) - parseInt($("#commentLeftIndent"+commentId).css("width")) - parseInt($(".userAvatarHolder").css("width"));		
		if (realWidth + 40 < parseInt($("#comment"+commentId).css("width"))) {
			realWidth-=20;
			$('.markItUpContainer').css({width: realWidth+'px'});
			$('#commentFormControlButtons').css({width: realWidth+'px'});	
		}
	}
}

function setCommentEditorFocus() {
	$('#memo').focus();
}

var memovalue;
function saveMemo() {
	if (navigator.userAgent.indexOf('Firefox')!=-1 && document.getElementById('memo')) {
		memovalue = document.getElementById('memo').value;
	}
}
function fixFirefoxHTML() {			
	if (navigator.userAgent.indexOf('Firefox')!=-1 && memovalue) {
		setTimeout("tinyMCE.activeEditor.setContent(memovalue)", 10);
	}
}

function removeCommentEditor() {
	hideme(currentCEContainerId);
	document.getElementById(currentCEContainerId).innerHTML = "";
}

function submitCommentForm(formId, contextPath) {
	var commentTxt = replaceNewLineWithBR(document.getElementById('memo').value); // replaceNewLineWithBR() - is located in jquery.markitup.js
	document.getElementById('memo').value = replaceLinks(commentTxt);
	Gallery.submitViaAjax(formId, '', '', 0, contextPath);
	setCommentEditorFocus();
	return false;
}

function postAnswer(parentCommentId, contextPath) {
	removeCommentEditor();
	Gallery.loadSimpleContent("ajax/comments/answer/" + parentCommentId, 'commentFormHolder' + parentCommentId, contextPath);	
	setCommentEditorFocus();	
} 

function editComment(commentId, contextPath) {
	// first check if user can edit comment
	Gallery.performAction("canedit", commentId, 'reader/ajax/comments/canedit/' + commentId, contextPath);
	setCommentEditorFocus();
}

function deleteComment(commentId, contextPath) {	
	Gallery.deleteItem('comments', "reader/ajax/comments/delete/" + commentId, 0, commentId, 0, contextPath);
    setCommentEditorFocus()   
}

function rateComment(action, commentId, contextPath) {
	Gallery.performAction(action, commentId, 'reader/ajax/comments/rate/' + commentId, contextPath);		
}

function cancelAnswerOrEdit(contextPath) {	
	reloadCommentsBlock(contextPath);
}

function reloadCommentsBlock(contextPath) {
	var uri = 'ajax/reloadcomments/' + currentArticleId;
	Gallery.loadSimpleContent(uri, 'commentsBlock', contextPath)
}

    
function replaceBRWithNewLine() {
	var commentMemo = document.getElementById('memo').value;
	var startIndex = -1;
	var openCodeIndexes = new Array();
	var closeCodeIndexes = new Array();

	while (commentMemo.indexOf("<pre class=", startIndex) > -1) {
		startIndex = commentMemo.indexOf("<pre class=", startIndex);
 		openCodeIndexes.push(startIndex);
 		startIndex++;
	}
	if (startIndex > -1) {
		startIndex = -1;
		while (commentMemo.indexOf("</pre>", startIndex) > -1) {
			startIndex = commentMemo.indexOf("</pre>", startIndex);
 			closeCodeIndexes.push(startIndex);
 			startIndex++;
		}
	}
	if (startIndex == -1) {
		document.getElementById('memo').value = commentMemo.replace(/<br\s\/>/g, "\r\n"); 	
	} else {		
		startIndex = -1;
		var shiftPosition = 0;
		while (commentMemo.indexOf("<br />", startIndex) > -1) {
			startIndex = commentMemo.indexOf("<br />", startIndex);
			var processed = false;
			for (i = 0; i < closeCodeIndexes.length; i++) {	
				if (startIndex < closeCodeIndexes[i] + shiftPosition) {
					if (openCodeIndexes[i] + shiftPosition < startIndex) {
						processed = true;
					}
					break;
				}
			}
			if (!processed) {
				commentMemo = setCharAt(commentMemo,startIndex, "\r\n", 6); // \n -> br
				shiftPosition -= 5;
				startIndex -= 5;
			}
			startIndex++;
		}
		document.getElementById('memo').value = commentMemo;
	}
}
	
function setCharAt(str, startIndex, inputStr, substituteLength) {  // replace characters at position
    if(startIndex > str.length - 1) return str;
    return str.substr(0, startIndex) + inputStr + str.substr(startIndex + substituteLength);
}
