//shanlu4.h

//Sample for room: 衡山山路4
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路4");
	
	add_npc("pub_flowerg");        //add by zdn 2001-07-17


	add_door("衡山山路3", "衡山山路3", "衡山山路4");
	add_door("衡山半山亭", "衡山半山亭", "衡山山路4");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。" );
    

/*****************************************************
        set("exits", ([ 
           "southeast" : __DIR__"shanlu3",
           "northup"   : __DIR__"banshan",
        ]));
********************************************/
};


ROOM_END;
