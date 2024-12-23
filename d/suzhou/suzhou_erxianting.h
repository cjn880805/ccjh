//erxianting.h

//Sample for room: 二仙亭
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_erxianting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "二仙亭");
	
	add_npc("pub_flowerg");       //add by zdn 2001-07-16
	add_npc("helpnpc009");


	add_door("苏州白莲池", "苏州白莲池", "苏州二仙亭");
	add_door("苏州千人石", "苏州千人石", "苏州二仙亭");

	

/*****************************************************
	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : __DIR__"qianrenshi",
		"north" : __DIR__"bailianchi",
	]));
********************************************/
};


ROOM_END;
