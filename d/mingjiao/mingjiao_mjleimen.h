//mjleimen.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjleimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");


	add_door("������ʯ��4", "������ʯ��4", "����������");
	add_door("��������", "������������", "����������");

	set("long", "ǰ��������̵ġ������š��ˣ�������������������������ĵط���������״������������ǵ�����ϰ���Լ�ʹ����ƷҲ���������졣" );
	
 
/*****************************************************
    set("exits", ([
        "enter" : __DIR__"sushe",
        "northeast" : __DIR__"mjleimen",
    ]));
    set("outdoors", "mingjiao");
********************************************/
};


ROOM_END;
