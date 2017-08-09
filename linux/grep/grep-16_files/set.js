// ----------------------------------------------------------------------------
// markItUp!
// ----------------------------------------------------------------------------
// Copyright (C) 2008 Jay Salvat
// http://markitup.jaysalvat.com/
// ----------------------------------------------------------------------------
// Html tags
// http://en.wikipedia.org/wiki/html
// ----------------------------------------------------------------------------
// Basic set. Feel free to add more tags
// ----------------------------------------------------------------------------
articleSettings = {
	onShiftEnter:	{keepDefault:false, openWith:'<br/>'},
//	onCtrlEnter:	{keepDefault:false, openWith:'\n<p>', closeWith:'</p>\n'},
//	onEnter:	{keepDefault:false, openWith:'<br/>\n'},
	onTab:			{keepDefault:false, openWith:'	 '},
	markupSet: [
		{name:'Заголовок',  className:'header1', openWith:'<h1(!( class="[![Class]!]")!)>', closeWith:'</h1>', placeHolder:'Заголовок...' },
		{name:'Подзаголовок', className:'header2', openWith:'<h2(!( class="[![Class]!]")!)>', closeWith:'</h2>', placeHolder:'Подзаголовок...' },
		{separator:'---------------' },
		{name:'Полужирный', className:'bold', openWith:'(!(<strong>|!|<b>)!)', closeWith:'(!(</strong>|!|</b>)!)' },
		{name:'Курсив', className:'italic', openWith:'(!(<em>|!|<i>)!)', closeWith:'(!(</em>|!|</i>)!)' },		
		{name:'Подчеркнутый', className:'underline' , openWith:'<span style="text-decoration: underline">', closeWith:'</span>' },
		{name:'Зачеркнутый', className:'stroke', openWith:'<span style="text-decoration: line-through;">', closeWith:'</span>' },
		{separator:'---------------' },
		{name:'По левому краю', className:'text_align_left', openWith:'<p style="text-align : left">', closeWith:'</p>' },
		{name:'По центру', className:'text_align_center', openWith:'<p style="text-align : center">', closeWith:'</p>' },
		{name:'По правому краю', className:'text_align_right', openWith:'<p style="text-align : right">', closeWith:'</p>' },
		{name:'По ширине', className:'text_align_justify', openWith:'<p style="text-align : justify">', closeWith:'</p>' },		
		{separator:'---------------' },
		{name:'Маркированный список', className:'list-bullet', openWith:'<ul>\n', closeWith:'</ul>\n' },
		{name:'Нумерованный список', className:'list-numeric', openWith:'<ol>\n', closeWith:'</ol>\n' },
		{name:'Элемент списка', className:'list-item', openWith:'<li>', closeWith:'</li>' },
		{separator:'---------------' },
		{name:'Линк', className:'link', openWith:'<a href="[![Link:!:http://]!]"(!( title="[![Title]!]")!)>', closeWith:'</a>', placeHolder:'Your text to link...' },
		{name:'Фото', className:'photo',
			beforeInsert:function(markItUp) {
				$("#uploadFormHolder").dialog( "option", "width", 420 );
               	//$("#uploadFormHolder").dialog( "option", "height", 175 );
               	//openDialogForm('uploadFormHolder');							
				loadUploadForm('photo', 'uploadFormHolder', 'markitup', '/');
			}
		},
		{name:'Видео', className:'video',	
			beforeInsert:function(markItUp) {
				$("#uploadFormHolder").dialog( "option", "width", 370 );
               	//$("#uploadFormHolder").dialog( "option", "height", 215 );
               	//openDialogForm('uploadFormHolder');			
				loadUploadForm('video', 'uploadFormHolder', 'markitup', '/');
			}
		},
		{name:'Добавить программный код', className:'code',
			beforeInsert:function(markItUp) {
				$("#uploadFormHolder").dialog( "option", "width", 715 );
                //$("#uploadFormHolder").dialog( "option", "height", 715 );
                //openDialogForm('uploadFormHolder');	
				loadUploadForm('code', 'uploadFormHolder', 'markitup', '/');
            }
         },
		{separator:'---------------' },
		{name:'Кат маркер', className:'cut_marker', openWith:"<hr><a name='cut' />\n" },
		{name:'Очистить от тегов (сначала выделите текст)', className:'clean', replaceWith:function(markitup) { return markitup.selection.replace(/<(.*?)>/g, "") } },
		{name:'Предварительный просмотр', className:'preview', call:'preview' }
	]
}

commentSettings = {
	onShiftEnter:	{keepDefault:false, openWith:'<br/>'},
//	onCtrlEnter:	{keepDefault:false, openWith:'\n<p>', closeWith:'</p>\n'},
//	onEnter:	{keepDefault:false, openWith:'\n'},
	onTab:			{keepDefault:false, openWith:'	 '},
	markupSet: [		
		{name:'Полужирный', className:'bold', openWith:'(!(<strong>|!|<b>)!)', closeWith:'(!(</strong>|!|</b>)!)' },
		{name:'Курсив', className:'italic', openWith:'(!(<em>|!|<i>)!)', closeWith:'(!(</em>|!|</i>)!)' },		
		{separator:'---------------' },
		{name:'Линк', className:'link', openWith:'<a href="[![Link:!:http://]!]"(!( title="[![Title]!]")!)>', closeWith:'</a>', placeHolder:'Your text to link...' },
		{name:'Фото', className:'photo',
			beforeInsert:function(markItUp) {
				$("#uploadFormHolder").dialog( "option", "width", 420 );
               	//$("#uploadFormHolder").dialog( "option", "height", 175 );
               	//openDialogForm('uploadFormHolder');							
				loadUploadForm('photo', 'uploadFormHolder', 'markitup', '/');
			}
		},
		{name:'Видео', className:'video',	
			beforeInsert:function(markItUp) {
				$("#uploadFormHolder").dialog( "option", "width", 370 );
               	//$("#uploadFormHolder").dialog( "option", "height", 215 );
               	//openDialogForm('uploadFormHolder');			
				loadUploadForm('video', 'uploadFormHolder', 'markitup', '/');
			}
		},
		{name:'Добавить программный код', className:'code',
			beforeInsert:function(markItUp) {
				$("#uploadFormHolder").dialog( "option", "width", 715 );
                //$("#uploadFormHolder").dialog( "option", "height", 715 );
                //openDialogForm('uploadFormHolder');	
				loadUploadForm('code', 'uploadFormHolder', 'markitup', '/');
            }
         },
		{separator:'---------------' },
		{name:'Предварительный просмотр', className:'preview', call:'preview' }
	]
}