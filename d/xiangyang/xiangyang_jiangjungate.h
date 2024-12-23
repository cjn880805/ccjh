//jiangjungate.h

//Sample for room: 将军府大门
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_jiangjungate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "将军府大门");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("xiangyang_guojing");        //add by zdn 2001-07-20
	add_npc("helpnpc001");


	add_door("襄阳东北", "襄阳东北", "襄阳将军府大门");

	set("outdoors", "xiangyang");
/*****************************************************
	set("exits", ([
		"south" : __DIR__"eastjie1",
		"north" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
********************************************/
};


ROOM_END;
