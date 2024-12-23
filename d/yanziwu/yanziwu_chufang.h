//chufang.h

//Sample for room: Ñà×ÓÎë³ø·¿
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ñà×ÓÎë³ø·¿");

	add_npc("pub_nanpu");

	add_door("Ñà×ÓÎëÏşº®Ìü", "Ñà×ÓÎëÏşº®Ìü", "Ñà×ÓÎë³ø·¿");

};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp