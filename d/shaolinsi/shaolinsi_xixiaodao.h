//xixiaodao.h

//Sample for room: 少林寺西竹林小道
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_xixiaodao);

virtual void create()			//Call it when Room Create
{
	set_name( "少林寺西竹林小道");
	
	add_npc("shaolin_sengbing1");   //add by zdn 2001-07-20

	add_door("少林寺藏经阁一楼", "少林寺藏经阁一楼", "少林寺西竹林小道");
	//add_door("少林寺和尚院四部", "少林寺和尚院四部", "少林寺西竹林小道");
	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺西竹林小道");

};

ROOM_END;