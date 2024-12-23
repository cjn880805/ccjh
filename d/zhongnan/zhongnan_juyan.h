//juyan.h

//Sample for room: 终南山老妪岩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_juyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山老妪岩");
	
	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_playboy");
	add_npc("pub_lady3");

	add_door("终南山树林7", "终南山树林7", "终南山老妪岩");
	add_door("终南山山道8", "终南山山道8", "终南山老妪岩");

	set("long","一路过来，山路是越来越险。只见一块大岩石挡在路中，自空凭临，宛似一个老妇弯腰俯视，但形状阴森可怖，令人望而生畏。不少游客在此驻足观看，往南是一片茂密的松林。往北上是一条陡峭的山路。" );

/*****************************************************
        set("exits", ([
                "northup"    : __DIR__"shanlu8",
                "southdown"  : __DIR__"shulin7",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/ji": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
