//yaopu.h

//Sample for room: 立春堂
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "立春堂");

	//add npcs into the room
	add_npc("pub_huoji");/////////////////////////

	add_door("苏州中", "苏州中", "苏州立春堂");

	set("outdoors", "suzhou");
/*****************************************************
//	
	set("exits", ([
		"south"  : __DIR__"dongdajie2",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));

********************************************/
};


ROOM_END;
