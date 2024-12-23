//cangjingdian.h

//Sample for room: 藏经殿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_cangjingdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "藏经殿");


	add_door("衡山山路14", "衡山山路14", "衡山藏经殿");
	add_door("衡山梳妆台", "衡山梳妆台", "衡山藏经殿");

    set("long"," 藏经殿深掩祥光峰下，因藏明太祖所赠 '大藏经' 故名。这里古木参天，殿宇飘翼，奇花异草，林壑幽深，景色秀丽， '藏经殿之秀' 是衡山大四绝之一。" );
    

/*****************************************************
        set("exits", ([ 
           "east"   : __DIR__"shanlu14",
           "south"  : __DIR__"shuzhuangtai",
        ]));
********************************************/
};


ROOM_END;
