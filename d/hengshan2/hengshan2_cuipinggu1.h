//cuipinggu1.h

//Sample for room: 恒山翠屏谷1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuipinggu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山翠屏谷1");

	//add npcs into the room
	add_npc("hengshan_yiwen");

	add_door("恒山金龙峡", "恒山金龙峡", "恒山翠屏谷1");
	add_door("恒山翠屏谷2", "恒山翠屏谷2", "恒山翠屏谷1");

    set("long","浑河在谷中冲刷而过，天峰岭和翠屏山分列峡谷两侧，绝壁千仞，犹如刀削斧劈，高耸入云，这里自古就是塞外通往内地的咽喉要道，真有一夫当关万夫莫开之势。 " );
	set("outdoors", "hengshan");

/*****************************************************
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
		"northwest"  : __DIR__"jinlongxia",
	]));
	set("objects", ([
		__DIR__"npc/wen" : 1,
	]));
********************************************/
};


ROOM_END;
