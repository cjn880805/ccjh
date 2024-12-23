//shudian.h

//Sample for room: 书店
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_shudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书店");

	//add npcs into the room
	add_npc("pub_shudianboss");
				

	add_door("襄阳西北", "襄阳西北", "襄阳书店");
/*****************************************************
	set("exits", ([
		"east" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/shudianboss" : 1,
	]));
********************************************/
};


ROOM_END;
