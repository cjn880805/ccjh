//shanlu15.h

//Sample for room: 终南山山间小径15
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu15);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山间小径15");

	//add npcs into the room 2001-07-10  zdn add
	add_npc("pub_liumang");

	add_door("终南山山间小径14", "终南山山间小径14", "终南山山间小径15");
	add_door("终南山山间小径16", "终南山山间小径16", "终南山山间小径15");

	set("long","这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林苍翠，遍地山花，枝头啼鸟唱和不绝。往西和东南可通往山林深处。" );

/*****************************************************
        set("exits", ([
                "southeast" : __DIR__"shanlu14",
                "west"      : __DIR__"shanlu16",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
