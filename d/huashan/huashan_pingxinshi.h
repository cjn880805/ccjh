//pingxinshi.h

//Sample for room: 华山平心石
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_pingxinshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山平心石");

	add_npc("huashan_cheng_buyou");

	add_door("华山百尺峡", "华山百尺峡", "华山平心石");
	add_door("华山老君沟", "华山老君沟", "华山平心石");

	set("long", "百尺峡尽头，两边岩崖势欲相合，中夹两块巨石，前边一块刻有“惊心石”三字。过此回望，石上刻有“平心石”三字，示人们以险境已经过去，已进入平安之途了。顿时心情至此一舒。");  
    
 
/*****************************************************
        set("exits", ([ 
            "westdown" : __DIR__"baichi",
            "eastup"   : __DIR__"laojun",
        ]));
********************************************/
};


ROOM_END;
