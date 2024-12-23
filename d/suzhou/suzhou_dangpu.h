//dangpu.h

//Sample for room: 宝和记
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "宝和记");
	
	add_npc("pub_xiaoer2");         //add by zdn 2001-07-16


	add_door("苏州中", "苏州中", "苏州宝和记");

 	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	
/*****************************************************
	set("exits", ([
		"north"  : __DIR__"dongdajie1",
	]));
	set("item_desc", ([
		"sign" : "公平交易\n
sell        卖 
buy         买
value       估价
",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));

********************************************/
};


ROOM_END;
