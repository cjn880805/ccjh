//bamboo.h

//Sample for room: 泉州竹林小道
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_bamboo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州竹林小道");
	
	add_npc("pub_playboy");   // add by zdn 2001-07-14
	add_npc("pub_zichuandaoshi");

	add_door("泉州南门", "泉州南门", "泉州竹林小道");
	add_door("泉州青龙会前庭", "泉州青龙会前庭", "泉州竹林小道");

	
	
/*****************************************************
	set("exits", ([
		"west"  : __DIR__"qinglong",
//		"south" : __DIR__"zhulin1",
		"north" : __DIR__"nanmen",
	]));

	set("outdoors", "quanzhou");
	create_door("west","木门","east",DOOR_CLOSED);
********************************************/
};


ROOM_END;
