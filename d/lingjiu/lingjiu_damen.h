//damen.h

//Sample for room: ���ն���������
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ն���������");

	add_npc("lingjiu_meijian");
	add_npc("lingjiu_lanjian");

	add_door("���ն�����", "���ն�����", "���ն���������");
	add_door("������ʯ���2", "������ʯ���2", "���ն���������");

	set("long", "�����ͨ�����չ����������Ĵ��š��������Ҹ���һͷʯ������գ��ߴ��������࣬��๾�צ���񿥷Ƿ��������������ƺ���ʱҪ�ڿն�ȥ��" );

/*****************************************************
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
        ]));
	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		__DIR__"npc/lanjian" : 1,
	]));
********************************************/
};


ROOM_END;
