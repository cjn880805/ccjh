//mtroad1.h

//Sample for room: 侠客岛树林
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛树林");
	
	add_npc("wudang_dingdang");        //add by zdn 201-07-20

	add_door("侠客岛山路6", "侠客岛山路6", "侠客岛树林");
	add_door("侠客岛山路", "侠客岛山路", "侠客岛树林");

    

/*****************************************************
        set("exits", ([
            "east"  : "/d/henshan/hsroad5",
            "west"  : __DIR__"mtroad",
            "north" : __FILE__,
            "south" : __DIR__"mtroad2",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp