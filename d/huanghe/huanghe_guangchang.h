//guangchang.h

//Sample for room: �ƺӹ㳡
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_guangchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӹ㳡");

	//add npcs into the room
	add_npc("pub_qian");

	add_door("�ƺӰ�կ��", "�ƺӰ�կ��", "�ƺӹ㳡");
	add_door("�ƺ�������", "�ƺ�������", "�ƺӹ㳡");

	set("long","�㳡ռ�����󣬲����Ͻ���������ȥ�ɴ�ƺӰ�ġ�������������Χ����Щ���ᣬ�����ھ�ס��");

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghegate",
		"west"  : __DIR__"xiayiting",
	]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
		__DIR__"npc/qian" : 1,
	]));
********************************************/
};


CHANGAN_END;
