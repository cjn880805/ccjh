//shanlu13.h

//Sample for room: 衡山山路13
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu13);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路13");
	
	add_npc("pub_youke");         //add by zdn 2001-07-17

	add_door("衡山山路5", "衡山山路5", "衡山山路13");
	add_door("衡山南天门", "衡山南天门", "衡山山路13");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。东北方就是南天门了，高高矗立在西北方的就是衡山五峰之一的芙蓉峰。" );
    

/*****************************************************
        set("exits", ([ 
           "northeast"  : __DIR__"nantian",
           "southeast"  : __DIR__"shanlu5",
        ]));
********************************************/
};


ROOM_END;
