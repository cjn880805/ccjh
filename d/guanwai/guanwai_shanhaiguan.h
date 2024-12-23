//shanhaiguan.h

//Sample for room: 山海关
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_shanhaiguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山海关");

	set("resident", "山海关");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_ouyangbu");
	add_npc("pub_ouyangzhan");
	
	add_door("关外老龙头", "关外老龙头", "关外山海关");
	add_door("关外官道", "关外官道", "关外山海关");

    set("long","这里就是万里长城最东面的重要关口--山海关。这里地势险要，自古就是关外通往中原的必经之地。站在关楼上北望，角山，古堡，烽火台历历在目，南沿长城远眺，直深入海的老龙头依稀可见。城楼二楼上悬挂着一块巨幅横匾(bian)。" );
	

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"road1",
		"southeast" : __DIR__"laolongtou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("item_desc",([
		"bian" : 
"
    ※※※※※※※※※※※※※※※※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※　天  下  第  一  关  ※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※※※※※※※※※※※※※※※※\n",
	]));
********************************************/
};


RESIDENT_END;
