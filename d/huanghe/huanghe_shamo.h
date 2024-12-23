//shamo.h

//Sample for room: 黄河沙漠1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shamo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河沙漠1");
	
	add_npc("pub_tufeitou");  ///add by zdn 2001-07-14

	add_door("黄河靖远", "黄河靖远", "黄河沙漠1");
	add_door("黄河沙漠2", "黄河沙漠2", "黄河沙漠1");

	set("long","这是一片没边际的沙漠，到处是近百米高的巨大沙丘。你一走进来就仿佛迷了路。");
	

/*****************************************************
	set("exits", ([
		"north" : __FILE__,
		"south" : __DIR__"shamo1",
		"east"  : __FILE__,
		"west"  : __FILE__,
	]));
********************************************/
};


CHANGAN_END;
