//shimen.h

//Sample for room: 黄河石门
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河石门");

	//add npcs into the room
	add_npc("pub_xixiabing");/////////////////////////
	add_npc("pub_caishiren");

	add_door("黄河古长城", "黄河古长城", "黄河石门");
	add_door("黄河红山峡", "黄河红山峡", "黄河石门");
	add_door("黄河五佛寺", "黄河五佛寺", "黄河石门");

	set("long","这里是石门，是西夏的采石场，当地没有别的物产，只有遍地的白玉石，西夏王宫里的玉石地板就是用这里出产的白玉石铺成的。时常有大批的苦力被官府征到这儿来，没日没夜的开采白玉石矿，许多人倒下后就没有再站起来。北面有一座寺庙。");

/*****************************************************
	set("exits", ([
		"northwest" : __DIR__"yinpanshui",
		"south"     : __DIR__"hongshanxia",
		"north"     : __DIR__"wufosi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
		__DIR__"npc/caishiren" : 2,
	]));
********************************************/
};


CHANGAN_END;
