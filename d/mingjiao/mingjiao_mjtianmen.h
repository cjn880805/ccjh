//mjtianmen.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjtianmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_door("������ʯ��4", "������ʯ��4", "����������");
	add_door("��������", "������������", "����������");

	set("long", "ǰ��������̵ġ������š��ˣ��������������е��������ĵط������ſڿ���ȥ�����������ľ�����ơ��˴�����Ů��������롣" );
	

/*****************************************************
    set("exits", ([
        "enter" : __DIR__"nanshe",
        "southeast" : __DIR__"mjtianmen",
    ]));
    set("outdoors", "mingjiao");
********************************************/
};


ROOM_END;
