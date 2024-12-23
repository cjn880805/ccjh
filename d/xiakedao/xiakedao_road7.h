//road7.h

//Sample for room: 侠客岛夹鳖石
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛夹鳖石");
	
	add_npc("gaibang_shitianjing");        //add by zdn 2001-07-20


	add_door("侠客岛山路6", "侠客岛山路6", "侠客岛夹鳖石");
	add_door("侠客岛一线天", "侠客岛一线天", "侠客岛夹鳖石");

    

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup"   : __DIR__"road8",
                "northdown" : __DIR__"road6",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp