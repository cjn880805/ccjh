//shanjiao.h

//Sample for room: 终南山脚
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanjiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山脚");

	//add npcs into the room
	add_npc("pub_youke");/////////////////////////
	add_npc("pub_xiangke");

				

	add_door("终南山山路1", "终南山山路1", "终南山脚");
	add_door("终南山道路13", "终南山道路13", "终南山脚");


/*****************************************************
        set("exits", ([
//                "northup" : __DIR__"shijie1",
                "north"    : "/d/gumu/shanlu13",
                "westdown" : __DIR__"shanlu4",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
