//tianzhu.h

//Sample for room: 衡山天柱峰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_tianzhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山天柱峰");


	add_door("衡山山路7", "衡山山路7", "衡山天柱峰");
	add_door("衡山山路10", "衡山山路10", "衡山天柱峰");

    set("long","你爬上衡山五峰之一的天柱峰，四望群山缥缈云雾中，每每天阴地湿时候，这里就是天柱云气的所在了。" );
    

/*****************************************************
        set("exits", ([
           "westdown"   : __DIR__"shanlu10",
           "eastdown"   : __DIR__"shanlu7",
        ]));
********************************************/
};


ROOM_END;
