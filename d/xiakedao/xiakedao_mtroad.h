//mtroad.h

//Sample for room: 侠客岛山路
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtroad);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛山路");
	
	add_npc("pub_dizi3");       //add by zdn 2001-07-16

	add_door("侠客岛树林", "侠客岛树林", "侠客岛山路");
	add_door("侠客岛崖底", "侠客岛崖底", "侠客岛山路");

    

/*****************************************************
        set("exits", ([
            "south" : __DIR__"mtyadi",
            "east"  : __DIR__"mtroad1",
        ]));
        set("objects",([
            __DIR__"npc/dingdang" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp