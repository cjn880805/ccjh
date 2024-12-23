//shijianshi.h

//Sample for room: 试剑石
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_shijianshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "试剑石");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("苏州枕石", "苏州枕石", "苏州试剑石");
	add_door("苏州孙武亭", "苏州孙武亭", "苏州试剑石");
	add_door("苏州千人石", "苏州千人石", "苏州试剑石");
	add_door("苏州万景山庄", "苏州万景山庄", "苏州试剑石");


/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"zhenniang",
		"south"     : __DIR__"qianrenshi",
		"north"     : __DIR__"zhenshi",
		"westdown"  : __DIR__"wanjing",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
********************************************/
};


ROOM_END;
