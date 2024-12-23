//luohan4.h

//Sample for room: 罗汉堂四部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan4);

virtual void create()			//Call it when Room Create
{
	set_name( "罗汉堂四部");

	add_npc("shaolin_cheng_jing");

	add_door("少林寺罗汉堂三部", "少林寺罗汉堂三部", "少林寺罗汉堂四部");
	add_door("少林寺罗汉堂五部", "少林寺罗汉堂五部", "少林寺罗汉堂四部");

};


ROOM_END;
