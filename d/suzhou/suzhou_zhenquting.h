//zhenquting.h

//Sample for room: ��Ȥͤ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhenquting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ȥͤ");
	
	add_npc("pub_youke");         //add by zdn 2001-07-16


	add_door("����������", "����������", "������Ȥͤ");
	add_door("������÷��", "������÷��", "������Ȥͤ");

	
/*****************************************************
	set("exits", ([
		"east"      : __DIR__"wenmeige",
		"northwest" : __DIR__"yanyutang",
	]));
********************************************/
};


ROOM_END;
