//qinxiu.h

//Sample for room: 勤修场
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_qinxiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺勤修场");
	
	add_npc("shaolin_sengbing2");   //add by zdn 2001-07-20

	add_door("少林寺后殿", "少林寺后殿", "少林寺勤修场");
	add_door("少林寺斋厅", "少林寺斋厅", "少林寺勤修场");
	add_door("少林寺戒律院", "少林寺戒律院", "少林寺勤修场");
	add_door("少林寺精进场", "少林寺精进场", "少林寺勤修场");

};

ROOM_END;
