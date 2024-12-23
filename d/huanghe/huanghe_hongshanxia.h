//hongshanxia.h

//Sample for room: 黄河红山峡
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_hongshanxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河红山峡");

	//add npcs into the room
	add_npc("pub_mazei");

	add_door("黄河石门", "黄河石门", "黄河红山峡");
	add_door("黄河靖远", "黄河靖远", "黄河红山峡");

	set("long","红山峡是个非常险峻的峡谷，两边是数十丈的黄土坡，很是陡峭，中间只有一条可以通行一人一马的窄道，俗称“一线天”。附近没有什么生物，却有商旅常在这里失踪。");

/*****************************************************
	set("exits", ([
		"north"     : __DIR__"shimen",
		"south"     : __DIR__"jingyuan",
	]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));
********************************************/
};


CHANGAN_END;
