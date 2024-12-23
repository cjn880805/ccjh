//damen.h

//Sample for room: 桃花山庄正门
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花山庄正门");
	
	add_npc("pub_shiwei");        //add by zdn 2001-07-16
	add_npc("pub_xiangke");


	add_door("桃花岛", "桃花岛", "桃花山庄正门");
	add_door("桃花岛山庄正厅", "桃花岛山庄正厅", "桃花山庄正门");

	set("long", "这里是桃花山庄的正门。门前疏落有致地种了几株桃花树，更显得此地主人对桃花的偏爱。门口站着两个小童看守大门。看来由于地处边远，人烟罕至，人们对山庄的防卫不是特别谨慎。门前有一对白雕(diao)。");
	set("valid_startroom", 1);
	set("no_beg", "1");

/*****************************************************
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
		"骑上(ride)就可以飞到中原。\n",
	]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
********************************************/
};


ROOM_END;




