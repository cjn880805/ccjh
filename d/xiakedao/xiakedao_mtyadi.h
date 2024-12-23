//mtyadi.h

//Sample for room: 侠客岛崖底
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtyadi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛崖底");

	add_door("侠客岛山路", "侠客岛山路", "侠客岛崖底");
	add_door("侠客岛摩天崖", "侠客岛摩天崖", "侠客岛崖底");

    

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits", ([
            "north" : __DIR__"mtroad",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp