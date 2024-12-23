//tiandi3.h

//Sample for room: 黄河田地3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河田地3");
	
	add_npc("pub_nongfu2");     //add by zdn 2001-07-14
	add_item("daotian");


	add_door("黄河田地1", "黄河田地1", "黄河田地3");
	add_door("黄河田地4", "黄河田地4", "黄河田地3");

	set("long","这里是一大片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围是一块块的田地，田里有一些正在耕作的农人。");
	

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"tiandi1",
		"northeast" : __DIR__"tiandi4",
	]));
********************************************/
};


CHANGAN_END;
