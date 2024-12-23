//shanlu11.h

//Sample for room: 终南山道路11
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山道路11");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_liumang");
	add_npc("pub_liumang");


	add_door("终南山山路12", "终南山山路12", "终南山道路11");
	add_door("终南山金莲阁", "终南山金莲阁", "终南山道路11");

	set("long","此处位於终南山山脚。巍峨的终南山，自古以来就是历代名人游览的圣地。它西起甘肃的岐山，东至陕西的潼关，其间跨越十馀县，连绵八百馀里。素有万里终南山之称。往东可看见一座寺庙。往西是一条通往密林的幽静小路。往北可上终南山." );

/*****************************************************
        set("exits", ([
                "northup"   : __DIR__"shanlu12",
                "east"      : __DIR__"puguangsi",
                "west"      : __DIR__"shanlu14",
                "south"     : "/d/quanzhen/shanjiao",
        ]));
*****************************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
