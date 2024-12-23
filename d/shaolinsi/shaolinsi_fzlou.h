//fzlou.h

//Sample for room: 方丈楼
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fzlou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "方丈楼");

	add_npc("shaolin_dao_pin");

	add_door("少林寺般若堂九部", "少林寺般若堂九部", "少林寺方丈楼");
	add_door("少林寺罗汉堂九部", "少林寺罗汉堂九部", "少林寺方丈楼");

	add_door("少林寺茶室", "少林寺茶室", "少林寺方丈楼");
	add_door("少林寺和尚院一部", "少林寺和尚院一部", "少林寺方丈楼");
	add_door("少林寺和尚院四部", "少林寺和尚院四部", "少林寺方丈楼");
	
	add_door("少林寺西竹林小道", "少林寺西竹林小道", "少林寺方丈楼");
	add_door("少林寺东竹林小道", "少林寺东竹林小道", "少林寺方丈楼");
	add_door("少林寺练武场", "少林寺练武场", "少林寺方丈楼");
	add_door("少林寺广场", "少林寺广场", "少林寺方丈楼");
	add_door("少林寺达摩院", "少林寺达摩院", "少林寺方丈楼");

};


ROOM_END;
