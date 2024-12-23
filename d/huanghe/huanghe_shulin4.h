//shulin4.h

//Sample for room: 黄河树林4
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河树林4");

	//add npcs into the room
//	add_npc("animal_fox");

	add_door("黄河树林2", "黄河树林2", "黄河树林4");
	add_door("黄河树林3", "黄河树林3", "黄河树林4");
	add_door("黄河树林5", "黄河树林5", "黄河树林4");

	set("long","树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的啸声使人不觉犹豫了前进的脚步。");
	

/*****************************************************
	set("exits", ([
		"northwest"  : __DIR__"shulin5",
		"east"       : __DIR__"shulin3",
		"south"      : __DIR__"shulin2",
	]));
	set("objects", ([
		"/d/baituo/npc/fox" : 1,
	]));
********************************************/
};


CHANGAN_END;
