//shijianshi.h

//Sample for room: �Խ�ʯ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_shijianshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Խ�ʯ");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("������ʯ", "������ʯ", "�����Խ�ʯ");
	add_door("��������ͤ", "��������ͤ", "�����Խ�ʯ");
	add_door("����ǧ��ʯ", "����ǧ��ʯ", "�����Խ�ʯ");
	add_door("������ɽׯ", "������ɽׯ", "�����Խ�ʯ");


/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"zhenniang",
		"south"     : __DIR__"qianrenshi",
		"north"     : __DIR__"zhenshi",
		"westdown"  : __DIR__"wanjing",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
********************************************/
};


ROOM_END;
