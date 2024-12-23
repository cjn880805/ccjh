//xkroad3.h

//Sample for room: 平原小路
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRXiaKeDao_xkroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛平原小路");
	
	add_npc("pub_bing");    //add by zdn 2001-07-16


	add_door("佛山南门", "佛山南门", "侠客岛平原小路");
	add_door("侠客岛海滩", "侠客岛海滩", "侠客岛平原小路");

	

/*****************************************************
    set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : "/d/foshan/southgate",
		"south"   : __DIR__"xkroad4",
	]));
********************************************/
};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp