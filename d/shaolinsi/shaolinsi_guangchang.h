//guangchang.h

//Sample for room: 少林寺广场
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_guangchang);

virtual void create()			//Call it when Room Create
{
	set_name( "少林寺广场");

	add_npc("shaolin_qing_shan");
	add_npc("shaolin_qing_wei");
	add_npc("shaolin_qing_wu");
	add_npc("shaolin_qing_fa");

	add_door("少林寺千佛殿", "少林寺千佛殿", "少林寺广场");
	add_door("少林寺地藏殿", "少林寺地藏殿", "少林寺广场");
	add_door("少林寺方丈楼", "少林寺方丈楼", "少林寺广场");
	add_door("少林寺白衣殿", "少林寺白衣殿", "少林寺广场");

};

ROOM_END;