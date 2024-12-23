//doumo.h

//Sample for room: 泰山斗母宫
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_doumo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山斗母宫");

	set("monster_chance", 16);

	add_door("泰山一天门", "泰山一天门", "泰山斗母宫");
	add_door("泰山石经峪", "泰山石经峪", "泰山斗母宫");

	set("long","上了一段山路，游人一般都会在这里稍为休息。这里的地势已经比泰山邻近的徂徕山为高，从这里往东北走便是石经峪。");

/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"shijin",
		"southdown" : __DIR__"yitian",
	]));
	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));
*****************************************************/
};


FIELD_END;
