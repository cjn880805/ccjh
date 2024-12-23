//banruo5.h

//Sample for room: 般若堂五部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_banruo5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "般若堂五部");

	add_npc("shaolin_xuan_nan");
	add_npc("shaolin_cheng_zhi2");

	add_door("少林寺练武场", "少林寺练武场", "少林寺般若堂五部");
	add_door("少林寺般若堂四部", "少林寺般若堂四部", "少林寺般若堂五部");
	add_door("少林寺般若堂六部", "少林寺般若堂六部", "少林寺般若堂五部");


};


ROOM_END;
