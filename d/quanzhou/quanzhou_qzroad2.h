//qzroad2.h

//Sample for room: 泉州山路2
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州山路2");

	set("resident", "泉州");
	
	add_npc("pub_playboy");        //add by zdn 2001-07-14


	add_door("泉州山路3", "泉州山路3", "泉州山路2");
	add_door("泉州山路1", "泉州山路1", "泉州山路2");
	add_door("苏州东门", "苏州东门", "泉州山路2");
	add_door("嘉兴南门", "嘉兴南门", "泉州山路2");	

	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"qzroad2",
		"east" : __DIR__"qzroad4",
	]));

********************************************/
};


RESIDENT_END;
