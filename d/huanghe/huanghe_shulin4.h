//shulin4.h

//Sample for room: �ƺ�����4
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����4");

	//add npcs into the room
//	add_npc("animal_fox");

	add_door("�ƺ�����2", "�ƺ�����2", "�ƺ�����4");
	add_door("�ƺ�����3", "�ƺ�����3", "�ƺ�����4");
	add_door("�ƺ�����5", "�ƺ�����5", "�ƺ�����4");

	set("long","��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���");
	

/*****************************************************
	set("exits", ([
		"northwest"  : __DIR__"shulin5",
		"east"       : __DIR__"shulin3",
		"south"      : __DIR__"shulin2",
	]));
	set("objects", ([
		"/d/baituo/npc/fox" : 1,
	]));
********************************************/
};


CHANGAN_END;
