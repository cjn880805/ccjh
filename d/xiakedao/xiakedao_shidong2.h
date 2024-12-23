//shidong2.h

//Sample for room: 侠客岛石洞2
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛石洞2");

	add_npc("xiake_long");
	add_npc("xiake_mu");

	add_door("侠客岛迎宾馆", "侠客岛迎宾馆", "侠客岛石洞2");
	add_door("侠客岛大厅", "侠客岛大厅", "侠客岛石洞2");

    

/*****************************************************
        set("exits", ([
                "east" : __DIR__"shidong3",
                "west" : __FILE__,
                "south" : __FILE__,
                "north" : __DIR__"yingbin",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp