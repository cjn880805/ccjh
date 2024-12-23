//luohan5.h

//Sample for room: 罗汉堂五部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "罗汉堂五部");

	add_npc("shaolin_cheng_jian");
	add_npc("shaolin_xuan_ku");

	add_door("少林寺练武场", "少林寺练武场", "少林寺罗汉堂五部");
	add_door("少林寺罗汉堂四部", "少林寺罗汉堂四部", "少林寺罗汉堂五部");
	add_door("少林寺罗汉堂六部", "少林寺罗汉堂六部", "少林寺罗汉堂五部");

};


ROOM_END;
