//grass.h

//Sample for room: 黑木崖草地
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_grass);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖草地");

	add_npc("pub_maxiaofeng");
	add_door("黑木崖风雷堂大厅", "黑木崖风雷堂大厅", "黑木崖草地");
	add_door("黑木崖风雷堂", "黑木崖风雷堂", "黑木崖草地");
	add_door("黑木崖风雷堂厨房", "黑木崖风雷堂厨房", "黑木崖草地");

	set("long", "你走在一片草地。 ");
    

/*****************************************************
        set("exits", ([
            "east"    : __DIR__"mudi",
            "south"    : __DIR__"fen0", 
            "north"    :__DIR__"grass2",
        ]));
********************************************/
};


ROOM_END;
