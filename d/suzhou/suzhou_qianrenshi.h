//qianrenshi.h

//Sample for room: ǧ��ʯ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_qianrenshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ǧ��ʯ");
	
	add_npc("pub_poorman");         //add by zdn 2001-07-16


	add_door("���ݶ���ͤ", "���ݶ���ͤ", "����ǧ��ʯ");
	add_door("������ˬ��", "������ˬ��", "����ǧ��ʯ");
	add_door("�����Խ�ʯ", "�����Խ�ʯ", "����ǧ��ʯ");

	
/*****************************************************
	set("exits", ([
		"east"      : __DIR__"erxianting",
		"north"     : __DIR__"shijianshi",
		"northwest" : __DIR__"zhishuang",
	]));
********************************************/
};


ROOM_END;
