//jiulou2.h

//Sample for room: �书��¥��¥
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_jiulou2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�书��¥��¥");


	add_door("�书��¥", "�书��¥", "�书��¥��¥");


/*****************************************************
        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
        ]));
        set("objects", ([
                __DIR__"npc/zhanggui" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));
********************************************/
};


WUGONG_END;
