//jingjin.h

//Sample for room: 精进场
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_jingjin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺精进场");

	add_npc("shaolin_hui_kong");

	add_door("少林寺勤修场", "少林寺勤修场", "少林寺精进场");
	add_door("少林寺天王殿", "少林寺天王殿", "少林寺精进场");
	add_door("少林寺鼓楼小院", "少林寺鼓楼小院", "少林寺精进场");
	add_door("少林寺钟楼一层", "少林寺钟楼一层", "少林寺精进场");

};

ROOM_END;
