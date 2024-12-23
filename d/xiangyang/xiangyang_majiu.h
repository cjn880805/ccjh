//majiu.h

//Sample for room: 马厩
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "马厩");

	//add npcs into the room
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_zaohongma");
//	add_npc("animal_ziliuma");
//	add_npc("pub_mafu");
				

	add_door("襄阳茶馆", "襄阳茶馆", "襄阳马厩");

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
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz


TEXT]));
	set("exits",([ 
		"south"  : __DIR__"northroad2",
	]));
********************************************/
};


ROOM_END;
