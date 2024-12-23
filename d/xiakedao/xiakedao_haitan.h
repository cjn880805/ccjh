//haitan.h

//Sample for room: 侠客岛海滩
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_haitan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛海滩");
	
	add_npc("pub_yufu");        //add by zdn 2001-07-20


	add_door("佛山南门", "佛山南门", "侠客岛海滩");
	add_door("侠客岛山门", "侠客岛山门", "侠客岛海滩");

    

/*****************************************************
    set("item_desc", ([
        "boat" : "这是侠客岛对外联系的大船。岛上的客人或弟子只要\n"
                  "上船(enter)就可以回中原。\n",
    ]));
    set("exits",([
        "south" :__DIR__"lin1",
    ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp