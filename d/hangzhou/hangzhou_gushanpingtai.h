//gushanpingtai.h

//Sample for room: ���ݹ�ɽƽ̨
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_gushanpingtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݹ�ɽƽ̨");
	
	add_npc("pub_whitelady");           // add by zdn 2001-07-14


	add_door("���ݹ�ɽ", "���ݹ�ɽ", "���ݹ�ɽƽ̨");

	set("long"," ƽ̨�����С��������¾���ͤ��ͤ��������һ����(duilian)�����ﻹ������ˮ�أ��ٳ��е�ʯ��ɽ�����õøߵͲβ�������¡���������ɽ��·��");
    

/*****************************************************
        set("exits", ([
            "northdown" : __DIR__"gushan",
        ]));
        set("item_desc", ([
            "duilian" :
"ˮ              ��
ɽ              ��
��              ʱ
��              ʱ
��              ��
��              ��\n"
        ]));
 ********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
