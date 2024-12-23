//sgyhole.h

//Sample for room: 华山山洞
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_sgyhole);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山山洞");

	add_npc("huashan_linghu");	

	add_door("华山思过崖", "华山思过崖", "华山山洞");
	add_door("华山长空栈道", "华山长空栈道", "华山山洞");

	set("long", "山洞内有块光溜溜的大石，不知道曾有多少华山派的前辈在此思过面壁，以致这块大石竟被坐得滑溜。石壁(wall)左侧刻着「风清扬」三个大字，是以利器所刻，笔划苍劲，深有半寸。这三字刻得劲力非凡，想必其人武功一定十分了得。");  

/*****************************************************
        set("objects", ([
//         CLASS_D("huashan")+"/linghu" : 1,
            "/d/heimuya/npc/linghu" : 1,
//         __DIR__"npc/ling-huchong.c" : 1,
        ]));
        set("exits", ([  
            "out" : __DIR__"siguoya",
        ]));
        set("item_desc", ([
            "wall" : "一面很厚的石壁。\n"
        ]) );
********************************************/
};


ROOM_END;
