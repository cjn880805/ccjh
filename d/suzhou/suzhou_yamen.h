//yamen.h

//Sample for room: 苏州府衙
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_yamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苏州府衙");

	//add npcs into the room
	add_npc("pub_yayi");/////////////////////////

	add_door("苏州中", "苏州中", "苏州府衙");

 	set("outdoors", "suzhou");
/*****************************************************
//	
	set("exits", ([
		"south"  : __DIR__"xidajie1",
	]));
	set("objects", ([
		__DIR__"npc/feng": 1,
		__DIR__"npc/shiye": 1,
		__DIR__"npc/yayi": 4,
	]));

********************************************/
};


ROOM_END;
