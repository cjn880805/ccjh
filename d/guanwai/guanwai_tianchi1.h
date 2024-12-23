//tianchi1.h

//Sample for room: 白头山天池1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_tianchi1);

virtual void create()			
{
	set_name( "白头山天池1");
	
	add_npc("pub_playboy");   

	set("monster_chance", 2);

	add_door("关外龙门峰", "关外龙门峰", "关外白头山天池1");
	add_door("关外白云峰", "关外白云峰", "关外白头山天池1");
	add_door("关外华盖峰", "关外华盖峰", "关外白头山天池1");
	add_door("关外白头山天池2", "关外白头山天池2", "关外白头山天池1");

	set("long","“天池在长白山巅中心点，群峰环抱，离地高约二十里，故名天池。”天池碧波盈盈，清澈湛蓝。湖周围峭壁百丈，峰影云影倒映其中，湖光山色、岚影云天十分诱人。湖岸周遭芳草茵茵，百花吐艳。古人诗云：“周迥八十里，峭壁立池边。水满疑天池，云低别有天。江山宜漫画，鹿逐结前缘。予卜携书隐，遨游慰晚年。”" );
    
};

virtual int do_look(CChar * me)
{
	say("“天池在长白山巅中心点，群峰环抱，离地高约二十里，故名天池。”天池碧波盈盈，清澈湛蓝。湖周围峭壁百丈，峰影云影倒映其中，湖光山色、岚影云天十分诱人。湖岸周遭芳草茵茵，百花吐艳。", me);
	say("古人诗云：“周迥八十里，峭壁立池边。水满疑天池，云低别有天。江山宜漫画，鹿逐结前缘。予卜携书隐，遨游慰晚年。”", me);
	if (me->query_temp("gumu/jq_gu") && !me->query_temp("gumu/read"))
	{
		say("靠近天池的不远，有一处显得有些不同的景象。这里杂草众多，在杂草从中遮掩着一个山洞，深不见底，不知道秘密是不是就在这里，你陷入了犹豫中。",me);
		AddMenuItem("豁出去了，跳进山洞", "$0jump $1", me);
		AddMenuItem("好深的一个洞哟，还是算了吧", "$0no $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("gumu/jq_gu"))
		return 0;
	if(strcmp(comm, "jump") == 0)
		return do_ssb(me, arg);
	if(strcmp(comm, "no") == 0)
		return do_no(me, arg);
	return 0;
}


int do_ssb(CChar *me, char * arg)
{
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。");
	
   	message_vision("$N犹豫了一下还是跳了下去", me);
	if(random(2)||me->query_temp("gumu/read"))
	{
		message_vision( "$N一脚踩了个空，摔的遍体鳞伤。", me);
		me->set("hp",me->query("hp")/4);
		me->start_busy(3);
		message_vision("$HIR$N看看了周围，忽然发现似乎回到了一个熟悉的地方。",me);
		me->move(load_room("古墓休息室"));
	}
	else
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
			{
				me->set_temp("gumu/zuobi",1);
				break;
			}
		}
		if(!me->query_temp("gumu/zuobi"))
		{
			message_vision( "$HIR$N掉下去屁股正好坐在花刺上，疼的晕了过去。", me);
			me->start_busy(15);
			me->move(load_room("绝情谷"));
		}
		else
		{
			message_vision( "$N一脚踩了个空，摔的遍体鳞伤。", me);
			me->set("hp",me->query("hp")/4);
			me->start_busy(3);
			message_vision("$HIR$N看看了周围，忽然发现似乎回到了一个熟悉的地方。",me);
			me->move(load_room("古墓休息室"));
			me->delete_temp("gumu/zuobi");
		}
	}
	return 1;
}

int do_no(CChar *me, char * arg)
{
	me->delete_temp("gumu/jq_gu");
	return 1;
}

ROOM_END;




