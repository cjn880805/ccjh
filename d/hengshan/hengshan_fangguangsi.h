//fangguangsi.h

//Sample for room: 方广寺
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_fangguangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "方广寺");


	add_door("衡山山路10", "衡山山路10", "衡山方广寺");
	add_door("衡山山涧", "衡山山涧", "衡山方广寺");

    set("long","方广寺在莲花峰下。莲花峰有八个山头，犹如金莲瓣瓣，方广寺就建在这莲花中心的一片平地上。深邃幽雅，有 '不游方广寺，不知南岳之深' 之说，故 '方广寺之深' 为衡山大四绝之一。" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shanjian",
           "eastup"     : __DIR__"shanlu10",
        ]));
        set("outdoors", "henshan");
********************************************/
};


ROOM_END;
