//xiaoyao_kongdi.h 空地
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_kongdi);

virtual void create()
{
	set_name( "空地");

	add_item("mupai");

	add_door("逍遥谷紫莲峰山路5", "逍遥谷紫莲峰山路5", "逍遥谷空地");	
	add_door("逍遥谷青龙塔", "逍遥谷青龙塔", "逍遥谷空地");	
	add_door("逍遥谷玄武塔", "逍遥谷玄武塔", "逍遥谷空地");	
	add_door("逍遥谷朱雀塔", "逍遥谷朱雀塔", "逍遥谷空地");	
	add_door("逍遥谷白虎塔", "逍遥谷白虎塔", "逍遥谷空地");	

};

virtual int do_look(CChar * me)
{
	if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_5")  )
	{
		say("空地上有一朵野菊花，一朵红玫瑰。",me);
		if(me->query_temp("xy/renwu4_1") && !me->query("xy/renwu4_41"))
		{
			CContainer * env = load_room("逍遥谷空地");
			if(me->query_temp("xy/renwu4_1")==2)//邀请的是李秋痕
			{
				//检查李秋痕是否在逍遥谷空地
				CContainer * liqiouhen=env->present("li qiou heng");
				if(liqiouhen)
				{
					say("李秋痕摘下一朵野菊花，轻轻地插在鬓边，转头向你嫣然一笑：“你看师叔我美吗？”",me);
					AddMenuItem("赞美李秋痕", "$0zhanmei $1",me);	
					AddMenuItem("不置可否", "$0bushuo $1",me);
				}
			}
			else//邀请的是天山铁姥
			{
				CContainer * tielao=env->present("tong lao");
				if(tielao)
				{
					say("天山铁姥摘下一朵野菊花插在鬓边，忍不住轻轻叹了一口气：“唉！”",me);
					AddMenuItem("赞美天山铁姥", "$0zhanmei1 $1",me);	
					AddMenuItem("不置可否", "$0bushuo1 $1",me);
				}
			}
			me->set("xy/renwu4_41",1);
		}
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("xy/renwu4_1") ||!me->query("xy/renwu4_3")  )
		return 0;
	CContainer * env = load_room("逍遥谷空地");
	if(me->query_temp("xy/renwu4_1")==2)
	{
		CContainer * liqiouhen=env->present("li qiou heng");
		if(liqiouhen)
		{
			if(!strcmp(comm, "zhanmei") && !me->query("xy/renwu4_41_1"))
				return do_zhanmei(me, arg);
			if(!strcmp(comm, "bushuo") && !me->query("xy/renwu4_41_2"))
				return do_bushuo(me, arg );
			if(!strcmp(comm, "rose") && !me->query("xy/renwu4_41_3"))
				return do_rose(me, arg);
			if(!strcmp(comm, "dai") && !me->query("xy/renwu4_41_4"))
				return do_dai(me, arg);
		}
	}
	else
	{	
		CContainer * tielao=env->present("tong lao");
		if(tielao)
		{
			if(!strcmp(comm, "zhanmei1") && !me->query("xy/renwu4_41_5"))
				return do_zhanmei1(me, arg);
			if(!strcmp(comm, "bushuo1") && !me->query("xy/renwu4_41_6"))
				return do_bushuo1(me, arg);
			if(!strcmp(comm, "dai1") && !me->query("xy/renwu4_41_7"))
				return do_dai1(me, arg);
			if(!strcmp(comm, "budai") )
				return do_budai(me, arg);
		}
	}
	return 0;
}

int do_zhanmei(CChar *me, char * arg)
{
	say("你赞道：“师叔的容颜，可谓姣若明月，媚如秋水，当真可迷死天下男人！”",me);
	if(EQUALSTR(me->querystr("gender"), "女性"))
	{
		say("李秋痕在你脸蛋上轻轻拧了一把，嗔道：“小丫头，竟然敢取笑你师叔！”",me);	
	}
	else
	{
		say("李秋痕轻啐了你一口道：“不正经！”",me);
	}
	if(!me->query("xy/renwu4_41_1"))
	{
		me->add("xy/完成度",1);
		me->set("xy/renwu4_41_1",1);
	}

	AddMenuItem("拾起红玫瑰送给李秋痕", "$0rose $1",me);
	if(EQUALSTR(me->querystr("gender"), "女性"))
	{
		AddMenuItem("拾起红玫瑰送给李秋痕", "$0rose $1",me);
		AddMenuItem("拾起红玫瑰插自己头上", "$0dai $1",me);
	}
	else if(EQUALSTR(me->querystr("gender"), "男性"))
		AddMenuItem("拾起红玫瑰送给李秋痕", "$0rose $1",me);
	SendMenu(me);
	
	return 1;
}

int do_bushuo(CChar *me, char * arg)
{
	say("你说道：“不就是头上插了朵野花嘛，没有什么区别呀！”",me);
	say("李秋痕“哼”了一声。",me);
	
	if(!me->query("xy/renwu4_41_2"))
	{
		me->add("xy/完成度",-1);
		me->set("xy/renwu4_41_2",1);
	}

	AddMenuItem("拾起红玫瑰送给李秋痕", "$0rose $1",me);
	if(EQUALSTR(me->querystr("gender"), "女性"))
	{
		AddMenuItem("拾起红玫瑰送给李秋痕", "$0rose $1",me);
		AddMenuItem("拾起红玫瑰插自己头上", "$0dai $1",me);
	}
	else if(EQUALSTR(me->querystr("gender"), "男性"))
		AddMenuItem("拾起红玫瑰送给李秋痕", "$0rose $1",me);
	SendMenu(me);
	
	return 1;
}

int do_rose(CChar *me, char * arg)
{
	if(EQUALSTR(me->querystr("gender"), "女性"))
	{
		say("你将红玫瑰放在李秋痕手上，说道：“以师叔这般美艳，若以红玫相衬似乎更加合适！”",me);	
		say("李秋痕笑道：“你这小丫头，还蛮讨人欢喜的，不像我那不知趣的师姐，一天到晚只知道和我作对！”",me);
	}
	else if(EQUALSTR(me->querystr("gender"), "男性"))
	{
		say("你将轻轻将红玫瑰插在李秋痕的发髻之上：“野菊虽美，只能装点秋色。以师叔这般的绝色红颜，当以红玫热辣奔放之美方可相衬！”",me);	
		say("李秋痕用力在你脸上亲了一口，轻佻地笑道：“师侄小小年纪，就这般会讨女人欢心，将来定是个情中圣手！”",me);
	}
	if(!me->query("xy/renwu4_41_3"))
	{
		me->add("xy/完成度",1);
		me->set("xy/renwu4_41_3",1);
	}
	SendMenu(me);
	return 1;
}

int do_dai(CChar *me, char * arg)
{
	if(me->query("per")<36)
	{
		say("你把玫瑰插在头上，嘻嘻笑道：“师叔戴花，我也戴花！”",me);
		say("李秋痕冲你呵呵一笑：“小丫头可真调皮！”",me);
	}
	else
	{
		say("你轻轻地把红玫瑰插在头上，一时间，鲜花的娇艳映衬得你越发美丽动人，相形之下，竟比李秋痕不让分毫。",me);
		say("李秋痕冷哼了一声：“小小年纪，就会学人招摇了！”",me);
		if(!me->query("xy/renwu4_41_4"))
		{
			me->add("xy/完成度",-1);
			me->set("xy/renwu4_41_4",1);
		}
	}
	SendMenu(me);
	return 1;
}

int do_zhanmei1(CChar *me, char * arg)
{
	say("你看着天山铁姥，不禁动容道：“想不到师伯也是这般美貌，平日里我怎么就未曾留意呢！”",me);
	say("天山铁姥面露妒色道：“那是因为平日里你只顾着看你李秋痕师叔去了，就跟师弟一个模样！”",me);	
	if(!me->query("xy/renwu4_41_5"))
	{
		me->add("xy/完成度",1);
		me->set("xy/renwu4_41_5",1);
	}

	AddMenuItem("拾起红玫瑰插自己头上", "$0dai1 $1",me);
	AddMenuItem("还是不要拾起红玫瑰为好", "$0budai $1",me);
	SendMenu(me);
	
	return 1;
}

int do_bushuo1(CChar *me, char * arg)
{
	say("你说道：“好端端的，师伯你叹啥气呀！”",me);
	say("天山铁姥恶狠狠地瞪了你一眼。",me);

	if(!me->query("xy/renwu4_41_6"))
	{
		me->add("xy/完成度",-1);
		me->set("xy/renwu4_41_6",1);
	}

	AddMenuItem("拾起红玫瑰插自己头上", "$0dai1 $1",me);
	AddMenuItem("还是不要拾起红玫瑰为好", "$0budai $1",me);

	SendMenu(me);

	return 1;
}

int do_dai1(CChar *me, char * arg)
{
	if(EQUALSTR(me->querystr("gender"), "女性"))
	{
		say("天山铁姥冷冷地看了你一眼。",me);
		if(me->query("per")>30 && !me->query("xy/renwu4_41_6"))
			{
				me->add("xy/完成度",-1);
				me->set("xy/renwu4_41_6",1);
			}
	}
	else
	{
		say("你摘下一朵红玫瑰插在自己头上。",me);
		say("天山铁姥睁圆眼睛瞪着你怒道：“你认为我戴花就像男人戴花一样可笑吗！”",me);
		me->add("xy/完成度",-1);
	}
	SendMenu(me);
	return 1;
}

int do_budai(CChar *me, char * arg)
{
	return 1;
}
XiaoYao_END;
