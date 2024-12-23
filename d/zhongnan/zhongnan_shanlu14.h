//shanlu14.h

//Sample for room: 终南山山间小径14
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山间小径14");
	
	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_playboy");

	add_door("终南山道路13", "终南山道路13", "终南山山间小径14");
	add_door("终南山山间小径15", "终南山山间小径15", "终南山山间小径14");

	set("long","这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林苍翠，遍地山花，枝头啼鸟唱和不绝。往西和东南可通往山林深处。" );

/*****************************************************
        set("exits", ([
                "east"      : __DIR__"shanlu13",
                "northwest" : __DIR__"shanlu15",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
