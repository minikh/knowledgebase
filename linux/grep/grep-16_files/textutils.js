/*
 * Find all http:// not in <a href="http://..">..</a> and replace to <a href="http://zzz.zzz">zzz.zzz</a>, skip http in code
 * 
 * @param {Object} commentMemo
 * @return {TypeName} 
 */
function replaceLinks(commentMemo) {
	var exp = /(\b(https?|ftp|file):\/\/[-A-Z0-9А-Яа-я+&@#\/%?=~_|!:,.;]*[-A-Z0-9А-Яа-я+&@#\/%=~_|])/ig;
	if (commentMemo.indexOf("<pre class=")==-1 && commentMemo.indexOf("<a href")==-1) {
  		return commentMemo.replace(exp,"<a href='$1'>$1</a>");
	}
	var httpIndex = -1;
	while ((httpIndex = Math.min(commentMemo.indexOf("http://", httpIndex)==-1?100000:commentMemo.indexOf("http://", httpIndex),
						  commentMemo.indexOf("https://", httpIndex)==-1?100000:commentMemo.indexOf("https://", httpIndex),
						  commentMemo.indexOf("ftp://", httpIndex)==-1?100000:commentMemo.indexOf("ftp://", httpIndex)
						 )) > -1 && (httpIndex < 100000) )
	{
		if (httpIndex >= 9 && commentMemo.substring(httpIndex - 9, httpIndex)=="<a href=\"") {
			httpIndex += 9;
			continue;
		}
		// check if  http|ftp|https:// is in code
		var searchStartIndex = -1;
		var prevSearchStartIndex = -1;
		while ((searchStartIndex = commentMemo.indexOf("<pre class=", searchStartIndex)) > -1 && (searchStartIndex < httpIndex)) {
			prevSearchStartIndex = searchStartIndex;
			searchStartIndex++;
		}
		if (prevSearchStartIndex > -1) {
			if (commentMemo.indexOf("</pre>", prevSearchStartIndex) > httpIndex) {
				httpIndex++;
				continue;
			}
		}
		// check if  http|ftp|https:// already in <a href=""></a>
		var searchStartIndex = -1;
		var prevSearchStartIndex = -1;
		while ((searchStartIndex = commentMemo.indexOf("<a href=", searchStartIndex)) > -1 && (searchStartIndex < httpIndex)) {
			prevSearchStartIndex = searchStartIndex;
			searchStartIndex++;
		}
		if (prevSearchStartIndex > -1) {
			if (commentMemo.indexOf("</a>", prevSearchStartIndex) > httpIndex) {
				httpIndex++;
				continue;
			}
		}
		var startStr = commentMemo.substring(0, httpIndex);
		var endStr = commentMemo.substring(httpIndex);

		endStr = endStr.replace(exp,"<a href='$1'>$1</a>");
		commentMemo = startStr + endStr;
		httpIndex += 20;
	}
	return commentMemo;
}

/*
 * Replace \r\n to <br /> in preview. Code and table don't processed 
 * 
 * @param {Object} commentMemo - input text with \r\n
 * @return {TypeName} - output text with <br />
 */
					
function replaceNewLineWithBR(commentMemo) {
	var startIndex = -1;
	var openSkipCodeIndexes = new Array();
	var closeSkipCodeIndexes = new Array();

	//commentMemo = commentMemo.toLowerCase();
	while ((startIndex = commentMemo.indexOf("<pre class=", startIndex)) > -1) {				
 		openSkipCodeIndexes.push(startIndex);
 		startIndex++;
	}
	startIndex = -1;
	while ((startIndex = commentMemo.indexOf("<table", startIndex)) > -1) {				
 		openSkipCodeIndexes.push(startIndex);
 		startIndex++; 		
	}
	if (openSkipCodeIndexes.length > 0) {
		startIndex = -1;
		while ((startIndex = commentMemo.indexOf("</pre>", startIndex)) > -1) {
 			closeSkipCodeIndexes.push(startIndex);
 			startIndex++;
		}
		startIndex = -1;
		while ((startIndex = commentMemo.indexOf("</table>", startIndex)) > -1) {	
 			closeSkipCodeIndexes.push(startIndex);
 			startIndex++;
		}
	}
	if (openSkipCodeIndexes.length == 0) {	
		commentMemo = commentMemo.replace(/\r/g, "");  // FF and Chrome don't contain \r
		commentMemo = commentMemo.replace(/\n/g, "<br />");	
	} else {
		var processedR = true;  // IE, Opera - contain \r\n, but FF,Chrome \n
		if (commentMemo.indexOf("\r") == -1) {
			processedR = false;
		}
		startIndex = -1;
		var shiftPosition = 0;
		while ((startIndex = commentMemo.indexOf("\n", startIndex)) > -1) {
			var processed = false;
			for (i = 0; i < closeSkipCodeIndexes.length; i++) {	
				if (startIndex < closeSkipCodeIndexes[i] + shiftPosition) {
					if (openSkipCodeIndexes[i] + shiftPosition < startIndex) {
						processed = true;
						break;
					}
				}
			}
			if (!processed) {
				if (processedR) {
					commentMemo = setCharAt(commentMemo,startIndex-1, "", 1);  // \r -> ''
					commentMemo = setCharAt(commentMemo,startIndex-1, "<br />", 1); // \n -> br
				} else {
					commentMemo = setCharAt(commentMemo,startIndex, "<br />", 1); // \n -> br
				}
				if (processedR) {
					shiftPosition += 4;
					startIndex += 4;
				} else {
					shiftPosition += 5;
					startIndex += 5;
				}
			}
			startIndex++;
		}		
	}
	return commentMemo;
}
