//mjfengmen.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjfengmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");


	add_door("������ʯ��4", "������ʯ��4", "���̷���");
	add_door("��������", "���̵�������", "���̷���");
	add_door("�������", "���̷������", "���̷���");

	set("long", "���������е�һ��СԺ����Ӱ������������������ϱ�����һ�����ᣬ�����������͵��ͷ�ҵ��ӵ�����������" );
	

/*****************************************************
    set("exits", ([
        "northwest" : __DIR__"mjfengmen",
	"north" : __DIR__"foshe",
	"south" : __DIR__"daoshe",
    ]));
********************************************/
};


ROOM_END;
