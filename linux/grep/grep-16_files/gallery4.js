
Gallery = {
	
	// the contextPath initialized with default value
	contextPath : '/',
	
	// An array used to store current offset values.
	offset : new Array(),
	
	// An array used to store current perPage values.
	perPage : new Array(),

	// An array used to store onSuccess, onError and other callbacks. 
	galleryСallbacks : new Array(),
	
	// An array contains the names of forms waiting for server responce on submit request.
	pendingSubmitRequests : new Array(),

	selectDisplayName : function(listName) {
		var dispId = "display" + capitalize(listName);
		if (typeof document.getElementById(dispId) == "undefined") {
			dispId = "displayList";
		}
		return dispId;
	},
	
	displayList : function(data, listName, dispId) {
		if (data == "") {
			return;
		}
		var disp;
		if ((typeof dispId != "undefined") &&  (dispId != "")) {
			disp = document.getElementById(dispId);
		} else {
			disp = document.getElementById(selectDisplayName(listName));	
		}
		if (typeof disp != "undefined") {		
			disp.style.visibility = 'visible';
		    disp.style.display = 'block';
		    disp.innerHTML = data;
		    
			var browserType;
			if (document.layers) {browserType = "nn4"}
			if (document.all) {browserType = "ie"}
			if (window.navigator.userAgent.toLowerCase().match("gecko")) {
			   browserType= "gecko"
			}		
			
		var x;
			if (browserType != "ie") {
				x = disp.getElementsByTagName("script"); 
			} else {
				var x = new Array();
			    var idx = data.indexOf('<script');
			    var i = 0;
			    while ( idx > -1 ) {
			        idx = data.indexOf('>', idx) + 1;		        
			        var idx2 = data.indexOf('</script>', idx);		        
			        x[i] = new Object();
			        var res = data.substring(idx, idx2);
			        res = res.replace("<!--", "");
					res = res.replace("-->", "");
			        x[i].text = res;
			        idx = data.indexOf('<script', idx2);
			        i++;
			    }					
			}
		    // exec the javascript
			for(var i=0;i<x.length;i++) {
				eval(x[i].text);
				//(Function(x[i].text))();
			}
		} else {
			// developers error
			alert('Ошибка :(');
		}
	},

	initListValues : function(listName, pp) {	
		if (typeof pp != "undefined") {
			Gallery.perPage[listName] = pp;	
		}
		if (typeof this.offset[listName] == "undefined") {
			Gallery.offset[listName] = 0;
		}
	},
	
	loadList : function(listName, reqUri, dispId, pp, contextPath, notShowProgress) {
		
		Gallery.initContextPath(contextPath);
		Gallery.initListValues(listName, pp);
		
		Gallery.invokeOnBeforeActionHandlers('loadList', listName, dispId);
		
		var url = Gallery.getCurrentContextPath(contextPath) + reqUri;	
		AjaxRequest.post({'url':url,
			'parameters':{
							'action': 'showlist',
							'listName': listName,
							'offset': Gallery.offset[listName],
							'perPage': Gallery.perPage[listName]
						 },
			"onSuccess":			
				function (req) {
						data = req.responseText;
						if (data == "error") {
							Gallery.invokeOnErrorHandlers('loadList', listName);
						} else {
							Gallery.invokeOnSuccessHandlers('loadList', listName, data);
							Gallery.displayList(data, listName, dispId);
							Gallery.invokeOnAfterActionHandlers('loadList', listName, data);
						}	
				}, 
			"onLoading":function() { 
				if (notShowProgress == null) { 
					showLoadingProgress(document.getElementById("defaultDisplayElement")); 
				} 
			},
			"onComplete": function() { 
				if (notShowProgress == null) { 
					hideLoadingProgress(); 
				}
				try {
					pageTracker._trackPageview(url);
					yaCounter561921.hit(url);
				} catch(e) {}
			},
			"onError": function (req) { 
				hideLoadingProgress(); 
				if (notShowProgress == null) { 
					alert("Ошибка...");	
				}				
			}
		});	
	},
		
	submitSearch : function(formName, listName, dispId, pp, contextPath) {
		Gallery.invokeOnBeforeActionHandlers('submitSearch', listName, dispId, pp, contextPath)
		Gallery.offset[listName] = 0;
		Gallery.savedForm = Gallery.cloneAForm(formName);//Gallery.getCopyForm(formName);		
		Gallery.submitViaAjax(formName, listName, dispId, pp, contextPath);
		return false;
	},
	
	submitViaAjax : function(formName, listName, dispId, pp, contextPath, notShowProgress) {
		if (typeof document.forms[formName] != "undefined") {
			if (!Gallery.canSubmitForm(formName)) {
				return;
			}
			Gallery.addPendingSubmitRequest(formName);
		
			/* Temporary commented. Where is a bug with cloning checkboxes (cloneAForm, getCopyForm - doesn't work)
			var sf = Gallery.savedForm; 
			if (sf == null) {
				sf = Gallery.cloneAForm(formName); //Gallery.getCopyForm(formName);
			}*/
			var sf = document.forms[formName];

			Gallery.initListValues(listName, pp);
			Gallery.invokeOnBeforeActionHandlers('submitViaAjax', formName, listName, dispId);
			AjaxRequest.submit(
		    	sf, {		
		    		'onSuccess':function (req) {
						try {
							data = req.responseText;
							if (data == "error") {
								Gallery.invokeOnErrorHandlers('submitViaAjax', formName, listName);
							} else {
								Gallery.invokeOnSuccessHandlers('submitViaAjax', formName, listName, data);
								Gallery.displayList(data, listName, dispId);
								Gallery.invokeOnAfterActionHandlers('submitViaAjax', formName, listName, data);
							}
							Gallery.removePendingSubmitRequest(formName);
						} catch(e) {
							Gallery.removePendingSubmitRequest(formName);
						}
					},
					'offset': Gallery.offset[listName],
					'perPage': Gallery.perPage[listName],
					'listName':listName,	
					"onLoading":function() { 
						if (notShowProgress == null) {
							showLoadingProgress(document.getElementById("defaultDisplayElement"));
						} 
					},
					"onComplete": function() { 
						if (notShowProgress == null) {
							hideLoadingProgress();
						} 
						try {
							pageTracker._trackPageview(Gallery.savedForm.action);
							yaCounter561921.hit(Gallery.savedForm.action);
						} catch(e) {}
					},
					"onError": function (req) { 
						Gallery.removePendingSubmitRequest(formName);
						hideLoadingProgress(); 
						if (notShowProgress == null) { 
							alert("Ошибка...");
						}
					}
		    	}
		    );
		} else {
			// developers error
			alert("Ошибка :(");
		}
	},
		
	onChangeSelect : function(listName, reqUri, dispId, contextPath) {
		var newPerPage = parseInt(document.getElementById("perPage").value);
		Gallery.offset[listName] = 0;
		Gallery.loadList(listName, reqUri, dispId, newPerPage, contextPath);
	},
		
	deleteItem : function(listName, reqUri, itemId, dispId, perPage, contextPath, confirmMsg) {
		if (confirmMsg == null) {
			confirmMsg = "Вы уверены?"; 
		}
		if (confirm(confirmMsg)) {
			
			Gallery.initContextPath(contextPath);
			Gallery.initListValues(listName, perPage);
		
			Gallery.invokeOnBeforeActionHandlers('deleteItem', listName, reqUri, itemId)
			
			var url = Gallery.getCurrentContextPath(contextPath) + reqUri;
			AjaxRequest.post({
				'url':url,
				'parameters':{
								'listName':listName,
								'itemId':itemId,
								'action':'delete'
							 },
				'onSuccess':			
					function (req) {
						var response = req.responseText;
						if (response != "error") {
							Gallery.invokeOnSuccessHandlers('deleteItem', response, listName, reqUri, dispId, perPage, contextPath);
						} else {
							Gallery.invokeOnErrorHandlers('deleteItem', response, listName, reqUri, dispId);
						}
					},
				'onLoading':function() { 
					try {
						showLoadingProgress(document.getElementById("defaultDisplayElement"));
					} catch (e) {
						// ignore
					}	 
				},
				'onComplete': function() { 
					try { 
						hideLoadingProgress();
					} catch (e) {
						// ignore
					}
				},
				'onError': function (req) { 
					hideLoadingProgress(); 
					alert("Ошибка...");	
				}			
			});
		}
		return false;	
	},
			
	sendActionRequest : function(actionForm, listName, reqUri, dispId, pp, contextPath) {
		if (!Gallery.canSubmitForm(actionForm)) {
			return false;
		}
		Gallery.addPendingSubmitRequest(actionForm);
		Gallery.initContextPath(contextPath);
		
		Gallery.invokeOnBeforeActionHandlers('sendActionRequest', listName, dispId)
		AjaxRequest.submit(
	    	document.forms[actionForm], {		
	    		'onSuccess':function (req) {
					try {
	 					var response = req.responseText;
						if (response != "error") {
							Gallery.invokeOnSuccessHandlers('sendActionRequest', listName, response, actionForm);
							Gallery.loadList(listName, reqUri, dispId, pp, contextPath);
						} else {
							Gallery.invokeOnErrorHandlers('sendActionRequest', listName, actionForm);
						}
 						Gallery.removePendingSubmitRequest(actionForm);
					} catch(e) {
						Gallery.removePendingSubmitRequest(actionForm);
					}
				},
				"onLoading":function() { showLoadingProgress(document.getElementById("defaultDisplayElement")); },
				"onComplete": function() { 
					hideLoadingProgress();
					try {	
						pageTracker._trackPageview(document.forms[actionForm].action);
						yaCounter561921.hit(document.forms[actionForm].action);
					} catch(e) {}
				},
				"onError": function (req) { 
					Gallery.removePendingSubmitRequest(actionForm);
					hideLoadingProgress(); 
					alert("Ошибка...");	
				}			
	    	}
	    );		
	   	return false;
	},		
			
	sendSubmitRequest : function(actionForm, formName, listName, dispId, pp, contextPath) {
		Gallery.initContextPath(contextPath);
		Gallery.invokeOnBeforeActionHandlers('sendSubmitRequest', listName, dispId)
		
		AjaxRequest.submit(
	    	document.forms[actionForm], {		
	    		'onSuccess':function (req) {
					var response = req.responseText;
					if (response != "error") {
						Gallery.invokeOnSuccessHandlers('sendSubmitRequest', listName, response, actionForm);
						Gallery.submitViaAjax(formName, listName, dispId, pp, contextPath);
					} else {
						Gallery.invokeOnErrorHandlers('sendSubmitRequest', listName);				
					}
				},
				"onLoading":function() { showLoadingProgress(document.getElementById("defaultDisplayElement")); },
				"onComplete": function() { 
					hideLoadingProgress(); 
					try {
						pageTracker._trackPageview(document.forms[actionForm].action);
						yaCounter561921.hit(document.forms[actionForm].action);
					} catch(e) {}
				},
				"onError": function (req) { 
					hideLoadingProgress(); 
					alert("Ошибка...");	
				}			
	    	}
	    );
	   	return false;    
	},

	markAll : function(firstMarkAll, secondMarkAll, offset, perPage){
		//Gallery.initListValues(listName, perPage);
		
		var mainBox = document.getElementById('markAll');
		if (firstMarkAll != null) {
			mainBox = document.getElementById(firstMarkAll);
		}
		if (mainBox != null) {
			mainBox.checked=mainBox.checked? 1:0;
			for (var i=offset; i<=(perPage+offset); i++) {
		 		var box = document.getElementById('checkBox_' + i);
				if (box != null) {
				 	box.checked=mainBox.checked;
				}
			}
		}
		if (secondMarkAll != null) {
			document.getElementById(secondMarkAll).checked=mainBox.checked;
		}
	},

	performAction : function(action, listName, reqUri, contextPath, confirmMsg) {
		if (confirmMsg != null) {
			if(!confirm(confirmMsg)) {
				return false;
			}
		}
		Gallery.initContextPath(contextPath);
		//Gallery.initListValues(listName, perPage);
		
		Gallery.invokeOnBeforeActionHandlers('performAction', action, listName, reqUri);
		
		var url = Gallery.getCurrentContextPath(contextPath) + reqUri;	
		AjaxRequest.post({
			'url':url,
			'parameters':{
							'listName':listName,
							'action':action
						 },
			"onSuccess":			
				function (req) {
					var response = req.responseText;
					if (response != "error") {
						Gallery.invokeOnSuccessHandlers('performAction', action, listName, reqUri, response);
					} else {
						Gallery.invokeOnErrorHandlers('performAction', action, listName, reqUri);
					}
				},
			"onLoading":function() { showLoadingProgress(document.getElementById("defaultDisplayElement")); },
			"onComplete": function() { 
				hideLoadingProgress(); 
				try {
					pageTracker._trackPageview(url);
					yaCounter561921.hit(url);
				} catch(e) {}
			},
			"onError": function (req) { 
				hideLoadingProgress(); 
				alert("Ошибка...");	
			}			
		});
		return false;	
	},

	loadSimpleContent : function(reqUri, dispId, contextPath) {
		Gallery.initContextPath(contextPath);
		
		var url = Gallery.getCurrentContextPath(contextPath) + reqUri;	
		AjaxRequest.post({
			'url':url,
			'parameters':{},
			"onSuccess":			
				function (req) {
					var data = req.responseText;
					Gallery.displayList(data, 'default', dispId);
					Gallery.invokeOnAfterActionHandlers('loadSimpleContent', reqUri, dispId, contextPath);
				},
			"onLoading":function() { 
				showLoadingProgress(document.getElementById("defaultDisplayElement"));
			},
			"onComplete": function() { 
				hideLoadingProgress(); 
				try {
					pageTracker._trackPageview(url);
					yaCounter561921.hit(url);
				} catch(e) {}
			},
			"onError": function (req) { 
				hideLoadingProgress(); 
				alert("Ошибка...");	
			}			
		});
		return false;	
	},

	setOffsetToLastPage : function(listName, perPage, total) {
		Gallery.offset[listName] = Math.floor(total/perPage) * perPage;
	},
	
	setOffsetToFirstPage : function(listName) {
		Gallery.offset[listName] = 0;
	},
		
	addOnSuccessHandler : function(galleryFuncName, callback) {
		Gallery.registerCallback(galleryFuncName + "OnSuccessHandler", callback);
		return callback;
	},	
		
	invokeOnSuccessHandlers : function(galleryFuncName) {
		arguments[0] = galleryFuncName + "OnSuccessHandler";
		Gallery.invokeCallbacks.apply(this, arguments);
	},
	
	addOnErrorHandler : function(galleryFuncName, callback) {
		Gallery.registerCallback(galleryFuncName + "OnErrorHandler", callback);
		return callback;
	},
	
	invokeOnErrorHandlers : function(galleryFuncName) {
		arguments[0] = galleryFuncName + "OnErrorHandler";
		Gallery.invokeCallbacks.apply(this, arguments);
	},
	
	addOnBeforeActionHandler : function(galleryFuncName, callback) {
		Gallery.registerCallback(galleryFuncName + "OnBeforeHandler", callback);
		return callback;
	},
	
	invokeOnBeforeActionHandlers : function(galleryFuncName) {
		arguments[0] = galleryFuncName + "OnBeforeHandler";
		Gallery.invokeCallbacks.apply(this, arguments);
	},
	
	addOnAfterActionHandler : function(galleryFuncName, callback) {
		Gallery.registerCallback(galleryFuncName + "OnAfterHandler", callback);
		return callback;
	},
	
	invokeOnAfterActionHandlers : function(galleryFuncName) {
		arguments[0] = galleryFuncName + "OnAfterHandler";
		Gallery.invokeCallbacks.apply(this, arguments);
	},
				
	registerCallback : function(callbackName, callback) {
		if (callback == null) {
			return;
		}
		if (Gallery.galleryСallbacks[callbackName] == null) {
			Gallery.galleryСallbacks[callbackName] = new Array();
		}	
		var i = 0;
		while (Gallery.galleryСallbacks[callbackName][i] != null) {
			i++;
		}
		Gallery.galleryСallbacks[callbackName][i] = callback;
	},
	
	// replaces all existing callbacks with the given name, with new one (e.g. overwrites all existing handlers) 
	setCallback : function(callbackName, callback) {
		Gallery.galleryСallbacks[callbackName] = new Array();
		Gallery.galleryСallbacks[callbackName][0] = callback;
	},
	
	getCallbacks : function(callbackName) {
		return Gallery.galleryСallbacks[callbackName];
	},
	
	invokeCallbacks : function(callbackName) {
		if (Gallery.galleryСallbacks[callbackName] != null) {
			var args = new Array();
			for (var i = 1; i < arguments.length; i++) {
				args[i - 1] = arguments[i];
			}
			var i = 0;
			while (Gallery.galleryСallbacks[callbackName][i] != null) {
				Gallery.galleryСallbacks[callbackName][i].apply(this, args);
				i++;
			}	
		}
	},
	
	canSubmitForm : function(f_name) {
		if(!Array.indexOf){
		    Array.prototype.indexOf = function(obj){
		        for(var i=0; i<this.length; i++){
		            if(this[i]==obj){
		                return i;
		            }
		        }
		        return -1;
		    };
		}
		return Gallery.pendingSubmitRequests.indexOf(f_name) == -1;
	},
	
	addPendingSubmitRequest : function(f_name) {
		Gallery.pendingSubmitRequests.push(f_name);
	},
	
	removePendingSubmitRequest : function(f_name) {
		var index = Gallery.pendingSubmitRequests.indexOf(f_name);
		if (index != -1) {
			Gallery.pendingSubmitRequests.splice(index, 1);
		}
	},
	
	initContextPath : function(contextPath) {
		if ((typeof Gallery.contextPath == "undefined") && (typeof contextPath != "undefined")) {
			Gallery.contextPath = contextPath;
		}
	},
	
	getCurrentContextPath : function(contextPath) {
		if (typeof contextPath != "undefined") {
			return contextPath;
		} else {
			return Gallery.contextPath;
		}
	},
	
	cloneAForm : function(formName) {
		var origForm = document.forms[formName];
		var acopy = origForm.cloneNode(true);
		
		var fields = acopy.elements;	
		for(var i=0; i < fields.length; i++) {
			var elem = fields[i];
			if (elem.tagName == "SELECT" || (elem.tagName == "input") || (elem.tagName == "TEXTAREA")) {
				var source_sel = origForm.elements[elem.name];
				elem.value = source_sel.value;
			} else if (elem.tagName == "INPUT") {
				var source_sel = origForm.elements[elem.name];
				if (elem.type == "checkbox") {			
					elem.checked = source_sel.checked;
				} 
				// other types, need to be copied separately
			}
			//this is for test, in case you dont know what are you missed in form
			//alert('elem.tagName: ' + elem.tagName + "; elem.type: " + elem.type + ";");
		}
		return acopy;
	},
	
	getCopyForm : function(formName) {
		var origForm = document.forms[formName];
		
		var clonedForm = document.createElement(origForm.tagName);
		clonedForm.method = origForm.method;
		clonedForm.action = origForm.action;
		clonedForm.onsubmit = origForm.onsubmit;
		
		var fields = origForm.elements;
		
		for(var i=0, s=fields.length; i < s; i++) {
			var field = fields[i];
			
			if (field.type != "submit") {
				var clonedField =  document.createElement(field.tagName);
				if (field.tagName == "INPUT") {
					clonedField.type = field.type;
				}
				clonedField.name = field.name;
				
				if (field.type == "checkbox") {
					clonedField.checked = field.checked;
				} else {
					if (field.tagName == 'SELECT') {
						var idx = field.selectedIndex;
						clonedField.selectedIndex = idx;
						clonedField.value = field.options[idx].value;
					} else {
						clonedField.value = field.value;
					}
				}
			
				clonedForm.appendChild(clonedField);
			}
		}
		return clonedForm;
	}
};