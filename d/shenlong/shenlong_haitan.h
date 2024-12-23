//haitan.h

//Sample for room:  神龙教海滩
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_haitan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教海滩");
	
	add_npc("pub_yufu");         //add by zdn 2001-07-15

	add_door("北京塘沽口", "北京塘沽口", "神龙教海滩");
	add_door("神龙教灌木林", "神龙教灌木林", "神龙教海滩");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp