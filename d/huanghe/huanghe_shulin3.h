//shulin3.h

//Sample for room: �ƺ�����3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����3");

	//add npcs into the room
//	add_npc("animal_wolf2");/////////////////////////
//	add_npc("animal_maoniu");
	add_npc("pub_leimeng");	

	add_door("�ƺ�����1", "�ƺ�����1", "�ƺ�����3");
	add_door("�ƺ�����4", "�ƺ�����4", "�ƺ�����3");
	add_door("�ƺ����1", "�ƺ����1", "�ƺ�����3");

	set("long","��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���");
	

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"shulin4",
		"south" : __DIR__"shulin1",
		"north" : __DIR__"tiandi1",
	]));
********************************************/
};


CHANGAN_END;
