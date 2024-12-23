//talin.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_talin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	add_npc("dali_saodiseng");
				
	add_door("�����´���", "�����´���", "����������");
	add_door("������������1", "������������1", "����������");
	add_door("������������2", "������������2", "����������");
	add_door("������������3", "������������3", "����������");


/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"ta1",
		"west" : __DIR__"ta3",
		"east" : __DIR__"ta2",
                "north" : __DIR__"damen",
        ]));
	set("objects",([
                __DIR__"npc/saodiseng" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
