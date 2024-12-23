//chidifeng.h

//Sample for room: 衡山赤帝峰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_chidifeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山赤帝峰");


	add_door("衡山山路3", "衡山山路3", "衡山赤帝峰");
	add_door("衡山山路2", "衡山山路2", "衡山赤帝峰");
	add_door("衡山山路11", "衡山山路11", "衡山赤帝峰");

    set("long","相传祝融能 '以火施化' ，是黄帝的 '火正官' ，并主管南方的事务，死后葬于此，故名赤帝峰。" );
    

/*****************************************************
        set("exits", ([  
           "southdown"  : __DIR__"shanlu2",
           "eastdown"   : __DIR__"shanlu11",
           "northdown"  : __DIR__"shanlu3",
        ]));
********************************************/
};


ROOM_END;
