//road8.h

//Sample for room: 侠客岛一线天
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛一线天");
	
	add_npc("pub_dizi3");       //add by zdn 2001-07-16

	add_door("侠客岛夹鳖石", "侠客岛夹鳖石", "侠客岛一线天");
	add_door("侠客岛望云台", "侠客岛望云台", "侠客岛一线天");

    

/*****************************************************
        set("exits", ([
                "southup"   : __DIR__"wangyun",
                "northdown" : __DIR__"road7",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp