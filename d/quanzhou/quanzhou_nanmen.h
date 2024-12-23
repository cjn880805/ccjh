//nanmen.h

//Sample for room: 泉州南门
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州南门");

	set("resident", "泉州");
	
	add_npc("pub_shiwei");      //add by zdn 2001-07-14


	add_door("泉州", "泉州", "泉州南门");
	add_door("泉州竹林小道", "泉州竹林小道", "泉州南门");

	set("long", "这里是南方第一港泉州的南门。南门外是一片荒野。" );
	
	
/*****************************************************
	set("exits", ([
//		"south" : __DIR__"bamboo",
                "north" : __DIR__"zhongxin",
	]));
********************************************/
};


RESIDENT_END;
