//xiaodao1.h

//Sample for room: 小道1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaodao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林小道1");

	add_npc("xiaoyao_mengmianr");
	add_npc("zm_xiaoyao");

	add_door("逍遥林树林", "逍遥林树林", "逍遥林小道1");

	add_door("逍遥林石屋", "逍遥林石屋", "逍遥林小道1");
	add_door("逍遥林工匠屋", "逍遥林工匠屋", "逍遥林小道1");
	add_door("逍遥林小道2", "逍遥林小道2", "逍遥林小道1");

/*****************************************************
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
********************************************/
};


ROOM_END;
