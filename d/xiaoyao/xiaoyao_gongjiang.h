//gongjiang.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_gongjiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("xiaoyao_fengas");/////////////////////////

	add_door("��ң��С��1", "��ң��С��1", "��ң�ֹ�����");

	set("long", "����Ҳ��һ��ľ�ݣ������еİ���ʲô�򵥣�����ȴ�кܶ๤�ߣ��������������������������������ص�ľм��һ����֪����һ�������ļҡ��������ǵ��ɽ���æ���أ�������֪����������ʲô�أ�");

/*****************************************************
	set("exits", ([
		"north" : __DIR__"mubanlu",
	]));
	set("objects", ([
		__DIR__"npc/fengas": 1,
	]));
//	
********************************************/
};


ROOM_END;
