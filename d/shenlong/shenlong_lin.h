//lin.h

//Sample for room:  神龙教灌木林
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_lin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教灌木林");
	add_npc("animal_dushe");
	
	add_door("神龙教海滩", "神龙教海滩", "神龙教灌木林");
	add_door("神龙教空地", "神龙教空地", "神龙教灌木林");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp