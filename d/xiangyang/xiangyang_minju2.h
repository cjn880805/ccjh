//minju2.h

//Sample for room: ���2
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_minju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���2");


	add_door("��������", "��������", "�������2");

	set("long", "����һ�ұȽ���Ǯ�˵�ס���������������ڼ���æ��æ�ǣ��������������æվ����������к���" );
	
/*****************************************************
	set("exits", ([
		"east" : __DIR__"jiedao",
	]));
********************************************/
};


ROOM_END;
