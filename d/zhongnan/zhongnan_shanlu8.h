//shanlu8.h

//Sample for room: 终南山山道8
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山道8");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_liumangtou");
	add_npc("pub_liumang");
	add_npc("pub_liumang");

	add_door("终南山老妪岩", "终南山老妪岩", "终南山山道8");
	add_door("终南山大校场", "终南山大校场", "终南山山道8");

	set("long","此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边必须面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然一失足，就要掉进万丈深渊了。往北是一块广大的空地。往南下是一块巨岩。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
