//qingdating.h

//Sample for room: �����ô���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_qingdating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ô���");
	
	add_npc("heimuya_zhang2");     //add by zdn 2001-07-20


	add_door("��ľ�³���2", "��ľ�³���2", "��ľ�������ô���");
	add_door("��ľ��������", "��ľ��������", "��ľ�������ô���");

	set("long", "���ǡ�������̡��µ������ã������õĴ�����һλ���߾��У������㱡�(bian)��");
    

/*****************************************************
        set("exits", ([
            "north" : __DIR__"chlang2",
            "east" : __DIR__"tang",
        ]));
        set("objects",([
            __DIR__"npc/jiabu"   :1,
        ]));
********************************************/
};


ROOM_END;
