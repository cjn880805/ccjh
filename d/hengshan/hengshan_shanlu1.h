//shanlu1.h

//Sample for room: 衡山山路1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路1");
	
	add_npc("pub_xiaozei");        //add by zdn 2001-07-17


	add_door("衡山正北门", "衡山正北门", "衡山山路1");
	add_door("衡山山路2", "衡山山路2", "衡山山路1");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。" );
    

/*****************************************************
        set("exits", ([  
           "southdown"  : __DIR__"beimen",
           "northwest"  : __DIR__"shanlu2",
        ]));
********************************************/
};


ROOM_END;
