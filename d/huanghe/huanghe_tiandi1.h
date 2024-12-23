//tiandi1.h

//Sample for room: 黄河田地1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河田地1");

	//add npcs into the room
	add_npc("pub_poorman");

	add_door("黄河树林3", "黄河树林3", "黄河田地1");
	add_door("黄河田地2", "黄河田地2", "黄河田地1");
	add_door("黄河田地3", "黄河田地3", "黄河田地1");

	set("long","这里林木渐渐稀疏，不远处有一些村庄，炊烟袅袅升起。村庄周围是一块块的田地，田里有一些正在耕作的农人。");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"shulin3",
		"west"  : __DIR__"tiandi2",
		"east"  : __DIR__"tiandi3",
	]));
	set("objects", ([
		"/d/village/npc/poorman" : 1,
	]));
********************************************/
};


CHANGAN_END;
