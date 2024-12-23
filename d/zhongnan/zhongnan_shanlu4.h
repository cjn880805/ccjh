//shanlu4.h

//Sample for room: 终南山山路4
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路4");

	//add npcs into the room   2001-07-10  zdn add
	add_npc("pub_seller");

	add_door("终南山山路5", "终南山山路5", "终南山山路4");
	add_door("古墓终南山主峰", "古墓终南山主峰", "终南山山路4");

	set("long","这里是山路的尽头，南面好象有一片小树林，折而向东，就是终南山的山脚了。" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"shanlu2",
                "eastup" : __DIR__"shanjiao",
//                "southwest" : "/d/gumu/shulin1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
