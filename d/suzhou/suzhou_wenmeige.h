//wenmeige.h

//Sample for room: ��÷��
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_wenmeige);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��÷��");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////
	add_npc("pub_qinpeier");
	add_door("������Ȥͤ", "������Ȥͤ", "������÷��");
	add_door("������ѩ��", "������ѩ��", "������÷��");

	
/*****************************************************
	set("exits", ([
		"west"  : __DIR__"zhenquting",
		"south" : __DIR__"lixuetang",
	]));
	set("objects", ([
		__DIR__"npc/lady4" : 1,
	]));
********************************************/
};


ROOM_END;
