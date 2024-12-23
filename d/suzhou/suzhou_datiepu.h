//datiepu.h

//Sample for room: 打铁铺
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "打铁铺");

	//add npcs into the room
	add_npc("pub_smith");/////////////////////////

	add_door("苏州中", "苏州中", "苏州打铁铺");

 	set("outdoors", "suzhou");
/*****************************************************
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
        set("objects", ([
		"/d/city/npc/smith": 1,
	]));

********************************************/
};


ROOM_END;
