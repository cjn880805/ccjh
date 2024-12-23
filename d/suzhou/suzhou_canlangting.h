//canlangting.h

//Sample for room: 沧浪亭
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_canlangting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "沧浪亭");
	
	add_npc("pub_jianke");         //add by zdn 2001-07-16


	add_door("苏州", "苏州", "苏州沧浪亭");

	set("outdoors", "suzhou");
	
/*****************************************************
	set("item_desc", ([
		"lian" :
"清风明月本无价 近水远山皆有情\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"dongdajie1",
		"southwest" : __DIR__"xidajie1",
		"north"     : __DIR__"beidajie1",
		"south"     : __DIR__"baodaiqiao",
	]));

********************************************/
};


ROOM_END;
