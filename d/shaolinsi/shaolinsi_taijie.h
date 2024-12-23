//taijie.h

//Sample for room: 少林寺台阶
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_taijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺台阶");
	
	add_npc("pub_sixinzhe");

	add_door("少林寺山门殿", "少林寺山门殿", "少林寺台阶");
	add_door("少林寺天王殿", "少林寺天王殿", "少林寺台阶");

};

ROOM_END;
