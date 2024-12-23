//shanlu10.h

//Sample for room: 衡山山路10
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山路10");
	
	add_npc("pub_jianke");           //add by zdn 2001-07-17


	add_door("衡山方广寺", "衡山方广寺", "衡山山路10");
	add_door("衡山天柱峰", "衡山天柱峰", "衡山山路10");

    set("long","你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕，不觉心胸大快。山路向西通向方广寺。东面是天柱峰。" );
    

/*****************************************************
        set("exits", ([  
           "eastup"    : __DIR__"tianzhu",
           "westdown"  : __DIR__"fangguangsi",
        ]));
********************************************/
};


ROOM_END;
