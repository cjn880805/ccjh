//hsyuan1.h

//Sample for room: 和尚院一部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "和尚院一部");

	add_npc("shaolin_hui_he");

	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺和尚院一部");
	add_door("少林寺和尚院二部", "少林寺和尚院二部", "少林寺和尚院一部");

};


ROOM_END;
