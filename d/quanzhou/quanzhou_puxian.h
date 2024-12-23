//puxian.h

//Sample for room: 泉州莆仙平原
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_puxian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州莆仙平原");

	set("resident", "泉州");
	
	add_npc("pub_xixiabing");         //add by zdn 2001-07-14

	add_door("泉州山路4", "泉州山路4", "泉州莆仙平原");
	add_door("泉州中洲桥", "泉州中洲桥", "泉州莆仙平原");

	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"zhongzhou",
                "south" : "/d/quanzhou/beimen",
	]));
********************************************/
};


RESIDENT_END;
