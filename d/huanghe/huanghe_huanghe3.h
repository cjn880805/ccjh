//huanghe3.h

//Sample for room: �ƺӰ���3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���3");

	//add npcs into the room
	add_npc("pub_bangzong");

	add_door("�ƺӰ���2", "�ƺӰ���2", "�ƺӰ���3");
	add_door("�ƺӰ���4", "�ƺӰ���4", "�ƺӰ���3");

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ�");
	

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghe4",
		"west"  : __DIR__"huanghe2",
	]));
	set("objects", ([
		__DIR__"npc/bangzong" : 1,
	]));
********************************************/
};


CHANGAN_END;
