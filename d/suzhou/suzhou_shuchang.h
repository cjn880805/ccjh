//shuchang.h

//Sample for room: 书场
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_shuchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书场");

	//add npcs into the room
	add_npc("pub_gongzi");/////////////////////////

	add_door("苏州中", "苏州中", "苏州书场");

	set("outdoors", "suzhou");
/*****************************************************
//	
	set("exits", ([
		"south"  : __DIR__"xidajie2",
	]));
	set("objects", ([
		__DIR__"npc/gongzi": 1,
	]));

********************************************/
};


ROOM_END;
