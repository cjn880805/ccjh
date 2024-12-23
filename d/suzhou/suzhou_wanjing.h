//wanjing.h

//Sample for room: 万景山庄
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_wanjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "万景山庄");

	//add npcs into the room
	add_npc("pub_daoke");
	add_npc("pub_lundarong");

	add_door("苏州试剑石", "苏州试剑石", "苏州万景山庄");
	add_door("苏州憨憨泉", "苏州憨憨泉", "苏州万景山庄");
	add_door("苏州头门山", "苏州头门山", "苏州万景山庄");

	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"shijianshi",
		"east"   : __DIR__"toumenshan",
		"westup" : __DIR__"hanhanquan",
	]));
        set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));

********************************************/
};


ROOM_END;
