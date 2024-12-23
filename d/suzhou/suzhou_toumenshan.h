//toumenshan.h

//Sample for room: 头门山
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_toumenshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "头门山");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("苏州虎丘山", "苏州虎丘山", "苏州头门山");
	add_door("苏州万景山庄", "苏州万景山庄", "苏州头门山");


/*****************************************************
	set("exits", ([
		"north" : __DIR__"huqiu",
		"west"  : __DIR__"wanjing",
	]));
        set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
********************************************/
};


ROOM_END;
