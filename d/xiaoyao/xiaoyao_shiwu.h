//shiwu.h

//Sample for room: 石屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_shiwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "石屋");

	add_npc("xiaoyao_xiaoyaozi");

	add_door("逍遥林小道1", "逍遥林小道1", "逍遥林石屋");

	set("long", "这是树林中的一间石屋，屋内显得什么清净和简朴，房间中并没有什么特别的摆设在这里，不会受到任何东西的骚扰，是个修炼内功的好地方。");
	

/*****************************************************
	set("exits", ([ 
		"south" : __DIR__"xiaodao4",
	]));
********************************************/
};


ROOM_END;
