//hsqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_hsqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "��ˮ�����");

	add_door("��΢��", "������΢��", "��ˮ�����");
	add_door("��΢��", "������΢��", "��ˮ�����");

	set("long", "���������̺�ˮ��Ĵ���, ׯ�Ϲ���, ��ǰ�Բ����������������ǰˮ������, ȴ��һ��ˮ������������, �����ٲ�����Դ,ԭ��, ������ˮ��ͽ���������С��֮��");
    

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"hsqchanglang",
		"south" : __DIR__"tohsq7",
	]));
********************************************/

};



ROOM_END;
