//huanghai.h

//Sample for room:  神龙黄海
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_huanghai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄海");

	add_door("神龙教海滩", "神龙教海滩", "神龙黄海");
	add_door("北京塘沽口", "北京塘沽口", "神龙黄海");
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp