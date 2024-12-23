//houshan.h

//Sample for room:  重阳宫后山
//coded by zouwenbin
//data: 2000-12-2
//Last modify @ 2001-02-08
//Add a work.


ROOM_BEGIN(CRChongYang_houshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫后山");

	add_npc("quanzhen_wang");

	add_door("重阳宫小路", "重阳宫小路", "重阳宫后山");

	set("long", "这里已经出了重阳宫，到了终南山的后山。这里鸟语花香，空气清新，山势也平缓得多了。");
    

};

virtual int do_look(CChar * me)
{
	say("这里已经出了重阳宫，到了终南山的后山。这里鸟语花香，空气清新，山势也平缓得多了。",me);
	say("草地里长满了鲜嫩翠绿的萝卜，让人忍不住拔几个。", me);
	AddMenuItem("拔萝卜", "$9ba 0 luobo", me);
	AddMenuItem("算了", "", me);

	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	int i;
	if(strcmp(comm, "ba") == 0)
	{
		if (DIFFERSTR(arg, "luobo"))	return 0;

		if (me->is_busy())
		{
			return notify_fail("你现在正在忙……。");
		}

		CContainer * obj;
		message_vision("$N打量了一会地上的草，瞅准一株用力的拉，拉，拉啊……", me);
		if(random(5) == 0)
		{
			obj=load_item("luobo");	//萝卜
			obj->move(me);
			message_vision("只听乓的一声，$N摔倒在地上，手里抓了个老大萝卜。", me);
			i=random(me->query("level"))/2+1;
			me->add("combat_exp",i);
			me->start_busy(3);
			me->receive_damage("hp", i);
			return 1;
		}
		if(random(5) > 1)
		{
			message_vision("只听乓的一声，$N摔倒在地上，手中抓了一大把杂草。", me);
			i=random(me->query("level"))+1;
			me->start_busy(3);
			me->receive_damage("hp", i);
			return 1;
		}
		if(random(5) < 2 )
		{
			obj=load_item("caogeng");	//草根
			obj->move(me);
			message_vision("只听乓的一声，$N摔倒在地上，手里抓出一把草根。", me);
			i=random(me->query("level"))/4+1;
			me->add("combat_exp",i);
			me->start_busy(3);
			me->receive_damage("hp", i*2);
			return 1;
		}
		if(random(5) == 0)
		{
			obj=load_item("luobo");
			obj->move(me);
			message_vision("只听乓的一声，$N摔倒在地上，手里抓了个老大萝卜，砸到了自己脑袋。", me);
			i=random(me->query("level"))/2+1;
			me->add("combat_exp",i);
			me->start_busy(3);
			me->receive_wound("hp", i);
		}
			CChar * cat = load_npc("animal_wangcai");
			cat->move(me->environment());
			message_vision("突然你似乎听到两声狗叫……。", me);
			message_vision("一只狗扑了过来！", me);
			cat->kill_ob(me);
		return 1;
	}
	return 0;
}


ROOM_END;
