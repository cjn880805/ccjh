//bingying.h

//Sample for room: 兵营
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_bingying);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵营");

	//add npcs into the room
	add_npc("pub_wujiang");/////////////////////////
	add_npc("pub_bing");
				

	add_door("苏州中", "苏州中", "苏州兵营");

 	set("outdoors", "suzhou");
/*****************************************************
//	
	set("exits", ([
		"north"  : __DIR__"xidajie1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang": 1,
		"/d/city/npc/bing": 4,
	]));

********************************************/
};


ROOM_END;
