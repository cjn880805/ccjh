//wanjing.h

//Sample for room: ��ɽׯ
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_wanjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽׯ");

	//add npcs into the room
	add_npc("pub_daoke");
	add_npc("pub_lundarong");

	add_door("�����Խ�ʯ", "�����Խ�ʯ", "������ɽׯ");
	add_door("���ݺ���Ȫ", "���ݺ���Ȫ", "������ɽׯ");
	add_door("����ͷ��ɽ", "����ͷ��ɽ", "������ɽׯ");

	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"shijianshi",
		"east"   : __DIR__"toumenshan",
		"westup" : __DIR__"hanhanquan",
	]));
        set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));

********************************************/
};


ROOM_END;
