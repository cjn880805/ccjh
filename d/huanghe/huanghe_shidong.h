//shidong.h

//Sample for room: 黄河石洞
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shidong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河石洞");

	//add npcs into the room
	add_npc("honghua_chenjuyang");

	add_door("黄河沙漠2", "黄河沙漠2", "黄河石洞");

	set("long","这是沙漠中天然形成的一个石洞，洞中光线昏暗，但却十分干燥，地下铺者几堆稻草，似乎是供人睡卧之用，静心凝听，洞中仿佛有阵阵水声。洞的一角放着数堆人头骨(skulls)。");

/*****************************************************
	set("exits", ([
		"out" : __DIR__"shamo1",
	]));
	set("item_desc", ([
		"skulls" : "一堆整整齐齐的骷髅头，上一中三下五，不多不少，恰是
九颗白骨骷髅头。\n",
	]));
	set("objects", ([
		__DIR__"npc/mei" :1,
		__DIR__"npc/chen" :1,
	]));
********************************************/
};


CHANGAN_END;
