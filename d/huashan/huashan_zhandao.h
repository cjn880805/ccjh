//zhandao.h

//Sample for room: 华山长空栈道
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_zhandao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山长空栈道");


	add_door("华山山洞", "华山山洞", "华山长空栈道");
	add_door("华山落雁峰", "华山落雁峰", "华山长空栈道");

	set("long", "栈道以铁斜插，上覆青石板，宽不足八寸。上乃绝壁，下亦绝壁。挽索登其上，只听山风呼啸，林涛怒吼。远处偶传一两声禽鸣兽嘶，更使人毛骨悚然。踏上悬空的栈道，紧攀铁索，屏息静气，缓步挪动，才能过去。");  
    

/*****************************************************
        set("exits", ([  
           "southup"   : __DIR__"luoyan",
           "northdown" : __DIR__"sgyhole",
        ]));
********************************************/
};


ROOM_END;
