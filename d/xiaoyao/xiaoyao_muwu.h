//muwu.h

//Sample for room: 木屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_muwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "木屋");

	//add npcs into the room
	add_npc("xiaoyao_kanggl");

	add_door("逍遥林小道2", "逍遥林小道2", "逍遥林木屋");


/*****************************************************
	set("exits", ([
		"north" : __DIR__"xiaodao5",
	]));
 	set("objects", ([
		__DIR__"npc/kanggl": 1,
	]));
//	
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp