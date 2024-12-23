//road6.h

//Sample for room: 杭州青石大道6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道6");

	//add npcs into the room
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumangtou");
	
	//add_door("杭州岳廊", "杭州岳廊", "杭州青石大道6");
	add_door("杭州苏堤1", "杭州苏堤1", "杭州青石大道6");
	add_door("杭州青石大道7", "杭州青石大道7", "杭州青石大道6");
	add_door("杭州青石大道5", "杭州青石大道5", "杭州青石大道6");

	set("long","大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。大道延伸向东西两边。南边则通往苏堤。北边是岳王庙。");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu8_2")&& !me->query_temp("wei/renwu8_4"))
	{
		AddMenuItem("观察木桩子", "$0kan $1", me);
	}
	if(me->query_temp("wei/renwu8_3") && !me->query_temp("wei/renwu8_4"))
	{
		AddMenuItem("对木桩使用剑", "$0jian $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_2"))
		return 0;
	if(strcmp(comm, "kan") == 0)
		return do_kan(me, arg);
	if(strcmp(comm, "jian") == 0)
		return do_jian(me, arg);
	return 0;
}

int do_kan(CChar *me, char * arg)
{
	say("这是一个粗大的圆木桩，就像是被锯得整整齐齐的老树根。仔细观察木桩表面，可看到正中间有一个扁平如长剑身的小洞。", me);
	SendMenu(me);
	me->set_temp("wei/renwu8_3",1);//观察过了树桩
	return 1;
}

int do_jian(CChar *me, char * arg)
{
	CContainer * jian=me->present("changjian");
	if(jian)
	{
		tell_object(me,"你拨出一把长剑，对着木桩表面的小洞用力插了进去，只露出剑柄。");
		tell_object(me,"木桩下的地面发出喀嚓一声轻响。");
		tell_object(me,"一阵巨大的“轰隆隆”声传了过来，地面突然出现一个一丈见方的黑洞，你不由自主地掉了下去！");
		me->set_temp("wei/renwu8_4",1);//掉进了地洞
		me->move(load_room("杭州黄泥地道"));
	}
	else
	{
		say("你左右乱看，一筹莫展。", me);
		SendMenu(me);
	}
	return 1;
}

ROOM_END;
