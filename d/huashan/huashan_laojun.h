//laojun.h

//Sample for room: 华山老君沟
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_laojun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山老君沟");
	add_npc("pub_murenjin");

	add_door("华山平心石", "华山平心石", "华山老君沟");
	add_door("华山猢狲愁", "华山猢狲愁", "华山老君沟");

	set("long", "爬过两个要命的悬崖，可在这里稍作歇息。老君沟是一条半里多长的山沟，相传为太上老君到此，见无路可通，因而套上大青牛用铁犁犁出了这条沟作为登山通道。");  
    
 
/*****************************************************
        set("exits", ([  
            "westdown" : __DIR__"pingxinshi",
            "southup"  : __DIR__"husun",
        ]));
        set("objects", ([
             __DIR__"npc/lao-denuo": 1,
        ]));
********************************************/
};


ROOM_END;
