//minju2.h

//Sample for room: �书���2
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_minju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�书���2");
	
	add_npc("pub_boy");       //add by zdn 2001-07-16


	add_door("�书", "�书", "�书���2");

	

/*****************************************************
        );
        set("exits", ([
                "east" : __DIR__"beijie",
        ]));
        set("item_desc", ([
        "hua": "�ⲻ�Ǳ��η���ġ�Ϫɽ����ͼ��������һ�����������۾���ϸһ����ԭ���Ǹ���Ʒ��\n"
        ]) );
        
********************************************/
};


WUGONG_END;
