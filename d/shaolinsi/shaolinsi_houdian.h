//houdian.h

//Sample for room: 后殿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_houdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "后殿");

	add_npc("shaolin_hui_ru");
	add_npc("pub_chenmin");

	add_door("少林寺勤修场", "少林寺勤修场", "少林寺后殿");

	add_door("少林寺般若堂一部", "少林寺般若堂一部", "少林寺后殿");
	add_door("少林寺罗汉堂一部", "少林寺罗汉堂一部", "少林寺后殿");
	add_door("少林寺练武场", "少林寺练武场", "少林寺后殿");

	set("valid_startroom",1);
	set("resource/water",1);

};


ROOM_END;
