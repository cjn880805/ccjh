//dongmen.h

//Sample for room: 侠客岛洞门
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_dongmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛洞门");

	add_door("侠客岛石洞1", "侠客岛石洞1", "侠客岛洞门");
	add_door("侠客岛迎宾馆", "侠客岛迎宾馆", "侠客岛洞门");

    

/*****************************************************
        set("exits", ([
                "enter" : __DIR__"yingbin",
                "west" : __DIR__"shidong1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi1" : 1]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp