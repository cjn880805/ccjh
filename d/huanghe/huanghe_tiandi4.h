//tiandi4.h

//Sample for room: �ƺ����4
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ����4");

	//add npcs into the room
	add_npc("animal_dog");
	add_item("daotian");

	add_door("�ƺ����3","�ƺ����3", "�ƺ����4");
	add_door("�ƺӰ���1","�ƺӰ���1", "�ƺ����4");

	set("long","������һ��Ƭũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ��һ������أ�������һЩ���ڸ�����ũ�ˡ����ﲻʱ����һ������Ȯ�͡�");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"tiandi3",
		"north"     : __DIR__"huanghe1",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
********************************************/
};


CHANGAN_END;
