//road1.h

//Sample for room: 侠客岛山路1
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛山路1");
	
	add_npc("pub_daoke");         //add by zdn 2001-07-16

	add_door("侠客岛山门", "侠客岛山门", "侠客岛山路1");
	add_door("侠客岛瀑布", "侠客岛瀑布", "侠客岛山路1");

    

/*****************************************************
        set("exits", ([
                "southup" : __DIR__"road2",
                "northdown" :__DIR__"shanmen",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp