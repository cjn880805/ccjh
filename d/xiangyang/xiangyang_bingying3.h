//bingying3.h

//Sample for room: �ϱ�Ӫ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_bingying3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ϱ�Ӫ");

	//add npcs into the room
	add_npc("pub_zuo");
	add_npc("pub_pian");
	add_npc("pub_bing");

	add_door("��������", "��������", "�����ϱ�Ӫ");

	set("long", "�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ������еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ�������ܡ����������������ȫ������ɴ��۾������㡣" );
/*****************************************************
	set("exits", ([		"east" : __DIR__"southjie3",	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/bing" : 2,
********************************************/
};


ROOM_END;
