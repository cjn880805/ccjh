//htqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_htqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "���̺�������");

	add_door("��΢��", "������΢��", "���̺�������");
	add_door("��΢��", "������΢��", "���̺�������");

	set("long", "���Ǻ�����Ķ��ţ��Ŷ�����������ĺ������ڣ����Ϲ������£������̵���˭Ҳ�����㡣�ű�����̸���Ʊ߷����죬���ź������֡�");
    

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"htqdating",
		"south" : __DIR__"tohtq7",
	]));
********************************************/

};



ROOM_END;
