//nantian.h

//Sample for room: 衡山南天门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_nantian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山南天门");


	add_door("衡山山路13", "衡山山路13", "衡山南天门");
	add_door("衡山流云坪", "衡山流云坪", "衡山南天门");
	add_door("衡山登高台", "衡山登高台", "衡山南天门");
	add_door("衡山山路14", "衡山山路14", "衡山南天门");
	add_door("衡山狮子岩", "衡山狮子岩", "衡山南天门");

    set("long","  到了南天门，才能望到衡山第一的祝融峰。南天门是花岗岩的石碑坊，中门镌有 '南天门' 三字横额，左右二门的门楣上，分别刻有 '行云' ， '施雨' 。楹联(lian)破陋，显见岁月已久。" );
    

/*****************************************************
        set("exits", ([
            "northeast" : __DIR__"shiziyan",
            "southup"   : __DIR__"denggaotai",
            "eastup"    : __DIR__"liuyunping",
            "southwest" : __DIR__"shanlu13",
            "northwest" : __DIR__"shanlu14",
        ]));
        set("item_desc", ([
            "lian" :
"\n
        门              路
        可              承
        通              绝
        天              顶

        仰              俯
        观              瞰
        碧              翠
        落              微
        星              峦
        辰              屿
        近              低\n\n",
        ]));
********************************************/
};


ROOM_END;
