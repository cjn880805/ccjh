//gongjiang.h

//Sample for room: 工匠屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_gongjiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "工匠屋");

	//add npcs into the room
	add_npc("xiaoyao_fengas");/////////////////////////

	add_door("逍遥林小道1", "逍遥林小道1", "逍遥林工匠屋");

	set("long", "这里也是一间木屋，屋子中的摆设什么简单，但是却有很多工具，锯子啦，刨子啦，锤子啦，还有满地的木屑，一看就知道是一个工匠的家。看！我们的巧匠正忙着呢，不过不知道他又在做什么呢？");

/*****************************************************
	set("exits", ([
		"north" : __DIR__"mubanlu",
	]));
	set("objects", ([
		__DIR__"npc/fengas": 1,
	]));
//	
********************************************/
};


ROOM_END;
