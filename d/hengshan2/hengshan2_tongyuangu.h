//tongyuangu.h

//Sample for room: 恒山通元谷
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_tongyuangu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山通元谷");
	add_npc("hengshan_dingyueshitai");

	add_door("恒山果老岭", "恒山果老岭", "恒山通元谷");

    set("long","通元谷孤处见性峰下，相传为张果老成仙前修道之所，由于他道号 '通元' ，这里也就成了通元谷。  " );
    

/*****************************************************
        set("exits", ([ 
           "eastup"  : __DIR__"guolaoling",
        ]));
********************************************/
};


ROOM_END;
