//shanlu3.h

//Sample for room: 衡山山路3
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路3");
	
	add_npc("pub_caishiren");              //add by zdn 2001-07-17

	add_door("衡山赤帝峰", "衡山赤帝峰", "衡山山路3");
	add_door("衡山山路4", "衡山山路4", "衡山山路3");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。" );
    

/*****************************************************
        set("exits", ([  
           "southup"    : __DIR__"chidifeng",
           "northwest"  : __DIR__"shanlu4",
        ]));
********************************************/
};


ROOM_END;
