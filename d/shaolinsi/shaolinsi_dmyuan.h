//dmyuan.h

//Sample for room: 达摩院
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dmyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "达摩院");

	add_npc("shaolin_dao_yi");

	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺达摩院");
	add_door("少林寺达摩院二楼", "少林寺达摩院二楼", "少林寺达摩院");

	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"wuchang3",
		"northdown" : __DIR__"guangchang5",
		"up"        : __DIR__"dmyuan2",
	]));

********************************************/
};


ROOM_END;
