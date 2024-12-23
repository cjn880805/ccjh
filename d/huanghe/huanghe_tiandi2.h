//tiandi2.h

//Sample for room: 黄河田地2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河田地2");

	//add npcs into the room
//	add_npc("animal_cow");
        add_npc("pub_cunfu");        // add by zdn 2001-07-14

	add_door("黄河田地1", "黄河田地1", "黄河田地2");
	add_door("黄河树林5", "黄河树林5", "黄河田地2");

	set("long","这里是一大片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围是一块块的田地，田里有一些正在耕作的农人。");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"shulin5",
		"east"      : __DIR__"tiandi1",
	]));
	set("objects", ([
		"/d/wudang/npc/cow" : 1,
	]));
********************************************/
};


CHANGAN_END;
