//fu_cemen.h

//Sample for room: 富家侧门
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_cemen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "富家侧门");
//	add_npc("animal_wolfdog");
	add_npc("pub_lady3");           //add by zdn 2001-07-16

	add_door("武功", "武功", "武功富家侧门");
	add_door("武功富家小院", "武功富家小院", "武功富家侧门");

/*****************************************************
        set("exits", ([
                "northwest" : __DIR__"nanjie",
                "east" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/wolfdog" : 2,
        ]));
********************************************/
};


WUGONG_END;
