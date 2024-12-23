//yunmen.h

//Sample for room: 华山云门
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山云门");

	add_npc("zm_huashan");

	add_door("华山莎萝坪", "华山莎萝坪", "华山云门");
	add_door("华山青柯坪", "华山青柯坪", "华山云门");

	set("long", "过莎萝坪，是华山十八盘。十八盘的尽处就是“云门”了。这里刻着“仙境”、“天下第一名山”等石刻。云门之内的小盆地就是青柯坪。");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"shaluo",
            "southup" : __DIR__"qingke",
        ]));
********************************************/
};


ROOM_END;
