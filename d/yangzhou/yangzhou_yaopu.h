//yaopu.h

//Sample for room: 药铺
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "药铺");

	//add npcs into the room
	add_npc("pub_ping");
	add_npc("pub_huoji");
	
	add_door("扬州东北", "扬州东北", "扬州药铺");

	set("long", "这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。" );
/*****************************************************
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
无常丹由桃花岛黄药师所配，生死肉骨．
朱睛冰蟾救治百毒，无效包换．
其他神药与老板面议。\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "本店老板平一指外出采药未归，今日暂停营业。\n",
//	]));
	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));
//	
********************************************/
};


ROOM_END;
