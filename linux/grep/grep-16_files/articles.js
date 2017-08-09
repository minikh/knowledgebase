function initArticleActions(refreshParams) {
	Gallery.addOnSuccessHandler('deleteItem', function(data, listName, reqUri, commentId, perPage, contextPath) {
		if (listName == 'articles') {
			if (data == "success") {
				if (refreshParams != null) {
					document.location.search = refreshParams;
				} else {
					document.location.reload();
				}
			} else {
				document.getElementById("errorMsg").innerHTML = data;
				document.location.hash = "errorMsg";
			}
		}
	});
	Gallery.addOnSuccessHandler('performAction', function(action, id, reqUri, response) {
		if (action == 'articleratepos' || action == 'articlerateneg') {
			if (response == "success") {
				hideme("articleRateControls" + id);
				showme("articleRate" + id);
				document.getElementById("articleErrorMsg").innerHTML = "";
				var rate;
				if (action == 'articleratepos') {
					rate = 1;
				} else {
					rate = -1;
				}
				var el = document.getElementById("articleRate" + id);
				var rating = parseInt(el.innerHTML.substring(8)) + rate;
				if (rating > 0) {
					rating = "+" + rating;
				}
				el.innerHTML = "Рейтинг: " + rating;   // в substring исключаем Рейтинг: 
			} else {
				document.getElementById("articleErrorMsg").innerHTML = response;
			}	
		} else if (action == 'acceptMod') {
			if (response != "success") {
				document.getElementById("articleErrorMsg").innerHTML = response;
			} else {
				document.location.reload();
			}
		} else if (action == 'commentSubscribe' || action == 'commentUnsubscribe') {
			if (response != "success") {
				alert(response);
			}
		}
	});
	Gallery.addOnSuccessHandler('submitViaAjax', function(formName, listName, data) {
		if (listName == 'rejectMod') {
			if (data != "success") {
				showme('rejectFormHolder');
				document.getElementById("articleErrorMsg").innerHTML = data;
			} else {
				document.getElementById("articleNoticeMsg").innerHTML = getNoticeText('Статья возвращена автору успешно');
				closeDialogForm('rejectFormHolder');
			}
		}
	});
}

function deleteArticle(id, contextPath, isDraft) {
	// code duplicated (main.ftl)
	var uri = 'reader/ajax/';
	if (isDraft != null) {
		uri = uri + 'deletedraft'; 
	} else {
		uri = uri + 'deletearticle';
	}
	uri = uri + '/' + id; 
	return Gallery.deleteItem('articles', uri, id, '', 0, contextPath, 'Вы действительно хотите удалить статью?');
}

function rateArticle(action, id, contextPath) {
	Gallery.performAction(action, id, 'reader/ajax/ratearticle/' + id, contextPath);
}

function onSubmitArticleForm() {
	if (document.getElementById("editor").value=='markitup') {
		tinyMCE.activeEditor.setContent(document.getElementById("memo").value, {format : 'raw'});
	} else if (document.getElementById("editor").value=='tinymce') {
		// see http://tinymce.moxiecode.com/punbb/viewtopic.php?id=28	
		document.getElementById("memo").value = tinyMCE.activeEditor.getContent();
	}
}



function acceptArticle(articleId, contextPath) {
	Gallery.performAction('acceptMod', articleId, 'writer/ajax/acceptarticle/' + articleId, contextPath, 'Разрешить публикацию статьи?');
}

function rejectArticle(articleId, contextPath) {
	document.forms['f_reject_form'].rejectReason.value = '';
	hideArticleModControlls();
	openDialogForm('rejectFormHolder');
}

function submitRejectArticle(articleId, contextPath) {
	/*var reason = document.forms['f_reject_form'].rejectReason.value;
	var uri = 'writer/ajax/rejectarticle/' + articleId + '?reason=' + reason;
	Gallery.performAction('rejectMod', articleId, uri, contextPath);*/
	document.getElementById('reason').value = document.getElementById('rejectReason').value;
	Gallery.submitViaAjax('f_reject_form', 'rejectMod', '', 0, contextPath);
	
	hideme('rejectFormHolder');
	return false;
}

function cancelRejectArticle() {
	closeDialogForm('rejectFormHolder');
	showArticleModControlls();
	document.getElementById("articleErrorMsg").innerHTML = '';
	return false;
}

function hideArticleModControlls() {
	hideme('articleModControls1');
	hideme('articleModControls2');
}

function showArticleModControlls() {
	showme('articleModControls1');
	showme('articleModControls2');
}

function changeCommentSubscribedStatus(articleId, contextPath) {
	var action;
	if (document.getElementById('commentSubscribedStatus').checked) {
		action = 'commentSubscribe';
	} else {
		action = 'commentUnsubscribe';
	}
	Gallery.performAction(action, '', 'reader/ajax/commentsubscribe/' + articleId, contextPath);	
}

function changeCommentSubscribedStatusOnLabel(articleId, contextPath) {
	var el = document.getElementById('commentSubscribedStatus');
	el.checked = !el.checked;
	changeCommentSubscribedStatus(articleId, contextPath);
}

function setArticleVisibility(formName, value, isPublish, isEdit) {
	var isVisible = false;
	if(document.forms[formName].visible.value=="true"){
		isVisible=true;
	}
	var version = document.forms[formName].version.value;
	//if(!isEdit || !isVisible || version<=1){	
		document.forms[formName].publication.value = isPublish;
	//}
	document.forms[formName].visible.value = value;
	
	return true; 
}

function isPersonalBlog(formName, personalBlogId){
	if(document.forms[formName].blogId){
		if(document.forms[formName].blogId.value!=personalBlogId){
			document.forms[formName].offTopic.checked=false;
		}
	}
}

function onOffTopicCheck(formName, personalBlogId){
	if(document.forms[formName].blogId){
		if(document.forms[formName].offTopic.checked==true){
			$(document.forms[formName].blogId).val(personalBlogId);
		} 
	}
}
