//shimen.h

//Sample for room: �ƺ�ʯ��
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�ʯ��");

	//add npcs into the room
	add_npc("pub_xixiabing");/////////////////////////
	add_npc("pub_caishiren");

	add_door("�ƺӹų���", "�ƺӹų���", "�ƺ�ʯ��");
	add_door("�ƺӺ�ɽϿ", "�ƺӺ�ɽϿ", "�ƺ�ʯ��");
	add_door("�ƺ������", "�ƺ������", "�ƺ�ʯ��");

	set("long","������ʯ�ţ������ĵĲ�ʯ��������û�б�������ֻ�б�صİ���ʯ���������������ʯ�ذ��������������İ���ʯ�̳ɵġ�ʱ���д����Ŀ������ٸ������������û��ûҹ�Ŀ��ɰ���ʯ������˵��º��û����վ������������һ������");

/*****************************************************
	set("exits", ([
		"northwest" : __DIR__"yinpanshui",
		"south"     : __DIR__"hongshanxia",
		"north"     : __DIR__"wufosi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
		__DIR__"npc/caishiren" : 2,
	]));
********************************************/
};


CHANGAN_END;
