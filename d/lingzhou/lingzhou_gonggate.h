//gonggate.h

//Sample for room: 皇宫大门
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_gonggate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "皇宫大门");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     // add by zdn 2001-07-20
	add_npc("pub_liqiuhen");

	add_door("灵州西", "灵州西", "灵州皇宫大门");
	add_door("灵州皇宫大道", "灵州皇宫大道", "灵州皇宫大门");

	set("long", "这里就是西夏皇宫正门，四扇宽阔的朱红大门，上面包着拳头大的铜钉。门的两边站着两排衣甲鲜明的武士，戒备深严。");  

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	CContainer * env=me->environment();
	if(EQUALSTR(dir,"灵州皇宫大道"))
	{
		if(!me->query("lj/renwu11"))
		{
			message_vision("$HIR皇宫卫士伸手拦住了你，“大胆狂徒，皇宫也是你可以乱闯的地方？”", me);
			return 0;
		}
		else if(env->query("start") && env->query("start")!=atoi(me->id(1)))
		{
			message_vision("$HIR皇宫卫士伸手拦住了你，“竹虚先生刚才已经进去了，你一定是假冒的！”", me);
			return 0;
		}
		else if(EQUALSTR(me->querystr("gender"), "女性") )
		{
			if(DIFFERSTR(me->querystr_temp("apply/name"),"竹虚"))
			{
				message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你是女人，何必来参加比武招亲呢？！”", me);
				me->set("lj/renwu110",1);
				return 0;
			}
			else if(!me->query_temp("lj/renwu111"))
			{
				message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你的易容术未免有点浅薄了……”", me);
				me->set("lj/renwu110",1);
				return 0;
			}
			else
			{
				message_vision("$HIR皇宫卫士向你行了个礼，“竹虚先生，比武招亲大会马上就要开始了，请您快点进！”", me);
				if(me->query("lj/renwu110"))
					me->del("lj/renwu110");
				env->set("start",atoi(me->id(1)));
				me->set("lj/renwu12",1);
				return CRoom::valid_leave(me, dir);
			}
		}
		else
		{
			message_vision("$HIR我昏！你是男的，怎么可能接到这个任务呢？出老千呀！", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
