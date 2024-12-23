//puguangsi.h

//Sample for room: 终南山普光寺
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_puguangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山普光寺");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_playboy");
	add_npc("pub_liumang");

	add_door("终南山道路13", "终南山道路13", "终南山普光寺");

	set("long","这是一个位於终南山下的小寺庙，庙门横额写着 ‘普光寺’ 三个大字。由於此庙是上终南山的必经之路，大多数的游客都会在此落脚休息，也因此此处香火也颇为鼎盛。庙前的几株松树下，立着一块石碑(shibei)，几乎快被周围的长草给遮掩了。往西走是一条小路." );

/*****************************************************
        set("exits", ([
                "west" : __DIR__"shanlu13",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
