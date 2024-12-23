//duchang.h

//Sample for room: 赌场
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_duchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "赌场");

	add_npc("pub_baoqinguang");

	add_door("襄阳西南", "襄阳西南", "襄阳赌场");

};


ROOM_END;
