//fangzhangshi.h

//Sample for room: 方丈室
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fangzhangshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "方丈室");

	add_npc("shaolin_xuan_ci");

	add_door("少林寺茶室", "少林寺茶室", "少林寺方丈室");

};


ROOM_END;
