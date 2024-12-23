//dongxiaodao.h

//Sample for room: 少林寺东竹林小道
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dongxiaodao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺东竹林小道");
	
	add_npc("shaolin_sengbing1");       // add by zdn 2001-07-20

	add_door("少林寺武器库", "少林寺武器库", "少林寺东竹林小道");
//	add_door("少林寺和尚院一部", "少林寺和尚院一部", "少林寺东竹林小道");
	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺东竹林小道");

};

ROOM_END;