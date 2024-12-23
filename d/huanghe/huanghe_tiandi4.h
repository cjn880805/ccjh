//tiandi4.h

//Sample for room: 黄河田地4
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河田地4");

	//add npcs into the room
	add_npc("animal_dog");
	add_item("daotian");

	add_door("黄河田地3","黄河田地3", "黄河田地4");
	add_door("黄河岸边1","黄河岸边1", "黄河田地4");

	set("long","这里是一大片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围是一块块的田地，田里有一些正在耕作的农人。村里不时传出一声声的犬吠。");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"tiandi3",
		"north"     : __DIR__"huanghe1",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
********************************************/
};


CHANGAN_END;
