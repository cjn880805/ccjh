//shanlu7.h

//Sample for room: 衡山山路7
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路7");
	
	add_npc("pub_shennongdizi");          //add by zdn 2001-07-17


	add_door("衡山磨镜台", "衡山磨镜台", "衡山山路7");
	add_door("衡山天柱峰", "衡山天柱峰", "衡山山路7");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。山路东西通向磨镜台和天柱峰。" );
    

/*****************************************************
        set("exits", ([
           "westup"    : __DIR__"tianzhu",
           "eastdown"  : __DIR__"mojingtai",
        ]));
********************************************/
};


ROOM_END;
