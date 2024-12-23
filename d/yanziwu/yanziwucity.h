//yanziwucity.h

//Sample for room:  燕子坞长廊
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRyanziwucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞长廊");
	add_npc("murong_feng");        //add by zdn 2001-07-20

	add_door("燕子坞梨香苑", "燕子坞梨香苑", "燕子坞长廊");
	add_door("燕子坞汇珍园", "燕子坞汇珍园", "燕子坞长廊");
	add_door("燕子坞试剑台", "燕子坞试剑台", "燕子坞长廊");

/********************************************************
 
****************************************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp