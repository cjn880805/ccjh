//shulin2.h

//Sample for room: �ƺ�����2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����2");

	//add npcs into the room
//	add_npc("animal_wolf2");

	add_door("�ƺ�����1", "�ƺ�����1", "�ƺ�����2");
	add_door("�ƺ�����4", "�ƺ�����4", "�ƺ�����2");

	set("long","��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ�����������һ������(paizi)��");
	

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
	]));
	set("objects", ([
		"/d/baituo/npc/wolf" : 1,
	]));
********************************************/
};


CHANGAN_END;
