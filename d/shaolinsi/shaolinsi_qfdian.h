//qfdian.h

//Sample for room: 千佛殿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_qfdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "千佛殿");

	add_npc("shaolin_qing_guan");

	add_door("少林寺竹林", "少林寺竹林", "少林寺千佛殿");
	add_door("少林寺广场", "少林寺广场", "少林寺千佛殿");

};


ROOM_END;
