//daxiaochang.h

//Sample for room: 终南山大校场
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_daxiaochang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山大校场");

	add_npc("quanzhen_pi");

	add_door("终南山山道8", "终南山山道8", "终南山大校场");
	add_door("终南山石阶1", "终南山石阶1", "终南山大校场");
	add_door("终南山山路7", "终南山山路7", "终南山大校场");

    

/*****************************************************
        set("exits", ([
                "northup"     : "/d/quanzhen/shijie1",
                "westup"      : __DIR__"shanlu7",
                "southdown"   : __DIR__"shanlu8",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/pi": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
