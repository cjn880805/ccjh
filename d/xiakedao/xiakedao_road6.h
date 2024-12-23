//road6.h

//Sample for room: 侠客岛山路6
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛山路6");
	
	add_npc("pub_shizhe1");        //add by zdn 2001-07-16

	add_door("侠客岛石洞8", "侠客岛石洞8", "侠客岛山路6");
	add_door("侠客岛夹鳖石", "侠客岛夹鳖石", "侠客岛山路6");
	add_door("侠客岛树林", "侠客岛树林", "侠客岛山路6");

    

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"road7",
                "northdown" : __DIR__"road5",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp