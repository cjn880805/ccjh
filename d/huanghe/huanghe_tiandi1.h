//tiandi1.h

//Sample for room: �ƺ����1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ����1");

	//add npcs into the room
	add_npc("pub_poorman");

	add_door("�ƺ�����3", "�ƺ�����3", "�ƺ����1");
	add_door("�ƺ����2", "�ƺ����2", "�ƺ����1");
	add_door("�ƺ����3", "�ƺ����3", "�ƺ����1");

	set("long","������ľ����ϡ�裬��Զ����һЩ��ׯ�������������𡣴�ׯ��Χ��һ������أ�������һЩ���ڸ�����ũ�ˡ�");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"shulin3",
		"west"  : __DIR__"tiandi2",
		"east"  : __DIR__"tiandi3",
	]));
	set("objects", ([
		"/d/village/npc/poorman" : 1,
	]));
********************************************/
};


CHANGAN_END;
