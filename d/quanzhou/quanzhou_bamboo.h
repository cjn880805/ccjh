//bamboo.h

//Sample for room: Ȫ������С��
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_bamboo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ������С��");
	
	add_npc("pub_playboy");   // add by zdn 2001-07-14
	add_npc("pub_zichuandaoshi");

	add_door("Ȫ������", "Ȫ������", "Ȫ������С��");
	add_door("Ȫ��������ǰͥ", "Ȫ��������ǰͥ", "Ȫ������С��");

	
	
/*****************************************************
	set("exits", ([
		"west"  : __DIR__"qinglong",
//		"south" : __DIR__"zhulin1",
		"north" : __DIR__"nanmen",
	]));

	set("outdoors", "quanzhou");
	create_door("west","ľ��","east",DOOR_CLOSED);
********************************************/
};


ROOM_END;
