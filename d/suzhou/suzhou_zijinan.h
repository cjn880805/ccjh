//zijinan.h

//Sample for room: 紫金庵
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_zijinan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "紫金庵");

	//add npcs into the room
	add_npc("pub_nigu1");/////////////////////////
	add_npc("pub_nigu2");


	add_door("苏州北", "苏州北", "苏州紫金庵");

	set("outdoors", "suzhou");
	
	set("no_fight", "1");
/*****************************************************
 	set("objects", ([
		__DIR__"obj/box" : 1,
		__DIR__"npc/nigu1" : 1,
		__DIR__"npc/nigu2" : 1,
	]));
	set("exits", ([
		"east"      : __DIR__"beidajie2",
	]));

********************************************/
};


ROOM_END;
