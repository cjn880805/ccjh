//fu_datang.h

//Sample for room: 富家大堂
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_datang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "富家大堂");
//	add_npc("animal_wolfdog");

	add_door("武功富家小院", "武功富家小院", "武功富家大堂");


};


WUGONG_END;
