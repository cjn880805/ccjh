//men2.h

//Sample for room: 灵鹫书房大门
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_men2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫书房大门");

	//add npcs into the room
	add_npc("lingjiu_nvlang");
	add_npc("lingjiu_zhujian");
	add_door("灵鹫画廊12", "灵鹫画廊12", "灵鹫书房大门");

	

/*****************************************************
        set("outdoors", "lingjiu");
        set("exits", ([
		"east" : __DIR__"shufang",
		"west" : __DIR__"changl12",
        ]));
	set("objects",([
		__DIR__"npc/zhujian" : 1,
	]));
	set("item_desc", ([
	    "duilian" : "行到水穷处，坐看云起时.\n",
	    "bian" : HIC "任我逍遥\n" NOR,
        ]));
********************************************/
};


ROOM_END;
