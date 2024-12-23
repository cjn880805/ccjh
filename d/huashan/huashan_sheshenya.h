//sheshenya.h

//Sample for room: 华山舍身崖
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_sheshenya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山舍身崖");

	//add npcs into the room
	add_npc("pub3_gongpingziw");
	add_npc("huashan_mei");

	add_door("华山苍龙岭", "华山苍龙岭", "华山舍身崖");

	set("long", "这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小心，一失足掉下去，只怕连骨头都找不到。边上有个小山洞(dong)。");  
    
 
/*****************************************************
        set("exits", ([  
            "eastdown" : __DIR__"canglong",
            "west"     : "/d/xiaoyao/pubu",
        ]));
        set("item_desc", ([
            "dong" : "紧靠飞崖下石壁的小洞，黑呼呼的不知有多深。\n",
        ]));
        set("objects",([
                __DIR__"npc/referee" : 1,
        ]));
********************************************/
};


ROOM_END;
