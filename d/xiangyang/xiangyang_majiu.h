//majiu.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_zaohongma");
//	add_npc("animal_ziliuma");
//	add_npc("pub_mafu");
				

	add_door("�������", "�������", "�������");

	set("outdoors", "xiangyang");
	set("no_fight", "1");
	set("no_beg", "1");
	
/*****************************************************
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz


TEXT]));
	set("exits",([ 
		"south"  : __DIR__"northroad2",
	]));
********************************************/
};


ROOM_END;
