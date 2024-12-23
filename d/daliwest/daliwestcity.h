//daliwest.h

//Sample for room:  大理城西
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLiWestcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城西");
	
	add_npc("pub_shiwei1");   //add by zdn 2001-07-13
	add_npc("dali_bing");       //add by zdn 2001-07-20

	add_door("大理城", "大理城", "出口");

	add_door("大理城西祭祀大屋", "大理城西祭祀大屋", "出口");
	add_door("大理城西拈花寺", "大理城西拈花寺", "出口");
	add_door("大理城西祭祀大屋", "大理城西祭祀大屋", "出口");

};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp