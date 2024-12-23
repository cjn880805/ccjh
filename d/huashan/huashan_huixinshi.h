//huixinshi.h

//Sample for room: 华山回心石
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_huixinshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山回心石");
	
	add_npc("huashan_teller");        //add by zdn 2001-07-20


	add_door("华山青柯坪", "华山青柯坪", "华山回心石");
	add_door("华山千尺幢", "华山千尺幢", "华山回心石");

	set("long", "从青柯坪沿石阶上山，山路到此而尽，前面山势险恶，石崖间仅有窄窄的石阶犹如天梯耸立，两边铁链斜悬，令人不寒而栗，不敢前行。北壁下大石当路，此石因此叫做回心石，再上去山道奇险，游客至此，就该回头了。");  
    
 
/*****************************************************
        set("exits", ([  
            "westdown" : __DIR__"qingke",
            "eastup"   : __DIR__"qianchi",
        ]));
********************************************/
};


ROOM_END;
