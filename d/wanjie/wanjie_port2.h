//port2.h

//Sample for room: 澜沧江畔
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_port2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "澜沧江畔");


	add_door("万劫谷铁索桥", "万劫谷铁索桥", "万劫谷澜沧江畔");
	add_door("万劫谷山坡", "万劫谷山坡", "万劫谷澜沧江畔");

	set("long","这里是一个小山坡，西面是上山的路，东面一条铁索桥横跨江面，只见江水奔腾，呼啸而过，江风吹得铁索桥晃来晃去。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu3_5"))
	{
		say("山坡的拐角处似乎有一座茅屋。",me);
	}
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query("wei/renwu3"))
	{
		if(me->query("wei/renwu1") && me->query_temp("wei/renwu3_5") && !me->query_temp("wei/renwu3_7"))
		{
			int i;
			CContainer * env = me->environment();
			CContainer * canjiang;
			CContainer * canbing;
			CNpc * robber;
			if(!me->query_temp("wei/renwu3_6"))
			{
				canjiang=env->present("can jiang");
				if(!canjiang)
				{
					robber = load_npc("wei_canjiang");
					((CChar * )robber)->set("owner",me->id(1));
					((CChar * )robber)->move(env);
					
					canbing=env->present("can bing");
					if(!canbing)
					{
						for(i=0;i<4;i++)
							((CChar * )load_npc("wei_canbing"))->move(env);
					}
				}
				else
				{
					canbing=env->present("can bing");
					if(!canbing)
					{
						for(i=0;i<4;i++)
							((CChar * )load_npc("wei_canbing"))->move(env);
					}
				}
			}
			else
			{
				for(i=0;i<9;i++)
				{
					canbing=env->present("can bing");
					if(!canbing)
						break;
					else
					{
						destruct(canbing);
					}
				}
				tell_object(me,"余下众人见到首领已死，全都乱成一团，不一会儿便散了。");
				me->set_temp("wei/renwu3_7",1);//安全护送到达澜沧江畔
			}
		}
	}
}

ROOM_END;
