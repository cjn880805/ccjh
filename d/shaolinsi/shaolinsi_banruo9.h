//banruo9.h

//Sample for room: 般若堂九部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_banruo9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "般若堂九部");

	add_npc("shaolin_cheng_shang");

	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺般若堂九部");
	add_door("少林寺般若堂八部", "少林寺般若堂八部", "少林寺般若堂九部");


/*****************************************************
	set("exits", ([
		"south" : __DIR__"banruo8",
		"north" : __DIR__"fzlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
//	
********************************************/
};


ROOM_END;
