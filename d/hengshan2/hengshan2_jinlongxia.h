//jinlongxia.h

//Sample for room: 恒山金龙峡
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_jinlongxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山金龙峡");
	
	add_npc("hengshan_tian");      //add by zdn 2001-07-20


	add_door("恒山翠屏谷1", "恒山翠屏谷1", "恒山金龙峡");

	add_door("北京大驿道6", "北京大驿道6", "恒山金龙峡");

    set("long","金龙峡又称唐峪，是进入恒山的入口。恒山一名太恒山，或称玄岳，是五岳中的北岳，道教以之为 '第五小洞天' 。它横亘三百余里，如一队行进中的队列，昔人以为 '恒山如行' 来相对 '泰山如坐' ，'华山如立'，'嵩山如卧'和'衡山如飞'。" );
	set("outdoors", "hengshan");

/*****************************************************
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
		"northeast"  : "/d/city2/road6",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
	]));
********************************************/
};


ROOM_END;
