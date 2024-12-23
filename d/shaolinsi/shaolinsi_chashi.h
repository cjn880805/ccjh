//chashi.h

//Sample for room: 茶室
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_chashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "茶室");

	add_npc("shaolin_qing_le");

	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺茶室");
	add_door("少林寺方丈室", "少林寺方丈室", "少林寺茶室");

};


ROOM_END;
