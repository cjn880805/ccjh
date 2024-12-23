//shamo1.h

//Sample for room: 黄河沙漠2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shamo1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河沙漠2");
	
	add_npc("pub_xixiabing");      //add by zdn 2001-07-14


	add_door("黄河沙漠1", "黄河沙漠1", "黄河沙漠2");
	add_door("黄河石洞", "黄河石洞", "黄河沙漠2");

	set("long","这是一片没边际的沙漠，到处是近百米高的巨大沙丘。你一走进来就仿佛迷了路。地下有个石洞。");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"shamo",
		"south" : __DIR__"shamo",
		"east"  : __DIR__"shamo",
		"west"  : __DIR__"shamo",
		"enter" : __DIR__"shidong",
	]));
********************************************/
};


CHANGAN_END;
