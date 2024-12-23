//shulin1.h

//Sample for room: 黄河树林1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河树林1");

	//add npcs into the room
	add_npc("animal_dushe");
	add_npc("pub_zongjinquan");

	add_door("扬州北驿道", "扬州北驿道", "黄河树林1");

	add_door("黄河树林2", "黄河树林2", "黄河树林1");
	add_door("黄河树林3", "黄河树林3", "黄河树林1");

	set("long","树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的啸声使人不觉犹豫了前进的脚步。林中立着一块牌子(paizi)。");
	

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"shulin2",
		"east"  : __DIR__"caodi2",
		"north" : __DIR__"shulin3",
	]));
	set("item_desc", ([
		"paizi" : HIR"\n非黄河帮众者    擅入格杀勿论\n\n"NOR,
	]));
	set("objects", ([
		"/d/shenlong/npc/dushe" : 1,
		"/d/hangzhou/obj/shuzhi" : 1,
	]));
********************************************/
};


CHANGAN_END;
