//shulin5.h

//Sample for room: �ƺ�����5
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����5");

	//add npcs into the room
//	add_npc("animal_yezhu");/////////////////////////
//	add_npc("animal_fox");

	add_door("�ƺ�����4", "�ƺ�����4", "�ƺ�����5");
	add_door("�ƺ����2", "�ƺ����2", "�ƺ�����5");
	add_door("�ƺ�����6", "�ƺ�����6", "�ƺ�����5");

	set("long","��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���");
	

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"shulin6",
		"southeast" : __DIR__"shulin4",
		"northeast" : __DIR__"tiandi2",
	]));
	set("objects", ([
		"/d/hangzhou/npc/maque" : 2,
		"/d/taishan/npc/tangzi" : 1,
	]));
********************************************/
};


CHANGAN_END;
