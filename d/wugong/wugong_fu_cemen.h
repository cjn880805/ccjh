//fu_cemen.h

//Sample for room: ���Ҳ���
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_cemen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҳ���");
//	add_npc("animal_wolfdog");
	add_npc("pub_lady3");           //add by zdn 2001-07-16

	add_door("�书", "�书", "�书���Ҳ���");
	add_door("�书����СԺ", "�书����СԺ", "�书���Ҳ���");

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
