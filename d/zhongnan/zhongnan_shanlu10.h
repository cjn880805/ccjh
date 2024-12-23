//shanlu10.h

//Sample for room: 终南山山路10
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路10");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_liumangtou");
	add_npc("pub_liumang");
	add_npc("pub_liumang");

	add_door("终南山金莲阁", "终南山金莲阁", "终南山山路10");
	add_door("终南山日月岩", "终南山日月岩", "终南山山路10");

	set("long","此处位於终南山山脚。巍峨的终南山，自古以来就是历代名人游览的圣地。它西起甘肃的岐山，东至陕西的潼关，其间跨越十馀县，连绵八百馀里。素有万里终南山之称。往东可看见一座寺庙。往西是一条通往密林的幽静小路。往北可上终南山." );

/*****************************************************

*****************************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
