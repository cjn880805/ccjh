//zhenyue.h

//Sample for room: 镇岳宫
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_zhenyue);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "镇岳宫");

	add_npc("huashan_feng_buping");

	add_door("华山金锁关", "华山金锁关", "华山镇岳宫");
	add_door("华山玉女峰", "华山玉女峰", "华山镇岳宫");
	add_door("华山莲花峰小路", "华山莲花峰小路", "华山镇岳宫");

	set("long", "镇岳宫倚壁而构，四边松林蔽日，景色幽美。宫前有玉井(jing)，相传井中曾生千叶白莲。这里地势略为平坦，上、下山的游客多在此稍作休息再继续前行。附近有几间简陋的旅社，欲登东峰观日出者，大都于头晚歇息于此。");  
    set("resource/water", 1);

/*****************************************************
        set("exits", ([ 
            "northdown"  : __DIR__"jinsuo",
            "eastup"     : __DIR__"yunu",
            "southwest"  : __DIR__"lianpath1",
        ]));
        set("objects", ([
            __DIR__"npc/gao-genming" : 1,
        ]));
        set("item_desc", ([
            "jing" : "井中水色碧透，掬手可饮。\n",
        ]));

//        
        set("outdoors", "huashan" );
********************************************/
};


ROOM_END;
