//kedian1.h

//Sample for room: �书�͵�
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_kedian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�书�͵�");
	
	add_npc("pub_xiaoer2");     //add by zdn 2001-07-16


	add_door("�书", "�书", "�书�͵�");
	add_door("�书�͵��¥", "�书�͵��¥", "�书�͵�");

    set("no_fight", 1);
    set("valid_startroom", 1);
    set("sleep_room",1);

/*****************************************************
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹʮ��������\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer1" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"dongjie",
                "up" : __DIR__"kedian2",
        ]));
********************************************/
};


WUGONG_END;
