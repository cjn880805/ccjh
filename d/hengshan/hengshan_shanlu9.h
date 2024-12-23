//shanlu9.h

//Sample for room: 衡山山路9
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路9");


	add_door("衡山福严寺", "衡山福严寺", "衡山山路9");
	add_door("衡山南台寺", "衡山南台寺", "衡山山路9");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。南边是南台寺，北边通往福严寺。" );
    

/*****************************************************
        set("exits", ([  
           "southup"  : __DIR__"nantaisi",
           "northup"  : __DIR__"fuyansi",
        ]));
********************************************/
};


ROOM_END;
