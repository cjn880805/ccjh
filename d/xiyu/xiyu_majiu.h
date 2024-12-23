//majiu.h

//Sample for room: 马厩
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_majiu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "马厩");
	
//	add_npc("pub_mafu");      //add by zdn 2001-07-16


	add_door("小坝", "永登小坝", "西域马厩");

};



XIYU_END;
//last, register the room into ../server/RoomSetup.cpp