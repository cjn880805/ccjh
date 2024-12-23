//shanlu5.h

//Sample for room: 衡山山路5
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路5");


	add_door("衡山山路6", "衡山山路6", "衡山山路5");
	add_door("衡山半山亭", "衡山半山亭", "衡山山路5");
	add_door("衡山山路13", "衡山山路13", "衡山山路5");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。西边有岔路通往磨镜台和天柱峰。西北方就是芙蓉峰了，祝融峰也是往这个方向。" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"banshan",
           "west"       : __DIR__"shanlu6",
           "northwest"  : __DIR__"shanlu13",
        ]));
********************************************/
};


ROOM_END;
