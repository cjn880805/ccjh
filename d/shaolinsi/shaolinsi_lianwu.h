//lianwu.h

//Sample for room: 少林寺练武场
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_lianwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺练武场");

	add_npc("shaolin_dao_cheng");
	add_npc("shaolin_dao_jue");

	add_door("少林寺后殿", "少林寺后殿", "少林寺练武场");
	add_door("少林寺般若堂五部", "少林寺般若堂五部", "少林寺练武场");
	add_door("少林寺罗汉堂五部", "少林寺罗汉堂五部", "少林寺练武场");
	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺练武场");

};

ROOM_END;
