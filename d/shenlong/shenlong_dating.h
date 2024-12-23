//dating.h

//Sample for room:  神龙教大厅
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教大厅");

	add_npc("shenlong_yin");
	add_npc("shenlong_hong");
	add_npc("shenlong_wugeng");

	add_door("神龙教大门", "神龙教大门", "神龙教大厅");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp