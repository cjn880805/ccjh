//damen.h

//Sample for room:  神龙教大门
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教大门");

	add_npc("zm_shenlong");

	add_door("神龙教大道", "神龙教大道", "神龙教大门");
	add_door("神龙教大厅", "神龙教大厅", "神龙教大门");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp