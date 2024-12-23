//shanlu16.h

//Sample for room: 终南山山间小径16
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu16);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山间小径16");

	//add npcs into the room   2001-07-10 zdn add
	add_npc("animal_snake");

	add_door("终南山山间小径15", "终南山山间小径15", "终南山山间小径16");
	add_door("终南山小河边", "终南山小河边", "终南山山间小径16");

	set("long","这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林苍翠，遍地山花，枝头啼鸟唱和不绝。往南可看到一条小河。往东可通往山林深处。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "east"  : __DIR__"shanlu15",
                "south" : __DIR__"xiaohebian",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
