//minju1.h

//Sample for room: ���1
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_minju1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���1");
	
	add_npc("pub_linjinzhi");

	add_door("��������", "��������", "�������1");

	set("long", "����һ�ұȽ���Ǯ�˵�ס���������������ڼ���æ��æ�ǣ��������������æվ����������к���" );
	
/*****************************************************
	set("exits", ([
		"west" : __DIR__"jiedao",
	]));
********************************************/
};


ROOM_END;
