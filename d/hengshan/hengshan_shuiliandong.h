//shuiliandong.h

//Sample for room: 衡山水帘洞
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shuiliandong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山水帘洞");
	
	add_npc("pub_daoke");         ///add by zdn 2001-07-20

	add_door("衡山山路12", "衡山山路12", "衡山水帘洞");

    set("long","水帘洞在紫盖峰下，在吐雾和香炉两峰之间。紫盖峰之水经山涧汇入紫盖仙洞中，深不可测，水满则溢，飞瀑高二十余丈，数叠垂帘，飘泄而下，蔚为壮观。明张居正诗曰:  '误疑瀛海翻琼波，莫拟银河倒碧流，自是湘妃深隐处，水晶帘挂五云头。' 以赞叹这衡山大四绝之一的'水帘洞之奇' 。" );
    

/*****************************************************
        set("exits", ([  
           "westdown"    : __DIR__"shanlu12",
        ]));
********************************************/
};


ROOM_END;
