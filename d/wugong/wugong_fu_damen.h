//fu_damen.h

//Sample for room: ���Ҵ���
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҵ���");

	add_npc("pub_jiading");
	add_door("�书", "�书", "�书���Ҵ���");
	add_door("�书����СԺ", "�书����СԺ", "�书���Ҵ���");


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
