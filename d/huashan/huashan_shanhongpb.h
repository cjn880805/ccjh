//shanhongpb.h

//Sample for room: 华山山洪瀑布
//coded by zouwenbin
//data: 2000-12-2
//Last modify @ 2001-03-08
//by Teapot
//华山弃剑谷

ROOM_BEGIN(CRHuaShan_shanhongpb);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山山洪瀑布");

	add_door("华山莎萝坪", "华山莎萝坪", "华山山洪瀑布");

	set("long", "这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的瀑布。传说当年神雕侠杨过就是在这里练成绝世的玄铁剑法的。现在人去谷空，只剩下空寥的山谷和奔腾的洪水(hongshui)。");  

};

virtual int do_look(CChar * me)
{
	say("这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的瀑布。传说当年独孤不败就是在这里弃剑的。现在人去谷空，只剩下空寥的山谷和奔腾的洪水。", me);
	AddMenuItem("弃剑", "$0forsake $1", me);
	AddMenuItem("还是算了", "", me);
	if(me->query("level")>45 && EQUALSTR(me->querystr("family/family_name"), "华山派") //等级超过45级、学会独孤九剑的华山弟子可以触发此任务
		&& !me->query_temp("was/renwu1_1") && me->query_skill("lonely_sword",1))
	{
		AddMenuItem("练剑", "$0lianjian $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(me->query("level")>45 && EQUALSTR(me->querystr("family/family_name"), "华山派") 
		&& !me->query_temp("was/renwu1_1") && me->query_skill("lonely_sword",1))
	{
		if(!strcmp(comm, "lianjian") )
			return do_lianjian(me, arg);
		else if(!strcmp(comm, "pishi") )
			return do_pishi(me, arg);
	}
	if(strcmp(comm, "forsake") == 0)
	{
		DTItemList * list = me->Get_ItemList();
		CContainer * item = 0;
		POSITION pos;
		int flag = 0;
										
		pos = list->GetHeadPosition();
		while(pos)
		{
			item = list->GetNext(pos);
			if (item->query("teapot/brand")==1)
			{
				flag = 1;
				break;
			}	
		}
	
		if (!flag || ! item)
		{
			return notify_fail("原无剑，如何弃？");				
		}
		
				
		message_vision("$N长啸一声，将手中$n抛入滚滚山洪，刹时不见……", me, item);
		DESTRUCT_OB(item, "huanshan_shanhongpb");
		
		me->set("teapot/cumpower",0l);
		me->add("teapot/referent",-1);
		me->Save();
		
		return 1;
	}

	return 0;
}

int do_lianjian(CChar *me, char * arg)
{
	say("你一剑随意空刺，出招犹如行云流水绵绵不绝……",me);
	say("忽然间，你看到远处瀑布里仿佛有个洞，于是你施展轻功，轻轻一跃到瀑布底端，又一步一步往上纵跃。",me);
	say("突然，你往上一看，惊见一巨石正顺瀑布而下往你冲来。",me);
	AddMenuItem("劈石", "$0pishi $1", me);
	SendMenu(me);
	return 1;
}

int do_pishi(CChar *me, char * arg)
{
	say("你右手抽出腰间配剑，以无匹剑意疾劈巨石。",me);
	say("巨石转眼便至，你自感无法以九剑中的任何一剑破之……",me);
	
	if(me->query_skill("lonely_sword",1)>200 &&
		(me->query_skill("feiyan_huixiang",1)>150||me->query_skill("huashan_shenfa",1)>150))
	{
		say("不过此时你的剑法已经炉火纯青，不再拘泥于剑招。于是你暗自冥想，右手同时出剑，意至则剑至，雷霆万钧的一剑将巨石劈成两半。",me);
		say("你轻易纵腾，不费一盏茶工夫便跃进瀑布后的洞内。",me);
		me->move(load_room("华山瀑布后山洞"));
		me->set_temp("was/renwu1_1",1);//启动万安寺六派任务
	}
	else
	{
		say("你试图自创剑招劈石，然而力有所不达。只见巨石狂风闷雷般轰向你的身体，你从十丈高的地方被轰至瀑布底，登时晕厥过去。",me);
		me->unconcious();
	}
	SendMenu(me);
	return 1;
}
ROOM_END;
