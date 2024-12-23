//shatulu.h



//Sample for room: 黄河沙土路

//coded by zouwenbin

//data: 2000-11-27



CHANGAN_BEGIN(CRHuangHe_shatulu);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "黄河沙土路");
	
	add_npc("monster_28k");      // add by zdn 2001-07-14


	add_door("黄河永登", "黄河永登", "黄河沙土路");

	add_door("黄河古浪", "黄河古浪", "黄河沙土路");


	set("long","这里就是西北的军事重镇永登。一座孤城耸立在茫茫荒野之上。此城建于汉光武年间，据闻大将军霍去病曾在此练兵三年，后一举平定大西北。历代而来，这里都有军队长驻。");

	



/*****************************************************

	set("exits", ([

//		"southup" : __DIR__"liupanshan",

		"north"   : __DIR__"gulang",

		"east"    : __DIR__"huanghe_3",

		"west"    : __DIR__"kedian",

	]));

	set("objects", ([

		"/d/city/npc/wujiang" : 1,

		"/d/city/npc/bing" : 4,

	]));

********************************************/

};





CHANGAN_END;
