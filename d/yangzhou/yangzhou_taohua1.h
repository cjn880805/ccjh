//taohua1.h

//Sample for room: �һ���
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���");

	set("resident", "�һ���");

	add_npc("pub_playboy");
    add_npc("guiyun_quanjinfa");             //zdd by zdn 2001-07-20

	add_door("�����һ�Ϫ", "�����һ�Ϫ", "�����һ���");
	add_door("��������", "��������", "�����һ���");


/*****************************************************
	set("exits", ([
		"north" : __DIR__"taohua2",
		"south" : __DIR__"ximen",
	]));
	set("objects", ([
		"/d/wudang/npc/bee" : 1,
	]));
********************************************/
};


RESIDENT_END;
