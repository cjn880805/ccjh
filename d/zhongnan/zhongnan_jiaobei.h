//jiaobei.h

//Sample for room: ����ɽ�̱�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_jiaobei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�̱�");

	add_npc("quanzhen_zhao");

	add_door("����ɽ�Խ���", "����ɽ�Խ���", "����ɽ�̱�");
	add_door("����ɽʯ��6", "����ɽʯ��6", "����ɽ�̱�");
	add_door("����������", "����������", "����ɽ�̱�");
	
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ����������
������������������
������������ȫ����
������������������
�������������桡��
������������������
�������������š���
������������������
�������������̡���
������������������
������������������
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhao" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
