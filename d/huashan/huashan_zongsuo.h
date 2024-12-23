//zongsuo.h

//Sample for room: 华山总所
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_zongsuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山总所");

	//add npcs into the room
	add_npc("pub_xiaoer2");

    add_door("华山", "华山", "华山总所");
	add_door("群仙观", "华山群仙观", "华山总所");

/*****************************************************
	set("exits", ([
		"east" : __DIR__"square",
	]));
//	
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
********************************************/
};


ROOM_END;
