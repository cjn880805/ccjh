//shidong1.h

//Sample for room: 侠客岛石洞1
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRXiaKeDao_shidong1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛石洞1");
	
	add_npc("wudang_lisi");        //add by zdn 2001-07-20



	add_door("侠客岛甬道", "侠客岛甬道", "侠客岛石洞1");
	add_door("侠客岛洞门", "侠客岛洞门", "侠客岛石洞1");
	add_door("侠客岛石洞6", "侠客岛石洞6", "侠客岛石洞1");

	

/*****************************************************
        set("exits", ([
               "east" : __DIR__"dongmen",
               "north" : __DIR__"yongdao2",
               "south" : __DIR__"shidong6",
        ]));
        
********************************************/
};


ROOM_END;
