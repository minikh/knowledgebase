var mod_pagespeed_fB_sshTCZv = "jQuery(document).ready(function(a){\"use strict\";!function(){function b(a){var b=new RegExp(/^([\\w-\\.]+)@([\\w-\\.]+)\\.([\\w]{2,6})$/i);return b.test(a)}var c=a(\".jetpack--form\");c&&(c.on(\"click\",'input[type$=\"submit\"]',function(d){var e=a(this).prev(),f=e.val().trim(),g=a(this).parent();d.preventDefault(),\"\"===f?g.find(\".jetpack--error-empty\").removeClass(\"is-hidden\"):b(f)?a.ajax({url:ixrevoTheme.ajaxurl,type:\"POST\",dataType:\"json\",context:g,data:{action:\"subscription-widget-form-processing\",wpNonce:ixrevoTheme.wpNonce,email:f},success:function(b){\"success\"===b.subscribeStatus?(a(\".jetpack--desc\").hide(),c.hide(),a(\".jetpack--disclaimer\").hide(),a(\".subscription-widget--jetpack\").append(b.html)):\"already\"===b.subscribeStatus?(a(\".jetpack--desc\").hide(),c.hide(),a(\".jetpack--disclaimer\").hide(),a(\".subscription-widget--jetpack\").append(b.html)):\"invalid_email\"===b.subscribeStatus?a(this).find(\".jetpack--error-invalid\").removeClass(\"is-hidden\"):\"error\"===b.subscribeStatus&&a(this).find(\".jetpack--error-error\").removeClass(\"is-hidden\")},error:function(a,b,c){}}):g.find(\".jetpack--error-invalid\").removeClass(\"is-hidden\")}),c.on(\"keyup\",'input[type$=\"email\"]',function(b){b.preventDefault(),a(this).parent().find(\".jetpack--error-empty\").addClass(\"is-hidden\"),a(this).parent().find(\".jetpack--error-invalid\").addClass(\"is-hidden\"),a(this).parent().find(\".jetpack--error-error\").addClass(\"is-hidden\")}),a(\".subscription-widget--jetpack\").on(\"click\",\"#jetpack--try\",function(b){b.preventDefault(),a(\".jetpack--status\").hide(),a(\".jetpack--desc\").show(),c.show(),a(\".jetpack--disclaimer\").show()}))}()}),document.addEventListener(\"DOMContentLoaded\",function(){\"use strict\";var a,b,c=document.getElementById(\"main-navigation\"),d=document.getElementById(\"mobile-controls-menu\"),e=document.getElementById(\"mobile-controls-search\"),f=document.getElementById(\"mobile-controls-topics\"),g=document.getElementById(\"mobile-controls-topics--tablets\"),h=document.getElementById(\"mobile-controls\"),i=document.getElementById(\"site-title\"),j=document.getElementById(\"site-footer\"),k=!1,l=!1,m=\"unknown\",n=ixrevoTheme.mobile,o=ixrevoTheme.tablet,p=window.scrollY,q=10,r=72,s=function(){var a=window.innerWidth,b=\"\";return b=n>a?\"mobile\":o>a?\"tablet\":\"desktop\",b!==m?(m=b,!0):!1},t=function(){h.classList.add(\"is-sticky\"),i.classList.add(\"is-sticky\"),c.classList.add(\"is-sticky\")},u=function(){h.classList.remove(\"is-sticky\"),i.classList.remove(\"is-sticky\"),c.classList.remove(\"is-sticky\")},v=function(){c.classList.remove(\"is-search-open\"),e.classList.remove(\"is-active\"),l=!1},w=function(){c.classList.remove(\"is-menu-open\"),d.classList.remove(\"is-active\"),k=!1},x=function(){switch(m){case\"mobile\":v(),w();break;case\"tablet\":v(),w();break;case\"desktop\":v(),w(),u()}h.classList.remove(\"is-open\")},y=function(){k&&x(),c.classList.toggle(\"is-search-open\"),h.classList.toggle(\"is-open\"),e.classList.toggle(\"is-active\"),l=!l},z=function(){l&&x(),c.classList.toggle(\"is-menu-open\"),h.classList.toggle(\"is-open\"),d.classList.toggle(\"is-active\"),k=!k},A=function(){h.classList.add(\"is-slid-up\"),i.classList.add(\"is-slid-up\")},B=function(){h.classList.remove(\"is-slid-up\"),i.classList.remove(\"is-slid-up\")},C=function(){var a=j.offsetTop-h.offsetHeight;window.scrollTo(0,a)},D=function(a){a.addEventListener(\"touchend\",function(){this.classList.add(\"no-hover\")}),a.addEventListener(\"touchstart\",function(){this.classList.remove(\"no-hover\")}),a.addEventListener(\"mouseenter\",function(){this.classList.remove(\"no-hover\")})},E=function(){s(),D(g),D(e),D(d)};d.onclick=function(){z()},f.onclick=function(a){C(),z(),a.preventDefault()},g.onclick=function(){C()},e.onclick=function(){y()},window.onscroll=function(){var c=window.scrollY,d=window.innerHeight,e=document.documentElement.offsetHeight,f=k||l;Math.abs(p-c)!==q&&\"desktop\"!==m&&(a=j.offsetHeight,b=p-c>0?\"up\":\"down\",p=c,\"down\"===b&&p>r&&!f&&A(),p>12&&f&&t(),\"up\"!==b||f||(B(),t()),12>p&&u(),a>e-p-d&&(B(),t()))},window.onresize=function(){s()&&x()},E()});";
var mod_pagespeed_$Pnc9ZNdEI = "var addComment={moveForm:function(a,b,c,d){var e,f,g,h,i=this,j=i.I(a),k=i.I(c),l=i.I(\"cancel-comment-reply-link\"),m=i.I(\"comment_parent\"),n=i.I(\"comment_post_ID\"),o=k.getElementsByTagName(\"form\")[0];if(j&&k&&l&&m&&o){i.respondId=c,d=d||!1,i.I(\"wp-temp-form-div\")||(e=document.createElement(\"div\"),e.id=\"wp-temp-form-div\",e.style.display=\"none\",k.parentNode.insertBefore(e,k)),j.parentNode.insertBefore(k,j.nextSibling),n&&d&&(n.value=d),m.value=b,l.style.display=\"\",l.onclick=function(){var a=addComment,b=a.I(\"wp-temp-form-div\"),c=a.I(a.respondId);if(b&&c)return a.I(\"comment_parent\").value=\"0\",b.parentNode.insertBefore(c,b),b.parentNode.removeChild(b),this.style.display=\"none\",this.onclick=null,!1};try{for(var p=0;p<o.elements.length;p++)if(f=o.elements[p],h=!1,\"getComputedStyle\"in window?g=window.getComputedStyle(f):document.documentElement.currentStyle&&(g=f.currentStyle),(f.offsetWidth<=0&&f.offsetHeight<=0||\"hidden\"===g.visibility)&&(h=!0),\"hidden\"!==f.type&&!f.disabled&&!h){f.focus();break}}catch(q){}return!1}},I:function(a){return document.getElementById(a)}};";
var mod_pagespeed_K9vYsYrGhM = "!function(a,b){\"use strict\";function c(){if(!e){e=!0;var a,c,d,f,g=-1!==navigator.appVersion.indexOf(\"MSIE 10\"),h=!!navigator.userAgent.match(/Trident.*rv:11\\./),i=b.querySelectorAll(\"iframe.wp-embedded-content\");for(c=0;c<i.length;c++)if(d=i[c],!d.getAttribute(\"data-secret\")){if(f=Math.random().toString(36).substr(2,10),d.src+=\"#?secret=\"+f,d.setAttribute(\"data-secret\",f),g||h)a=d.cloneNode(!0),a.removeAttribute(\"security\"),d.parentNode.replaceChild(a,d)}else;}}var d=!1,e=!1;if(b.querySelector)if(a.addEventListener)d=!0;if(a.wp=a.wp||{},!a.wp.receiveEmbedMessage)if(a.wp.receiveEmbedMessage=function(c){var d=c.data;if(d.secret||d.message||d.value)if(!/[^a-zA-Z0-9]/.test(d.secret)){var e,f,g,h,i,j=b.querySelectorAll('iframe[data-secret=\"'+d.secret+'\"]'),k=b.querySelectorAll('blockquote[data-secret=\"'+d.secret+'\"]');for(e=0;e<k.length;e++)k[e].style.display=\"none\";for(e=0;e<j.length;e++)if(f=j[e],c.source===f.contentWindow){if(f.removeAttribute(\"style\"),\"height\"===d.message){if(g=parseInt(d.value,10),g>1e3)g=1e3;else if(200>~~g)g=200;f.height=g}if(\"link\"===d.message)if(h=b.createElement(\"a\"),i=b.createElement(\"a\"),h.href=f.getAttribute(\"src\"),i.href=d.value,i.host===h.host)if(b.activeElement===f)a.top.location.href=d.value}else;}},d)a.addEventListener(\"message\",a.wp.receiveEmbedMessage,!1),b.addEventListener(\"DOMContentLoaded\",c,!1),a.addEventListener(\"load\",c,!1)}(window,document);";
