//jiulou1.h

//Sample for room: �书��¥
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_jiulou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�书��¥");
	add_npc("pub_xiaoer2");


	add_door("�书", "�书", "�书��¥");
	add_door("�书��¥��¥", "�书��¥��¥", "�书��¥");

	

/*****************************************************
        set("exits", ([
                "south" : __DIR__"beijie",
                "up" : __DIR__"jiulou2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));
********************************************/
};


WUGONG_END;
