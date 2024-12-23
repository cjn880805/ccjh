//qianrenshi.h

//Sample for room: 千人石
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_qianrenshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "千人石");
	
	add_npc("pub_poorman");         //add by zdn 2001-07-16


	add_door("苏州二仙亭", "苏州二仙亭", "苏州千人石");
	add_door("苏州致爽阁", "苏州致爽阁", "苏州千人石");
	add_door("苏州试剑石", "苏州试剑石", "苏州千人石");

	
/*****************************************************
	set("exits", ([
		"east"      : __DIR__"erxianting",
		"north"     : __DIR__"shijianshi",
		"northwest" : __DIR__"zhishuang",
	]));
********************************************/
};


ROOM_END;
