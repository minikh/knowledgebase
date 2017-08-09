function initBlogSubscriptionActions(contextPath) {
	Gallery.addOnSuccessHandler('performAction', function(action, listName, reqUri, response) {				
		if (listName == 'subscriptions') {
			if (response == "success") {																		
				document.location.reload();
			} else {
				alert(response);
			}
		}
	});
}

function blogSubscribe(blogId, contextPath) {
	var uri = 'reader/ajax/subscription/manage/' + blogId;
	Gallery.performAction('subscribe', 'subscriptions', uri, contextPath);
}

function blogUnsubscribe(blogId, contextPath) {
	var uri = 'reader/ajax/subscription/manage/' + blogId;
	Gallery.performAction('unsubscribe', 'subscriptions', uri, contextPath, 'Отписатся?');
}