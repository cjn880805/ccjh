//road2.h

//Sample for room: 青石官道2
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青石官道2");
	
	add_npc("pub_gongzi");      // add by zdn 2001-07=16

	add_door("苏州北", "苏州北", "苏州青石官道2");
	add_door("扬州山路2", "扬州山路2", "苏州青石官道2");
	add_door("苏州虎丘山", "苏州虎丘山", "苏州青石官道2");

	set("long", "你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。南面就是苏州城了。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
