//xiaowu.h

//Sample for room:  神龙教小屋
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_xiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教小屋");

	add_npc("shenlong_pang");
	add_npc("shenlong_shou");
	add_npc("shenlong_lu");

	add_door("神龙教空地", "神龙教空地", "神龙教小屋");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp