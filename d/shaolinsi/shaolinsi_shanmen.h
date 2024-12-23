//shanmen.h

//Sample for room: 山门殿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_shanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山门殿");

	add_npc("shaolin_xu_tong");
	add_npc("shaolin_xu_ming");

	add_door("少林寺石阶", "少林寺石阶", "少林寺山门殿");
	add_door("少林寺台阶", "少林寺台阶", "少林寺山门殿");

};


ROOM_END;
