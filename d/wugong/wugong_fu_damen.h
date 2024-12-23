//fu_damen.h

//Sample for room: 富家大门
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "富家大门");

	add_npc("pub_jiading");
	add_door("武功", "武功", "武功富家大门");
	add_door("武功富家小院", "武功富家小院", "武功富家大门");


/*****************************************************
        set("exits", ([
                "north" : __DIR__"dongjie",
                "south" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 3,
        ]));
********************************************/
};


WUGONG_END;
