//dalieast.h

//Sample for room:  大理城东
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLiEastcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城东");

	add_npc("pub_playboy");  //add by zdn 2001-07-12

	add_door("大理城", "大理城", "出口");
	add_door("大理城玉虚观", "大理城东玉虚观", "出口");
	add_door("大理城养蚕房", "大理城东养蚕房", "出口");

};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp



