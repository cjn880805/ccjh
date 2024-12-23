//jinsuo.h

//Sample for room: 华山金锁关
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_jinsuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山金锁关");
	
	add_npc("huashan_ludayou");        //add by zdn 2001-07-20


	add_door("华山上天梯", "华山上天梯", "华山金锁关");
	add_door("华山镇岳宫", "华山镇岳宫", "华山金锁关");

	set("long", "金锁关山势形如一把锁，下面是一片开阔地，两旁是高耸入云的峭壁，中间一条羊肠小道。真是一夫当关，万夫莫开。");  
    
 
/*****************************************************
        set("exits", ([  
           "southup"   : __DIR__"zhenyue",
           "northdown" : __DIR__"shangtianti",
        ]));
********************************************/
};


ROOM_END;
