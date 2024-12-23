//shanlu11.h

//Sample for room: 衡山山路11
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路11");


	add_door("衡山赤帝峰", "衡山赤帝峰", "衡山山路11");
	add_door("衡山山路12", "衡山山路12", "衡山山路11");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。西边上山是赤帝峰。东边远远可以看到衡山五峰之一的紫盖峰了" );
    

/*****************************************************
        set("exits", ([  
           "westup"  : __DIR__"chidifeng",
           "east"    : __DIR__"shanlu12",
        ]));
********************************************/
};


ROOM_END;
