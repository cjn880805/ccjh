//xiaomuwu.h

//Sample for room: 小木屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaomuwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小木屋");

	//add npcs into the room
	add_npc("xiaoyao_xuemuh");/////////////////////////

	add_door("逍遥林小道2", "逍遥林小道2", "逍遥林小木屋");


/*****************************************************
	set("exits", ([
		"south" : __DIR__"xiaodao3",
	]));
	set("objects", ([
		__DIR__"npc/xuemuh" : 1,
//		__DIR__"npc/yaotong": 1,
	]));
//	
********************************************/
};


ROOM_END;
