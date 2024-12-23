//xin.h 

ITEM_BEGIN(CItongxinyin)

virtual void create(int nFlag = 0)		
{
	 set_name("同心印", "concentric mark");
     set_weight(100);
        
     set("unit", "盒");
     set("material", "steel");
 	 set("no_get",1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	char msg[255];
	if (EQUALSTR(me->querystr("gender"), "无性"))
		return notify_fail("……太监也想……？");


	if (!querystr("teapot/male")[0] && EQUALSTR(me->querystr("gender"), "女性"))
		return notify_fail("同心印的阳部还没有被激发……");					// ???

	if (querystr("teapot/male")[0] && EQUALSTR(me->querystr("gender"), "男性"))
		return notify_fail("这个……自恋与同性恋领先于这个时代……");		// ???

	if ((me->query("age") < 18) && EQUALSTR(me->querystr("gender"), "男性")
		|| (me->query("age") < 16) && EQUALSTR(me->querystr("gender"), "女性"))
		return notify_fail("太小了点吧……！青梅竹马也不用这么着急啊。");


	if (me->is_busy())
		return notify_fail("你现在很忙。");
	if( me->is_fighting() )
		return notify_fail("你先还是料理完你的朋友再说吧。");
	if( EQUALSTR(me->querystr("class"), "bonze"))
		return notify_fail("和尚……和尚……");
	//if( EQUALSTR(me->querystr("class"), "taoist" ))
	//	return notify_fail("道士也结婚？");
	
	if( me->querymap("couple"))	
		return notify_fail("你不专情，同心印不采你。");
	
	if( me->query("couple_betray") > 1 )	
		return notify_fail("你不专情，同心印不采你。");
	
	if (!querystr("teapot/male")[0])
	{
		set("teapot/male",me->querystr("id"));
		set("teapot/malename",me->querystr("name"));
		message_vision("$N轻轻的将手覆盖在同心印上，用柔和的目光看着缄印……",me);
		message_vision("只见同心印的阳部散发出淡淡的橘黄色光芒……",me);
		set_name("散发着淡黄微光的同心印");
		remove_call_out(remove_telepathy);
		call_out(remove_telepathy, 30);
		return 1;
	}

	CContainer * obj;
	obj=me->environment();

	CChar * player1;
	player1=(CChar * ) obj->present(querystr("teapot/male"));

	if(!player1 )
	{
		return notify_fail("你好不容易下定决心，可是……他呢？");
	}

	//if (EQUALSTR(player1->querystr("id"), me->querystr("last_couple_id")))
	//{
	//	return notify_fail("同心印道：嘎嘎。。。你们不是才离婚吗？");
	//}

		remove_call_out(remove_telepathy);
		
		set("teapot/female",me->querystr("id"));
		set("teapot/femalename",me->name(1));
		message_vision("$N闭上眼睛，微微吐出一口气，将手放在同心印上……",me);
		message_vision("只见同心印的阴部散发出淡淡的浅兰色光芒……",me);
			
		g_Channel.do_channel(&g_Channel, 0, "news", 
				snprintf(msg, 255, "%s与%s今日指天为誓，拜土为盟，永结同心，生生世世，不违此约……", querystr("teapot/femalename"),querystr("teapot/malename")));

		//Modified by lanwood 2001-03-15
		me->set("couple/id", player1->querystr("id"));
		me->set("couple/name", player1->querystr("name"));
		me->set("couple/gender", "老公");

		player1->set("couple/id", me->querystr("id"));
		player1->set("couple/name", me->querystr("name"));
		player1->set("couple/gender", "老婆");

		player1->set_temp("teapot/m_m", 1);	//可以发礼物的标记

		/*
		me->set("teapot/marry",querystr("teapot/male").c_str());
		me->set("teapot/marryname",querystr("teapot/malename").c_str());

		player1->set("teapot/marry",querystr("teapot/female").c_str());
		player1->set("teapot/marryname",querystr("teapot/femalename").c_str());		
		*/

		message_vision("刹那间一阵亮光照过，同心印化作一丝轻烟而去，只听天空中有人声传来：好……人间因缘簿上，今日又多一笔！",me);

		destruct(this);

	return 1;


//我能不能改变channel的发言者，不要“频道精灵”？


}




static void remove_telepathy(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	ob->del("teapot/male");
	ob->del("teapot/malename");
	ob->set_name("同心印");

	if(userp(me))
		tell_object((CChar *)me, "同心印的光芒慢慢的消退了……");
	else
		tell_room(me, "同心印的光芒慢慢的消退了……");

//	destruct(ob);
	return;
}






ITEM_END;







// 爱欲生忧 从忧生怖 若离於爱 何忧何怖