//chaguan.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
	add_npc("pub_xiaoer2");//////////////////////////////
				

	add_door("��������", "��������", "�������");
//	add_door("�������", "�������", "�������");

	set("long", "��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ���ſ��������˿��ˣ������̸��ս�֣���ͷ�Ӷ�Ԫ���ƴ���Ҫ�����ʲô�����²���ʱ��" );
	set("resource/water", 1);
	
/*****************************************************
	set("exits", ([
		"west" : __DIR__"northjie",
	]));
********************************************/
};


ROOM_END;
