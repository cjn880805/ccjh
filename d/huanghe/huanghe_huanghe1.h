//huanghe1.h

//Sample for room: �ƺӰ���1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���1");

	//add npcs into the room
	add_npc("pub_houxiahai");

	add_door("�ƺ����4", "�ƺ����4", "�ƺӰ���1");
	add_door("�ƺӰ���2", "�ƺӰ���2", "�ƺӰ���1");
	add_door("�ƺӰ�կ��", "�ƺӰ�կ��", "�ƺӰ���1");
	add_door("�ƺ�μ������", "�ƺ�μ������", "�ƺӰ���1");

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ������и�կ�ӡ�");
    

/*****************************************************
	set("exits", ([
		"south" : __DIR__"tiandi4",
		"north" : __DIR__"weifen",
		"east"  : __DIR__"huanghe2",
		"west"  : __DIR__"huanghegate",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
********************************************/
};


CHANGAN_END;
