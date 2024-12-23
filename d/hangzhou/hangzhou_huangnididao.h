//huangnididao.h 杭州黄泥地道


ROOM_BEGIN(CRhangzhou_huangnididao);

virtual void create()		
{
	set_name( "杭州黄泥地道");

	add_npc("wei_nixiang");

	add_door("杭州青石大道6", "杭州青石大道6", "杭州黄泥地道");

	set("long","此处没有出路，只有一个泥像。");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu8_5"))
	{
		say("倒下的泥像背后露出一道门来。", me);
		AddMenuItem("进门", "$0jin $1", me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
	if(strcmp(comm, "jin") == 0)
		return do_jin(me, arg);
	return 0;
}

int do_jin(CChar *me, char * arg)
{
	me->move(load_room("杭州毒液地道左岸"));
	return 1;
}

ROOM_END;
