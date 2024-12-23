//qinglong.h

//Sample for room: 泉州青龙会前庭
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州青龙会前庭");

	add_npc("pub_wuweiyang");
	add_door("泉州竹林小道", "泉州竹林小道", "泉州青龙会前庭");
	add_door("泉州青龙会侧庭3", "泉州青龙会侧庭3", "泉州青龙会前庭");
	add_door("泉州青龙会侧庭2", "泉州青龙会侧庭2", "泉州青龙会前庭");
	add_door("泉州青龙会大庭", "泉州青龙会大庭", "泉州青龙会前庭");

	
	
/*****************************************************
	set("exits", ([
		"west"  : __DIR__"qinglong1",
		"south" : __DIR__"qinglong2",
		"north" : __DIR__"qinglong3",
		"east"  : __DIR__"bamboo",
	]));
//	set("objects",([
//		__DIR__"npc/tang" : 1,
//	]));
	create_door("east","木门","west",DOOR_CLOSED);
********************************************/
};


ROOM_END;
