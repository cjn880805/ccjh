//pubu.h

//Sample for room: 侠客岛瀑布
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_pubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛瀑布");
	
	add_npc("pub_jianke");        //add by zdn 2001-07-16

	add_door("侠客岛山路1", "侠客岛山路1", "侠客岛瀑布");
	add_door("侠客岛甬道", "侠客岛甬道", "侠客岛瀑布");

     

/*****************************************************
        set("exits", ([ 
                "northdown" : __DIR__"road4",
        ]));
        set("outdoors", "xiakedao");
        set("item_desc",([
            "pubu"   : "你仔细一看，瀑布里面好象有出口，你似乎可以跳(jump)进去。\n",
            "xuanya" : "下面弥漫着烟雾，什么也看不见，你可不要跳(plump)下去呀！\n",
        ]) );
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp