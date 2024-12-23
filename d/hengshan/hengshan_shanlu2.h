//shanlu2.h

//Sample for room: 衡山山路2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路2");
	
	add_npc("animal_dushe");             //add by zdn 2001-07-17

	add_door("衡山山路1", "衡山山路1", "衡山山路2");
	add_door("衡山赤帝峰", "衡山赤帝峰", "衡山山路2");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。" );
    

/*****************************************************
        set("exits", ([  
           "southeast"  : __DIR__"shanlu1",
           "northup"    : __DIR__"chidifeng",
        ]));
********************************************/
};


ROOM_END;
