//shulin3.h

//Sample for room: 黄河树林3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河树林3");

	//add npcs into the room
//	add_npc("animal_wolf2");/////////////////////////
//	add_npc("animal_maoniu");
	add_npc("pub_leimeng");	

	add_door("黄河树林1", "黄河树林1", "黄河树林3");
	add_door("黄河树林4", "黄河树林4", "黄河树林3");
	add_door("黄河田地1", "黄河田地1", "黄河树林3");

	set("long","树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的啸声使人不觉犹豫了前进的脚步。");
	

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"shulin4",
		"south" : __DIR__"shulin1",
		"north" : __DIR__"tiandi1",
	]));
********************************************/
};


CHANGAN_END;
