//shanlu12.h

//Sample for room: 衡山山路12
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路12");
	
	add_npc("pub_daoke");       //add by zdn 2001-07-17


	add_door("衡山山路11", "衡山山路11", "衡山山路12");
	add_door("衡山水帘洞", "衡山水帘洞", "衡山山路12");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。西边上山的路。东边隐隐听到水响。" );
    

/*****************************************************
        set("exits", ([  
           "west"    : __DIR__"shanlu11",
           "eastup"  : __DIR__"shuiliandong",
        ]));
********************************************/
};


ROOM_END;
