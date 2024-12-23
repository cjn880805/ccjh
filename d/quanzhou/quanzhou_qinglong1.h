//qinglong1.h

//Sample for room: 泉州青龙会大庭
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州青龙会大庭");

	add_npc("quanzhou_nanchen");
	add_npc("quanzhou_xmdog");
	add_npc("pub_robotseller");

	add_door("泉州青龙会前庭", "泉州青龙会前庭", "泉州青龙会大庭");

//	set("no_clean_up", 1);
	set("no_fight",1);
    set("no_steal",1);
    set("no_beg",1);
	
/*****************************************************
	set("exits", ([
		"east" : __DIR__"qinglong",
	]));
********************************************/
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if(strcmp(comm, "say") == 0)
		{
			tell_object(me, "这里不许用这个频道说话");
			return 1;
		}
		return 0;
	}

	return CRoom::handle_action(comm, me, arg, target);
}

ROOM_END;




