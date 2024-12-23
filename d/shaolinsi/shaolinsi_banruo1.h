//banruo1.h

//Sample for room: 般若堂一部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_banruo1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "般若堂一部");

	add_npc("shaolin_cheng_xin");

	add_door("少林寺后殿", "少林寺后殿", "少林寺般若堂一部");
	add_door("少林寺般若堂二部", "少林寺般若堂二部", "少林寺般若堂一部");


/*****************************************************
	set("exits", ([
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"banruo2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
//	
********************************************/
};


ROOM_END;
