//qzroad3.h

//Sample for room: 泉州山路3
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州山路3");

	set("resident", "泉州");
	
	add_npc("pub_cunfu");      //add by zdn 2001-07-14


	add_door("泉州山路4", "泉州山路4", "泉州山路3");
	add_door("泉州山路2", "泉州山路2", "泉州山路3");
	add_door("杭州青石大道1", "杭州青石大道1", "泉州山路3");
		
	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"qzroad2",
		"east" : __DIR__"qzroad4",
	]));

********************************************/
};


RESIDENT_END;
