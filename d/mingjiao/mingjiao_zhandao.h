//zhandao.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_zhandao);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "����ջ��");

	add_door("�����һ������", "�����һ������", "����ջ��");
	add_door("������΢��", "������΢��", "����ջ��");

	set("long", "������ͨ�����̵�ջ��������ï�����ƣ�������ա�");
    

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"zhandao2",
		"southdown" : __DIR__"lhqhoumen",
	]));
	set("outdoors", "mingjiao");
	
********************************************/

};



ROOM_END;
